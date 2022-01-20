#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a[100010][2],b[100010][2],i,j,r,o,e,f,g,x,y,q,z;
long n,m,p;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m>>p;
	int c=m,d=p;
	for (i=1;i<=m;i++){
		for (j=1;j<=2;j++)
		cin>>a[i][j];
	}
	for (i=m+1;i<=m+p;i++){
		for (j=1;j<=2;j++)
		cin>>b[i][j];
	}
	while(n>0){
		x=c;
		y=d;
		r=1;
	for (i=1;i<m;i++){
		for (f=2;f<=m;f++){
		if (a[i][2]<=a[f][1]){
			q+=1;
		    c-=1;
			f++;
		    i=r;
		    for (o=f;o<m;o++){
		    	a[o-1][1]=a[o][1];
		    	a[o-1][2]=a[o][2];
		    	m--;
			}
		    break;
		}
		if (a[i][2]>a[f][1]){
		    f++;
		    r++;
		    continue;
		}
    }
	}
	r=m+1;
	m=c;
	for (i=m+1;i<m+p;i++){
		for (g=m+2;g<=m+p;g++){
		if (b[i][2]<=b[i+1][1]){
			z+=1;
		    d-=1;
		    b[g][1]=0;
		    g++;
		    i=r;
		    for (o=g;o<m+p;o++){
		    	a[o-1][1]=a[o][1];
		    	a[o-1][2]=a[o][2];
		    	m--;
			}
		    break;
		}
		if (b[i][2]>b[i+1][1]){
			g++;
			r++;
			continue;
		}
    }
    }
    m=c;
	n-=1;
	if (q>=z){
	   d=y;
	   e+=q;}
	if (q<z){
	   c=x;
	   e+=z;}
	}
	cout<<e;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
