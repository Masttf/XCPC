#include<bits/stdc++.h>
using namespace std;
#define int long long
bool vis[30];
int count (int n,int m){//Amn
	//计算cklen
	int sum=1;
	for(int i=n;i>=n-m+1;i--){
		sum*=i;
	}
	return sum;
}
void slove(){
	memset(vis,0,sizeof(vis));
	string s;cin>>s;
	int k;cin>>k;
	int sz=s.size();
	int c1=0;
	for(int i=0;i<sz;i++){
		if(!vis[s[i]-'a'+1]){
			c1++;
			vis[s[i]-'a'+1]=1;
		}
	}
	//1所有字母不重复
	//2 所有字母都是出现过的或者首字母是s里且后面字典序大于前
	int cnt=0;
	int fenmu=count(k-1,k-1);
	for(int i=1;i<=18;i++){//首先考虑枚举首字母
		if(18-i+1<k)break;
		if(vis[i]){
			int len=18-i;
			if(len+1>=k){//c(k-1)len
				cnt+=count(len,k-1)/fenmu;
			}
		}
	}
	if(c1>=k){
		int f=count(c1,k);//全排列
		cnt+=f-count(c1,k)/fenmu/k;
	}
	cout<<cnt<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		slove();
	}
	return 0;
}
