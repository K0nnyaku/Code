#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=7;
const int mod=10000079;
int n,k,tot,top,ans;
char s[601];
int a[601],stk[601];
bool vis[10000080];
inline int qread(){
	char c=getchar(),o=' ';int x=0;
	while(c>'9'||c<'0')o=c,c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+c-48,c=getchar();
	if(o=='-')return -x;return x;
}
inline int hash(){
	int dat=0;
	for(int i=1;i<=n;++i){
		dat=(dat*p+a[i])%mod;
	}
	return dat;
}
void dfs(int done){
	int stf=1;
	top=0;
	if(done==tot){
		for(int i=1;i<=n;++i){
			if(a[i]==1)top++;
			else if(a[i]==2)top--;
			if(top<0)return;
		}
		if(top)return;
		for(int i=1;i<=n;++i){
			if(a[i]==1){
				int flag=1;
				for(int j=i+1;j<=i+k;++j){
					if(a[j]!=3){
						flag=0;
						break;
					}
				}
				if(flag)return;
			}
			if(stf&&a[i]==3)return;
			if(stf&&a[i]!=3)stf=0;
			if(a[i]==3){
				while(a[i+1]==3)i++;
			}
			if(a[i]==3&&a[i+1]==1){
				int now=i+2;
				top=1;
				while(1){
					if(a[now]==1)top++;
					if(a[now]==2)top--;
					if(top<=0)break;
					now++;
				}
//				cout<<"--------\n";
//				cout<<now<<' '<<a[now]<<' '<<a[now+1]<<'\n';
				if(a[now]==2&&a[now+1]==3)return;
			}
		}
		if(a[1]==3||a[n]==3)return;
		if(vis[hash()])return;
		vis[hash()]=1;
		
		
//		for(int i=1;i<=n;++i){
//			if(a[i]==1)cout<<'(';
//			else if(a[i]==2)cout<<')';
//			else if(a[i]==3)cout<<'*';
//		}
//		cout<<'\n';
		ans++;
	}
	for(int i=1;i<=n;++i){
		if(a[i]==4){
			a[i]=1;
			dfs(done+1);
			a[i]=2;
			dfs(done+1);
			a[i]=3;
			dfs(done+1);
			a[i]=4;
		}
	}
}
signed main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=qread(),k=qread();
	scanf("%s",&s);
	for(int i=1;i<=n;++i){
		if(s[i-1]=='(')a[i]=1;
		else if(s[i-1]==')')a[i]=2;
		else if(s[i-1]=='*')a[i]=3;
		else if(s[i-1]=='?')a[i]=4,tot++;
	}
	dfs(0);
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*


7 3
(*??*??



10 2
???(*??(?)






*/
