#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=50;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int t,n,a[N],l[N],hd,tl;
bool b[N];
bool dfs(int p){
	if(p==n){
		for(int i=1;i<=n;i++){
			if(l[i]!=l[n-i+1])return false;
		}
		return true;
	}
	b[p+1]=0,l[p+1]=a[++hd];
	if(dfs(p+1))return true;
	hd--;
	b[p+1]=1,l[p+1]=a[--tl];
	if(dfs(p+1))return true;
	tl++;
	return false;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--){
		if(n>20){
			cout<<-1<<"\n";
			continue;
		}
		n=read()*2;
		hd=0,tl=n+1;
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		if(dfs(0)){
			for(int i=1;i<=n;i++){
				if(!b[i])cout<<"L";
				else cout<<"R";
			}
		}
		else cout<<-1;
		cout<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
