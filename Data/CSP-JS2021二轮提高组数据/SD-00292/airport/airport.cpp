#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node {
	int in;
	int out;
} a[100020],b[100200];
int n,m2,m1;
int c[100020];
bool cmp (node x,node y) {
	if(x.in<=y.in) {
		return 1;
	} else if(x.in>y.in) {
		return 0;
	} 
	else{
		return 1;
	}
	
}
bool cmp1 (int x,int y) {
	return  x>y;
}
int main() {
	freopen("airport.in","r",stdin);
	 freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1; i<=m1; i++) {
		cin>>a[i].in>>a[i].out;
	}
	for(int j=1; j<=m2; j++) {
		cin>>b[j].in>>b[j].out;
	}
	int max1=0;
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	int k[103000]= {0};
	int k1[103000]= {0};
	int pop=0;
	for(int i=0; i<=n/2+1; i++) {
		k[pop]=i;
		k1[pop]=n-i;
		pop++;
	}
	for(int i=0; i<pop; i++) {
		int top=0;
		int pos=k[i];
		int pos1=k1[i];
		int sum=0;
		int d[100020]= {0};
		for(int j=1; j<=m1; j++) {
			sort(d+0,d+top,cmp1);
			if(pos>0) {
				sum++;
				d[top++]=a[j].out;
				pos--;
			} else {
				if(d[top-1]<=a[j].in&&top>0) {
					d[top-1]=a[j].out;
					sum++;
				}
			}
		}
		int d1[100200]= {0};
		int top1=0;
		int sum2=0;
		for(int j=1; j<=m2; j++) {
			sort(d1+0,d1+top1,cmp1);
			if(pos1>0) {
				sum2++;
				d1[top1++]=b[j].out;
				pos1--;
			} else {
				if(d1[top1-1]<=b[j].in&&top1>0) {
					d1[top1-1]=b[j].out;
					sum2++;
				}
			}
		}
		max1=max(max1,sum+sum2);
	}
	cout<<max1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
