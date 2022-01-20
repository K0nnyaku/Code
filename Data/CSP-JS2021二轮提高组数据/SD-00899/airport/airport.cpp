#include <bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;i++)
#define UF(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pii pair<int,int>
#define lc pos<<1
#define rc pos<<1|1 
#define foredge(i) int i=head[u],v=edges[i].to;i;i=edges[i].nxt,v=edges[i].to

using namespace std;
const ll N=100005,M=400005;
int read(){
	int x=0,i=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')i=0;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return i!=0?x:-x;
}

void write(ll x){
	if(x<0){
		putchar('-');
		write(-x);
		return;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

void write(ll x,char c){
	if(x<0)putchar('-'),write(-x);
	else write(x);
	putchar(c);
}

int ltag[N<<3],mx[N<<3],id[N<<3];
struct Flight{
	int a,b;
}x[N],y[N];
bool cmp(Flight a,Flight b){
	return a.a<b.a;
}
int lsh[N<<2],dic[N<<2];
int n,ma,mb,lpos;
int ansa[N],ansb[N];

void down(int pos){
	ltag[lc]+=ltag[pos],ltag[rc]+=ltag[pos];
	mx[lc]+=ltag[pos],mx[rc]+=ltag[pos];
	ltag[pos]=0;
}

void up(int pos){
	mx[pos]=max(mx[lc],mx[rc]);
	if(mx[lc]>=mx[rc]) id[pos]=id[lc];
	else id[pos]=id[rc];
	return;
}

void build(int pos,int l,int r){
	if(l==r){
		id[pos]=l;
		return;
	}
	int mid=l+r>>1;
	build(lc,l,mid),build(rc,mid+1,r);
	up(pos);
//	cerr<<pos<<' '<<l<<' '<<r<<endl;
//	cerr<<ltag[pos]<<'&'<<mx[pos]<<'&'<<mx[pos]<<'&'<<id[pos]<<endl;
	return;
}

void modify(int pos,int l,int r,int tl,int tr,int k)
{
	if(l>=tl&&r<=tr){
		ltag[pos]+=k;
		mx[pos]+=k;
		return;
	}
	down(pos);
	int mid=l+r>>1;
	if(tl<=mid) modify(lc,l,mid,tl,tr,k);
	if(tr>mid) modify(rc,mid+1,r,tl,tr,k);
	up(pos);
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),ma=read(),mb=read();
	F(i,1,ma){
		lsh[++lpos]=x[i].a=read(),lsh[++lpos]=x[i].b=read();
	}
	F(i,1,mb){
		lsh[++lpos]=y[i].a=read(),lsh[++lpos]=y[i].b=read();
	}
	sort(lsh+1,lsh+1+lpos);
	F(i,1,ma){
		x[i].a=lower_bound(lsh+1,lsh+1+lpos,x[i].a)-lsh;
		x[i].b=lower_bound(lsh+1,lsh+1+lpos,x[i].b)-lsh;
	}
	F(i,1,mb){
		y[i].a=lower_bound(lsh+1,lsh+1+lpos,y[i].a)-lsh;
		y[i].b=lower_bound(lsh+1,lsh+1+lpos,y[i].b)-lsh;
	}
	sort(x+1,x+1+ma,cmp);
	sort(y+1,y+1+mb,cmp);
	F(i,1,ma) dic[x[i].a]=i,dic[x[i].b]=i;
	F(i,1,mb) dic[y[i].a]=i,dic[y[i].b]=i;
	build(1,1,lpos);
	F(i,1,ma){
		modify(1,1,lpos,x[i].a,x[i].b,1);
	}
	while(mx[1]){
		ansa[mx[1]]=ma;
		int to=mx[1]-1;
		while(mx[1]!=to){
			//cout<<mx[1]<<endl;
			modify(1,1,lpos,x[dic[id[1]]].a,x[dic[id[1]]].b,-1);
			ma--;
		}
	}
	memset(mx,0,sizeof(mx));
	memset(id,0,sizeof(id));
	memset(ltag,0,sizeof(ltag));
	build(1,1,lpos);
	F(i,1,mb){
		modify(1,1,lpos,y[i].a,y[i].b,1);
	}
	while(mx[1]){
		ansb[mx[1]]=mb;
		int to=mx[1]-1;
		while(mx[1]!=to){
			//cout<<mx[1]<<endl;
			modify(1,1,lpos,y[dic[id[1]]].a,y[dic[id[1]]].b,-1);
			mb--;
		}
	}
	int ans=0;
	F(i,0,n){
		ans=max(ans,ansa[i]+ansb[n-i]);
	}
	write(ans,'\n');
	return 0;
}
