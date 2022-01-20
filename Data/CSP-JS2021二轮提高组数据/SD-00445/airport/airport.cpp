#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<time.h>
#include<stdlib.h>
#include<string>
using namespace std;
int n,m1,m2;
int maxnn;
int m_t1[100010];
int m_t2[100010];
int m_t10[100010];
int m_t20[100010];
int chazhi01[100010];
int chazhi02[100010];
int ans;
int ansm;
bool mgtt;
int guoji;
int guonei;
void jiaohuan1(int a[],int b[]){
	for(int i=1;i<m1;i++){
		if(a[i]>a[i+1]){
		swap(a[i],a[i+1]);
		swap(b[i],b[i+1]);
		}
	}
}
void jiaohuan2(int a[],int b[]){
	for(int i=1;i<m2;i++){
		if(a[i]>a[i+1]){
		swap(a[i],a[i+1]);
		swap(b[i],b[i+1]);
		}
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&m_t1[i],&m_t10[i]);
		//chazhi01[i]=m_t10[i]-m_t1[i];
	}
	 for(int i=1;i<=m2;i++){
		scanf("%d%d",&m_t2[i],&m_t20[i]);
		//chazhi02[i]=m_t20[i]-m_t2[i];
	}
	 for(int j=0;j<m1;j++){
	 	jiaohuan1(m_t1,m_t10);
	 }
	 for(int j=0;j<m2;j++){
	 	jiaohuan2(m_t2,m_t20);
	 }
	 for(int i=0;i<=n;i++){
	 	guonei=i;
	 	guoji=n-i;
	 	if(guonei!=0){
	 		memset(chazhi01,i,sizeof(chazhi01));
		 	for(int i=1;i<=m1;i++){
		 		mgtt=0;
				for(int j=m_t1[i];j<=m_t10[i];j++){
					if(mgtt==1){
						break;
					}
					if(m_t1[i]<=0){
						break;
					}
					if(chazhi01[j]>=1){
						chazhi01[j]--;
					}else{
						mgtt=1;
						break;
					}
					ans++;
				}
			}
		 } 
		 if(guoji!=0){
		 	memset(chazhi02,n-i,sizeof(chazhi02));
		 	for(int i=1;i<=m2;i++){
		 		mgtt=0;
				for(int j=m_t2[i];j<=m_t20[i];j++){
					if(mgtt==1){
						break;
					}
					if(m_t2[i]<=0){
						break;
					}
					if(chazhi02[j]>=1){
						chazhi02[j]--;
					}else{
						mgtt=1;
						break;
					}
					ans++;
				}
			}
		 }
		 if(ans>maxnn){
		 	maxnn=ans;
		 }
		 ans=0;
	 }

	 cout<<maxnn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}//±ðÍüÁËÈ¥µô×¢ÊÍ 
