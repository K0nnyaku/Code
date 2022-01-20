#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);
#define T(x) E[x].to
#define V(x) E[x].val

const int MB=1<<21;
struct FastIN
{
	char buf[MB+100],*p,*e;
	int getChar()
	{
		if(p==e) p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

const int MAXN = 1e3 + 10;
const int MAXHP = 4;

struct Pig {
	deque<int> Hand;	
	int Kind[10];
	int hp, res;
	int chr;
	int chw;
	int pos;
	bool wp;

	void GetCard(char ch);

	void ExuMp();
	void ExuFp();
	void ExuZp();
	void UseKill();
	void UseD();
	void UseAll();
	bool ExuAll(int ch);

	Pig() {
		Hand.clear(); memset(Kind, 0, sizeof Kind);
		chr = res = chw = pos = 0; hp = 4;
	}

} P[MAXN];

char Card[MAXN];
int n, m;

int H(char ch);

int main() { /**/
	IN >> n >> m;
	IOR(i, 1, n+1) {
		char ch = getchar();
		switch(ch) {
			case 'M' : P[i].chr = 1;
					   break;
			case 'F' : P[i].cha = 2;
					   break;
			dafault : P[i].chr = 3;
		}
		IOR(v, 0, 4) {
			getchar();
			ch = getchar();	
			P[i].GetCard(ch);
		}
		P[i].pos = i;
		getchar();
	}

	IOR(i, 0, m) {
		char ch = getchar(); getchar();
		Card.push_back(H(ch));
	}

	return 0;
} /**/

int H(char ch) {
	switch(ch) {
		case 'P' return 1;
		case 'K' return 2;
		case 'D' return 3;
		case 'F' return 4;
		case 'N' return 5;
		case 'W' return 6;
		case 'J' return 7;
		case 'Z' return 8;
	}
}

void Pig::GetCard(char ch) {
	Hand.push_back(H(ch));
	res++;
	Kind[H(ch)]++; 
}

void Pig::ExuMp() {
	IOR(i, 0, Hand.size()) {
		if(ExuAll(Hand[i])) continue;
		
		if(Hand[i] == 2) {
			IOR(v, 1, n+1) {
				int to = (v + pos) % n;
				if(P[to].hp && Dis(pos, to) <= 1)
						if(P[to].chrw == 1 || P[to].chrw == 2) {
							UseKill(to);
						}
			}
		}
	}
}

void Pig::UseKill(int to) {
	P[to].UseD();	
}

void Pig::UseD() {
	if(Kind[3]) {

	}
}

void Pig::UseAll() {
	Kind[H(Hand.front())]--;
	res--;
	Hand.pop_front();
}

bool Pig::ExuAll(int x) {
	if(x == 1) {
		UseAll();
		hp++; hp = min(hp, MAXHP); return 1;
	}

	if(x == 5) {
		UseAll();
		UseN(); return 1;
	}

	if(x == 6) {
		UseAll();
		UseW(); return 1;
	}

	if(x == 8) {
		UseAll();
		wp = 1; return 1;
	 }
}



 
