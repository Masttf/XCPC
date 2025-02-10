//b的第一个字母要大于等于s0，或者小于等于s0
//设总长度为l，
#include<bits/stdc++.h>
using namespace std;
void solve(){
	string s;cin>>s;
	int len=s.size();
	int ca=0,cb=0;
	for(int i=0;i<len;i++){
		if(s[i]=='a')ca++;
		if(s[i]=='b')cb++;
	}
	if(ca==len||cb==len){
		for(int i=0;i<=len-1;i++){
			if(i==1||i==len-1)cout<<' ';
			cout<<s[i];
		}
		cout<<'\n';
	}else{
		if(s[0]=='a'&&s[len-1]=='a'){
			for(int i=0;i<len;i++){
				if(i==1||i==len-1)cout<<' ';
				cout<<s[i];
			}
			cout<<'\n';
		}else if(s[0]=='b'&&s[len-1]=='b'){
			int flag=1;
			for(int i=0;i<len;i++){
				if(s[i]=='a'&&flag)cout<<' ',flag=0;
				cout<<s[i];
				if(i==len-2)cout<<' ';
			}
			cout<<'\n';
		}else if(s[0]=='a'&&s[len-1]=='b'){
			if(ca==len-1){
				for(int i=0;i<len;i++){
					if(i==len-1||i==len-2)cout<<' ';
					cout<<s[i];
				}
				cout<<'\n';
			}else if(cb==len-1){
				for(int i=0;i<len;i++){
					if(i==1||i==len-1)cout<<' ';
					cout<<s[i];
				}
				cout<<'\n';
			}else{
				int flag=0;
				for(int i=0;i<len;i++){
					if(s[i]=='b'&&!flag)cout<<' ';
					if(s[i]=='b')flag++;
					cout<<s[i];
					if(s[i]=='b'&&flag==cb-1)cout<<' ';
				}
				cout<<'\n';
			}
		}else{
			if(ca==len-1){
				for(int i=0;i<len;i++){
					if(i==1||i==2)cout<<' ';
					cout<<s[i];
				}
				cout<<'\n';
			}else if(cb==len-1){
				for(int i=0;i<len;i++){
					if(i==1||i==len-1)cout<<' ';
					cout<<s[i];
				}
				cout<<'\n';
			}else{
				int c=1;
				for(int i=0;i<len;i++){
					if(s[i]=='a'&&c)cout<<' ';
					cout<<s[i];
					if(s[i]=='a'&&c)cout<<' ',c=0;
				}
				cout<<'\n';
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

