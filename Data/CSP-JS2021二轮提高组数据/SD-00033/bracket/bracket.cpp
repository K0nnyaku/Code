#include<iostream> 
#include<cstdio>
#include<cstring>
using namespace std;

/*

get a good job!
整个好活 

lcj AK IOI every day!!
lyx 吊打国家队

froepen
//freopen("breckat.in","w",stdout);
//freopen("bra.ans","r",stdin);

//fclose(stdin);
//fclose(stdout);

cin<<"你被骗了";

CCCCCCCCCCCCCCCCCCCOrz

#define mod ((long long)(1e7+9))

#define ccf for(int i=1;i<=n;++i)

airports?

bra ckets?

cout>>"你又被骗了"; 

pulin palen pelin pilan polan? 

我嫌弃了polan! 

traffic jam

AFO? 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
第一题简单点吧 
目标：120

密码：21!9-324@emb 

*/ 
#define ll long long
const int mod=1e9+7;
char s[501]; 
int n,k;
int sum=0; 
char S[501];
int top;
int Sfk[501],topfk;
bool check(int l,int r){
	cout<<l<<' '<<r<<endl;
	if(l==r) return 0;
	if(l+1==r&&s[l]==s[r]&&s[r]=='*') return 1;
	if(l+1==r) return s[l]=='('&&s[r]==')';
	if(l+2==r){
		if(s[l-1]=='('&&s[r+1]==')'){
			if(s[l]=='*'&&s[l+1]=='('&&s[r]==')') return 1;
			if(s[l]=='('&&s[l+1]==')'&&s[r]=='*') return 1;
			if(s[l]=='('&&s[l+1]=='*'&&s[r]==')') return 1;
		}
		else return s[l]=='('&&s[l+1]=='*'&&s[r]==')';
	}
	if(s[l-1]=='('&&s[r+1]==')'){
		int ans=0;
		for(int i=l;i<=r;++i){
			if(s[i]!='*'){
				ans=1;
				break;
			}
		}
		if(ans==0) return 1;
		if(s[l]=='*'&&s[r]=='*') return 0;
		int Q=0,q=l;
		while(s[q]=='*') ++Q,++q;
		if(Q>k) return 0;
		if(Q) return check(q,r);
		Q=0,q=r;
		while(s[q]=='*') ++Q,--r;
		if(Q>k) return 0; 
		if(Q) return check(l,q);
	}
	if(s[l]=='('&&s[r]==')'){
 		if(check(l+1,r-1)) return 1;	
	}
	for(int i=l+1;i<=r-1;++i){
		if(check(l,i-1)&&s[i-1]!='*'){
			for(int j=i;j<=i+k-1;++j){
				if(s[j]=='*'){
					if(check(j,r)) return 1; 
				}
				else{
					break;
				}
			}
		}
	}
	for(int i=l+1;i<=r-1;++i){
		if(check(l,i)&&check(i+1,r)) return 1;
	}
	return 0;
}
void dfs(int nowl,int nowr,int nowk,int idx){
	if(nowk>k) return;
	if(idx>n){
		if(check(1,n)) ++sum;
		return;
	}
	if(s[idx]=='('){
		dfs(nowl+1,nowr,0,idx+1);
		return;
	}
	if(s[idx]==')'){
		dfs(nowl,nowr+1,0,idx+1);
		return;
	}
	if(s[idx]=='*'){
		if(nowk==k) return;
		dfs(nowl,nowr,nowk+1,idx+1);
		return;
	}
	s[idx]='(';dfs(nowl+1,nowr,0,idx+1);
	s[idx]=')';dfs(nowl,nowr+1,0,idx+1);
	if(nowk<k) s[idx]='*',dfs(nowl,nowr,nowk+1,idx+1);
	s[idx]='?';
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout); 
	cin>>n>>k;
	cout<<((1<<n)-1);
	return 0;
}
