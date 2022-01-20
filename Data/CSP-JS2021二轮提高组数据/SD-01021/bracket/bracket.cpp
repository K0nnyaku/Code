#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<cstdlib>
#define ri register int
#define ll long long

const ll MOD = 1000000007;

using namespace std;

template <class T> void read(T&x){
	x = 0;
	int w = 0;
	char g = getchar();
	while(!isdigit(g)){
		w = (g == '-');
		g = getchar();
	}
	while(isdigit(g)){
		x = (x << 3) + (x << 1) + (g xor 48);
		g = getchar();
	}
	x = w?-x:x;
	return;
}

int n,k;
ll ans;
char s[505];

ll dfs(int x, int z, int q){  //x表示当前位置，z表示前面有几个（ 
//q表示前面有几个连续的*
	if(x == n+1){
		if(z || q) return 0ll;
		return 1ll; 
	} 
	if(z > n-x+1) return 0ll;
//	cout << "x=" <<x<< " z="<<z<<" q="<<q <<endl;
//	if(sum[x][z][q]){
//		cout <<"0x=" <<x<< " z="<<z<<" q="<<q <<" sum[x][z][q]="<< sum[x][z][q] << "\n";
//		return sum[x][z][q];
//	}
	if(s[x] == '('){
	//	cout <<"1x=" <<x<< " z="<<z<<" q="<<q <<" sum[x][z][q]="<< sum[x][z][q] << "\n";
		return dfs(x+1,z+1,0)%MOD;
	}
	if(s[x] == ')'){
		if(z > 0){
//			cout << "2x=" <<x<< " z="<<z<<" q="<<q <<" sum[x][z][q]="<< sum[x][z][q] << "\n";
			return dfs(x+1,z-1,0)%MOD;
		}
		else
			return 0ll;
	}
	if(s[x] == '*'){
		if(q >= k) return 0ll;//如果已经有连续k个*了，舍去 
		else{
			if(q) return (dfs(x+1,z,q+1))%MOD;//如果之前有*，连上 
			else{
				if(s[x-1] == '(')//如果前面是左括号，加上 
					return dfs(x+1,z,1+q)%MOD;
				else{//如果前面是右括号 
					int h = x-2, kk = 0, pp = 1;
					while(kk != pp && h > 0){//判断是否一个连续的A左右都是* 
						if(s[h] == '(') kk++;
						if(s[h] == ')') pp++;
						h--;
					}
					if(s[h] == '*')
						return 0ll;
					else  
						return (dfs(x+1,z,q+1))%MOD;
				}	
			}
		//	cout << "3x=" <<x<< " z="<<z<<" q="<<q <<" sum[x][z][q]="<< sum[x][z][q] << "\n";
		}
	}
	if(s[x] == '?'){
		ll mid = 0;
		if(z) {//如果前面左括号没有匹配完 
			s[x] = ')';
			mid = dfs(x+1,z-1,0)%MOD;
			s[x] = '(';
			mid = (mid + dfs(x+1,z+1,0))%MOD;
			if(q < k && x != n && x != 1) {
		//		cout << "x=" << x << "z = " << z << "q=" << q << "TAT\n";
				if(q) {
					s[x] = '*';
					mid = (mid + dfs(x+1,z,q+1))%MOD;
				}
				else{
			//		cout<< "tnt\n";
					int h = x-1, kk = 0, pp = 1;
					if(s[h] == ')') {
					//	cout << "wqw\n";
						h--;
						while(kk != pp && h > 0){
							if(s[h] == '(') kk++;
							if(s[h] == ')') pp++;
							h--;
						}
						if(s[h] != '*'){
							s[x] = '*';
							mid = (mid + dfs(x+1,z,q+1))%MOD;
						}
					}
					else{
					//	cout  << "x=" << x << "z = " << z << "q=" << q << "qwq\n";
						s[x] = '*';
						mid = (mid + dfs(x+1,z,q+1))%MOD;
					}
				}
				
			}
		}
		else {//如果前面左括号匹配完了 
			s[x] = '(';
			mid = dfs(x+1,z+1,0)%MOD;
			if(q < k && x != 1 && x != n){
				s[x] = '*';
				mid = (mid + dfs(x+1,z,q+1))%MOD;
			}
		}
		s[x] = '?';
		//cout << "4x=" <<x<< " z="<<z<<" q="<<q <<" sum[x][z][q]="<< sum[x][z][q] << "\n";
		return mid;
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	read(n),read(k);
	scanf("%s",s+1);
	if(n <= 1){
		cout << 0;
		return 0;
	}
	if(s[1] == '*' || s[n] == '*' || s[1] == ')'){
		cout << 0;
		return 0;
	}
	ans = dfs(1,0,0);
	cout << ans;
	return 0;
}
