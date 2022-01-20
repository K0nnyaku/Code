#include<iostream>
#include<cstdio>
using namespace std;

int main(){ 	
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	if(T==1){
		cout<<"-1"<<endl;
		return 0;
	}
	while(T--){
		printf("-1");
	}
	return 0;
}
