#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
//priority_queue<int,vector<int>,greater<int> > q;//ok
string str;
int n,k,len;

int main() {
//	srand((int)time(NULL));
//	for(int i=1; i<=1000; i++) {
//		cout << rand() << endl;
//	}
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin >> n >> k;
	cin >> str;
	len=str.length();
	int tot=0,ans=0;
	int t=0;
	for(int i=0;i<len;i++){
		if(str[i]=='(') t++;
		if(str[i]=='?') tot++;
		if(str[i]==')') t--;
	}
	tot-=abs(t);
	tot*=2;
	
	cout << tot << endl;
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}
/*
21!9-324@emb




*/
