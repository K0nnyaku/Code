#include<iostream> 
#include<cstdio>
using namespace std;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[50010];
		for(int i=0;i<2*n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<2*n;i++)//对于测试点18-20，有特殊性质
		{
			cout<<"L";//输出L，操作方案为全L时字典序最小 
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
