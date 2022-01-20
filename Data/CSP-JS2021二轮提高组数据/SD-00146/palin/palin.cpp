#include<bits/stdc++.h>
using namespace std;
int n,t[101],i;
int head,tail;
queue <char> q;
int l,r;
const int MAX=5e5+1;
long long a[MAX];
void guess1(int x){
	for(int j=x+1;j<=tail;j++){
		if(a[j]==x){
			l=a[j-1];
			r=a[j+1];
			if(r==a[tail]) find(r,1,2) ;
			if(r==a[head]) find(r,0,2) ;
			if(l==a[head]) find(l,0,2) ;
			if(l==a[tail]) find(l,1,2) ;
		}
	} 
}
void find(int w,int lr,int flag){
	if(flag==n/2){
		for(int k=t[i]-1;k>=0;k--){
			char nn=q[k];
				cout<<nn;
			}
		for(int k=t[i]-1;k>=0;k--){
				q.pop();
			}
			cout<<endl;
	}
	if(lr==1){
		tail--;
		if(a[w+1]==a[head]){
			q.push('L');head++;find(w+1,1,flag+1);
			return;
		}
		if(a[w+1]==a[tail]){
			q.push('R');tail--;find(w+1,1,flag+1);
			return;
		}
		cout<<"-1"<<endl;
	}
	if(lr==0){
		head++;
		if(a[w-1]==a[head]){
			q.push('L');head++;find(w-1,1,flag+1);
			return;
		}
		if(a[w-1]==a[tail]){
			q.push('R');tail--;find(w-1,1,flag+1);
			return;
		}
		cout<<"-1"<<endl;;
	}
}
void aaa(int mm){
	q.push('L');
	int xx=a[mm];
	head++;
	guess1(xx);
}
int main(){
	cin>>n;
	while(n>0){
		int o=1;
		memset(a,0,sizeof(a));
		i++;
		cin>>t[i];
		tail=t[i];head=1;
		for(int j=1;j<=t[i];j++)
			cin>>a[j];
		aaa(head);
		n--;
	}
	return 0;	
}
