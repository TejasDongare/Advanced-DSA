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
int fast_exponentiation(int n, int p)
{
	int power = n;
	int answer = 1;
	while (p > 0)
	{
		int last_bit = p & 1;
		if (last_bit)
		{
			answer *= (power * last_bit);
		}
		power = power * power;
		p = p >> 1;
	}
	return answer;
}
int main()
{
	fast_io();
	char a[20];
	cin >> a;
	int len = strlen(a);
	ll ans = 0;
	//2^0+2^1+2^2.....2^(len-1)=2^(len) -2
	ans = (1 << len) - 2;
	ll pos = 0;
	for (int i = len - 1; i >= 0; pos++, i--)
	{
		if (a[i] == '7')
		{
			ans += (1 << pos);
		}
	}
	//ans will contain the number of numbers contains smaller than this number
	cout << ans + 1 << endl;
	return 0;
}