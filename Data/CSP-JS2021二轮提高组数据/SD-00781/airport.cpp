#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int ans;
struct aa{
	int x,y;
}a[200000];
struct bb{
	int x,y;
}b[200000];
int main(){
freopen("airport.in",r,stdio);
freopen("airport.out",w,stdio);
int s,n,m;
cin>>s>>n>>m;
for(int i=0;i<n;i++){
	scanf("%d%d",&a[i].x,&a[i].y);
}
for(int i=0;i<m;i++){
	scanf("%d%d",&b[i].x,&b[i].y);
}
cout<<s;
/*for(int i=0;i<n;i++){
	for(int j=i;j<n;j++){
		if(a[i].y<a[j].y) {
			swap(a[i].x,a[j].x); 
			swap(a[i].y,a[j].y); 
		}
		else if(a[i].y==a[j].y){
			if(a[i].y-a[i].x>a[j].y-a[j].x){
				swap(a[i].x,a[j].x); 
				swap(a[i].y,a[j].y); 
			}
		}
	}
}*/



/*for(int i=0;i<n;i++){
	for(int j=i;j<n;j++){
		if(b[i].y<b[j].y) swap(b[i],b[j]); 
	}
}
*/


}
