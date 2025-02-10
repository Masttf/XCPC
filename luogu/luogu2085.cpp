//考虑到每个函数都是递增的那么第一次每个函数取x=1的函数值来比较
//然后把最小的数放入答案数组然后删除再把那个最小数所对应的函数式的x++;然后再将该函数式的结果放入比较
//依次放入答案数组直到个数够了
#include<bits/stdc++.h>
using namespace std;
int res[10005][5];
int jilu[10005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
vector<int>ans;
int jiusan(int a,int b,int c,int x){
	return a*x*x+b*x+c;
}
int main(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>res[i][1]>>res[i][2]>>res[i][3];
		jilu[i]=1;
	}
	for(int j=1;j<=n;j++){
		int a=res[j][1],b=res[j][2],c=res[j][3],x=jilu[j];
		q.push({jiusan(a,b,c,x),j});
	}
	int temp=0;
	for(int i=1;i<=m;i++){
		if(q.size()<n){
			int a=res[temp][1],b=res[temp][2],c=res[temp][3],x=jilu[temp];
			q.push({jiusan(a,b,c,x),temp});
		}
		ans.push_back(q.top().first);
		temp=q.top().second;
		jilu[q.top().second]++;
		q.pop();
	}
	for(int i=0;i<m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
