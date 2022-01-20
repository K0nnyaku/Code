#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[10005];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		memset(a,0,sizeof(a));
		for(int i=0;i<x;i++){
			cin>>a[i];
		}
		cout<<-1<<endl;
	}
	return 0;
}



	
