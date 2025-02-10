#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;cin>>n;
	int x;
	vector<int>res;
	res.push_back(0);
	for(int i=1;i<=n;i++){
		cin>>x;
		res.push_back(res[i-1]+x);
	}
	for(int i=1;i<res.size();i++){
		if(i==res.size()-1)
			cout<<res[i];
		else
			cout<<res[i]<<' ';
	}
	return 0;
}
