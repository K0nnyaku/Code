#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f;
long long n,mm1,mm2;
long long a[100010],b[100010];
long long x[100010],y[100010];
long long sum,num,ans;
long long fa,fx;
long long enda[100010],endx[100010];
long long p,q;
int flag=1,lag=1;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&mm1,&mm2);
	for(int i=1;i<=mm1;i++)scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=mm2;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=0;i<=n;i++){
		if(i>0){
			for(int j=1;j<=mm1;j++){
				flag=1;
				if(p>0){
					for(int k=1;k<=p;k++){
						if(a[j]>enda[k]){
							enda[k]=b[j];
							sum++; 
							flag=-1;
						}
					}
				}
				if(flag==(-1))continue;
				if(fa<i){
					fa+=1;
					p++;
					enda[p]=b[j];
					sum++;
				}
				else{
					sort(enda,enda+p+1);
					for(int k=1;k<=p;k++){
						if(a[j]>enda[k]){
							enda[k]=b[j];
							sum++; 
							continue;
						}
					}
				}
			}
		}
		if(i<n){
			for(int j=1;j<=mm2;j++){
				lag=1;
				if(q>0){
					for(int k=1;k<=q;k++){
						if(x[j]>endx[k]){
							endx[k]=y[j];
							num++; 
							lag=-1;
						}
					}
				}
				if(lag==(-1))continue;
				if(fx<(n-i)){
					fx++;
					q++;
					endx[q]=y[j];
					num++;
				}
				else{
					sort(endx,endx+q+1);
					for(int k=1;k<=q;k++){
						if(x[j]>endx[k]){
							endx[k]=y[j];
							num++;
							continue; 
						}
					}
				}
			} 
		}
		if(ans<(sum+num))ans=sum+num;
		sum=0;
		num=0;
		fa=0;
		fx=0;
		memset(enda,0,sizeof(enda));
		memset(endx,0,sizeof(endx));
		p=0;
		q=0;
	} 
	printf("%d\n",ans); 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
