#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int T,n;
bool book=0;
char c[N];
int a[N],z[N];
int redd(){
	int x=0,f=1;char c;c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
bool qwq(){
	for(int i=1,j=2*n;i<=n&&n<j;i++,j--)
		if(z[i]!=z[j])
			return 0;
	return 1;
}
void dfs(int x,int l,int r){
	if(x>2*n){
		if(!book&&qwq()){
			for(int i=1;i<=2*n;i++)
				printf("%c",c[i]);
			book=1;
		}
		return;
	}
	z[x]=a[l];
	c[x]='L';
	dfs(x+1,l+1,r);
	z[x]=a[r];
	c[x]='R';
	dfs(x+1,l,r-1);
	return;
} 
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=redd();
	while(T--){
		book=0;
		n=redd();
		for(int i=1;i<=2*n;i++)
			a[i]=redd();
		dfs(1,1,2*n);
		if(!book)
			printf("-1");
		printf("\n");
	}
	return 0;
}
