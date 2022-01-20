#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;

struct tim{
	int arr;
	int lea;
	bool operator <(const tim &x)const{
		return x.lea<lea;
	}
};

priority_queue<tim> q1;
priority_queue<tim> q2;

tim inp[100010],outp[100010];
int inb,outb,ans,n,m1,m2;;

bool comp(tim a,tim b){
	return a.arr<b.arr;
}

int solve(int ib,int ob){
	int tot=0;
	for(int i=0;i<m1;i++){
		if(ib>0){
			q1.push(inp[i]);
			tot++;
			ib--;
		}
		else{
			while(!q1.empty()&&q1.top().lea<inp[i].arr){
				q1.pop();
				ib++;
			}
			if(ib>0){
				tot++;
				q1.push(inp[i]);
				ib--;
			}
		}
	}
	for(int i=0;i<m2;i++){
		if(ob>0){
			q2.push(outp[i]);
			tot++;
			ob--;
		}
		else{
			while(!q2.empty()&&q2.top().lea<outp[i].arr){
				q2.pop();
				ob++;
			}
			if(ob>0){
				tot++;
				q2.push(outp[i]);
				ob--;	
			}
		}
	}
	return tot;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=0;i<m1;i++){
		cin>>inp[i].arr>>inp[i].lea;
	}
	for(int i=0;i<m2;i++){
		cin>>outp[i].arr>>outp[i].lea;
	}
	sort(inp,inp+m1,comp);
	sort(outp,outp+m2,comp);	
	for(int i=0;i<=n;i++){
		inb=i;
		outb=n-i;
		ans=max(ans,solve(inb,outb));
	}
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
