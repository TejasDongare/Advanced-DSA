#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define ll             long long signed int
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

}
ll k, p;
vector<vector<ll>> multiplyt(vector<vector<ll>> A, vector<vector<ll>> B)
{
	vector<vector<ll>> temp(k + 1, vector<ll> (k + 1));
	for (ll i = 1; i <= k; i++)
	{
		for (ll j = 1; j <= k; j++)
		{
			temp[i][j] = 0;
			for (ll l = 1; l <= k; l++)
			{
				temp[i][j] = (temp[i][j] + (A[i][l] * B[l][j]) % p) % p;
			}
		}
	}
	return temp;
}

vector<vector<ll>> calculate_powert(ll n, vector<vector<ll>> A)
{
	if (n == 1)
	{
		return A;
	}
	//power is odd
	if (n & 1)
	{
		return multiplyt(A, calculate_powert( n - 1, A));
	}
	vector<vector<ll>> x = calculate_powert(n / 2, A);
	return multiplyt(x, x);
}

vector<ll> computet(ll n, vector<ll> f1, vector<ll> c)
{
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
				Transform[i][j] = c[k - j + 1];
			}
		}
	}
	//Step 3.step Power of T
	Transform = calculate_powert(n - 1, Transform);
	//Step 4 Matrix with A vector Multiplication we will only multiply with the first row to get nth term of A that is T^(n-1)*F1=Fn we will just multiply the first vector to get fn
	vector<ll> temp(k + 1);
	ll tp = 0;
	for (ll i = 1; i <= k; i++)
	{
		for (ll j = 1; j <= 1; j++)
		{
			tp = 0;
			for (ll l = 1; l <= k; l++)
			{
				tp = (tp + (Transform[i][l] * f1[l]) % p) % p;
			}
			temp[i] = tp;
		}
	}
	return temp;
}
vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B)
{
	vector<vector<ll>> temp(k + 2, vector<ll> (k + 2));
	for (ll i = 1; i <= k + 1; i++)
	{
		for (ll j = 1; j <= k + 1; j++)
		{
			temp[i][j] = 0;
			for (ll l = 1; l <= k + 1; l++)
			{
				temp[i][j] = (temp[i][j] + (A[i][l] * B[l][j]) % p) % p;
			}
		}
	}
	return temp;
}
vector<vector<ll>> calculate_power(ll tn, vector<vector<ll>> A)
{
	if (tn == 1)
	{
		return A;
	}
	//power is odd
	if (tn & 1)
	{
		return multiply(A, calculate_power( tn - 1, A));
	}
	vector<vector<ll>> x = calculate_power(tn / 2, A);
	return multiply(x, x);
}
ll calculatesum( ll till, vector<ll> f1, vector<ll> c)
{
	if (till == 0)
	{
		return 0;
	}

	vector<ll> cs(k + 1);
	cs[0] = 0;
	for (ll i = 1; i <= k; i++)
	{
		cs[i] = (cs[i - 1] + f1[i]) % p;
	}
	if (till <= k)
	{
		return cs[till];
	}
	//f1 matrix
	vector<ll> newf1(k + 2);
	newf1[1] = cs[k];
	for (ll i = 1; i <= k; i++)
	{
		newf1[i + 1] = f1[i];
	}
	//Transformation
	vector<vector<ll>> Trans(k + 2, vector<ll>(k + 2));

	Trans[1][1] = 1;
	Trans[1][2] = 1;
	for (ll i = 3; i <= k + 1; i++)
	{
		Trans[1][i] = 0;
	}
	for (ll i = 2; i <= k; i++)
	{
		for (ll j = 1; j <= k + 1; j++)
		{
			if (j == 1)
			{
				Trans[i][j] = 0;
			}
			else if (i <= k)
			{
				if (j == i + 1)
				{
					Trans[i][j] = 1;
				}
				else
				{
					Trans[i][j] = 0;
				}
			}
		}
	}
	Trans[k + 1][1] = 0;
	ll id = k;
	for (ll i = 2; i <= k + 1; i++)
	{
		Trans[k + 1][i] = c[id];
		id--;
	}

	f1 = computet(k + 1, f1, c);
	for (ll i = 2; i <= k + 1; i++)
	{
		newf1[i] = f1[i - 1];
	}
	till = till - k;
	if (till > 1)
	{
		Trans = calculate_power(till , Trans);
	}

	ll res = 0;
	for (ll i = 1; i <= k + 1; i++)
	{
		res = (res + (Trans[1][i] * newf1[i]) % p) % p;
	}
	return res;
}
int main()
{
	fast_io();
	ll t;
	cin >> t;
	ll temp;
	vector<ll> f1;
	vector<ll> c;
	ll m, n;
	while (t--)
	{
		f1.push_back(0);//Pushing garbage value so that indexing starts from 0
		c.push_back(0);//Pushing Garbage Value so that indexing strarts from 0
		cin >> k;
		for (ll i = 1; i <= k; i++)
		{
			cin >> temp;
			f1.push_back(temp);
		}
		for (ll i = 1; i <= k; i++)
		{
			cin >> temp;
			c.push_back(temp);
		}
		cin >> m >> n >> p;
		//cout<<calculatesum(0,f1,c)<<endl;
		ll a1 = calculatesum(n, f1, c);

		ll a2 = calculatesum(m - 1, f1, c);
		ll temp = (a1 - a2) % p;
		if (temp < 0)
		{
			temp = temp + p;
		}
		cout << temp << endl;
		c.clear();
		f1.clear();
	}
	return 0;
}