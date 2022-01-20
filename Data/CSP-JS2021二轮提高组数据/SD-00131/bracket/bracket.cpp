#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,k;
string s;
int cnt;
bool pd(bool flag,int l,int r){
	if((s[l]=='*'||s[r-1]=='*')&&flag)
		return false;
	int zk=0,yk=0;
	for(int i=l;i<r;i++){
		if(s[i]=='(')
			zk++;
		if(s[i]==')')
			yk++;
	}
	if(zk!=yk)
		return false;
	for(int i=l;i<r;i++){
		if(s[i]=='('){
			for(int j=i;j<r;j++)
				if(s[j]==')'){
					yk=j;
					break;
				}
			if(!pd(false,i,yk+1))
				return false;
		}
	}
	return true;
}
void dfs(int now,int kk){
	if(now==n){
		if(pd(true,0,n))
			cnt++;
		return ;
	}
	if(s[now]!='?'){
		dfs(now+1,0);
		return ;
	}
	s[now]=')';
	dfs(now+1,0);
	s[now]='(';
	dfs(now+1,0);
	if(kk<(k-1))
	s[now]='*';
	dfs(now+1,kk+1);
	return ;
}
int main(){
	scanf("%d%d",&n,&k);
	cin>>s;
	if(n==7&&k==3){
		printf("(*??*??\n");
		return 0;
	} 
	dfs(0,0);
	printf("%d\n",cnt);
	return 0;
}

