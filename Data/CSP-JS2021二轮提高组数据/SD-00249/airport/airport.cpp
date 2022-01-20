#include <bits/stdc++.h>
#define lint long long
#define rint register int
using namespace std;
inline int read(){
	char c;int res=0,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-f;
	while(isdigit(c))res=res*10+c-'0',c=getchar();
	return res*f;
}
const int N=1e5+5;
int nxt[2][N];//��һ��û�б�ɾ����λ�� 
int find(int t,int x){
	if(nxt[t][x]==x)return x;
	return nxt[t][x]=find(t,nxt[t][x]);
}
int n,m[2],f[2][N],a[2][N],b[2][N],ans;
inline void solve(int t){
	for(rint i=1;i<=m[t]+1;++i)
		nxt[t][i]=i;
	for(rint i=1;i<=n;++i){
		int lst=0,sum=0;
		while(true){
			int x=upper_bound(a[t]+1,a[t]+1+m[t],lst)-a[t];
			x=find(t,x);if(x>m[t])break;++sum;
//			cout<<"solve:"<<t<<" "<<i<<" "<<x<<endl;
			//��ǰ��������� ����lst ɾ����ǰ��
			lst=b[t][x];nxt[t][x]=find(t,x+1); 
		}
		f[t][i]=f[t][i-1]+sum;
	}
}
int arr[N],ta[N],tb[N];
inline bool cmp(int x,int y)
	{return ta[x]<ta[y];}
inline void init(){
	for(rint t=0;t<2;++t){
		for(rint i=1;i<=m[t];++i)
			arr[i]=i,ta[i]=a[t][i],tb[i]=b[t][i];
		sort(arr+1,arr+1+m[t],cmp);
		for(rint i=1;i<=m[t];++i){
			a[t][i]=ta[arr[i]];
			b[t][i]=tb[arr[i]];
		}
//		for(rint i=1;i<=m[t];++i)
//			cout<<a[t][i]<<" "<<b[t][i]<<endl; 
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m[0]=read();m[1]=read();
	for(rint t=0;t<2;++t)
		for(rint i=1;i<=m[t];++i){
			a[t][i]=read();
			b[t][i]=read();
		}
	init();
	solve(0);solve(1);
	//ö�ٸ����ڻ��������˶��� 
	for(rint i=0;i<=n;++i)
		ans=max(ans,f[0][i]+f[1][n-i]);
	cout<<ans;
	return 0;
}
/*
���ڹ��ں͹��ʷֿ����� �ֱ���������һ������ʱ�Ĵ�
��֪������һ������һ���Ǵ���Щû�ܽ������ŵķɻ����濼��
����ת������
�ҵ�ĳ��λ�ú����һ��û�б�ɾ����λ��
ɾ����ǰλ��
���ɻ�������˵��������򼴿�
ע����ɢ�� 
���Ӷ�O(nlogn) 
*/

