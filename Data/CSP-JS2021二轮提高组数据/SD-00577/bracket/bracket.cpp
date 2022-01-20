#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 1e9+7
using namespace std;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);	
	int n,k;
	string s;
	scanf("%d%d",&n,&k);
	cin>>s;
	if(n==0||k==0) {
		printf("%d\n",0);
		return 0;
	} 
	int ans=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='?') ans++;
	}
	long long t=MAXN;
	ans=ans%t;
	if(n==1||k==1){
		printf("%d\n",ans);
		return 0;
	}
	int cnt=n*k;
	cnt%=t;
	printf("%d\n",cnt);
	return 0;
} 
