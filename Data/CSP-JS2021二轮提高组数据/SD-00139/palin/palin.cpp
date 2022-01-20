#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,b[500001],ans[1000001];
struct palin{
	int z,side;
}a[1000001];
int AK(int l){
	int r,top=1;r=l+n-1;
	for(int i=l;i<=r;i++){
		if(a[top].z==a[i].z)
			top++,a[i].side=1;
	}if(top!=l)return 0;
	top+=n;
	for(int i=r;i>=l;i--){
		if(a[top].z==a[i].z)
			top++,a[i].side=2;
	}if(top!=2*n+1)return 0;
	return 1;
} 
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int w=1;w<=t;w++){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			scanf("%d",&a[i].z);
		for(int i=n+1;i>=1;i--){
			int k=0;
			memset(b,0,sizeof(b));
			for(int j=i;j<=i+n-1;j++){
				b[a[j].z]++;
				if(b[a[j].z]>1)
					{k=1;break;}
			}
			if(!k){
				if(AK(i)){
					for(int j=i;j<=i+n-1;j++)
						ans[j-i+1]=a[j].side;
					if(a[i].z==a[1].z)
						for(int j=n+1;j<2*n;j++)
							ans[j]=2;
					else
						for(int j=n+1;j<2*n;j++)
							ans[j]=1;
					break;
				}
				else
					for(int j=i;j<=i+n-1;j++)
						a[j].side=0;
			}
		}
		if(ans[1]){
			for(int i=1;i<2*n;i++){
				if(ans[i]==1)
					printf("L");
				else printf("R");
			}
			printf("L");
		}
		else
			printf("-1");
	}
	return 0;
}
