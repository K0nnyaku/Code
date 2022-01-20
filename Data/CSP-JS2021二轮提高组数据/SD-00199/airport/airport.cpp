#include<bits/stdc++.h>
using namespace std;
int m1,m2,ml1,ml2;
int sum,maxm;
int tim1[100000001],tim2[100000001],temp;
bool que1[100000],que2[100000];
void cal(int n,int b){
	if(n==0)return;
	int t=-1;
	if(b==1){
		while(1){
			t++;
			//if(tim1[t]==0)continue;
			if(tim1[t]>0&&n>0){
				n--;sum++;
				que1[tim1[t]]=1;
			}
			if(tim1[t]<0&&que1[0-tim1[t]]==1){
				que1[0-tim1[t]]=0;
				n++;
			}
			if(t==ml1)break;
		}
		
	}
	if(b==2){
		while(1){
			t++;
			//if(tim2[t]==0)continue;
			if(tim2[t]>0&&n>0){
				n--;sum++;
				que2[tim2[t]]=1;
			}
			if(tim2[t]<0&&que2[0-tim2[t]]==1){
				que2[0-tim2[t]]=0;
				n++;
			}
			if(t==ml2)break;
		}
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n;
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d",&temp);
		tim1[temp]=i;
		scanf("%d",&temp);
		tim1[temp]=-i;
		ml1=max(ml1,temp);
	}
	int t=0;
	for(int i=0;i<=ml1;i++){
		if(tim1[i]==0)continue;
		tim1[t]=tim1[i];
		t++;
	}
	ml1=t;
	for(int i=1;i<=m2;i++){
		scanf("%d",&temp);
		tim2[temp]=i;
		scanf("%d",&temp);
		tim2[temp]=-i;
		ml2=max(ml2,temp);
	}
	t=0;
	for(int i=0;i<=ml2;i++){
		if(tim2[i]==0)continue;
		tim2[t]=tim2[i];
		t++;
	}
	ml2=t;
	for(int i=0;i<=n;i++){
		cal(i,1);
		cal(n-i,2);
		maxm=max(sum,maxm);
		sum=0;
	}
	cout<<maxm;
	return 0;
} 
