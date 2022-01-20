#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int n,m1,m2;
struct node{
	int l,r;
};
node din[100010];
node dout[100010];
bool cmp(node a,node b){
	return a.l <b.l ;
}
int count_in,count_out,vcnt,vin,vout,ans=-10000;
bool flag_in,flag_out;

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>din[i].l >> din[i].r ; 
	}
	for(int i=1;i<=m2;i++){
		cin>>dout[i].l>>dout[i].r ;
	}
	
	sort(din+1,din+1+m1,cmp);
	sort(dout+1,dout+1+m2,cmp);
	
	for(int i=0;i<=n;i++){
		vin=i;vout=n-i;
		priority_queue<int,vector<int>,greater<int> > q;
        priority_queue<int,vector<int>,greater<int> > q1;
		flag_in=false;flag_out=false;
		count_in=0;count_out=0;
		vcnt=0;	
			
		if(vin==0){
			count_in=0;
			flag_in=true;
		}
		if(vin>=m1){
			count_in=m1;
			flag_in=true;
		}
		if(vout==0){
			count_out=0;
			flag_out=true;
		}
		if(vout>=m2){
			count_out=m2;
			flag_out=true;
		}
			
		for(int j=1;j<=m1;j++){
			if(flag_in){
				break;
			}
			int now=0;
			if(!q.empty()){
				now=q.top();
			}
			if(vcnt<vin){
				count_in++;
				q.push(din[j].r);
				vcnt++;
			}else{
				if(now<=din[j].l){
					q.pop();
					q.push(din[j].r);
					count_in++;
				}else{
					continue;
				}
			}
		}				
		vcnt=0;
		for(int j=1;j<=m2;j++){
			if(flag_out){
				break;
			}
			int now=0;
			if(!q1.empty()){
				now=q1.top();
			}
			if(vcnt<vout){
				count_out++;
				q1.push(dout[j].r);
				vcnt++;
			}else{
				if(now<=dout[j].l){
					q1.pop();
					q1.push(dout[j].r);
					count_out++;
				}else{
					continue;
				}
			}
		}
		
		ans=max(ans,count_in+count_out);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
