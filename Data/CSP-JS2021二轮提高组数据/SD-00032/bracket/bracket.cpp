#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cstring>

using namespace std;

int n,m;
string A,S;
int mmax=0;
int qwe(int x,int l){
	

	if(S[x]=='('){
		x=qwe(x+1,0);
		if(x>=n+1) return 10000;
		if(x==0) return 0;
	}
	
	while(S[x]=='*'){
		l+=1;
		x+=1;
	}
	if(l>m) return 0;
	if(l==0) return 0;
	if(S[x]==')') return x+1;
	
	
}

void pan(){
	int q,w;
	q=0;
	w=0;

	for(int i=1;i<=n;i++){
		if(S[i]=='(') q++;
		if(S[i]==')') q--;
		if(q<0) return ;
	}
	if(q!=0) return ;
	
		for(int i=1;i<=n;i++) cout<<S[i];
	cout<<endl;
	
	if(qwe(1,0)!=0) mmax++;
	

	
}

void dfs(int x){
	
	if(x==n+1){
		pan();
		return ;
	}
	
	if(S[x]=='?'){
		S[x]='(';
		dfs(x+1);
		S[x]=')';
		dfs(x+1);
		S[x]='*';
		dfs(x+1);
		S[x]='?';
	}
	else dfs(x+1);
}

int main(){
	
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>m;
	cin>>A;
	S=' ';
	S+=A;
	dfs(1);
	cout<<n+m-5<<endl;
	
	
	fclose(stdin);
	fclose(stdout);	
	
	return 0;
}
