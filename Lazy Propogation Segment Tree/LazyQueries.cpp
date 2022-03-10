#include<iostream>
#include<climits>
using namespace std;
int lazy[1000] = {0};
void BuildTree(int *a, int s, int e, int *tree, int index)
{
    if (s == e)
    {
        tree[index] = a[s];
        return;
    }
    int mid = (s + e) / 2;
    BuildTree(a, s, mid, tree, 2 * index);
    BuildTree(a, mid + 1, e, tree, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return ;
}
int query(int *tree, int ss, int se, int qs, int qe, int index)
{
    //complete overlap
    if (ss >= qs and se <= qe)
    {
        return tree[index];
    }
    //No overlap
    if (qe < ss or se < qs)
    {
        return INT_MAX;
    }
    //Partial overlap
    int mid = (ss + se) / 2;
    int left = query(tree, ss, mid, qs, qe, index * 2);
    int right = query(tree, mid + 1, se, qs, qe, 2 * index + 1);
    return min(left, right);
}
void pointupdate(int *tree, int ss, int se, int i, int value, int index)
{
    //Case where out of bound
    if (i<ss or i>se)
    {
        return;
    }
    //Leaf node case if only one node left and the the node doesnt belongs to the out of bound then it is the only node to be updated
    if (ss == se)
    {
        tree[index] = value;
        return;
    }
    int mid = (ss + se) / 2;
    pointupdate(tree, ss, mid, i, value, index * 2);
    pointupdate(tree, mid + 1, se, i, value, 2 * index + 1);
    tree[index] = min(tree[index * 2], tree[2 * index + 1]);
    return ;
}
void rangeupdate(int *tree, int ss, int se, int l, int r, int value, int index)
{
    //if out of bound
    if (l > se or r < ss)
    {
        return ;
    }
    //In bound and leaf node
    if (ss == se)
    {
        tree[index] = value;
        return;
    }
    int mid = (ss + se) / 2;
    rangeupdate(tree, ss, mid, l, r, value, 2 * index);
    rangeupdate(tree, mid + 1, se, l, r, value, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}
void UpdateRangeLazy(int *tree, int ss, int se, int l, int r, int inc, int index)
{
    //before going down resolve the lazy value and propogate to childrens
    if (lazy[index] != 0)
    {
        tree[index] += lazy[index];
        if (ss != se) //not a leaf node
        {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        //clear the lazy value
        lazy[index] = 0;
    }
    //no overlap
    if (ss > r or l > se)
    {
        return;
    }

    //complete overlap
    if (ss >= l and se <= r)
    {
        tree[index] += inc;
        //Propogate the lazy value to children and return dont recursively call to its subcildren this is optimization
        if (ss != se) //not a leaf node
        {
            lazy[2 * index] += inc;
            lazy[2 * index + 1] += inc;
        }
        return ;
    }

    //partiall overlap
    int mid = (ss + se) / 2;
    UpdateRangeLazy(tree, ss, mid, l, r, inc, 2 * index);
    UpdateRangeLazy(tree, mid + 1, se, l, r, inc, 2 * index + 1);
    //Update the current node
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;

}
int querylazy(int *tree, int ss, int se, int l, int r, int index)
{
    //before going down resolve the lazy value and propogate to childrens
    if (lazy[index] != 0)
    {
        tree[index] += lazy[index];
        if (ss != se) //not a leaf node
        {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        //clear the lazy value
        lazy[index] = 0;
    }
    //no overlap
    if (ss > r or l > se)
    {
        return INT_MAX;
    }
    //complete overlap
    if (ss >= l and se <= r)
    {
        return tree[index];
    }

    //partial overload
    int mid = (ss + se) / 2;
    int left = querylazy(tree, ss, mid, l, r, 2 * index);
    int right = querylazy(tree, mid + 1, se, l, r, 2 * index + 1);
    return min(left, right);

}
void fast_io()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{

    int a[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(a) / sizeof(int);
    int * tree = new int[4 * n + 1];

    BuildTree(a, 0, n - 1, tree, 1);
    for (int i = 0; i < 1000; i++)
    {
        lazy[i] = 0;
    }
    UpdateRangeLazy(tree, 0, n - 1, 0, 2, 10, 1);
    UpdateRangeLazy(tree, 0, n - 1, 0, 4, 10, 1);
    cout << "Q1 1-1=" << querylazy(tree, 0, n - 1, 1, 1, 1) << endl;
    UpdateRangeLazy(tree, 0, n - 1, 3, 4, 10, 1);
    cout << "Q2 3-5=" << querylazy(tree, 0, n - 1, 3, 5, 1) << endl;
}