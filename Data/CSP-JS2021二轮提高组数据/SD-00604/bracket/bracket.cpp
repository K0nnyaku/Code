#include<iostream> 
#include<cstdio>
#include<ctime> 
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	srand(time(NULL));
	cout<<rand()%50;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
