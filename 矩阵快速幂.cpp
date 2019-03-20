#include<bits/stdc++.h>
using namespace std;
const int Max = 99999;
const int Min = 0;
const int inf = 1e6;
const long long mod = 123456789;
#define M 1000
#define N 1000
#define ll long long
#define swap(x,y) x^=y^=x^=y
void jzc(ll (*a)[6],ll (*b)[6]){
	int t[6][6];
	memset(t,0,sizeof(t));
	for(int i=0;i<6;i++)
	    for(int j=0;j<6;j++)
		    for(int k=0;k<6;k++){
	    	    t[i][j] += (a[i][k]*b[k][j]%mod);
		    }
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
	    	a[i][j] = t[i][j]%mod;
		} 	
	}
	return;	    
}
void jzc_(ll *a,ll (*b)[6]){
	int t[6];
	memset(t,0,sizeof(t));
	for(int i=0;i<6;i++)
	    for(int j=0;j<6;j++){
	    	t[i] += (a[j]*b[i][j]%mod);
		}
	for(int i=0;i<6;i++) a[i] = t[i]%mod;
	return;
}
ll jzksm(ll n){
	ll temp[6][6] = {{1,2,1,3,3,1},{1,0,0,0,0,0},{0,0,1,3,3,1},{0,0,0,1,2,1},{0,0,0,0,1,1},{0,0,0,0,0,1}};
	ll a[6] = {2,1,8,4,2,1};
	while(n>0){
		if(n&1) jzc_(a,temp);
		jzc(temp,temp);
		n >>= 1; 
	}
	return a[0];
}
int main(){
	#ifdef LOCAL
		freopen("test.txt","r",stdin);
	#endif
	int T;
	cin >> T;
	while(T--){
		ll n;
		cin >> n;
		if(n==1) cout << 1 << endl;
		else if(n==2) cout << 2 << endl;
		else{
			ll ans =  jzksm(n-2);
			cout << ans << endl;
		}
	}
    return 0;
}

