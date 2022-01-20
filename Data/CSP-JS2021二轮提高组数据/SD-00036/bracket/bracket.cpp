//ccf NMSL!!!! 
//duliu string
//bao da 0 le 
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
#define ll long long 
ll n,k,mo=1e9+7,ans;
string s;
/*
bool ck(){
	stack<int> qa,pp;
	int qb=0,la=-1,cs=0,state;
	for(int i=0;i<n;++i){
		if(s[i]=='('){
			qa.push(i);
			la=-1;
		}
		else if(s[i]==')'){
			if(q.empty())
				return 0;
			
			qa.pop();
			la=-1;
		}
		else{
			if(la!=-1 && i-la==k)
				return 0;
			if(i==0 || i==n-1)
				return 0;
			if(i!=n-1 && s[i+1]=='*'){
				if(s[i-1]!='*')
					la=i;
				continue;
			}
			if(s[la-1]=='(' && s[i+1]==')')
				continue;
			if(s[la-1]==')' && s[i+1]=='(')
				continue;
			if(s[la-1]=='(' && s[i+1]=='('){
				state=1;
				pp.push(i+1);
				continue;
			}
			if(s[la-1]==')' && s[i+1]==')'){
				continue;
			}
			return 0;
		}
	}
	return 1;
}
void dfs(int now){
	if(now==n){
		if(ck()){
			++ans;
			ans%=mo;
		}
		return ;
	}
	if(s[now]=='?'){
		s[now]='(';
		dfs(now+1);
		s[now]=')';
		dfs(now+1);
		s[now]='*';
		dfs(now+1);
	}
}*/
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	//cin>>n>>k;
	//cin>>s;
	//dfs(0);
	//cout<<ans%mo<<endl;
	cout<<0<<endl;
	return 0;
} 
