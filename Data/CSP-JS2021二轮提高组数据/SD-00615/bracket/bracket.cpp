#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<algorithm> 
using namespace std;
unsigned long long a,ans;
stack<char>kuo;
int n,k,sum,f1,f2,k_now;
string c;
long long const mod_mod=1e9+7;
void dfs(string s,int sheng){
	if(sheng==0){
	//	cout<<"*";
	//cout<<s<<endl;
		while(!kuo.empty())kuo.pop();
		if(s[0]!='('||s[n-1]!=')') return;
		kuo.push('(');
		
		for(int i=1;i<s.length()-1;i++){
			if(s[i-1]=='*'&&s[i]=='('&&s[i+1]==')'&&s[i+2]=='*')
				return;
			if(s[i]=='*'){
				f1=f2=0;
				k_now=0;
				while(s[i]=='*'){
					k_now++;
					i++;
				}
				i--;
				if(k_now>k)return;
			}
			else if(s[i]=='(')kuo.push('(');
			else if(s[i]==')'){
				if(kuo.top()=='(')kuo.pop();
				else if(s[i-1]=='(')return;
				else return;
			}
		}
		if(kuo.top()=='(')kuo.pop();
		else return;
		if(kuo.empty()){
			a++;	
//			cout<<a<<" "<<s<<endl;
		}
		return;
	}
	
	for(int i=0;i<n;i++){
		if(s[i]=='?'){
			if(i==0){
				s[i]='(';
				dfs(s,sheng-1);
			}else{	
				s[i]='(';
				dfs(s,sheng-1);
				s[i]='*';
				dfs(s,sheng-1);
				s[i]=')';
				dfs(s,sheng-1);
			}
		}
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>c;
	while(c[0]==' '){
		c.erase(0);
	}
	if(c==""){
		cout<<"0";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=0;i<n;i++){
		if(c[i]=='?')sum++;
	}
	dfs(c,sum);
	cout<<a%mod_mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
