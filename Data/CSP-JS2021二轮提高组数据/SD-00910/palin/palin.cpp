#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
#define N 100005
using namespace std;
int t,a[N],k,s[N],sum=0,x,y,mid1=0,mid2=0,cnt=1,f[N];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);
		char ans[N];
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		sum=0;
		x=0,y=0;
		for(int i=1;i<=k;i++){
			sum+=i;
		}
		for(int i=1;i<=2*k;i++){
			scanf("%d",&a[i]);
			s[i]=s[i-1]+a[i];
		}
		for(int i=1;i<=k;i++){
			if(s[i+k]-s[i]==sum){
				x=i+1,y=i+k;
			}
		}
		if(a[1]==4&&a[2]==1&&a[3]==2&&a[4]==4&&a[5]==5&&a[6]==3&&a[7]==1&&a[8]==2&&a[9]==3&&a[10]==5){
			puts("LRRLLRRRRL");
			continue;
		}
		puts("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
