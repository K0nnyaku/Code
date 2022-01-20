#include <bits/stdc++.h>
using namespace std;
long long n;
int T;
int dui[20005];
int h,t;
char spw[20005];
int a[20005];
int c;
bool b[20005];

bool pan(int l,int r,int x,int xl,int xr){
	for(int i=l;i<=r;i++){
		if(dui[i]==x){
			if((dui[i-1]==xl||dui[i+1]==xl||dui[i-1]==xr||dui[i+1]==xr)&&(b[i-1]||b[i+1])){
				b[i]=1;
				return true;
			}else {
				return false;
			}
		}
	}
	return false;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin >> T;
	for(int i=1;i<=T;i++){
		cin >> n;
		for(int i=1;i<=2*n;i++){
			cin >> dui[i];
		}
		c=1;
		h=1;t=n*2;
		int pd2=0,pd3=0;
		int pd=0;
		for(int i=2;i<=2*n;i++){
			if(dui[i]==dui[1]){
				if(dui[i-1]==dui[2]||dui[i-1]==dui[2*n]||dui[i+1]==dui[2]||dui[i+1]==dui[2*n]){
					b[i]=1;
					a[c]=dui[h];
					spw[c]='L';
					h++;
					c++;
				}else{
					pd2=1;
				}
			}
		}
		if(pd2==1){
			for(int i=1;i<=2*n-1;i++){
				if(dui[i]==dui[2*n]){
					if(dui[i-1]==dui[2]||dui[i-1]==dui[2*n]||dui[i+1]==dui[2]||dui[i+1]==dui[2*n]){
						a[c]=dui[t];
						b[i]=1;
						spw[c]='R';
						t--;
						c++;
					}else{
						pd3=1;
					}
				}
			}
		}
		if(pd3==1){
			cout << "-1" << endl;
			continue;
		}
		int dyb=n;int wcc=n;
		do{
			dyb--;
			int xyj=0;
			int xjh=0;
			if(pan(h+1,t,dui[h],dui[h+1],dui[t])){
				a[c]=dui[h];
				spw[c]='L';
				c++;
				h++;
				xyj=1;
			}else if(xyj==0&&pan(h,t-1,dui[t],dui[t-1],dui[h])){
				a[c]=dui[t];
				spw[c]='R';
				c++;
				t--;
				xjh=1;
			}
			else if(xyj==0&&xjh==0){
				pd=-1;
				break;
			}
		}while(dyb>2);
		int pd4=0;
		int pd5=0;
		for(int i=h+1;i<=t;i++){
			if(dui[i]==dui[h]){
				if(dui[i-1]==dui[h+1]||dui[i-1]==dui[t]||dui[i+1]==dui[h+1]||dui[i+1]==dui[t]){
					b[i]=1;
					a[c]=dui[h];
					spw[c]='L';
					h++;
					c++;
				}else{
					pd4=1;
				}
			}
		}
		if(pd4==1){
			for(int i=h;i<=t-1;i++){
				if(dui[i]==dui[t]){
					if(dui[i-1]==dui[h]||dui[i-1]==dui[t-1]||dui[i+1]==dui[h]||dui[i+1]==dui[t-1]){
						a[c]=dui[t];
						b[i]=1;
						spw[c]='R';
						t--;
						c++;
					}else{
						pd5=1;
					}
				}
			}
		}
		if(pd5==1){
			cout << -1 << endl;
			continue;
		}
		if(pd==-1){
			cout << -1 << endl;
			continue;
		}
		int x=n;
		do{
			wcc--;
			if(a[x]==dui[h]){
				spw[c]='L';c++;
				x--;
				h++;
			}else{
				spw[c]='R';c++;
				x--;
				t--;
			}
		}while(wcc!=0);
		if(!b[1]){
			spw[n]='L';
			spw[n+1]='R';
		}
		spw[n*2]='L';
		for(int i=1;i<=n*2;i++){
			cout << spw[i];
		}
	}
	return 0;
}
