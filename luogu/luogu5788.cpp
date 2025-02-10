#include<bits/stdc++.h>
using namespace std;
stack<int>s;
vector<int>ans;
int res[3000005];
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>res[i];
	}
	//加进去一次拿出来一次拿出去n方的复杂度
	for(int i=n;i>=1;i--){
		while(!s.empty()&&res[i]>=res[s.top()]){
			s.pop();
		}
		if(s.empty())ans.push_back(0);
		else ans.push_back(s.top());
		s.push(i);
	}
	for(int i=ans.size()-1;i>=0;i--){
		cout<<ans[i]<<' ';
	}
	return 0;
}
