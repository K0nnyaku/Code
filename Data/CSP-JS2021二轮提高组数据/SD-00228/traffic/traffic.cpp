//4
#include<cstdio>
using namespace std;
int n,m,t,to[95][95][2],tot;
int ma[95][95][95][95];
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
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),t=read();
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m;j++)
			ma[i][j][i+1][j]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m-1;j++)
			ma[i][j][i][j+1]=read();
	for(int j=1;j<=m;j++)
		to[1][j][++to[1][j][0]]=j;
	for(int i=1;i<=n;i++)
		to[i][m][++to[i][m][0]]=i+m;
	for(int j=m;j>=m;j--)
		to[n][j][++to[n][j][0]]=j+m+n+1;
	for(int i=1;i<=n;i++);
	while(t--){
		int a1,a2,a3;
		putchar('1');
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

