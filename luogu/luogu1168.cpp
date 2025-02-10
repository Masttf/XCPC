//取中位数维护一个小根堆和一个大根堆中位数不就是相当于排序后取中间
//所以小根堆可以看成是前半段大根堆是后半段，那么中位数就是两个堆顶的情况
//所以我们要维护两个堆的元素个数相差不超过1，且小根堆的元素都比大根堆的元素小
//那么再插入数的时候先比较两个堆元素个数，如果相同在这里我插入大根堆
//同时如果我要把数插入到大根堆，那么我这个数应该先插入到小根堆然后取小根堆的堆顶插入大根堆，这样就保证了我插入大根堆的数
//一定大于小根堆的数同理插入小根堆也是如此
#include<bits/stdc++.h>
using namespace std;
priority_queue<int>small;
priority_queue<int,vector<int>,greater<int>>large;
signed main(){
	int n;cin>>n;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(small.size()>=large.size()){
			small.push(x);
			large.push(small.top());
			small.pop();
		}else{
			large.push(x);
			small.push(large.top());
			large.pop();
		}
		if(i%2!=0){
			cout<<large.top()<<'\n';
		}
	}
	return 0;
}
