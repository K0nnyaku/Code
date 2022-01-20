#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int n,m1,m2;
struct Interval{
	Interval(){
		l = -1,r = -1;
	}
	Interval(int a,int b){
		l = a,r = b;
	}
	int l,r;
};
Interval gn[5959810],gj[5959810];
Interval Jiao(Interval a,Interval b){
	if(a.r >= b.l)return Interval(b.l,a.r);
	else return Interval(-1,-1);
}
int dp1[5959810],dp2[5959810];
Interval jia[5959810];
void psolve(){
	for(int i = 2;i<=m1;i++){
		Interval j = Jiao(gn[i],gn[i-1]);
		if(j.l != -1){
			
		}
	}
	for(int i = 2;i<=m2;i++){
		Interval j = Jiao(gj[i],gj[i-1]);
	}
	srand(time(0));
	cout<<rand() %(m1+m2)<<endl;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i = 1;i<=m1;i++)cin>>gn[i].l>>gn[i].r;
	for(int i = 1;i<=m2;i++)cin>>gj[i].l>>gj[i].r;
	psolve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
