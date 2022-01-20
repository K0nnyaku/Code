#include <iostream>
#include <queue>
#include <stdio.h>
#include <algorithm>
using namespace std;

inline int read()
{
	int res = 0;
	char ch = '0';
	int opera = 1;
	while(ch = getchar(),ch < '0'||ch > '9')
	{
		if(ch == '-')
		{
			opera = -1; 
		}
	}
	res = ch - '0';
	while(ch = getchar(),ch >= '0'&&ch <= '9')
	{
		res = (res<<1)+(res<<3)+ch - '0';
	}
	return opera * res;
}

struct Bridge
{
	int end = 0,cnt =0,id = 0;
	bool operator < (const Bridge& pp)const
	{
		return pp.id < id;
	} 	
};

struct edge
{
	int start,end;
}guonei[100010],guowai[100010];

priority_queue <Bridge> q1;
priority_queue <Bridge> q2;
int n,m1,m2;
int cnt = 0;
int sum1[100010];
int sum2[100010];

int cmp(edge a,edge b)
{
	if(a.start == b.start)
	{
		return a.end < b.end;
	}
	return a.start <b.start;
}
queue <Bridge> tmp;
void add(int start,int end,int from)
{
	if(from == 1)				//来自国内 
	{
	/*????*///	tmp.clear();
		bool ok = false;
		while(!q1.empty())
		{
			Bridge tt = q1.top();
			q1.pop();
			if(tt.end <= start)
			{
				ok = true;
				tt.end = end;
				tt.cnt = tt.cnt+1;
				q1.push(tt);
				break;
			}
			else
			{
				tmp.push(tt);
			} 
		}
		while(!tmp.empty())
		{
			Bridge ws = tmp.front();
			tmp.pop();
			q1.push(ws);
		}
		if(!ok)
		{
			Bridge ws;
			ws.cnt = 1;
			ws.end = end;
			ws.id = cnt; 
			q1.push(ws);	
		}
	}
	else if(from == 2)
	{
	/*????*///	tmp.clear();
		bool ok = false;
		while(!q2.empty())
		{
			Bridge tt = q2.top();
			q2.pop();
			if(tt.end <= start)
			{
				ok = true;
				tt.end = end;
				tt.cnt = tt.cnt+1;
				q2.push(tt);
				break;
			}
			else
			{
				tmp.push(tt);
			} 
		}
		while(!tmp.empty())
		{
			Bridge ws = tmp.front();
			tmp.pop();
			q2.push(ws);
		}
		if(!ok)
		{
			Bridge ws;
			ws.cnt = 1;
			ws.end = end;
			ws.id = cnt;
			q2.push(ws);	
		}
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	/**
	思路：首先将输入的航班按照开始时间排序（相同时结束时间小的在前），添加到优先队列当中，当可以添加的时候，就插一个
	个数最多的。（如果一样，就插结束小的）。前缀和维护个数，比较。 
	*/
	n = read(),m1 = read(),m2 = read();
	
	for(int i = 1;i <= m1;i++)
	{
		guonei[i].start = read(),guonei[i].end = read();
	}
	for(int i = 1;i <= m2;i++)
	{
		guowai[i].start = read(),guowai[i].end = read();
	}
	
	sort(guonei+1,guonei+1+m1,cmp); 
	sort(guowai+1,guowai+1+m2,cmp);
	
//	for(int i = 1;i <= m1;i++)
//	{
//		cout << "i=" << i <<",start=" << guonei[i].start <<",end=" << guonei[i].end << endl;
//	}
//	for(int i = 1;i <= m2;i++)
//	{
//		cout << "i=" << i <<",start=" << guowai[i].start <<",end=" << guowai[i].end << endl;
//	}
	
	cnt = 0;
	for(int i = 1;i <= m1;i++)
	{
		cnt++;
		add(guonei[i].start,guonei[i].end,1);
	}
	cnt = 0;
	for(int i  =1;i <= m2;i++)
	{
		cnt++;
		add(guowai[i].start,guowai[i].end,2);
	}
	int size1 = q1.size(),size2 = q2.size();
	
	for(int i = 1;i <= size1;i++)
	{
		Bridge ttt = q1.top();
		q1.pop();
	//	cout << "i=" << i <<" ,cnt = " << ttt.cnt << "  end=" << ttt.end << endl;
		sum1[i] = sum1[i-1]+ttt.cnt;
	}
	for(int i = 1;i <= size2;i++)
	{
		Bridge ttt = q2.top();
		q2.pop();
	//	cout << "i=" << i <<" ,cnt = " << ttt.cnt << "  end=" << ttt.end << endl;
		sum2[i] = sum2[i-1]+ttt.cnt;
	}
	
	int ans  = -1;
	
	for(int i = 0;i <= n;i++)
	{
		ans = max(ans,sum1[i]+sum2[n-i]);
	}
	
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
