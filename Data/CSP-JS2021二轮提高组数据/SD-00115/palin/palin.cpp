#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[2100],b[2100],v[1100],s[2100],flag;
void asd(int step,int h,int d)
{
	if(flag) return;
	if(step>n)
	{
		int cnt=n,hh=h,dd=d;
		for(int i=n;i>=1;--i)
		{
			if(a[hh]==b[i])
			{
				s[++cnt]=1;
				b[cnt]=a[hh];
				++hh;
				continue;
			}
			else if(a[dd]==b[i])
			{
				
				s[++cnt]=2;
				b[cnt]=a[dd];
				--dd;
				continue;
			}
			return;
		}
		flag=1;
		for(int i=1;i<=2*n;++i)
		{
			if(s[i]==1) printf("L");
			if(s[i]==2) printf("R");
		}
		printf("\n");
	//	for(int i=1;i<=2*n;++i)
	//	cout<<b[i]<<" ";
	//	cout<<endl;
		return;
	}
	if(!v[a[h]])
	{
		s[step]=1;
		b[step]=a[h];
		v[a[h]]=1;
		asd(step+1,h+1,d);
		v[a[h]]=0;
	}
	if(!v[a[d]])
	{
		s[step]=2;
		b[step]=a[d];
		v[a[d]]=1;
		asd(step+1,h,d-1);
		v[a[d]]=0;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int o=1;o<=t;++o)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(v,0,sizeof(v));
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i)
		scanf("%d",&a[i]);
		flag=0;
		asd(1,1,2*n);
		if(!flag) printf("-1\n");
	}
	return 0;
}
