#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct inner{
	int arr;
	int lea;
}inn[5005];
struct abroad{
	int ar;
	int le;
}abr[5005];
int ans[5005],bns[5005],asw[5005];
bool cmp(abroad a,abroad b){
	return a.ar<b.ar;
}
bool cmpn(inner a,inner b){
	return a.arr<b.arr;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,a,b,e,nsw;
	int ai[105],bi[105];
	memset(ai,0x7ffffff,sizeof(ai));
	memset(bi,0x7ffffff,sizeof(bi));
	scanf("%d%d%d",&n,&a,&b);
	if(n<=a+b){
	for(int i=1;i<=a;i++)scanf("%d%d",&inn[i].arr,&inn[i].lea);
	sort(inn+1,inn+a+1,cmpn);
	for(int i=0;i<=n;i++){
		int p=i,e=0;
		for(int j=1;j<=a;j++){
			if(p>0){
				p--;
				e++;
				ai[p]=inn[j].lea;
			}
			else{
				for(int l=1;l<=i;l++){
					if(ai[l]<=inn[j].arr){
						e++;
						ai[l]=inn[j].lea;
						break;
					}
				}
			}
			ans[i]=e;
		}
	}
	for(int i=1;i<=b;i++)scanf("%d%d",&abr[i].ar,&abr[i].le);
	sort(abr+1,abr+b+1,cmp);
	for(int i=n;i>=0;i--){
		int p=i,e=0;
		for(int j=1;j<=b;j++){
			if(p>0){
				p--;
				e++;
				bi[p]=abr[j].le;
			}
			else{
				for(int l=1;l<=i;l++){
					if(bi[l]<=abr[j].ar){
						e++;
						bi[l]=abr[j].le;
						break;
					}
				}
			}
			bns[i]=e;
		}
	}
	for(int i=0;i<=n;i++){
		asw[i]=ans[i]+bns[n-i];
	}
	nsw=asw[0];
	for(int i=1;i<=n;i++){
		if(asw[i]>nsw)nsw=asw[i];
	}
	nsw+=1;
	printf("%d",nsw);
	return 0;
}
	else{
		cout<<a+b;
		return 0;
	}
}

