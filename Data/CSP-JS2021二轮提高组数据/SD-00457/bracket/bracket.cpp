#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>

using namespace std;
const int N=100010;


int ans=0;


int k,n;int p=0;
string s;
int st[N]={0};
int last=0;
int h[N];
void solve(int idx,int tmp){
	if(tmp<0) return;
	if(idx>p) return;
	if(idx==p){
		if (tmp-1!=0) return;
		if (n-last-2>k) return;
		if(n-last-2!=0&&s[last]==')') return;
		ans++;
		return;
	}
	if(s[h[idx]]=='(') solve(idx+1,tmp+1);
	if(s[h[idx]]==')') solve(idx+1,tmp-1);
	

	if(h[idx]-last-1>k) return;
	solve(idx+1,tmp);
	s[h[idx]]='(';last=h[idx];solve(idx+1,tmp+1);
	s[h[idx]]=')';last=h[idx];solve(idx+1,tmp-1);
	s[h[idx]]='*';return;
}
int main(){
	freopen("bracket2.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	if(s[0]=='*') {cout<<0;return 0;}
	if(s[n-1]=='*') {cout<<0;return 0;}
	s[0]='(';s[n-1]=')';last=0;
	for(int i=1;i<n-1;i++){
		if(s[i]=='*') st[i]=1;
		else h[p++]=i;
		if(s[i]=='?') {s[i]='*';}
	}
	solve(0,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

