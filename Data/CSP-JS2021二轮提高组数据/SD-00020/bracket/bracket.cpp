#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,k;
bool check(string s) {
	int cnt=0,tmp=0;
	if(s[0]=='*'||s[n-1]=='*')
		return 0;
	for(int i=1;i<n;i++) {
		if(s[i-1]=='*'&&s[i]!='*')
			cnt=max(cnt,tmp),tmp=0;
		else if(s[i]=='*')
			tmp++;
	}
	if(cnt>k)
		return 0;
	stack<char> st;
	for(int i=0;i<n;i++)
		if(s[i]==')') {
			if(st.empty()) return 0;
			else if(st.top()!='(') return 0;
			else st.pop();
		}
		else if(s[i]=='(')
			st.push('(');
	if(st.empty()) {
		cout<<s<<endl;
		return 1;
	}
	return 0;
}
long long dfs(string s,int now) {
	if(now==n)
		return (long long)check(s);
	if(s[now]!='?')
		return dfs(s,now+1);
	long long ans=0;
	s[now]='(';
	(ans+=dfs(s,now+1))%=mod;
	s[now]=')';
	(ans+=dfs(s,now+1))%=mod;
	s[now]='*';
	(ans+=dfs(s,now+1))%=mod;
	return ans;
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	string s;
	cin>>n>>k>>s;
	cout<<dfs(s,0)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
