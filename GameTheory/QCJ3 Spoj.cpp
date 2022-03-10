#include <iostream>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n+1];
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]&1)
            {
                ans=ans^(i);
            }
        }
        if(ans==0)
        {
            cout<<"Hanks Wins"<<endl;
        }
        else
        {
            cout<<"Tom Wins"<<endl;
        }
    }
}