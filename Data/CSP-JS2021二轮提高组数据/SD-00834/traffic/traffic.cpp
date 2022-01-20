 	//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn=10;
int n,m,T,x1[maxn][maxn],x2[maxn][maxn],x3[maxn][maxn][2],to[maxn][maxn][2],k,cnt[maxn][maxn];
inline int gc(int x,int y,int i){
	return ((i&(1<<((x-1)*n+y)))>0);
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>T;
	int num=n*m;
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			cin>>x1[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			cin>>x2[i][j];
		}
	}
	while(T--){
		memset(x3,0,sizeof(x3));
		memset(to,0,sizeof(to));
		memset(cnt,0,sizeof(to));
		cin>>k;
		for(int i=1;i<=k;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(b<=m) x3[1][b][++cnt[1][b]]=a,to[1][b][cnt[1][b]]=c;
			if(b>m&&b<=n+m) x3[b-m][m][++cnt[b-m][m]]=a,to[b-m][m][++cnt[b-m][m]]=c;
			if(b>n+m&&b<=2*m+n) x3[n][b-n-m][++cnt[n][b-n-m]]=a,to[n][b-n-m][++cnt[n][b-n-m]]=c;
			if(b>2*m+n) x3[b-2*m-n][1][++cnt[b-2*m-n][1]]=a,to[b-2*m-n][1][++cnt[b-2*m-n][1]]=c;
		}
		long long ans=1e15;
		for(int i=0;i<=(1<<num)-1;i++){
			long long res=0;
			for(int x=1;x<=n;x++){
				for(int y=1;y<=m;y++){
					int col=gc(x,y,i);
					if(col!=gc(x+1,y,i)) res+=x1[x][y];
					if(col!=gc(x,y+1,i)) res+=x2[x][y];
					if(col!=to[x][y][0]) res+=x3[x][y][0];
					if(col!=to[x][y][1]) res+=x3[x][y][1];
				}
			}
			ans=min(ans,res);
		}
		cout<<ans<<endl;
	}
	return 0;
}

