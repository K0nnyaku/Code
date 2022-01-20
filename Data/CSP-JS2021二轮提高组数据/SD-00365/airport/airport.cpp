#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include<cstdio>
using namespace std;
int n,m1,m2;
int tot=-0x3f;
int ans1,ans2;
int maxn=-0x3f;
int min1,min2=0x3f;
bool mark1[100010];
bool mark2[100010];
struct qaq{
	int ld;
	int le;
}T[100010];
qaq Y[100010];
//int min(int a,int b)
//{
//	if(a>b)
//		return b;
//	if(b>a)
//		return a;
//}
//int max(int a,int b)
//{
//	if(a>b)
//		return a;
//	if(b>a)
//		return b;
//}
bool cmp(qaq a,qaq b)
{
	return a.ld<b.ld;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>T[i].ld>>T[i].le;
		maxn=max(maxn,T[i].le);
	}
		
	for(int i=1;i<=m2;i++)
	{
		cin>>Y[i].ld>>Y[i].le;
		maxn=max(maxn,Y[i].le);
	}
	sort(T+1,T+n+1,cmp);
	sort(Y+1,Y+n+1,cmp);
	int a;
	for(int i=0;i<=n;i++)
	{
		int mk1=0;
		int mk2=0;
		ans1=0;
		ans2=0;
		int h1=i;
		int k=n-i;
		int h2=n-i;
		int t1d,t2d;//t1d:guonei land t2d:guowailand;
		int t1=1;
		int t2=1;
		int t1l[i+1],t2l[k+1];
		for(int z=0;z<=i+1;z++)
			t1l[z]=0x3f;
		for(int z=0;z<=k+1;z++)
			t2l[z]=0x3f;
		for(int j=1;j<=maxn;j++)
		{
			t1d=T[t1].ld;
			t2d=Y[t2].ld;
			if(j==t1d)
			{
				t1++;
				if(h1>0)
				{
					mk1++;//guonei lai le ji jia plane
					ans1++;
					h1--;
					t1l[i]=T[mk1].le;
					sort(t1l+1,t1l+i+1);
				}
			}
			if(j==t2d)
			{
				t2++;
				if(h2>0)
				{
					mk2++;
					ans2++;
					h2--;
					t2l[k]=Y[mk2].le;
					sort(t2l+1,t2l+k+1);
				}
			}
			if(j==t1l[1])
			{
				h1++;
				t1l[1]=0x3f;
				sort(t1l+1,t1l+1+i);
			}
			if(j==t2l[1])
			{
				h2++;
				t2l[1]=0x3f;
				sort(t2l+1,t2l+1+k);
			}
			tot=max(tot,ans1+ans2);
		}
	}
	cout<<tot; 
	return 0;
}

