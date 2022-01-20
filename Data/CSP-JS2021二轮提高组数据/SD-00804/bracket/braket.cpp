#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
inline ll read() {
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
ll n,k,ans;
string kkk;
map <string,bool> mp;
bool check(string s) {
	if(s[0]=='*'||s[s.size()-1]=='*') return false;
	ll num=0,st=0;
	for(int i=0;i<s.size();i++) {
		if(st==0&&s[i]=='*') return false;
		if(s[i]=='(') st++;
		else if(s[i]==')') st--;
		if(s[i]=='*') num++;
		else num=0;
		if(num>k) return false;
		if(st<0) return false;
	}
	if(st==0) return true;
	else return false;
}
void dfs(string s,ll l) {
	if(mp[s]) return  ;
	mp[s]=true;
	bool find=false;
	for(int i=l;i<=n;i++) {
		if(find) break;
		if(s[i-1]=='?') {
			string ttt=s;
			ttt[i-1]='*';
			dfs(ttt,l+1);
			ttt=s;
			ttt[i-1]='(';
			dfs(ttt,l+1);
			ttt=s;
			ttt[i-1]=')';
			dfs(ttt,l+1);
			find=true;
			//break;
		}
		
	}
	if(!find) {
		if(check(s)) {
			ans++;
			//cout<<s<<'\n';
		}
		return ;
	}
}
int main() {
	freopen("braket.in","r",stdin);
	freopen("braket.out","w",stdout);
	n=read();k=read();
	cin>>kkk;
	dfs(kkk,0);
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}

