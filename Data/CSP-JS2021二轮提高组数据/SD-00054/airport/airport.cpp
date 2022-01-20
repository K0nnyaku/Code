#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int range=1e5+1;
inline int read()
{
	int x=0; int f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
struct CYprf
{
	int l,r;
}	ma[range],mb[range];
int n,m1,m2,f[range];
int cmp(CYprf a,CYprf b)
{ return a.l<b.l; }
int op1(int br)
{
	int ans,i,j,tl=0,tr=0,k=br;
	for(i=1;i<=m1;i++)
	{
		if(ma[i].l>tr) k=br;
		if(ma[i].l>tl)
		{
			ans++;
			tl=min(ma[i].r,tl);
			tr=max(tr,ma[i].r);
		}
		if(ma[i].l<tl)
		{
			if(!k&&ma[i].r<tr)
			{
				tl=min(ma[i].r,tl);
				tr=max(tr,ma[i].r);
			}
			if(k)
			{
				tl=min(ma[i].r,tl);
				tr=max(tr,ma[i].r);
				ans++; k--;
			}
		}
	}
	return ans;
}
int op2(int br)
{
	int ans,i,j,tl=0,tr=0,k=br;
	for(i=1;i<=m1;i++)
	{
		if(ma[i].l>tr) k=br;
		if(ma[i].l>tl)
		{
			ans++;
			tl=min(ma[i].r,tl);
			tr=max(tr,ma[i].r);
		}
		if(ma[i].l<tl)
		{
			if(!k&&ma[i].r<tr)
			{
				tl=min(ma[i].r,tl);
				tr=max(tr,ma[i].r);
			}
			if(k)
			{
				tl=min(ma[i].r,tl);
				tr=max(tr,ma[i].r);
				ans++; k--;
			}
		}
	}
	return ans;
}
int main()
{
	//freopen("airport.in","r",stdin);
	//freopen("airport.out","w",stdout);
	int i,j;
	n=read(); m1=read(); m2=read();
	for(i=1;i<=m1;i++) { 
	ma[i].l=read(); ma[i].r=read();}
	for(i=1;i<=m2;i++) { 
	mb[i].l=read(); mb[i].r=read();}
	memset(f,0,sizeof(f));
	sort(ma+1,ma+m1+1,cmp);
	sort(mb+1,mb+m2+1,cmp);
	f[0]=op1(0)+op2(n);
	for(i=1;i<=n;i++)
	f[i]=max(f[i-1],op1(i)+op2(n-i));
	printf("%d",f[n]);
	
	fclose(stdin); fclose(stdout);
	return 0;
}

