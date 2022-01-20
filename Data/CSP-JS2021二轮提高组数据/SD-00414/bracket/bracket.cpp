#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=1e6;
int ans,n,k,a[N];
string s;
int dfs(int now,int type){
	if(now==n)return 1;
	if(type){
		if(type==2){
			int cnt=0;
			for(int i=now;i>=0;i--){
				if(s[i]=='*'){
					cnt++;
				}
				else break;
			}
			if(cnt>k)return 0;
			ans+=dfs(now+1,a[now+1]);
		}
		if(type==3){
			int l=0,r=0;
			for(int i=now;i>=0;i--){
				if(s[i]=='(')l++;
				if(s[i]==')')r++;
			}
			if(r>l)return 0;
			ans+=dfs(now+1,a[now+1]);
		}
		if(type==1)ans+=dfs(now+1,a[now+1]);
	}
	int cnt=0;
	for(int i=now-1;i>=0;i--){
		if(s[i]=='*'){
			cnt++;
			continue;
		}
		else{
			break;
		}
	}
	if(cnt<k){
		s[now]='*',a[now]=2;
		ans+=dfs(now+1,a[now+1]);
		s[now]='?',a[now]=0;
	}
	int l=0,r=0,flag=0;
	for(int i=now-1;i>=0;i--){
		if(s[i]==')')r++;
		if(s[i]=='(')l++;
	}
	if(l>r){
		s[now]=')',a[now]=3;
		ans+=dfs(now+1,a[now+1]);
		s[now]='?',a[now]=0;
	}
	s[now]='(',a[now]=1;
	dfs(now+1,a[now+1]);
	s[now]='?',a[now]=0;
	return ans%mod;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cout<<0;
	return 0;
}
