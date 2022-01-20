#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int mod=1e9+7;
inline int Add(int x,int y,int M=mod){return (x+y)%M;}
inline int Mul(int x,int y,int M=mod){return 1ll*x*y%M;}
inline int Dec(int x,int y,int M=mod){return (x-y+M)%M;}
inline int Max(int x,int y){return x>y?x:y;}
inline int Min(int x,int y){return x<y?x:y;}
char buf[1<<21],*p1=buf,*p2=buf;
//char obuf[1<<21],*O=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10-'0'+ch;
		ch=getchar();
	}
	return s*w;
}
//inline void Write(int x){
//	if(x>9)Write(x/10);
//	*O++=(x%10+'0');
//}
inline int qpow(int x,int y,int M=mod){
	int res=1;
	while(y){
		if(y&1)res=Mul(res,x,M);
		x=Mul(x,x,M);
		y>>=1;
	}
	return res;
}
typedef pair<int,int> pr;
#define poly vector<int>
#define fi first
#define se second
#define mk make_pair
#define pb emplace_back
const int N=2e5+10;
inline void __FILE(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
}
int n,m[3],len;
struct P{
	int l,r,opt,id;
	P(int xx=0,int yy=0,int zz=0,int xxx=0){l=xx;r=yy;opt=zz;id=xxx;}
}ft[N],A[N],B[N];
inline bool cmp(P a,P b){return a.l<b.l;}
int vis[N][2];
int ans=0;
set<pr>ia,ib;
void check(int v){
	int num=0;
	int res=0;
	for(int i=1;i<=m[1];++i){
		pr t;
		while(!ia.empty()&&A[(t=(*ia.begin())).second].r<A[i].l){
			if(vis[t.second][0])num--;
			ia.erase(t);
		}
		if(num==v)continue;
		vis[i][0]=1;num++;
		++res;ia.insert(mk(A[i].r,i));
	}
	int R=0;
	num=0;
	for(int i=1;i<=m[2];++i){
		pr t;
		while(!ib.empty()&&B[(t=(*ib.begin())).second].r<B[i].l){
			if(vis[t.second][1])num--;
			ib.erase(t);
		}
		if(num==n-v)continue;
		vis[i][1]=1;++num;
		++R;ib.insert(mk(B[i].r,i));
	}
	ans=Max(ans,R+res);
	for(int i=1;i<=m[1];++i)vis[i][0]=0;
	for(int i=1;i<=m[2];++i)vis[i][1]=0;
	ia.clear();ib.clear();
}
int main(){
	__FILE();
	n=read();m[1]=read();m[2]=read();
	for(int i=1;i<=m[1];++i){
		int u=read(),v=read();
		ft[i]=P(u,v,0,i);
		A[i]=P(u,v,0,i);
	}
	for(int i=1;i<=m[2];++i){
		int u=read(),v=read();
		ft[i+m[1]]=P(u,v,1,i);
		B[i]=P(u,v,1,i); 
	}
	sort(A+1,A+m[1]+1,cmp);
	sort(B+1,B+m[2]+1,cmp);
//	for(int i=1;i<=m[1];++i)printf("(%d %d)\n",A[i].l,A[i].r);
	for(int i=0;i<=n;++i)check(i);
	printf("%d\n",ans);
	return 0;
}
