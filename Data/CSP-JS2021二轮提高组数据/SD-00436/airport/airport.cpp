#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<vector>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#define ll long long
using namespace std;
struct flight
{
	int l,r; 
}f1[100010],f2[100010];
int lst_tm1[100010];
int lst_tm2[100010];
int n,m1,m2;
bool cmp(struct flight a,struct flight b)
{
	return a.l<b.l;
}
void input()
{
	cin >> n >> m1 >> m2;
	for(int i=1;i<=m1;i++)
		cin >> f1[i].l >> f2[i].r;
	for(int i=1;i<=m2;i++)
		cin >> f2[i].l >> f2[i].r;
	sort(f1+1,f1+1+m1,cmp);
	sort(f2+1,f2+1+m2,cmp);
}
void calc()
{
	int ans=0,mans=0;
	for(int i=0;i<=n;i++)//循环个数
	{
		int now=0;
		for(int k=1;k<=m1;k++)//飞机 
		{
			int flag=0;
			for(int j=1;j<=now;j++)//循环桥
			{
				if(lst_tm1[j]<f1[k].l)
				{
					lst_tm1[j]=f1[k].r,ans++;
					flag=1;
					break;
				}
			}
			if(!flag)
				now++,ans++;
			if(now>i)
				now--,ans--;
		}
		now=0;
		for(int k=1;k<=m2;k++)//飞机 
		{
			int flag=0;
			for(int j=1;j<=now;j++)//循环桥
			{
				if(lst_tm2[j]<f2[k].l)
				{
					lst_tm2[j]=f2[k].r,ans++;
					flag=1;
					break;
				}
			}
			if(!flag)
				now++,ans++;
			if(now>n-i)
				now--,ans--;
		}
		mans=max(ans,mans);
		ans=0;
	}
	cout << mans << endl;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	input();
	calc();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

