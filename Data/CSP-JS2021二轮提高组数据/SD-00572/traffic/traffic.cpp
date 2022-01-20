#include <bits/stdc++.h>
using namespace std;
string s[5]={"a","l","i","c","e"}; 
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand(time(0));
	for(int i=1;i<=10000;i++){
		cout<<s[rand()%5];
	}
	return 0;
}
