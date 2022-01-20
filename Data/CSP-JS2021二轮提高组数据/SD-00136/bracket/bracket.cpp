#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=510;
const int mod=1e9+7;
int n,k;
int a[N],f[N][N][2],vis[N][N];
string s;
signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=1;i<=n;++i)
	  a[i]=s[i-1];
	for(int i=1;i<n;++i)
	  vis[i][i+1]=1;
	for(int i=1;i<n-1;++i)
	  if(a[i+1]=='*'||a[i+1]=='?')
	    vis[i][i+2]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+3;j<=n;++j)
		{
			int flag=0;
			for(int g=i+1;g<=j-1;++g){
				if(a[g]!='*'&&a[g]!='?'){
					flag=1;
					break;
				}
			}
			if(flag==0) vis[i][j]=1;
		}
	}
//	for(int i=1;i<=n;++i){
//		printf("%-3d",i);
//	}
//	puts("");
//	for(int i=1;i<=n;++i)
//	{
//		printf("%-3c",a[i]);
//	}
	for(int len=2;len<=n;++len)
	{
		for(int i=1;i+len-1<=n;++i)
		{
			int j=i+len-1;
			if(a[i]=='*'||a[i]==')'||a[j]=='('||a[j]=='*') continue;
//			if(i==7){
//				cout<<"ljh";
//			}			
//			if(i==69&&j==76) cout<<"---"<<vis[i][j]<<"---";
			if(vis[i][j]&&len-2<=k) f[i][j][1]++;
			for(int g=i+1;g<=i+k+1;++g)
			{
				if(g>=j-1) break;
				if(vis[i][g]==0) break;
				f[i][j][1]+=f[g][j-1][0]+f[g][j-1][1];
				f[i][j][1]%=mod;
			}
			for(int g=j-1;g>=j-k-1;--g)
			{
				if(g<=i+1) break;
				if(vis[g][j]==0) break;
				f[i][j][1]+=f[i+1][g][0]+f[i+1][g][1];
				f[i][j][1]%=mod;
			}
			f[i][j][1]-=f[i+1][j-1][0]+f[i+1][j-1][1];
			f[i][j][1]%=mod;
			for(int g=i+1;g<=j;++g)
			  {
			  	for(int w=g+1;w<=j;++w)
			  	{
			  		if(vis[g][w]==0) break;
			  		if(w-g-1>k) break;
			  		f[i][j][0]+=(f[i][g][1]*f[w][j][0])%mod;
			  		f[i][j][0]%=mod;
			  		f[i][j][0]+=(f[i][g][1]*f[w][j][1])%mod;
			  		f[i][j][0]%=mod;
				}
			  }
//			cout<<i<<" "<<j<<" "<<f[i][j][0]<<" "<<f[i][j][1]<<endl;  
		}
	}
	cout<<((f[1][n][0]+f[1][n][1])%mod+mod)%mod; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
7 3
(*??*??
*/
/*
10 2
???(*??(?)
*/
/*
100 18
?*?????)?????*????????*??(*???????*????????????*???*?????*?????*??????*****??*??????????*???????????
*/
