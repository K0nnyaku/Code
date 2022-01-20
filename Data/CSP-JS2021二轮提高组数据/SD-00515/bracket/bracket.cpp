#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
stack<char> s;
string ch;
char ch1[3]= {'(',')','*'};
int n,k,m,m1;
int ans;
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>ch[i];

	}
	if(ch[1]==')'||ch[n]=='(') {
		cout<<0;
	} else cout<<3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
stack<char> s;
string ch;
char ch1[3]= {'(',')','*'};
int n,k,m,m1;
int ans;
bool pd() {
	for(int i=1; i<=n; i++) {
		if(ch[i]=='(') {
			s.push('(') ;
		} else m1++;
		if(ch[i]==')') {
			s.pop() ;
		} else m1++;
	}
	if(s.empty()&&m1<=k) {
		return true;
	} else {
		return false;
	}
}
int dfs(int m) {
	if(m==0&&pd()){
	 ans++;
	 return 0; }
	for(int i=1; i<=n; i++) 
	for(int j=1;i<=n;){
		if(ch[i]=='?')
		ch[i]=ch1[j];
		m--;	
	}
}
int main() {
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>ch[i];
		if(ch[i]=='?')
			m++;
	}
	if(ch[1]=='?') {
		ch[1]=='(';
		m--;
	}
	if(ch[n]=='?') {
		ch[n]=='(';
		m--;
	}
	if(ch[1]==')'||ch[n]=='('){
	cout<<0;
	return 0;}
	dfs(m);
	cout<<ans;
	return 0;
}
*/

