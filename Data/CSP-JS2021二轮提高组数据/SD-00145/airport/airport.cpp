#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
int num,m1,m2;
int incl[100001]={0};
int incg[100001]={0};
int nacl[100001]={0};
int nacg[100001]={0};
int br[100001];
int tmp[100000001]={0};
int ans=0,tans=0;
int temp=0,temp1=0;

int main()
{
	memset(br,-1,sizeof(br));
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>num>>m1>>m2;
	for(int i=0;i<num;i++){
		br[i]=0;
	}
	for(int i=0;i<m1;i++){
		cin>>nacl[i]>>nacg[i];
		if(nacl[i]>temp){
			temp=nacl[i];
		}
	}
	for(int i=0;i<m2;i++){
		cin>>incl[i]>>incg[i];
		if(incl[i]>temp1){
			temp1=incl[i];
		}
	}                                  // ‰»Î 
	
	for(int i=0;i<m1;i++){
		tmp[nacl[i]]=nacg[i];
	}
	for(int i=0,j=0;i<=temp;i++){
		if(tmp[i]!=0){
			nacl[j]=i;
			nacg[j]=tmp[i];
			j++;
		}
	}
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<m2;i++){
		tmp[incl[i]]=incg[i];
	}
	for(int i=0,j=0;i<=temp1;i++){
		if(tmp[i]!=0){
			incl[j]=i;
			incg[j]=tmp[i];
			j++;
		}
	}                                //∆Ωµ≈≈–Ú 
	memset(tmp,-1,sizeof(tmp));
	for(temp=0,temp1=0;temp1<m2;temp++,temp1++){
		tmp[temp]=incl[temp1];
	}
	for(temp1=0;temp1<m2;temp++,temp1++){
		tmp[temp]=incg[temp1];
	}
	for(temp1=0;temp1<m1;temp++,temp1++){
		tmp[temp]=nacg[temp1];
	}
	for(temp1=0;temp1<m1;temp++,temp1++){
		tmp[temp]=nacl[temp1];
	}
	sort(tmp,tmp+(2*m1+2*m2));
	for(int ib=num,nb=0;ib>=0&&nb<=num;ib--,nb++){
		ans=0;
		int ir=ib,nr=nb;
		int it=0,nt=0;
		for(int i=0;i<=(2*m1+2*m2)-1;i++){
			if(incl[it]==tmp[i]){
				if(ir>0){
					for(int h=0;h<ib;h++){
						if(br[h]==0){
							br[h]=incg[it];
							goto tpi;
						}
					}
					tpi:
					ir--;
					ans++;
					it++;
				}
				else{
					it++;
				}
				goto end;
				
			}
			else if(nacl[nt]==tmp[i]){
				if(nr>0){
					for(int h=ib;h<ib+nb;h++){
						if(br[h]==0){
							br[h]=nacg[nt];
							goto tpn;
						}
					}
					tpn:
					nr--;
					ans++;
					nt++;
				}
				else{
					nt++;
					
				}
				goto end;
			}
			else{
				for(int j=0;j<num;j++){
					if(br[j]==tmp[i]){
						br[j]=0;
						if(j>=ib){
							nr++;
						}
						else{
							ir++;
						}
						goto end;
					}
				}
			}
end:
			if(ans>tans){
			tans=ans;
			}
		}
	}
	cout<<tans;
	return 0;
}
