#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1e5+5;
const int inf=2147483647;
struct inside
{
	int a,b;
}in[N];
struct outside
{
	int a,b;
}out[N];
priority_queue<int,vector<int>,greater<int> >q;
int bein[N],beout[N],totin[N],totout[N];
bool cmp1(inside x,inside y)
{
	return x.a<y.a;
}
bool cmp2(outside x,outside y)
{
	return x.a<y.a;
}
int read()
{
	int res,f=1;
	char ch;
	while((ch=getchar())<'0'||ch>'9')
	if(ch=='-')
	f=-1;
	res=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
	res=(res<<1)+(res<<3)+(ch^48);
	return res*f;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,i,j,cnt,t,x,ans=0,tot;
	n=read();m1=read();m2=read();
	for(i=1;i<=m1;i++)
	{
		in[i].a=read();in[i].b=read();
	}
	for(i=1;i<=m2;i++)
	{
		out[i].a=read();out[i].b=read();
	}
	sort(in+1,in+1+m1,cmp1);
	sort(out+1,out+1+m2,cmp2);
	for(i=1;i<=n;i++)
	{
		cnt=tot=0;
		for(j=1;j<=m1;j++)
		{
			t=in[j].a;cnt++;
			while(q.size())
			{
				x=q.top();
				if(x<t)
				{
					cnt--;
					q.pop();
				}
				else
				break;
			}
			if(cnt<=i)
			{
				tot++;
				q.push(in[j].b);
			}
			else
			cnt--;
		}
		while(q.size())
		q.pop();cnt=0;
		for(j=1;j<=m2;j++)
		{
			t=out[j].a;cnt++;
			while(q.size())
			{
				x=q.top();
				if(x<t)
				{
					cnt--;
					q.pop();
				}
				else
				break;
			}
			if(cnt<=n-i)
			{
				tot++;
				q.push(out[j].b);
			}
			else
			cnt--;
		}
		ans=max(ans,tot);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
