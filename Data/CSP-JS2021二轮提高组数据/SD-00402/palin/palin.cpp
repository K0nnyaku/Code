#include <bits/stdc++.h>
using namespace std;
const int N=110;
int a[2*N],s[2*N],cnt,w[2*N];
int fron=0,end;
void er(int x){
	if(x==0) return ;
	er(x/2);
//	cout<<x%2<<" ";
	if(x%2==0){
		//L:
		s[++cnt]=a[++fron];
	}else{
		s[++cnt]=a[--end];
	}
	w[cnt]=x%2;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		n*=2;
		int wxx=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
			for(int j=1;j<=n;j++){
				s[++cnt]=a[++fron];
			}
		for(int i=1;i<pow(2,n)-1;i++){
			memset(s,0,sizeof s);
			memset(w,0,sizeof s);
			fron=0,end=n+1,cnt=0;
			for(int j=1;j<=n-(log2(i));j++){
				//L:
			//	cout<<endl<<i;
				s[++cnt]=a[++fron];
			}
			er(i);
			int flag=0;
			for(int j=1;j<=n;j++){
				if(s[j]!=s[n-j+1]){
					flag=1;
					break;
				}
			}
			if(flag==0){
				wxx=1;
				//cout<<i<<endl;
			
				for(int j=1;j<=cnt;j++){
					if(w[j]%2==0){
						cout<<"L";
					}else{
						cout<<"R";
					}
				} 
				cout<<endl;
				break;
			}
		}
		if(!wxx)
		cout<<-1<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
