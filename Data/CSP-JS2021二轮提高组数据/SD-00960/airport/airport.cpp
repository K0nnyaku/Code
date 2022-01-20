#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a1[100000],b1[100000],a2[100000],b2[100000],gnn[100000],gjn[100000],gnt[100000],gjt[100000],p1[100000],p2[100000];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,zuida=0,t1,t2;
	cin>>n>>m1>>m2;
	int gny=0,gjy=0;
	for(int i=0;i<m1;i++){
		cin>>a1[i]>>b1[i];
		p1[i]=a1[i];
	}
	for(int i=0;i<m2;i++){
		cin>>a2[i]>>b2[i];
		p2[i]=a2[i];
	}
	for(int i=0;i<m1;i++){
		for(int j=0;j<m1-1;j++){
			if(p1[j]>p1[j+1]){
				t1=p1[j];
				p1[j]=p1[j+1];
				p1[j+1]=t1;
			}
		}
	}
	for(int i=0;i<m2;i++){
		for(int j=0;j<m2-1;j++){
			if(p2[j]>p2[j+1]){
				t2=p2[j];
				p2[j]=p2[j+1];
				p2[j+1]=t2;
			}
		}
	}
	for(int i=0;i<=n;i++){
		gny=i;
		for(int k=0;k<m1;k++){
		for(int j=0;j<m1;j++){
			if(a1[j]==p1[k]){
				if(gny>0){
					gnn[i]++;
					gny--;
					gnt[j]=b1[j];
					break;
				}
				else{
					for(int h=0;h<i;h++){
					if(a1[j]>=gnt[h]){
						gnn[i]++;
						gnt[h]=b1[j];
						break;
				}
			}
			}
			}
		}
		}
	}
	for(int i=0;i<=n;i++){
		gjy=i;
		for(int k=0;k<m2;k++){
		for(int j=0;j<m2;j++){
			if(a2[j]==p2[k]){
				if(gjy>0){
					gjn[i]++;
					gjy--;
					gjt[j]=b2[j];
				}
				else{
					for(int h=0;h<i;h++){
					if(a2[j]>=gjt[h]){
						gjn[i]++;
						gjt[h]=b2[j];
					}
					}
			}
		}
		}
	}
	}
	for(int i=0;i<=n;i++){
		if(gnn[i]+gjn[n-i]>=zuida) zuida=gnn[i]+gjn[n-i];
	}
	cout<<zuida;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
