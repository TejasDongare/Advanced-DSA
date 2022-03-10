#include <iostream>
using namespace std;
int BIT[100005]={0};
void update(int i,int inc,int N)
{
    while(i<=N)
    {
        BIT[i]+=inc;
        i+=(i&(-i));
    }
}
int query(int i)
{
    int ans=0;
    while(i>0)
    {
        ans+=BIT[i];
        i-=(i&(-i));
    }
    return ans;
}
int main() 
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        update(i,a[i],n);
    }
    //Query
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(r)-query(l-1)<<endl;
    }
}
