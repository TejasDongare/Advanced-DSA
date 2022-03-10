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



void fast_io()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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
int main() {
	ll t;
	cin >> t;
	ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
	while (t > 0) {
		ll n;
		cin >> n;
		ll subsets = (1 << 8) - 1;
		ll ans = 0;
		for (ll i = 1; i <= subsets; i++) {
			ll denom = 1ll;
			ll sb = __builtin_popcount(i);
			for (ll j = 0; j <= 7; j++)
			{
				if (i & (1 << j))
				{
					denom = denom * primes[j];
				}
			}
			ans = ((sb & 1) ? ans + (n / denom) : ans - (n / denom));
		}
		cout << ans << endl;
		t--;
	}
	return 0;
}
