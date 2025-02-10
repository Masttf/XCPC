#include<bits/stdc++.h>
using namespace std;
string s;
//定义输入字符串将黑白间隔排放
void dt(int n){
	if(n==4){
		s[n-1]='-';
		s[n]='-';
		s[2*n]='o';
		s[2*n+1]='*';
		cout<<s<<'\n';
		s[n-1]='*';
		s[n]='o';
		s[2*n]='-';
		s[2*n-1]='-';
		cout<<s<<'\n';
		s[1]='-';
		s[2]='-';
		s[7]=s[8]='o';
		cout<<s<<'\n';
		s[1]='*';
		s[2]='o';
		s[6]=s[7]='-';
		cout<<s<<'\n';
		s[0]=s[1]='-';
		s[6]='o';
		s[7]='*';
		cout<<s<<'\n';
		return ;
	}
	s[n-1]='-';
	s[n]='-';
	s[2*n]='o';
	s[2*n+1]='*';
	cout<<s<<'\n';
	s[n-1]='*';
	s[n]='*';
	s[2*n-1]='-';
	s[2*n-2]='-';
	cout<<s<<'\n';
	dt(n-1);
	return ;
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		s+='o';
	}
	for(int i=1;i<=n;i++){
		s+='*';
	}
	s+='-';
	s+='-';
	cout<<s<<'\n';
	dt(n);
	return 0;
}
