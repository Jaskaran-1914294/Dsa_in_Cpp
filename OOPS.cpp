#include<bits/stdc++.h>
using namespace std;
#define deb(c) cout<<"C is : "<<c<<endl;
int GCD(int a,int b){
	int t1=max(a,b);
	int t2=min(a,b);
	a=t1;
	b=t2;
	while(b!=0){
		int rem=a%b;
		a=b;
		b=rem;
	}
	return a;
}
class fraction{
	int numerator;
	int denominator;
	static int total;
	public:
	//Constructors
	fraction(){
		total++;
		numerator=1;
		denominator=1;
	}
	fraction(int a,int b){
		if(b==0){
			cout<<" Denominator can't be 0 "<<endl;
			return;
		}
		total++;
		numerator=a,denominator=b;
	}
	fraction(int a){
		if(a==0){
			cout<<" Denominator can't be 0 "<<endl;
			return;
		}
		total++;
		numerator=a;
		denominator=a;
	}
	fraction(const fraction &f1){
		this->numerator=f1.getNumerator();
		this->denominator=f1.getDenominator();
		// total++;
	}
	void simplify(){
		int gcd=GCD(numerator,denominator);
		numerator/=gcd;
		denominator/=gcd;
	}
    static int getTotal(){
		return total;
	}

	// Getters and setters
	void print(){
		cout<<this->numerator<<" / "<<this->denominator<<endl;
	}
	int getNumerator()const{
		return this->numerator;
	}
	int getDenominator()const{
		return this->denominator;
	}
	void setNumerator(int a){
		this->numerator=a;
	}
	void setDenominator(int b){
		if(b==0){
			cout<<" Denominator can't be 0 "<<endl;
			return;
		}
		this->denominator=b;
	}

    //Operator Overloading
	bool operator== (fraction &f1){
		this->simplify();
		f1.simplify();
		if(this->numerator==f1.getNumerator() and this->denominator==f1.getDenominator()){
			return 1;
		}
		return 0;
	}
	bool operator>= (fraction f1){
		int num1=this->numerator*f1.getDenominator();
		int num2=this->denominator*f1.getNumerator();
		return (num1>=num2);
	}
	bool operator!= (fraction f1){
		int num1=this->numerator*f1.getDenominator();
		int num2=this->denominator*f1.getNumerator();
		return (num1!=num2);
	}
	bool operator<= (fraction f1){
		int num1=this->numerator*f1.getDenominator();
		int num2=this->denominator*f1.getNumerator();
		return (num1<=num2);
	}
	bool operator< (fraction f1){
		int num1=this->numerator*f1.getDenominator();
		int num2=this->denominator*f1.getNumerator();
		return (num1<num2);
	}
	bool operator> (fraction f1){
		int num1=this->numerator*f1.getDenominator();
		int num2=this->denominator*f1.getNumerator();
		return (num1>num2);
	}
	fraction operator+ (const fraction &f1)const{
		int n=(this->numerator*f1.getDenominator())+(this->denominator*f1.getNumerator());
		int d=this->denominator*f1.getDenominator();
		fraction ans(n,d);
		ans.simplify();
		return ans;
	}
	fraction operator- (const fraction &f1)const{
		int n=(this->numerator*f1.getDenominator())-(this->denominator*f1.getNumerator());
		int d=this->denominator*f1.getDenominator();
		fraction ans(n,d);
		ans.simplify();
		return ans;
	}
	fraction operator* (const fraction &f1)const{
		int n=this->numerator*f1.getNumerator();
		int d=this->denominator*f1.getDenominator();
		//deb(n) deb(d)
		fraction ans(n,d);
		ans.simplify();
		return ans;
	}
	fraction operator/ (const fraction &f1)const{
        int n=this->numerator*f1.getDenominator();
		int d=this->denominator*f1.getNumerator();
		fraction ans(n,d);
		ans.simplify();
		return ans;
	}
	//Post Increment will work like it will firstly increase value then return
	// & -> we are passing the function as refference which will help in ++(++i) 
	fraction& operator++(){
		numerator+=denominator;
		simplify();
		return *(this);
	}
	//Syntax is a bit different in it
	fraction operator++(int){
		int n=this->numerator;
		int d=this->denominator;
		numerator+=denominator;
		simplify();
		fraction ans(n,d);
		ans.simplify();
		return ans;
	}

};
int fraction::total=0;

//Complex Number Class
class Complex{
	int a;
	int b;
	static int total;
  public:
    Complex(){
		total++;
		a=0,b=0;
	}
	Complex(int real,int imag){
		this->a=real;
		this->b=imag;	
	}
	Complex(Complex &c1){
		a=c1.getReal();
		b=c1.getImag();
	}
	const int getReal(){
		return this->a;
	}
	const int getImag(){
		return this->b;
	}
	void print(){
		cout<<this->a<<" + i "<<this->b<<endl;
	}
	Complex operator+ (Complex&c1){
		int real=c1.getReal()+this->a;
		int imag=c1.getImag()+this->b;
		deb(real)
		deb(imag)
		Complex ans(real,imag);
		//ans.print();
		return ans;
	}
	
};
class arr{
public:
	int *a;
	int size;
	int mx;
	arr(){
		mx=5;
		size=0;
		a=new int[mx];
		for(int i=0;i<mx;i++){
			a[i]=0;
		}
	}
	void push_back(int val){
		if(size<mx-1){
			a[size]=val;
			size++;
		}
		else{
			int *newArr=new int[mx*2];
			for(int i=0;i<size;i++){
				newArr[i]=a[i];
			}
			newArr[size]=val;
			size++;
			delete []a;
			a=newArr;
			mx*=2;
		}
	}
	void print(){
		for(int i=0;i<size;i++){
			cout<<a[i]<<" ";
		}
	}
};


int Complex::total=0;
int main(){
	fraction f1(1,2);
	fraction f2(3,4);
	fraction f3(3,3);
	fraction f4(1,2);
	cout<<fraction::getTotal()<<endl;
	deb((f1==f4))
	deb((f1!=f2))
	deb((f2>=f4))
	//fraction f5=f1+f4;
	fraction f6=f1*f4;
	//f5.print();
	f6.print();
	cout<<fraction::getTotal()<<endl;
	fraction f5(1,3);
	fraction temp(1,3);
	fraction f7=++temp;
	temp=f5;
	fraction f8=temp++;
	f5.print();
	f7.print();
	f8.print();


    cout<<"_________________________________"<<endl;
	Complex c1(2,3);
	Complex c2(3,4);
    Complex c3;
	c3=c1+c2;
	c3.print();
	cout<<"_______________________________"<<endl;

	arr made ;
	made.push_back(2);
	made.push_back(1);
	made.push_back(1);
	made.push_back(1);
	made.push_back(1);
	made.push_back(1);
	made.push_back(1);
	made.push_back(1);
	made.push_back(1);
	made.print();

	cout<<"_______________________________"<<endl;


	return 0;
}