#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
int n,m,n2;
int go[maxn][20];//返回从第s区间开始走2的多少次方所能到达的最远区间
int ans[maxn];
struct node{
	int id;
	int left,right;
	bool operator < (const node x)const{
		return left<x.left;
	}
}res[maxn*2];

void get_next(){//预处理
	int next=1;
	for(int i=1;i<=n2;i++){
		while(next<=n2&&res[next].left<=res[i].right){
			next++;
		}
		go[i][0]=next-1;
	}
	for(int i=1;(1<<i)<=n;i++){
		for(int s=1;s<=n2;s++){
			go[s][i]=go[go[s][i-1]][i-1];//转移递推
		}
	}
}
void getans(int x){
	int len=res[x].left+m,cur=x,cnt=1;
	for(int i=log2(maxn);i>=0;i--){
		int pos=go[cur][i];
		if(pos&&res[pos].right<len){
			cnt+=1<<i;
			cur=pos;
		}
	}
	ans[res[x].id]=cnt+1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		res[i].id=i;
		cin>>res[i].left>>res[i].right;
		if(res[i].left>res[i].right){
			res[i].right+=m;
		}
	}
	sort(res+1,res+1+n);
	n2=n;
	for(int i=1;i<=n;i++){//把换补成链
		n2++;
		res[n2].id=res[i].id;
		res[n2].left=res[i].left+m;
		res[n2].right=res[i].right+m;
	}
	get_next();
	for(int i=1;i<=n;i++)getans(i);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}
