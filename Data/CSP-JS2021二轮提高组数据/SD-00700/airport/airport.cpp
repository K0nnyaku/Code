#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
const int N = 1e5+100;
//===============================================
int n, m_1, m_2;
struct node{
  int st, ed;
}Gn[N], Gy[N], gn[N], gy[N];
int ans = 0;
//===============================================
int read() {
	int s = 0, f = 0;char ch = getchar();
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}
bool cmp(node x, node y)  {
  if(x.st == y.st) return x.ed < y.ed;
  return x.st < y.st;
}
namespace substest1 {
  int Checkgn(int max_n, int st) {
//    cout << "check:\n";
    for (int i = 1; i <= max_n; ++i) {
//      cout << gn[i].ed <<"  "<<st <<"\n";
      if(gn[i].ed < st) {
        gn[i].ed = 1e9;
        return 1;
      } 
    }
    return 0;
  }
  
  int Checkgy(int max_n, int st) {
    for (int i = 1; i <= max_n; ++i) {
      if(gy[i].ed < st) {
        gy[i].ed = 1e9;
        return 1;
      }
    }
    return 0;
  }
  
  void main() {
    for (int i = 0; i <= n; ++i) {
      for (int j = 1; j <= m_1; ++j) gn[j] = Gn[j];
      for (int j = 1; j <= m_2; ++j) gy[j] = Gy[j];
      int las_gn = 0, las_gy = 0;
      int lim1 = i, lim2 = n - i, ans1 = 0, ans2 = 0;
//        cout <<"lim:  " << lim1 <<" " << lim2 <<"\n";
      if(i != 0) {
        for (int j = 1; j <= m_1; ++j) {
//          cout <<i<<"\n";
//          for (int k = 1; k <= m_1; ++k) cout << gn[k].st <<"  " << gn[k].ed <<"\n";
          if(lim1 > 0) ans1++, lim1--, las_gn  = j;
          else {
              lim1 += Checkgn(las_gn, gn[j].st);
//              cout <<"lim1: "<< lim1 <<"\n";
              if(lim1 > 0) ans1++, lim1--, las_gn = j;
              else gn[j].ed = 1e9;
          }
//          cout <<" las_gn: " << las_gn <<" " << "lim1: " << lim1 <<" ans1: " << ans1<<"\n";
//          puts("");
        }
      }
      if(i != n) {
        for (int j = 1; j <= m_2; ++j) {
          if(lim2 > 0) ans2++, lim2--, las_gy = j;
          else {
             lim2 += Checkgy(las_gy, gy[j].st);
             if(lim2 > 0) ans2++, lim2--, las_gy = j;
             else gy[j].ed = 1e9;
          }
//          cout << " las_gy: " << las_gy << " lim2: " << lim2 <<" ans2: " << ans2 <<"\n";
        }
      }
      ans = max(ans, ans1 + ans2);
//      cout << ans1<<" " << ans2<<"\n";
//      cout << ans <<"\n" ;
//      puts("");
    }
    cout << ans;
    return ;
  }
  
}
//===============================================
int main() {
	freopen("airport.in","r", stdin);
	freopen("airport.out","w",stdout);
  n = read(), m_1 = read(), m_2 = read();
  for (int i = 1; i <= m_1; ++i) Gn[i].st = read(), Gn[i].ed = read();
  for (int i = 1; i <= m_2; ++i) Gy[i].st = read(), Gy[i].ed = read();
  sort(Gn + 1, Gn + m_1 + 1, cmp), sort(Gy + 1, Gy + m_2 + 1, cmp);
//  for (int i = 1; i <= m_1; ++i) cout << gn[i].st <<" " << gn[i].ed <<" ";puts("") ;
//  for (int i = 1; i <= m_2; ++i) cout << gy[i].st <<" " << gy[i].ed <<" ";puts("") ;
  substest1::main();
  
  
	fclose(stdin), fclose(stdout);
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

/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
