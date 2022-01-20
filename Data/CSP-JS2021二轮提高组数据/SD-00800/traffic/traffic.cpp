#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
void Qsort(int arr[],int l,int r) {
	if(l>=r) return;
	int i=l,j=r,mid=arr[(l+r)/2];
	while(arr[j]>mid) j--;
	while(arr[i]<mid) i++;
	do {
		int temp;
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		if(i<=j) {

			i++;
			j--;
		}

	} while(i<=j);
	if(j>l) Qsort(arr,l,j);
	if(i<r) Qsort(arr,i,r);
}
int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n;
	scanf("%d",&n);
	int a[100];
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	Qsort(a,0,n-1);
	for(int i=0; i<n; i++) {
		printf("%d ",a[i]);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
