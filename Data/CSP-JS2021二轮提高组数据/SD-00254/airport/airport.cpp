#include<iostream> 
#include<cstdio>
using namespace std;/*21!9-324@emb*/
int main(){
	long long a=0,b=0,i=0,n=0,m1=0,m2=0,a1[10001],b1[10001],a2[10001],b2[10001];
	long long x=0,o=0,k=0,r1=0,r2=0,r=0,ra=0,rb=0;
	freopen("airport1.in","r",stdin);
	freopen("airport1.out","w",stdout); 
	cin>>n>>m1>>m2;
	for(i=0;i<m1;i++){
		cin>>a1[i]>>b1[i]>>a2[i]>>b2[i];
		cout<<a1[i]<<b1[i]<<a2[i]<<b2[i];
		for(x=0;x<n;x++){
			if(x!=0){
				for(i=m1;i>0;i--){
					cin>>a1[i]>>b1[i];
					if(b1[i]<=a1[i]){
						r++;
						ra=r;
					}
				}
			}
			else 
			for(i=0;i<m1;i++){
				cin>>a1[i]>>b1[i];
					if(b1[i]<=a1[i]){
						r1++;
						x=2*x-r1;
						n=n-x;
							for(i=0;i<m2;i++){
							cin>>a2[i]>>b2[i];
								if(b2[i]<=a2[i]){
									r2++;
									r=r1+r2;
									rb=r;
								}
							}
					}
			}
		}
	}

	if(ra>=rb)
	cout<<ra<<endl;
	else
	cout<<rb;
	
   
	
	
	
	return 0;
}

