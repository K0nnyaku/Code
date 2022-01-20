#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<iomanip>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<cstring> 
#include<set>
using namespace std;
struct Node{
	int a,b;
};
struct S{
	int type,when,check;
};
Node node1[100005],node2[100005];
int n,m1,m2,now1,now2,ans1,ans2,Max,ans;
struct cmp{
	bool operator()(int c,int d)
	{
		return c>d;
	}
};
priority_queue<int,vector<int>,cmp> s1,s2;

bool cmp(Node c,Node d)
{
	return c.a<d.a;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	Max = -1;
	for(int i = 1,j = 1;i<=m1;i++,j++)
	{
		cin>>node1[i].a>>node1[i].b;
	}
	for(int i = 1,j = 1;i<=m2;i++,j++)
	{
		cin>>node2[i].a>>node2[i].b;
	}
	sort(node1+1,node1+1+m1,cmp); sort(node2+1,node2+1+m2,cmp);
	for(int i = 0;i<=n;i++)
	{
		for(int j = 1;j<=m1;j++)
		{
			if(s1.size())
			{
				while(node1[j].a>s1.top())
				{
					s1.pop();
					now1--;
					if(!s1.size())
					{
						break;
					}
				}
			}
			if(now1<i)
			{
				s1.push(node1[j].b);
				ans1++;
				now1++;
			}
		}
		for(int j = 1;j<=m2;j++)
		{
			if(s2.size())
			{
				while(node2[j].a>s2.top())
				{
					s2.pop();
					now2--;
					if(!s2.size())
					{
						break;
					}
				}
			}
			if(now2<n-i)
			{
				s2.push(node2[j].b);
				ans2++;
				now2++;
			}
		}
		if(ans1+ans2>Max)
		{
			Max = ans1+ans2;
		}
		now1 = 0;
		now2 = 0;
		ans1 = 0;
		ans2 = 0;
	}
	cout<<Max<<endl;
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
