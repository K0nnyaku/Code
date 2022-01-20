#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define N 100010
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
//-------------------------------------
int n,nat,fo;//本地，外地
int ck1,ck2;//分配个数 
struct Flight{
	int a,b;
}nei[N];
Flight wai[N];
bool cmp1(Flight a,Flight b)
{
	return a.a<b.a;
} 
int maxn=-1000010;
void check(unsigned int fi,unsigned int se)
{
	priority_queue <int,vector<int>,greater<int> > q1;
	priority_queue <int,vector<int>,greater<int> > q2;
	int ans1=0,ans2=0;
	if(fi!=0) 
	for(int i=1;i<=nat;++i)
	{
		if(q1.size()<fi)
		{
			q1.push(nei[i].b),++ans1;
		}
		else{
			if(nei[i].a>q1.top())
			{
				q1.pop();
				q1.push(nei[i].b);
				++ans1;
			}
		}
	}
	if(se!=0)
	for(int i=1;i<=fo;++i)
	{
		if(q2.size()<se)
		{
			q2.push(wai[i].b),++ans2;
		}
		else{
			if(wai[i].a>q2.top())
			{
				q2.pop();
				q2.push(wai[i].b);
				++ans2;
			}
		}
	}
	if((ans1+ans2)>maxn) maxn=ans1+ans2;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),nat=read(),fo=read();
	for(int i=1;i<=nat;++i)
		nei[i].a=read(),nei[i].b=read();
	for(int i=1;i<=fo;++i)
		wai[i].a=read(),wai[i].b=read();
	sort(nei+1,nei+1+nat,cmp1);
	sort(wai+1,wai+fo+1,cmp1);
	for(int i=0;i<=n;++i)
	{
		ck1=i;
		ck2=(n-i);
		check(ck1,ck2);
	}	
	write(maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

