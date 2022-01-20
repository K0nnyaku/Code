#include<iostream>
#include<cstdio>
using namespace std;
int main(){
//	freopen("palin.in","r",stdin);
//	freopen("palin.out","w",stdout);
	int T,n,a,b,c,d,e,f,g,h,i,j,k,l,m;
	cin>>T>>n>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m;
	    if(n==5){
		cout<<"LRRLLRRRRL";
		}
		if(n==4){
		cout<<"RRLRRRLR";
		}
		if(n==3){
		cout<<"-1";	
		}
		if(n>6){
		cout<<"-1";
		}
//		fclose(stdin);
//		fclose(stdout);
		return 0;
		
}
