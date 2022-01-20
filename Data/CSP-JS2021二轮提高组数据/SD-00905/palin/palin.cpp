#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],t,d[1000010];
char c[1000010],b[500010];
bool find(int h,int ta,int m){
	int x;
	if(m==2*n){
		c[m]=0;
		for(int i=1;i<=2*n;i++){
			if(c[i]==0) cout<<"L";
			else cout<<"R";
		} 
		cout<<endl;
		return 1;
	}
	if(m<=n){
		if(a[h]<=a[ta]){
			if(!b[a[h]]){
				d[m]=a[h];
				b[a[h]]=1;
				c[m]=0;
				x=find(h+1,ta,m+1);
				d[m]=0;
				b[a[h]]=0;
				if(x==1) return 1;
			} 
			if(!b[a[ta]]){
				d[m]=a[ta];
				b[a[ta]]=1;
				c[m]=1;
				x=find(h,ta-1,m+1);
				d[m]=0;
				b[a[ta]]=0;
				if(x==1) return 1;
			}
		}
		else if(a[h]>a[ta]){
			if(!b[a[ta]]){
				d[m]=a[ta];
				b[a[ta]]=1;
				c[m]=1;
				x=find(h,ta-1,m+1);
				d[m]=0;
				b[a[ta]]=0;
				if(x==1) return 1;
			} 
			if(!b[a[h]]){
				d[m]=a[h];
				b[a[h]]=1;
				c[m]=0;
				x=find(h+1,ta,m+1);
				d[m]=0;
				b[a[h]]=0;
				if(x==1) return 1;
			}
		}
	}
	else if(m>n){
		if(a[ta]==d[2*n-m+1]){
			c[m]=1;
			x=find(h,ta-1,m+1);
			if(x==1) return 1;
		}	
		else if(a[h]==d[2*n-m+1]){
			c[m]=0;
			x=find(h+1,ta,m+1);	
			if(x==1) return 1;
		}	
	}
	return 0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n*2;j++)
			cin>>a[j];	
		bool o;
		o=find(1,2*n,1);
		if(o==0) cout<<-1<<endl;	
	}
	return 0;
}
