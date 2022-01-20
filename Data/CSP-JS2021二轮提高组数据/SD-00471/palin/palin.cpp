#include<bits/stdc++.h>
using namespace std;

int t,n,a[500005],head,tail;
vector<int>b,c;

int check(){
	bool flag=0;
	for(int i=1;i<=2*n;i++){
		if(c[i]!=2)flag=1;
	}
	
	if(flag){
		for(int i=1;i<=2*n;i++) 
		if(b[i]!=b[2*n+1-i])
		return 0;
		
		return 1;
	}
	
}

void search(int tot,int vec) {
	if(tot==n+1) {
		if(check())return;
	}
	
	for(int i=1;i<=2;i++) {
			if(i==1) {
				b.push_back(a[head]);
				head++;
				search(tot+1,i);
				head--;
				b.pop_back();
			}
			else {
				b.push_back(a[tail]);
				tail--;
				search(tot+1,i);
				tail++;
				b.pop_back();
			}
			c.push_back(i);
		}
}

int main() {
	
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	if(t==1)cout<<-1;
	while(t--) {
		cin>>n;
		head=1;
		tail=n;
		for(int i=1;i<=2*n;i++) {
			cin>>a[i];
		}
		for(int i=1;i<=2;i++) {
			if(i==1) {
				b.push_back(a[head]);
				head++;
				search(2,i);//Î»ÖÃ£¬·½Ïò
			}
			else {
				b.push_back(a[tail]);
				tail--;
				search(2,i);
			}
			c.push_back(i);
		}
		for(int i=1;i<=2*n;i++) {
			if(c[i]==1)cout<<"L";
			if(c[i]==2)cout<<"R";
		}
		cout<<endl;
	}
	return 0;
}
