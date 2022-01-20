#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<cstdio>
#include<windows.h>
#include<algorithm>
#include<vector>
#include<stack> 
using namespace std;
const int N=550;
const long long mod=1e9+7;
string s;
int n,k;
stack <int> st;
int w[N];
int tot=0;
int lpd=0;
bool pd(){
	while(st.size()){
		st.pop();
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='(') st.push(1);
		if(s[i]==')'){
			if(st.size()==0){
//				cout<<1;
				return 0;
			}
			else{
				st.pop();
			}
		}
	}
	if(st.size()){
//		cout<<2;
		return 0;
	}
	int time=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='*') {
			time++;
			if(time>k){
//				cout<<3;
				return 0;
			}
		}
		else{
			time=0;
		}
	}
	return 1;
}
long long dg(int a){
	long long time=0;
	if(a!=tot){
		s[w[a]]='*';
		time+=dg(a+1);
		s[w[a]]='(';
		time+=dg(a+1);
		s[w[a]]=')';
		time+=dg(a+1);
		return time%mod;
	}
	else{
		s[w[a]]='*';
//		cout<<s<<endl;
		if(pd()){
//			cout<<s<<" "<<st.size()<<endl;
			return 1;
		}
		s[w[a]]=')';
		if(pd()){
//			cout<<s<<" "<<st.size()<<endl;
			return 1;
		}
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='?'){
			tot++;
			w[tot]=i;
		}
	}
	cout<<dg(1)%mod;
	return 0;
}
/*
 括弧匹配 
 对于每一个?，都有：1.（ 2.） 3.*
 *的数量不能超过k个 
7 3
(*??*??
???????????????????????????????????????????????????????????????????????????????????????????????????????
??????????????????????????????????????????????????????????????????????????????????????????????????????????
??????????????????????????????????????????????????????????????????????????????????????????????????????????
??????????????????????????????????????????????????????????????????????????????????????????????????????????
???????????????????????????????????????????????????????????????????????????????

*/
