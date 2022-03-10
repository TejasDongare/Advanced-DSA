/*Vivek likes to solve mathematical problems. So, Dheer tries to challenge him with a problem. But Vivek is quite busy these days, So he asks for your help.

The problem is as follows: You are given an integer q which denotes the number of queries. For each query, You are given an integer n. You have to find the result of number n.

The result of a number n is defined as the sum of even divisors of n minus the sum of odd divisors of n.

More Formally, result = (Sum of even divisors of n) - (Sum of odd divisors of n)

A divisor of a number n is defined as a positive integer i such that n is divisible by i.

Input Format
First line of input contains an integer q denoting the number of queries. After that q lines follow, Each line consists an integer n for which you have to find the value of result.

Note: Use fast input output as input is quite large;*/
#include<iostream>
using namespace std;
int sum[100005] = {0};
void sieve()
{
	for (int i = 1; i < 100005; i++)
	{
		for (int j = i; j < 100005; j += i)
		{
			if (i % 2 == 0)
			{
				sum[j] += i;
			}
			else
			{
				sum[j] -= i;
			}
		}
	}
}
int main() {
	sieve();
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << sum[n] << endl;
	}
}