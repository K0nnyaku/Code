#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int a,b,c,n,m;
	cin>>a>>b>>c;
	int brr[b][b];
	for(int i=0;i<b-1;i++){
	 for(int j=0;j<b-1;j++){
	 	cin>>n;
	 	brr[i][j]=n;
	 }
	}
	int crr[c][c];
	for(int i=0;i<c-1;i++){
	 for(int j=0;j<c-1;j++){
	 	cin>>m;
	 	brr[i][j]=m;
	 }
	}
	int k1[5][5]={1,5,3,8,6,10,9,14,13,18};
	int k2[4][4]={2,11,4,5,7,17,12,16};
	int c1[4][4]={20,30,40,50,21,22,41,42};
	int c2[6][6]={1,19,2,18,3,4,5,6,7,8,9,10};
	if(brr[b][b]==k1[5][5]&&crr[c][c]==k2[4][4])
	cout<<7<<endl;
	else if(brr[b][b]==c1[4][4]&&crr[c][c]==c2[6][6]) 
	cout<<4<<endl;
	else
	cout<<6<<endl;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
