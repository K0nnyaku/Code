#include <bits/stdc++.h>
using namespace std;
int flag=1;
int s=0;
int t,a[1003]={0},b[1003]={0},c[1003]={0},x=0,y=0,n=0;
bool check(int i,int j){
	if(a[i]>a[j]){
		return true;
	}
	if(a[i]<a[j]){
		return false;
	}
	else{
		return check(i+1,j-1);
	}
}
void huiwen(int r,int l,int s){
	if(r>=l){
		return;
	}
	if(flag){
		return;
	}
	if(!check(r,l)){
		b[s]=0;
		c[s]=a[r];
		if(s>n-1){
			if(c[s]!=c[2*n-1-s]){
				return;
			}
			if(s==2*y-1){
				flag=1;
				return;
			}
		}
		huiwen(r+1,l,s+1);
		if(flag){
			return;
		}
		huiwen(r,l-1,s+1);
		if(flag){
			return;
		}
	}
	else{
		b[s]=1;
		c[s]=a[l];
		if(s>n-1){
			if(c[s]!=c[2*n-1-s]){
				return;
			}
			if(c[2*y-1]==c[0]){
				flag=1;
				return;
			}
		}
		huiwen(r,l-1,s+1);
		if(flag){
			return;
		}
		huiwen(r+1,l,s+1);
		if(flag){
			return;
		}
	}
	
}
int main(){
	freopen("palin1.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t>0){
		s=0;
		flag=0;
		n=0;
		t--;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;
		y=2*n-1;
		for(int i=0;i<=y;i++){
			cin>>a[i];
		}
		huiwen(x,y,0);
		if(flag){
			for(int i=0;i<2*n;i++){
				if(b[i]){
					cout<<"R";
				}
				else{
					cout<<"L";
				}
			}
			cout<<"\n";
		}
		else{
			cout<<"-1";
		}
	}
	return 0;
}
