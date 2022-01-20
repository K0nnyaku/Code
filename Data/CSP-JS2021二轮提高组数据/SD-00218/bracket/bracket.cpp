#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define LL long long
#define f(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
int n,k,ans,num,aa;
char a[1009],s[1009];
int dfs(int d,int x,int t1,int t2){
	if(d==n+1&&t2==t1){
		ans++;
		return 0;
	}
	if(s[d]=='('){
		dfs(d+1,x,t1+1,t2);
	}
	if(s[d]==')'){
		dfs(d+1,x,t1,t2+1);
	}
	if(s[d]=='*'){
		dfs(d+1,x+1,t1,t2);
	}if(x>k)return 0;
	if(t2>t1)return 0;
	if(t1-t2>n-d)return 0;
	if(s[d]=='?'){
		num++;
		s[d]='(';dfs(d+1,x,t1+1,t2);
		s[d]=')';dfs(d+1,x,t1,t2+1);
		s[d]='*';if(x+1>k)return 0;
		dfs(d+1,x+1,t1,t2);
		num--;
	}return 0;
}
int main(){
//  freopen("bracket.in","r",stdin);
//  freopen("bracket.out","w",stdout);
	cin>>n>>k;
	scanf("%s",s+1);
	s[1]='(';
	s[n]=')';
	f(i,1,n)if(s[i]=='?')aa++;
	dfs(1,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

