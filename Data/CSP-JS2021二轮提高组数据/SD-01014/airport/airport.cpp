#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;
int timen[150001],timej[150001],gnneed[150001],gjneed[150001];

struct gnhangban{
	int c,g;//来去时间 
}gnhb[150001];

struct gjhangban{
	int c,g;
}gjhb[150001];

int dodogn(int k,int gn) {//k是廊桥数量 gn是航班数量 
	if(k==0)return 0;
	int ans=0;
	for(int i=1;i<=gn;i++){
		//先检查开头是否行 
		if(timen[gnhb[i].c]+1<=k){
			ans++;
			for(int j=gnhb[i].c;j<=gnhb[i].g;j++)timen[j]++;
		}
	}
	return ans;
}

int dodogj(int k,int gj) {
	if(k==0)return 0;
	int ans=0;
	for(int i=1;i<=gj;i++){
		if(timej[gjhb[i].c]+1<=k){
			ans++;
			for(int j=gjhb[i].c;j<=gjhb[i].g;j++)timej[j]++;
		}
	}
	return ans;
}

bool cmpgn(gnhangban a,gnhangban b){
	return a.c<b.c;
}

bool cmpgj(gjhangban a,gjhangban b){
	return a.c<b.c;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	//输入 廊桥数量 国内国际航班数量
	int lq,gn,gj;
	cin>>lq>>gn>>gj;
	//国内 国际航班来去时间 
	for(int i=1;i<=gn;i++) cin>>gnhb[i].c>>gnhb[i].g;
	for(int i=1;i<=gj;i++) cin>>gjhb[i].c>>gjhb[i].g;
	//航班会往里挤 能早进就早进 给每一个航班附加一个值 需要廊桥的值 
	
	//按照来的时间排序
	sort(gnhb+1,gnhb+1+gn,cmpgn);
	sort(gjhb+1,gjhb+1+gj,cmpgj);
	
	//转换思路 暴力模拟
	int maxn=-0x3f3f;
	for(int ign=0;ign<=lq;ign++){
		int igj=lq-ign;		
		maxn=max(maxn,dodogn(ign,gn)+dodogj(igj,gj));
		memset(timen,0,sizeof timen);memset(timej,0,sizeof timej);
	}cout<<maxn;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
