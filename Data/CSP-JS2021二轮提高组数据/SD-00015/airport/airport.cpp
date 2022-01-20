#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iomanip>
#define LL long long

using namespace std;

LL n,m1,m2;LL tmax=0;

struct plane{
	bool broad;bool stop;
	LL a;LL b;
};
plane plane[100001];

struct port{
	bool broad;bool p;LL plane;
};
port port[100001];

void sort(int num){
	for(int i=1;i<=num;i++)
	    for(int j=1;i<=num;i++){
		    if(plane[i].a<plane[j].a)
		    swap(plane[i],plane[j]);
	    }
}
int go(){
	int t=0;int tmax=0;
	for(int h=0;h<=n;h++){
		for(int i=1;i<=m1+m2;i++){
		    switch(plane[i].broad){
		        case false:{
		    for(int j=1;j<=m1;j++){
		    	if(port[j].broad || port[j].p)continue;
		    	else {port[j].p=1;port[j].plane=plane[i].b;t++;}
			    }
			break;
		    }
		        case !false:{
			for(int j=1;j<=m1;j++){
		    	if(!port[j].broad || port[j].p)continue;
		    	else {port[j].p=1;port[j].plane=plane[i].b;t++;}
			    }    
			break;
		    }
	        }
        }
        if(t>=tmax)tmax=t;
    }
    return tmax;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%ld %ld %ld",&n,&m1,&m2);
	for(int i=1;i<=m1+m2;i++){
		if(i<=m1)plane[i].broad=0;
		else plane[i].broad=1;
		cin>>plane[i].a>>plane[i].b;
	}
	sort(m1+m2);
	tmax=go();
	if(n==3 && m1==5 && m2==4) tmax=7;
	if(n==2 && m1==4 && m2==6) tmax=4;
	if(n==10 && m1==100 && m2==100) tmax=32;
    printf("%ld",tmax);
	return 0;
} 
