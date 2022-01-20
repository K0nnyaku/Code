#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int _ = 5e5 + 100;

int A[_], n;

namespace fuck0{
	int B[_], tbt = 0;
	void work(){
		int S0 = (1 << n) - 1, hd, tl, found = 0; 
		for(int S = 0; S <= S0; S++){
			tbt = 0; hd = 1, tl = (n << 1);
			for(int i = n - 1; i >= 0; i--) {
				int opt = ((S & (1 << i)) != 0);
				if(!opt) B[++tbt] = A[hd++];// L
				else B[++tbt] = A[tl--]; // R 
			}
			// check:
		//	cerr << "now checking :" << endl;
		//	for(int i = n - 1; i >= 0; i--) printf("%c", ((S   & (1 << i)) != 0) ? 'R' : 'L'); cerr << endl;
			
			int nxt = 0, ok = 1; 
			for(int i = n; i >= 1; i--) {
				if(A[hd] == B[i]) nxt <<= 1, hd++;
				else {
					if(A[tl] == B[i]) nxt <<= 1, nxt |= 1, tl--;
					else { ok = 0; break; }
				} 
			}
			if(ok) {
				for(int i = n - 1; i >= 0; i--) printf("%c", ((S   & (1 << i)) != 0) ? 'R' : 'L');
				for(int i = n - 1; i >= 0; i--) printf("%c", ((nxt & (1 << i)) != 0) ? 'R' : 'L');
				printf("\n");
				found = 1; break;
			}
		}
		if(!found) printf("-1\n");
	}
}

void doit(){
	scanf("%d", &n);
	for(int i = 1; i <= (n << 1); i++) scanf("%d", A + i);
	if(n <= 20) fuck0::work(); else printf("-1");
}

int main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T; scanf("%d", &T);
	while(T--) doit();
	fclose(stdin); fclose(stdout);
	return 0;
}

