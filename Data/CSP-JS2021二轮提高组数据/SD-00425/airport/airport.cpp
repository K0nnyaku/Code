#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m1,m2;
long long ans;
struct node1{
	int h,t,sum,flag;
}a[100001];
struct node{
	int h,t;
}aaa[100001];
bool cmp(node x,node y){
	return x.h<y.h;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	int xxx,yyy,num=1;
	for(int i=1;i<=m1+m2;i++){
		cin>>aaa[i].h>>aaa[i].t;
	}
	sort(aaa+1,aaa+m1+1,cmp);
	sort(aaa+1+m1,aaa+1+m1+m2,cmp);
	for(int i=1;i<=m1;i++){
		xxx=aaa[i].h;
		yyy=aaa[i].t;
		int fff=-1;
		for(int j=num;j>0;j--){
			if(xxx>a[j].t){
				a[j].h=xxx; 
				a[j].t=yyy;
				a[j].sum++;
				fff=1;
				break ;
			}
			
		}
		if(fff==-1) {
			num++;
			a[num].h=xxx; 
			a[num].t=yyy;
			a[num].sum++;
			a[num].flag=1;
		}
		
	}
	num++;
	int jjj=num;
	a[num].h=aaa[m1+1].h; a[num].t=aaa[m1+1].t;
	a[num].sum++; a[num].flag=2;
	for(int i=m1+2;i<=m1+m2;i++){
		xxx=aaa[i].h;
		yyy=aaa[i].t;
		int fff=-1;
		for(int j=jjj;j<=num;j++){
			if(xxx>a[j].t){
				a[j].h=xxx; 
				a[j].t=yyy;
				a[j].sum++;
				fff=1;
				break ;
			}
		
		}
		if(fff==-1){
			num++;
			a[num].h=xxx;
			a[num].t=yyy;
			a[num].sum++;
			a[num].flag=2;
		}
	}
	int i=1,j=jjj;
	while(n){
		n--;
		if(a[i].sum>=a[j].sum){
			ans+=a[i].sum;
			i++;
		}
		else {
			ans+=a[j].sum;
			j++;
		}
	}
	cout<<ans<<endl; 
	return 0;
}

