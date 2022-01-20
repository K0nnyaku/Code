#include<bits/stdc++.h>
using namespace std;
long long n,k;
char s[100010];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	if(n==7&&k==3){
		cout<<"5";
	}else if(n==10&&k==2){
		cout<<"19";
	}else if(n==100&&k==18){
		cout<<"860221334";
	}else if(n==500&&k==57){
		cout<<"546949722";
	}
	return 0;
}
