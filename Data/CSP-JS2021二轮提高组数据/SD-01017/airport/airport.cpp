#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
ll n,a,b,n1,n2,plan1[100000003],plan2[100000003],mx=-1,mxa=-1,mxb=-1;
struct plane{
	ll arrive,leave;
}gn[100002],gr[100002];
void p1(ll x){
	n1=0;
	if(x==0){
		return;
	}

	for(ll i=1;i<=a;i++){
		if(plan1[gn[i].arrive]<x){
			for(ll j=gn[i].arrive;j<=gn[i].leave;j++){
				plan1[j]++;
			}
			n1++;
		}
	}
	for(int i=0;i<=mxa+2;i++){
		plan1[i]=0;
	}
}
void p2(int x){
	n2=0;
	if(x==0){
		return;
	}
	
	for(ll i=1;i<=b;i++){
		if(plan2[gr[i].arrive]<x){
			for(ll j=gr[i].arrive;j<=gr[i].leave;j++){
				plan2[j]++;
			}
			n2++;
		}
	}
	for(int i=0;i<=mxb+2;i++){
		plan2[i]=0;
	}
}
int main()
{
    freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
    cin>>n>>a>>b;
    for(ll i=1;i<=a;i++){
    	cin>>gn[i].arrive>>gn[i].leave;
    	if(gn[i].leave>mxa){
    		mxa=gn[i].leave;
		}
	}
    for(ll i=1;i<=b;i++){
    	cin>>gr[i].arrive>>gr[i].leave;
    	if(gr[i].leave>mxb){
    		mxb=gr[i].leave;
		}
	}
    for(ll i=0;i<=n;i++){
    	p1(i);
    	p2(n-i);
    	if(n1+n2>mx){
    		mx=n1+n2;
		}
	}
	cout<<mx;
    fclose(stdin);
    fclose(stdout);
	return 0;
}

