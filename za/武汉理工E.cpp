#include<bits/stdc++.h>
using namespace std;
int cnt,cur=1;
vector<vector<int>> res(200005);
bool vis[200005];
vector<int> ans;
queue<int>q;
int n,m;
void bfs(int x){
	q.push(x);
	while(!q.empty()){
		int sz=q.size();
		for(int j=1;j<=sz;j++){
			int temp=q.front();q.pop();
			int len=res[temp].size();
			for(int i=0;i<len;i++){
				if(!vis[res[temp][i]]){
					q.push(res[temp][i]);
					vis[res[temp][i]]=1;
					cur++;
				}
			}
		}
	}
}
bool check(int x){
	int qwq=0;
	for(int i=0;i<cnt;i++){
		qwq+=min(x,ans[i]);
	}
	return qwq>=2*cnt-2;
}
int main(){
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		res[x].push_back(y);
		res[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			bfs(i);
			ans.push_back(cur);
			cur=1;
			cnt++;
		}
	}
	if(2*cnt-1>n)cout<<-1;
	else{
		sort(ans.begin(),ans.end());
		int a=-1,left=1,right=n;
		while(left<=right){
			int mid=(left+right)>>1;
			if(check(mid))a=mid,right=mid-1;
			else left=mid+1;
		}
		cout<<a;
	}
	return 0;
}
