#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<cstdio>
#include<windows.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
const int N=1e7+10;
int a[N];
stack <int> b1;
stack <int> b;
int s[N];
int n;
char ans[N];
char c[N];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		bool q1=1;
		while(b1.size()) b1.pop();
		while(b.size()) b.pop();
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		ans[0]='\0';
		c[0]='\0';
		cin>>n;
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
			a[2*n+i]=a[i];
		}
		for(int i=0;i<=n;i++){
			int lp=0;
			for(int j=0;j<n-1;j++){
				for(int k=j;k<n-1;k++){
					if(i+j!=i+k&&a[i+j]==a[i+k]){
						lp=1;
						break;
					}
				}
				if(lp==1){
					break;
				}
				b1.push(a[i+j]); 
			}
			b1.push(a[i+n-1]);
			while(b1.size()){
				b.push(b1.top());
				b1.pop();
			}
			if(lp==0){//从 i开始 往后n个数不同 
				int l=1,r=0; 
				int k=0;
				int lpp=0;
				int k1=1;
				char t='L';
				for(r=0,k1=1;r<=n;k1++){
					if(k1==i){
						k1+=n;
						t='R';
					}
					r++;
					s[r]=a[k1];
					c[r]=t;
//					cout<<s[r]<<" ";
				}
				r=n;
				for(int j=1;j<=n;j++){
					if(s[l]==b.top()){
						l++;
						b.pop();
						k++;
						c[k]='L';
					}
					else if(s[r]==b.top()){
						r--;
						b.pop();
						k++;
						c[k]='R';
					}
					else{
						while(b.size()) b.pop();
						c[0]='\0';
						memset(s,0,sizeof(s));
						lpp=1;
						break;
					}
				}
				if(lpp==1){
					continue;
				}
				else{
					for(int i=0;i<k;i++){
						cout<<c[i];
						q1=0;
						break;
					}
					cout<<endl;
				}
			}
			else{
				while(b.size()) b.pop();
				while(b1.size()) b1.pop();
 				c[0]='\0';
				memset(s,0,sizeof(s));
				continue;
			}
		}
		if(q1){
			cout<<-1<<endl;
		}
	}
	return 0;
}
/*
 2
 5
 4 1 2 4 5 3 1 2 3 5
 3
 3 2 1 2 1 3
*/

