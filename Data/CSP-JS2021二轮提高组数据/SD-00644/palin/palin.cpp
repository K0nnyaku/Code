#include<bits/stdc++.h>
using namespace std;
const int maxn=50;
int a[maxn],b[maxn],n,s[maxn];
bool flag;
inline int read(){
	int x=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*w;
}
void dfs(int l,int r,int pos){
	if(pos>n+1&&b[pos-1]!=b[2*n+2-pos])return;
	if(pos>2*n){flag=1;return;}
	b[pos]=a[l];s[pos]=-1;dfs(l+1,r,pos+1);if(flag)return;
	b[pos]=a[r];s[pos]=1;dfs(l,r-1,pos+1);if(flag)return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=read();
	while(T--){
		flag=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(s,0,sizeof(s));
		n=read();
		if(T==1&&n>100){printf("-1\n");return 0;}
		for(int i=1;i<=2*n;i++)a[i]=read();
		dfs(1,2*n,1);
		if(!flag)printf("-1\n");
		else{
			for(int i=1;i<=2*n;i++)
			printf("%c",s[i]<0?'L':'R');
			printf("\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

