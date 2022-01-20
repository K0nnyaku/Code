#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,q,h,w;
char a[505];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>a;
	for(int i=1;i<=strlen(a);i++){
		if(a[i]=='(') q++;
		if(a[i]==')') h++;
		if(a[i]=='?') w++;
	}
	if(a[strlen(a)-1]=='*'||a[strlen(a)-1]=='(') cout<<0;
	else {
		if(n==1) cout<<0;
		/*if(n==2){
			if(a[1]=='('&&a[2]==')') cout<<0;
			if(a=='(?'||a=='?)'||a=='??') cout<<1;
			if(a[1]=='*'||a=='(*'||a=='*)') cout<<0;
		}*/
		if(n>1){
			if(q>h+w) cout<<0;
			if(h>q+w) cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

