#include<iostream>
#include<cstdio>
using namespace std;
#define N 500010
inline long long read(){
	int x=0;bool flag=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') flag=0;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	if(flag) return x;
	return ~(x-1);
}
int T;
int n;
int a[N];
int b[N];
int road[N];
char ans[N];
int f=1;
bool check(){
	for(int i=1,j=n*2;i<=n;i++,j--){
		if(b[i]!=b[j]) return 0;
	}
	return 1;
}
void dfs(int dep,int t,int l,int r){
	if(dep==2*n){
		if(check()){
			f=0;
			for(int i=1;i<=2*n;i++) ans[i]=road[i];
		}
		return;
	}
	if(t==1) b[dep+1]=a[l],l++;
	if(t==2) b[dep+1]=a[r],r--;
	//cout<<"---"<<endl;
	road[dep+1]=t;
	dfs(dep+1,2,l,r);dfs(dep+1,1,l,r);
} 
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		f=1;
		for(int i=1;i<=2*n;i++) a[i]=read();
		dfs(0,2,1,2*n);dfs(0,1,1,2*n);
		if(f) cout<<"-1"<<endl;
		else{
			for(int i=1;i<=2*n;i++){
				if(ans[i]==1) cout<<"L";
				else cout<<"R";
			}
			cout<<endl;
		}
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
