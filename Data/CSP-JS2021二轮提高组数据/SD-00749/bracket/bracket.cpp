#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define ll long long

ll qread(){
	ll number=0;int zhengfu=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') zhengfu=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') number=(number<<1)+(number<<3)+(ch^48),ch=getchar();
	return number*zhengfu;
}
ll n,k,w;
char s[100001];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=qread(),k=qread();
	for(int i=1;i<=n;++i){
		s[i]=getchar();
		if(s[i]=='?') w++;
	}
	cout<<w*(w-1)*(w-2)*(w-3)**(w-5)%1000000007;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
7 3
(*??*??
*/
