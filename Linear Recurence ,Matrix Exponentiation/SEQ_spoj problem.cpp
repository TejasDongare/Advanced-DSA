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
#define MOD             1000000000
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x//precision
#define mk(arr,n,type)  type *arr=new type[n];//dynamic array
#define w(x)            ll x; cin>>x; while(x--)//Test case
#define nl				cout<<endl;//new line 
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());//shuffler


ll k, n;
vector<ll> b, c;
void fast_io()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B)
{
	vector<vector<ll>> temp(k + 1, vector<ll> (k + 1));
	for (ll i = 1; i <= k; i++)
	{
		for (ll j = 1; j <= k; j++)
		{
			//temp[i][j] = 0;
			for (ll l = 1; l <= k; l++)
			{
				temp[i][j] = (temp[i][j] + (A[i][l] * B[l][j]) % MOD) % MOD;
			}
		}
	}
	return temp;
}

vector<vector<ll>> calculate_power(ll n, vector<vector<ll>> A)
{
	if (n == 1)
	{
		return A;
	}
	//power is odd
	if (n & 1)
	{
		return multiply(A, calculate_power( n - 1, A));
	}
	vector<vector<ll>> x = calculate_power(n / 2, A);
	return multiply(x, x);
}

ll compute(ll n)
{
	//Step 1. Base case
	if (n == 0)
	{
		return 0;
	}
	if (n <= k)
	{
		return b[n - 1];
	}
	vector<ll> f1(k + 1);//1 based indexing
	for (ll i = 1; i <= k; i++)
	{
		f1[i] = b[i - 1];
	}
	//Step 2.Calculate the transform matrix;
	vector<vector<ll>> Transform(k + 1, vector<ll>(k + 1));
	for (ll i = 1; i <= k; i++)
	{
		for (ll j = 1; j <= k; j++)
		{
			if (i < k)
			{
				if (j == i + 1)
				{
					Transform[i][j] = 1;
				}
				else
				{
					Transform[i][j] = 0;
				}
			}
			else
			{
				Transform[i][j] = c[k - j];
			}
		}
	}
	//Step 3.step Power of T
	Transform = calculate_power(n - 1, Transform);
	//Step 4 Matrix with A vector Multiplication we will only multiply with the first row to get nth term of A that is T^(n-1)*F1=Fn we will just multiply the first vector to get fn
	ll res = 0;
	for (ll i = 1; i <= k; i++)
	{
		res = (res + (Transform[1][i] * f1[i]) % MOD) % MOD;
	}
	return res;
}
int main()
{
	fast_io();
	ll t;
	cin >> t;
	while (t > 0)
	{
		cin >> k;
		ll num;
		for (ll i = 0; i < k; i++)
		{
			cin >> num;
			b.push_back(num);
		}
		//coefficents
		for (ll i = 0; i < k; i++)
		{
			cin >> num;
			c.push_back(num);
		}
		cin >> n;
		cout << compute(n) << endl;
		b.clear();
		c.clear();
		t--;
	}
}