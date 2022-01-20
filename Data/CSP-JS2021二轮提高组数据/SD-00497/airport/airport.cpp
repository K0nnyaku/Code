#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;
const int N=5e3+10;
int n,m1,m2,ans;
priority_queue <int>q1;
priority_queue <int>q2;
struct node
{
	int st,en;
};
node n1[N],n2[N];
bool cmp(node a,node b)
{
	return a.st>b.st;
}

int check1(int num){
	if(num==0) {
		return 0;
	}
	int an=0;
	for(int i=1;i<=m1;i++){
		if(num>0){
			num--;
			q1.push(n1[i].en);
			//cout<<q1.top()<<" ";
			an++;
		}else{
			int now=q1.top();
			if(now>n1[i].st){
				an++;
				q1.pop();
				q1.push(n1[i].en);
				//cout<<q1.top()<<" ";
			}
		}
	}
	//cout<<an<<endl;
	return an;
} 
int check2(int num){
	if(num==0) {
		return 0;
	}
	int an=0;
	for(int i=1;i<=m2;i++){
		if(num>0){
			num--;
			q2.push(n2[i].en);
			//cout<<q2.top()<<" ";
			an++;
		}else{
			int now=q2.top();
			if(now>n2[i].st){
				an++;
				q2.pop();
				q2.push(n2[i].en);
				//cout<<q2.top()<<" ";
			}
		}
	}
	//cout<<an<<endl;
	return an;
} 
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d %d",&n1[i].st,&n1[i].en);
		n1[i].st*=-1,n1[i].en*=-1;
	}
	/*for(int i=1;i<=m1;i++){
		cout<<n1[i].st<<" "<<n1[i].en<<endl;
	}*/
	for(int i=1;i<=m2;i++){
		scanf("%d %d",&n2[i].st,&n2[i].en);
		n2[i].st*=-1,n2[i].en*=-1;
	}
	stable_sort(n1+1,n1+m1+1,cmp);
	stable_sort(n2+1,n2+m2+1,cmp);
	for(int i=0;i<=n;i++)
	{
		int j=n-i;
		ans=max(ans,check1(i)+check2(j));
	}
	printf("%d",ans);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10


*/
