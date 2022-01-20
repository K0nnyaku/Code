#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#define ll long long
using namespace std;
int ans[100001];
int n,num[101000]; 
int a[100001];
int cnt=1;
int dfs(int l,int r)
{
	if(cnt==2*n) {
		for(int i=1;i<=n;i++)
		{
			if(num[i]!=num[2*n-i+1]) return 0;
		}
		return 1;
	}
	cnt++;
	ans[cnt]=1;
	num[n-cnt+1]=a[l];
	dfs(l+1,r); cnt--;
	cnt++;
	ans[cnt]=0;
	num[n-cnt+1]=a[r];
	dfs(l,r-1);
	cnt--;
	
	return 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T; cin>>T;
	while(T)
	{
		cin>>n;
		memset(a,0,sizeof a);
		memset(num,0,sizeof num);
		memset(ans,0,sizeof ans);
		for(int i=1;i<=2*n;i++) cin>>a[i];
		if(dfs(1,2*n)) 
		{
			for(int i=1;i<=2*n;i++) 
			{
				if(ans[i]) cout<<'L';
				else cout<<'R';
			}
		}
		else cout<<-1;
		T--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

