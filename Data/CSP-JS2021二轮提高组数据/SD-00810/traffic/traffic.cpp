#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#define ll long long
using namespace std;
ll re(){
	ll x=0;int f=1;char t=getchar();
	while(t<'0'||t>'9'){if(t=='-')f=-1;t=getchar();}
	while(t>='0'&&t<='9')x=x*10+t-'0',t=getchar();
	return x*f;
}
const int N=510,dx[6]={0,-1,1,0,0},dy[6]={0,0,0,-1,1};
struct date{
	int x,y,v;
};
date l[N*N];
int n,m,t,k,f1,pda,sum0,sum1,head,tail;
int yh[N][N],ys[N][N],h[N][N],s[N][N],d[N][N];
ll ans;
void fz(){
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
			s[i][j]=ys[i][j];
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
			h[i][j]=yh[i][j];
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=re(),m=re(),t=re();
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			ys[i][j]=re();
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			yh[i][j]=re();
	date ls;
	while(t--){
		k=re();
		f1=-1,pda=1,head=0,tail=0;fz();ans=0;
		memset(d,0,sizeof(d));
		memset(l,0,sizeof(l));
		for(int i=1;i<=k;i++){
			int x1=re(),x2=re(),x3=re();
			if(f1==-1)f1=x3;
			else if(f1!=x3)pda=0;
			if(x2>2*m+n)x2-=2*m+n,h[n+1-x2][0]=x1,d[n+1-x2][0]=x3,ls.x=n+1-x1,ls.y=0;
			else if(x2>m+n)x2=x2-m-n,s[n][m+1-x2]=x1,d[n+1][m+1-x2]=x3,ls.x=n+1,ls.y=m+1-x2;
			else if(x2>m)x2-=m,h[x2][m]=x1,d[x2][m+1]=x3,ls.x=x2,ls.y=m+1;
			else s[0][x2]=x1,d[0][x2]=x3,ls.x=0,ls.y=x2;
			ls.v=21474836;
			if(x3)l[++tail]=ls,ans+=x1;
		}
		if(pda)printf("0\n");
		else {
			date ls1[5];
			while(head<tail){
				int nx=l[++head].x,ny=l[head].y,sum1=0;
				for(int i=1;i<=4;i++){
					int lx=nx+dx[i],ly=ny+dy[i];
					if(lx<0||lx>n+1||ly<0||ly>m+1||d[nx][ny]==d[lx][ly])continue;
					if(i==1)sum1+=s[lx][ly],ls1[i].v=s[lx][ly];
					else if(i==2)sum1+=s[nx][ny],ls1[i].v=s[nx][ny];
					else if(i==3)sum1+=h[lx][ly],ls1[i].v=h[lx][ly];
					else sum1+=h[nx][ny],ls1[i].v=h[nx][ny];
					ls1[i].x=lx,ls1[i].y=ly;
				}
				if(sum1<l[head].v){
					d[nx][ny]^=0;ans=ans-l[head].v-l[head].v+sum1;
					for(int i=1;i<=4;i++){
						if(ls1[i].v==l[head].v)continue;
						l[++tail]=ls1[i];
					}
				}
			}
			//for(int i=1;i<=tail;i++)dfs(l[])
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

