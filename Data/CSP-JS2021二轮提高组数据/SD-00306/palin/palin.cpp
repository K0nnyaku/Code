#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int T,n,x,y,f;
int a[N], b[N], e[N];
void print(){
	for(int i=1;i<=2*n;i++)
		if(b[i])printf("L");
		else printf("R");
	printf("\n");
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	if(T==1)printf("-1");
	else while(T--){
		f=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			if(a[i]!=a[2*n-i+1])
				f=1;
		if(f)printf("-1\n");
		else{
			for(int i=1;i<=2*n;i++)
				printf("L");
			printf("\n");
		}
	}
	

	return 0;
}
