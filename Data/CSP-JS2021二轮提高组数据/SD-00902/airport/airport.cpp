#include<cstdio>
#include<cstring>
#include<algorithm>
#define il inline
#define F(I,A,N) for(I=A;I<=N;I++)
using namespace std;

const int maxn=1e5+1;
struct T1
{
	int a1,b1;
}t1[maxn];
struct T2
{
	int a2,b2;
}t2[maxn];
int TiMe[maxn];

il int read()
{
	int num=0; bool flag=1; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') flag=1; c=getchar();}
	while(c>='0'&&c<='9') num=(num<<1)+(num<<3)+(c^48), c=getchar();
	return flag?num:-num;
}

il bool cmp1(T1 a,T1 b)
{
	if(a.a1!=b.a1)
		return a.a1<b.a1;
	else 
		return a.b1<b.b1;
}

il bool cmp2(T2 a,T2 b)
{
	if(a.a2!=b.a2)
		return a.a2<b.a2;
	else
		return a.b2<b.b2;
}

il bool pd1(int pos,int cnt)
{
	int i;
	sort(TiMe+1,TiMe+1+cnt);
	F(i,1,cnt)
		if(TiMe[i]<t1[pos].a1)
		{
			TiMe[i]=t1[pos].b1;
			return 1;
		}
	return 0;
}

il bool pd2(int pos,int cnt)
{
	int i;
	sort(TiMe+1,TiMe+1+cnt);
	F(i,1,cnt)
		if(TiMe[i]<t2[pos].a2)
		{
			TiMe[i]=t2[pos].b2;
			return 1;
		}
	return 0;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	int n,m1,m2;
	int n1,n2,sum1,sum2,ans=-1;
	int i,cnt=0;
	
	n=read(); m1=read(); m2=read();
	F(i,1,m1)
		t1[i].a1=read(), t1[i].b1=read();
	F(i,1,m2)
		t2[i].a2=read(), t2[i].b2=read();
	
	sort(t1+1,t1+1+m1,cmp1);
	sort(t2+1,t2+1+m2,cmp2);
	
	n1=0; n2=n;
	while(n1<=n&&n2>=0)
	{
		sum1=0; sum2=0;
		
		cnt=0;
		memset(TiMe,0,sizeof(TiMe));
		F(i,1,m1)
		{
			if(pd1(i,cnt))
				sum1++;
			else if(sum1<n1)
				sum1++, TiMe[++cnt]=t1[i].b1;
		}
		cnt=0;
		memset(TiMe,0,sizeof(TiMe));
		F(i,1,m2)
		{
			if(pd2(i,cnt))
				sum2++;
			else if(sum2<n2)
				sum2++, TiMe[++cnt]=t2[i].b2;
		}
		
		if(ans<sum1+sum2)
			ans=sum1+sum2;
		
		n1++; n2--;
	}
	
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
