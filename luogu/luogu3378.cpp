//实现二叉堆
#include<bits/stdc++.h>
using namespace std;
int f[1000000],cnt=0;
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
	int x,y;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==1){
			cin>>y;
			insert(y);
		}else if(x==2)cout<<f[1]<<'\n';
		else if(x==3) delmin();
	}
	return 0;
}
