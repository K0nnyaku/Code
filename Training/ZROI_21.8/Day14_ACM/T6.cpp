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

const int MAXN = 1e2 + 10;


int n,k;
int a[MAXN][MAXN];

inline void down() {
    for(int i=n;i>=1;i--) {
        for(int j=1;j<=n;j++) {
            if(a[i][j]) {
                for(int x=n;x>=1;x--) { //find a place to put
                    if(!a[x][j]) {
                        a[x][j]=a[i][j];
                        a[i][j]=0;
                        break;
                    }
                }
            }
        }
    }
}

inline void up() {  // note:error
    for(int i=n;i>=1;i--) {
        for(int j=1;j<=n;j++) {
            if(a[i][j]) {
                for(int x=1;x<=n;x++) { //find a place to put
                    if(!a[i][x]) {
                        a[i][x]=a[i][j];
                        a[i][j]=0;
                        break;
                    }
                }
            }
        }
    }
}


inline void lft() { 
    for(int i=n;i>=1;i--) {
        for(int j=1;j<=n;j++) {
            if(a[i][j]) {
                for(int x=1;x<=n;x++) { //find a place to put
                    if(!a[i][x]) {
                        a[i][x]=a[i][j];
                        a[i][j]=0;
                        break;
                    }
                }
            }
        }
    }
}



inline void rgt() { 
    for(int i=n;i>=1;i--) {
        for(int j=n;j>=1;j--) {
            if(a[i][j]) {
                for(int x=n;x>=1;x--) { //find a place to put
                    if(!a[i][x]) {
                        a[i][x]=a[i][j];
                        a[i][j]=0;
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    freopen("In.in", "r", stdin); 
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%d",&a[i][j]);
        }
    }

    rt();
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}