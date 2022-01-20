#include <bits/stdc++.h>
using namespace std;
int a[502]={0};
int n=0,k=0,cnt=0,s1=0,s2=0;
bool check(int b){
	if(b==n){
		return true;
	}
	if(a[b]==1){
		s1++;
		s2=0;
	}
	if(a[b]==0){
		s1--;
		s2=0;
	}
	if(s1<0){
		return false;
	}
	if(b==n-1&&s1>0){
		return false;
	}
	if(a[b]==3){
		s2++;
	}
	if(s2>k){
		return false;
	}
	return check(b+1);
}
void dfs(int m){
	if(m==n-1){
		if(check(0)&&a[0]==1&&a[n-1]==2){
			cnt++;
		}
		return;
	}
	if(a[m]==4){
		for(int i=1;i<4;i++){
			a[m]=i;
			dfs(m+1);
			a[m]=4;
		}
	}
}
int main(){
	//freopen("bracket.in","r",stdin);
	//freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		char b;
		cin>>b;
		if(b=='(')
		{
			a[i]=1;
		}
		if(b==')'){
			a[i]=2;
		}
		if(b=='*'){
			a[i]=3;
		}
		if(b=='?'){
			a[i]=4;
		}
	}
	dfs(0);
	cout<<cnt;
	return 0;
}
