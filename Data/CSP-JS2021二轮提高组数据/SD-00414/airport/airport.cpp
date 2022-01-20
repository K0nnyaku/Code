#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int n,m1,m2,ans,vis1[N],vis2[N];
struct node{
	int x,y;
}a1[N],a2[N];
bool cmp(node a,node b){return a.x<b.x;}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a1[i].x,&a1[i].y);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&a2[i].x,&a2[i].y);
	}
	sort(a1+1,a1+1+m1,cmp);
	sort(a2+1,a2+1+m2,cmp);
	for(int i=0;i<=n;i++){
		int l=i,k1,k2,ans1=0,ans2=0,r=n-i;
		for(int i=0;i<=m1;i++)vis1[i]=0;
		for(int i=0;i<=m2;i++)vis2[i]=0;
		for(int j=1;j<=m1;j++){
			if((l==0)&&(j==1))break;
			int min1=0x3f3f3f3f;
			int num1=0;
			for(int k=1;k<=j-1;k++){
				if((!vis1[k])&&(a1[k].y<min1))num1=k,min1=a1[k].y;
			}
			if(min1<a1[j].x){
				ans1++;
				vis1[num1]=1;
			}
			if(min1>a1[j].x){
				if(l>0){
					l--;
					ans1++;
				}
				else {
					vis1[j]=1;
				}
			}
		}
		for(int j=1;j<=m2;j++){
			if((r==0)&&(j==1))break;
			int min2=0x3f3f3f3f;
			int num2;
			for(int k=1;k<j;k++){
				if(!vis2[k]&&a2[k].y<min2)num2=k,min2=a2[k].y;
			}
			if(min2<a2[j].x){
				ans2++;
				vis2[num2]=1;
			}
			if(min2>a2[j].x){
				if(r>0){
					r--;
					ans2++;
				}
				else {
					vis2[j]=1;
				}
			}
		}
		ans=max(ans,ans1+ans2);
	}
	cout<<ans;
	return 0;
}
