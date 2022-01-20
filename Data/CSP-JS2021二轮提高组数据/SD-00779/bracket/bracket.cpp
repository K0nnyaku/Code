#include<iostream>
#include<cstdio>
using namespace std;
inline int rn(){
	char c=getchar();
	int ans=0,d=1;
	while(c<'0'||c>'9'){
		if(c=='-') d=-d;
		c = getchar();
	}while(c>='0'&&c<='9'){
		ans = ans*10+(c^48);
		c = getchar();
	}return ans*d;
}
void out(int n){
	if(n<0){
		putchar('-');
		n = -n;
	}
	if(!n){
		putchar('0');
		return;
	}
	char f[100];
	int top=0;
	while(n){
		f[++top] = n%10 + '0';
		n/=10;
	}while(top){
		putchar(f[top--]);
	}
	return;
}
const int N = 502;
int n, k, tail;
int a[N],dp[N][N][N];// 左括号i个 *j个的个数 
string s;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n = rn(),k=rn();
	s.push_back('0');
	cin>>s;
	tail = s.size()-1;
	/*for(int i=tail;i;i--){
		if(s[i]=='*')
		   a[i-1] = a[i] + 1;
	}
	for(int i=0;i<=tail;i++)
	cout<<a[i];*/
	for(int i=1;i<=tail;i++){//位置 
	//cout<<i<<endl;
		if(s[i]=='('){
			for(int j=i+1;j>=1;j--){//左括号个数 
				for(int l=k;l>=0;l--){//*个数 
				//cout<<l;
					dp[i][j][l] = dp[i-1][j-1][l];
				}
			}
		}
		else if(s[i]==')'){
			for(int j=i-1;j>=0;j--){//左括号个数 
				for(int l=k;l>=0;l--){//*个数 
					dp[i][j][l] = dp[i-1][j+1][l];
				}
			}
		}
		else if(s[i]=='*'){
			for(int j=i;j>=0;j--){//左括号个数 
				for(int l=1;l<=k;l++){//*个数 
					dp[i][j][l] = dp[i-1][j][l-1];
					//cout<<"位置"<<i<<" *个数 "<<l<<" 左括号个数为 "<<j<<" "<<" "<<dp[i][j][l]<<endl;
				}
			}
		}
		else{
			for(int j=i-1;j>=0;j--){//左括号个数 
				for(int l=k;l>=0;l--){//*个数 
					dp[i][j][l] += dp[i-1][j+1][l]+1;
				}
			}
			for(int j=1;j<=i+1;j++){//左括号个数 
				for(int l=k;l>=0;l--){//*个数 
					dp[i][j][l] += dp[i-1][j-1][l]+1;
				}
			}
			for(int j=i;j>=0;j--){//左括号个数 
				for(int l=k;l>=1;l--){//*个数 
					dp[i][j][l] += dp[i-1][j][l-1]+1;
					//cout<<"i "<<i<<" "<<dp[i][j][l]<<endl;
				}
				
			}
		}
	}
	cout<<dp[tail][0][0];
	return 0;
}
