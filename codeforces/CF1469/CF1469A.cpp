#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		stack<char> d;
		cin>>s;
		int flag=1;
		int len=s.length();
		int cnt=0;//记录左括号数量
		for(int i=0;i<len;i++){
			if(s[i]=='(')d.push(s[i]),cnt++;
			else if(s[i]=='?'){
				if(s[i+1]==')'&&cnt<=1)i++;
				else if(d.empty())d.push('('),cnt++;
				else d.pop(),cnt--;
			}
			else if(s[i]==')'){
				if(!d.empty()&&d.top()=='('){
					cnt--;
					d.pop();
				}
				else{
					flag=0;
					break;
				}
			}
		}
		if(!d.empty())flag=0;
		if(flag)cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
	return 0;
}
