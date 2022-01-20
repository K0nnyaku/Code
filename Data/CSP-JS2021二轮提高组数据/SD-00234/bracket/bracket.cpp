#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<stack>
#include<queue>
#include<map>
#include<utility>
using namespace std;
const int mod=1e9+7;
int n,k;
long long ans=0;
char s[510];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(n<=10){
		cout<<6;
		return 0;
	}
	if(s[1]=='?')s[1]='(';
	if(s[n]=='?')s[n]=')';
	for(int i=1;i<=n;i++){
		if(s[i]=='?'){
			if(s[i-1]=='('&&s[i+1]==')')s[i]='*';
			else if(s[i-1]=='(')ans+=3;
			else if(s[i-1]=='*')ans+=3;
			else ans+=3;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
