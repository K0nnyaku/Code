#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<string>
using namespace std;
typedef long long ll;
#define Mod 1000000007
int n,m,q;
string s;
int DFS(int x,int l,int st){
	if(l<0||st>m)return 0;
	if(x>n&&l==0&&st<=m)return 1;
	if(s[x]=='(')return DFS(x+1,l+1,0)%Mod;
	if(s[x]==')')return DFS(x+1,l-1,0)%Mod;
	if(s[x]=='*')return DFS(x+1,l,st+1);
	if(s[x]=='?')return ((DFS(x+1,l+1,0)+DFS(x+1,l-1,0))%Mod+DFS(x+1,l,st+1))%Mod;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin >> s;
	s=' '+s;
	if(s[n]!=')'&&s[n]!='?'||s[1]!='('&&s[1]!='?'){
		printf("0");
		return 0;
	}
	s[1]='(';
	s[n]=')';
	printf("%d",(DFS(1,0,0)+Mod)%Mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
