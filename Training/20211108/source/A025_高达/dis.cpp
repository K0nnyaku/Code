#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int f[1010][1010];
bool vis[1010];
int n,m;
char c;
int k;
inline void floyd()
{
	for(int kk=1;kk<=n;kk++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][kk]+f[kk][j]);
	return;
}
inline void work()
{
	for(int i=1;i<=m;i++){
		cin>>c;
		if(c=='?'){
			floyd();
			scanf("%d",&k);
			int ans=0;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(f[i][j]!=0x3f3f3f3f&&f[i][j]<=k)
						ans++;
			cout<<ans<<endl;	
		}
		else{
			scanf("%d",&k);
			vis[k]=1;
			memset(f,0x3f3f3f3f,sizeof(f));
			for(int i=1;i<=n;i++){
				f[i][i]=0;
				if(vis[i]) continue;
				f[i][i/2]=1,f[i/2][i]=1;
			}
		}
	}
}
int main()
{
	freopen("dis.in","r",stdin);
	freopen("dis.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(f,0x3f3f3f3f,sizeof(f));
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int i=1;i<=n;i++)
		f[i][i/2]=1,f[i/2][i]=1;
	if(n<=1000&&m<=1000){
		work();
		return 0;
	}
	else{
		int p;
		for(int i=1;i<=m;i++){
			cin>>c;
			scanf("%d",&p);
			if(c=='?')
				cout<<1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
