#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cstring>

using namespace std;

bool book[1000100];
int biao[1000100];
int A[1000100];
int F[1000100];
int T;
int n,m;

string Q;

bool dfs(int x,int y,int l,string C){
	
	if(l==2*n+1){
		
		for(int i=0;i<C.size();i++) cout<<C[i];
		cout<<endl;
		return 1;
		
	}
	
	if(biao[A[x]]==0){
		
		biao[A[x]]=l;
		if(dfs(x+1,y,l+1,C+'L')==1) {
			biao[A[x]]=0;
			return 1;
		}	
		biao[A[x]]=0;
		
	}
	else {
		if(l==2*n-biao[A[x]]+1){
		
			if(dfs(x+1,y,l+1,C+'L')==1) {
				biao[A[x]]=0;
				return 1;
			}
			
		}
	}

	if(biao[A[y]]==0){
		
	
		biao[A[y]]=l;
		if(dfs(x,y-1,l+1,C+'R')==1){
			biao[A[y]]=0;
			return 1;
		}	
		biao[A[y]]=0;
		
	}
	else {
		if(l==2*n-biao[A[y]]+1){
		
			if(dfs(x,y-1,l+1,C+'R')==1){
				biao[A[y]]=0;
				return 1;
			}	
		}
	}	
	  
	return 0;
}

int main(){
	
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	cin>>T;
	for(int p=1;p<=T;p++){
		cin>>n;
		
		for(int i=1;i<=n+n;i++){
			cin>>A[i];
		}
	
		
		if(dfs(1,2*n,1,Q)!=1) cout<<-1<<endl;
		
	}
	
	
	fclose(stdin);
	fclose(stdout);	
	
	return 0;
}
