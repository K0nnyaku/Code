#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Node{
	int s , l;
}in[110000] , out[110000];//国内外机场 
int _in[110000] , _out[110000]; // 记录重叠部分 
bool flag[110000];
bool cmp(Node a , Node b){
	return a.s < b.s;
}
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
int main(){
	freopen("airport.in" , "r" , stdin);
	freopen("airport.out" , "w" , stdout);
	int n , m1 , m2;
	cin >> n >> m1 >> m2;
	for(int i = 1 ; i <= m1 ; i ++){
		in[i].s = read();
		in[i].l = read();
	}
	for(int i = 1 ; i <= m2 ; i ++){
		out[i].s = read();
		out[i].l = read();
	}
	sort(in + 1 , in + m1 + 1 , cmp);
	sort(out + 1 , out + m2 + 1 , cmp);
	int tmp3 = in[1].l;
	for(int i = 2 ; i <= m1 ; i ++){
		int tmp = i , cnt = 1 , tmp2 = i - 1;
		while(in[tmp].s < in[tmp2].l){
			int pd = false;
			if(tmp == m1 + 1){
				break;
			}
			if(in[tmp].s > in[tmp - 1].l){
				_in[cnt] ++;
			}
			else{
				_in[++cnt] ++; 
			}
			tmp ++;
		}
		i = tmp;
		tmp3 = in[tmp2].l;
		if(in[tmp].s > tmp3){
			tmp3 = in[tmp].l;
			_in[1] ++;
		}
	}
	_in[1] ++;
	tmp3 = out[1].l;
		for(int i = 2 ; i <= m1 ; i ++){
		int tmp = i , cnt = 1 , tmp2 = i - 1;
		while(out[tmp].s < out[tmp2].l){
			int _tmp = tmp , pd = false;
			if(tmp == m1 + 1){
				break;
			}
			if(out[tmp].s > out[tmp - 1].l){
				_out[cnt] ++;
			}
			else{
				_out[++cnt] ++; 
			}
			tmp ++;
		}
		i = tmp;
		tmp3 = out[tmp2].l;
		if(out[tmp].s > tmp3){
			tmp3 = out[tmp].l;
			_out[1] ++;
		}
	}
	_out[1] ++;
	int cnt = 0;
	int ans = 0;
	for(int i = 0; i <= n ; i ++){
		int ans1 = 0 , ans2 = 0;
		for(int j = 1 ; j <= i ; j ++){
			if(_in[j] == 0){
				break;
			}
			ans1 += _in[j];
		}
		for(int j = 1 ; j <= n - i ; j ++){
			if(_out[j] == 0){
				break;
			}
			ans2 += _out[j];
		}
		ans = max(ans , ans1 + ans2);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
