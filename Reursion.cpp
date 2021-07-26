#include<bits/stdc++.h>
using namespace std;
#define deb(a) cout<<"A is : "<<a<<endl;
int firstOccurence(int a[],int n,int key){
    if(n==0){
        return -1;
    }
    //Our Priority here is to check the first element
    if(a[0]==key){
        return 0;
    }
    int ans=firstOccurence(a+1,n-1,key);
    if(ans==-1){
        return ans;
    }
    else{
        return (ans+1);
    }
}

int LastOccurence(int a[],int n,int key){
    if(n==0){
        return -1;
    }
    //Our Priority here is to find the last element
    int ans=LastOccurence(a+1,n-1,key);
    if(ans!=-1){
        return ans+1;
    }
    else{
        if(a[0]==key){
            return 0;
        }
        else{
            return -1;
        }
    }
}
int allOccurences(int a[],int n,int key,int sol[]){
    if(n==0){
        return 0;
    }
    int ans=allOccurences(a,n-1,key,sol);
    if(a[n-1]==key){
        sol[ans]=n-1;
        return (ans+1);
    }
    else{
        return ans;
    }
}
void removePi(char a[]){
    if(a[0]=='\0' or a[1]=='\0'){
        return;
    }
    if(a[0]=='p' and a[1]=='i'){
        int n=0;
        while(a[n]!='\0'){
            n++;
        }
        n+=2;
        for(int i=n;i>=2;i--){
            a[i]=a[i-2];
        }
        a[0]='3';
        a[1]='.';
        a[2]='1';
        a[3]='4';
        return removePi(a+3);
    }
    else{
        removePi(a+1);
    }
}
//Return all subsequence of a string in a output array
int countSubseq(string input,string sol[]){
    if(input.empty()){
        sol[0]="";
        return 1;
    }
    char s=input[0];
    int ans=countSubseq(input.substr(1),sol);
    for(int i=0;i<ans;i++){
        sol[i+ans] = s+sol[i];
    }
    return 2 * ans ;
}

//Creating all subsets of a and storing it in sol 
int subset(int a[], int n, int sol[][20]) {

    if(n==0){
        sol[0][0]=0;
        return 1;
    }
    int ans=subset(a+1,n-1,sol);
    int here=a[0];
    for(int i=ans;i<2*ans;i++){
		sol[i][0]=sol[i-ans][0]+1;
        sol[i][1]=here;
    }
    for(int i=ans;i<2*ans;i++){
		int size = sol[i][0];
        for(int j=2;j<=size;j++){
            sol[i][j]=sol[i-ans][j-1];
        }
    }
	return (ans * 2);
}


int main(){
    cout<<"______________________________"<<endl;
    cout<<"FIRST LAST AND ALL OCCURENCES : "<<endl;
    int a[]={1,1,2,3,4,4,1,5,1};
    int n=sizeof(a)/sizeof(int);
    int key=1;
    cout<<firstOccurence(a,n,key)<<endl;
    cout<<LastOccurence(a,n,key)<<endl;
    int sol[50];
    cout<<allOccurences(a,n,key,sol)<<endl;
    for(int i=0;i<allOccurences(a,n,key,sol);i++){
        cout<<sol[i]<<" ";
    }
    cout<<endl;

    cout<<"______________________________"<<endl;
    cout<<"Replace PI : "<<endl;
    char input[]="abcepidefghpiie";
    removePi(input);
    cout<<input<<endl;

    cout<<"______________________________"<<endl;
    cout<<"Printing sub sequences of a char array : "<<endl;
    string z="abc";
    int l=pow(2,z.size());
    string *solution=new string [l];
    int count=countSubseq(z,solution);
    for(int i=0;i<count;i++){
        cout<<solution[i]<<endl;
    }

    cout<<"______________________________"<<endl;
    cout<<"Creating and storing subsets of a string : "<<endl;
    int inputt[20],length, output[350][20];
    cin >> length;
    for(int i=0; i < length; i++){
        cin >> inputt[i];
    }
    int size = subset(inputt, length, output);

    for( int i = 0; i < size; i++) { 
        for( int j = 1; j <= output[i][0]; j++) { 
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    cout<<((8&1)==0)<<endl;
}