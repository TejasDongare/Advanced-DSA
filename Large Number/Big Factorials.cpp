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
void multiply(int *a, int &n, int number)
{
	int carry = 0;
	for (int i = 0; i < n; i++)
	{
		int product = a[i] * number + carry;
		a[i] = product % 10;
		carry = product / 10;
	}
	while (carry)
	{
		a[n] = carry % 10;
		carry = carry / 10;
		n++;
	}
}
void big_factorial(int number)
{
	int *a = new int[1000];
	for (int i = 0; i < 1000; i++) a[i] = 0;
	a[0] = 1;
	int n = 1;
	for (int i = 2; i <= number; i++)
	{
		multiply(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		cout << a[i];
	}
}
int main()
{
	fast_io();
	int n;
	cin >> n;
	big_factorial(n);
	return 0;
}