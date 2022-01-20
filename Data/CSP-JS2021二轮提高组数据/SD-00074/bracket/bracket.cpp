#include <bits/stdc++.h>
#define LL long long

using namespace std;
const int N = 510;
int n,k,ans=0,l;
char s[N],t[N],s1[N];
//7 3
//(*??*??
void dfs(int x,int l){
//	cout<<t[x]<<' ';
	if(s[x]=='('||s[x]==')'||s[x]=='*') {
		t[x]=s[x];
		dfs(x+1,l);
		return ;
	}
	if(x>=l){
		int f=1;
		int stk[N],top=0;
		int stk1[N],top1=0;
		for(int i=0;i<l;i++){
			if(t[i]=='('){
				stk1[top1++];
				
			}
			if(t[i]==')'&&t[stk1[top1]]=='('){
				top--;
			}
			else if(t[i]==')'&&t[stk1[top1]]!='(')
			
			if(t[i]=='('||t[i]=='*'){
				stk[top++]=i;
			}
			if(t[i]==')'){
				int tmp=0;
				while(top>0){
					if(t[stk[top]]=='('){
						top--;
						if(tmp>k){
							break;
							f=0;
						}
						break;
					}
					if(t[stk[top]]=='*'){
						tmp++;
						--top;
						if(tmp>k){
							break;
							f=0;
						}						
					}

				}
				if(top<0) f=0;
			}
			if(top<0){
				f=0;
				break;
			}
		}
		if(!top1)f=0;
		if(f){
			for(int i=0;i<l;i++) cout<<t[i]<<' ';
			cout<<endl;
			ans++;
		}
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			t[x]=')';
			dfs(x+1,l);
			t[x]='?';
		}
		if(i==2){
			t[x]='(';
			dfs(x+1,l);
			t[x]='?';		
		}
		if(i==3){
			t[x]='*';
			dfs(x+1,l);			
			t[x]='?';
		}
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	int l=strlen(s);
	dfs(0,l);
	cout<<ans;
	return 0;
} 
