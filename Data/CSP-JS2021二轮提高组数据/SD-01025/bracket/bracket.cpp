#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string> 
#include<queue>
#define ll long long
using namespace std;

const int maxn = 100010;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

inline int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w = -1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9'){
		s = (s<<1) + (s<<3) + (ch^48);
		ch = getchar();
	}
	return s * w;
}

inline void write(int x){
	char f[200];int cnt = 0;
	if(x<0){
		putchar('-');
		x = -x;
	}
	while(x){
		f[++cnt] = x % 10 + '0';
		x /= 10;
	}
	while(cnt){
		putchar(f[cnt]);
		cnt--;
	}
	return;
}

ll ksm(ll a,ll b,ll mod){
	ll ans = 1;
	while(b)
	{
		if(b&1){
			ans = ans * a % mod;
		}
		a = a * a % mod;
		b>>=1;
	}
	return ans;
} 

int n,k;
int top;
int stac[505];

string s;

int main()
{
	freopen("bracket","r",stdin);
	freopen("bracket","w",stdout);
	
	n = read(),k = read();
	
	cin>>s;

	if(s[0]=='('){
		s[n-1] = ')';
	}

	for(int i=0;i<s.size();++i){
		if(s[i]=='?'){
			stac[++top] = i;
		}
	}
	
	int cnt = 0;
	
	int t = 0;
	
	for(int i=0;i<s.size();++i){
		if(s[i]=='*'||s[i]=='?'){
			cnt++;
		}
		else{
			t+=cnt;
			cnt = 0;
		}
	}
	
	if(top==1){
		top=2;
	}
	
	cout<<(ksm(top,3,mod)-(top-2)*ksm(t,2,mod)+top);

	return 0;
}

