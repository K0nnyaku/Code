#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
const int N=1e5,M=1e6;
typedef pair<int,pair<int,int> >PIII;
int n,m,T;
map<pair<int,int>,int> hash1;
int cnt;
int h[N],e[M],ne[M],w[M],idx;
PIII dian[N];
int k;
bool st[N];
long long ans;
void add(int a,int b,int c){
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void deal(){
	long long res=0;
	for(int t=1;t<=n*m;t++){
		for(int i=h[t];~i;i=ne[i]){
			int j=e[i];
			if(st[t]!=st[j])res+=w[i];
		}
	}
	for(int i=1;i<=k;i++){
		int zhi=dian[i].first;
		int xian=dian[i].second.first;
		int col=dian[i].second.second;
			if(xian<=m){
				if(col^st[m]==1)res+=zhi;
			}else if(xian>m&&xian<=n+m){
				if(col^st[(xian-m)*m]==1)res+=zhi;
			}else if(xian>n+m&&xian<=2*m+n){
				if(col^st[(n-1)*m+m-(xian-n-m)+1]==1)res+=zhi;
			}else if(xian>2*m+n&&xian<=2*m+2*n){
				if(col^st[(n-(xian-2*m-n))*m+1]==1)res+=zhi;
			}
	}
	if(res==0)return;
	ans=min(ans,res);
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	memset(h,-1,sizeof h);
	cin>>n>>m>>T;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			hash1[make_pair(i,j)]=++cnt;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			scanf("%d",&x);
		int a=hash1[make_pair(i,j)];
		int b=hash1[make_pair(i-1,j)];
		add(a,b,x);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			int x;
			scanf("%d",&x);
			int a=hash1[make_pair(i,j-1)];
			int b=hash1[make_pair(i,j)];
			add(a,b,x);
		}
	}
	while(T--){
	ans=0x3f3f3f3f;
	cin>>k;
	for(int i=1;i<=k;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		dian[i]=make_pair(a,make_pair(b,c));
	}
	for(int i=1;i<1<<(n*m);i++){
		for(int j=1;j<=n*m;j++){
			if((i>>(j-1))&1)st[j]=1;
			else st[j]=0;
		}
		deal();
	}
	printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

