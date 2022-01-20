#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring> 
using namespace std;
struct ss{
	long long  s,e,f;
}g1[100003],g2[100003],g3[100003],g4[100003];
long long n,m1,m2,a1,a2,b1,b2;long long x=1,ans1=0,maxx=0;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int k=1;k<=m1;k++){
		cin>>a1>>b1;x=max(x,b1);g1[a1].s=1;g1[a1].e=b1;g1[b1].f=1;
	}
	for(int k=1;k<=m2;k++){
		cin>>a2>>b2;x=max(x,b2);g2[a2].s=1;g2[a2].e=b2;g2[b2].f=1;
	}
	for(int j=0;j<=n;j++){
		for(int i=1;i<=x;i++){
			g3[i].s=g1[i].s;g3[i].e=g1[i].e;g3[i].f=g1[i].f;
	}
		for(int i=1;i<=x;i++){
			g4[i].s=g2[i].s;g4[i].e=g2[i].e;g4[i].f=g2[i].f;
	}
		int p=j,q=n-j;
		for(int i=1;i<=x;i++){
			if(j>0){
				if(g3[i].f==1){
			p++;
		} 
		if(g3[i].s==1&&p<=0){
		    g3[g3[i].e].f=0; 
		}   
		    if(g3[i].s==1&&p>0){
			p--;ans1++;
		}
			}
		if(n-j>0){
			    if(g4[i].f==1){
			q++;
		} 
		if(g4[i].s==1&&q<=0){
		    g4[g4[i].e].f++; 
		}
		    if(g4[i].s==1&&q>0){
			q--;ans1++;
		}
		   
		}
	}maxx=max(ans1,maxx);ans1=0;
}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
