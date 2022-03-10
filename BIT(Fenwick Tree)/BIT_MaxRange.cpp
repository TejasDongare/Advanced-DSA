#include <iostream>
#include<climits>
using namespace std;
int BIT[100005];
void updatebit()
{
    for(int i=0;i<100005;i++)
    {
        BIT[i]=INT_MIN;
    }
}
void update(int i,int val,int n)
{
    while(i<=n)
    {
        BIT[i]=max(BIT[i],val);
        i+=(i&(-i));
    }
}
int query(int i,int n)
{
    int ans=INT_MIN;
    while(i>0)
    {
        ans=max(ans,BIT[i]);
        i-=(i&(-i));
    }
    return ans;
}
int main() {
    updatebit();
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        update(i,a[i],n);
    }
    //here we cannot query for L to R we can find maximum till R directly as BIT can be used for prefix kinda problems only
    int q;
    cin>>q;
    while(q--)
    {
        int q1;
        cin>>q1;
        cout<<query(q1,n)<<endl;
    }
}
