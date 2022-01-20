#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <set>
using namespace std;
inline int read()
{
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
int n,domenum,internum,ans,lea[100010];
int domecnt,domedel[100010];
int intercnt,interdel[100010];
set<int> st;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();domenum=read();internum=read();
	for(int i=1;i<=domenum;i++)
	{
		int arr=read();
		lea[arr]=read();
		st.insert(arr);
	}
	while(!st.empty())
	{
		set<int>::iterator it=st.begin();
		domecnt++;
		while(it!=st.end())
		{
			int now=(*it);
			it=st.upper_bound(lea[now]);
			st.erase(now);
			domedel[domecnt]++;
		}
	}
	for(int i=1;i<=internum;i++)
	{
		int arr=read();
		lea[arr]=read();
		st.insert(arr);
	}
	while(!st.empty())
	{
		set<int>::iterator it=st.begin();
		intercnt++;
		while(it!=st.end())
		{
			int now=(*it);
			it=st.upper_bound(lea[now]);
			st.erase(now);
			interdel[intercnt]++;
		}
	}
	for(int i=1;i<=domecnt;i++)domedel[i]+=domedel[i-1];
	for(int i=1;i<=intercnt;i++)interdel[i]+=interdel[i-1];
	for(int i=0;i<=n;i++)ans=max(ans,domedel[i]+interdel[n-i]);
	printf("%d\n",ans); 
	return 0;
}
