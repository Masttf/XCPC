#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int>a={3,1,4,2,6,5,8,10,7,9};
	do{
		for(auto x:a)cout<<x<<' ';
		cout<<endl;
	}while(next_permutation(a.begin(),a.end()));
	return 0;
}