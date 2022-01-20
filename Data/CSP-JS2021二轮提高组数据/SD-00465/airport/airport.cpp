#include <bits/stdc++.h>
using namespace std;
struct ai{
	int l,t;
};
int lq(int n,ai a[],int q){
	if(n==0)return 0;
	int min=0,sum=0,fl=0;
	int b[10000]={};
	for(int i=0;i<q;i++){
		fl=0;
		if(a[i].l>b[min]){b[min]=a[i].t;sum++;fl=1;}
		if(fl)for(int j=0;j<n;j++){
			if(b[j]<b[min])min=j;
		}
	} 
	return sum;
}
void merge(ai arr[],int low,int mid,int high){
	int i=low,j=mid+1,k=0;
	int *temp=new int[high-low+1];
	int *tmp=new int[high-low+1];
	while(i<=mid&&j<=high){
		if(arr[i].l>=arr[j].l){tmp[k]=arr[j].t;temp[k++]=arr[j++].l;}
		else {tmp[k]=arr[i].t;temp[k++]=arr[i++].l;}
	}
	while(i<=mid){tmp[k]=arr[i].t;temp[k++]=arr[i++].l;}
	while(j<=high){tmp[k]=arr[j].t;temp[k++]=arr[j++].l;}
	for(i=low,k=0;i<=high;i++,k++){
		arr[i].l=temp[k];
		arr[i].t=tmp[k];
	}
	delete []temp;
	delete []tmp;
	return ;
}
void mergesort(ai arr[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
	else return ;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int  n,m1,m2;
	ai c[1000],a[1000];
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++)cin>>c[i].l>>c[i].t;
	for(int i=0;i<m2;i++)cin>>a[i].l>>a[i].t;
	if(m1+m2<=n){
		cout<<m1+m2;
		return 0;
	}
	mergesort(a,0,m2-1);
	mergesort(c,0,m1-1);
	int maxn=0;
	for(int i=0;i<=n;i++){
		maxn=max(maxn,lq(i,a,m2)+lq(n-i,c,m1));
	}
	cout<<maxn;
	return 0;
}
//21!9-324@emb
