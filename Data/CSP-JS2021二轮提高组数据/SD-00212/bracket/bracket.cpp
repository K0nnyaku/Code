#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
char s[600],zi[100000];
int n,k,w,top,m,q[600];
int p(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int l=0,r=0,t=0;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			l=0;
			top++;
			zi[top]='(';
			t=0;
		}else if(s[i]==')'){
			if(zi[top]=='('){
				top--;
				r=0;
				t=1;
			}else{
				top=0;
				return 0;
			}
		}else if(s[i]=='?'){
			top=0;
			return 0;
		}else if(t=0){
			l++;
		}else{
			r++;
		}
		if((l>k||r>k)||(l>0&&r>0)){
			top=0;
			return 0;
		}
	}
	if(top==0){
		return 1;
	}else{
		return 0;
	}
}
void ch(){
	if(p()==1){
		m++;
	}else{
		for(int i=1;i<=w;i++){
			s[q[i]]='*';
			ch();
			s[q[i]]='(';
			ch();
			s[q[i]]=')';
			ch();
		}
	}
}
int main(){
	cin>>n>>k;
	cin>>s;
	if(s[n-1]=='?'){
		s[top]=')';
	}
	if(s[0]=='?'){
		s[0]='(';
	}
	for(int i=0;i<n;i++){
		if(s[i]=='?'){
			w++;
			q[w]=i;
		}
	}
	ch();
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
