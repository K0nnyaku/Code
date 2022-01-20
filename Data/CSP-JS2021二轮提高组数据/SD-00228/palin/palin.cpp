//3
#include<cstdio>
using namespace std;
int t,n,a[1000005],k[1000005],s[1000005],key;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
void print(int x){
	if(x<0)putchar('-'),x=~x+1;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
void dfs(int x,int l,int r){
	if(x>2*n){
		key=1;
		for(int i=1;i<=2*n;i++){
			if(k[i]==1)putchar('L');
			if(k[i]==2)putchar('R');
		}
		putchar('\n');
		return;
	}
	if((x>n&&a[l]==s[2*n-x+1])||x<=n){
		k[x]=1;
		s[x]=a[l];
		dfs(x+1,l+1,r);
		k[x]=0;
		s[x]=0;
		if(key)return;
	}
	if((x>n&&a[r]==s[2*n-x+1])||x<=n){
		s[x]=a[r];
		k[x]=2;
		dfs(x+1,l,r-1);
		k[x]=0;
		s[x]=0;
	} 
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=2*n;i++)
			a[i]=read();
		dfs(1,1,2*n);
		if(key)key=0;
		else putchar('-'),putchar('1'),putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
