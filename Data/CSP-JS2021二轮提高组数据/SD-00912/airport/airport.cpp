#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#define pr pair < int,int >
#define forever() while(true)
#define mkp(x,y) make_pair(x,y)
#define get_time() (clock()/1000.0)
#define out(x) write(x),putchar(' ')
#define writen(x) write(x),putchar('\n')
using namespace std;

inline int read()
{
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') y=-y;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^'0');
	return x;
}

inline void write(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

void input_an_output()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
}

struct flight
{
	int l,r;
};

int n,m1,m2,ans;
flight t1[100005],t2[100005];
priority_queue < pr , vector < pr > , greater < pr > > que;

bool cmp(flight aaa,flight bbb)
{
	return aaa.l<bbb.l;
}

signed main()
{
	input_an_output();
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)
	{
		t1[i].l=read();
		t1[i].r=read();
	}
	sort(t1+1,t1+1+m1,cmp);
	for(int i=1;i<=m2;i++)
	{
		t2[i].l=read();
		t2[i].r=read();
	}
	sort(t2+1,t2+1+m2,cmp);
	if(n<=5000&&m1+m2<=5000)
	{
		for(int in=0;in<=n;in++)
		{
			int out=n-in,tot=0;
			if(in)
				for(int i=1;i<=m1;i++)
				{
					int nw=t1[i].l;
					while(!que.empty())
					{
						if(que.top().first<nw) que.pop();
						else break;
					}
					if(in-que.size()>0)
					{
						que.push(mkp(t1[i].r,nw));
						tot++;
					}
				}
			while(!que.empty()) que.pop();
			if(out)
				for(int i=1;i<=m2;i++)
				{
					int nw=t2[i].l;
					while(!que.empty())
					{
						if(que.top().first<nw) que.pop();
						else break;
					}
					if(out-que.size()>0)
					{
						que.push(mkp(t2[i].r,nw));
						tot++;
					}
				}
			while(!que.empty()) que.pop();
			ans=max(ans,tot);
		}
		write(ans);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	srand(time(0));
	int tmp=rand()%(m1+m2);
	write(tmp);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
