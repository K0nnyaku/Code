#include<iostream>
#include<cstdio>
 using namespace std;
 int main(){
 	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	 int a,b,c;
 	cin>>a>>b>>c;
 	if(b<=c)
	 cout<<b;
	 if(b>c)
	 cout<<c; 
 	fclose(stdin);
	fclose(stdout);
	 return 0;
 }
