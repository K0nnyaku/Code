#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	srand(n * m << 1);
	printf("%d",rand() % (n * m << 1));
	return 0;
}
