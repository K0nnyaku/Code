#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;

int n,m1,m2,ans = 0;

struct Airp{
	int beg,end;
};
Airp guonei[100005],guoji[100005];

bool cmp(Airp a,Airp b){
	return a.beg < b.beg;
}

Airp qiao[100005];
bool yes_1[100005],yes_2[100005];
int main(){
   freopen("airport.in","r",stdin);
   freopen("airport.out","w",stdout);
   cin>>n>>m1>>m2;
   for(int i=1;i<=m1;i++){
   	cin>>guonei[i].beg>>guonei[i].end;
   }
   for(int i=1;i<=m2;i++){
   	cin>>guoji[i].beg>>guoji[i].end;
   }
   sort(guonei+1,guonei+m1+1,cmp);
   sort(guoji+1,guoji+m2+1,cmp);//输入无误  
   
   for(int g=0;g<=n;g++){
   	int cnt_1=0,cnt_2=0;
   for(int i=1;i<=g;i++){//模拟廊桥编号
      for(int j=1;j<=m1;j++){//模拟国内机编号
	       if(yes_1[j] == 0){
		   if(j == 1){
	       	qiao[1].beg = guonei[1].beg;
	       	qiao[1].end = guonei[1].end;
	       	cnt_1++;
	       	yes_1[1] = 1;
	       	continue;
		   }
		   else if(qiao[i].end > guonei[j].beg){
		   	continue;
		   }
		   else if(qiao[i].end < guonei[j].beg){
		   	qiao[i].beg = guonei[j].beg;
		   	qiao[i].end = guonei[j].end;
		   	cnt_1++;
		   	yes_1[j] = 1;
		   	continue;
		   }
		   }
	  }
	  } 
      for(int p=g+1;p<=n;p++){//模拟廊桥编号i
      for(int q=1;q<=m2;q++){//模拟国际机编号j
	       if(yes_2[q] == 0){
		   if(q == 1){
	       	qiao[1].beg = guoji[1].beg;
	       	qiao[1].end = guoji[1].end;
	       	cnt_2++;
	       	yes_2[1] = 1;
	       	continue;
		   }
		   else if(qiao[p].end > guoji[q].beg){
		   	continue;
		   }
		   else if(qiao[p].end < guoji[q].beg){
		   	qiao[p].beg = guoji[q].beg;
		   	qiao[p].end = guoji[q].end;
		   	cnt_2++;
		   	yes_2[q] = 1;
		   	continue;
		   }
		   }
	  } 
   }
      ans = max(ans,cnt_1+cnt_2);
   } 
   cout<<ans<<endl;
   return 0;
}

