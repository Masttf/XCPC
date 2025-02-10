//记忆化
//搜索循序
//最优化 可行性 冗余
#include<bits/stdc++.h>
using namespace std;
int res[70],cnt[55];
int n,mx,mi=90;
int flag=0;
void dfs(int x,int rest,int target,int all,int last){
	if(rest==0){
		x++;
		rest=target;
		last=mx;
	}
	if(x==all+1){
		flag=1;
		return ;
	}
	if(rest<mi)return ;
	for(int i=min(last,rest);i>=mi;i--){
		if(cnt[i]){
			cnt[i]--;
			dfs(x,rest-i,target,all,i);
			cnt[i]++;
			if(flag)return ;//找到答案直接退出
			if(rest==target&&!flag) return ;//如果接下不能拼成就说明这个长度不行
			if(rest==i&&!flag)return ;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)cin>>res[i],sum+=res[i],mx=max(mx,res[i]),mi=min(mi,res[i]),cnt[res[i]]++;
	for(int i=mx;i<=sum;i++){
		if(sum%i==0){
			dfs(1,i,i,sum/i,mx);
			if(flag){
				cout<<i;
				break;
			}
		}
	}
	return 0;
}
