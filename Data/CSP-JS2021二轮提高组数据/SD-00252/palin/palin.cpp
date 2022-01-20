#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e6+100;
int T,n,a[N],c[N],d[N];
bool f,b[N>>1];
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=2*n;i++){
			a[i]=read();
		}
		for(int i=1;i<=n;i++){
			if(a[i]==a[2*n-i+1]){
				f=true;
			}
			else{
				f=false;
				break;
			}
		}
		if(f){
			for(int i=1;i<=n;i++){
				printf("L");
			}
			printf("\n");
		}
		else printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
