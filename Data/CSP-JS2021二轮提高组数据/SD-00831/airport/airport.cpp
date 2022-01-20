#include<bits/stdc++.h>

#define lxl long long

using namespace std;

//114514 1919810

const int N = 1e5+10;

struct node{
	int x,y;
}A[N],B[N];

int n,n1,n2;
int s1[N],s2[N],top1=0,top2=0,u1[N],u2[N];
lxl sum1[N],sum2[N];

bool cmp(node a,node b)
{
	return a.x<b.x;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);

	int maxn=-0x3f3f3f3f;
	
	scanf("%lld%lld%lld",&n,&n1,&n2);
	
	for(lxl i=1;i<=n1;++i)
	{
		lxl x,y;
		scanf("%lld%lld",&x,&y);
		A[i].x=x,A[i].y=y;
		maxn=max(maxn,A[i].y);
	}
	
	for(lxl i=1;i<=n2;++i)
	{
		lxl x,y;
		scanf("%lld%lld",&x,&y);
		B[i].x=x,B[i].y=y;
		maxn=max(maxn,B[i].y);
	}
	
	sort(A+1,A+1+n1,cmp);
	sort(B+1,B+1+n2,cmp);
	
	for(lxl i=1;i<=n1;++i)
	{
		lxl x=A[i].x,y=A[i].y;
		if(i==1)
		{
			s1[++top1]=y;
			u1[top1]++;
			continue;
		}
		lxl f=1;
		for(lxl j=1;j<=top1;++j)
		{
			if(x>s1[j])
			{
				s1[j]=y;
				u1[j]++;f=0;
				break;
			}
		}
		if(f)
		{
			s1[++top1]=y;
			u1[top1]++;
		}
	}
	
	
	for(lxl i=1;i<=n2;++i)
	{
		lxl x=B[i].x,y=B[i].y;
		if(i==1)
		{
			s2[++top2]=y;
			u2[top2]++;
			continue;
		}
		lxl f=1;
		for(lxl j=1;j<=top2;++j)
		{
			if(x>s2[j])
			{
				s2[j]=y;
				u2[j]++;f=0;
				break;
			}
		}
		if(f)
		{
			s2[++top2]=y;
			u2[top2]++;
		}
	}
	
	for(lxl i=1;i<=top1;++i)
	{
//		cout<<u1[i]<<" ";
		sum1[i]=u1[i]+sum1[i-1];
	}
//	cout<<endl;
	for(lxl i=1;i<=top2;++i)
	{
//		cout<<u2[i]<<" ";
		sum2[i]=u2[i]+sum2[i-1];
	}
	long long ans=-0x3f3f3f3f;
	for(lxl i=0;i<=n;++i)
	{
		lxl j=n-i;
		ans=max(ans,sum1[i]+sum2[j]);
	}
	cout<<ans<<endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
