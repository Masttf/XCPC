#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn],cnt[maxn];
bool instack[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],cnt[a[i]]++;
	stack<int>s;
	for(int i=1;i<=n;i++){
		cnt[a[i]]--;
		if(instack[a[i]])continue;
		while(!s.empty()&&a[i]<s.top()&&cnt[s.top()]){
			instack[s.top()]=0;
			s.pop();
		}
		s.push(a[i]);
		instack[a[i]]=1;
	}
	vector<int>ans;
	while(!s.empty()){
		ans.push_back(s.top());
		s.pop();
	}
	for(int i=m-1;i>=0;i--)cout<<ans[i]<<' ';
	return 0;
}
