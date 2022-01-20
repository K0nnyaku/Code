#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#define MOD 1000000007
using namespace std;
long long n,k,X,ans;
string s;
string sk[101];
long long ks[10010];
queue<char>q;
bool pd(){
	long long ans=0,t=0;
	while(!q.empty()){
		q.pop();
	}
	for(long long i=0;i<s.length();i++){
		if(s[i]=='*'){
			ans++;
			if(ans>k){
				return false;
			}
			continue;
		}
		if(s[i]==')'){
			ans=0;
			if(!q.empty()){
				q.pop();
			}else{
				return false;
			}
		}else{
			ans=0;
			q.push(s[i]);
		}
	}
	if(!q.empty()){
		return false;
	}
	if(s[0]=='*'||s[s.length()-1]=='*'){
		return false;
	}
	ans=0;
	for(long long i=0;i<s.length();i++){
		if(s[i]=='('){
			t++;
			sk[t]="";
			sk[t]+=s[i];
			ans++;
		}else if(s[i]==')'){
			sk[t]+=s[i];
			if(i+1!=s.length()){
				if(s[i+1]!=')'&&s[i+1]!='('&&t-1!=0){
					return false;
				}
			}
			t--;
		}else if(t!=0){
			sk[t]+=s[i];
		}
	}
	return true;
}
void dfs(long long id,long long x){
	if(id==n){
		if(pd()==true){
			ans++;
			ans%=MOD;
//			cout<<s<<endl;
		}
		return;
	}
	if(s[id]=='?'){
		//*
		s[id]='*';
		dfs(id+1,x+1);
		s[id]='?';
		//(
		s[id]='(';
		dfs(id+1,x);
		s[id]='?';
		//)
		s[id]=')';
		dfs(id+1,x);
		s[id]='?';
	}else{
		dfs(id+1,x);
	}
	return;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(long long i=0;i<s.length();i++){
		if(s[i]=='*'){
			X++;
		}
	}
	dfs(0,X);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
