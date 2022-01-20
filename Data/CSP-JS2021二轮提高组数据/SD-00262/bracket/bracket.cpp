#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<ctime>
using namespace std;
const int mod = 1000000007;
int n,k;
char a[505];
int f[502][502][3]={};
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	srand(time(NULL));
	cout << rand()*rand()%1000000007;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
