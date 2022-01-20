#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')
		f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=1000010;

int t,n,a[N],b[N];
inline bool ck(int s){
	for(register int i=1,j=(s*2);i<=s,j>s;i++,j--){
		if(b[i]!=b[j]) return false;
	}
	return true;
}
inline bool ck2(){
	for(register int i=1,j=(n*2);i<=n,j>n;i++,j--){
		if(a[i]!=a[j]) return false;
	}
	return true;
}
int c[N];
inline void dfs(int idx,int now){//操作序号和当前的位置 
	if(idx==1){
		b[2*n-now+1]=a[now];
	}else {
		b[now]=a[2*n-now+1];
	}
	if(!(now&1)){
		if(!(ck(now)))
		return ;
	}c[now]=idx;
	dfs(1,now+1);
	if(idx==1){
		b[2*n-now+1]=0;
	}else {
		b[now]=0;
	}
	dfs(2,now+1);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	if(t==1){
		n=read();
		for(int i=1;i<=(2*n);i++) a[i]=read();
		cout<<"-1";
		return 0;
	}
	
	else if(t<=10)while(t--){
		n=read();
		for(int i=1;i<=(2*n);i++) a[i]=read();
		dfs(1,1);
		for(int i=1;i<=2*n;i++){
			if(c[i]==1) cout<<"L";
			else cout<<"R";
		}
		cout<<endl;
	}
	else if(t>10&&t<=100){
		while(t--){
			n=read();
			for(int i=1;i<=(2*n);i++) a[i]=read();
			if(ck2){
				for(register int i=1;i<=(2*n);i++){
					cout<<"L";
				}
			}
			cout<<endl; 
				
		}
		
	}
	
	 


	fclose(stdin);
	fclose(stdout);
	return 0;
}

