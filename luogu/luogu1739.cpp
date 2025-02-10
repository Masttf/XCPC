#include<bits/stdc++.h>
using namespace std;
stack<char> s;
int main(){
	string x;cin>>x;
	int flag=1;
	for(int i=0;i<x.size();i++){
		if(x[i]=='('){
			s.push(x[i]);
		}
		else if(x[i]==')'){
			if(s.empty()){
				cout<<"NO";
				flag=0;
				break;
			}
			else s.pop();
		}
	}
	if(flag&&s.empty())cout<<"YES";
	else if(flag)cout<<"NO";
	return 0;
}
