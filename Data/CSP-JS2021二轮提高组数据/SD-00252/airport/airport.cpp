#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e6+10;
int n,m1,m2,ans;
struct plane{
	int beg,end;
	bool vis;
}a1[N],a2[N];
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
void init(){
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++){
		int a=read(),b=read();
		a1[i]=(plane){a,b,0};
	}
	for(int i=1;i<=m2;i++){
		int a=read(),b=read();
		a2[i]=(plane){a,b,0};
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	init();
	if(n>=m1+m2)printf("%d\n",m1+m2);
	else printf("%d\n",n);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
