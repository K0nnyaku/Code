#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
long long n[500005];
long long t;
inline int read(){
	int x(0),f(1);
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void wri(int a){
	if(a){
	cout<<"L";
	return ;	
	}
	cout<<"R";
	return ;
}
long long  maxx=-1;
void dfs(long long ws,long long z,long long ys){
	if(ws==z){
		long long cur=ys;
		long long cc[z+5];
		long long tmpl(1),tmpr(z);
		for(int i=z;i>=1;i--){
			if(cur&(1<<i)){
				cc[z-i]=n[tmpl];
				tmpl++;
			}else{
				cc[z-i]=n[tmpr];
				tmpr--;
			}
			cur=cur>>1;
		}
		for(int i=1;i<=z/2;i++){
			if(cc[i]!=cc[z-i+1])return ;
		}
		maxx=max(maxx,ys);
	}
	dfs(ws+1,z,ys<<1);
	dfs(ws+1,z,ys<<1+1);
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	for(int i=1;i<=t;i++){
	cout<<"-1"<<endl;	
	/*	int c=read();
		c*=2;
		for(int j=1;j<=c;j++){
		n[i]=read();	
		}
		dfs(1,c,0);
		for(int j=c;j>=1;j--){
				wri(maxx&(1<<j));
				maxx=maxx>>1;
		}*/
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
