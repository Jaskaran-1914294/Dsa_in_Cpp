#include<bits/stdc++.h>
using namespace std;

//Function to Swap Two Numbers in an array
void swap(int arr[],int a,int b){
      swap(arr[b],arr[a]);
}
//Bubble Sort
void BubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
               swap(arr,j,j+1);
            }
        }
    }
}
//Selection Sort
void SelectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr,i,j);
            }
        }
    }
}
//Insertion Sort
void InsertionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current&&j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
}
//Merge Sort
void Merge(int arr[],int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++;
            k++;
        }
        else{
            arr[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++;
        k++;
    }

}
void MergeSort(int arr[],int l,int r){
    if(l<r){

        int mid=(l+r)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,r);
        Merge(arr,l,mid,r);
    }
}
//Selection Sort
int partition(int arr[],int l,int r){
      int pivot=arr[r];
      int i=l-1;
      for(int j=l;j<r;j++){
          if(arr[j]<pivot){
              i++;
              swap(arr,i,j);
          }
      }
     swap(arr,i+1,r);
     return i+1;
}
void SelectionSort(int a[],int l,int r){
    if(l<r){
        int pivot=partition(a,l,r);
        SelectionSort(a,l,pivot-1);
        SelectionSort(a,pivot+1,r);
    }
}
//Count Sort
void CountSort(int arr[],int n){
    int maxElement=6;
    int count[maxElement];
    for(int i=0;i<maxElement;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<maxElement;i++){
        count[i]=count[i]+count[i-1];
    }
    int ans[n];
    for(int i=n-1;i>=0;i--){
        ans[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=ans[i];
    }
}
//DNF Sort
void DNFSort(int arr[],int n){
    int s=0;
    int mid=0;
    int e=n-1;
    while(mid<=e){
        if(arr[mid]==0){
            swap(arr,mid,s);
            mid++;
            s++;
        }
        if(arr[mid]==1){
            mid++;
        }
        if(arr[mid]==2){
            swap(arr,mid,e);
            e--;
        }
    }
}
//Wave Sort
void WaveSort(int arr[],int n){
    for(int i=1;i<n;i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr,i,i-1);
        }
        if(arr[i]>arr[i+1]){
            swap(arr,i,i+1);
        }
    }
}
int main(){
    int a[]={5,2,3,4,1,1};
    int n=6;
    int b[]={1,0,0,1,2,2,1,0,2,1};
    int m=10;
    //BubbleSort(a,n);
    //SelectionSort(a,n);
    //InsertionSort(a,n);
    //MergeSort(a,0,4);
    CountSort(a,n);
    //DNFSort(b,m);
    //WaveSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}