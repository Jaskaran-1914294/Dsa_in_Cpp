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
//Fast Square root: EASY
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
//Aggressive Cows Question: EASY-MEDIUM 
bool canWePlaceCows(int stalls[],int cows,int n,int minDis){
    int lastCow=stalls[0];
    int count=1;
    for(int i=1;i<n;i++){
        if(stalls[i]-lastCow>=minDis){
            lastCow=stalls[i];
            count++;
            if(count==cows){
                return 1;
            }
        }
    }
    return 0;
}
int AggressiveCows(int stalls[],int n,int cows){
    sort(stalls,stalls+n);
    int s=0;
    int e=stalls[n-1]-stalls[0];
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(canWePlaceCows(stalls,cows,n,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
//Books Allocation Question 
bool canWeGiveBooks(int b[],int n,int students,int maxPerStudent){
    int total=0;
    int cnt=1;
    for(int i=0;i<n;i++){
        // Total += b[i] (which is hard to remember)
        if(total+b[i]>maxPerStudent){
            cnt++;
            total=b[i];
            if(cnt>students){
                return 0;
            }
        }
        // I am forgetting to add this statements 
        else{
            total+=b[i];
        }
    }
    return 1;
}
int BooksAllocation(int books[],int n,int students){
    sort(books,books+n);
    int s=books[n-1];
    int e=0;
    for(int i=0;i<n;i++){
        e+=books[i];
    }
    int ans=-1;
    while(s<=e){
        int mid =(s+e)/2;
        if(canWeGiveBooks(books,n,students,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int main(){
    // int a[]={1,2,3,4,4,4,7,8};
    // int n=sizeof(a)/sizeof(a[0]);
    // int key=4;
    // cout<<firstOccurence(a,n,key)<<endl;
    // cout<<NumberOfOccurence(a,n,key)<<endl;
    // cout<<squareRoot(15)<<endl;
    // cout<<squareRoot(5)<<endl;
    // cout<<squareRoot(81)<<endl;

    // int a[]={1,0,1,1,1};
    // int n=5;
    // int key=0;
    // cout<<findKey(a,n,key)<<endl;

    // int stalls[]={1,3,4,5,6,8};
    // int length=sizeof(stalls)/sizeof(int);
    // int cows=3;
    // cout<<AggressiveCows(stalls,length,cows)<<endl;

    int books[]={10,20,30,40};
    int n=4;
    int students=2;
    cout<<BooksAllocation(books,n,students)<<endl;
}