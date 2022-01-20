#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
int r1=-1,r2=-1,ans=0;
struct node{
	int st,fi;
	int ji,im;
}a[200005],le[100005];
bool cmp1(const node &x,const node &y){
	return x.st<y.st;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a[i].st>>a[i].fi;
		a[i].ji=0;//0国内 
	}
	for(int j=1;j<=m2;j++){
		cin>>a[j].st>>a[j].fi;
		a[j].ji=1;//1国外 
	}
	sort(a+1,a+1+m1+m2,cmp1);
	int l=n;
	for(int i=1;i<=m1+m2;i++){
		if(a[i].ji==0){
			if(r1<a[i].st&&l>0){
				r1=a[i].st;
				l--;
				a[i].ji=-1;
				ans++;
				le[ans].st=a[i].st;
				le[ans].fi=a[i].fi;
				continue;
			}
		}else if(a[i].ji==1&&l>0){
			if(r2<a[i].st){
				r2=a[i].st;
				l--;
				a[i].ji=-1;
				ans++;
				continue;
			}
		}
	}
	if(l>0){
		for(int i=1;i<=m1+m2;i++){
			if(a[i].ji!=-1){
				l--;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
