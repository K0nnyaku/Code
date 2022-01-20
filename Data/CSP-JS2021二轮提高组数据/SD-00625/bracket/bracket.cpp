#include<bits/stdc++.h>
using namespace std;
int n,k;
char s[550];
int a[550];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='?')
		a[i+1]=1;
		if(s[i]=='(')
		a[i+1]=2;
		if(s[i]==')')
		a[i+1]=3;
		if(s[i]=='*')
		a[i+1]=4;
	}
	return 0;
} 
