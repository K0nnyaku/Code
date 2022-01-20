#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
bool bo[500005];
int T,n,a[500005],ans[500005];
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	if(T>1) {
		while(T--) {
			scanf("%d",&n);
			for(int i=1;i<=n<<1;i++) {
				scanf("%d",&a[i]);
			}
			for(int i=1;i<n<<1;i++) {
				if(bo[a[i]]) printf("R"),bo[a[i]]=false;
				else printf("L"),bo[a[i]]=true;	
			}
			bo[a[n*2]]=false;
			printf("L\n");
		}
		return 0;
	}
	
	while(T--) {
		/*scanf("%d",&n);
		for(int i=1;i<=n<<1;i++) {
			scanf("%d",&a[i]);
		}
		int N=n<<1;
		for(int t=0;t<2<<N;t++) {
			int Head=0,Tail=N|1,tot=0;
			int i=t;
			for(int j=1;j<=N;i++) {
				if(i&1) ans[j]=a[++Head];
				else ans[j]=a[--Tail];
				i>>=1;
			}
			for(int i=1;i<=n;i++) {
				if(ans[i]==ans[N+1-i]) ++tot;
			}
			if(tot==n){
				for(int j=1;j<=n<<1;i++) {
				if(t&1) printf("L");
				else printf("R");
				t>>=1;
				}
				break;
			}	
		}
	continue;*/
	cout<<"-1\n";
   }
   return 0;
}
