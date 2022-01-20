#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int Card[50], Bk[50];

int TurnF(char x);
char TurnS(int x);
bool Cmp(int x, int y);

int main() {
	freopen("In.in", "r", stdin);

	for(int i = 0; i < 7; i++) {
		string X;
		cin>>X;
		if(X.size() == 1) {
			if(X[0] >= '1' && X[0] <= '9') {
				Card[i] = X[0] - '1' + 1;
				Bk[X[0] - '1' + 1]++;	
			}else {
				Card[i] = TurnF(X[0]);
				Bk[TurnF(X[0])]++;
			}
		}else {
			Card[i] = 10;
			Bk[10]++;
		}
	}

	sort(Card, Card + 7, Cmp);

	for(int i = 14; i >= 2; i--) {
		if(Bk[i] == 4) {
			for(int z = 1; z < 4; z++) i != 10 ?  printf("%c ", TurnS(i)) : printf("10 ");
			i != 10 ? printf("%c", TurnS(i)) : printf("10");
			return 0;
		}
	}

	for(int i = 14; i >= 2; i--) {
		if(Bk[i] == 3) {
			for(int j = 14; j >= 2; j--) {
				if(j == i) continue;
				if(Bk[j] >= 2) {
					if(j > i) {
						for(int v = 1; v <= 2; v++) if(j != 10) printf("%c ", TurnS(j)); else printf("10 ");
						for(int v = 1; v <= 2; v++) if(i != 10) printf("%c ", TurnS(i)); else printf("10 "); 
						if(i != 10) printf("%c", TurnS(i)); else printf("10");
					}else {
						for(int v = 1; v <= 3; v++) if(i != 10) printf("%c ", TurnS(i)); else printf("10");
						for(int v = 1; v <= 1; v++) if(j != 10) printf("%c ", TurnS(j)); else printf("10");
						if(i != 10) printf("%c", TurnS(j)); else printf("10");
					}
					return 0;
				}
			}
		}
	}

	if(Bk[14]) Card[7] = 1;
	for(int i = 0; i <= 3; i++) {
		if(Card[i] == Card[i+1] - 1 && Card[i+1] == Card[i+2] -1 && Card[i+2] == Card[i+3] - 1 && Card[i+3] == Card[i+4] - 1) {
			for(int j = i; j < i + 4; j++) if(Card[j] !=10) printf("%c ", TurnS(Card[j])); else printf("10 ");
			if(Card[i+4] != 10) printf("%c", TurnS(Card[i+4])); else printf("10");
			return 0;
		}
	}

	int T[10];
	for(int i = 14; i >= 2; i--) {
		if(Bk[i] == 3) {
			for(int j = 14; j >= 2; j--) {
				if(j == i) continue;
				if(Bk[j])
				for(int v = 14; v >= 2; v--) {
					if(v == j || v == i) continue;
					if(Bk[v]) {
						if(v > j) swap(v, j);
						if(i > v && i > j) {
							for(int z = 1; z <= 3; z++) i != 10 ? printf("%c ", TurnS(i)) : printf("10 ");
							j != 10 ? printf("%c ", TurnS(j)) : printf("10 ");
							v != 10 ? printf("%c", TurnS(v)) : printf("10");
						}else if(i < j && i > v) {
							j != 10 ? printf("%c ", TurnS(j)) : printf("10 ");
							for(int z = 1; z <= 3; z++) i != 10 ? printf("%c ", TurnS(i)) : printf("10 ");
							v != 10 ? printf("%c", TurnS(v)) : printf("10");
						}else {
							j != 10 ? printf("%c ",TurnS(j)) : printf("10 ");
							v != 10 ? printf("%c ", TurnS(v)) : printf("10 ");
							for(int z = 1; z <= 2; z++) i != 10 ? printf("%c ", TurnS(i)) : printf("10 ");
							i != 10 ? printf("%c", TurnS(i)) : printf("10");
						}
						return 0;
					}
				}
			}
		}
	}

	for(int i = 14; i >= 2; i--) {
		if(Bk[i] == 2)
		for(int j = 14; j >= 2; j--) {
			if(j == i) continue;
			if(Bk[j] == 2) 
			for(int v = 14; v >= 2; v--) {
				if(v == j || v == i) continue;
				if(Bk[v]) {
					if(v < j) {
						for(int z = 1; z <= 2; z++) i != 10 ? printf("%c ", TurnS(i)) : printf("10 ");
						for(int z = 1; z <= 2; z++) j != 10 ? printf("%c ", TurnS(j)) : printf("10 ");
						v != 10 ? printf("%c", TurnS(v)) : printf("10");
					}else if(v > j && v < i) {
						for(int z = 1; z <= 2; z++) i != 10 ? printf("%c ", TurnS(i)) : printf("10 ");
						v != 10 ? printf("%c ", TurnS(v)) : printf("10 ");
						j != 10 ? printf("%c ", TurnS(j)) : printf("10 ");
						j != 10 ? printf("%c", TurnS(j)) : printf("10");
					}else if(v > i) {
						v != 10 ? printf("%c ", TurnS(v)) : printf("10 ");
						for(int v = 1; v <= 2; v++) i != 10 ? printf("%c ", TurnS(i)) : printf("10 ");
						j != 10 ? printf("%c ", TurnS(j)) : printf("10 ");
						j != 10 ? printf("%c", TurnS(j)) : printf("10");
					}
					return 0;
				}
			}
		}
	}

	for(int i = 14; i >= 2; i--) {
		if(Bk[i] == 2) 
		for(int j = i-1; j >= 2; j--) {
			if(Bk[j]) 
			for(int v = j-1; v >= 2; v--) {
				if(Bk[v])
				for(int z = v-1; z >= 2; v--) {
					if(Bk[z]) {
						for(int i = 1; i <= 2; i++) i != 10 ? printf("%c ", TurnS(i)) : printf("10 ");
						j != 10 ? printf("%c ", TurnS(j)) : printf("10 ");
						v != 10 ? printf("%c ", TurnS(v)) : printf("10 ");
						z != 10 ? printf("%c", TurnS(z)) : printf("10");
						return 0;
					}
				}
			}
		}
	}

	for(int i = 0; i < 4; i++) {
		Card[i] != 10 ? printf("%c ", TurnS(Card[i])) : printf("10 ");
	}
	Card[4] != 10 ? printf("%c", TurnS(Card[5])) : printf("10");

	return 0;
}


int TurnF(char x) {
	switch(x) {
		case 'J': return 11;
		case 'Q': return 12;
		case 'K': return 13;
		case 'A': return 14;
	}
	return x;
}

char TurnS(int x) {
	if(x >= 2 && x < 10) return x + 48;
	else {
		switch(x) {
			case 11: return 'J';
			case 12: return 'Q';
			case 13: return 'K';
			case 14: return 'A';
		}
	}
}

bool Cmp(int x, int y) {
	return x > y;
}



















