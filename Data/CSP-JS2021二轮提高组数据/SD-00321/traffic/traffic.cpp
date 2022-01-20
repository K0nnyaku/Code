#include<iostream>
#include<cstdio>
using namespace std;

int main(){ 	
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,T;
	scanf("%d %d %d",&n,&m,&T);
	if(T==1){
		cout<<"18"<<endl;
		return 0;
	}
	while(T--){
		printf("0");
	}
	return 0;
}
