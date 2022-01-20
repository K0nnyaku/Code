#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>

using namespace std;

char a[100001];
int n;
int num[100001];
int k;
int h = 0;
int ans = 0;

void sol(int de){
	if(de > h){
		if(a[1] != '(' || a[n] != ')') return ;
		int cnt = 0;
		int fl = 0;
		int head = 0;
		int no[5002] = {0};
		int c2=0,c3=0;
		int c1 = 0;
		for(int i = 1;i <= n;i++){
			head++;
			if(a[i] == '('){
				c1++;
				c2++;
				no[c1] = head;
				cnt = 0;
			}
			if(a[i] == ')'){
				head = no[c1] - 1;
				c1--;
				c3++;
				cnt = 0;
			}
 			if(a[i] == '*') cnt++;
			if(cnt > k){
				fl = 1;
				break ;
			}
		}
		if(head == 0 && fl != 1 && c2 == c3) ans++;
		return ;
	}
	a[num[de]] = ')';
	de++;
	sol(de);
	de--;
	a[num[de]] = '(';
	de++;
	sol(de);
	de--;
	a[num[de]] = '*';
	de++;
	sol(de);
	de--;
}

int main(){

	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&k);
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] == '?'){
			h++;
			num[h] = i;
		}
	}
	sol(1);
	printf("%d\n",ans + 1);
//	printf("%d",cc);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}


