#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
using namespace std;
#define ss 100001
int n,n1=-1,n2=0,n11[ss]={0},n22[ss]={0},m1,m2,a1[ss]={0},b1[ss]={0},a2[ss]={0},b2[ss]={0},res=0,ans=0;
int des1=0,des2=0;
void nit()
{
	for(int i=1;i<=m1;i++)
	   n11[i]=-1;
	for(int i=1;i<=m2;i++)
	   n22[i]=-1;
}
void input()
{
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	   cin>>a1[i]>>b1[i];
	for(int i=1;i<=m2;i++)
	   cin>>a2[i]>>b2[i];
	if(n==m1+m2) {res=n;}
}
void pai()
{
	for(int i=1;i<=m1;i++)
	   for(int j=i;j<=m1;j++)
	      if(a1[i]>a1[j]) {swap(a1[i],a1[j]);swap(b1[i],b1[j]);}
	for(int i=1;i<=m2;i++)
	   for(int j=i;j<=m2;j++)
	      if(a2[i]>a2[j]) {swap(a2[i],a2[j]);swap(b2[i],b2[j]);}
	int max=b1[1];
	for(int i=2;i<=m1;i++)
	    if(max<b1[i])  max=b1[i];
	    des1=max;
	max=b2[1];
	for(int i=2;i<=m2;i++)
	   if(max<b2[i]) max=b2[i];
	des2=max;

}
void act()
{
int count=1;
	for(int time=1;time<=des1;time++)
	    if(count<=m1){ 
	   for(int lian=1;lian<=n1;lian++) if(n11[lian]==time) {n11[lian]=-1;}
	   if(a1[count]==time) {bool k=false;for(int lian=1;lian<=n1;lian++) if(n11[lian]==-1) {n11[lian]=b1[count];k=true;count++;ans++;break;}if(k==false) count++;}
	   } 
	
int num=1;
    for(int time=1;time<=des2;time++)
	   if(num<=m2){ 
	   for(int lian=1;lian<=n2;lian++) if(n22[lian]==time) {n22[lian]=-1;}
	   if(a2[num]==time)  {bool k=false;for(int lian=1;lian<=n2;lian++) if(n22[lian]==-1) {n22[lian]=b2[num];k=true;num++;ans++;break;}  if(k==false) num++;}
	   }}
void output()
{
	cout<<res<<endl;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	input();
	if(res==n) output();
	else {pai();
	for(int i=0;i<=n;i++)
	   {n1=i;n2=n-i;ans=0;nit();
	   act();if(res<ans) {res=ans;}
	   }
	output();}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
