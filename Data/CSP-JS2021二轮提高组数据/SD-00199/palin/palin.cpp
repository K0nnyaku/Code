#include<bits/stdc++.h>
using namespace std;
char anss[500001];
int a[500001];
int head,tail;
int stu[500001];
bool book[500001];
bool flag=0;
int t,m;
void dout(char s[]){
	for(int i=0;;i++){
		if(s[i]='\000')return;
		printf("%c",&s[i]);
	}
}
void chec(int top){
	t=top+1;
	while(top!=0){
	
			if(stu[top]==a[head]){
				top--;
				head++;
				anss[t]='L';
				t++;
			}
			else if(stu[top]==a[tail]){
				top--;
				tail--;
				anss[t]='R';
				t++;
			}
			else {
				flag=1;
				return;
			}
		}
		return;
	}
void dfs(int top){
	if(top==m){
		chec(top-1);
		if(flag=1){
			flag=0;
			return;
		}
		else dout(anss);
	}
	if(book[a[head]]==0){
		book[a[head]]=1;
		stu[top]=a[head];
		head++;
		anss[top]='L';
		dfs(top+1);
		head--;
		book[a[head]]=0;
	}
	if(book[a[tail]]==0){
		book[a[tail]]=1;
		stu[top]=a[tail];
		anss[top]='R';
		tail--;
		dfs(top+1);
		tail++;
		book[a[tail]]=0;
	}
		return ;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	for(int q=1;q<=T;q++){
		scanf("%d",&m);
		for(int i=1;i<=2*m;i++){
			scanf("%d",&a[i]);
		}
		head=1;
		tail=2*m;
		dfs(0);
		if(flag=1)cout<<-1;
		cout<<endl;
	}
	return 0;
}
