#include <iostream>
#include<vector>
#define ll long long int
#define mod 98765431
using namespace std;
ll n, steps;
vector<ll> f1;
vector<vector<ll>> mul(vector<vector<ll>> A, vector<vector<ll>> B)
{
    vector<vector<ll>> answer(n + 1, vector<ll>(n + 1));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            answer[i][j] = 0;
            for (ll k = 1; k <= n; k++)
            {
                answer[i][j] = (answer[i][j] + (A[i][k] * B[k][j]) % mod) % mod;
            }
        }
    }
    return answer;
}
vector<vector<ll>> power(ll st, vector<vector<ll>> Trans)
{
    if (st == 1)
    {
        return Trans;
    }
    if (st & 1)
    {
        return mul(Trans, power(st - 1, Trans));
    }
    vector<vector<ll>> tr = power(st / 2, Trans);
    return mul(tr, tr);
}
vector<ll> compute()
{
    //Transformation Matrix
    vector<vector<ll>> Trans(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                Trans[i][j] = 0;
            }
            else
            {
                Trans[i][j] = 1;
            }
        }
    }

    if (steps > 1)
    {
        Trans = power(steps, Trans);
    }

    vector<ll> result(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 1; j++)
        {
            ll temp = 0;
            for (int k = 1; k <= n; k++)
            {
                //cout<<"Trans[i][k]="<<Trans[i][k]<<" f1[k]="<<f1[k]<<" temp before="<<temp<<" Temp After="<<(temp+(Trans[i][k]*f1[k])%mod)%mod<<endl;
                temp = (temp + (Trans[i][k] * f1[k]) % mod) % mod;
            }
            result[i] = temp;
        }
    }
    return result;
}
int main() {
    cin >> n >> steps;
    f1.push_back(0);//Garbage value to start from indexing 1
    ll temp;
    for (ll i = 1; i <= n; i++)
    {
        cin >> temp;
        f1.push_back(temp);
    }
    f1 = compute();
    for (int i = 1; i <= n; i++)
    {
        cout << f1[i] << endl;
    }
}