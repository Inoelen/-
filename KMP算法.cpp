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
void get_next(string a,int *next){
	int en=a.size();
	next[0] = 0;
	for(int i=1,k=0;i<en;i++){
		while(k>0&&a[k]!=a[i]) k = next[k-1];
		if(a[k]==a[i]) k++;
		next[i] = k;
	}
	return;
}
int kmp(string a,string b){
	int en = a.size(),eb=b.size();
	int next[eb],ans(0);
	get_next(b,next);
	for(int i=0,k=0;i<en;i++){
		while(k>0&&b[k]!=a[i]) k = next[k-1];
		if(b[k]==a[i]) k++;
		if(k==eb) return i-eb+2;
	}
	return ans;
}
int main(){
	#ifdef LOCAL
		freopen("test.txt","r",stdin);
	#endif
	string a;
	string b;
	while(cin >> a >> b){
		cout << kmp(a,b) << endl;
	}
    return 0;
}

