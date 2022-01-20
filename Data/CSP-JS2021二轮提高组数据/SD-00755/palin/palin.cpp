#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>
using namespace std;

int T,n,cnt=0;
deque<int> a,ck;
int b[1000010];
char pth[1000010];

inline bool huiwen(){
	for(int i=0;i<n;i++){
		if(b[i]!=b[2*n-1-i]) return false;
	}
	return true;
}

bool jdg(int dep){
	if(ck.empty()) return true;
	if(ck.front()!=b[dep]&&ck.back()!=b[dep]) return false;
	if(ck.front()==b[dep]){
		int fr=ck.front();
		ck.pop_front();
		cnt++;
		pth[cnt]='L';
		if(jdg(dep+1)){
			return 1;
		}
		cnt--;
	}
	if(ck.back()==b[dep]){
		int fr=ck.back();
		ck.pop_back();
		cnt++;
		pth[cnt]='R';
		if(jdg(dep+1)){
			return 1;
		}
		cnt--;
	}
	return false;
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<2*n;i++){
			int x;
			scanf("%d",&x);
			a.push_back(x);
			b[i]=x;
		}
		sort(b,b+2*n);
		bool f=0;
		do{
			if(huiwen()){
				ck=a;
				cnt=0;
				if(jdg(0)){
					f=1;
					for(int i=1;i<=cnt;i++){
						putchar(pth[i]);
					}
					putchar('\n');
					break;
				}
			}
		}while(next_permutation(b,b+2*n));
		if(!f)
		printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 5 3 1 2 2 1 3 5 4
*/
