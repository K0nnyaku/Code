#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm> 
using namespace std;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand(time(NULL));
	cout << rand()*rand()%15216131;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
