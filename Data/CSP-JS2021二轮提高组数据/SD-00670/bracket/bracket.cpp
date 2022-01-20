#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int MOD=1e9+7;
const int N=510;
int n,k,ans;
char s[N];
stack<char>stk;
void reads(){
	char ch=getchar();
	while(ch=='\n'||ch==' ') ch=getchar();
	s[1]=ch;
	for(int i=2;i<=n;i++) s[i]=getchar();
}
bool judge(){
	while(!stk.empty()) stk.pop();
//	for(int i=1;i<=n;i++) printf("%c",s[i]);
//	printf("\n");
	bool canputs=true,out=false;
	for(int i=1;i<=n;i++){
		if(s[i]=='('){
			stk.push('(');
//			printf("%d in\n",i);
			if(s[i-1]!='*') canputs=true;
		}else if(s[i]==')'){
			if(stk.empty()){
//				printf("%d end\n",i);
				return false;
			}else{
//				printf("%d out\n",i);
				stk.pop();
				if(s[i-1]=='*') out=true;
				if(stk.empty()) canputs=true;
			}
			if(s[i-1]==')') canputs=true;
		}else{
			if(s[i-1]=='(') canputs=false;
			if(s[i-1]==')'&& !canputs){
				if(!out) return false;
				out=false;
			}
		}
	}
	if(stk.empty()) return true;
	else return false;
}
void dfs(int point,int stars){
	if(point==n){
		if(s[point]=='?') s[point]=')';
		if(judge()){
//			printf("^ is true\n");
			ans=(ans+1)%MOD;
		}
	}else{
		if(s[point]!='?'){
			switch(s[point]){
				case '(':{
					dfs(point+1,0);
					break;
				}
				case '*':{
					dfs(point+1,stars+1);
					break;
				}
			}
		}else{
			s[point]='(';
			dfs(point+1,0);
			s[point]='?';
			if((stars+1)<k){
				s[point]='*';
				dfs(point+1,stars+1);
				s[point]='?';
			}
			s[point]=')';
			dfs(point+1,0);
			s[point]='?';
		}
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	reads();
	s[1]='(';
	dfs(2,0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
7 3
(*??*??
*/
