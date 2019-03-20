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
ll dfs(int pos,int pre,int sta,bool limit){  //��53421Ϊ�� 
	if(pos==-1) return 1;                   //���������������������+1 
	if(!limit&&dp[pos][sta]!=-1) return dp[pos][sta];           //���û�дﵽ���ޱ�������0--50000 ��ʱ�򣬵�һλ��0��1��2��3��4��ʱ��û�����ƣ�5��ʱ���� 
	int up = limit?digit[pos]:9;                                  //�����ƵĻ�ѡȡ��һλ��ֵ������λ��0��1��2��3��4��ǧλ������1-9��������λ��5��ǧλ���ܳ���3 
	ll sum(0); 
	for(int i=0;i<=up;i++){                                       //ÿһλ����ö�� 
		if(pre==4&&i==9) continue;                                 //���������Ĳ����� 
		sum += dfs(pos-1,i,i==4,limit&&i==digit[pos]);             //�����������ļ��ϣ�pre��¼��һλ��ֵ��sta��¼�Ƿ��п��ܳ�Ϊ49�����һ����ʾ�Ƿ������� 
	}
	if(!limit) dp[pos][sta] = sum;                        //û�����ƽ�dp����ֵ���������Ա���� 
	return sum;                                        //����ֵ 
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

