#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define ll             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define mii             map<ll,ll>
#define pqmx             priority_queue<ll>//max heap
#define pqmn             priority_queue<ll,vi,greater<ll> >//min heap
#define setbits(x)      __builtin_popcountll(x)//Number of set bits in a number
#define zerobits(x)      __builtin_ctzll(x)//number of zeros after the first 1 from right example 1010=1 only 1 one after the first one from right
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x//precision
#define mk(arr,n,type)  type *arr=new type[n];//dynamic array
#define w(x)            ll x; cin>>x; while(x--)//Test case
#define nl				cout<<endl;//new line 
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());//shuffler



void fast_io()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int setbitfind(int a, int n)
{
	int pos = 0;
	while (a > 0)
	{
		if (a & 1)
		{
			break;
		}
		pos++;
		a    = a >> 1;
	}
	return pos;
}
int main()
{
	fast_io();
	int n;
	cin >> n;
	int a[n];
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		ans = ans ^ a[i];
	}
	int pos = setbitfind(ans, n);
	int temp = ans;
	for (int i = 0; i < n; i++)
	{
		if (a[i] & (1 << pos))
		{
			temp = temp ^ a[i];
		}
	}
	if (temp < (temp ^ ans))
	{
		cout << temp << " " << (temp ^ ans) << endl;
	}
	else
	{
		cout << (temp ^ ans) << " " << temp << endl;

	}
	return 0;
}