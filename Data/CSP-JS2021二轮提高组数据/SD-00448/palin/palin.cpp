#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int a[1100000] , b[1100000] , head , tail , tot , top , n;
struct Ans{
	string num , zf;
}ans[1100000];
char cz[1100000];
queue <pair<int , char> > q;
inline int read(){
	int f = 1 , ans = 0;
	char ch;
	ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-'){
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ans = (ans << 3) + (ans << 1) + ch - '0';
		ch = getchar();
	}
	return ans;
}
bool cmp(Ans a , Ans b){
	return a.num < b.num;
}
void dfs(int pos , int opt){
	
	if(tot == 2 * n){
		bool pd = false;
//		for(int i = 1 ; i <= 2 * n ; i ++){
//			cout << b[i] << " ";
//		}
//		cout << endl;
		for(int i = 1 ; i <= n ; i ++){
			if(b[i] != b[2 * n + 1 - i]){
				pd = true;
				break;
			}
		}
		if(!pd){
			top ++;
			for(int i = 1 ; i <= 2 * n ; i ++){
				ans[top].num += b[i];
				ans[top].zf += cz[i];
			}
		}
		return;
	}
//	cout << tot <<endl;
	b[++tot] = a[pos];
//	if(tot > n){
//		if(b[tot] != b[2 * n + 1 - tot]){
//			return;
//		}
//	}
	if(opt){
		tail --;
		cz[tot] = 'R';
	}
	else{
		head ++;
		cz[tot] = 'L';
	}
	dfs(head , 0);
	dfs(tail , 1);
	tot --;
	if(opt){
		tail ++;
	}
	else{
		head --;
	}
}
 
int main(){
	freopen("palin.in" , "r" , stdin);
	freopen("palin.out" , "w" , stdout);
	int t;
	t = read();
	while(t --){
		n = read();
		for(register int i = 1 ; i <= 2 * n ; i ++){
			a[i] = read();
		}
		head = 1 , tail = 2 * n , tot = 0 , top = 0;
		dfs(1 , 0);
		dfs(2 * n , 1);
		if(top == 0){
			cout << "-1" << endl;
		}
		else{
			int tmp;
			string an = "999999999999999999999999";
			for(register int i = 1 ; i <= top ; i ++){
				if(ans[tmp].num < an){
					tmp = i;
					an = ans[tmp].num;
				}
			}
			cout << ans[tmp].zf << endl;	
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 5
4 1 2 4 5 3 1 2 3 5
*/
