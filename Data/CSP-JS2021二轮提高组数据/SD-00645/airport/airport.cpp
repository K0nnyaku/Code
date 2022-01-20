#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define timIn second.first
#define timOut second.second

int pmmn,pMMn;//��ǰʱ��
int n,mm,MM;
int tBeginmm,tBeginMM,tEndmm,tEndMM; 
int pmmc=0,pMMc=0;
int aaa[100010],ans;
bool mmisC[100010],MMisC[100010];//�Ƿ�ѡ�� 
//100010
vector<pair<int,pair<int,int> > > plmm,plMM; 

bool operator <(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b){
	return a.first<b.first;
}

int awa(){//n: now p	
	int res=0;

	for(int i=1;i<plmm.size();i++){
		if(mmisC[i])continue; 
		
		if(pmmc++<pmmn){
			tBeginmm=min(tBeginmm,plmm[i].timIn);
			tEndmm=max(tEndmm,plmm[i].timOut);
			mmisC[i]=true;
			res++;
		}else	if(plmm[i].timIn<=tBeginmm || plmm[i].timOut>=tEndmm){//����֮��
			mmisC[i]=true;
			res++;
		}
	}
	
	for(int i=1;i<plMM.size();i++){
		if(MMisC[i])continue; 
		if(pMMc++<pMMn){
			tBeginMM=min(tBeginMM,plMM[i].timIn);
			tEndMM=max(tEndMM,plMM[i].timOut);
			MMisC[i]=true;
			res++;
		}else	if(plMM[i].timIn<=tBeginMM || plMM[i].timOut>=tEndMM){//����֮��
			MMisC[i]=true;
			res++;
		}
	}
	
	return res;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>mm>>MM;
	int a=0,b=0;
	//���ڷɻ� 
	for(int i=1;i<=mm;i++){
		cin>>a>>b;
		plmm.push_back(make_pair(b-a,make_pair(a,b)));
	}
	//����ɻ�
	for(int i=1;i<=MM;i++){
		cin>>a>>b;
		plMM.push_back(make_pair(b-a,make_pair(a,b)));
	}
	sort(plmm.begin(),plmm.end());
	sort(plMM.begin(),plMM.end());

	
	for(int i=1;i<=n;i++){
		memset(mmisC,0,sizeof(mmisC));
		memset(MMisC,0,sizeof(MMisC));
		pmmn=i-1,pMMn=n-i+1;
		aaa[i]=awa();//�ӵ�i���ɻ���ʼ����
	}
	
	
	
	for(int i=1;i<=n;i++){
		ans=max(ans,aaa[i]);
	}
	cout<<ans;
	
	return 0;
}

