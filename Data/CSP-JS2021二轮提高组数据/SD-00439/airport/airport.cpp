#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<cstring>

using namespace std;

const int MAXSIZE = 1e5+7;

int n=0;
int m1=0;
int m2=0;
int ans=-1;

struct zudui{
	int down;
	int taof;
};

zudui guonei[MAXSIZE];
zudui guowai[MAXSIZE];

//bool ffff[MAXSIZE];

queue<int> q;

struct que{
	int a[MAXSIZE];
	int head;
	int tail;
	
	void init(){
		head=0;
		tail=0;
	}
	
	bool empty(){
		if(head==tail){
			return 1;
		}
		return 0;
	}
	
	int front(){
		return a[head];
	}
	
	bool pop(){
		if(empty()){
			return 0;
		}
		head=(head+1)%MAXSIZE;
		return 1;
	}
	
	bool push(int i){
		tail=(tail+1)%MAXSIZE;
		a[tail]=i;
		return 1;
	}
	
	bool pushhead(int i){
		head=(head+MAXSIZE-1)%MAXSIZE;
		a[head]=i;
		return 1;
	}
	
	int back(){
		return a[tail];
	}
};

bool cmp(zudui a,zudui b){
	if(a.down<b.down){
		return 1;
	}
	return 0;
}

void init(){
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=0;i<m1;i++){
		scanf("%d%d",&guonei[i].down,&guonei[i].taof);
	}
	sort(guonei,guonei+m1,cmp); 
	for(int i=0;i<m2;i++){
		scanf("%d%d",&guowai[i].down,&guowai[i].taof);
	}
	sort(guowai,guowai+m2,cmp);
}

void apt(int fu,int fule){
//	cout<<1<<' ';
	int temp=0;
	for(int i=0;i<m1;i++){
		if(!q.empty()){
			while(!q.empty() && guonei[q.front()].taof<guonei[i].down){
//				ffff[q.front()]=0;
				q.pop();
			}
		}
		
		if(q.size()<fu){
//			cout<<2<<' ';
			temp++;
//			ffff[i]=1;
			q.push(i);
		}
	}
	while(!q.empty()){
		q.pop();
	}
	for(int i=0;i<m2;i++){
		while(!q.empty() && guowai[q.front()].taof<guowai[i].down){
//			ffff[q.front()]=0;
			q.pop();
		}
		if(q.size()<fule){
//			cout<<2<<' ';
			temp++;
//			ffff[i]=1;
			q.push(i);
		}
	}
	while(!q.empty()){
		q.pop();
	}
//	cout<<endl;
	ans=max(ans,temp);
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	init();
	
	for(int i=0,j=n;i<=n;i++,j--){
		apt(i,j);
	}
	
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	//十年阳寿换有分，知道bug不会de 
	return 0;
} 

