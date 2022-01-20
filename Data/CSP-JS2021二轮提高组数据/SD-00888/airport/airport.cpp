#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,p=0,ns,r,ns1,z,ps,m,p1[1001]={0};
	int a[1001]={0},aa[1001]={0},a1[1001]={0},a2[1001]={0},b[1001]={0},bb[1001]={0},b1[1001]={0},b2[1001]={0};
	int i=0,j=0,k=0;
	int sumh[1001]={0},rs2[1001]={0},rs1[1001]={0};
	int sum,s1,s2;
	cin>>n>>m1>>m2;
	for(i;i<m1;i++){
		cin>>a1[i]>>a2[i];
	}
	for(i=0;i<m2;i++){
		cin>>b1[i]>>b2[i];
	}
	for(i=0;i<m1;i++){
		for(j=0;j<m1;j++){
			if(a1[i]>a1[j]){
			p++;
			}	
		}
		a[p]=a1[i];
		aa[p]=a2[i];
		p=0;
	}
	for(i=0;i<m2;i++){
		for(j=0;j<m2;j++){
			if(b1[i]>b1[j]){
			p++;
			}	
		}
		b[p]=b1[i];
		bb[p]=b2[i];
		p=0;
	}
	for(ns=0;ns<=n;ns++){
		if(ns=0)
			s1=0;
		else{
			for(m=0;m<ns;m++){
				p1[m]=aa[m];
				z=m;
				s1++;}
				//pai 
			for(int y=0;y<=m1;y++){
				for(ps=0;ps<=m;ps++){
					if(p1[ps]<a[z+1]){
					aa[z+1]=p1[ps];
					s1++;	
					}
					z++;
				}	}	}
				for(int h=0;h<n;h++){
					rs1[h]=s1;
					s1=0; 
				}	}
	for(ns1=n;ns1>=0;ns1--){
		if(ns1=0)
			s1=0;
		else{
			for(m=0;m<ns1;m++){
				p1[m]=aa[m];
				z=m;
				s2++;}
				//pai 
				for(int y=0;y<=m1;y++){
				for(ps=0;ps<=m;ps++){
					if(p1[ps]<b[z+1]){
					bb[z+1]=p1[ps];
					s2++;	
					}
					z++;
				}	}	}
				for(int h=0;h<n;h++){
					rs2[h]=s2;
					s2=0; 
				}	}
	for(r=0;r<n;r++){
	sumh[r]=rs1[r]+rs2[r];	
	}
	for(r=0;r<n;r++){
		if(sumh[0]<sumh[r])
		sumh[0]=sumh[r];
	}
	cout<<sumh[0];
	return 0;
} 
