#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;
#define N 1005
int t,n,a[N * 2],b[N * 2],f,r,top;
bool flag;
char s[N];
bool pan()
{
	for(int i = 1,j = top;i < j;i++,j--)
	{
		if(b[i] != b[j]) return 0;
	}
	return 1;
}
void dfs(int h)
{
	if(h == n + 1)
	{
		for(int i = 1;i <= n;i++)
			{
				cout << s[i];
			}
			cout << endl;
//		for(int i = 1;i <= n;i++)
//		{
//			if(s[i] == 'L')
//				b[++top] = a[f++];
//			else
//				b[++top] = a[r++];
//		}
//		if(pan())
//		{
//			for(int i = 1;i <= n;i++)
//			{
//				cout << s[i];
//			}
//			cout << endl;
//			flag = 1;
//		}
		return;
	}
	for(int i = 1;i <= 2;i++)
	{
		if(i == 1) s[h] = 'L';
		else s[h] = 'R';
		dfs(h + 1);
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",t);
	for(int o = 1;o <= t;o++)
	{
		scanf("%d",n);
//		flag = 0;
//		f = 1;r = 2 * n;
		for(int i = 1;i <= n * 2;i++)
		{
			scanf("%d",a[i]);
		}
		cout << "-1" << endl;
//		dfs(1);
//		if(!flag) printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
