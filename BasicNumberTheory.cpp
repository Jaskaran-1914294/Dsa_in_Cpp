#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<"X is : "<<x<<endl;
#define ll long long int 
ll n=10000007;
int n=100001;
//Prime Array 
vector<int>prime;
//Making prime seive array(Vector)
void primeSeive(vector <ll> &a){
	//Setting odds 
	for(ll i=3;i<n;i+=2){
		a[i]=1;
	}

	//Putting Multiples of them
	for(ll i=3;i<n;i+=2){
		if(a[i]==1){
			for(ll j=i*i;j<n;j=j+i){
				a[j]=0;
			}
		}
	}
	//Corner Cases 
	a[2]=1;
	a[0]=0;
	a[1]=0;
}
//Segmented Prime Seive
void fill(){
   bool *a=new bool[n+1];
   for(int i=0;i<=n;i++){
   	a[i]=0;
   }
	 for(int i=2;i*i<=n;i++){
	 	if(a[i]==0){
	 		prime.push_back(i);
	 		for(int j=i*i;j<=n;j+=i){
	 			a[j]=1;
	 		}
	 	}
	 }
	 delete []a;
}

void SegmentedSeive(){
	ll n=0,m=0;
	cin>>m>>n;
	vector<bool>ans(n-m+1,0);
	for(int i=0;i<prime.size();i++){
		int x=prime[i];
		if(x*x>n){
			break;
		}
		ll start=(m/x)*x;
		if(x>=m and x<=n){
			start=2*x;
		}
		for(ll i=start;i<=n;i+=x){
			ans[i-m]=1;
		}
	}
	for(ll i=0;i<n-m+1;i++){
		if(ans[i]==0){
			if(i+m==1){
				continue;
			}
			cout<<i+m<<endl;
		}
	}
	cout<<endl;
}


int main(){

 int ans=0;
 vector<ll>a(n,0);
 primeSeive(a);
 for(int i=0;i<n;i++){
    if(a[i]==1)cout<<i<<endl;
 }
 cout<<ans<<endl;
	
}