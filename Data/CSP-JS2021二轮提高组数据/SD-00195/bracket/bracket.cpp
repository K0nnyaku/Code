#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#define long long
#define dd double
#define ld long double
#define ull unsigned long long
#define N 1000100
#define M number
using namespace std;

const int mod=1e9+7;

template<typename T> inline void read(T &x){
	x=0;int flag=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') flag*=-1;
	for(;isdigit(c);c=getchar()){x*=10;x+=c-'0';}
	x*=flag;
}

char s[N],t[N];
int n,k,sta[N],top,ans,Cnt[N];
bool pd[N];

inline bool Check(){

	for(int i=0;i<=n;i++){
		top=0;
		Cnt[i]=0;pd[i]=0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(t[i]=='('){
			pd[top]=1;
			sta[++top]=i;
			Cnt[top]=0;pd[top]=0;
		}
		else if(t[i]==')'){
			if(!top) return 0;
			top--;
		}
		else if(t[i]=='*'){
			if(Cnt[top]&&pd[top]) return 0;
			if(!top&&!pd[top]) return 0;
			Cnt[top]++;
			if(Cnt[top]>k) return 0;
		}
	}
	if(top) return 0;
	return 1;
}

inline void dfs(int k){
	if(k==n+1){
		if(!Check()) return;
		ans++;ans%=mod;
		return;
	}
	if(s[k]!='?'){
		t[k]=s[k];dfs(k+1);
	}
	else{
		t[k]='*';dfs(k+1);
		t[k]='(';dfs(k+1);
		t[k]=')';dfs(k+1);
	}
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	read(n);read(k);
	scanf("%s",s+1);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
