#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int read()//int!!
{
	int w=1,f=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		f=f*10+c-'0';
		c=getchar();
	}
	return w*f;
}
int n,m1,m2,result,ra[N],rb[N];
bool visa[N],visb[N];
int minn(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
int maxn(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
struct node
{
	int s,e;
}a[N],b[N];
struct node2
{
	int val,orderl;
}vala[N*2];
bool comp(const node &x,const node &y)
{
	if(x.s!=y.s)
		return x.s<y.s;
	return x.e<y.e;
}
int main()
{
	freopen("airport.in","r",stdin);//!!!!
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;i++)
	{
		a[i].s=read();
		a[i].e=read();
	}
	for(int i=1;i<=m2;i++)
	{
		b[i].s=read();
		b[i].e=read();
	}//bf
	sort(a+1,a+1+m1,comp);
	sort(b+1,b+1+m2,comp);

	int underl=1,ed=0,cnt=0,tot=0;//tot；第几组 
	while(cnt<m1)//处理m1 
	{
		++tot;underl=1;
		vala[tot].orderl=1;vala[tot].val=0;
		while(visa[underl])
			underl++;
		while(underl<=m1)
		{
			ed=a[underl].e;
			visa[underl]=true;
			vala[tot].val++;
			cnt++;underl++;
			while(underl<=m1&&(a[underl].s<=ed)||visa[underl]==true)
				underl++;
		}
	}
	underl=0,ed=0,cnt=0;
	while(cnt<m2)//处理m2 
	{
		++tot;underl=1;
		vala[tot].orderl=2;vala[tot].val=0;
		while(visb[underl])
			underl++;
		while(underl<=m2)
		{
			ed=b[underl].e;
			visb[underl]=true;
			vala[tot].val++;
			cnt++;underl++;
			while(underl<=m2&&(b[underl].s<=ed)||visb[underl]==true)
				underl++;
		}
	}
	underl=1;
	while(vala[underl].orderl==1)
	{
		ra[underl]=vala[underl].val;
		ra[underl]+=ra[underl-1];
		underl++;
	}
	int siza=underl-1,sizb,ct=underl-1;
	while(underl<=tot)
	{
		rb[underl-ct]=vala[underl].val;
		rb[underl-ct]+=rb[underl-ct-1];
		underl++;
	}
	sizb=underl-ct-1;
 	for(int i=minn(n,siza);i>=0&&n-i<=sizb;i--)
	 	result=maxn(result,ra[i]+rb[n-i]);
	printf("%d",result);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
