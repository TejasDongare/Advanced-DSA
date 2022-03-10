#include <bits/stdc++.h>
using namespace std;
struct sparse_table
{
    int n,m;
    vector<int> p2;
    vector<vector<int>> mat;
    void init(int n,int m)
    {
        this->n=n,
        this->m=m;
        mat.resize(n);
        p2.resize(n+1);
        for(int i=0;i<n;i++) mat[i].resize(m);
        //Log calculation inbuilt log2 function takes alot of time 
        for(int i=2;i<=n;i++) p2[i]=p2[i/2]+1;
    }
    void build(int a[])
    {
        for(int i=0;i<n;i++) mat[i][0]=a[i];
        for(int j=1;j<m;j++)
        {
            for(int i=0;(i+(1<<j)-1)<n;i++)
            {
                mat[i][j]=min(mat[i][j-1],mat[i+(1<<(j-1))][j-1]);
            }
        }
    }
    int query(int l,int r)
    {
        int range=r-l+1;
        int lg=p2[range];
        //power of 2
        if(1<<lg==range)
        {
            return mat[l][lg];
        }
        return min(mat[l][lg],mat[r-(1<<lg)+1][lg]);
        /* if we to reduce the condition of power of 2
            int lg=p2[r-l] //here suppose even if it it is power of example l=0,r=7 r-l=7 so lg=2
                            //that means length 4 so we will find minimum of 2 segments of length 4 and return
            return min(mat[l][lg],mat[r-(1<<lg)+1][lg]);//we bypassed the if condition
        */
    }
    void print()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<mat[i][j]<<" ";
            }
          //  cout<<endl;
        }
    }
};
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m=ceil(log2(n))+1;
    sparse_table sp;
    sp.init(n,m);
    sp.build(a);
  //  sp.print();
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<sp.query(l,r)<<endl;   
    }
}