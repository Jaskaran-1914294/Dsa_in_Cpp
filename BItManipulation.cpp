#include<bits/stdc++.h>
using namespace std;
#define deb(c) cout<<"X is : "<<c<<endl;

// { 11111111(111) , 2 } -> 111111111000 
//clear last i+1 bits
void clearBitsFrom(int &n,int i){
    int mask= ~( ( 1 << (i+1) ) -1 );   // ~( 1000-1 = 0111) =111111111111111111111000;
    n = n & mask;
}

// {1111111000 , 2 } -> 1111111111
// Sets last bits 
void setBitsFrom(int &n,int i){
    int mask = ( 1<<(i+1) ) -1 ;  //(1000)->111
    n = n | mask; 
}

// 1000000(end)000(start)00 -> 1000000111000
//Sets bit from start to finish 
void setBitsFromTo(int &n,int start,int end){
    int num = end - start;
    int a = (1 << (num+1) ) -1;
    deb(a)
    int mask = a << start ;
    n=n | mask ;
}
void clearBitsFromTo(int &n,int start,int end){
    // int num=end-start;
    // int a=(1<<(num+1))-1;
    // int mask = ~ (a<<start);

    int a = ~0 << (end +1); // end+1 because we want to clear till <=end so it will be +1 numbers

    int b = (1 << start) -1;
    int mask= a | b;
    n =n & mask;
}
//Counting number of setbits
//Faster way is that n&(n-1) it will remove the last set bits always
int countBits(int n){
    int ans=0;
    // while(n>0){
    //     ans+= n & 1;
    //     n = n >> 1;
    // }
    while(n>0){
        ans++;
        n = n & (n-1);  
    }
    // ans = __builtin_popcount(n);
    return ans;
}
int intToBinary(int n){
    int ans=0;
    int poww=0;
    while(n>0){
        int last_bit = n & 1;
        ans+=pow(10,poww)*last_bit;
        poww++;
        n = n >> 1;
    }
    return ans;
}

void makeBitsFromNToM(int &n,int m,int start,int end){
    clearBitsFromTo(n,start,end);
    int mask = m << start;
    n= n | mask;
}

int powerOptimized(int a, int n){
    int ans = 1;
    while(n>0){
        if(n&1){
            ans = ans * a;
        }
        a = a * a;
        n = n >> 1;
    }
    return ans;
}

int main(){
    int n=1023;
    // clearBitsFrom(n,2);
    // deb(n);
    // setBitsFrom(n,2);
    // deb(n);
    // n=1024;
    // setBitsFromTo(n,2,6);
    // deb(n);
    // clearBitsFromTo(n,2,6);
    // deb(n);
    // deb(intToBinary(9))
    n=1108;
    makeBitsFromNToM(n,21,2,6);
    deb(n)
    deb(powerOptimized(3,3))
}