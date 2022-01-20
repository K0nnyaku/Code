#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,n1,n2,m1,m2,s=0,s2=0,t[10001],t2[10001],t3,t4;
	cin>>n>>m1>>m2;
	int a1[10001]={0},b1[10001]={0},a2[10001]={0},b2[10001]={0};
	for(int i=0;i<m1;i++){
		cin>>a1[i]>>b1[i];
	} 
	for(int i=0;i<m2;i++){
		cin>>a2[i]>>b2[i];
	}
	for(int i=0;i<10001;i++){
		t[i]=t2[i]=100001;
	}
	for(int i=0;i<=n;i++){
		s=0;
		n1=i;
		n2=n-i;
		if(n1>0)
		for(int j=0;j<m1;j++){
			if(n1>0){
				n1--;
				s++;
				t[j]=b1[j];
			}else
			for(int x=0;x<m1;x++)
			if(n1==0&&a1[j]>t[x]){
				s++;
				t[x]=100000;
				n1++;
				t[j]=b1[j];
				}
		}
		if(n2>0)
		for(int z=0;z<m2;z++){
			if(n2>0){
				n2--;
				s++;
				t2[z]=b2[z];
			}else
			for(int y=0;y<m2;y++)
			if(n2==0&&a2[z]>t2[y]){
				s++;
				t2[y]=100000;
				n2++;
				t2[z]=b2[z];
				}
		}
		if(s>s2)
		s2=s;
	}
	cout<<s2;
	return 0;
 } 
