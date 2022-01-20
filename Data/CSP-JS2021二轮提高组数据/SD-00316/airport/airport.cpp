#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

const int N=1e5+10;
struct fl{int x,y;}p[N],t[N];
int n,m[2];

bool cmp(const fl &x,const fl &y){return x.x<y.x;}

int ans1[N],ans2[N];
bool v[N],w[N];

void check1()
{
	for(int i=1;i<=n;i++)
	{
		ans1[i]=ans1[i-1];int rc=0;
		if(ans1[i]==m[0]) continue;
		for(int j=1;j<=m[0];j++)
		{
			if(v[j]) continue;
			if(p[j].x>rc) {
				ans1[i]++;v[j]=1;rc=p[j].y;
			}
		}
	}
}

void check2()
{
	for(int i=1;i<=n;i++)
	{
		ans2[i]=ans2[i-1];int rc=0;
		if(ans2[i]==m[1]) continue;
		for(int j=1;j<=m[1];j++)
		{
			if(w[j]) continue;
			if(t[j].x>rc) {
				ans2[i]++;w[j]=1;rc=t[j].y;
			}
		}
	}
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m[0],&m[1]);
	for(int i=1;i<=m[0];i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	for(int i=1;i<=m[1];i++)
		scanf("%d%d",&t[i].x,&t[i].y);
	sort(p+1,p+m[0]+1,cmp);
	sort(t+1,t+m[1]+1,cmp);
	check1();check2();
	int Ans=0;
	for(int i=0;i<=n;i++)
		if(ans1[i]+ans2[n-i]>Ans)
			Ans=ans1[i]+ans2[n-i];
	printf("%d",Ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
