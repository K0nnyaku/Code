#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int A,num;
	bool B;
	const bool operator < (const Node &other)const{
		return A<other.A;
	}
}Arr[200005];
int N,M1,M2,val[100005],cnt1[100005],cnt2[100005],ans;
priority_queue<int,vector<int>,greater<int> > Q;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&N,&M1,&M2);
	for(int i=1;i<=M1;++i){
		scanf("%d%d",&Arr[i].A,&Arr[i+M1].A);
		Arr[i].B=false,Arr[i+M1].B=true,Arr[i].num=i,Arr[i+M1].num=i;
	}
	M1<<=1;
	sort(Arr+1,Arr+M1+1);
	for(int i=1,idx,tot=0;i<=M1;++i){
		idx=Arr[i].num;
		if(Arr[i].B){
			Q.push(val[idx]);
		}else{
			if(Q.size()){
				val[idx]=Q.top();
				Q.pop();
			}else{
				val[idx]=++tot;
			}
			++cnt1[val[idx]];
		}
	}
	while(Q.size()) Q.pop();
	memset(Arr,0,sizeof(Arr));
	memset(val,0,sizeof(val));
	for(int i=1;i<=M2;++i){
		scanf("%d%d",&Arr[i].A,&Arr[i+M2].A);
		Arr[i].B=false,Arr[i+M2].B=true,Arr[i].num=i,Arr[i+M2].num=i;
	}
	M2<<=1;
	sort(Arr+1,Arr+M2+1);
	for(int i=1,idx,tot=0;i<=M2;++i){
		idx=Arr[i].num;
		if(Arr[i].B){
			Q.push(val[idx]);
		}else{
			if(Q.size()){
				val[idx]=Q.top();
				Q.pop();
			}else{
				val[idx]=++tot;
			}
			++cnt2[val[idx]];
		}
	}
	for(int i=1;i<=N;++i){
		cnt1[i]+=cnt1[i-1];
		cnt2[i]+=cnt2[i-1];
	}
	for(int i=0;i<=N;++i){
		ans=max(ans,cnt2[i]+cnt1[N-i]);
	}
	printf("%d",ans);
	return 0;
}
