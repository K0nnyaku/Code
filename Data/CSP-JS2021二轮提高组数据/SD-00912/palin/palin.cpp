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
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
}

int n,mem[1000005],top,lmy[1000005];
char opt[1000005];
bool flg;
deque < int > que;

bool check()
{
	for(int i=1;i<=n;i++)
		if(mem[i]!=mem[2*n+1-i])
			return 0;
	return 1;
}

void dfs()
{
	if(top==2*n)
	{
		if(check())
		{
			flg=1;
			for(int i=1;i<=top;i++)
				putchar(opt[i]);
			putchar('\n');
		}
		return ;
	}
	int fr=que.front(),bk=que.back();
	top++;
	mem[top]=bk;
	opt[top]='L';
	que.pop_back();
	dfs();
	que.push_back(bk);
	if(flg) return ;
	mem[top]=fr;
	opt[top]='R';
	que.pop_front();
	dfs();
	que.push_front(fr);
	if(flg) return ;
	opt[top]=0;
	mem[top]=0;
	top--;
}

signed main()
{
	input_an_output();
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n*2;i++)
		{
			lmy[i]=read();
			que.push_front(lmy[i]);
		}
		bool ch=0;
		for(int i=1;i<=n;i++)
			if(lmy[i]!=lmy[2*n+1-i])
			{
				ch=1;
				break;
			}
		if(!ch)
		{
			for(int i=1;i<=2*n;i++)
				putchar('L');
			putchar('\n');
			continue;
		}
		dfs();
		if(!flg) writen(-1);
		memset(mem,0,sizeof(mem));
		memset(opt,0,sizeof(opt));
		que.clear();
		top=flg=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
