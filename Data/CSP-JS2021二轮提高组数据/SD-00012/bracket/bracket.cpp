#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<vector>

using namespace std;

const int N = 510;
long long Mod = 1e9+7;

int n, k, qnum=0;
char s[N];
int num[N],l ,r;
long long ans=0;

bool check(){
	int lf=0;
	for(int i=1;i<=n;i++){
		
		if(s[i]=='?') return 0;
		if(s[i]==')') lf--;
		if(s[i]=='(') lf++;
		if(lf<0) return 0;
	}
	if(lf!=0) return 0;
	for(int i=1;i<=n;i++){
		if(s[i]=='*'){
			int cnt=0,idx=1;
			for(int j=i;j<=n && s[j]=='*';j++){
				cnt++;
				idx=j;
				if(cnt>k) return 0;
			}
		}
	}
	for(int i=n;i>=1;i--){
		if(s[i]=='*')return 0;
		if(s[i]==')') break;
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='*')return 0;
		if(s[i]=='(') break;
	}
	l=1,r=n;
	while(l<=r){
		int kkk=0;
		while(l<=r) {if(s[l]!='(')  l=l+1; else break;}
		
		if(s[l-1]=='*') kkk++;l++;
		while(l<=r) {if(s[r]==')') break; else r--;}
		if(s[r+1]=='*') kkk++;
		r--;
		
		if(kkk>=2) return 0;
		
	}
	return 1;
} 

void dfs(int x){
	if(x>n){
		if(check()) ans=(ans+1ll)%Mod;
		return ;
	}
	if(s[x]!='?') {
		for(int i=x+1;i<=n;i++){
			if(s[i]=='?'){
				dfs(i);
				return ;
			}
		}
	}
	s[x]='*';
	dfs(x+1);
	s[x]='(';
	dfs(x+1);
	s[x]=')';
	dfs(x+1);
	s[x]='?';
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int l=1,r=n;
	ans=0;
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}

