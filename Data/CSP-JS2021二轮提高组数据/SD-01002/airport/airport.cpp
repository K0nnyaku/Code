#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;
#define N 100005
int n,por1,por2,maxn1 = -1,maxn2 = -1,minn1,minn2,inf,ans;
int a[N][2],b[N][2];
int maxnn[2];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	//初始化
	memset(maxnn,127,sizeof(maxnn));
	minn1 = minn2 = inf = maxnn[0];
	//读入数据 
	cin >> n >> por1 >> por2;
	for(int i = 1;i <= por1;i++)
	{
		cin >> a[i][0] >> a[i][1];
		minn1 = min(minn1,a[i][0]);
		maxn1 = max(maxn1,a[i][1]);
	}
		
	for(int i = 1;i <= por2;i++)
	{
		cin >> b[i][0] >> b[i][1];
		minn2 = min(minn2,b[i][0]);
		maxn2 = max(maxn2,b[i][1]);
	}
	
	cout << max(maxn1,maxn2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
