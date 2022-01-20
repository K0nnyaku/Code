#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n , k , sum , ans;
char c[1000];
int main()
{
	freopen("bracket.in" , "r" , stdin);
	freopen("bracket.out" , "w" , stdout);
	cin >> n >> k;
	int flag = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
	cin >> c[i];
	if(c[i] == '(' || c[i] == ')')
	sum ++;	
	}
	if(n == 1 || c[1] == '*' || c[n] == '*' || c[1] == ')' || c[n] == '(')
	{
		cout << "0";
		return 0;
	}
	if(c[1] != '(')
	sum ++;
	if(c[n] != ')')
	sum ++;
	c[1] = '(' ; c[n] = ')';
	int m = 0;
	for(int i = 1 ; i<= n ; i ++)
	{
		if(c[i] == '?')
		m ++;
		m %= mod;
	}
	cout << (m * m - m - 1) % mod;
	return 0;
}
