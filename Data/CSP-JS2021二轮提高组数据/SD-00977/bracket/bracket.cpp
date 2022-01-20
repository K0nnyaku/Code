#include <cstdio>
#include <iostream>
#include <string>
std::string s;
int k;
int next_balanced_rparen(const std::string& t, int x) {
	int n=0;
	for(int i=x; i<t.length(); i++)
		if(t[i]=='(')n++;
		else if(t[i]==')') {
			n--;
			if(n==0)
				return i;
		}
	return -1;
}
// Optimization: With string_view
// TODO: Recursive-descent
bool is_valid(const std::string& t) {
	if(t.empty() || t[0] != '(' || *t.rbegin() != ')')
		return false;
	if(t.length() == 2)
		return true;
	if(t[1]=='*') {
		int n = t.find_first_not_of('*',1)-1;
		if(n==t.length()-2)
			return n <= k;
		if(n>k)
			return false;
		// (S?)
		if(t[n] == ')') // (S)?) => (?)
			return is_valid(std::string("(") + t.substr(n+2));
		// (S(?)
		n = next_balanced_rparen(t, n+1);
		if(n == t.length()-1)
			// (S(n)
			return false;
		// (S(n)?)
		if(t[n+1] == '*') {
			int n1 = t.find_first_not_of('*',n+1);
			if(n1 == t.length()-1) // (S(n)S)
				return false;
			if(t[n1] == ')') // (S(n)S)?)
				return is_valid(std::string("(") + t.substr(n1+1));
			// (S(n)S(?)
			// TODO
		}
		// (S(n)(?)
		return is_valid(t.substr(n+1)+std::string(")"));
	} else if (t[1]=='(') {
		int n = next_balanced_rparen(t, 1);
		if(n == t.length() - 1)
			return false;
		if(!is_valid(t.substr(1,n)))
			return false;
		// (S(n)(?)
		return is_valid(std::string("(") + t.substr(n+1));
	} else {
		if(t[2]=='(')
			return is_valid(t.substr(2));
		if(t[2]==')')
			return false;
		int n = t.find_first_not_of('*',2)-2;
		if(n>k)
			return false;
		if(t[n+2]==')')
			return false;
		else
			return is_valid(t.substr(n+2));
	}
	return true;
}
int search(int from) {
	if(s.find('?') == std::string::npos) {
		if(is_valid(s))
			return 1;
		else
			return 0;
	}
	int result=0;
	s[from]='*';
	result+=search(s.find('?'));
	s[from]='(';
	result+=search(s.find('?'));
	s[from]=')';
	result+=search(s.find('?'));
	s[from]='?';
	return result;
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n;
	scanf("%d%d", &n, &k);
	std::getline(std::cin, s);
	std::getline(std::cin, s);
	printf("%d\n", search(s.find('?')));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

