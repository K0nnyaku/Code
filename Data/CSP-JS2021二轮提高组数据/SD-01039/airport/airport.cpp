#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<iostream>
#include<set>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int n,m1,m2,sum,num,ans,L,M,x,X,y,Y;
int a[100001],A[100001];
int main(){
freopen("airport.in","r",stdin);
freopen("airport.out","w",stdout);
cin>>n>>m1>>m2;
int b[m1+1][3],c[m2+1][3];
for(int i=1;i<=m1;i++){for(int j=1;j<=2;j++) cin>>b[i][j];}
for(int i=1;i<=m2;i++){for(int j=1;j<=2;j++) cin>>c[i][j];}
for(int i=0;i<=n;i++){
for(x=1;x<=m1;x++) {if(i==0) break; for(X=1;X<=i ;X++){
if(b[x][1]>a[X]){a[X]=b[x][2];sum++;break;}}}
for(y=1;y<=m2;y++) {if(i==n) break; for(Y=1;Y<=n-i;Y++){
if(c[y][1]>A[Y]){A[Y]=c[y][2];num++;break;}}}
if(ans<num+sum)
ans=sum+num;
for(L=i;L>=1;L--){
	a[L]=0;
}
for(M=n-i;M>=1;M--){
	A[M]=0;
}
num=0;
sum=0;
}
cout<<ans<<endl;
fclose(stdin);
fclose(stdout);
	return 0;
}


