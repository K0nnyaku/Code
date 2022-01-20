#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x*f;
}

const int N=1e6;
int n,m1,m2,ans=0;
int cur,ti;
bool at[2][N];

struct node
{
	int arr,lea;
}flt1[N],flt2[N];

bool check(int temp,int pos)
{
	bool flg=0;
	if(temp==1)
	{
		for(int i=1;i<=pos;i++)
		{
			if(at[0][i])
			{
				if(flt1[i].lea<=ti)
				{
					flg=true;
					at[0][i]=false;
					cur--;
				}
			}
		}
		if(flg) {return true;}
		else {return false;}
	}
	else
	{
		for(int i=1;i<=pos;i++)
		{
			if(at[1][i])
			{
				if(flt2[i].lea<=ti)
				{
					flg=true;
					at[1][i]=false;
					cur--;
				}
			}
		}
		if(flg) {return true;}
		else {return false;}
	}
}

void work(int h,int ab)
{
	memset(at,0,sizeof at);
	int temp=0;
	int ans1=0,ans2=0;
	if(h!=0)
	{
		cur=0,ti=0;
		for(int i=1;i<=m1;i++)
		{
			ti=flt1[i].arr;
			if(cur<h)
			{
				at[0][i]=1;
				cur++;
				ans1++;
				continue;
			}
			else
			{
				if(check(1,i)) ans1++;
			}
		}
	}
	if(ab!=0)
	{
		cur=0,ti=0;
		for(int i=1;i<=m2;i++)
		{
			ti=flt2[i].arr;
			if(cur<ab)
			{
				at[1][i]=1;
				cur++;
				ans2++;
				continue;
			}
			else
			{
				if(check(2,i)) ans2++;
			}
		}
	}
	ans=max(ans,ans1+ans2);
	if(ab) work(h+1,ab-1);
}

bool cmp(node a,node b)
{
	if(a.arr==b.arr) return a.lea<b.lea;
	else return a.arr<b.arr;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;i++) {flt1[i].arr=read();flt1[i].lea=read();}
	for(int i=1;i<=m2;i++) {flt2[i].arr=read();flt2[i].lea=read();}
	sort(flt1+1,flt1+1+m1,cmp);
	sort(flt2+1,flt2+1+m2,cmp);
	work(0,n);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
 3 5 4
  1 5 
  3 8 
  6 10 
  9 14
13 18 
2 11
 4 15
  7 17
   12 16
*/
