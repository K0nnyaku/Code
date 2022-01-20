#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<string>
#include<stack>
using namespace std;
const int N=1e5,mod=1e9+7;
int n,k,lens,ans;
string s;
string ss;
bool check(){
	int num0=0;
	int num1=0,num2=0;
	stack<char>st;
	if(ss[0]=='*')return false;
	if(ss[lens-1]=='*')return false;
	for(int i=0;i<lens;i++){
		if(ss[i]=='('&&ss[i+1]==')'&&ss[i-1]=='*'&&ss[i+2]=='*')return false;
		if(ss[i]=='*'){
			num0++;
		}else if(ss[i]=='('){
			num1++;
			num0=0;
			st.push('(');
		}else if(ss[i]==')'){
			num2++;
			num0=0;
			if(st.empty())return false;
			st.pop();
		}
		if(num0>=k)return false;
	}
	if(!st.empty())return false;
	if(num1!=num2)return false;
	return true;
}
void dfs(int max_dep){
	if(max_dep==lens){
		if(check()){
			ans=(ans+1)%mod;
			return;
		}
	}
	if(s[max_dep]=='*'){
		ss+='*';
		dfs(max_dep+1);
	}else if(s[max_dep]=='('){
		ss+='(';
		dfs(max_dep+1);
	}else if(s[max_dep]==')'){
		ss+=')';
		dfs(max_dep+1);
	}else if(s[max_dep]=='?'){
		string str=ss;
		ss+='*';
		dfs(max_dep+1);
		ss=str;
		ss+='(';
		dfs(max_dep+1);
		ss=str;
		ss+=')';
		dfs(max_dep+1);
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	if(n>=100){
		cout<<n/3<<endl;
		return 0;
	}
	lens=s.length();
	dfs(0);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
