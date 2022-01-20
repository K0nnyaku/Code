#include<bits/stdc++.h>

using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MB=1<<21;
struct FastIO {
	char buf[MB+100],*p,*e;
	int getChar() { if(p==e)p=buf,e=buf+fread(buf,1,MB,stdin); return p==e?EOF:*p++; }
	template<typename T>
	FastIO& operator>>(T& x) { char c,l; for(c=0;!isdigit(c);c=getChar())l=c; for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c; if(l=='-')x=-x; return *this; }
};

const int MAXN = 1e5 + 10;

char str[MAXN];

int main() {
    str[0]=' ';
    gets(str+1);
    int len = strlen(str+1);
    for(int i=1;i<=len;i++) {
        if(str[i-1]==' ') {
            if('A'<=str[i] && str[i]<='Z') {
                str[i]=str[i]-'A'+'a';
                while(i<strlen(str) && str[i]!=' ') i++;
                str[i-1]=str[i-1]-'a'+'A';
            }
        }
    }
    for(int i=len;1<=i;i--) {
        putchar(str[i]);
    }
    return 0;
}