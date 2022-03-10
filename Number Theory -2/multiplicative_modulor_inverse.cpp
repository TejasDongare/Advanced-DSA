#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define ll             long long int
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

#define primemax 100005
vector<int> primes;
void fast_io()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
ll x, y, GCD;
void ExtendedEucledMethod(ll a, ll b)
{
	//Base Case
	if (b == 0)
	{
		x = 1;
		y = 0;
		GCD = a;
		return;
	}
	ExtendedEucledMethod(b, a % b);
	//Recursive Case
	ll cx = y;
	ll cy = x - (a / b) * y;
	x = cx;
	y = cy;
}
//It exists only if the gcd of a,m is 1
ll multiplicative_modulo_inverse(ll a, ll m)
{
	ExtendedEucledMethod(a, m);
	//to avoid negative values
	return (x + m) % m;
}
int main()
{
	fast_io();
	cout << multiplicative_modulo_inverse(6, 7) << endl;
	return 0;
}