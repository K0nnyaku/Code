#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[1000010];
bool vis[1000010];
char ans[1000010],res[1000010];
bool okk;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
		{
			ans[i]=res[i]='z';
		}
		for(int i=1;i<=2*n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int q=0;q<=n;q++)
		{
			for(int i=1;i<=2*n;i++)
			{
				vis[i]=0;
			}
			bool flag=0;
			for(int i=1;i<=n;i++)
			{
				if(vis[a[i+q]])
				{
					flag=1;
					break;
				}
				vis[a[i+q]]=1;
			}
			if(flag)
			{
				continue;
			}
			int l1=q+1,r1=q+n,l2=q,r2=q+n+1;
			int l=n,r=n+1;
			bool god=0;
			while(1)
			{
				if(l==0&&r==2*n+1)
				{
					okk=1;
					god=1;
					break;
				}
				if(a[r1]==a[r2])
				{
					ans[l]='R';
					ans[r]='R';
					r1--;
					r2++;
				}
				else if(a[l1]==a[r2])
				{
					ans[l]='R';
					ans[r]='L';
					l1++;
					r2++;
				}
				else if(a[l1]==a[l2])
				{
					ans[l]='L';
					ans[r]='L';
					l1++;
					l2--;
				}
				else if(a[r1]==a[l2])
				{
					ans[l]='L';
					ans[r]='R';
					r1--;
					l2--;
				}
				else
				{
					flag=1;
					break;
				}
				l--;
				r++;
			}
			if(!flag&&god)
			{
				for(int i=1;i<=2*n;i++)
				{
					if(ans[i]<res[i])
					{
						for(int j=1;j<=2*n;j++)
						{
							res[j]=ans[j];
						}
						break;
					}
				}
			}
		}
		if(okk)
		{
			res[2*n]='L';
			for(int i=1;i<=2*n;i++)
			{
				printf("%c",res[i]);
			}
			printf("\n");
		}
		else
		{
			printf("-1\n");
		}
		okk=0;
	}
	return 0;
}
