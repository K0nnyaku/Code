#include<bits/stdc++.h>

using namespace std;

const int N=6000;

int n,m1,m2;
int a1[N],b1[N];
int a2[N],b2[N];
int daan[N];
int zhu[N];
int fa1[N],fa2[N];

int main(){
    freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a1[i]>>b1[i];;
		fa1[i]=a1[i];
	}
	for(int i=1;i<=m2;i++){
		cin>>a2[i]>>b2[i];
		fa2[i]=a2[i];
	}
	sort(fa1+1,fa1+m1+1);
	sort(fa2+1,fa2+m2+1);
	//for(int i=1;i<=m1;i++) cout<<fa1[i]<<" ";
	//cout<<endl;
	//for(int i=1;i<=m2;i++) cout<<fa2[i]<<" ";
	
	int gn=0,gw=0;
	for(int i=0;i<=n;i++){
		gn=i;gw=n-gn;
		//daan[i]=n;
		if(gn>0){
			for(int j=1;j<=m1;j++){
				for(int k=1;k<=m1;k++){
					if(a1[k]==fa1[j]){
						zhu[j]=b1[k];
					}
				}
			}
			//for(int ii=1;ii<=n;ii++) cout<<zhu[i]<<" ";
			daan[i]+=gn;
		    for(int j=1;j<=gn;j++){
		    	for(int k=gn+1;k<=m1;k++){
		    		if(zhu[j]<a1[k]){
		    			daan[i]+=1;
		    			zhu[j]=b1[k];
					}
				}
			}
		}
		if(gw>0){
			for(int j=1;j<=m2;j++){
				for(int k=1;k<=m2;k++){
					if(a2[k]==fa2[j]){
						zhu[j]=b2[k];
					}
				}
			}
		    daan[i]+=gw;
		    for(int j=1;j<=gw;j++){
		    	for(int k=gw+1;k<=m2;k++){
		    		if(zhu[j]<a2[k]){
		    			daan[i]+=1;
		    			zhu[j]=b2[k];
					}
				}
			}
		}
	}
	int maxans=-1;
	for(int i=0;i<=n;i++){
		if(maxans<daan[i]) maxans=daan[i];
	}
	cout<<maxans;
//	cout<<endl;
//	for(int i=0;i<=n;i++) cout<<daan[i]<<" ";
	return 0;
}
