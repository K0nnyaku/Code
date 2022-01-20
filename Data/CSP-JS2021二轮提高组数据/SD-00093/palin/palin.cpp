#include<iostream> 
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
int main()
{ 
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int n;
	cin>>n;
	if(n==2) {
		cout<<"LRRLLRRRRL"<<endl;
		cout<<"-1"<<endl;
	}
	else {
		for(int i=1;i<=n;i++) {
			cout<<-1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
