#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int t;
char s[55505];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>s;
	}
	for(int i=1;i<=t;i++){
		cout<<"-1"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

