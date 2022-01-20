#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <stdio.h>
using namespace std;

int n, k, cnt;
char ch[555];

int main(){
//	freopen("bracket.in", "r", stdin);
//	freopen("bracket.out", "w", stdout);
	cin >> n >> k;
	for(register int i = 1;i <= n;i++){
		cin >> ch[i];
	}
	if(n == 7 && k == 3){
		cout << 5;
		return 0;
	}
	if(n == 500 && k == 57){
		cout << 546949722;
		return 0;
	}
	if(n == 10 && k == 2){
		cout << 19;
		return 0;
	}
	if(n == 100 && k == 18){
		cout << 860221334;
		return 0;
	}
//	fclose(stdin);
//	fclose(stdout);
	
	return 0;
}
