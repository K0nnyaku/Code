#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
int T , n , a[N] , ans = -1 , b[N] , d[N] ;
char c[N] , f[N];
void dfs(int len , int head , int tail)
{
	if(len == 2 * n)
	{
		int i = 1 , j = 2 * n;
		while(c[i] == c[j])
		{
			i ++;
			j --;
		}
		if(i != j - 1)
		return ;
		ans = 1;
		i = 1;
		while (b[i] == d[i])
		{
			i ++;
		}
		if(b[i] > d[i])
		{
			for(int j = 1 ; j <= 2*n ; j ++)
			{
			b[j] = d[j];
			c[j] = f[j];
			}
		}
		return ;
	}
	b[2*n - len] = a[head];
	f[len + 1] = 'L';
	dfs(len + 1 , head + 1 , tail);
	b[2*n - len] = a[tail];
	f[len + 1] = 'R';
	dfs(len + 1 , head , tail - 1);
}
int main()
{
	freopen("palin.in" , "r" , stdin);
	freopen("palin.out" , "w" , stdout); 
	cin >> T;
	while(T --)
	{
		ans = -1;
		cin >> n ;
		for(int i = 1 ; i <= 2 * n ; i ++)
		cin >> a[i];
		dfs(0 , 1 , n);
		if(ans != -1)
		{
			for(int i = 1 ; i <= 2*n ; i ++)
			cout << c[i];
		}
		else cout <<"-1";
		cout << endl;
	}
	return 0;
}
