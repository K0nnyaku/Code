#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int f=1,w=0;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		w=w*10+c-'0';
		c=getchar();
	}
	return f*w;
}
int t,n,a[5000001],tt[500005],cz[555555],visit[5555505];
int dfs(int i,int l,int r)
{
	if(i==2*n+1)
	{
		return 1;
	}
	if(!visit[a[l]]||(i>n&&a[l]==tt[2*n-i+1])){
	tt[i]=a[l],cz[i]=0,visit[a[l]]=1;
	if(dfs(i+1,l+1,r))return 1;
	visit[a[l]]=0;
	}
	if(!visit[a[r]]||(i>n&&a[r]==tt[2*n-i+1])){
		tt[i]=a[r],cz[i]=1,visit[a[r]]=1;
	if(dfs(i+1,l,r-1))return 1;
	visit[a[r]]=0;
	}
	return 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){
		n=read();
		if(n<5000000)
		{
		memset(visit,0,sizeof(visit));
		for(int i=1;i<=2*n;i++){
		a[i]=read();
		}
		if(!dfs(1,1,2*n)){
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=2*n;i++)
		if(cz[i])printf("R");else printf("L");
		printf("\n");
		}
		else {
			int k=0;
			for(int i=1;i<=n;i++){
				a[i]=read(),tt[a[i]]++;
				if(tt[a[i]]%2==0){
				printf("-1\n");	k=1;break;
				}
			}
			if(k==1)continue;
			for(int i=1;i<=n;i++)a[i]=read();
			for(int i=1;i<=2*n;i++)printf("L");
			printf("\n");
		}
	}
	return 0;
 } 
