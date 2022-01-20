#include<iostream>
#include<iomanip>
#include<cstdio>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<ctime>
#include<bitset>
#include<complex>
#define F(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
namespace fastIO{
	inline int read(){
		int x=0;
		bool fu=false;
		char ch=0;
		while((ch=getchar())>'9'||ch<'0'){
			if(ch=='-')fu=true;
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+ch-'0';
			ch=getchar();
		}
		return fu?-x:x;
	}
	template<class T>
	inline void read(T &x){
		x=0;
		bool fu=false;
		char ch=0;
		while((ch=getchar())>'9'||ch<'0'){
			if(ch=='-')fu=true;
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+ch-'0';
			ch=getchar();
		}
		if(fu)x=-x;
	}
	char num_[50];
	int cnt_;
	template<class T>
	inline void write(T x){
		if(x==0){
			putchar('0');
			return;
		}
		if(x<0)putchar('-'),x=-x;
		while(x){
			num_[++cnt_]=x%10+'0';
			x/=10;
		}
		while(cnt_)putchar(num_[cnt_--]);
	}
	template<class T>
	inline void write(T x,char c){
		write(x);
		putchar(c);
	}
}
using namespace fastIO;
#define cnt_ qwqwqwqwqwqwqwq
const int MAXN=260002,MAXM=1100002;
int tot,to[MAXM],v[MAXM],nxt[MAXM],head[MAXN],now[MAXN],cnt=1,to_[MAXM],v_[MAXM],nxt_[MAXM],head_[MAXM],cnt_,d[MAXN],q[MAXN],ql,qr;
const int S=260000,T=260001;
int n,m,TT;
inline void sv(){
	memcpy(to_,to,sizeof(to));
	memcpy(v_,v,sizeof(v));
	memcpy(nxt_,nxt,sizeof(nxt));
	memcpy(head_,head,sizeof(head));
	cnt_=cnt;
}
inline void cp(){
	tot=n*m;
	memcpy(to,to_,sizeof(to));
	memcpy(v,v_,sizeof(v));
	memcpy(nxt,nxt_,sizeof(nxt));
	memcpy(head,head_,sizeof(head));
	cnt=cnt_;
}
inline void add(int x,int y,int z){
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
	v[cnt]=z;
}
inline void ed(int x,int y,int z){
	add(x,y,z);
	add(y,x,z);
}
inline bool bfs(){
	memset(d,0x3f,sizeof(d));
	d[S]=0;
	ql=qr=1;
	q[1]=S;
	while(ql<=qr){
		int pos=q[ql++];
		for(int i=head[pos];i;i=nxt[i]){
			if(v[i]>0&&d[to[i]]>d[pos]+1){
				d[to[i]]=d[pos]+1;
				q[++qr]=to[i];
			}
		}
	}
	return d[T]<100000000;
}
inline int dfs(int pos,int mmax){
//	if(!mmax)return 0;
	if(pos==T)return mmax;
	int rt=0;
	for(int i=now[pos];i&&mmax;i=nxt[i]){now[pos]=i;
	if(d[to[i]]==d[pos]+1&&v[i]>0){
		
		int temp=dfs(to[i],min(mmax,v[i]));//cerr<<pos<<" "<<mmax<<" "<<temp<<endl;
		if(temp){
			rt+=temp;
			v[i]-=temp;
			v[i^1]+=temp;
			mmax-=temp;
		}else d[to[i]]=INT_MAX-2;
	}	
	}	
	return rt;
}
inline int Dinic(){
	int rt=0;
	while(bfs()){
		F(i,1,tot)now[i]=head[i];
		now[S]=head[S];
		now[T]=head[T];
		rt+=dfs(S,INT_MAX);
	}
	return rt;
}
inline int getid(int x,int y){
	return (x-1)*m+y;
}
inline int asdf(int x){
	if(x<=m)return getid(1,x);
	if(x<=n+m)return getid(x-m,m);
	if(x<=n+m+m)return getid(n,m-(x-n-m)+1);
	return getid(n-(x-n-m-m)+1,1);
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>TT;
	F(i,1,n-1){
		F(j,1,m)ed(getid(i,j),getid(i+1,j),read());
	}
	F(i,1,n){
		F(j,1,m-1)ed(getid(i,j),getid(i,j+1),read());
	}
	sv();
	F(iakcsp,1,TT){
		int k=read();
		cp();
		F(i,1,k){
			++tot;
			int v=read();
			ed(tot,asdf(read()),v);
			if(read()==0)ed(S,tot,1e9);
			else ed(T,tot,1e9);
		}
		write(Dinic(),'\n');
	}
	fflush(stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//orzhqwqwqwqwqwqwqwq
