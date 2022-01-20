#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const int N=1e5+10,M=1e5+5;
int n,m1,m2,go1[N],go2[N],ans=0;
priority_queue<int,vector<int>,greater<int> >qfet;//queue for endtime;
struct timelenth{
	int begin;
	int endtime;
}inp[M],oup[M];
bool cmp(const timelenth &x,const timelenth &y){
	return x.begin<y.begin;
}
inline void qclear(){
	while(!qfet.empty()) qfet.pop();
}
int cal1(int num){
	if(num>=m1) return m1;
	int cnt=num;
	for(int i=1;i<=num;i++) qfet.push(inp[i].endtime);
	for(int i=(num+1);i<=m1;i++){
		if(inp[i].begin>qfet.top()){
			cnt++;
			qfet.pop();
			qfet.push(inp[i].endtime);
		}
	}
	return cnt;
}
int cal2(int num){
	if(num>=m2) return m2;
	int cnt=num;
	for(int i=1;i<=num;i++) qfet.push(oup[i].endtime);
	for(int i=(num+1);i<=m2;i++){
		if(oup[i].begin>qfet.top()){
			cnt++;
			qfet.pop();
			qfet.push(oup[i].endtime);
		}
	}
	return cnt;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		int s,e;
		scanf("%d%d",&s,&e);
		inp[i]=(timelenth){s,e};
	}
	sort(inp+1,inp+1+m1,cmp);
	for(int i=1;i<=m2;i++){
		int s,e;
		scanf("%d%d",&s,&e);
		oup[i]=(timelenth){s,e};
	}
	sort(oup+1,oup+1+m2,cmp);
	go1[0]=0,go2[n]=0;
	for(int k=1;k<=n;k++){
		qclear();
		go1[k]=cal1(k);
		if(go1[k]==m1){
			for(int i=(k+1);i<=n;i++){
				go1[i]=m1;
			}
			break;
		}
	}
	for(int k=1;k<=n;k++){
		qclear();
		go2[n-k]=cal2(k);
		if(go2[n-k]==m2){
			for(int i=(k+1);i<=n;i++){
				go2[n-i]=m2;
			}
			break;
		}
	}
	for(register int i=0;i<=n;i++){
//		printf("%d %d\n",go1[i],go2[i]);
		ans=max(ans,go1[i]+go2[i]);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
