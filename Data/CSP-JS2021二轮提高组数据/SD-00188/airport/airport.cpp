#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
//CSP 2021 RP++!
void file(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
}
const int N=1e5+5;
struct node{
	int l,r;
};
node a[N],b[N];
int ua[N],ub[N];
int n,m1,m2;
int f,ans=0,cnt;
int cmp(node a,node b){
	return a.l<b.l?1:0;
}
int com(int d){
		f=0;
		cnt=0;
		memset(ua,0,sizeof(ua));
		memset(ub,0,sizeof(ub));
		for(int j=1;j<=m1;j++){
			for(int k=1;k<j;k++){
				if(ua[k]&&a[k].r<a[j].l){
					ua[k]=0;
					f--;
				}
			}
			if(f==d){
				ua[j]=0;
			}
			else{
				f++;
				cnt++;
				ua[j]=1;
			}
		}
		f=0;
		for(int j=1;j<=m2;j++){
			for(int k=1;k<j;k++){
				if(ub[k]&&b[k].r<b[j].l){
					ub[k]=0;
					f--;
				}
			}
			if(f==(n-d)){
				ub[j]=0;
			}
			else{
				f++;
				cnt++;
				ub[j]=1;
			}
		}
		return cnt;
}
int main(){
	file();
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a[i].l>>a[i].r;
	}
	for(int i=1;i<=m2;i++){
		cin>>b[i].l>>b[i].r;
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
//	int l=0,r=n,ls=n/3,rs=n*2/3;
//	while(1){
//		ls=l+(r-l)/3;
//		rs=l+(2*r-2*l)/3;
//		int sl=com(l),sr=com(r);
//		if(sl>sr){
//			r=rs;
//		}
//		else l=ls;
//		if(abs(l-r)<=10){
//			break;
//		}
//	}
	for(int i=1;i<=n;i++){
		ans=max(ans,com(i));
		//cout<<com(i)<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
/*
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
//20 pts
