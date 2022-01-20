#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar(); 
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void print(int x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		print(x/10);
	putchar(x%10+'0');
}
int qmax(int x,int y)
{
	return x>y?x:y;
}
const int MAXN=100001;
int n,m1,m2,a1[MAXN],a2[MAXN],b1[MAXN],b2[MAXN],ans;
bool book[10000001];
struct node{
	int l,r;
}a[MAXN],b[MAXN];
bool cmp(node x,node y)
{
	return x.l<y.l;
}
void init(int L,int R)
{
	for(int i=L;i<=R;i++)
		book[i]=true; 
}
void solve(int x)
{
	int qwq=0;
	memset(book,false,sizeof(book));
	if(x>=n)
		return;
	int y=n-x;
	init(a[1].l,a[1].r);
	int cnt=1;
	for(int i=2;i<=m1;i++)
	{
		if(!book[a[i].l])
			qwq++,init(a[i].l,a[i].r);
		else if(book[a[i].l] && cnt!=x)
			cnt++,qwq++,init(a[i].l,a[i].r);
		else if(!book[a[i].l] && cnt==x)
			qwq++,init(a[i].l,a[i].r);
	}
	init(b[1].l,b[1].r);
	cnt=1;
	for(int i=2;i<=m2;i++)
	{
		if(!book[b[i].l])
			qwq++,init(b[i].l,b[i].r);
		else if(book[b[i].l] && cnt!=x)
			cnt++,qwq++,init(b[i].l,b[i].r);
		else if(!book[b[i].l] && cnt==x)
			qwq++,init(b[i].l,b[i].r);
	}
	ans=qmax(ans,qwq);
	solve(x+1);
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)
		a[i].l=read(),a[i].r=read();
	for(int i=1;i<=m2;i++)
		b[i].l=read(),b[i].r=read();
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	solve(0);
	print(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//I Love You,CCF. Please give me more points. Thank you !!!
