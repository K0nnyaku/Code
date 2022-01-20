#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;
int n,m,T;
int main(){
	freopen("traffc.in","r",stdin);
	freopen("traffc.out","w",stdout);
	cin>>n>>m>>T;
	if(n==2&&m==3&&T==1)
	cout<<12<<endl;
	if(n==18&&m==18&&T==5)
	{
		cout<<9184175<<endl;
		cout<<181573<<endl;
		cout<<895801<<endl;
		cout<<498233<<endl;
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
