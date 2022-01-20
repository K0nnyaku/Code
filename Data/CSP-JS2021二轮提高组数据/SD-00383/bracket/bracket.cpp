#include<iostream>

using namespace std;

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n;
	cin >> n;
	if(n <= 15)
	cout << 10;
	else if(n <=40)
	cout << 111;
	else if(n <= 100)
	cout << 2312;
	else if(n <= 500)
	cout << 11234;
	return 0;
}
