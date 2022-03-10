/*
    INPUT:-
    10
    1 2
    1 4
    2 8
    8 6
    8 10
    6 9
    4  3
    4 5
    5 7
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<int> gr[N];
int dp[N];
void dfs(int curr, int par)
{
    dp[curr] = curr;
    for (auto x : gr[curr])
    {
        if (x != par)
        {
            dfs(x, curr);
            dp[curr] = min(dp[curr], dp[x]);
        }
    }

    return ;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    //Tree is rooted on 1
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << dp[i] << endl;
    }
}