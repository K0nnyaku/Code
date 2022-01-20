#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
long long led[500001]={0};
long long red[500001]={0};
long long ans1[500001]={0};
long long ans2[500001]={0};
int n=0;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	if(t==1){
		cout<<"-1"<<endl;
		return 0;
	}
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<2*n;j++){
			cout<<"L";
		}
		cout<<endl;
	}
	return 0;
}
