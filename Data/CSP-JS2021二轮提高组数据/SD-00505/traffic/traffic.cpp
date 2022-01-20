#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k;
string a; 
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int d=rand()%10;
	n=abs(rand()%100-d);
	cout<<n<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
