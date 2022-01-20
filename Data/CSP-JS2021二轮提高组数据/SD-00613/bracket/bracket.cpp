#include<bits/stdc++.h>
using namespace std;
int n,k,Stack[2001],top;
char a[1001];
int b[2002],cnt,ans,sum[20001],q[1001],tail;
bool check(){
	top=0;int flag=0;
	for(int i=1;i<=n;i++){
//		cout<<a[i];
		if(a[i]=='('){
			Stack[++top]=i;
		}
		if(a[i]==')'){
			if(top==0) return false; 
			if(a[Stack[top]-1]=='*'&&a[i+1]=='*'){
				flag=0;
				for(int j=Stack[top]-1;j>=1;j--){
//					cout<<a[j]<<" "<<j;
					if(a[j]=='(') {
						flag++;
						break;
					}
					if(a[j]==')'){
						break;
					}
				}
				for(int j=Stack[top]+1;j<=n;j++){
//					cout<<a[j]<<" ";
					if(a[j]=='(') break;
					if(a[j]==')') flag++;
				}
//				cout<<flag;
				if(flag>=2) return false;
			}
			top--;
		}
	}
	if(top!=0) return false;
	else return true;
}
inline void dfs(int dep){
	if(dep==tail+1){
		if(check()){
			ans++;
		}
		return ;
	}
	cnt=0;
	for(int i=q[dep]-1;a[i]=='*';i--){
		cnt++;
	}
	for(int i=q[dep]+1;a[i]=='*';i++){
		cnt++;
	}
	if(cnt+1<=k){
		a[q[dep]]='*';
		dfs(dep+1);
		a[q[dep]]='?';
	}
	a[q[dep]]='(';
	dfs(dep+1);
	a[q[dep]]=')';
	dfs(dep+1);
	a[q[dep]]='?';
} 
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		a[i]=getchar();
		if(a[i]!='('&&a[i]!=')'&&a[i]!='*'&&a[i]!='?'){
			i--;
			continue;
		}
		if(a[i]=='?'){
			b[++cnt]=i;
		}
	}
	if(b[1]==1) a[1]='(';
	else q[++tail]=b[1];
	for(int i=2;i<cnt;i++){
		q[++tail]=b[i];
	} 
	if(b[cnt]==n) a[n]=')'; 
	else q[++tail]=b[cnt];
	cnt=0;
	for(int i=n;i>=1;i--){
		if(a[i]=='*'){
			cnt++;
		}else{
			if(cnt>k){
				cout<<0;
				return 0;
			}
			cnt=0;
		}
	}
//	for(int i=1;i<=tail;i++){
//		cout<<q[i];
//	}
	dfs(1);
	cout<<ans<<endl;
}
