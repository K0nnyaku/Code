#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAX = 5e5 + 10;

class PAM {
public:	
	int len;
	int sum; 
	PAM* fail;
	PAM* ch[30];

	void Init(int, PAM*, PAM*);
	void New(int,int);
	PAM* Gf(int);
	
}*Ev, *Od, *last;

char s[MAX];
int t, k, Index;

int main() { /**/
	Ev = new PAM; Od = new PAM;
	Ev->Init(0, Od, Ev);  Od->Init(-1, Ev, Ev); 
	last = Ev;
	
	cin>>s+1;
	t = strlen(s+1);
	
	for(int  i = 1; i <= t; i++) {
		s[i] = (s[i] - 97 + k) % 26 + 97;
		int T = s[i] - 'a';
		last = last->Gf(i);	 
		
		if(last->ch[T] == Ev) last->New(T,i);
		
		last = last->ch[T];
		
		printf("%d ",last->sum);
		k = last->sum;
	}	
	return 0;
} /**/

void PAM::Init(int k, PAM* to, PAM* z) { 
	len = k; fail = to; 
	for(int i = 0; i < 30; i++) ch[i] = z; 
}
void PAM::New(int k, int pos) { 
	PAM* Tch = new PAM;
	Tch->Init(len+2, fail->Gf(pos)->ch[k], Ev); 
	Tch->sum = Tch->fail->sum + 1;
	ch[k] = Tch;	Index++; 
}
PAM* PAM::Gf(int pos) { return s[pos-len-1] == s[pos] ? this : fail->Gf(pos); }

