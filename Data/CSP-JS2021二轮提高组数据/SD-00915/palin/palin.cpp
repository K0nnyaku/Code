#include<bits\stdc++.h>
using namespace std;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int i3=0,n,m1,m2,time1in[100000],time1out[100000],time2in[100000],time2out[100000];
	int temp=1,temp1,n1[1000],n2[1000],templ=1,templ1,num[1000],lal;
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++){
		cin>>time1in[i]>>time1out[i];
	}
	for(int i2=0;i2<m2;i2++){
		cin>>time2in[i2]>>time2out[i2];
	}
	for(int j=0;j<n;j++){
		if(time1out[j]>time1in[j+1]&&temp1<=3){
			temp++;
			}
			if(temp>=j){
				for(int t=0;t<j;t++){
					if(time1out[t]>time1in[j]){
						temp--;
					}
					else{
						time1in[j]=9999;
					}
				}
			}
		n1[j]=temp;
		}
	
	for(int j=0;j<n;j++){
		if(time2out[j]>time2in[j+1]&&templ<=3){
			templ++;
			}
			if(templ>=j){
				for(int t=0;t<j;t++){
					if(time2out[t]>time2in[j]){
						templ--;
					}
					else{
						time2in[j]=9999;
					}
				}
			}
		n2[j]=templ;
		}
		for(int ui=0;ui<500;ui++){
			num[ui]=n1[ui]+n2[ui];
		}
	for(int j=0;j<50000;j++){
		if(num[j]<num[j+1]){
			lal=num[j];
			num[j]=num[j+1];
			num[j+1]=lal;
		}
		for(int k=50000;k>j;k--){
			if(num[k]>num[k-1]){
				lal=num[k];
				num[k]=num[k-1];
				num[k-1]=lal;
			}
			
			
		
		}
			 
	}		
     cout<<num[0]<<" ";
	return 0;
}

		
