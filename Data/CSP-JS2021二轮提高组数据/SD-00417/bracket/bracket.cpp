#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int k,n;
string s;
const int M=1e9+7;
long long ans;
vector<int> zuo;
int xing;
void dfs(int x){
	if(x==n){
		if(zuo.size())return;
		int u=n-1;
		if(s[u]=='*')ans++;
		return;
	}
	if(s[x]=='('){
		zuo.push_back(x);
		
		dfs(x+1);
		zuo.pop_back();
	}
	else if(s[x]=='*'){
		if(xing==k)return;
		else {
			xing++;
			dfs(x+1);
			xing--;
		} 
	}
	else if(s[x]==')'){
		if(zuo.size()==0)return;
		else{
			int o=zuo[zuo.size()];
			zuo.pop_back();
			dfs(x+1);
			zuo.push_back(o);
		}
	}
	else{
		if(xing<k){
			xing++;
			s[x]='*';
			dfs(x+1);
			s[x]='?';
			xing--;
		}
		if(zuo.size()>0){
			int o=zuo[zuo.size()];
			zuo.pop_back();
			s[x]=')';
			dfs(x+1);
			s[x]='?';
			zuo.push_back(o);
		}
		zuo.push_back(x);
		s[x]='(';
		dfs(x+1);
		s[x]='?';
		zuo.pop_back();
	}
	return;
	
	
	
}
int main(){
freopen("bracket.in","r",stdin);
freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	dfs(0);
	cout<<ans%M;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
