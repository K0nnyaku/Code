#include<iostream>
#include<cstdio>
using namespace std;
int n,m1,m2;
struct wuhuqifei{
	long long daoda,lichang,shuxing,cixudao,cixuli,zhuangtai; 
}feiji[100005];
long long shijian=0;
long long tianhuaban=1;
int guonei,guoji;
int manyi=0,zuidaint=0,daan=0;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>feiji[i].daoda>>feiji[i].lichang;
		if(feiji[i].lichang>=tianhuaban) tianhuaban=feiji[i].lichang;
		feiji[i].shuxing=1;
		feiji[i].cixudao=1;
		feiji[i].cixuli=1;
	}
	for(int i=1;i<=m2;i++){
		cin>>feiji[m1+i].daoda>>feiji[m1+1].lichang;
		if(feiji[m1+i].lichang>=tianhuaban) tianhuaban=feiji[m1+i].lichang;
		feiji[m1+i].shuxing=2;
		feiji[m1+i].cixudao=1;
		feiji[m1+i].cixuli=1;
	}
	for(int i=1;i<=m1+m2;i++){
		for(int j=1;j<=m1+m2;j++){
			if(feiji[i].daoda<feiji[j].daoda) feiji[i].cixudao++;
		}
	}
	for(int i=1;i<=m1+m2;i++){
		for(int j=1;j<=m1+m2;j++){
			if(feiji[i].lichang<feiji[j].lichang) feiji[i].cixuli++;
		}
	}
	for(int j=0;j<=n;j++){
		guonei=j;
		guoji=n-j;
		for(shijian;shijian<=tianhuaban;shijian++){
			for(int i=1;i<=m1+m2;i++){
				for(int k=1;k<=m1+m2;k++){
					if(feiji[k].cixudao==i){
						if(feiji[k].shuxing==1){
						    if(guonei!=0){
							    guonei--;
							    manyi++;
							    feiji[k].zhuangtai=1;
						    }
					    }
					    if(feiji[k].shuxing==2){
						    if(guoji!=0){
							    guoji--;
							    manyi++;
							    feiji[k].zhuangtai=1;
						    }
					    }
					}
				}
				for(int k=1;k<=m1+m2;k++){
					if(feiji[k].cixuli==i){
						if(shijian==feiji[k].lichang){
					        if(feiji[k].shuxing==1){
					        	if(feiji[k].zhuangtai==1) guonei++;
							}
					        if(feiji[k].shuxing==2){
					        	if(feiji[k].zhuangtai==1) guoji++;
							}
				        }
					}
				}
			}
			for(int k=1;k<=m1+m2;k++){
				feiji[k].zhuangtai=0;
			}   
			if(zuidaint<=manyi) zuidaint=manyi;
			manyi=0;
		}
		shijian=0;
		guonei=0;
		guoji=0;
		if(daan<=zuidaint) daan=zuidaint;
		zuidaint=0;
	}
	cout<<daan;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
