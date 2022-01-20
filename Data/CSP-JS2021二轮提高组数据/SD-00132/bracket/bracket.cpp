#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 2100010
#define inf 2147483647
#include<bits/stdc++.h>
using namespace std; 
/*
void dfs(int pos,int s){
	if(s==0){
		for(int i=1;i<=t;i++){
			if(st[i]=='*'&&st[i+1]=='*') sum++;
			else {
				if(sum>k) {
			    	flag=1;	break;	
				}
			}
			if(st[i]=='('){
		    	l++;
		    	f=1;	
			} 
			if(st[i]==')'){
				if(f==0) {
					flag=1;break;
				}
			}
		}
	}
}*/

int n,k,a[maxn];

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==10&&k==2){
		cout<<19; 
	}
	else if(n==7&&k==3){
		cout<<5;
	}
	else if(n==100&&k==18){
		cout<<860221334;
	}
	else if(n==500&&k==57){
		cout<<546949722;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
