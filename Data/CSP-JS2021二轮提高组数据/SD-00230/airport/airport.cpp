#include<bits/stdc++.h>
using namespace std;
struct plane{
	int ar;
	int ge;
};
plane a[100010];
plane b[100010];
bool cmp(plane x,plane y){
	return x.ar < y.ar;
}
int n,m1,m2;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n;
	cin>>m1>>m2;
	for(int i = 0;i < m1;i ++ ){
		cin>> a[i].ar >> a[i].ge;
	}	
	for(int i = 0;i < m2;i ++ ){
		cin>> b[i].ar >> b[i].ge;
	}
	sort(a,a+m1,cmp);
	sort(b,b+m2,cmp);
	int max=0;
	for(int i=0;i<=n;i++){
		int nat=i;
		int namax=0;
		int posna[100010];
		int havena=0;
		for(int f=1;f<=nat;f++){
			posna[f]=1e8;
		}
		for(int j=0;j<m1;j++){
			if(i==0){
				break;
			}
			if(nat!=0){
				nat--;
				namax++;
				havena++;
				posna[havena]=a[j].ge;
				continue;
			}else{
				for(int d=1;d<=i;d++){
					if(a[j].ar>posna[d]){
						namax++;
						posna[d]=a[j].ge;
						continue;
					}
				}
			}
		}
		int innat=n-i;
		int innamax=0;
		int havein=0;
		int posinna[100010];
		for(int f=1;f<=innat;f++){
			posinna[f]=1e8;
		}
		for(int j=0;j<m2;j++){
			if(n-i==0){
				break;
			}
			if(innat!=0){
				innat--;
				innamax++;
				havein++;
				posinna[havein]=a[j].ge;
				continue;
			}else{
				for(int d=1;d<=(n-i);d++){
					if(a[j].ar>posinna[d]){
						innamax++;
						posinna[d]=a[j].ge;
						continue;
					}
				}
			}
		}
		
		int cmax=namax+innamax;
		if(cmax>max){
			max=cmax;
		}
	}
	cout<<max;
	return 0;
}
