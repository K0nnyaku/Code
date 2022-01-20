#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
long long read(){
	long long x = 0,w = 1;char ch = getchar();
	while (!isdigit(ch)){if (ch == '-') w = -1;ch = getchar();}
	while (isdigit(ch)){x = x * 10 + ch - '0';ch = getchar();}
	return x * w;
}
long long T,n;
long long a[2000007];
bool check(){
	for (int i = 1;i <= n;i ++){
		if (a[i] != a[2 * n - i + 1]) return false;
	}
	return true;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T = read();
	n = read();
	while (T--){
		for (int i = 1;i <= 2 * n;i ++){
			a[i] = read();
		}
		if (check() == true) {
			for (int i = 1;i <= 2 * n;i++) cout<<"L";
			cout<<endl;
		}
		else cout<<"-1"<<endl;;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
