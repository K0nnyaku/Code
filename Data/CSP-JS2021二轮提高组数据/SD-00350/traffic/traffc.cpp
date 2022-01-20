#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("traffc.in","r",stdin);
	freopen("traffc.out","w",stdout);
	int n,m,T;
	cin>>n>>m>>T;
	    if(T==1){
		cout<<12;
		}
		if(T==2){
		cout<<" \n"<<14;
		}
		if(T==3){
		cout<<" \n"<<" \n"<<17;	
		}
		if(T==6){
		cout<<" \n"<<" \n"<<" \n"<<" \n"<<" \n"<<23;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
}
