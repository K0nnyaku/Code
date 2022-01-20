#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring> 
using namespace std;
char s[506]; 
int n,k,ans,x=0;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(s[1]=='?'){ 
		s[1]='('; 
	}
	if(s[n]=='?'){
		s[n]=')';
	}
	for(int i=1;i<=n;i++){
		
	}
	cout<<ans%1000000007;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
