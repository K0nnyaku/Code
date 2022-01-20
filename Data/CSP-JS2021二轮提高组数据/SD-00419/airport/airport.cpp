#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
struct plane{
	int a,b,id;
}a[100010],b[100010];
bool cmp(struct plane z,struct plane w){
	if(z.a<w.a) return true;
	else if(z.a>w.a) return false;
	else{
		if(z.b<w.b) return true;
		else return false;
	}
}
bool pmc(int z,int w){
	return z>w;
}
int /*bka[100010]={0},bkb[100010]={0},*/cnta=0,cntb=0,oi=0,ans=0;
int lsta[100100],lstb[100010]={0};
int zua[100010]={0},zub[200010]={0};
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	//printf("%d\n",x);
	for(int i=0;i<x;i++){
		scanf("%d%d",&a[i].a,&a[i].b);
	}
	//printf("haha\n");
	sort(a,a+x,cmp);
	for(int i=0;i<x;i++){
		if(cnta==0){
			lsta[cnta]=i;
			zua[cnta++]++;
			//printf("haha\n");
		}
		else{
			//printf("haha\n");
			oi=0;
			for(int j=0;j<cnta;j++){
				if(a[lsta[j]].b<=a[i].a){
					lsta[j]=i;
					zua[j]++;
					oi=1;
					break;
				}
			}
			if(oi==0){
				lsta[cnta]=i;
				zua[cnta++]++;
			}
		}
	}
	//printf("haha\n");
	
	
	for(int i=0;i<y;i++){
		scanf("%d%d",&b[i].a,&b[i].b);
	}
	sort(b,b+y,cmp);
	for(int i=0;i<y;i++){
		if(cntb==0){
			lstb[cntb]=i;
			zub[cntb++]++;
		}
		else{
			oi=0;
			for(int j=0;j<cntb;j++){
				if(b[lstb[j]].b<=b[i].a){
					lstb[j]=i;
					zub[j]++;
					oi=1;
					break;
				}
			}
			if(oi==0){
				lstb[cntb]=i;
				zub[cntb++]++;
			}
		}
	}
	int p=0,q=0;
	for(int i=0;i<n;i++){
		if(zua[p]>=zub[q]){
			ans+=zua[p++];
		}
		else{
			ans+=zub[q++];
		}
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
