#include<cstdio>
#include<algorithm>

#define N 1000006

using namespace std;

int read()
{
	char a=getchar();
	int b=0,d=1;
	while(a<'0'||a>'9')
	{
		if(a=='-')
			d*=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9')
		b=(b<<3)+(b<<1)+a-'0',a=getchar();
	return b*d;
}

void check()
{
	freopen("a.in","r",stdin);
	freopen("T1.out","w",stdout);
}

int n,m1,m2,ans,tail,cnt;
int t[N];

struct QWQ
{
	int l,r;
}a[N],b[N];

bool cmp(QWQ c,QWQ d)
{
	return c.l<d.l;
}

void add(int x)
{
	t[++tail]=x;
	int now=tail;
	while(now>1&&(t[now]<t[now>>1]||t[now>>1]==0))
	{
		if(now==1)
			break;
		swap(t[now],t[now>>1]);
		now>>=1;
	}
	++cnt;
}

void dele()
{
	int now=1;
	t[1]=0;
	while(t[now<<1]!=0||t[now<<1|1]!=0)
	{
		if(t[now<<1|1]==0||(t[now<<1]&&t[now<<1]<t[now<<1|1]))
			swap(t[now],t[now<<1]),now<<=1;
		else
			swap(t[now],t[now<<1|1]),(now<<=1)|=1;
	}
	--cnt;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;++i)
		a[i].l=read(),a[i].r=read();
	for(int i=1;i<=m2;++i)
		b[i].l=read(),b[i].r=read();
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	int l=0,r=n;
	while(l+1<r)
	{
		
		int mid=(r+l)>>1,midq=mid+1,h1=0,h2=0,l1=0,l2=0,qqq=0,sss=0;
		while(t[1])
			dele();
		tail=cnt=0;
		for(int j=1;j<=m1;++j)
		{
			while(t[1]<a[j].l&&t[1]!=0)
				dele();
			if(cnt<mid)
				add(a[j].r);
		}
		qqq+=tail;
		while(t[1])
			dele();
		tail=cnt=0;
		for(int j=1;j<=m2;++j)
		{
			while(t[1]<b[j].l&&t[1]!=0)
				dele();
			if(cnt<(n-mid))
				add(b[j].r);
		}
		qqq+=tail;
		while(t[1])
			dele();
		tail=cnt=0;
		for(int j=1;j<=m1;++j)
		{
			while(t[1]<a[j].l&&t[1]!=0)
				dele();
			if(cnt<midq)
				add(a[j].r);
		}
		sss+=tail;
		while(t[1])
			dele();
		tail=cnt=0;
		for(int j=1;j<=m2;++j)
		{
			while(t[1]<b[j].l&&t[1]!=0)
				dele();
			if(cnt<(n-midq))
				add(b[j].r);
		}
		sss+=tail;
		if(qqq==sss)
		{
			ans=qqq;
			break;
		}
		if(qqq<sss)
		{
			ans=max(qqq,sss);
			l=mid;
		}
		else
		{
			ans=max(qqq,sss);
			r=mid;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0x0;
}
