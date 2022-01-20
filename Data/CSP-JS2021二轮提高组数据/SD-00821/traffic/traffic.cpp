#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,T,mp[510][510][14],k,ty[510][510],minn;
int xt[14]= {1,0,-1,0};
int yt[14]= {0,1,0,-1};
int memyzh() {
	minn=0x3f3f3f3f;
	for(int i=0; i<=m; ++i) {
		mp[0][i][1]=0;
		mp[0][i][2]=0;
		mp[0][i][3]=0;
		mp[0][i][4]=0;
		mp[n+1][i][1]=0;
		mp[n+1][i][2]=0;
		mp[n+1][i][3]=0;
		mp[n+1][i][4]=0;
		ty[0][i]=-1;
		ty[n+1][i]=-1;
	}
	for(int i=0; i<=n; ++i) {
		mp[i][0][1]=0;
		mp[i][0][2]=0;
		mp[i][0][3]=0;
		mp[i][0][4]=0;
		mp[i][m+1][1]=0;
		mp[i][m+1][2]=0;
		mp[i][m+1][3]=0;
		mp[i][m+1][4]=0;
		ty[i][0]=-1;
		ty[i][m+1]=-1;
	}
}
void add(int x,int p,int t) {
	if(p<=m) {
		mp[0][p][1]=x;
		mp[1][p][3]=x;
		ty[0][p]=t;
	}
	else if(p>m&&p<=m+n){
		p-=m;
		mp[p][m+1][4]=x;
		mp[p][m][2]=x;
		ty[p][m+1]=t;
	}
	else if(p>m+n&&p<=2*m+n){
		p=p-m-n;
		p=m-p+1;
		mp[n+1][p][3]=x;
		mp[n][p][1]=x;
		ty[0][p]=t;
	} 
	else if(p>2*m+n&&p<=2*(m+n)){
		p=p-2*m-n;
		p=n-p+1;
		mp[p][0][2]=x;
		mp[p][1][4]=x;
		ty[p][0]=t;
	}
}
void dfs(int i,int j){
	if(i>n){
		int ans=0;
		for(int i=0;i<=n;++i){
			for(int j=0;j<=m;++j){
//				cout<<ty[i][j]<<" ";
				for(int k=0;k<2;++k){
//					if(j==0&&!k) continue;
//					if(i==0&&k==1) break;
					if(ty[i][j]!=ty[i+xt[k]][j+yt[k]]){
//						cout<<i<<" "<<j<<" "<<k<<endl;
						ans+=mp[i][j][k+1];
						if(mp[i][j][k+1]){
//							cout<<i<<" "<<j<<" "<<k+1<<" "<<mp[i][j][k+1]<<endl;
						}
					}
				}
			}
//			cout<<endl;
		}
		
//		cout<<ans<<endl;
		minn=min(minn,ans);
		return;
	}
	ty[i][j]=0;
	if(j==m) dfs(i+1,1);
	else dfs(i,j+1);
	ty[i][j]=1;
	if(j==m) dfs(i+1,1);
	else dfs(i,j+1);
}
int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1; i<n; ++i) {
		for(int j=1; j<=m; ++j) {
			int t;
			scanf("%d",&t);
			mp[i][j][1]=t;
			mp[i+1][j][3]=t;
		}
	}
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<m; ++j) {
			int t;
			scanf("%d",&t);
			mp[i][j][2]=t;
			mp[i][j+1][4]=t;
		}
	}
	while(T--) {
		scanf("%d",&k);
		memyzh();
		for(int i=1; i<=k; ++i) {
			int x,p,t;
			scanf("%d%d%d",&x,&p,&t);
			add(x,p,t);
		}
		dfs(1,1);
		printf("%d\n",minn);
	}
	return 0;
}
