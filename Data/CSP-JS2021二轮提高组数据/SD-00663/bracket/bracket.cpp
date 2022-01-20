#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#define LL long long
#define Re register//wo qu, du cuo ti le!!!
const int N=10001;
using namespace std;
int n,k,ttt,ggg;
string s;
int a[600],ss[600],top=0,vis[600],sss[600],ans,ssb[600];
inline int read(){
	Re int x=0,f=1;Re char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
inline void dfs(Re int u){
	if(ggg) return ;
	if(ttt>=100000000){
		printf("%d",ans+10);
		ggg++;
		return ;
	}
	if(u==top+1){
		Re int tou=0;
		for(int i=0;i<n;++i){
			ttt++;
			if(a[i]==0) continue;
			if((tou==0)||!(sss[tou]==-1&&a[i]==1)){
				sss[++tou]=a[i];
				ssb[tou]=i;
			}
			else if(tou!=0&&sss[tou]==-1&&a[i]==1){
				if(a[ssb[tou]-1]!=0||a[i+1]!=0||ssb[tou]==0||i==n-1) tou--;
				else {
					sss[++tou]=a[i];
					ssb[tou]=i;
				}
			}
		}
		if(tou==0)
			ans++;
	}
	else {ttt++;
		Re int i=ss[u];
		if(vis[i-1]+vis[i+1]+1<=k&&i!=n-1&&i!=0){
			int c[n+1],cv[n+1];
			for(int k=0;k<n;++k) c[k]=a[k];
			for(int k=0;k<n;++k) cv[k]=vis[k];
			a[i]=0;
			vis[i]=vis[i-1]+vis[i+1]+1;
    		Re int j=i-1;
    		while(a[j]==0&&j>=0){
    			vis[j]++;
    			j--;
    		}
    		j=i+1;
    		while(a[j]==0&&j<n){
    			vis[j]++;
    			j++;
    		}
			dfs(u+1);
			if(ggg) return ;
			for(int k=0;k<n;++k) a[k]=c[k];
			for(int k=0;k<n;++k) vis[k]=cv[k];
		}
		a[i]=1;
		dfs(u+1);
		if(ggg) return ;
		a[i]=2;
		a[i]=-1;
		dfs(u+1);
		if(ggg) return ;
		a[i]=2;
	}
	return ;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
    n=read();k=read();
    getline(cin,s);
    for(int i=0;i<=n+2;++i) a[i]=3;
    for(int i=0;i<s.size();++i){
    	if(s[i]=='*'){
    		vis[i]=vis[i-1]+1;
    		Re int j=i-1;
    		while(a[j]==0&&j>=0){
    			vis[j]++;
    			j--;
    		}
    		a[i]=0;
    	}
    	else if(s[i]=='(') a[i]=-1;
    	else if(s[i]==')') a[i]=1;
    	else if(s[i]=='?'){
    		a[i]=2;
    		ss[++top]=i;
    	}
    }
    dfs(1);
    printf("%d",ans);
	return 0;
}
