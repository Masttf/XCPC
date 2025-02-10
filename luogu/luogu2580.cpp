#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main(){
	int n,m;cin>>n;
	string name;
	for(int i=1;i<=n;i++){
		cin>>name;
		mp[name]=1;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>name;
		if(mp.count(name)){
			if(mp[name]==1)mp[name]++,cout<<"OK"<<'\n';
			else cout<<"REPEAT"<<'\n';
		}else cout<<"WRONG"<<'\n';
	}
	return 0;
}
