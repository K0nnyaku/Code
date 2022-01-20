//什么时候我才能有杜爷一半强啊/kk
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int N=200086;
int n,m1,m2,tot,ans,tc[2][N];
bool vis[N];
struct asdf{
	int val,pos,flr;
	asdf(){}
	asdf(int vv,int pp,int ff){val=vv;pos=pp;flr=ff;}
	bool operator <(const asdf b)const{return val<b.val;}
}tmp[N<<1];
struct item{
	int a,b;
	item(){}
	item(int aa,int bb){a=aa;b=bb;}
	bool operator <(const item c)const{return a<c.a;}
	bool operator <(const int x)const{return a<x;}
}a[N];
set<item>s;
int Max(int a,int b){return a>b?a:b;}
int read(){
	char ch=getchar();int nn=0,ssss=1;
	while(ch<'0'||ch>'9'){if(ch=='-')ssss*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){nn=nn*10+(ch-'0');ch=getchar();}
	return nn*ssss;
}
bool operator <(const int x,const item b){return x<b.a;}
int solve(int m,int cnt[]){
	int ret=0;
	s.clear();
	for(int i=1;i<=m;i++)s.insert(a[i]);
	while(!s.empty()){
		set<item>::iterator it=s.begin();
		ret++;cnt[ret]=cnt[ret-1];
		while(it!=s.end()){
			cnt[ret]++;s.erase(it);
//			printf("%d:get to %d,%d.\n",ret,it->a,it->b);
			it=s.lower_bound(item(it->b,0));
		}
	}
	for(int i=ret+1;i<=n;i++)cnt[i]=cnt[i-1];
	return ret;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;i++){
		tmp[++tot]=asdf(read(),i,0);
		tmp[++tot]=asdf(read(),i,1);
	}
	int nval=0;
	sort(tmp+1,tmp+tot+1);
	for(int i=1;i<=tot;i++){
		nval+=(i==1||tmp[i].val!=tmp[i-1].val);
		if(tmp[i].flr&1)a[tmp[i].pos].b=nval;
		else a[tmp[i].pos].a=nval;
	}
	sort(a+1,a+m1+1);
	int ac=solve(m1,tc[0]);
	tot=0;
	for(int i=1;i<=m2;i++){
		tmp[++tot]=asdf(read(),i,0);
		tmp[++tot]=asdf(read(),i,1);
	}
	nval=0;
	sort(tmp+1,tmp+tot+1);
	for(int i=1;i<=tot;i++){
		nval+=(i==1||tmp[i].val!=tmp[i-1].val);
		if(tmp[i].flr&1)a[tmp[i].pos].b=nval;
		else a[tmp[i].pos].a=nval;
	}
	sort(a+1,a+m2+1);
	int bc=solve(m2,tc[1]);
	for(int i=0;i<=n;i++)ans=Max(ans,tc[0][i]+tc[1][n-i]);
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
