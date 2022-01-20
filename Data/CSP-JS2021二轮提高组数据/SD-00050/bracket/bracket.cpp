#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#define ll long long
#define MOD 1000000007
using namespace std;
struct STACK{
	ll head,top,bra;
}s[1010];
ll top;
ll n,k;
ll chuan[1010];
string str;
ll ans;
void dfs(ll );
bool check();
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	cin>>str;
	dfs(0);
	printf("%lld\n",ans%MOD);
	return 0;
}
bool check(){
	if(chuan[0]==0||chuan[n-1]==0)return false;
	top=0;
	ll zero=0;
	for(ll i=0;i<n;i++){
		if(chuan[i]==0)zero++;
		else zero=0;
		if(zero>k)return false;
		if(chuan[i]==1){
			s[top].bra++;
			top++;
			s[top].head=i;
			s[top].top=s[top].bra=0;
		}else if(chuan[i]==0){
			if(s[top].head==i-1){
				s[top].top=1;
			}
		}else if(chuan[i]==-1){
			if(top<1)return false;
			if(chuan[i-1]==0&&s[top].top==1&&s[top].bra>0)return false;
			top--;
		}
	}
	if(top>0)return false;
//	for(ll i=0;i<n;i++){
//		if(chuan[i]==1){
//			printf("(");
//		}else if(chuan[i]==0){
//			printf("*");
//		}else{
//			printf(")");
//		}
//	}
//	printf("\n");
	return true;
}
void dfs(ll ceng){
	if(ceng==n){
		if(check())ans++;
		return;
	}
	if(str[ceng]=='?'){
		chuan[ceng]=1;
		dfs(ceng+1);
		chuan[ceng]=0;
		dfs(ceng+1);
		chuan[ceng]=-1;
		dfs(ceng+1);
	}else{
		if(str[ceng]=='('){
			chuan[ceng]=1;
		}else if(str[ceng]==')'){
			chuan[ceng]=-1;
		}else{
			chuan[ceng]=0;
		}
		dfs(ceng+1);
	}
	return;
}
