#include<bits/stdc++.h>
using namespace std;
//Returns the index of elements in sorted and Rotated array
int findKey(int a[],int n,int key){
	int s=0;
	int e=n-1;
	while(s<=e){
		int mid=(s+e)/2;
		if(a[mid]==key){
			return mid;
		}
		//Is it sorted or not
		else if(a[s]<=a[mid]){
			//Key in first part
			if(key>=a[s] and key<=a[mid]){
				e=mid-1;
			}
			//Key is in second part
			else{
				s=mid+1;
			}
		}
		else{
			if(key<=a[e] and key>=a[mid]){
				s=mid+1;
			}
			else{
				e=mid-1;
			}
		}
	}
	return -1;
}
//Returns the occurences of a particular number in a array.
int NumberOfOccurence(int a[],int n,int key){
    bool isTheNumberPresent=binary_search(a,a+n,key);
    if(!isTheNumberPresent){
        return -1;
    }
    int *firstFound=lower_bound(a,a+n,key);
    int *foundBefore=upper_bound(a,a+n,key);
    return(foundBefore-firstFound);
}
//Returns The firstOccurence of Number in a sorted array
int firstOccurence(int a[],int n,int key){
    int start=0;
    int end=n-1;
    int ans=-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(a[mid]==key){
            ans=mid;
            end=mid-1;
        }
        else if(a[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}
//Fast Square root
float squareRoot(int n){
    int s=0;
    int e=n;
    float ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(mid*mid==n){
            ans=mid;
            break;
        }
        else if(mid*mid<n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    float inc=0.1;
    //Set your precision here
    int precision=6;
    for(int i=1;i<=precision;i++){
        while(ans*ans<=n){
            ans+=inc;
        }
        ans-=inc;
        inc/=10;
    }
    return ans;
}

int main(){
    int a[]={1,2,3,4,4,4,7,8};
    int n=sizeof(a)/sizeof(a[0]);
    int key=4;
    cout<<firstOccurence(a,n,key)<<endl;
    cout<<NumberOfOccurence(a,n,key)<<endl;
    cout<<squareRoot(15)<<endl;
    cout<<squareRoot(5)<<endl;
    cout<<squareRoot(81)<<endl;
}