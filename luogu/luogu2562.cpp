#include<iostream>
#include<string>
using namespace std;
string fun(string s){
	int sum=0;
	for(int i=0;i<s.size();i++){
		sum+=s[i]-'0';
	}
	if(sum==s.size())
		return "B";
	else if(sum==0)
		return "A";
	else{
		string s1=s.substr(0,s.size()/2);
		string s2=s.substr(s.size()/2,s.size()/2);
		return "C"+fun(s1)+fun(s2);
	}
}
int main(){
	string s;
	cin>>s;
	cout<<fun(s)<<'\n';
	return 0;
}
