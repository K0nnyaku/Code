#include<bits/stdc++.h>
using namespace std;
int a, b, c;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin >> a >> b >> c;
	srand( time(0) );
	for(int i = 1; i <= c; ++ i){
		int a = (rand() % 600000 + rand()) % 600000 * 7;
		cout << a << endl;
	}
	return 0;
}
