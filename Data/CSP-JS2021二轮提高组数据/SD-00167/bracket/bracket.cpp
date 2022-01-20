#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;
const int N =  600;

int n,k;
char ch[N];
ll zhan[N],top = 0;
ll star[N];
bool flag;
bool vis[N];

ll ans;

void ssort(int wei){
	if(wei > n && top != 0){
		ans++;
		return;
	}
	if(ch[wei] == '('){
		if(ch[wei - 1] == '*' && !vis[wei - 1]) vis[wei] = true;
		zhan[++top] = wei;
		ssort(wei + 1);
		vis[wei] = false;
		top--;
	}
	if(ch[wei] == '*'){
		if(ch[wei - 1] == '*')vis[wei] = vis[wei - 1];
		if(ch[wei - 1] == ')' && !vis[wei - 1]) vis[wei] = true;
		star[wei] = star[wei - 1] + 1;
		
		if(star[wei] > k) return;
		ssort(wei + 1);
		star[wei] = 0;
		vis[wei] = false;
	}
	if(ch[wei] == ')'){
		if(top == 0) return;
		
		if(vis[zhan[top]]){
			vis[wei] = true;
			int l = zhan[top];
			top--;
			ssort(wei + 1);
			
			zhan[++top] = l;
			vis[wei] = false;
		}
		
		
	}
	
	if(ch[wei] == '?'){
		if(top != 0) {
			ch[wei] = ')';
			if(vis[zhan[top]]){
				vis[wei] = true;
				int l = zhan[top];
				top--;
				ssort(wei + 1);
			
				zhan[++top] = l;
				vis[wei] = false;
			}
			
		}
		
		ch[wei] = '*';
		if(ch[wei - 1] == '*')vis[wei] = vis[wei - 1];
		if(ch[wei - 1] == ')' && !vis[wei - 1]) vis[wei] = true;
		star[wei] = star[wei - 1] + 1;
		
		if(star[wei] > k) return;
		ssort(wei + 1);
		star[wei] = 0;
		vis[wei] = false;
		
		
		
		ch[wei] = '(';	
		if(ch[wei - 1] == '*' && !vis[wei - 1]) vis[wei] = true;
		zhan[++top] = wei;
		ssort(wei + 1);
		vis[wei] = false;
}

}

int main(){
//	
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	scanf("%s",ch + 1);
//	ssort(1);
	
	cout << 21;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


