#include<iostream>
#include<vector>
#define ll long long int
#define mod 1000000007
using namespace std;
vector<vector<ll>> mul(vector<vector<ll>> A, vector<vector<ll>> B)
{
	vector<vector<ll>> answer(4, vector<ll>(4));
	for (ll i = 1; i <= 3; i++)
	{
		for (ll j = 1; j <= 3; j++)
		{
			answer[i][j] = 0;
			for (ll k = 1; k <= 3; k++)
			{
				answer[i][j] = (answer[i][j] + (A[i][k] * B[k][j]) % mod) % mod;
				//	cout<<i<<"=i, j="<<j<<" k="<<k<<" a="<<A[i][k]<<" b="<<B[k][j]<<" " <<answer[i][j]<<endl;
			}
		}
	}
	return answer;
}
vector<vector<ll>> power(ll n, vector<vector<ll>> v)
{
	if (n == 1)
	{
		return v;
	}
	if (n & 1)
	{
		return mul(v, (power(n - 1, v)));
	}
	vector<vector<ll>> temp = power(n / 2, v);
	return mul(temp, temp);
}
ll compute(ll n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 0;
	}
	if (n == 2)
	{
		return 1;
	}
	//Transformation
	vector<vector<ll>> Trans(4, vector<ll>(4));
	Trans[1][1] = 1;
	Trans[1][2] = 1;
	Trans[1][3] = 0;
	Trans[2][1] = 0;
	Trans[2][2] = 0;
	Trans[2][3] = 1;
	Trans[3][1] = 0;
	Trans[3][2] = 1;
	Trans[3][3] = 1;
	//f1 vector
	vector<ll> f1(3);
	f1[1] = 1;
	f1[2] = 1;
	f1[3] = 2;
	n = n - 2;
	if (n > 1)
	{
		Trans = power(n, Trans);
	}
	ll finalanswer = 0;
	for (ll i = 1; i <= 3; i++)
	{
		//cout<<"T="<<Transform[1][i]<<" f1[i]="<<f1[i]<<endl;
		finalanswer = (finalanswer + (Trans[1][i] * f1[i]) % mod) % mod;
	}
	return finalanswer;
}
int main () {
	int t;
	cin >> t;
	while (t--)
	{
		ll n, m;
		cin >> n >> m;
		cout << ((compute(m + 1) - compute(n) + mod) % mod) << endl;
	}
}