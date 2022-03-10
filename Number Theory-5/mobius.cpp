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
#define MAX 			100005
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
int a[MAX], prime_count[MAX], mobius[MAX];
//nloglogn like sieve
void calculate_mobius()
{
	for (int i = 1; i < MAX; i++)
	{
		a[i] = 1;
	}
	for (int i = 2; i < MAX; i++)
	{
		if (prime_count[i]) continue;
		for (int j = i; j < MAX; j += i)
		{
			prime_count[j]++;
			a[j] *= i;
		}
	}
	//a[1] is always 1
	for (int i = 1; i < MAX; i++)
	{
		//square free number
		if (a[i] == i)
		{
			if (prime_count[i] % 2 == 0)
			{
				mobius[i] = 1;
			}
			else
			{
				mobius[i] = -1;
			}
		}
		else
		{
			mobius[i] = 0;
		}
	}
}
int main()
{
	fast_io();
	calculate_mobius();
	for (int i = 1; i <= 10; i++)
	{
		cout << mobius[i] << " ";
	}
	return 0;
}