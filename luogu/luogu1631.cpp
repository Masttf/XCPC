//与2085为同一题
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
pair<int,int>a[maxn];
int b[maxn],cur[maxn];
vector<int>ans;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].first,a[i].second=i;
	for(int i=1;i<=n;i++)cin>>b[i];
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		q.push({a[i].first+b[1],i});
		cur[i]=1;
	}
	for(int i=1;i<=n;i++){
		pair<int,int>temp=q.top();
		q.pop();
		cur[temp.second]++;
		q.push({a[temp.second].first+b[cur[temp.second]],temp.second});
		ans.push_back(temp.first);
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
