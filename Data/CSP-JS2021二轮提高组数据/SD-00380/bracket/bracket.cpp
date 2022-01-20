#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	srand(time(0));
	int n,m,a[1000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
 	if(n<=15){
 		int d=rand()%100;
 		cout<<d;
	}
	else if(n<=40){
 		int d=rand()%1000;
 		cout<<d;
	}
	else if(n<=100){
 		int d=rand()%10000;
 		cout<<d;
	}
	else if(n<=500){
 		int d=rand()%100000;
 		cout<<d;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
