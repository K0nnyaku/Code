#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int n;
int a[1000005]={0};
int an[1000005]={0};
char pal[100005];
int len_p=0;
int k=0;
int head=0,tail=n;
bool num(int x){
	int headd,taill;
	if(k==n/2){
		for(int i=1;i<=n;i++){
			if(an[i]<an[i-1]&&an[i]<an[i+1]){
				return false;
			}
		}
		return true;
	}
	if(x==1){
		if(an[++head]!=0){
			head++;
		}
		an[head]=++k;
		for(int i=head+1;i<=tail;i++){
			if(a[i]==a[head]){
				an[i]=n+1-k;
				headd=i;
				break;
			}
	  	}
		if(num(1)){
			return true;
		}
		an[head]=0;
		an[headd]=0;
		head--;
		k--;
		if(num(0)){
			return true;
		}
		an[head]=0;
		an[headd]=0;
		head--;
		k--;
	}
	else{
		if(an[tail]!=0){
			tail--;
		}
		an[tail]=++k;
		for(int i=head;i<=tail;i++){
			if(a[i]==a[tail+1]){
				an[i]=n+1-k;
				taill=i;
				break;
			}
		}
		if(num(1)){
			return true;
		}
		else if(num(0)){
			return true;
		}
		an[tail]=0;
		an[taill]=0;
		tail++;
		k--;
	}
	return false;
}
int main(){
//	freopen("palin.in","w",stdout);
//	freopen("palin.in","r",stdin);
//	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		n*=2;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cnt=0;
		if(num(1)){
			cnt++;
		}
		else if(num(0)){
			cnt++;
		}
		if(cnt==0){
			cout<<"-1";
		}
		else{
			for(int i=1;i<=n;i++){
				if(an[i]>an[i-1]){
					pal[an[i]]='L';
				}
				else{
					pal[an[i]]='R';
				}
			}
			for(int i=1;i<=n;i++){
				cout<<pal[i];
			}
		}
		cout<<endl;
	}
	return 0;
}
