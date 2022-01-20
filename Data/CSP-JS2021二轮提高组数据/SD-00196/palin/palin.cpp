#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <bitset>
#include <set>
#include <vector>
#include <deque>
#include <string>

#define I inline
#define LL long long
#define CI const int
#define Heriko return
#define Deltana 0
#define Romanno 1
#define mst(a,b) memset(a,b,sizeof(a))

using namespace std;

template<typename J>
I void fr(J &x)
{
	x=0;short f=1;char c(getchar());
	
	while(c<'0' or c>'9')
	{
		if(c=='-') f=-1;
		
		c=getchar();
	}
	
	while(c>='0' and c<='9')
	{
		x=(x<<1)+(x<<3)+(c^=48);
		c=getchar();
	}
	
	x*=f;
}

CI MXX(5e5+5),NXX(1e6+5);

deque<int> q;

char s[NXX],ts[NXX];

int T,n,a[NXX],b[NXX],len,co[NXX];

void DFS(int step,int opt)
{	
	if(len==(n*2))
	{	
		for(int i(1);i<=len;++i)
			if(b[i]!=b[len+1-i])
					Heriko;
		bool flg(0);
		
		if(strcmp(s+1,ts+1)>0) flg=1;
			
		if(flg)
			for(int i(1);i<=len;++i)
				s[i]=ts[i];
		
		Heriko;
	}
	
	int tmp;
	
	if(opt==0)
	{
		b[++len]=q.front();
		tmp=q.front();q.pop_front();
		ts[len]='L';
	}
	else
	{
		b[++len]=q.back();
		tmp=q.back();q.pop_back();
		ts[len]='R';
	}
	
	DFS(step+1,0);DFS(step+1,1);
	
	if(opt==0)
	{
		--len;q.push_front(tmp);
	}
	else
	{
		--len;q.push_back(tmp);
	}
}

signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	fr(T);
	
	while(T--)
	{
		fr(n);int m(n*2);len=0;q.clear();
		
		for(int i(1);i<=m;++i) fr(a[i]),q.push_back(a[i]),s[i]='R';
		
		DFS(1,0);len=0;DFS(1,1);
		
		int flg(0);
		
		for(int i(1);i<=m;++i)
			if(s[i]!='R')
			{
				flg=1;
				break;
			}
				
		if(!flg) puts("-1");
		else printf("%s\n",s+1);
	}
	
	Heriko Deltana;
}
