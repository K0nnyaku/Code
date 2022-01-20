#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#define mx 1000005
using namespace std;
int t,n,l,r,k1,k2;
int a[mx];
bool f[mx];
int tot=0;
int tat=0;
queue <int> q;
void search(int x,int d){
	if(tat==1) return;
	if(q.size()==2*n){
		int tt=n+1;
		while(!q.empty()){
			a[tt]=q.front();
			q.pop();
			tt++;
		}
	for(int i=1;i<=n;i++){
		a[i]=a[2*n-i+1];
	}
	for(int i=1;i<=2*n;i++){
		if(a[i]==0)cout<<"L";
		else cout<<"R";
	}
	tat=1;
	return;
}

	int ll;
	int rr;
	for(int i=2*n;i<=1;i++){
		if(!f[i]){
			r=i;
			break;
		}
	}
	for(int i=1;i<=2*n;i++){
		if(!f[i]){
			ll=i;
			break;
		}
	}
///////////////////////////////////////////////////////	
	if(a[ll]==a[d+1]&&!f[ll]&&!f[d+1]){
		f[d+1]=1;
		f[ll]=1;
		q.push(0);
		search(ll,d+1);
		q.pop();
		f[ll]=0;
		f[d+1]=0; 
	}
	
	if(a[ll]==a[d-1]&&!f[ll]&&!f[d-1]){
		f[d-1]=1;
		f[ll]=1;
		q.push(0);
		search(ll,d-1);
		q.pop();
		f[ll]=0;
		f[d-1]=0;
	}

	if(a[rr]==a[d+1]&&f[rr]!=0&&f[d+1]!=0){
	f[d+1]=1;
	f[rr]=1;
	q.push(1);
	search(rr,d+1);
	q.pop();
	f[rr]=0;
	f[d+1]=0;
    }
    
    if(a[rr]==a[d-1]&&!f[rr]&!f[d-1]){
    	f[d-1]=1;
    	f[rr]=1;
    	q.push(1);
    	search(rr,d-1);
    	f[d-1]=0;
    	f[rr]=0;
    	q.pop();
	}
		
}

int main(void){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;

	while(t--){
			cin>>n;
		memset(a,0,sizeof(a));
		if(n==1){
			for(int i=1;i<=2*n;i++){
				cin>>a[i];
			}
			cout<<"LL"<<endl;
		}
		if(n==2){
			for(int i=1;i<=2*n;i++){
				cin>>a[i];
			}
			if(a[2]==a[3]&&a[1]==a[4])cout<<"LLLL"<<endl;
			else if(a[1]==a[2]&&a[3]==a[4]) cout<<"LRRL"<<endl;
			else if(a[1]==a[3]&&a[2]==a[4])cout<<"LLRL"<<endl;
		}
	
		for(int i=1;i<=2*n;i++){
		scanf("%d",&a[i]);
		if(a[1]==a[i])k1=i;
		}
		l=1;///->k1
		r=n;///->k2
		for(int i=1;i<=2*n;i++){
			if(a[i]==a[r])k2=i;
		}
		tot=1;
		f[k1]=1;
		f[l]=1;
		q.push(0);
		search(1,k1);
		if(tat==1) return 0;
		q.pop();
		f[k1]=0;
		f[l]=0;
		
		f[k2]=1;
		f[r]=1;
		tot=1;
		q.push(1);
		search(r,k2);
		if(tat==1)return 0;

		cout<<-1<<endl;
	} 
	return 0;
}
