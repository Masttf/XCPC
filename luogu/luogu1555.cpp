#include<bits/stdc++.h>
using namespace std;
long long res[1005],cnt;
void get_two(string s){
	long long base=1;
	long long ans=0;
	for(int i=s.size()-1;i>=0;i--){
		ans+=(s[i]-'0')*base;
		base*=2;
	}
	res[++cnt]=ans;
}
void get_three(string s){
	long long base=1;
	long long ans=0;
	for(int i=s.size()-1;i>=0;i--){
		ans+=(s[i]-'0')*base;
		base*=3;
	}
	res[++cnt]=ans;
}
int main(){
	string x,y;
	cin>>x>>y;
	for(int i=0;i<x.size();i++){
		if(x[i]=='1'){
			x[i]='0';
			get_two(x);
			x[i]='1';
		}else{
			x[i]='1';
			get_two(x);
			x[i]='0';
		}
	}
	for(int i=0;i<y.size();i++){
		if(y[i]=='0'){
			y[i]='1';
			get_three(y);
			y[i]='0';
			y[i]='2';
			get_three(y);
			y[i]='0';
		}else if(y[i]=='1'){
			y[i]='0';
			get_three(y);
			y[i]='1';
			y[i]='2';
			get_three(y);
			y[i]='1';
		}else{
			y[i]='0';
			get_three(y);
			y[i]='2';
			y[i]='1';
			get_three(y);
			y[i]='2';
		}
	}
	sort(res+1,res+cnt+1);
	for(int i=1;i<cnt;i++){
		if(res[i]==res[i+1]){
			cout<<res[i];
			break;
		}
	}
	return 0;
}
