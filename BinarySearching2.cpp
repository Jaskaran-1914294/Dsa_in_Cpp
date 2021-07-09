#include<bits/stdc++.h>
using namespace std;
//PRATA Problem -> SPOJ (Binary Search)
bool CanWeMakePrata(int rank[],int n,int need,int maxAllowed){
    int total=0,cnt=0,j=1,i=0;
    while(i<n){
        if(total+rank[i]*j<=maxAllowed){
            total+=rank[i]*j;
            cnt++;
            j++;
            if(cnt>=need){
                return 1;
            }
        }
        else{
            j=1;
            total=0;
            i++;
        }
    }
    return 0;
}
int Prata(int a[],int n,int need){
    int s=0;
    int e=100000007;   //Any Greater number than questions input
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(CanWeMakePrata(a,n,need,mid)){
            ans=mid;
            e=mid-1;    //Search for a lower time value
        }
        else{
            s=mid+1;
        }
    }
}
//EKO problem- trees cutting SPOJ
bool CanWeCutThis(int heights[],int n,int req,int done){
    int total=0;
	for(int i=0;i<n;i++){
		if(heights[i]>done){
			total+=heights[i]-done;
			if(total>=req){
				return 1;
			}
		}
	}
	return 0;
}
int EKOeko(int heights[],int n,int req){
    sort(heights,heights+n);
    int s=0;
    int e=0;
    int ans=-1;
    for(int i=0;i<n;i++){
        e+=heights[i];
    }
    while(s<=e){
        int mid=(s+e)/2;
        if(CanWeCutThis(heights,n,req,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}

int main(){
    // int n=4;
    // int ranks[]={1,2,3,4};
    // int need=10;
    // cout<<Prata(ranks,n,need)<<endl;
    
    int heights[]={4,42,40,26,46};
    int n=5;
    int req=20;
    cout<<EKOeko(heights,n,req)<<endl;
}