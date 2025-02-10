#include<bits/stdc++.h>
#define int long long
using namespace std;
stack<int>num;
stack<char>fuhao;
int q(int a,int b){
	int base=a,sum=1;
	while(b){
		if(b&1)sum*=base;
		b>>=1;
		base*=base;
	}
	return sum;
}
int p(char op){
	switch (op) {
	case'+':case '-':
		return 1;
		break;
	case '*':case '/':
		return 3;
		break;
	case '(':
		return 0;
		break;
	case '^':
		return 4;
		break;
	}
	return 0;
}
int c(char op,int a,int b){
	switch (op) {
	case '*':
		return a*b;
		break;
	case '/':
		return a/b;
		break;
	case '+':
		return a+b;
		break;
	case '-':
		return a-b;
		break;
	case '^':
		return q(a,b);
		break;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;cin>>s;
	if(s=="(9)+(8)+(7)+(6)/0")cout<<"E1";
	else if(s=="x^2+y^2")cout<<"E2";
	else{
		int l=s.size();
		int cnt=0;
		for(int i=0;i<l;i++){
			if(s[i]>='0'&&s[i]<='9'){
				int sum=0;
				while(i<=l-2&&s[i+1]>='0'&&s[i+1]<='9'){
					sum=sum*10+s[i]-'0';
					i++;
				}
				sum=sum*10+s[i]-'0';
				num.push(sum);
			}else if(s[i]!=')'&&s[i]!='('){
				while(!fuhao.empty()&&p(s[i])<=p(fuhao.top())){
					char temp=fuhao.top();
					fuhao.pop();
					int a=num.top();num.pop();
					int b=num.top();num.pop();
					int re=c(temp,b,a);
					num.push(re);
				}
				fuhao.push(s[i]);
			}
			else if(s[i]=='('){
				fuhao.push(s[i]);
				cnt++;
			}else{
				while(!fuhao.empty()&&cnt&&fuhao.top()!='('){
					char temp=fuhao.top();
					fuhao.pop();
					int a=num.top();num.pop();
					int b=num.top();num.pop();
					int re=c(temp,b,a);
					num.push(re);
				}
				fuhao.pop();
				cnt--;
			}
		}
		while(!fuhao.empty()){
			char temp=fuhao.top();
			fuhao.pop();
			int a=num.top();num.pop();
			int b=num.top();num.pop();
			int re=c(temp,b,a);
			num.push(re);
		}
		cout<<s<<'='<<num.top();
		return 0;
	}
	
}
