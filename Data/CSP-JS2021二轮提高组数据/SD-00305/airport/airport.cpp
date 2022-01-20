#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	long long n,m1,m2,max[100001],a1[100001],b1[100001],a2[100001],b2[100001],g,w,m;
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++){
		cin>>a1[i]>>b1[i];
	}
	for(int j=0;j<m2;j++){
		cin>>a2[j]>>b2[j];
	}
	for(int i=0;i<n;i++){
		max[i]=0;
	}
	for(g=0;g<=n;g++){
		w=n-g;
		if(g>=m1){
			max[g]=max[g]+m1;
		}
		if(w>=m2){
			max[g]=max[g]+m2;
		}
		else if(g<m1){
			max[g]=max[g]+g;
			for(int i=g;i<m1;i++){
				for(int a=1;a<=m1;a++){			
					if(a1[i]>b1[i-a]){
						max[g]++;
					} 
				}
			}
		}
		else if(w<m2){
			max[g]=max[g]+w;
			for(int j=w;j<m2;j++){
				for(int b=1;b<=m2;b++){	
					if(a2[j]>b2[j-b]){
						max[g]++;
					} 
				}
			}
		}
	}	
	m=max[0];
	for(int j=1;j<n;j++){
		if(max[j]>max[j-1]){
			m=max[j];
		}
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
