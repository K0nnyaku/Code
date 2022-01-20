#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m1,m2;
int arr,lea;
int cnt;
int deb,inb;
int ans=0;
int num;
bool leave[100000003]={0};
struct sch{
	bool typ;
	int tim;
	int leavetime;
	
};
sch demo[100003],inte[100003];
bool cmp(sch x,sch y){
	return x.tim<y.tim;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);	
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>arr>>lea;
		demo[2*i-1].typ=0;
		demo[2*i-1].tim=arr;
		demo[2*i-1].leavetime=lea;
		demo[2*i].typ=1;
		demo[2*i].tim=lea;
	}
	sort(demo+1,demo+2*m1+1,cmp);
	
	for(int i=1;i<=m2;i++){
		cin>>arr>>lea;
		inte[2*i-1].typ=0;
		inte[2*i-1].tim=arr;
		inte[2*i-1].leavetime=lea;
		inte[2*i].typ=1;
		inte[2*i].tim=lea;
	}
	sort(inte+1,inte+2*m2+1,cmp);
	for(int i=0;i<=n;i++){
		num=0;
		if(i==0){
			inb=n;
			for(int j=1;j<=2*m2;j++){
				if(inte[j].typ==0){
					if(inb>0){
						inb--;
						leave[inte[j].leavetime]=1;
						num++;
					}
				}
				else{
					if(leave[inte[j].tim]){
						inb++;
						leave[inte[j].tim]=0;
					}
				}
			}
			ans=max(num,ans);
		}
		else{
			if(i==n){
				deb=n;
			for(int j=1;j<=2*m1;j++){
				if(demo[j].typ==0){
					if(deb>0){
						deb--;
						leave[demo[j].leavetime]=1;
						num++;
					}
				}
				else{
					if(leave[demo[j].tim]){
						deb++;
						leave[demo[j].tim]=0;
					}
				}
			}
			ans=max(num,ans);
			}
			else{
				deb=i;
				inb=n-i;
				
				for(int j=1;j<=2*m1;j++){
				if(demo[j].typ==0){
					if(deb>0){
						deb--;
						leave[demo[j].leavetime]=1;
						num++;
					}
				}
				else{
					if(leave[demo[j].tim]){
						deb++;
						leave[demo[j].tim]=0;
					}
				}
			}
			for(int j=1;j<=2*m2;j++){
				if(inte[j].typ==0){
					if(inb>0){
						inb--;
						leave[inte[j].leavetime]=1;
						num++;
					}
				}
				else{
					if(leave[inte[j].tim]){
						inb++;
						leave[inte[j].tim]=0;
					}
				}
			}
			ans=max(num,ans);
			}
		}
	}
	cout<<ans;
	return 0;
}
