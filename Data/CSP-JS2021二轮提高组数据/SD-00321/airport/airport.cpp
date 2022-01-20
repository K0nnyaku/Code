#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	scanf("%d %d %d",&n,&m1,&m2);
	int nei[m1][2],wai[m2][2];
	for(int i = 0;i<m1;i++)scanf("%d %d",&nei[i][0],&nei[i][1]);//input
	for(int i = 0;i<m2;i++)scanf("%d %d",&wai[i][0],&wai[i][1]);//output
	//paixu 
	for(int j = 0;j<m1-1;j++){
		for(int i = 0;i<m1-1-j;i++){
			if(nei[i][0]<nei[i+1][0])continue;
			else{
				swap(nei[i][0],nei[i+1][0]);
				swap(nei[i][1],nei[i+1][1]);
			}
		}
	}
	for(int j = 0;j<m2-1;j++){
		for(int i = 0;i<m2-1-j;i++){
			if(wai[i][0]<wai[i+1][0])continue;
			else{
				swap(wai[i][0],wai[i+1][0]);
				swap(wai[i][1],wai[i+1][1]);
			}
		}
	}
	//n种廊桥，n+1种情况 
	int ans[n+1];
	memset(ans,0,sizeof(ans));
	
	
	for(int i = 0;i<=n;i++){//shiyandiizhongqingkuang
		//内南桥 外南桥 
		int neil[i],wail[n-i];
		memset(neil,0,sizeof(neil));
		memset(wail,0,sizeof(wail));
		
		for(int j = 0;j<m1;j++){
			for(int k = 0; k<i;k++){
					if(nei[j][0]>neil[k]||neil[k]==0){
						neil[k]=nei[j][1];
						ans[i]++;
						break;
					}	
				}
		} 
		for(int j = 0;j<m2;j++){
			for(int k = 0; k<n-i;k++){
					if(wai[j][0]>wail[k]||wail[k]==0){
						wail[k]=wai[j][1];
						ans[i]++;	
						break;
					}	
				}
		}
	}
	int tmp=0;
	for(int i=0;i<n+1;i++){
		tmp=max(ans[i],tmp);
	}
	printf("%d\n",tmp);
	return 0;
}
