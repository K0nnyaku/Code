#include<bits/stdc++.h>
using namespace std;
inline int rread(){
	int x=0;
	char c=getchar(),o=' ';
	while(c<'0'||c>'9')o=c,c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=getchar();
	if(o=='-')x=~x+1;
	return x; 
}
inline int mmin(int x,int y){
	return x<y?x:y;
}
int a[1000005];
int n;
int tt;
bool f=0;
int vis[1000005];
int b[1000005];
int lst[1000005];
void dfs(int dep,int l,int r){
//	cout<<dep<<' '<<l<<' '<<r<<endl;
	if(dep>n&&b[dep]!=b[2*n-dep+1])return;
	if(dep==2*n-1){
		int fl=0;
		for(int i=2;i<=n;i++){
			if(b[i]!=b[2*n-i+1]){
				fl=1;break;
			}
		}
//		for(int i=1;i<=2*n-1;i++){
//			cout<<b[i]<<' ';
//		}
//		cout<<a[l+1]<<' '<<'\n';
//		for(int i=1;i<=n;i++){
//			cout<<lst[i]<<' ';
//		}
//		cout<<endl;
		if((!fl)&&(b[1]==a[l+1])){
			for(int i=1;i<=2*n-1;i++){
				if(vis[i]==1)cout<<"L";
				else cout<<"R";
			}
			cout<<"L\n";
			f=1;
		}
		return;
	}
	bool x;
	bool y;
	b[dep+1]=a[l+1];
	vis[dep+1]=1;
	x=0;
	y=0;
	if(!lst[b[dep+1]]){
		lst[b[dep+1]]=dep+1,x=1;
//		cout<<lst[b[dep+1]]<<' '<<b[dep+1]<<endl;
	}
	else{
		if(lst[b[dep+1]]!=2*n-(dep+1)+1){
			y=1;
		}
	} 
	/**/if(!y)dfs(dep+1,l+1,r);
	if(f)return;
	if(x)lst[b[dep+1]]=0;
	b[dep+1]=0;
	vis[dep+1]=0;
	b[dep+1]=a[r-1];
	vis[dep+1]=-1;
	x=0;
	y=0;
	if(!lst[b[dep+1]])lst[b[dep+1]]=dep+1,x=1;
	else{
		if(lst[b[dep+1]]!=2*n-(dep+1)+1){
			y=1;
		}
	} 
	/**/if(!y)dfs(dep+1,l,r-1);
	if(f)return;
	if(x)lst[b[dep+1]]=0;
	b[dep+1]=0;
	vis[dep+1]=0;
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout); 
	tt=rread();
	while(tt--){
		n=rread();
		for(int i=1;i<=2*n;i++){
			a[i]=rread();
		}
		f=0;
		memset(lst,0,(sizeof(int))*(mmin((sizeof lst)/(sizeof(int)),n+10)));
		memset(vis,0,(sizeof(int))*(mmin((sizeof vis)/(sizeof(int)),n+10)));
		dfs(0,0,2*n+1);
		if(!f)cout<<"-1\n";
	}
	return 0;
}
