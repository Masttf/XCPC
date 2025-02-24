#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int res[maxn];
vector<int>ans;
stack<int>s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>res[i];
	for(int i=n;i>=1;i--){
		while(!s.empty()&&res[i]>=res[s.top()]){
			s.pop();
		}
		s.push(i);
		ans.push_back(s.size());
	}
	for(int i=n-1;i>=0;i--){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
