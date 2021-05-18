#include<bits/stdc++.h>
using namespace std;
//Prints Sum Uptil N
int SumUptil_N(int n){
	if(n==0 || n==1){
		return n;
	}
	return (n+SumUptil_N(n-1));
}
//Prints N^P
int power(int n,int p){
	if(p==0){
		return 1;
	}
	return (n*power(n,p-1));
}
//Fibbonaci sum uptil n
int Sumfibbonaci(int n){
	if(n==0 || n==1){
		return n;
	}
	return (Sumfibbonaci(n-1)+Sumfibbonaci(n-2));
}
//Print Numbers in Increasing Order
void PrintTill(int n){
	if(n==0){
		return;
	}
	cout<<n<<" ";
	PrintTill(n-1);
}
//Print Numbers in decreasing order
void PrintTill_d(int n){
	if(n==0){
		return;
	}
	PrintTill_d(n-1);
	cout<<n<<" ";
}
//Check That Array is sorted in increasing order
bool IsSorted(int a[],int n){
    if(n==1){
		return true;
	}
	return(a[0]<a[1] && IsSorted(a+1,n-1));
	
}
//Check That Array is sorted in Decreasing order
bool IsSorted_d(int a[],int n){
    if(n==1){
		return true;
	}
	return(a[0]>a[1] && IsSorted_d(a+1,n-1));
}
//first/last occurence of key in array
int FirstOccurence(int a[],int n,int i,int key){
	if(i==n){
		return -1;
	}
	if(a[i]==key){
		return i;
	}
	return(FirstOccurence(a,n,i+1,key));

}
//Reverse print a string
void stringRev(string s){
	if(s.length()==0){
		return ;
	}
	
	string ros=s.substr(1);
	stringRev(ros);
	cout<<s[0];
}
//Replace "pi" with 3.14
void replace(string s){
	if(s.length()==0){
		return;
	}
	if(s[0]=='p'&&s[1]=='i'){
		string ros=s.substr(2);
		cout<<"3.14";
		replace(ros);
	}
	else{
	string ros=s.substr(1);
	cout<<s[0];
	replace(ros);
	}	
}
// Remove Duplicates From String 
string Remove(string s){
	if(s.length()==0){
		return "";
	}
	char c=s[0];
	string ros=Remove(s.substr(1));
	if(ros[0]==c){
		return ros;
	}
	else{
		return c+ros;
	}
}
//Tower Of Hanoi
void toh(int n,char a,char c,char b){
	if(n==0){
		return;
	}
	toh(n-1,a,b,c);
	cout<<"Move a Disk from "<<" to "<<c<<endl;
	toh(n-1,b,c,a);
}
//Moving all x to end 
string moveX(string s){
	if(s.length()==0){
		return "";
	}
	char c=s[0];
	string ros=moveX(s.substr(1));
	if(c=='x'){
		return ros+c;
	}
	else{
		return c+ros;
	}
}
//Generating substrings
void printSub(string s,string ans){
	if(s.length()==0){
		cout<<ans<<endl;
		return;
	}
	char c=s[0];
	string ros=s.substr(1);
	printSub(ros,ans);
	printSub(ros,ans+c);
}
//Substring with Ascii
void printsub(string s,string ans){
	if(s.length()==0){
		cout<<ans<<endl;
		return;
	}
	char c=s[0];
	string ros=s.substr(1);
	int ascii=(int)c;
	printsub(ros,ans);
	printsub(ros,ans+c);
	printsub(ros,ans+to_string(ascii));

}
//Keypad Problem
string keypad[]={"/","./","abc","def","ghi","jkl","mno","pqr","stuv","wxyz"};
//Array to store characters of number 
void keypadProb(string s,string ans){
    if(s.length()==0){
		cout<<ans<<endl;
		return;
	}
	char c=s[0];
	int value=c-'0';
	string allPossible=keypad[value];
	string ros=s.substr(1);
	for(int i=0;i<allPossible.length();i++){
		keypadProb(ros,ans+allPossible[i]);
	}
}


int main(){
	int a[]={1,2,3,4,5};
	int n=5;
	int b[]={5,4,3,2,1};
cout<<SumUptil_N(4)<<endl;
cout<<power(2,3)<<endl;
cout<<Sumfibbonaci(3)<<endl;
PrintTill(6);
cout<<endl;
PrintTill_d(6);
cout<<endl;
cout<<IsSorted(b,n)<<endl;
stringRev("BINOD");
cout<<endl;
replace("Piepiepieeeeepppeee");
cout<<endl;
cout<<Remove("vvvvvabcadbbbb")<<endl;
cout<<moveX("xmmmxmxmxxxxmxm")<<endl;
toh(3,'A','B','C');
cout<<endl;
printSub("ABC","");

printsub("AB","");

keypadProb("23","");



}