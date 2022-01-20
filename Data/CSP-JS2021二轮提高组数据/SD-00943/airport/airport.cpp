#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
#define re register int
#define ll long long
const int N=1e5+10;
int read(){
	int x=0,mark=1;char c=getchar();
	while(c<'0'||c>'9'){if (c=='-')mark=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*mark;
}
struct seg{
	int l,r,op;
	bool operator < (const seg &A)const {
		return l<A.l;
	} 
}a[N],b[N];
int f[N],g[N];
int lsh[N*4];
struct {
	int l,r;
	int minn;
}tr[16*N];//4n*4
const int inf=1e9;
int ins[2*N];//最小编号->数值
void pushup(int x){
	tr[x].minn=min(tr[x<<1].minn,tr[x<<1|1].minn);
} 
void build(int x,int l,int r){
	tr[x]={l,r,inf};
	if (l==r) return;
	int mid=(l+r)>>1;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	pushup(x);
}
void change(int x,int pos,int val){//更新最小编号
	if (tr[x].l==tr[x].r){
		tr[x].minn=val;
		return;
	} 
	int mid=(tr[x].l+tr[x].r)>>1;
	if (pos<=mid) change(x<<1,pos,val);
	else change(x<<1|1,pos,val);
	pushup(x);
} 
int ask(int x,int l,int r){
	if (l<=tr[x].l&&tr[x].r<=r){
		return tr[x].minn;//返回最小编号 
	}
	int mid=(tr[x].l+tr[x].r)>>1,res=inf;
	if (l<=mid) res=min(res,ask(x<<1,l,r));
	if (r>mid) res=min(res,ask(x<<1|1,l,r));
	return res; 
}
int n,m1,m2,top;
void work1(){
	for (re i=1;i<=m1;i++){
		a[i].l=lower_bound(lsh+1,lsh+1+top,a[i].l)-lsh;
		a[i].r=lower_bound(lsh+1,lsh+1+top,a[i].r)-lsh;
	}
	build(1,1,top);
	int cnt=0,maxn=0;
	for (re i=1;i<=m1;i++){
		if (cnt==0){
			f[++cnt]=1;change(1,a[i].r,cnt);//新开一个 
			ins[cnt]=a[i].r;
		}
		else {
			int x=ask(1,1,a[i].l-1);//小于的最小编号
			if (x==inf){//新开一个 
				f[++cnt]=1;change(1,a[i].r,cnt);ins[cnt]=a[i].r;
			}
			else {//找到了 
				f[x]++;change(1,ins[x],inf);//删去原来的
				ins[x]=a[i].r;
				change(1,a[i].r,x);
			}
		}
	}
	for (re i=1;i<=m1;i++) f[i]+=f[i-1];
}
void work2(){
	for (re i=1;i<=m2;i++){
		b[i].l=lower_bound(lsh+1,lsh+1+top,b[i].l)-lsh;
		b[i].r=lower_bound(lsh+1,lsh+1+top,b[i].r)-lsh;
	}
	build(1,1,top);
	int cnt=0,maxn=0;
	memset(ins,0,sizeof ins);
	for (re i=1;i<=m2;i++){
		if (cnt==0){
			g[++cnt]=1;change(1,b[i].r,cnt);//新开一个 
			ins[cnt]=b[i].r;
		}
		else {
			int x=ask(1,1,b[i].l-1);//小于的最小编号
			if (x==inf){//新开一个 
				g[++cnt]=1;change(1,b[i].r,cnt);ins[cnt]=b[i].r;
			}
			else {//找到了 
				g[x]++;change(1,ins[x],inf);//删去原来的
				ins[x]=b[i].r;
				change(1,b[i].r,x);
			}
		}
	}
	for (re i=1;i<=m2;i++) g[i]+=g[i-1];
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	int x,y;
	top=0;
	for (re i=1;i<=m1;i++){
		x=read(),y=read();
		a[i].l=x,a[i].r=y;
		lsh[++top]=x,lsh[++top]=y;
	}
	sort(a+1,a+1+m1);
	for (re i=1;i<=m2;i++){
		x=read(),y=read();
		b[i].l=x,b[i].r=y;
		lsh[++top]=x,lsh[++top]=y;
	}
	sort(b+1,b+1+m2);
	sort(lsh+1,lsh+1+top);
	top=unique(lsh+1,lsh+1+top)-lsh-1;
	work1();work2();
	int ans=0;
	for (re i=0;i<=min(n,m1);i++){
		ans=max(ans,f[i]+g[n-i]);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
return 0;}


