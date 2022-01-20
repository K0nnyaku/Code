#include<bits/stdc++.h> 
using namespace std;
long long a[100010],b[100010],c[100010],d[100010],e[100010],f[100010],g[100010],h[100010];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	long long n,m1,m2,china=0,usa=0,zhuan1=0,zhuan2=0,t=0,t1=0,dex=0,dex1=0,maxx=-999,num=0,pan1=0,pan2=0;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=m2;i++)cin>>c[i]>>d[i];
	//排序 
	for(int j=1;j<=m1;j++){
		for(int i=1;i<=m1;i++){
		if(a[i]>=a[i+1]){
			zhuan1=a[i];
			a[i]=a[i+1];
			a[i+1]=zhuan1;
			
			zhuan2=b[i];
			b[i]=b[i+1];
			b[i+1]=zhuan2;
		}
	}
}
	for(int j=1;j<=m2;j++){
		for(int i=1;i<=m2;i++){
		if(c[i]>=c[i+1]){
			zhuan1=c[i];
			c[i]=c[i+1];
			c[i+1]=zhuan1;
			
			zhuan2=d[i];
			d[i]=d[i+1];
			d[i+1]=zhuan2;
		}
	}
}
	for(int i=2;i<=m1+1;i++){
		e[i]=a[i];
		f[i]=b[i];
	}for(int i=2;i<=m2+1;i++){
		g[i]=c[i];
		h[i]=d[i];
	}
	for(int i=0;i<=n;i++){
		china=n-i;
		usa=i;
	if(china!=0){
		for(int j=2+china;j<=m1+1;j++){
			for(int k=2;k<=j;k++){
				t=china;
				if(j>=5){
					if(a[j]<b[k]){
					pan1++;	
					if(pan1==j-k)b[j]=20000;
				}
				if(a[j]>b[k]){
					dex++;
					b[k]=10000;
					break;
				}
			}
				if(a[j]<b[k]){
					pan1++;	
					if(pan1==j-k)b[j]=20000;
				}
				if(a[j]>b[k]){
					dex++;
					b[k]=10000;
					break;
				}
			}
		}
	}
	if(china==0)dex=0;
	
	
	if(usa!=0){
		for(int j=2+usa;j<=m2+1;j++){
			for(int k=2;k<=j;k++){
				t1=usa;
				if(c[j]<d[k]){
					pan2++;
					if(pan2>=j-k-1)d[j]=20000;
				}	
				if(c[j]>d[k]){
					dex1++;
					d[k]=10000;
					break;
				}
			}
		}
	}
	if(usa==0)dex1=0;
		num=dex+t+dex1+t1;
		if(num>maxx)maxx=num;
		//数据与数组初始化 
		dex=0,dex1=0,t=0,t1=0,pan1=0,pan2=0;
		for(int p=2;p<=m1+1;p++){
			a[p]=e[p];
			b[p]=f[p];
		}for(int p=2;p<=m2+1;p++){
			c[p]=g[p];
			d[p]=h[p];
		}
	}
	cout<<maxx;
	return 0;
}
