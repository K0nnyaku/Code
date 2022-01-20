#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,sum=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=(sum<<3)+(sum<<1)+(ch^48);
		ch=getchar();
	}
	return sum*f;
}
int t,n,m,a[1000001],b[1000001],lb,fra,la,c[1000001],dp[10001][10001];
map<int,int > q;
bool check(){
	if(lb<2*n||lb>2*n) return false;
	for(int i=1;i<=lb;++i){
		c[lb-i+1]=b[i];
	}
	for(int i=1;i<=lb;++i){
		if(b[i]!=c[i]) return false;
	}
	return true;
}
void right(int ls,int rs);
void left(int ls,int rs){
	//cout<<"l"<<endl;
    b[++lb]=a[++fra];
	if(lb>2*n||fra>2*n||la<1||lb<0||fra<0||la>2*n||fra>la||q[ls,rs]==1) return;
	
	if(check()){
		//for(int i=1;i<=lb;++i) cout<<b[i]<<" ";
		
		cout<<endl<<ls<<" "<<rs<<endl;
		q[ls,rs]=1;
		return;
	}
	
//	
	right(ls,rs+1);
	lb--;
	la++;
	left(ls+1,rs);
	lb--;
	fra--;
	
}
void right(int ls,int rs){
	//cout<<"r"<<endl;
    b[++lb]=a[la--];
	if(lb>2*n||fra>2*n||la<1||lb<0||fra<0||la>2*n||fra>la||q[ls,rs]==1) return;
	
	if(check()){
		//for(int i=1;i<=lb;++i) cout<<b[i]<<" ";
		
		cout<<endl<<ls<<" "<<rs<<endl;
		q[ls,rs]=1;
		return;
	}
//	
	
	left(ls+1,rs);
	lb--;
	fra--;
	right(ls,rs+1);
	lb--;
	la++;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	//q[1,1]=0;
	//memset(dp,0,sizeof(dp));
	while(t--){
		n=read();
		la=2*n;
		for(int i=1;i<=2*n;++i) a[i]=read();
		/*right(0,1);
		lb--;
	    la++;
	    cout<<lb<<"{}"<<fra<<endl;
		left(1,0);
		lb--;
	    fra--;
	    */
		cout<<"-1"<<endl;
	//	baoli();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

