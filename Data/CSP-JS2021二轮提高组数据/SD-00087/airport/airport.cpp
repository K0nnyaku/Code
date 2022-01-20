#include<bits/stdc++.h>
#define MAXN 100005
#define re register
#define il inline
using namespace std;
template<typename tn> void read(tn &a)
{
	tn f=1,x=0;char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=f*x;
}
int n,m1,m2;
int f1[MAXN],f2[MAXN];
int ans1[MAXN],ans2[MAXN];
int ans;
struct plane
{
	int l,r;
}a1[MAXN],a2[MAXN];
int cmp(plane x,plane y)
{
	return x.l<y.l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	memset(f1,0,sizeof(0));
	memset(f2,0,sizeof(0));
	read(n);read(m1);read(m2);
	for(re int i=0;i<m1;i++)
		read(a1[i].l),read(a1[i].r);
	for(re int i=0;i<m2;i++)
		read(a2[i].l),read(a2[i].r);
	sort(a1,a1+m1,cmp);
	sort(a2,a2+m2,cmp);
	for(re int i=0;i<m1;i++)
	{
		if(f1[i]==0)
		{
			f1[i]=1;
			ans1[i]=1;
			int s=a1[i].r;
			for(re int j=i;j<m1;j++)
			{
				if((f1[j]==0)&&a1[j].l>=s)
				{
					f1[j]=1;
					s=a1[j].r;
					ans1[i]++;
				}
			}
		}
	}
	for(re int i=0;i<m2;i++)
	{
		if(f2[i]==0)
		{
			f2[i]=1;
			ans2[i]=1;
			int s=a2[i].r;
			for(re int j=i;j<m2;j++)
			{
				if((f2[j]==0)&&a2[j].l>=s)
				{
					f2[j]=1;
					ans2[i]++;
					s=a2[j].r;
				}
			}
		}
	}
	int i=0,j=0;
	while((i+j)<n)
	{
		if(ans1[i]>ans2[j])
		{
			ans+=ans1[i];
			i++;
		}
		else if(ans1[i]<ans2[j])
		{
			ans+=ans2[j];
			j++;
		}
		else
		{
			ans+=ans1[i];
			ans+=ans2[j];
			i++,j++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
