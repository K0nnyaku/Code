#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
typedef unsigned long long ULL;
typedef long long LL;
typedef double DB;
using namespace std;
inline int read()
{
	int s=0;bool w=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') w=1; ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+(ch^48); ch=getchar();}
	return w ? ~s+1 : s;
}
const int maxn=100005;
struct Tmp
{
	int st,en,nu;
}w1[maxn],w2[maxn];
int n,m1,m2,cnt1,cnt2;
struct Node{
	int l,r;
}a[maxn],b[maxn];
bool cmp(Node x,Node y){return x.l<y.l;}
bool cmpi(Tmp x,Tmp y){return x.st<y.st;}
int sum1[maxn],sum2[maxn];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;i++){a[i].l=read();a[i].r=read();}
	for(int i=1;i<=m2;i++){b[i].l=read();b[i].r=read();}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	cnt1++;
	w1[cnt1].st=a[1].l;
	w1[cnt1].en=a[1].r;
	w1[cnt1].nu=1;
	for(int i=2;i<=m1;i++)
	{
		bool f=true;
		for(int j=1;j<=cnt1;j++)
		{
			if(w1[j].en<=a[i].l)
			{
				f=false;
				w1[j].nu++;w1[j].en=a[i].r;
				break;
			}
		}
		if(f)
		{
			cnt1++;
			w1[cnt1].st=a[i].l;
			w1[cnt1].en=a[i].r;
			w1[cnt1].nu=1;
		}
	}
	cnt2++;
	w2[cnt2].st=b[1].l;
	w2[cnt2].en=b[1].r;
	w2[cnt2].nu=1;
	for(int i=2;i<=m2;i++)
	{
		bool f=true;
		for(int j=1;j<=cnt2;j++)
		{
			if(w2[j].en<=b[i].l)
			{
				f=false;
				w2[j].nu++;w2[j].en=b[i].r;
				break;
			}
		}
		if(f)
		{
			cnt2++;
			w2[cnt2].st=b[i].l;
			w2[cnt2].en=b[i].r;
			w2[cnt2].nu=1;
		}
	}
	sort(w1+1,w1+cnt1+1,cmpi);
	sort(w2+1,w2+cnt2+1,cmpi);
	for(int i=1;i<=cnt1;i++) sum1[i]=sum1[i-1]+w1[i].nu;
	for(int i=1;i<=cnt2;i++) sum2[i]=sum2[i-1]+w2[i].nu;
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,sum1[i]+sum2[n-i]);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
