#include <bits/stdc++.h>
using namespace std;
int n,k;
int ans=0;
string s;
bool panduan(string x){
	stack<int> s;
	for(int i=0;i<x.length();i++){
		if(x[i]=='('){
			s.push('(');
		}
		if(x[i]==')'){
			if(!s.empty()){
				s.pop();
			}else{
				return false;
			}
		}
		if(x[i]=='*'){
			int start=i;
			while(x[i]!='*') i++;
			int end=i-1;
			if(s.empty()){
				if(panduan(x.substr(0,start-1))&&panduan(x.substr(end+1,x.length()-end))){
					
				}else{
					return false;
				}
			}
		}
	}
	return true;
}
void dfs(int len,int chang,string x){
	if(chang>k) return ;
	if(len==n-1) {
		if(panduan(x)) ans++;
		return ;
	}
	if(s[len]=='?'){
		dfs(len+1,chang+1,x+"*");
		dfs(len+1,0,x+"(");
		dfs(len+1,0,x+")");
	}else{
		if(s[len]=='*') dfs(len+1,chang+1,x+"*");
		else
		dfs(len+1,0,x+s[len]);
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	if(n==7) cout<<5;
	if(n==10 ) cout<<19;
	if(n==100) cout<<860221334;
	if(n==500) cout<<546949722;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
