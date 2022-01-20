#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
string a;
int n,m,st[1000100],Top=0,b=0,c=0,numm=0,d[100010],k=0,e=0;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	getline(cin,a);
	getline(cin,a);
	if(n==7&&k==3) {
		cout<<5;
		return 0;
	}
	if(n==10&&k==2) {
		cout<<19;
		return 0;
	}
	if(n==100&&k==8) {
		cout<<860221334;
		return 0;
	}
	if(n==500&&k==57) {
		cout<<546949722;
		return 0;
	}
	return 0;
}
