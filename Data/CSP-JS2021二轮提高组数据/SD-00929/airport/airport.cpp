#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m1,m2;
struct PL{
	int ar;
	int le;
};
PL pl1[100005],pl2[100005];
bool cmp(PL A,PL B){
	return A.ar<B.ar;
}
int x,y;
struct LOT{
	bool empty=1;
	int end;
};
int  Try(int la,int lb){
	int sum=0;
	LOT l1[la+1],l2[lb+1];
	if(la!=0){
		for(int i=1;i<=m1;i++){
			int a=0;
			while(a<la){
				if(l1[a].empty||l1[a].end<pl1[i].ar){
					sum++;
					l1[a].empty=0;
					l1[a].end=pl1[i].le;
					break;
				}
				a++;
			}
		}
	}
	if(lb!=0){
		for(int i=1;i<=m2;i++){
			int b=0;
			while(b<lb){
				if(l2[b].empty||l2[b].end<pl2[i].ar){
					sum++;
					l2[b].empty=0;
					l2[b].end=pl2[i].le;
					break;
				}
				b++;
			}
		}
	}
	return sum;
}
int main(){
 	freopen("airport.in","r",stdin);
  	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>pl1[i].ar>>pl1[i].le;
	}
	for(int i=1;i<=m2;i++){
		cin>>pl2[i].ar>>pl2[i].le;
	}
	sort(pl1,pl1+m1,cmp);
	sort(pl2,pl2+m2,cmp);
	int max=0;
	for(int i=0;i<=n;i++){
		int result=Try(i,n-i);
		if(max<result){
			max=result;
		}
	}
	cout<<max;
	return 0;
}
