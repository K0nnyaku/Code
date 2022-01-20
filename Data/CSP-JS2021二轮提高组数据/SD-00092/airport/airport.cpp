#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
const int INF=0x3f3f3f3f;
//m1指m1有多少飞机 
const int N=1e5+10;
struct node{
	int come;
	int leave;
	int flag;
};
int cmp(node x,node y){
	return (x.come<y.come);
}
node m1_list[N];
node m2_list[N];
int m1_ans[N];
int m2_ans[N]; 
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>m1_list[i].come;
		cin>>m1_list[i].leave;
		m1_list[i].flag=1;
	}
	for(int i=1;i<=m2;i++){
		cin>>m2_list[i].come;
		cin>>m2_list[i].leave;
		m2_list[i].flag=1;
	}
	m1_ans[0]=0;
	m2_ans[0]=0;
	for(int i=1;i<=n;i++){
		//寻找每次循环第一个飞机st
		int st=1;
		int f=0;
		for(int j=1;j<=m1;j++){
			if(m1_list[j].flag==1){
				m1_list[j].flag=0;
				st=j;
				m1_ans[i]++;
				f=1;
				break;
			}
		}
		if(f==0)break; 
//		cout<<st<<"____"<<endl;
		int now_leave=m1_list[st].leave;
		for(int j=st;j<=m1;j++){
			if(m1_list[j].come>now_leave&&m1_list[j].flag==1){
//				cout<<m1_list[j].come<<' '<<now_leave<<endl;
				m1_ans[i]++;
				now_leave=m1_list[j].leave;
				m1_list[st].flag=0;
				st=j;
			}
		}
//		for(int j=1;j<=m1;j++){
//			if(m1_list[j].flag==0)cout<<'o'<<' ';
//			else cout<<'x'<<' ';
//		}
//		cout<<endl;
	}
	
	for(int i=1;i<=n;i++){
		//寻找每次循环第一个飞机st
		int st=1;
		int f=0;
		for(int j=1;j<=m2;j++){
			if(m2_list[j].flag==1){
				m2_list[j].flag=0;
				st=j;
				m2_ans[i]++;
				f=1;
				break;
			}
		}
		if(f==0)break;
		int now_leave=m2_list[st].leave;
		for(int j=st;j<=m2;j++){
			if(m2_list[j].come>now_leave&&m2_list[j].flag==1){
				m2_ans[i]++;
				now_leave=m2_list[j].leave;
				m2_list[st].flag=0;
				st=j;
			}
		}
	}
	int ans1[N];
	int ans2[N];
	for(int i=1;i<=n;i++){
		ans1[i]=ans1[i-1]+m1_ans[i];
	}
	for(int i=1;i<=n;i++){
		ans2[i]=ans2[i-1]+m2_ans[i];
	}
	int maxx=-INF;
	for(int i=0;i<=n;i++){
//		if(maxx<(ans1[i]+ans2[n-i]))cout<<i<<endl;
		maxx=max(maxx,(ans1[i]+ans2[n-i]));
	}
	cout<<maxx<<endl;
//	cout<<m1_ans[2]<<endl;
//	cout<<ans1[1]<<' '<<ans2[n-1]<<endl;
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 
