#include<bits/stdc++.h>
#define il inline
#define POS(i,l,r) for(int i=l;i<=r;i++)
#define REV(i,l,r) for(int i=r;i>=l;i--)
using namespace std;
int read(){
	int ans=0,fl=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')fl=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=(ans<<1)+(ans<<3)+(ch^48);
		ch=getchar();
	}
	return ans*fl;
}
int n,a[1000010];
int t;
int b[1000010];
bool ans=0;
void dfs(int now,string s){
	if(ans){
		return;
	}
	if(now==2*n){
		for(int l=1,r=2*n,i=1;i<=2*n;i++){
			if(s[i-1]=='L'){
				b[i]=a[l];
				l++;
			}else{
				b[i]=a[r];
				r--;
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]!=b[2*n-i+1]){
				return;
			}
		}
		cout<<s<<endl;
		ans=1;
		return;
	}
	for(int i=1;i<=2;i++){
		dfs(now+1,s+(i==1?'L':'R'));
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=2*n;i++){
			a[i]=read();
		}
		dfs(0,"");
		if(!ans)puts("-1");
		ans=0;
	}
	return 0;
}


