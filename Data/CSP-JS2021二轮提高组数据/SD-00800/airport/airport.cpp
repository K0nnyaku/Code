#include  <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
const int MMM=100001;
using namespace std;
int n,m1,m2,tot1,tot2;
int a1[MMM],b1[MMM],a2[MMM],b2[MMM],c[MMM];
bool v1[MMM]= {0};
bool v2[MMM]={0};
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=0; i<m1; i++) {
		scanf("%d%d",&a1[i],&b1[i]);
	}
	for(int i=0;i<m1-1;i++){
		for(int j=i+1;j<m1;j++){
			if(a1[j]<a1[i]){
				swap(a1[j],a1[i]);
				swap(b1[j],b1[i]);
			}
		}
	}
	for(int i=0; i<m2; i++) {
		scanf("%d%d",&a2[i],&b2[i]);
	}
	for(int i=0;i<m2-1;i++){
		for(int j=i+1;j<m2;j++){
			if(a2[j]<a2[i]){
				swap(a2[j],a2[i]);
				swap(b2[j],b2[i]);
			}
		}
	}
	int maxx=-2000;
	for(int i=0; i<=n; i++) {
		int i2=n-i;
		tot1=0,tot2=0;
		//////////////////////////////////////////////
		if(i!=0) {
			if(i>=m1) {
				tot1=m1;
			} else {
				memset(v1,0,sizeof(v1));
				int head=0,tail=-1,cur=0;
				for(int j=0; j<m1; j++) {
					if(cur==i) {
						for(int k=head; k<=tail; k++) {
							if(v1[k]==1&&a1[j]>=c[k]) {
								v1[k]=0;
								cur--;
							}
						}
						
					}
					if(cur<i) {
						tot1++;
						cur++;
						tail++;
						v1[tail]=1;
						c[tail]=b1[j];
					}
				}
				
			}
			

		}
		///////////////////////////////////////////////
		if(i2!=0) {
			if(i2>=m2) {
				tot2=m2;
			} else {
				memset(v2,0,sizeof(v2));
				int head=0,tail=-1,cur=0;
				for(int j=0; j<m2; j++) {
					if(cur==i2) {
						for(int k=head; k<=tail; k++) {
							if(v2[k]==1&&a2[j]>=c[k]) {
								v2[k]=0;
								cur--;
							}
						}
					}
					if(cur<i2) {
						tot2++;
						cur++;
						tail++;
						v2[tail]=1;
						c[tail]=b2[j];
					}
				}
				;
			}
			
		}
		//////////////////////////////////////
		maxx=max(maxx,tot1+tot2);
		
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
