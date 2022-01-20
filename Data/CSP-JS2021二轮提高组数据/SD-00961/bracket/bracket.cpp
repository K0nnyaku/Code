#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <stack> 
using namespace std;

const int N=505,M=1e9+7;
int n,k;
int a[N], ct=0, lft[N], rght[N];
string s;
long long cnt; 

inline bool isValid(){
	int lfft=0,rghht=0,strr=0;
	if(s[1]=='*'||s[n]=='*'|| s[1]==')' || s[n]=='(') return false;
	static int lftc[N],rhtc[N];
	for(register int i=1;i<=n;i++){
		switch(s[i]){
			case '(': lfft++;lftc[lfft]=i;strr=0;break;
			case ')': rghht++;rhtc[rghht]=i;strr=0;break;
			case '*': strr++;break;
		}
		if(strr>k) return false;
		if(lfft<rghht) return false; 
	}
	if(lfft!=rghht) return false;
	for(register int i=1;i<=lfft;i++){
		int ind=upper_bound(rhtc+1,rhtc+rghht+1,lftc[i])-rhtc;
//		cerr<<<<" "<<ind<<endl;
		if(rhtc[ind]==lftc[i]+1) continue;
		bool flag = 0;
		for(register int j=lftc[i]+1;i<=rhtc[ind]-1;i++){
			if(s[j]=='('||s[j]==')') {
				flag=1;
				break;
			}
		}
		if(s[lftc[i]+1]=='*'&&s[rhtc[ind]-1]=='*'&&flag) return false;
	}
	
	return true;
}

void search(char ch, int dep){
	if(dep==ct){
		if(isValid()) {
//			cerr<<ch<<" "<<dep<<" "<<s<<endl;
			cnt++;
		}
		return;
	}
//	if(lft[a[dep]]<=rght[a[dep]]) return;
//	if(lft[a[dep]]-rght[a[dep]]>(n-a[dep+1]+1)) return;
	for(auto ch : {'(',')','*'}) {
		if(a[1]==1&&ch=='*') continue;
		if(ch=='(') {
			for(register int i=a[dep+1];i<=n;i++){
				lft[a[dep+1]]++;
			}
		}
		else if(ch==')') {
			for(register int i=a[dep+1];i<=n;i++){
				rght[a[dep+1]]++;
			}
		}
		else if(ch=='*') {
			int len=1;
			for(register int i=a[dep+1]-1;i>=1;i--){
				if(s[i]!='*') break;
				len++;
			}
			if(len>k) continue;
		}
		s[a[dep+1]]=ch;
		search(ch,dep+1);
		s[a[dep+1]]='?';
		if(ch=='(') {
			for(register int i=a[dep+1];i<=n;i++){
				lft[a[dep+1]]--;
			}
		}
		else if(ch==')') {
			for(register int i=a[i];i<=n;i++){
				rght[a[dep+1]]--;
			}
		}
	}
	
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("bracket.in","r",stdin);
//	freopen("bracket.out","w",stdout);
	
	cin>>n>>k>>s;
	s='-'+s;
	
	for(register int i=1;i<=n;i++){
		if(s[i]=='?') a[++ct]=i;
		lft[i]=lft[i-1]+(s[i]=='(');
		rght[i]=rght[i-1]+(s[i]==')');
	}
	for(auto ch : {'(',')','*'}) {
		if(ch=='(') {
			for(register int i=a[1];i<=n;i++){
				lft[a[i]]++;
			}
		}
		else if(ch==')') {
			for(register int i=a[1];i<=n;i++){
				rght[a[i]]++;
			}
		}
		else if(ch=='*') {
			int len=1;
			for(register int i=a[1]-1;i>=1;i--){
				if(s[i]!='*') break;
				len++;
			}
			if(len>k) continue;
		}
		s[a[1]]=ch;
		search(ch,1);
		s[a[1]]='?';
		if(ch=='(') {
			for(register int i=a[1];i<=n;i++){
				lft[a[i]]--;
			}
		}
		else if(ch==')') {
			for(register int i=a[1];i<=n;i++){
				rght[a[i]]--;
			}
		}
	}
	
	cout<<cnt%M<<endl;
	
	return 0;
}
