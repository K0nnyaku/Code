#include<bits/stdc++.h>
using namespace std;
int a[500005];int n;
int b[1000005];
char path[1000005];
bool F=0;
void dfs(int la,int ra,int x)
{
	if(F==1) return;
	if(x==n*2)
	{
		bool flag=1;
		int l=0,r=n*2-1;
		while(r>l)
		{
			if(b[r]!=b[l])
			{
				flag=0;
				break;
			}
			r--;
			l++;
		}
		if(flag==1)
		{
			F=1;
			for(int i=1;i<=n*2;i++)
			{
				cout<<path[i];
			}
			cout<<endl;
		}
		return;
	}
	b[x]=a[la];
	path[x+1]='L';
	dfs(la+1,ra,x+1);
	b[x]=a[ra];
	path[x+1]='R';
	dfs(la,ra-1,x+1);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;cin>>T;
	while(T>0)
	{
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)
		{
			scanf("%d",&a[i]);
		}
		F=0;
		dfs(1,n*2,0);
		if(F==0) printf("-1\n");
		T--;
	}
	return 0;
}
