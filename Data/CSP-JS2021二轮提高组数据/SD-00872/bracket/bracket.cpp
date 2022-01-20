#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int n,k,ans;
string s;
bool check(int l,int r){
	if(r-l<=1){
		return 1;
	}
	int kh=0,t,khs=0,xs=0;
	for(int i=l;i<r;i++){
		if(s[i]=='('){
			if(kh==0){
				t=i+1;
			}
			kh++;
		}
		if(s[i]==')'){
			kh--;
			if(kh==0){
				khs++;
				if(!check(t,i)){
					return 0;
				}
			}
		}
		if(kh==0&&s[i]=='*'&&(i==l||s[i]!=s[i-1])){
			xs++;
		}
	}
	if(khs>=xs||khs==0){
		return 1;
	}
	else{
		return 0;
	}
}
void dfs(int wz,int zhan,int xn){
	while(wz<s.length()&&s[wz]!='?'){
		if(s[wz]=='('){
			zhan++;xn=0;
		}
		if(s[wz]==')'){
			zhan--;xn=0;
			if(zhan<0){
				return;
			}
		}
		if(s[wz]=='*'){
			xn++;
			if(xn>k){
				return;
			}
		}
		wz++;
	}
	if(wz==s.length()){
		if(zhan==0&&check(1,s.length()-1)){
			//cout<<s<<endl;
			ans++;
		}
		return;
	}
	s[wz]='(';
	dfs(wz+1,zhan+1,0);
	s[wz]='?';
	if(zhan!=0){
		s[wz]=')';
		dfs(wz+1,zhan-1,0);
		s[wz]='?';
	}
	if(xn!=k){
		s[wz]='*';
		dfs(wz+1,zhan,xn+1);
		s[wz]='?';
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>s;
	if(s[0]=='*'||s[s.length()-1]=='*'||s[0]==')'||s[s.length()-1]=='('){
		cout<<"0";return 0;
	}
	int tt=0;
	for(int i=1;i<s.length();i++){
		if(s[i]=='*'){
			tt++;
			if(tt>k){
				cout<<"0";return 0;
			}
		}
		else{
			tt=0;
		}
	}
	if(s[0]=='?'){
		s[0]='(';
	}
	if(s[s.length()-1]=='?'){
		s[s.length()-1]=')';
	}
	dfs(0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
