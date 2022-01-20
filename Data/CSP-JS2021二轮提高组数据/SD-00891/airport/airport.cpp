#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;
const int N=10000;
int guonei(int a1[N],int N){
	int num=0;
	int m1,n;
	int c1[N],b1[N];
	for(int i=1;i<=n;i++){
	    if(m1>1){
			for(int i=1;i<=m1;i++){
		        if(a1[i]>=b1[i-1]&&b1[i]<=a1[i+1]){
			        num++;
			        for(int k=i;k<=m1;k++){
		             a1[i]=a1[i+1];
		             b1[i]=b1[i+1];
		             m1--;
		            }    
		        }  
		    }
		    c1[i]=num;
	    }
		    else if(m1==1){
		    	num=1;
		    	m1--;
		        c1[i]=num;
			}
			else{
			     num=0;
			     c1[i]=num;
			}	
	}
	for(int i=1;i<n;i++){
		for(int i=1;i<n;i++){
			if(c1[i]<c1[i+1]){
				swap(c1[i],c1[i+1]);
			}
	    }
	}
	
}
int guowai(int a2[N],int  N){
	int num=0;
	int m2,n;
	int c2[N],b2[N];
	for(int i=1;i<=n;i++){
	    if(m2>1){
			for(int i=1;i<=m2;i++){
		        if(a2[i]>=b2[i-1]&&b2[i]<=a2[i+1]){
			        num++;
			        for(int k=i;k<=m2;k++){
		             a2[i]=a2[i+1];
		             b2[i]=b2[i+1];
		             m2--;
		            }    
		        }  
		    }
		    c2[i]=num;
	    }
		    else if(m2==1){
		    	num=1;
		    	m2--;
		        c2[i]=num;
			}
			else{
			     num=0;
			     c2[i]=num;
			}	
	}
	for(int i=1;i<n;i++){
		for(int i=1;i<n;i++){
			if(c2[i]<c2[i+1]){
				swap(c2[i],c2[i+1]);
			}
	    }
	}
	
}
int e(int c1[N],int c2[N]){
        int ans,n;
        for(int i=1;i<=n;i++){
		if(c1[i]>c2[i]){
			ans+=c1[i];
			for(int k=i;k<n;k++){
			    c2[k+1]=c2[k];
			}
		}
		else{	
		    ans+=c2[i];
			for(int k=i;k<n;k++){
			    c1[k+1]=c1[k];
			}
			
		}
	}
	return ans;
}
int main(){    
	int n,m1,m2;
	int ans=0;
	int a1[N],b1[N],c1[N],a2[N],b2[N],c2[N];
    freopen("airport.in","r",stdin); 
	freopen("aioport.out","w+",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a1[i]>>b1[i];}
		for(int i=1;i<=m1;i++){
		for(int i=1;i<=m1;i++){
			if(a1[i]>a1[i+1]){
				swap(a1[i],a1[i+1]);
				swap(b1[i],b1[i+1]);
			}
	    }}
	for(int i=1;i<=m2;i++){
		cin>>a2[i]>>b2[i];}
		for(int i=1;i<=m2;i++){
		for(int i=1;i<=m2;i++){
			if(a2[i]>a2[i+1]){
				swap(a2[i],a2[i+1]);
				swap(b2[i],b2[i+1]);
			}
	    }}
	guonei(a1,N);
	guowai(a2,N);
	cout<<e(c1,c2)<<endl;
	fclose(stdin),fclose(stdout);
	return 0;
}
