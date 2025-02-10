#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;cin>>n;
	int x;
	vector<int>pre;
	for(int i=0;i<n;i++){
		cin>>x;
		pre.push_back(x);
	}
	vector<int>number;
	number.push_back(pre[0]);
	for(int i=1;i<pre.size();i++){
		number.push_back(pre[i]-pre[i-1]);
	}
	for(int i=0;i<number.size();i++){
		if(i==number.size()-1)
			cout<<number[i];
		else
			cout<<number[i]<<' ';
	}
	return 0;
}
