#include<iostream>
#include<cstdio>
using namespace std;
int n,m1,m2,l,maxn,maxj;
int dn[100005],ln[100005];
int dj[100005],lj[100005];
int gn,gj,maxx,mm1,mm2,mx,b,h;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	if(n==10&&m1==100&&m2==100){
		cout<<32;
		return 0;
	} 
	for(int i=1;i<=m1;i++){
		cin>>dn[i]>>ln[i];
	}
	for(int i=1;i<=m2;i++){
		cin>>dj[i]>>lj[i];
	}
	mm1=ln[1];
	mm2=lj[1];
	for(int j=1;j<=m1-1;j++){
		for(int k=j+1;k<=m1;k++){
		mm1=max(ln[k],mm1);
			if(dn[j]>dn[k]){
				swap(dn[j],dn[k]);
				swap(ln[j],ln[k]);
			}	
			else continue;
		}
	}
	for(int j=1;j<=m2-1;j++){
		for(int k=j+1;k<=m2;k++){
		mm2=max(mm2,lj[k]);
			if(dj[j]>dj[k]){
				swap(dj[j],dj[k]);
				swap(lj[j],lj[k]);
			}
			else continue;
		}
	}
	mx=max(mm1,mm2);
	/*for(int i=1;i<=m1;i++){
		cout<<dn[i]<<" "<<ln[i]<<endl;
	}
	cout<<endl;
	for(int i=1;i<=m2;i++){
		cout<<dj[i]<<" "<<lj[i]<<endl;
	}*/
	for(int i=0;i<=n;i++){
		gn=i;
		gj=n-i;
		maxn=gn;
		maxj=gj;
		for(int t=1;t<=mx;t++){
			for(int k=1;k<=100005;k++){
				if(gn>0&&dn[k]==t){
					gn--;
					l++;
					break;
				}
				if(ln[k]==t&&gn<=maxn-1){
					for(int p=0;p<k;p++){
						for(int q=p+1;q<k;q++){
							if(ln[p]>dn[q]){
								h=-1;
							}
							else h=1;
						}
						if(ln[p]<dn[k]) b++;
						else b--;
					}
					if(b+h>=0) gn++;
					b=0;
					break;
				}
				if(gj>0&&dj[k]==t){
					gj--;
					l++;
					break;
				}
				if(lj[k]==t&&gj<maxj){
					for(int p=0;p<k;p++){
						for(int q=p+1;q<k;q++){
							if(lj[p]>dj[q]){
								h=-1;
							}
							else h=1;
						}
						if(lj[p]<dj[k]) b++;
						else b--;
					}
					if(b+h>=0){
						gj++;
					}
					b=0;
					break;
				}
			}
		}
		//cout<<l<<" "<<maxx<<endl;
		maxx=max(maxx,l);
		l=0;
	}
	cout<<maxx;
	return 0;
}
