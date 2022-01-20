#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;
const int M=1e6+5;
int a[M],n;
char b[M];
int f=1,r=2*n;
queue<int> q;
int idx=1,r1=1;
stack<int> st1,st2;
bool judge(int x){
	if(a[f]==x){
		b[idx++]='L';
		f++;
		return 1;
	}
	if(a[r]==x){
		b[idx++]='R';
		r--;
		return 1;
	}
	return 0;
}
//void bfs(int x){
//	idx=1;
//	if(!st1.empty()||!st2.empty()){
//		
//	}
//}
int main(){
	freopen("palin.in","r",stdin);
    freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t){
		t--;
		r1=1;
		idx=1;
		memset(a,0,sizeof a);
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		st1.push(a[f]);
		f++;
		b[idx++]='L';
		int l=st1.top(),flag=0;
		for(int i=1;i<=2*n;i++){
			if(!st1.empty()){
				if(st1.size()>n){
					cout<<-1;
					puts("");
					r1=0;
					break;
				}
			}
			if(!st2.empty()){
				if(st2.size()>n){
					cout<<-1;
					puts("");
					r1=0;
					break;
				}
			}
			if(judge(l)){
				st2.push(l);
				flag=1;
				continue;
			}
			if(flag){
				l=a[f];
				flag=0;
			}
			st1.push(l);
			f++;
			b[idx++]='L';
		}
		if(r1){
		for(int i=1;i<idx;i++) cout<<b[i];
		puts("");
	}
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
}
