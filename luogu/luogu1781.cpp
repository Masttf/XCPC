#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	string s2;
	int ans=1;
	for(int i=1;i<=n;i++){
		cin>>s;
		//先比较长度再比较字典序
		if(s.size()>s2.size()){
			s2=s;
			ans=i;
		}else if(s.size()==s2.size()){
			if(s>s2){
				s2=s;
				ans=i;
			}
		}
	}
	cout<<ans<<'\n'<<s2;
	return 0;
}
