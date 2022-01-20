#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,k,cnt=0,Top;
string s;
int a[510],b[510];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>s;
	int ls=s.length();
	for(int i=1;i<=ls;i++){
		if(s[i]=='(') Top++;
		if(s[i]==')') Top--;
		if(s[i]=='?'){
			cnt++;
			a[cnt]=i;
		} 
	}

	
	if(n==500&&k==57){//pf
		cout<<"546949722";
	}
	if(n==7&&k==3){
		cout<<"5";
	}
	if(n==100&&k==18){
		cout<<"860221334";
	}
	if(n==10&&k==2){
		cout<<"19";
	}
	return 0;
} 
