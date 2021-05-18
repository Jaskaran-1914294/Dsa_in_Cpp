#include<bits/stdc++.h>
using namespace std;
vector <vector<int>> ans;
void RevStr(string s){
    if(s.length()==0){
		return;
	}
    string ros=s.substr(1);
	RevStr(ros);
    cout<<s[0]<<" ";
}
void rP(string s){
    if(s.length()==0){
		return;
	}

	if(s[0]=='p' && s[1]=='i'){
		cout<<"3.14";
		string ros=s.substr(2);
		rP(ros);
	}
	else{
		cout<<s[0];
		string ros=s.substr(1);
		rP(ros);
	}
}
void toh(int n,char a,char c,char b){
if(n==0){
	return ;
}
toh(n-1,a,b,c);
cout<<"Move a disk from "<<a<<" to "<<c<<endl;
toh(n-1,b,c,a);

}

string mX(string s){
	if(s.size()==0){
		return "";
	}
	char c=s[0];
	string ros=mX(s.substr(1));
	if(c=='x'){
       return (ros+c);
	}
	else{
		return (c+ros);
	}
}
string rD(string s){
	if(s.length()==0){
		return "";
	}
	char c=s[0];
    string ros=rD(s.substr(1));
	if(c==ros[0]){
		return ros;
	}
	else{
		return (c+ros);
	}
}
void ss(string s,string ans){
	if(s.length()==0){
		cout<<ans<<endl;
	    return;
	}
	char c=s[0];
	string ros=s.substr(1);
	ss(ros,ans);
	ss(ros,ans+c);
}

void Vss(string s,string ans){
	if(s.length()==0){
		cout<<ans<<endl;
		return ;
	}
	char c=s[0];
    string ros =s.substr(1);
	int code=c;
	Vss(ros,ans);
	Vss(ros,ans+c);
	Vss(ros,ans+to_string(code));
}

string keypad[]={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"," "};
void kP(string s,string ans){
	if(s.length()==0){
		cout<<ans<<endl;
		return;
	}
	// cout<<"check"<<endl;
    char c=s[0];
	 int index=(int)(c-'0');
	string all=keypad[index];
	string ros=s.substr(1);
	for(int i=0;i<all.length();i++){
        kP(ros,ans+all[i]);
	}
}

void per(string s,string ans){
	if(s.length()==0){
		cout<<ans<<endl;
		return ;
	}
	for(int i=0;i<s.length();i++){
        char fix =s[i];
		string ros=s.substr(0,i)+s.substr(i+1);
		per(ros,ans+fix);
	}
}

int countPath(int s,int e){
	if(s==e){
		return 1;
	}
	if(s>e){
		return 0;
	}
	int count=0;
	//Dice value can add upto 6 .Thus,1->6.
	for(int i=1;i<=6;i++){
       count +=countPath(s+i,e);

	}
	return count ;
}
int countPathMaze(int n,int i,int j){
	if(i==n-1 && j==n-1){
		return 1;
	}
	if(i>n-1 || j>n-1){
		return 0;
	}
	return (countPathMaze(n,i+1,j)+countPathMaze(n,i,j+1));
}

int tiling(int n){
	if(n==0 || n==1){
		return n;
	}
	return (tiling(n-2)+tiling(n-1));
}

int friendPair(int n){
	if(n==0 || n==1 || n==3){
		return n;
	}
	return (friendPair(n-1)+(n-1)*friendPair(n-2));
}
//Knacksap Problem =n-> yes,no (max of each)
int knacksap(int v[],int w[],int n,int W){
   if(n==0 || W==0){
	   return 0;
   }
   if(w[n-1]>W){
	   return knacksap(v,w,n-1,W);
   }
   return (max((knacksap(v,w,n-1,W-w[n-1])+v[n-1]),knacksap(v,w,n-1,W)));
}
bool isSafe(int **a,int x,int y,int n){
	if(x<n && y<n && a[x][y]==1){
		return 1;
	}
return 0;
}
bool backT(int **a,int x,int y,int n,int **ans){
	if(x==n-1&&y==n-1){
		return 1;
	}
	if(isSafe(a,x,y,n)){
		ans[x][y]=1;
		if(backT(a,x+1,y,n,ans)){
			return true;
		}
		if(backT(a,x,y+1,n,ans)){
			return true;
		}
		ans[x][y]=0;
		return false;
    }
	return false;
}

void permut(vector<int>a,int index){
	if(index==a.size()){
		ans.push_back(a);
		return;
	}
	for(int i=index;i<a.size();i++){
		swap(a[i],a[index]);
		permut(a,index+1);
		swap(a[i],a[index]);
	}
	return;
}
bool isSafee(int **a,int x,int y,int n){
	for(int row=0;row<n;row++){
		if(a[row][y]==1){
			return false;
		}
	}
	int row=x,col=y;
	while(row>=0 &&col>=0){
		if(a[row][col]==1){
			return false;
		}
	}
	row=x,col=y;
	while(row>=0 &&col<n){
		if(a[row][col]==1){
			return false;
		}
	}
	return 1;
}
bool nQueen(int **a,int n,int x){
	if(x>=n){
		return 1;
	}
for(int col=0;col<n;col++){
	if(isSafe(a,x,col,n)){
		a[x][col]=1;
		if(nQueen(a,n,x+1)){
			return true;
		}
		a[x][col]=0;
	}
}
return false;
     

}





int main(){
	// int wt[]={10,20,30};
	// int vl[]={100,10,150};

//    RevStr("Binod");
//    cout<<endl;
//    rP("pirrrrpoeeeepiepeiopieee");
//    cout<<endl;
//    toh(3,'A','B','C');
//    cout<<endl;
//    cout<<mX("xxxxxabskfngkjnvfjxxdkjnfkx")<<endl;
//    cout<<rD("aaaaaaaaabbbbbbdddeeeeefttttttttttngklb")<<endl;
//    ss("ABC","");
//    Vss("AB","");
//    kP("2367","");
//    per("ABC"," ");
//    cout<<countPath(0,3)<<endl;
//    cout<<countPathMaze(3,0,0)<<endl;
//    cout<<tiling(4)<<" "<<friendPair(4)<<endl;
//    cout<<knacksap(vl,wt,3,50);
// int n;
// cin>>n;
// int **a=new int *[n];
// for(int i=0;i<n;i++){
// 	a[i]=new int[n];
// }
// for(int i=0;i<n;i++){
// 	for(int j=0;j<n;j++){
// 		cin>>a[i][j];
// 	}
// }
// int **s=new int *[n];
// for(int i=0;i<n;i++){
// 	s[i]=new int[n];
// 	for(int j=0;j<n;j++){
// 		s[i][j]=0;
// 	}
// }

// if(backT(a,0,0,n,s)){
// 	for(int i=0;i<n;i++){
// 	for(int j=0;j<n;j++){
// 		cout<<s[i][j]<<" ";
// 	}
// 	cout<<endl;
// }
// }
vector<int>a;
 a.push_back(1);
 a.push_back(2);
 a.push_back(1);
sort(a.begin(),a.end());
permut(a,0);
// do{
// 	ans.push_back(a);
// }
// while(next_permutation(a.begin(),a.end()));
for(auto i:ans){
	for(auto j:i){
		cout<<j<<" ";
	}
	cout<<endl;
 }
  
}