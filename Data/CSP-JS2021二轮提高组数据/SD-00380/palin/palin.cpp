#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int read(){
	char ch=getchar();
	if(ch!='-'&&(ch>'9'||ch<'0')){
		ch=getchar();
	}
	int ans=0,t=1;
	if(ch=='-'){
		t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*t;
}
int p,n;
int a[N];
int pos[3];
int vis[N];
void inti(){
	for(int i=1;i<=n;i++)
		vis[i]=0;
}
//void qpl(int a[]){
//	int ans=0;
//	for(int g=2;g>=1;g--){
//		inti();
//		int l=pos[g],r=pos[g];
//		while(l>=1&&!vis[a[l]]){
//			l--;
//			vis[a[l]]=1;
//		}
//		if(vis[a[l]]) 
//			cout<<" !11"<<a[l-1]<<" "<<r-l<<endl;
//		while(r<=2*n&&!vis[a[r]]){
//			r++;
//			vis[a[r]]=1;
//		}
////		cout<<r<<" "<<l<<endl;
//		if(r-l+1==n){
//			ans=g;
//			break;
//		}
//	}
////	return ans;
//}
int abc(int x){
	if(x<1)return 1;
	return x; 
}
bool flag=1;
int startt,endd;
void qpl(int a[]){
	flag=1;
	for(int g=2;g>=1;g--){
		for(int i=abc(pos[g]-n);i<=n;i++){
			cout<<abc(pos[g]-n)<<endl;
			inti();
			for(int j=1;j<=n;j++){
				if(vis[a[j]]==1){
					flag=0;
					break;
				}
				vis[a[j]]=1;
			}
			if(flag==1){
				startt=i;
				endd=i+n-1;
				break;
			}
		}
		if(flag==1)break;		
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	p=read();
	p+=1;
	while(p--){
		flag=1;
		n=read();
		int cnt=1;
		for(int i=1;i<=2*n;i++){
			a[i]=read();
			if(a[i]==1){
				pos[cnt]=i;
				cnt++;
			}
		}
		qpl(a);
		cout<<"-1"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
