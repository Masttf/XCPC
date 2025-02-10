#include<bits/stdc++.h>//最长上升子序列nlogn优化
//原理首先如果能找到一个比它大的就替换掉，原因首先不会改变最长长度，第二这个数变小给后边的数提供更大的机会
//如果找不到就在末尾加上这是没有疑问的
#define int long long
using namespace std;
const int maxn=1e6+5;
string dp[maxn];
vector<string>a;
set<int> se[maxn];
int res[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;cin>>s;
	int len=s.size();
	int k=0;
	while(k<len){
		string temp="";
		temp+=s[k++];
		while(k<len&&s[k]>='a'&&s[k]<='z')temp+=s[k++];
		a.push_back(temp);
	}
	int cnt=a.size();
	int ans=1;
	dp[1]=a[0];
	se[1].insert(0);
	for(int i=2;i<=cnt;i++){//核心，
		int now=lower_bound(dp+1,dp+1+ans,a[i-1])-dp;
		if(now>ans){
			dp[++ans]=a[i-1];
			se[ans].insert(i-1);
		}else{
			dp[now]=a[i-1];
			se[now].insert(i-1);
		}
	}
	string anw="Zzzzzzzzzzzzzz";//在本题中在保证最长子序列的同时要求字典序最小因此用set维护一下这个位置有多少个可以放然后贪心取最小
	int idx=0;
	for(auto it=se[ans].begin();it!=se[ans].end();it++){
		if(anw>a[*it]){
			anw=a[*it];
			idx=*it;
		}else if(anw==a[*it]) idx=max(idx,*it);
	}
	res[ans]=idx;
	for(int i=ans-1;i>=1;i--){
		anw="Zzzzzzzzzzzzzzzz";
		for(auto it=se[i].begin();it!=se[i].end();it++){
			if(*it<res[i+1]&&a[*it]<a[res[i+1]]){//注意要比上一个字符串小
				if(anw>a[*it]){
					anw=a[*it];
					idx=*it;
				}else if(anw==a[*it])idx=max(idx,*it);
			}
		}
		res[i]=idx;
	}
	for(int i=1;i<=ans;i++)cout<<a[res[i]];
	return 0;
} 
