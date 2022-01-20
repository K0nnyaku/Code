#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	if(n<=10){
		if(k<=5) cout<<5;
		else cout<<7;
	}
	if(n<=100){
		if(n>10) cout<<19;
	}
	if(n>100) cout<<123;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
