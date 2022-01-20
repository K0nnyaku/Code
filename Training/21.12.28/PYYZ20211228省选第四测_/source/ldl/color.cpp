#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
const int N=202021;
int n,Tcnt,tot;
int v[N],wt[N],id[N],top[N],son[N],siz[N],fa[N],col[N];
struct Tr{LL w; int cnt,c,f,tag;}tr[N<<2];
struct Edge{int to,next;}e[N<<1];
void add(int x,int y){
	e[++tot].to=y; e[tot].next=v[x]; v[x]=tot;
}
void dfs1(int x,int ff){
	siz[x]=1;
	for(int p=v[x];p;p=e[p].next){
		int kp=e[p].to;
		if(kp!=ff){
			fa[kp]=x; dfs1(kp,x);
			siz[x]+=siz[kp];
			if(siz[kp]>siz[son[x]])son[x]=kp;
		}
	}
}
void dfs2(int x,int topth){
	id[x]=++Tcnt; wt[Tcnt]=x;
	top[x]=topth;
	if(son[x])dfs2(son[x],topth);
	for(int p=v[x];p;p=e[p].next){
		int kp=e[p].to;
		if(kp!=fa[x] && kp!=son[x])
			dfs2(kp,kp);
	}
}
inline void updata(int k){
	tr[k].w=tr[k<<1].w+tr[k<<1|1].w;
	tr[k].cnt=tr[k<<1].cnt+tr[k<<1|1].cnt;
	tr[k].tag=tr[k<<1].tag|tr[k<<1|1].tag;
}
void build(int k,int l,int r){
	if(l==r){
		if(wt[l]!=1)tr[k].w=siz[wt[l]],tr[k].cnt=1,tr[k].c=col[wt[l]];
		return;
	} int mid=(l+r)>>1;
	build(k<<1,l,mid); build(k<<1|1,mid+1,r);
	updata(k);
}
void down(int k){
	if(tr[k].f){
		tr[k<<1].w=tr[k<<1|1].w=tr[k<<1].cnt=tr[k<<1|1].cnt=0;
		tr[k<<1].c=tr[k<<1|1].c=tr[k].c;
		tr[k<<1].f=tr[k<<1|1].f=1; tr[k].f=0;
	}
}
void changed(int k,int l,int r,int w){
	if(l==r){
		if(wt[l]!=1)tr[k].w=siz[wt[l]],tr[k].cnt=1;
		return;
	} down(k); int mid=(l+r)>>1;
	(w<=mid)?changed(k<<1,l,mid,w):changed(k<<1|1,mid+1,r,w);
	updata(k);
}
void change(int k,int l,int r,int ql,int qr,int w){
	if(ql<=l && qr>=r){
		tr[k].w=tr[k].cnt=0; tr[k].f=1; tr[k].c=w;
		return;
	} down(k); int mid=(l+r)>>1;
	if(ql<=mid)change(k<<1,l,mid,ql,qr,w);
	if(qr>mid)change(k<<1|1,mid+1,r,ql,qr,w);
	updata(k);
}
void Ptag(int k,int l,int r){
	if(!tr[k].tag)return;
	if(l==r)return changed(1,1,n,l);
	down(k); int mid=(l+r)>>1;
	Ptag(k<<1,l,mid); Ptag(k<<1|1,mid+1,r);
	updata(k);
}
void pushtag(int k,int l,int r,int ql,int qr){
	if(ql<=l && qr>=r)return Ptag(k,l,r);
	down(k); int mid=(l+r)>>1;
	if(ql<=mid)pushtag(k<<1,l,mid,ql,qr);
	if(qr>mid)pushtag(k<<1|1,mid+1,r,ql,qr);
	updata(k);
}
void changetag(int k,int l,int r,int x,int w){
	if(l==r)return tr[k].tag=w,void();
	down(k); int mid=(l+r)>>1;
	(x<=mid)?changetag(k<<1,l,mid,x,w):changetag(k<<1|1,mid+1,r,x,w);
	updata(k);
}
int queryc(int k,int l,int r,int w){
	if(l==r)return tr[k].c;
	down(k); int mid=(l+r)>>1;
	return (w<=mid)?queryc(k<<1,l,mid,w):queryc(k<<1|1,mid+1,r,w);
}
void Tchange(int x,int c){
/*	int tx=querytag(1,1,n,id[x]);
	if(tx){
		changed(1,1,n,id[tx],1);
		changetag(1,1,n,id[x],0);
	} else if(son[x]){
		if(queryc(1,1,n,x)==queryc(1,1,n,son[x]))
			changed(1,1,n,son[x],1);
	}*/
	if(queryc(1,1,n,id[son[x]])==queryc(1,1,n,id[x]))
		changed(1,1,n,id[son[x]]);
	int y=x;
	while(y){
		pushtag(1,1,n,id[top[y]],id[y]);
		y=fa[top[y]];
	} y=x;
	while(y){
		change(1,1,n,id[top[y]],id[y],c);
		changetag(1,1,n,id[fa[top[y]]],top[y]);
		y=fa[top[y]];
	}
}
LL query(int k,int l,int r,int ql,int qr){
	if(ql<=l && qr>=r)return tr[k].w;
	down(k); int mid=(l+r)>>1; LL res=0;
	if(ql<=mid)res+=query(k<<1,l,mid,ql,qr);
	if(qr>mid)res+=query(k<<1|1,mid+1,r,ql,qr);
	return res;
}
int querycnt(int k,int l,int r,int ql,int qr){
	if(ql<=l && qr>=r)return tr[k].cnt;
	down(k); int mid=(l+r)>>1,res=0;
	if(ql<=mid)res+=querycnt(k<<1,l,mid,ql,qr);
	if(qr>mid)res+=querycnt(k<<1|1,mid+1,r,ql,qr);
	return res;
}
LL Tquery(int x){
	int res=0;
	while(x){
		res+=querycnt(1,1,n,id[top[x]],id[x]);
		x=fa[top[x]];
	}
	return res;
}
int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
//		int w=top[y];
//		change(1,1,n,id[w],id[x]);
//		changetag(1,1,n,id[fa[w]],w);
//		tag[fa[w]]=w;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)col[i]=i;
	for(int x,y,i=1;i<n;i++)
		x=read()+1,y=read()+1,add(x,y),add(y,x);
	dfs1(1,0); dfs2(1,1); build(1,1,n);
	int aq=read(),cols=n; char ch;
	while(aq--){
		scanf(" %c",&ch); int x=read()+1;
		if(ch=='q'){
			LL ans=query(1,1,n,id[x],id[x]+siz[x]-1);
			ans+=1ll*Tquery(fa[x])*siz[x]; printf("%0.10lf\n",1.0*ans/siz[x]);
		} else Tchange(x,++cols);
	}
	return 0;
}
/*
13
0 1
0 2
1 11
1 10
1 9
9 12
2 5
5 8
2 4
2 3
4 6
4 7
7
q 0
O 4
q 6
q 2
O 9
q 9
q 2

*/
