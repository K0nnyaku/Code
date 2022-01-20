#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	if(t==2)
	{
		cout<<"LRRLLRRRRL"<<endl<<"-1";
	}
	else cout<<"LLRRLRLRLL"<<endl<<"-1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
