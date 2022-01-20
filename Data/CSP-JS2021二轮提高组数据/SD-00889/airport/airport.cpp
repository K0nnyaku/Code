#include <iostream> 
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,nhome,nabord; 
long long home[100001],abord[100001],a,b,minin=0x7FFFFFFF,minout=0x7FFFFFFF,maxin,maxout,no1,no2,s1,s2,ans;
long long book[100000],book2[100000];
//long long homein[100000],homeout[100000],abordin[100000];abordout[100000];
int main(){
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>nhome>>nabord;
	for(int i=1;i<=100000;i++)home[i]=0x7FFFFFFF;
	for(int i=1;i<=100000;i++)abord[i]=0x7FFFFFFF;
	for (int i=1;i <= nhome;i++){
		cin>>a>>b;
		home[a]=b;
		maxin=max(maxin,a);
	}
	for (int i=1;i<=nabord;i++){
		cin>>a>>b;
		abord[a]=b;
		maxout=max(maxout,a);
	}
	for(int i=0;i<=n;i++){
		cout<<i<<" "<<n-i;
		minin=0x7fffffff;
		minout=0x7fffffff;
		int j=n-i;
		s1=0;s2=0;
		int xi=i,xj=j;
		for(int k=1;k<=max(maxin,maxout);k++){
			if(home[k]<0x7FFFFFFF){
				if(xi>0){
//					cout<<" ("<<k<<" "<<home[k]<<")"<<"Y "<<endl;
					if(home[k]<minin){
						minin=home[k];
						no1=k;
					}
					s1++;
					xi--;
				}
				else{
					if(k>minin){
					    for(int w=1;w<=k;w++){
					    	if(home[w]<k){
					    		book[w]=1;
					    		xi++;
							}
						}
						book[no1]=1;
						minin=home[k];
						no1=k;
//						cout<<" ("<<k<<" "<<home[k]<<")"<<"Y "<<endl;
						for(int l=1;l<=k;l++){
							if(book[l]==0)minin=min(minin,home[l]);
						}
						s1++;
						xi--;
					} 
					else {
//						cout<<" ("<<k<<" "<<home[k]<<")"<<"N "<<endl;
						book[k]=1;
					}
					
				}
			}
			if(abord[k]<0x7FFFFFFF){
				if(xj>0){
//					cout<<" ("<<k<<" "<<abord[k]<<")"<<"Y "<<endl;
					if(abord[k]<minout){
						minout=abord[k];
						no2=k;
					}
					s2++;
					xj--;
				}
				else{
					if(k>minin){
				    	for(int w=1;w<=k;w++){
					    	if(abord[w]<k){
					    		book2[w]=1;
					    		xj++;
							}
						}
						book2[no2]=1;
						minout=abord[k];
						no2=k;
//				    	cout<<" ("<<k<<" "<<abord[k]<<")"<<"Y "<<endl;
						for(int l=1;l<=k;l++){
							if(book2[l]==0)minout=min(minout,abord[l]);
						}
						s2++;
						xj--;
					}
//					else cout<<" ("<<k<<" "<<abord[k]<<")"<<"N "<<endl; 
				}
			}
		}
		ans=max(ans,s1+s2);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
