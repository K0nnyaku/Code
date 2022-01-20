#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n,m1,m2;
priority_queue<int,vector<int>,greater<int> >gn;
priority_queue<int,vector<int>,greater<int> >gw;
struct qwq{
	int kaishi,jieshu,guo;
}qaq[100005];
int ans=0,mans=0;
bool cmp(qwq a,qwq b){
	return a.kaishi<b.kaishi;
}
int main(){
//	a.push(1);
//	a.push(2);
//	cout<<a.top();
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=0;i<m1+m2;i++){
		if(i<m1)qaq[i].guo=0;
		else qaq[i].guo=1;
		scanf("%d%d",&qaq[i].kaishi,&qaq[i].jieshu);
	}
	sort(qaq,qaq+m1+m2,cmp);
	for(int i=0;i<=n;i++){
		int guonei=i,guoji=n-i;
		for(int j=0;j<m1+m2;j++){
			
			if(qaq[j].guo==0){
				
				while(!gn.empty()&&gn.top()<qaq[j].kaishi){
					gn.pop();
					guonei++;
				}
				if(guonei==0)continue;
				else{
					guonei--;
					ans++;
					gn.push(qaq[j].jieshu);
				}
			}else{
				
				while(!gw.empty()&&gw.top()<qaq[j].kaishi){
					gw.pop();
					guoji++;
				}
				if(guoji==0)continue;
				else{
					guoji--;
					ans++;
					gw.push(qaq[j].jieshu);
				}	
			}
		}
	//	cout<<ans<<" ";
		mans=max(mans,ans);
		ans=0;
		while(!gn.empty())gn.pop();
		while(!gw.empty())gw.pop();
	}
	cout<<mans;
	//This .cpp file is blessed by the one and only true god,Huajige.
	//This .cpp file is blessed by cincoutcerrclog,the godly-ben of godly-bens.
	//This .cpp file is blessed by wangzhi05,the godly-ben of sleeping.
	//This .cpp file is blessed by etsger,the godly-ben of fantastic hands.
	//This .cpp file is blessed by LTY,the godly-ben of gays.
	//This .cpp file is blessed by mensanjin,the godly-ben of cuteness.
	//This .cpp file is blessed by shaibai,the godly-ben of bad hands.
	//This .cpp file is blessed by SPJ,the godly-ben of soft eggs.
	//This .cpp file is blessed by sendiago,the godly-ben of diyaing.
	//With their blessings,I shall get the first prise of CSP-S 2021.
	//written by syko_canir84,the godly-ben of true hands.
	return 0;
}
//3 5 4
//1 5
//3 8
//6 10
//9 14
//13 18
//2 11
//4 15
//7 17
//12 16

//2 4 6
//20 30
//40 50
//21 22
//41 42
//1 19
//2 18
//3 4
//5 6
//7 8
//9 10

