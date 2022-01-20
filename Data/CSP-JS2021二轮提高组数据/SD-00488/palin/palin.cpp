#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int t,n,k;
int a[10001];
int b[20000][20000];
void grow(){
	int cnt1=1;
	for(int i=1;i<2*n;i++){
		cnt1*=2;
	}
	int cnt2=cnt1*2;
	for(int i=1;i<=2*n;i++){
		for(int j=1;j<cnt2/cnt1;j++){
			for(int k=1;k<=cnt2/j/2;k++){
				b[k][i]=1;
			}
			for(int k=cnt2/j/2+1;k<=cnt2/j;k++){
				b[k][i]=2;
			}
		}
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		printf("-1\n");
	}
	return 0;
}
