#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;

int n,m1,m2,ans[100000];
long long int km1[100000],qm1[100000],km2[100000],qm2[100000];
long long int kn1[100000],kn2[100000];

void sw1(int x){
	for(int i=0;i<m1;i++){
		for(int w=0;w<m1;w++){
			if(km1[i]<km1[w]&&i>w){
				int cun1=km1[i],cun2=qm1[i];
				km1[i]=km1[w],qm1[i]=qm1[w];
				km1[w]=cun1,qm1[w]=cun2;
			}
		}
	}
} 

void sw2(int x){
	for(int i=0;i<m2;i++){
		for(int w=0;w<m2;w++){
			if(km2[i]<km2[w]&&i>w){
				int cun1=km2[i],cun2=qm2[i];
				km2[i]=km2[w],qm2[i]=qm2[w];
				km2[w]=cun1,qm2[w]=cun2;
			}
		}
	}
} 

int minn1(int y){
	long long int mmin= 100000001;
	int mid = y/2,mmint;
	for(int i=mid,ii=mid;i>=0||ii<=y;i--,ii++){
		if(i>=0&&kn1[i]<mmin) {
			mmin=kn1[i];
			mmint=i;
		}
		if(ii<=y&&kn1[ii]<mmin&&kn1[ii]<kn1[i]) {
			mmin=kn1[ii];
			mmint=ii;
		}
	}
	return mmint;
}
int minn2(int y){
	long long int mmin= 100000001;
	int mid = y/2,mmint;
	for(int i=mid,ii=mid;i>=0||ii<=y;i--,ii++){
		if(i>=0&&kn2[i]<mmin) {
			mmin=kn2[i];
			mmint=i;
		}
		if(ii<=y&&kn2[ii]<mmin&&kn2[ii]<kn2[i]) {
			mmin=kn2[ii];
			mmint=ii;
		}
	}
	return mmint;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	for(int i=0;i<100001;i++){
		kn1[i]=100000001;
		kn2[i]=100000001;
	}
	
	int ansm=-1;
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++){
		cin>>km1[i]>>qm1[i];
	}
	sw1(m1);
	for(int i=0;i<m2;i++){
		
		cin>>km2[i]>>qm2[i];
	}
	sw2(m2);
	int n1,n2;
	for(int i=0;i<=n;i++){
		n1=i;n2=n-i;
		int n11=0,n22=0;
		for(int w=0;w<m1;w++){
			
			if(n11<n1){
				n11++;
				kn1[w]=qm1[w];
				ans[i]++;
			}
			
			else if(n1!=0){
				if(km1[w]>kn1[minn1(n1)]){
					ans[i]++;
					kn1[minn1(n1)]=qm1[w];
				}
			}
		}
		
		for(int w=0;w<m2;w++){
			
			if(n22<n2){
				n22++;
				kn2[w]=qm2[w];
				ans[i]++;
			}
			
			else if(n2!=0){
				if(km2[w]>kn2[minn2(n2)]){
					ans[i]++;
					kn2[minn2(n2)]=qm2[w];
				}
			}
		}

	}
	for(int i=0;i<=n;i++){
		if(ans[i]>ansm) ansm=ans[i];
	}
	cout<<ansm;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
