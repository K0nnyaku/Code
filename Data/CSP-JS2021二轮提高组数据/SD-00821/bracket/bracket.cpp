#include<bits/stdc++.h>
#include<stack>
#define ll long long
using namespace std;
stack<int> st;
stack<char> sct;
int n,k,ans,num;
int mod=1e9+7;
string s;
void dfs(int id) {
	if(id==n) {
		if(!num&&!st.top()&&sct.top()!='(') {
//			cout<<id<<endl;
			ans++;
			ans%=mod;
		}
		return;
	}
	if(s[id]=='?') {
		if(!st.empty()&&st.top()<k&&num) {
			st.push(st.top()+1);
			sct.push('*');
			dfs(id+1);
			st.pop();
			sct.pop();
		}
		if(num>0) {
			num--;
			st.push(0);
			sct.push(')');
			dfs(id+1);
			st.pop();
			sct.pop();
			num++;
		}
		num++;
		st.push(0);
		sct.push('(');
		dfs(id+1);
		num--;
		st.pop();
		sct.pop();
	}  
	else {
		if(s[id]=='*') {
			if(!st.empty()&&st.top()+1==k) return;
			st.push(st.top()+1);
		} else if(s[id]=='('){
			st.push(0);
			num++;
		}
		else{
			num--;
			st.push(0);
		}
		sct.push(s[id]);
		dfs(id+1);
	}
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	dfs(0);
	printf("%d",ans);
	return 0;
}
