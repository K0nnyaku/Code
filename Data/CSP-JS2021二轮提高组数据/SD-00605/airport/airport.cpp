 //40pts???
 #include<iostream>
 #include<cstdio>
 #include<queue>
 #include<algorithm>
 const int N=100005; 
 int n,m1,m2,tot1,tot2;
 using namespace std;
 int read(){
 	int x=0,f=1;char ch=getchar();
 	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*f;
 }
struct node{
	int f,t;
} a[N],b[N];
int l,r;
int cmp(node a,node b){
	return a.f<b.f;
}
priority_queue<int,vector<int>,greater<int> > q1,q2;
long long check(int x,int y){
	long long res=0;
	while (!q1.empty()) q1.pop();
	while (!q2.empty()) q2.pop();
	if (x!=0){
	q1.push(a[1].t),tot1=1,res++;
	for (int i=2;i<=m1;i++){
		while (!q1.empty()&&q1.top()<a[i].f)
		  q1.pop(),tot1--;
	    if (tot1<x)
	      q1.push(a[i].t),tot1++,res++;
	  }
    }
    if (y!=0){
	q2.push(b[1].t),tot2=1,res++;
	for (int i=2;i<=m2;i++){
		while (!q2.empty()&&q2.top()<b[i].f)
		  q2.pop(),tot2--;
	    if (tot2<y)
	      q2.push(b[i].t),tot2++,res++;
	  }
    }
	return res;
}
long long ans=-1;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout); 
	n=read(),m1=read(),m2=read();
	for (int i=1;i<=m1;i++)
	  cin>>a[i].f>>a[i].t;
	for (int i=1;i<=m2;i++)
	  cin>>b[i].f>>b[i].t;
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	for (int i=1;i<=n;i++)
		 ans=max(ans,check(i,n-i));
	cout<<ans<<endl;
	return 0;
}
	
