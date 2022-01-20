#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m1,m2,qianzhuihe_nei[100005],qianzhuihe_wai[100005],cnt1,cnt2;//cn1 ื้สý 
struct node{
	int start,end,bing;
	bool fangwen;
}nei[100005],wai[100005];
bool cmp(node x,node y){
	if(x.start<y.start) return 1;
	return 0;
}
void hebing1(int x){
	for(int i=x;i<=m1;i++){
		if(nei[x].end<=nei[i].start&&nei[i].fangwen==0){
			nei[i].bing=cnt1;
			nei[i].fangwen=1;
			qianzhuihe_nei[cnt1]++;
			hebing1(i);
			return ;
		}
	}
}
void hebing2(int x){
	for(int i=x;i<=m2;i++){
		if(wai[x].end<=wai[i].start&&wai[i].fangwen==0){
			wai[i].bing=cnt2;
			wai[i].fangwen=1;
			qianzhuihe_wai[cnt2]++;
			hebing2(i);
			return ;
		}
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&nei[i].start,&nei[i].end);
		nei[i].bing=i;
		nei[i].fangwen=0;
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&wai[i].start,&wai[i].end);
		wai[i].bing=i;
		wai[i].fangwen=0;
	}
	sort(nei+1,nei+1+m1,cmp);
	sort(wai+1,wai+1+m2,cmp);
	for(int i=1;i<=m1;i++){
		if(nei[i].fangwen==0){
			cnt1++;
			nei[i].fangwen=1;
			nei[i].bing=cnt1;
			qianzhuihe_nei[cnt1]++;
			hebing1(i);
		}
	}
	for(int i=1;i<=m2;i++){
		if(wai[i].fangwen==0){
			cnt2++;
			wai[i].fangwen=1;
			wai[i].bing=cnt2;
			qianzhuihe_wai[cnt2]++;
			hebing2(i);
		}
	}
	for(int i=1;i<=n;i++){
		qianzhuihe_nei[i]+=qianzhuihe_nei[i-1];
	}
	for(int i=1;i<=n;i++){
		qianzhuihe_wai[i]+=qianzhuihe_wai[i-1];
	}
	int ma=-1;
	if(cnt1+cnt2<=n){
		printf("%d",m1+m2);
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(ma<qianzhuihe_nei[i]+qianzhuihe_wai[n-i]){
			ma=qianzhuihe_nei[i]+qianzhuihe_wai[n-i];
		}
	}
	printf("%d",ma);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
