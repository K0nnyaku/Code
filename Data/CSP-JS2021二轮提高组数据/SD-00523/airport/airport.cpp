#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,m1,m2,maxn=0;
priority_queue<int,vector<int>,greater<int> >q1;
priority_queue<int,vector<int>,greater<int> >q2;
struct node
{
	int s,e;
} a[1000005],b[1000005];

bool cmp(node x,node y)
{
	return x.s<y.s;
}
int read()
{
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
void write1(int x)
{
	if(x<0){putchar('-');x=-x;}
	while(x>9)
	{
		write1(x/10);
		x%=10;
	}
	putchar(x%10+'0');
	return;
}
int main()
{
    freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(register int i=1;i<=m1;i++) a[i].s=read(),a[i].e=read();
	for(register int i=1;i<=m2;i++) b[i].s=read(),b[i].e=read();
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	for(register int k=0;k<=n;k++)
	{
	    while(q1.size()) q1.pop();
	    while(q2.size()) q2.pop(); 
		int ans=0;
		int t1=k,t2=n-k;
		for(register int i=1;i<=m1;i++)
		{
			if(t1)
			{
				int ln=q1.size();
				if(ln==t1)
				{
					//cout<<a[i].s<<' '<<q1.top()<<' ';
					if(a[i].s>=q1.top())
					{
						ans++;
						q1.pop();
						q1.push(a[i].e);
					}
				}
					
				else 
				{
					q1.push(a[i].e);
					ans++;
				}
				
			}
		}
		//cout<<endl;
		for(register int i=1;i<=m2;i++)
		{
			if(t2)
			{
				int ln=q2.size();
				if(ln==t2)
				{
					//cout<<q2.top()<<' ';
					if(b[i].s>=q2.top())
					{
						ans++;
						q2.pop();
						q2.push(b[i].e);
					}
				}
					
				else 
				{
					q2.push(b[i].e);
					ans++;
				}
			}
		}
		//cout<<endl;
		maxn=max(maxn,ans);
	}
	write1(maxn);
	fclose(stdin);fclose(stdout);
	return 0;
}


