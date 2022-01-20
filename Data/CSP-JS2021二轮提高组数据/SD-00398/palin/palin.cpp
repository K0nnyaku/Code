#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int a[1000005],b[1000005],er[1000005],a_t,a_h,b_t,n;
void chai(long long x){
	memset(er,0,sizeof(er));
	int tota=0,bian=2*n;
	while(x!=0){
		er[bian-tota]=x%2;
		x/=2;
		tota++;
	}
}
bool pan(){
	int tou=1,wei=2*n;
	while(tou<wei){
		if(b[tou++]!=b[wei--]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		bool youwuans=0;
		a_h=1;
		scanf("%d",&n);
		a_t=b_t=2*n;
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		long long num=pow(2,2*n);
		for(long long i=0;i<num;i++){
			chai(i);
			a_h=1;
			a_t=b_t=2*n;
			for(int j=1;j<=2*n;j++){
				if(er[j]==0){
					b[b_t--]=a[a_h++];
				}
				else{
					b[b_t--]=a[a_t--];
				}
			}
			if(pan()){
				for(int j=1;j<=2*n;j++){
					if(er[j]==0){
						printf("L");
					}
					else{
						printf("R");
					}
				}
				puts("");
				youwuans=1;
				break;
			}
		}
		if(youwuans==0) puts("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
