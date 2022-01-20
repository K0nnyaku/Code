#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int n=1,k=0;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') n=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	return n*k;
}
const int MAXN=1e5+50;
struct plane{
	int l,r;
	friend bool operator < (plane a,plane b)
	{
		return a.l<b.l;
	}
}neib[MAXN],waib[MAXN];
int n,mm1,mm2,maxn;
int now;
priority_queue <int> q;
inline int check(int nei,int wai)
{
	int ans=0;
	now=0;
	while(!q.empty()) q.pop();
	for(int i=1;i<=mm1;i++)
	{
		while(!q.empty()&&q.top()>-neib[i].l)
		{
			q.pop();
			now--;
		}
		if(now<nei) 
		{
			q.push(-neib[i].r);
			now++;
			ans++;
		}
	}
	now=0;
	while(!q.empty()) q.pop();
	for(int i=1;i<=mm2;i++)
	{
		while(!q.empty()&&q.top()>-waib[i].l)
		{
			q.pop();
			now--;
		}
		if(now<wai) 
		{
			q.push(-waib[i].r);
			now++;
			ans++;
		}
	}
	return ans;
}
int main()
{
    freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();mm1=read();mm2=read();
	for(int i=1;i<=mm1;i++)
	{
		neib[i].l=read();
		neib[i].r=read();
	}
	for(int i=1;i<=mm2;i++)
	{
		waib[i].l=read();
		waib[i].r=read();
	}
	if(mm1+mm2<=n)
	{
		printf("%d",mm1+mm2);
		return 0;
	}
	sort(neib+1,neib+1+mm1);
	sort(waib+1,waib+1+mm2);
	
	for(int i=0;i<=n;i++)
	{
		int s=check(i,n-i);
		if(s>maxn) maxn=s;
	}
	printf("%d",maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}



