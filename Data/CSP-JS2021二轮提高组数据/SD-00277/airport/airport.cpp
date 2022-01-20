#include<bits/stdc++.h>
using namespace std;
struct node1{
	int sta,en;
}nat[100101];
struct node2{
	int sta,en;
}innat[100101];
bool cmp1(node1 a,node1 b){
	return a.sta<b.sta;
}
bool cmp2(node2 a,node2 b){
	return a.sta<b.sta;
}
int n,m,mm,tot_one,tot_two,now_one,now_two,zd1[100101],zd2[100101],nn=1,biao=1;
int ans;
bool vis1[100101],vis2[100101];
int pan1,pan2;

int main() {

	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m>>mm;
	for(int i=1;i<=m;i++){
		cin>>nat[i].sta>>nat[i].en;
	}
	for(int i=1;i<=mm;i++){
		cin>>innat[i].sta>>innat[i].en;
	}
	sort(nat+1,nat+m+1,cmp1);
	sort(innat+1,innat+mm+1,cmp2);
	for(int i=1;i<=m;i++){
		if(!vis1[i]){
			pan1=nat[i].en;
			vis1[i]=true;
			tot_one++;
			for(int j=i;j<=m;j++){
				if(nat[j].sta>pan1&&!vis1[j]){
					pan1=nat[j].en;
					vis1[j]=true;
					tot_one++; 
				}
			}
			zd1[++now_one]=tot_one;
			tot_one=0;
		}
	}
	for(int i=1;i<=mm;i++){
		if(!vis2[i]){
			pan2=innat[i].en;
			vis2[i]=true;
			tot_two++;
			for(int j=i;j<=mm;j++){
				if(innat[j].sta>pan2&&!vis2[j]){
					pan2=innat[j].en;
					vis2[j]=true;
					tot_two++;
				}
			}
			zd2[++now_two]=tot_two;
			tot_two=0;
		}
	}

	if(now_one<=now_two){
		for(int i=1;i<=now_one;i++){
			if(nn<=n){
				if(zd1[i]>zd2[biao]){
					ans+=zd1[i];
				}else if(zd1[i]<=zd2[biao]){
					ans+=zd2[biao];
					biao++;
					i-=1;
				}
			}else{
				break;
			}
			nn++;
		}
		if(nn<=n){
			for(int i=biao;i<=now_two;i++){
				if(nn<=n){
					ans+=zd2[i];
				}else{
					break;
				}
				nn++;
			} 
		}
	}else if(now_one>now_two){
		for(int i=1;i<=now_two;i++){
			if(nn<=n){
				if(zd2[i]>zd1[biao]){
					ans+=zd2[i];
				}else if(zd2[i]<=zd1[biao]){
					ans+=zd1[biao];
					biao++;
					i-=1;
				}
			}else{
				break;
			}
			nn++;
		}
		if(nn<=n){
			for(int i=biao;i<=now_one;i++){
				if(nn<=n){
					ans+=zd1[i];
				}else{
					break;
				}
				nn++;
			} 
		}
	}
	cout<<ans<<endl;

	return 0;
}
