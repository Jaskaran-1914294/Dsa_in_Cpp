#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Priority_Queue{
	vector<int>a;
public:
	bool isEmpty(){
		return (a.size()==0);
	}
	int getMin(){
		if(isEmpty()){
			return -1;
		}
		return a[0];
	}
	int getSize(){
		return a.size();
	}
	void insert(int element){
		a.push_back(element);
		int childIdx=a.size()-1;
		while(childIdx>0){
			int parentIdx=(childIdx-1)/2;
			if(a[parentIdx]>a[childIdx]){
				swap(a[parentIdx],a[childIdx]);
			}
			else{
				break;
			}
			childIdx=parentIdx;
		}
	}
	int removeMin(){
		if(isEmpty())return -1;
		int ans=a[0];
		a[0]=a[a.size()-1];
		a.pop_back();
		int parentIdx=0;
		int limit=a.size()-1;
		while(parentIdx<limit){
			int minIdx=parentIdx;
			int leftChild=(2*parentIdx)+1;
			int rightChild=(2*parentIdx)+2;
			if(leftChild<=limit and rightChild>limit){
				minIdx=leftChild;
			}
			else if(rightChild<=limit and leftChild>limit){
				minIdx=rightChild;
			}
			else if(rightChild<=limit and leftChild<=limit){
				if(a[leftChild]<a[rightChild]){
					minIdx=leftChild;
				}
				else{
					minIdx=rightChild;
				}
			}
			else{
				break;
			}
			if(a[minIdx]>=a[parentIdx]){
				break;
			}
			else{
				swap(a[minIdx],a[parentIdx]);
				parentIdx=minIdx;
			}
		}
		return ans;
	}
	// void print(){
	// 	for(auto i:a){
	// 		cout<<i<<" ";
	// 	}
	// 	cout<<endl;
	// }

};

//InPlace Heap Sort
void heapSort(int a[], int n) {
    // Write your code
    // Making heap
    for(int i=0;i<n;i++){
    	int child=i;
    	while(child>0){
    		int parent=(child-1)/2;
    		if(a[parent]<a[child]){
    			swap(a[parent],a[child]);
    		}
    		else{
    			break;
    		}
    		child=parent;
    	}
    }
    // Sorting
    for(int i=0;i<n;i++){
    	swap(a[0],a[n-i-1]);
    	int parent=0;
    	int limit=n-i-2;
    	while(parent<limit){
    		int maxIdx=parent;
    		int leftIdx=(parent*2)+1;
    		int rightIdx=(parent*2)+2;
    		if(leftIdx<=limit and rightIdx>limit){
    			maxIdx=leftIdx;
    		}
    		else if(leftIdx>limit and rightIdx<=limit){
    			maxIdx=leftIdx;
    		}
    		else if(leftIdx<=limit and rightIdx<=limit){
    			if(a[leftIdx]>a[rightIdx]){
    				maxIdx=leftIdx;
    			}
    			else{
    				maxIdx=rightIdx;
    			}
    		}
    		else{
    			break;
    		}
    		if(a[parent]>=a[maxIdx]){
    			break;
    		}
    		else{
    			swap(a[parent],a[maxIdx]);
    			parent=maxIdx;
    		}
    	}
    }  
}
// Inbuilt Queues 
// -> priority_queue<int>a;



int main(){
	Priority_Queue p;
	p.insert(7);
	p.insert(6);
	p.insert(5);
	p.insert(3);
	p.insert(4);
	p.insert(2);
	p.insert(1);
	p.insert(0);
	// p.print();
	// p.removeMin();
	// p.removeMin();
	// p.removeMin();
	// p.removeMin();
	while(!p.isEmpty()){
		cout<<p.removeMin()<<" ";
	}
	cout<<endl;
	// p.print();
	//Inbuilt Queue->MaxPriority Queue
	cout<<"--------------------------------"<<endl;
	cout<<"_____INBUILT_PRIORITY_QUEUES____"<<endl;
	priority_queue<int>a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.push(6);
	cout<<a.size()<<endl;
	while(!a.empty()){
		cout<<a.top()<<" ";
		a.pop();
	}
	cout<<endl;
}