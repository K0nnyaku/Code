#include<bits/stdc++.h>
using namespace std;

int t;
int n;
int a[5000];
int s[5000];

int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	cin >> t;
	while(t --)
	{
		bool fflag = 0;
		cin >> n;
		n *= 2;
		for(int i = 1; i <= n; i ++)
		{
			cin >> a[i];
		}
		for(int i = 0; i < (1ll << n); i ++)
		{
			int head = 1, tail = n;
			for(int j = n - 1; j >= 0; j --)
			{
				if(i & (1ll << j))
				{
					s[j] = a[tail];
					tail --;
				}
				else
				{
					s[j] = a[head];
					head ++;
				}
			}
			bool flag = 1;
			for(int j = 0; j < n; j ++)
			{
				if(s[j] != s[n - j - 1])
				{
					flag = 0;
					break;
				}
			}
			if(flag == 1)
			{
				for(int j = n - 1; j >= 0; j --)
				{
					if(i & (1ll << j)) cout << "R" ;
					else cout << "L";
				}
				fflag = 1;
				break;
			}
		}
		if(!fflag) cout << -1;
		cout << endl;
	}
	return 0;
}
