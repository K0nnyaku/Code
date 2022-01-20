#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue> 
#define maxn 100005
using namespace std;
int n,m,s,ans=-1;
int shuyi[maxn],shuer[maxn];
int minyi[maxn],miner[maxn];
struct node{
	int kai,jie;
}nei[maxn],wai[maxn];
int sumyi=1,sumer=1;
void jiaruyi(int x){
	int k=0;
	if(x==1){
		shuyi[1]++;
		minyi[1]=nei[1].jie;
		return ;
	}
	for(int i=1;i<=sumyi;i++){
		if(nei[x].kai>minyi[i]){
			shuyi[i]++;
			k=1;
			minyi[i]=nei[x].jie;
			return;
		}
	}
	if(!k&&sumyi<n){
		sumyi++;
		shuyi[sumyi]++;
		minyi[sumyi]=nei[x].jie;
		return ;
	}
}
void jiaruer(int x){
	int k=0;
	if(x==1){
		shuer[1]++;
		miner[1]=wai[1].jie;
		return ;
	}
	for(int i=1;i<=sumer;i++){
		if(wai[x].kai>miner[i]){
			shuer[i]++;
			k=1;
			miner[i]=wai[x].jie;
			return;
		}
	}
	if(!k&&sumer<n){
		sumer++;
		shuer[sumer]++;
		miner[sumer]=wai[x].jie;
		return;
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m,&s);
	memset(shuyi,0,sizeof(shuyi));
	memset(shuer,0,sizeof(shuer));
	for(int i=1;i<=m;i++){
		scanf("%d%d",&nei[i].kai,&nei[i].jie);
		jiaruyi(i);
	}
	for(int i=1;i<=s;i++){
		scanf("%d%d",&wai[i].kai,&wai[i].jie);
		jiaruer(i);
	}
	for(int i=0;i<=n;i++){
		int j=n-i;
		int q=0,p=0;
		if(i>0){
		for(int k=1;k<=i;k++){
			q+=shuyi[k];
		}
			}
		if(j>0){
		for(int k=1;k<=j;k++){
			p+=shuer[k];
		}
		}
		ans=max(p+q,ans);
	}
		cout<<ans;

//	cout<<sumyi<<endl;
//	cout<<shuyi[1]<<endl;
//	cout<<minyi[1];	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
