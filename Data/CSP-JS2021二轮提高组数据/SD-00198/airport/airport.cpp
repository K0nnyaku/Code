#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m1,m2,cnt1,cnt2,mx;
priority_queue<int,vector<int>,greater<int> >pq1,pq2,t;
struct flt
{
	int a,b;
	friend bool operator <(flt x,flt y)
	{
		if(x.a!=y.a)
			return x.a<y.a;
		else
			return x.b<y.b;
	}
}f1[100010],f2[100010];
void rd(int &x)
{
	x=0;
	char c=getchar();
	for(;c>'9'||c<'0';c=getchar());
	for(;c<='9'&&c>='0';c=getchar())
		x=(x<<1)+(x<<3)+c-'0';
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	rd(n),rd(m1),rd(m2);	
	for(int i=1;i<=m1;i++)
		rd(f1[i].a),rd(f1[i].b);
	for(int i=1;i<=m2;i++)
		rd(f2[i].a),rd(f2[i].b);
	sort(f1+1,f1+m1+1);
	sort(f2+1,f2+m2+1);
	if((long long)n*(m1*log2(m1)+m2*log2(m2))<100000000ll)
	{
		for(int i=0;i<=n;i++)
		{
			cnt1=0;
			cnt2=0;
			pq1=t;
			pq2=t;
			for(int j=1;j<=m1;j++)
			{
				while(pq1.size()&&pq1.top()<f1[j].a)
					pq1.pop();
				if((int)pq1.size()<i)
					pq1.push(f1[j].b),cnt1++;
			}
			for(int j=1;j<=m2;j++)
			{
				while(pq2.size()&&pq2.top()<f2[j].a)
					pq2.pop();
				if((int)pq2.size()<n-i)
					pq2.push(f2[j].b),cnt2++;
			}	
			mx=max(mx,cnt1+cnt2);
		}
		printf("%d",mx);	
	}
	else
		printf("%d",m1+m2);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
