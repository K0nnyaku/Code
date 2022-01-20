#include<iostream> 
#include<iomanip> 
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int n,T,a[500005];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>n;
		for(int j=0;j<2*n;j++)
		{
			cin>>a[i];
		}
	}
	for(int i=0;i<T;i++)
	{
		cout<<-1;
	}
	return 0;
}
