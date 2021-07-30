#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<"X is : "<<x<<endl;
#define ll long long int 
ll n=10000007;

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

int main(){

 int ans=0;
 vector<ll>a(n,0);
 primeSeive(a);
 for(int i=0;i<n;i++){
    if(a[i]==1)cout<<i<<endl;
 }
 cout<<ans<<endl;
	
}