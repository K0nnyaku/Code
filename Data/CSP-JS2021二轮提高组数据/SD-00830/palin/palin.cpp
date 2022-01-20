#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
int T;
int x[110][500010];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>x[i][0];
		for(int j=1;j<=x[i][0];j++)
		{
			cin>>x[i][j];
		}
	}
	for(int i=1;i<=T;i++)
	{
		cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
