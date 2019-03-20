#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int inf=1e9;
const int maxn=1e7+5;
const int maxm=1e7+5;
#define MAX_N 10001
#define MAX_M 10001
#define ll long long
int prime[maxn];
bool check[maxm];
void aishai(int n){
	memset(check,0,sizeof(check));
	int tot(0);
	for(int i=2;i<n;i++){
		if(!check[i]){
			prime[tot++] = i;
		}
		for(int j=2*i;i*j<n;j+=i){
			check[i*j] = 1;
		}
	}
	return;
}
void oulashai(int n){
	memset(check,0,sizeof(check));
	int tot(0);
	for(int i=2;i<n;i++){
		if(!check[i]){
			prime[tot++] = i;
		}
		for(int j=0;i*prime[j]<n&&j<tot;j++){
			check[i*prime[j]] = 1;
			if(i%prime[j]==0)
			    break;
		}		
	}
	return;
}
int main()
{
	#ifdef LOCAL
	freopen("test.txt","r",stdin);
	#endif
	int n=1000;
    oulashai(n);
    for(int i=0;i<1000;i++){
    	cout << prime[i] << endl;
    }
	return 0;
}

