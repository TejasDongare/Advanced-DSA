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
vector<ll> primes;
void fast_io()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input_miler.txt", "r", stdin);
	freopen("output_miler.txt", "w", stdout);
#endif
}
//(a^b)%n
ll modular_multiplication(ll a, ll b, ll n)
{
	ll res = 0;
	while (b)
	{
		if (b & 1ll)
		{
			res = res + a;
			res = res % n;
		}
		a = (a * 2) % n;
		b = b / 2;
	}
	return res;
}
ll modular_exponentiation(ll a, ll b, ll n)
{
	ll res = 1;
	while (b)
	{
		if (b & 1ll)
		{
			res = modular_multiplication(res, a, n); //Range is 10^18 that is res can be upto 10^18 and a can also be 10^18 so to avoid overflow
			res %= n;
		}
		a = modular_multiplication(a, a, n) % n;
		b /= 2;
	}
	return res;
}
//Time complexity:-klog^3(n) and k is the random numbers that is the sizeof
// the array of primes here it is 9 which is 9(logn^3)= (logn^3)
bool miller_rabin(ll n)
{
	if (n == 1)	return false;
	if (n == 2)	return true;
	if (n % 2 == 0)	return false;
	//Now n is odd
	ll d = n - 1, s = 0;
	//to make d as odd
	while (d % 2 == 0)
	{
		s++;
		d = d / 2;
	}
	//n-1=d*(2^s)
	//d is an odd number
	vector<ll> a({2, 3, 5, 7, 11, 13, 17, 19, 23});
	for (ll i = 0; i < a.size(); i++)
	{
		//	cout << a[i] << " " << n - 2 << endl;
		if (a[i] > n - 2)
		{
			//		cout << "Inside" << endl;
			continue; //This means we dont need this number
		}
		//(a[i]^d)%n

		ll ad = modular_exponentiation(a[i], d, n);
		if (ad % n == 1) continue;
		bool prime = false;
		for (ll r = 0; r <= s - 1; r++)
		{
			//(2^r)%n
			ll rr = modular_exponentiation(2, r, n);
			ll ard = modular_exponentiation(ad, rr, n);
			//cout << "rr=" << rr << " ard=" << ard << " r=" << r << " n=" << n << endl;;
			if (ard % n == n - 1)
			{
				prime = true;
				break;
			}
		}
		if (prime == false) return false;
	}
	return true;
}
//here the number 3825123056546413051 will show prime even though it is not prime it is the maximum limit approx3*10^(18)
//this is maximum limit below this all number will show the right answer all the number stictly less than 3825123056546413051 will give right answer
void solve()
{
	ll n;
	cin >> n;
	if (miller_rabin(n))
	{
		cout << "Prime\n";
	}
	else
	{
		cout << "Not prime\n";
	}
}

int main()
{
	fast_io();
	ll t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}