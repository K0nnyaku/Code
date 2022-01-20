#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAX = 500000 + 10;

class PAM {
public: 
    int len; 
    PAM* fail; 
    PAM* trans;
    PAM* ch[30];

    void Init(int, PAM*, PAM*); 
    void New(int,int);
    PAM* Gf(int); 
    PAM* Gt(int,int);

}*Ev, *Od, *last;

int t, k, Index, ans;

int main() { /**/
    Ev = new PAM; Od = new PAM; //Ev偶根 Od奇根 
    Ev->Init(0, Od, Ev);  Od->Init(-1, Ev, Ev);  
    last = Ev;

    cin >> t;
    for(int i = 1; i <= t; i++) {
        char x;
        cin >> x;
        int T = x - 'a';
        last = last->Gf(i);  

        if(last->ch[T] == Ev) last->New(T,i);
        last = last->ch[T];

        if(last->len % 4 == 0 and last->trans->len == last->len/2) ans = max(ans, last->len);
    }
    printf("%d", ans);  
    return 0;
} /**/

void PAM::Init(int k, PAM* to, PAM* z) { //初始化, 
    len = k; fail = to; trans = fail; //trans默认为fail 
    for(int i = 0; i < 30; i++) ch[i] = z; 
}
void PAM::New(int k, int pos) { //新建节点 
    PAM* Tch = new PAM;
    Tch->Init(len+2, fail->Gf(pos)->ch[k], Ev); //初始化  len和 fail , trans默认为fail 

    if(Tch->len > 2) Tch->trans = trans->Gt(pos, Tch->len)->ch[k];  //如果新节点长度大于2, 从他的父亲(即last)的trans开始跳 
    ch[k] = Tch;    
}
PAM* PAM::Gf(int pos) { return s[pos-len-1] == s[pos] ? this : fail->Gf(pos); } //跳fail 
PAM* PAM::Gt(int pos, int now) { return s[pos-len-1] != s[pos] or (len + 2) * 2 > now ? fail->Gt(pos, now) : this; } //跳trans 