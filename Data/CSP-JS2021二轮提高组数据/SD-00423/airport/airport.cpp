#include<bits/stdc++.h>
using namespace std;
#define debug1 cout<<"debug";
int n,m1,m2;
const int maxn=100000+10;
int anss1[maxn],anss2[maxn];
struct li
{
	int id;
	int v;
	int lr;
}; 
bool cmp(li x,li y)
{
	if(x.v!=y.v) return x.v<y.v;
	else
	{
		if(x.lr==1) return 1;
		else return 0;
	}
}
li a[2*maxn],b[2*maxn];
int ans1[maxn],ans2[maxn];
int gui[maxn];
void solve1()
{
	int cnt=0,now=1,ansqwq=0;
	while(cnt<=m1*2)
	{
		if(a[++cnt].lr==1) now=gui[a[cnt].id];
		else
		{
			ans1[++ansqwq]=now;
			gui[a[cnt].id]=now;
			now++;
			
		}
		//cout<<cnt<<' '<<now<<endl;
	}
}
void solve2()
{
	int cnt=0,now=1,ansqwq=0;
	while(cnt<=m2*2)
	{
		if(b[++cnt].lr==1) now=gui[b[cnt].id];
		else
		{
			ans2[++ansqwq]=now;
			gui[b[cnt].id]=now;
			now++;
		}
		//cout<<cnt<<' '<<now<<endl;
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>a[i].v>>a[i+m1].v;
		a[i].id=a[i+m1].id=i;
		a[i].lr=0;
		a[i+m1].lr=1;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>b[i].v>>b[i+m2].v;
		b[i].id=b[i+m2].id=i;
		b[i].lr=0;
		b[i+m2].lr=1;
	}
	sort(a+1,a+m1*2+1,cmp);
	sort(b+1,b+2*m2+1,cmp);	 
	/*
	for(int i=1;i<=m1*2;i++)
	{
		cout<<a[i].v<<' '<<a[i].id<<endl;
	}
	*/
	solve1();memset(gui,0,sizeof gui);
	solve2();
	/*
	for(int i=1;i<=m2;i++)
	{
		cout<<ans2[i]<<' ';
	}
	*/
	sort(ans1+1,ans1+m1+1);
	sort(ans2+1,ans2+m2+1);
	for(int i=1;i<=m1;i++)
	{
		if(ans1[i]!=ans1[i+1])
		{
			anss1[ans1[i]]=i;
		}
	}
	for(int i=1;i<=m2;i++)
	{
		if(ans2[i]!=ans2[i+1])
		{
			anss2[ans2[i]]=i;
		}
	}
	int ans=0;
	/*
	for(int i=1;i<=m1;i++)
	{
		cout<<anss1[i]<<' ';
	}
	cout<<endl;
	for(int i=1;i<=m2;i++)
	{
		cout<<anss2[i]<<' ';
	}
	*/
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,anss1[i]+anss2[n-i]);
	}
	
//	cout<<endl; 
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//记得删文件 
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
//21!9-324@emb 
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

