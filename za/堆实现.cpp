//实现二叉堆
#include<bits/stdc++.h>
using namespace std;
int f[100],cnt=0;
void swim(int x){
	while(x>1&&f[x]<f[x/2]){
		swap(f[x],f[x/2]);
		x/=2;
	}
	return ;
}
void sink(int x){
	//有子节点
	while(x*2<=cnt){
		int t=x*2;
		if(t+1<=cnt&&f[t+1]<f[t])t++;//拿到子数组里面小的一个
		if(f[x]<f[t])break;
		swap(f[x],f[t]);
		x=t;
	}
}
void insert(int x){
	cnt++;
	f[cnt]=x;
	swim(cnt);
}
void delmin(){
	swap(f[1],f[cnt]);
	cnt--;
	sink(1);
	return ;
}
int main(){
	int n;cin>>n;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		insert(x);
	}
	for(int i=1;i<=cnt;i++){
		cout<<f[i]<<' ';
	}
	return 0;
}
