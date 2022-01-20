#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m1,m2,cpid,apid,totplid,maxiumi=-1;
int jcsnpid[100005];

class planer{
public:
	int arr;
	int lea;
	int typerr; //country=1  abroad=2

}planes[100005];

bool cmp1(planer a,planer b){
	return a.arr < b.arr;
}
int main() {
	planes[0].lea=0; //dummy
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	int i=1;
		for(; i<=m1; i++) {
			scanf("%d%d",&planes[i].arr,&planes[i].lea);
			planes[i].typerr=1;//cp
		}
		for(; i<=m2+m1; i++) {
			scanf("%d%d",&planes[i].arr,&planes[i].lea);
			planes[i].typerr=2;//ap
		}
	sort(planes+1,planes+m1+m2+1,cmp1);
	for(int i=0;i<=n;i++){ //c tot blk
		//loop id
		int capt=i;
		int csum=0;
		//st time all pla blk =0(0)(dummy)
		for(int j=1;j<m1+m2+1;j++){//loop pla id (allid)
			if(planes[j].typerr==1)//country plane
			{
				for(int k=0;k<capt;k++){
				;
					if(planes[jcsnpid[k]].lea<=planes[j].arr)
					{
						csum++;// ke ru ci ji chang
						jcsnpid[k]=j; //fei ji jin ru..
						break;
					}
				}
			}
			else{ //abroad plane
			for(int k=capt;k<n;k++){
				;
					if(planes[jcsnpid[k]].lea<=planes[j].arr)
					{
						csum++;// ke ru ci ji chang
						jcsnpid[k]=j; //fei ji jin ru..
						break;
					}	
				}
			
			}
		}
		maxiumi=max(maxiumi,csum);
	memset(jcsnpid,0,sizeof(jcsnpid));
	}
	printf("%d",maxiumi);
	fclose(stdin);
	fclose(stdout);
	return 0;
}



