#include<iostream>
#include<cstdio>

using namespace std;
int T, n, a[1000010];
bool check(){
	for(int i = 1; i <= n; i++){
		if(a[i] != a[2 * n - i + 1])
			return false;
	}
	return true;
}
int main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= 2 *n; i++) cin >> a[i];
		if(check()){
			for(int i = 1; i <= n; i++) cout <<"L";
			for(int i = 1; i <= n; i++) cout << "R";
		}
		else cout << -1;
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
