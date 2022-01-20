#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
const int N=100010;
using namespace std;
long long a1[N],b1[N],a2[N],b2[N];
long long n,m1,m2,sum1,sum2,l1,l2;
long long ans1[N],ans2[N];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a1[i],&a2[i]);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b1[i],&b2[i]);
	}
	sort(a1+1,a1+m1+1);
	sort(b1+1,b1+m2+1);
	sum1=n;
	sum2=0;
	if(m1+m2<=n){
		printf("%d",m1+m2);
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(sum1<=n&&sum2>=0){
			for(int j=1;j<=n+1;j++){
				ans1[j]++;
				ans2[j]++;
				if(ans1[j]<=sum1){
					if(ans1[j]==sum1){
						if(a1[j+ans1[j]]<a2[j]){
							a1[j+ans1[j]]=a1[j+ans1[j]+1];
							a2[j+ans1[j]]=a2[j+ans1[j]+1];
							ans1[j]--; 
						}
						else{
							a1[j]=a1[j+ans1[j]];
							a2[j]=a2[j+ans1[j]];
							ans1[j]++;
						}
					}
					/*else{
						ans1[j]++;
					}*/
				}
				if(ans2[j]<=sum2){
					if(ans2[j]==sum2){
						if(b1[j+ans2[j]]<b2[j]){
							b1[j+ans2[j]]=b1[j+ans2[j]+1];
							b2[j+ans2[j]]=b2[j+ans2[j]+1];
							ans2[j]--; 
						}
						else{
							b1[j]=b1[j+ans2[j]];
							b2[j]=b2[j+ans2[j]];
						}
					}
					/*else{
						ans2[j]++;
					}*/
				}
			}
			sum1--;
			sum2++;
		}
	}
	long long m=0;
	for(int i=1;i<=n+1;i++){
		m=max(m,ans1[i]+ans2[i]);
	}
	printf("%d\n",m); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
