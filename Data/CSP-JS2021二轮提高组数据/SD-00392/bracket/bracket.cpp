#include<iostream>
#include<cstdio>
using namespace std;
int n,k,l,cnt;
char s[501];
inline void dfs(int x){
	if(s[2]=='*'&&s[3]==')'&&s[5]=='('&&s[6]==')'){
		int w;
		w=1;
	}
	if(x>l){
		int sum1=0,sum2=0,p=0,num;
		for(int i=0;i<=l;i++){
			sum1=0,sum2=0,num;
			if(s[i]=='('&&!p){
				for(int j=i;j<=l;j++){
					if(s[j]=='(')sum1++;
					if(s[j]==')')sum2++;
					if(sum2>sum1)return;
				}
				p=1;
			}
			if(sum2!=sum1)return;
			if(s[i]=='*'){
				if(i==0||i==l)return;
				num=1;
				for(int j=i-1;j>=0;j--){
					if(s[j]=='('||s[j]==')')break;
					if(s[j]=='*')num++;
				}
				for(int j=i+1;j<=l;j++){
					if(s[j]==')'||s[j]=='(')break;
					if(s[j]=='*')num++;
				}
				if(num>k)return;
			}
		}
		sum1=0,sum2=0,p=0;
		for(int i=l;i>=0;i--){
			if(s[i]==')'&&!p){
				for(int j=i;j>=0;j--){
					if(s[j]=='(')sum1++;
					if(s[j]==')')sum2++;
					if(sum1>sum2)return;
				}
				p=1;
			}
		}
		if(sum2!=sum1)return;
		cnt++;
		return;
	}
	while(s[x]!='?'&&x<=l)x++;
	if(s[x]=='?'){
		s[x]='(';
		dfs(x+1);
		s[x]=')';
		dfs(x+1);
		s[x]='*';
		dfs(x+1);
		s[x]='?';
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<=n-1;i++)cin>>s[i];
	l=n-1;
	dfs(0);
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
}
