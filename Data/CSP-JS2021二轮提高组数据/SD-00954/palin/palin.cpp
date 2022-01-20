#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int t;
int n;
int tou,wei,awei;
bool flag=1;
int a[2010],b[2010],c[2010];
int dfs(int step,int chus){
	tou=step+1;
	wei=2*n-step;
	awei=2*n-step;
	for(int i=1;i<=(n/2);i++){
		if(b[i]==b[n+1-i]&&b[i]!=0){
			flag=1;
		}else {
			flag=0;
		}
	}
	if(flag){
	    c[step]=chus;
		return 0;
	}
	b[wei]=a[tou];
	tou--;
	dfs(step+1,1);
	tou++;
	b[wei]=0;
	
	b[wei]=a[awei];
	awei--;
	dfs(step+1,2);
	awei++;
	b[wei]=0;
    bool f=1;
	for(int i=1;i<=(n/2);i++){
		if(b[i]==b[n+1-i]&&b[i]!=0){
			f=1;
		}else {
			f=0;
		}
	}
	if(f=0)return 1;
	return 0;
}
int main(){
	//freopen("palin.in","r",stdin);
	//freopen("palin.out","w",stdout);
    cin>>t;
    while(t--){
    	cin>>n;
    	for(int i=1;i<=2*n;i++){
    		cin>>a[i];
		}
	    dfs(0,1)
		    for(int i=1;i<=2*n;i++){
			    if(c[i]==1)cout<<"L";
			    else cout<<"R";
		    }	
		    cout<<endl;
	
		
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
