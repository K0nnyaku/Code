#include <bits/stdc++.h>   // y1,y2���� 
//#define int long long   //�Ƿ�long long(��ull) ���߲���int(ע�͵�) ���߱�ull(��ƽ) 
using namespace std;  //������ע���ͻ 
const int MAXN=1e5+5;    //���鿪������ 
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}struct node {
	int a,b;
}p1[MAXN],p2[MAXN];
bool cmp(node a,node b) {return a.a<b.a;}
priority_queue<int,vector<int>,greater<int> > q;
int main ()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);        //�����ͱ�0.......
	int n,m1,m2,ans=-1;
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++) p1[i].a=read(),p1[i].b=read();
	for(int i=1;i<=m2;i++) p2[i].a=read(),p2[i].b=read();
	sort(p1+1,p1+1+m1,cmp);
	sort(p2+1,p2+1+m2,cmp);
	for(int x=0;x<=n;x++){   //ö�ٷּ��������� 
		int temp=x,cnt=0;	
		while(q.size()) q.pop();
		//cout<<q.size()<<" ";
		for(int i=1;i<=m1;i++){
			if(q.size()) if(p1[i].a>=q.top()) {q.pop(); temp++;}
			//cout<<"DONE";
			if(temp){
				cnt++; q.push(p1[i].b); temp--;
			}
		}
		temp=n-x;
		//cout<<"DONE";
		while(q.size()) q.pop();
		for(int i=1;i<=m2;i++){
			if(q.size()) if(p2[i].a>=q.top()) {q.pop(); temp++;}
			if(temp) {cnt++; q.push(p2[i].b); temp--;}
 		}ans=max(ans,cnt);
	}cout<<ans; 
	return 0;   // ��鷵���ǲ���0 , �ж�RE 
}
