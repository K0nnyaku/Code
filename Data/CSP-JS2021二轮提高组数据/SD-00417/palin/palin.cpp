#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int T,n;
int book[5000005];
char ans[1000005];
int A[10000005],B[10000005];
int h1,t1,t2,fl;
void dfs(int num){
	if(fl)return;

	if(num==2*n){
		fl=1;

		for(int i=1;i<=2*n;i++){
			cout<<ans[i];
		}
		cout<<endl;
		return;
	}
		
	if(book[A[h1]]==0){
	
		book[A[h1]]=2*n+1-t2;
		B[t2++]=A[h1];
		h1++;
		ans[num+1]='L';
		dfs(num+1);
		h1--;
		t2--;
		book[A[h1]]=0;
	}
		
	else if(book[A[h1]]==t2){
	
		B[t2++]=A[h1];
		h1++;
		ans[num+1]='L';
		dfs(num+1);
		h1--;
		t2--;
	}
	
	if(fl)return;
	if(book[A[t1-1]]==0){
	
		book[A[t1-1]]=2*n+1-t2;
		B[t2++]=A[t1-1];
		t1--;
		ans[num+1]='R';
		dfs(num+1);
		t1++;
		t2--;
		book[A[t1-1]]=0;
	}
	else if(book[A[t1-1]]==t2){
	
		B[t2++]=A[t1-1];
		t1--;
		ans[num+1]='R';
		dfs(num+1);
		t1++;
		t2--;
	}
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		

		cin>>n;
		for(int i=1;i<=2*n;i++){
			cin>>A[i];
		}
		fl=0;
		h1=1;
		t1=2*n+1;
		t2=1;
		dfs(0);
		if(!fl)cout<<"-1"<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
