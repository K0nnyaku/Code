#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6;
int mx[N],tag[N];
void build(int rot,int lt,int rt)
{
	tag[rot]=0;mx[rot]=rt;
	if(lt==rt)return;
	int mid=(lt+rt)>>1;
	build(rot<<1,lt,mid),build(rot<<1|1,mid+1,rt);
}
void upd(int rot,int w){mx[rot]+=w,tag[rot]+=w;}
void pushdown(int rot)
{
	if(tag[rot])
	{
		int t=tag[rot];tag[rot]=0;
		upd(rot<<1,t),upd(rot<<1|1,t);
	}
}
void update(int rot,int lt,int rt,int lq,int rq,int w)
{
	if(lq>rq)return;
	if(lt>=lq&&rt<=rq){upd(rot,w);return;}
	int mid=(lt+rt)>>1;
	pushdown(rot);
	if(lq<=mid)update(rot<<1,lt,mid,lq,rq,w);
	if(rq>mid)update(rot<<1|1,mid+1,rt,lq,rq,w);
	mx[rot]=max(mx[rot<<1],mx[rot<<1|1]);
}
int query(int rot,int lt,int rt)
{
	if(lt==rt){if(mx[rot]!=0)return lt;return lt+1;}
	int mid=(lt+rt)>>1;pushdown(rot);
	if(mx[rot<<1])return query(rot<<1,lt,mid);
	return query(rot<<1|1,mid+1,rt);
}
struct TMP
{
	int x,d,id;
	TMP(const int &_x,const int &_d,const int &_id)
	{
		x=_x,d=_d,id=_id;
	}
	TMP(){}
}tmp[N];
int n,m1,m2,ans1[N],ans2[N],beg[N];
bool operator <(const TMP &a,const TMP &b){return a.x<b.x;}
void calc(int m,int ans[])
{
	int tn=0;
	for(int i=1,l,r;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		tmp[++tn]=TMP(l,1,i),tmp[++tn]=TMP(r,-1,i);
	}
	sort(tmp+1,tmp+tn+1);
	build(1,1,n);
	for(int i=1;i<=tn;i++)
	{
		if(tmp[i].d==1)
		{
			int t=query(1,1,n);
			beg[tmp[i].id]=t;
			update(1,1,n,t,n,-1);
			ans[t]++;
		}
		else
			update(1,1,n,beg[tmp[i].id],n,1);
	}
	for(int i=1;i<=n;i++)ans[i]+=ans[i-1];
}
int main()
{
//	freopen("airport3.in","r",stdin);
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);	
	calc(m1,ans1);
	calc(m2,ans2);
	int ans=0;
	for(int i=0;i<=n;i++)ans=max(ans,ans1[i]+ans2[n-i]);
	cout<<ans<<endl;	
}

