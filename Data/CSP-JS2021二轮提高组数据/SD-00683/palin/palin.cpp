#include<iostream>
#include<cstdio>
using namespace std;
bool c[500005],d[1000005];
int t,n,a[1000005],b[1000005],ha,ta,f;
void dfs(int k){
	if(f==0) return;
	if(k==n+1){
		int hha=ha,tta=ta;
		for(int j=n;j>=1;j--){
			if(a[hha]==b[j]) hha++;
			else if(a[tta]==b[j]) tta--;
				else return;
		}
		hha=ha;tta=ta;
		for(int j=n;j>=1;j--){
			if(a[hha]==b[j]) hha++,d[j]=1;
			else if(a[tta]==b[j]) tta--;
		}
		d[2*n]=1;
		for(int j=1;j<=2*n;j++){
			if(d[j]) printf("L");
			else printf("R");
		}
		f=0;
	}
	if(!c[a[ha]]){
		b[k]=a[ha];c[a[ha]]=1;ha++;d[k]=1;
		dfs(k+1);
		c[a[--ha]]=0;d[k]=0;
	}
	if(!c[a[ta]]){
		b[k]=a[ta];c[a[ta]]=1;ta--;
		dfs(k+1);
		c[a[++ta]]=0;
	}
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int o=1;o<=t;o++){
		scanf("%d",&n);ha=1;ta=2*n;f=1;
		for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
		dfs(1);
		if(f) printf("-1");
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
