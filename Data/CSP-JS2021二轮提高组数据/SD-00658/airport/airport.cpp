//枚举国内和国际分别几个，然后判断是否可行
//廊桥存储每个飞机的离开时间，若到达时间大于离开时间则可以进。
#include<bits/stdc++.h>
using namespace std;
int n,m,L,num1,num2,ans1,ans2,res;
priority_queue<int,vector<int>,greater<int> > q1,q2;//小根堆，存离开时间 
struct node{
	int l,r;
}a[100010],b[100010];
bool cmp(node a,node b)
{
	return a.l<b.l;//先到先得 
}
int main()
{
    freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m>>L;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	for(int i=1;i<=L;i++)
	{
		scanf("%d%d",&b[i].l,&b[i].r);
	}
	sort(a+1,a+1+m,cmp);
	sort(b+1,b+1+L,cmp);
	for(int i=0;i<=n;i++)//枚举国内区有几个廊桥 
	{
		ans1=0,ans2=0;
		while(!q1.empty())
		q1.pop();
		while(!q2.empty())
		q2.pop();
		num1=i,num2=n-i;
		for(int j=1;j<=m;j++)//国内
		{
			while(!q1.empty())//非空 
			{
				if(q1.top()<a[j].l)
				q1.pop();//先清除过期的 
				else break;
			}
			if(q1.size()<(unsigned)num1)
			{
				q1.push(a[j].r);
				ans1++;
			}
		}
		for(int j=1;j<=L;j++)//国际 
		{
			while(!q2.empty())//非空 
			{
				if(q2.top()<b[j].l)
				q2.pop();//先清除过期的
				else break; 
			}
			if(q2.size()<(unsigned)num2)
			{
				q2.push(b[j].r);
				ans2++;
			}
		}
		res=max(res,ans1+ans2);
	}
	cout<<res;
	return 0;
}
