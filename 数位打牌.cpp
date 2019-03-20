#include<bits/stdc++.h>
using namespace std;
const int Max = 99999;
const int Min = 0;
const int inf = 1e6;
const int mod = 1e9+7;
#define M 1000
#define N 1000
#define ll long long
#define swap(x,y) x^=y^=x^=y
ll dp[20][6];
int digit[20];
ll dfs(int pos,int pre,int sta,bool limit){  //以53421为例 
	if(pos==-1) return 1;                   //代表这种情况搜索结束，+1 
	if(!limit&&dp[pos][sta]!=-1) return dp[pos][sta];           //如果没有达到上限比如搜索0--50000 的时候，第一位是0，1，2，3，4的时候没有限制，5的时候有 
	int up = limit?digit[pos]:9;                                  //有限制的话选取下一位的值，如万位是0，1，2，3，4，千位可以是1-9，但是万位是5，千位不能超过3 
	ll sum(0); 
	for(int i=0;i<=up;i++){                                       //每一位进行枚举 
		if(pre==4&&i==9) continue;                                 //符合条件的不搜了 
		sum += dfs(pos-1,i,i==4,limit&&i==digit[pos]);             //不符合条件的加上，pre记录这一位的值，sta记录是否有可能成为49，最后一个表示是否有限制 
	}
	if(!limit) dp[pos][sta] = sum;                        //没有限制将dp的数值存起来，以便调用 
	return sum;                                        //返回值 
}
ll solve(ll a){
	int cnt = 0;
	while(a>0){
		digit[cnt++] = a%10;
		a/=10;
	}
	ll ans = dfs(cnt-1,0,0,true);
	return ans;
}
int main(){
	#ifdef LOCAL
		freopen("test.txt","r",stdin);
	#endif
	int T;
	cin >> T;
	memset(dp,-1,sizeof(dp));
	while(T--){
		ll a;
		scanf("%I64d",&a);
		ll ans = solve(a); 
		cout << a+1-ans << endl;
	}
    return 0;
}

