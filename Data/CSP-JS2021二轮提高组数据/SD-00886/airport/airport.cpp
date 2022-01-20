#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue> 
using namespace std;
int n,m1,m2;
struct node3
{
	int num,cnt;
	friend bool operator <(node3 x,node3 y)
	{
		return x.num>y.num;
	}
};
struct node2
{
	int num,t;
	friend bool operator <(node2 x,node2 y)
	{
		return x.t>y.t;
	}
};
struct node
{
	int a,b;
}plane1[100005],plane2[100005];
int len1,len2; 
bool cmp(node x,node y)
{
	return x.a<y.a;
}
bool cmp2(int x,int y)
{
	return x>y;
}
int sum1[100005],sum2[100005];
priority_queue<node3>fr1,fr2;
priority_queue<node2>use1,use2;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	node2 in;
	node3 in2;
	int i,j;
	scanf("%d %d %d",&n,&m1,&m2);
	for(i=1;i<=m1;i++)
		scanf("%d %d",&plane1[i].a,&plane1[i].b);
	for(i=1;i<=m2;i++)
		scanf("%d %d",&plane2[i].a,&plane2[i].b);
	sort(plane1+1,plane1+m1+1,cmp);
	sort(plane2+1,plane2+m2+1,cmp);
	/*for(i=1;i<=m1;i++)
	{
		printf("%d %d\n",plane1[i].a,plane1[i].b);
	}*/
	//---------------------------------------
	for(i=1;i<=m1;i++)
	{
		while(!use1.empty())
		{
			in=use1.top();
			if(in.t<plane1[i].a)
			{
				use1.pop();
				in2.num=in.num;
				in2.cnt=sum1[in2.num]; 
				fr1.push(in2);
			}
			else
				break;
		}
		if(fr1.empty())
		{
			len1++;
			in2.num=len1;in2.cnt=sum1[in2.num];
			fr1.push(in2);
		}
		in2=fr1.top();
		in.num=in2.num;in.t=plane1[i].b;
		use1.push(in);
		sum1[in.num]++;
		fr1.pop();
	}
	//----------------------------------
	for(i=1;i<=m2;i++)
	{
		while(!use2.empty())
		{
			in=use2.top();
			if(in.t<plane2[i].a)
			{
				use2.pop();
				in2.num=in.num;
				in2.cnt=sum2[in2.num]; 
				fr2.push(in2);
			}
			else
				break;
		}
		if(fr2.empty())
		{
			len2++;
			in2.num=len2;in2.cnt=sum2[in2.num];
			fr2.push(in2);
		}
		in2=fr2.top();
		in.num=in2.num;in.t=plane2[i].b;
		use2.push(in);
		sum2[in.num]++;
		fr2.pop();
	}
	//cout<<len1<<" "<<len2<<endl;
	//--------------------------------
	if(len1+len2<=n)
	{
		printf("%d",m1+m2);
		return 0;
	}
	int ans=0; 
	for(i=1;i<=len1;i++)
	{
		//printf("%d ",sum1[i]);
		sum1[i]+=sum1[i-1];
	}
	for(i=1;i<=len2;i++)
	{
		//printf("%d ",sum2[i]);
		sum2[i]+=sum2[i-1];
	}
	for(i=n;i>=0;i--)
	{
		ans=max(ans,sum1[i]+sum2[n-i]); 
	}
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
