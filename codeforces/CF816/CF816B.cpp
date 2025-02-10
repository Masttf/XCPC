//即统计每个温度的推荐菜谱
//使用差分快速时每个区间
#include<iostream>
using namespace std;
int res[200005];
int ant[200005];
int pre[200005];
int nel[200005];
int main(){
	int n,k,q;
	cin>>n>>k>>q;
	int x,y;
	while(n--){
		cin>>x>>y;
		res[x]++;
		res[y+1]--;
	}
	//拿到nel表明这个温度是否可接受，1表示可，0表示不可，再前缀和就可以拿到想要区间内推荐的温度有多少个
	for(int i=1;i<200005;i++){
		ant[i]=ant[i-1]+res[i];
		if(ant[i]>=k)
			nel[i]=1;
		else
			nel[i]=0;
		pre[i]=pre[i-1]+nel[i];
	}
	int a,b;
	while(q--){
		cin>>a>>b;
		cout<<pre[b]-pre[a-1]<<'\n';
	}
	return 0;
}
