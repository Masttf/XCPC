//如果给你n和k 求n&x=k 容易得到x就是k
//&肯定是会变越小且k只能是n的子集，
#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	if(k>n)cout<<-1<<'\n';
	else if(k==n)cout<<n<<'\n';
	else{
		int sum=0,temp=n;//模拟这个毁1的过程//一次一次加太慢了直接用lowbit找到关键的部分
		while(temp){//不断拿到它的子集，发现子集也有包含关系举例101101，x只能是101100 100000 000000
			sum=lowbit(temp);
			if((temp&(temp+sum))==k){//&操作只会让这个数不断变小，这个数变小的到把连续的1变0 
				cout<<temp+sum<<'\n';//
				return ;
			}
			int t=temp+sum;
			temp&=t;//肯定也是这个的子集
		}
		cout<<-1<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
/*下面的做法是直接拿到x与n相同的1成为保护的1所以凑出的数一定保护的位+被毁的1的上一位
#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	vector<int>a;//表示同一的位
	vector<int>b;//表示原为1而x为0的位
	int n,x;cin>>n>>x;
	if((n&x)!=x){//子集
		cout<<-1<<'\n';
		return ;
	}
	for(int i=0;i<64;i++){
		if((n>>i)&1){
			if((x>>i)&1){
				a.push_back(i);
			}else{
				b.push_back(i);
			}
		}
	}
	if(b.empty()){//没有被毁的说明是自己本身
		cout<<n<<'\n';
		return ;
	}else if(a.empty()){//全毁
		cout<<(2LL<<((int)log2(n)))<<'\n';
	}else if(b.back()+1>=a[0]){//不符条件被毁的数不可能在被保护的数的后一位，因为是连续&所以后面的1肯定是一个一个都被毁掉
		cout<<-1<<'\n';
	}else{
		int ans=0;
		for(int i=0;i<a.size();i++){
			ans+=(1LL<<a[i]);
		}
		ans+=(1LL<<b.back()+1);
		cout<<ans<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
 */
