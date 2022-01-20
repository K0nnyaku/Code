
#include<bits/stdc++.h>
#define maxn 100010 
using namespace std;
priority_queue<int,vector<int>,greater<int> >qn;
priority_queue<int,vector<int>,greater<int> >qw;
int n,mn,mw,ans,num;
struct node1
{
	int to,go;
}nei[maxn];
struct node2
{
	int to,go;
}wai[maxn];
bool cmp1(node1 a,node1 b)
{
	return a.to<b.to;
}
bool cmp2(node2 a,node2 b)
{
	return a.to<b.to;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>mn>>mw;
	for(int i=1;i<=mn;i++)
	{
		cin>>nei[i].to>>nei[i].go;
		
	}
	for(int i=1;i<=mw;i++)
	{
		cin>>wai[i].to>>wai[i].go;
		
	}
	sort(nei+1,nei+mn+1,cmp1);
	sort(wai+1,wai+mw+1,cmp2);
	for(int i=0;i<=n;i++)
	{
		num=n;
		int j=n-i;
		qn.empty();
		qw.empty();
		for(int kn=1;kn<=mn;kn++)
		{
			if(kn<=i)
				qn.push(nei[i].go);
			int z=qn.top();
			if(nei[i].to>=z)
				{
					qn.pop();
					qn.push(nei[i].go);
					num++;
				}
		}
		for(int kw=1;kw<=mw;kw++)
		{
			if(kw<=i)
				qw.push(wai[i].go);
			if(wai[i].to>=qw.top())
				{
					qw.pop();
					qw.push(nei[i].go);
					num++;
				}
		}
		ans=max(num,ans);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
 }
 
 /*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
