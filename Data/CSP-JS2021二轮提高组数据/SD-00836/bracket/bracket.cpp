#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define LL long long
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 6e2 + 10; 
int n,m,F = false;
int st[MAXN],top,a[MAXN],res;
LL Ans = 0;
char s[MAXN],t[MAXN];
int read()
{
	int s = 0,f = 0;char ch = getchar();
	while(!isdigit(ch)) f |= ch == '-',ch = getchar();
	while(isdigit(ch)) s = (s << 3) + (s << 1) + (ch ^ 48),ch = getchar();
	return f ? -s : s;
}
int judge(int pos)
{
	if(pos == 0) return 0;
	int xing = 0,res = 0,ret = 0;
	if(!F) return 0;
	for(int i = pos;i <= n;i ++) {
		if(t[i] == '*') xing ++;
		if(t[i] == '(') {
			res ++;
			i = judge(i + 1);
			if(i == 0) return 0; 
			if(xing) xing = 0,ret ++;
		}
		else if(t[i] == ')') {
			if(xing) ret ++,xing = 0;
			if(ret > res && res) F = false; 
			return i;
		}
		if(xing > m) F = false;
	} 
	return 0;
}
bool check()
{
	res = 0;
	for(int i = 1;i <= n;i ++) {
		if(t[i] == '(') a[++ res] = 1;
		else if(t[i] == ')') {
			if(a[res] == 1) res --;
			else return false; 
		}
	}
	if(res) return false;//ÅÐ¶Ï×Ö·û´®ÊÇ·ñºÏ·¨
	if(t[1] == '*' || t[n] == '*') return false; 
	F = true;
	judge(1);
	if(F) return true;
	else return false;
}
void DFS(int id)
{
	if(id == top + 1) {
		if(check()) {
			Ans = (Ans + 1) % mod;
		}
		return;
	}
	t[st[id]] = '(';
	DFS(id + 1);
	t[st[id]] = ')';
	DFS(id + 1);
	t[st[id]] = '*';
	DFS(id + 1);
	return; 
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n = read(),m = read();
	cin >> s + 1;
	for(int i = 1;i <= n;i ++) {
		if(s[i] == '?') st[++ top] = i;
		t[i] = s[i];
	} 
	DFS(1);
	Ans = (Ans + mod) % mod;
	printf("%lld\n",Ans); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
20 4
???????????????????? 
*/

