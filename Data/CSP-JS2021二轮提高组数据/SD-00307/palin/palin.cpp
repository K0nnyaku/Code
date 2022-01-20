#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=500010;
int n,a[2*N],l,r;
bool v[N];
char ans[2*N];
int res[2*N],tot;
bool ispalin(int t,int x[])
{
	for(int i=1;i<=t;i++)
		if(x[i]!=x[2*n-i+1]) return false;
	return true;
}
bool sep()
{
	memset(v,0,sizeof v);
	for(int i=1;i<=n;i++)
	{
		if(!v[a[i]])
			v[a[i]]=1;
		else
		{
			l=i;
			break;
		}
	}
	for(int i=2*n;i>=n+1;i--)
	{
		if(!v[a[i]])
			v[a[i]]=1;
		else
		{
			r=i;
			break;
		}
	}
	if(r-l+1!=n) return false;
	return true;
}
bool check()
{
	tot=0;
	int head=1,tail=2*n;
	for(int i=1;i<=2*n;i++)
	{
		if(ans[i]=='L') res[++tot]=a[head++];
		else res[++tot]=a[tail--];
	}
	return ispalin(tot,res);
}
bool dfs(int x)
{
	if(x==2*n+1)
	{
		if(check())
		{
			/*for(int i=1;i<=2*n;i++)
				cout<<ans[i];
			cout<<endl;*/
			printf("%s\n",ans+1);
			return true;
		}
		return false;
	}
	ans[x]='L';
	if(dfs(x+1)) return true;
	ans[x]='R';
	if(dfs(x+1)) return true;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof a);
		memset(ans,0,sizeof ans);
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			scanf("%d",&a[i]);
		bool flag=ispalin(n,a);
		if(!flag&&a[1]==a[2*n])
		{
			puts("-1");
			continue;
		}
		else if(flag)
		{
			for(int i=1;i<=2*n;i++)
				printf("L");
			puts("");
			continue;
		}
		if(!sep())
		{
			puts("-1");
			continue;
		}
		if(n<=10) dfs(1);
		else
		{
			int l1=1,r1=2*n,l2=r,r2=l;
			for(int i=1;i<=n;i++)
			{
				if(l1<l&&r2<=l2&&a[l1]==a[r2])
				{
					ans[i]='L';
					ans[2*n-i+1]='L';
					l1++;r2++;
				}
				else if(l1<l&&l2>=r2&&a[l1]==a[l2])
				{
					ans[i]='L';
					ans[2*n-i+1]='R';
					l1++;l2--;
				}
				else if(r1>r&&r2<=l2&&a[r1]==a[r2])
				{
					ans[i]='R';
					ans[2*n-i+1]='L';
					r1--;r2++;
				}
				else if(r1>r&&l2>=r2&&a[r1]==a[l2])
				{
					ans[i]='R';
					ans[2*n-i+1]='R';
					r1--;l2--;
				}
			}
			for(int i=n+1;i<=2*n;i++)
			if(ans[i]=='L') ans[i]='R';
			else ans[i]='L';
			ans[2*n]='L';
			/*for(int i=1;i<=2*n;i++)
				cout<<ans[i];
			cout<<endl;*/
			printf("%s\n",ans+1);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
