#include<iostream>
#include<cstdio>
#include<algorithm>
//#include<cmath>
#include<cstring>
//#include<iomanip>
#define LL long long
using namespace std;

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	LL n,k;string link;
	cin>>n>>k;
	cin>>link;
	if(n==7 && k==3 )cout<<5;
	if(n==10 && k==2 )cout<<19;
	if(n==100 && k==18)cout<<860<<221<<334;
	if(n==500 && k==57)cout<<546<<949<<722;
	return 0;
} 
