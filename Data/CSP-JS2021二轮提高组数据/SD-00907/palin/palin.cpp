#include <iostream>
#include <cstdio>
using namespace std;
int T,n,a[1000005],k[1000005],s[1000005],ans[1000005],f;
void read(int &x){
	int f=1;char c=getchar();x=0;
	while(c<'0'||c>'9'){
		if (c=='-')f=-f;
		c=getchar(); 
	}
	while (c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}x*=f;
}
void judge(){
	int l=0,r=2*n+1;
	for (int i=1;i<=2*n;i++)if (s[i]==1)k[i]=a[++l];else k[i]=a[--r];
	for (int i=1;i<=n;i++)if (k[i]!=k[2*n-i+1])return;
	if (f!=0){
		for (int i=1;i<=2*n;i++)if (s[i]>ans[i])return;
	}swap(ans,s);f=1;
}
void dfs(int p){
	if (p>2*n){
		judge();
		return;
	}s[p]=1;
	dfs(p+1);
	s[p]=2;
	dfs(p+1);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(T);
	while (T--){
		read(n);f=0;
		for (int i=1;i<=2*n;i++)read(a[i]);
		dfs(1);
		if (f==0)printf("-1\n");else
		for (int i=1;i<=2*n;i++)if (ans[i]==1)printf("L");else printf("R");printf("\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
