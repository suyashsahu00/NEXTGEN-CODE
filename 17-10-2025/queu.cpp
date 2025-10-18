#include<iostream>
using namespace std ;

class Queue{
		int rear ;
		int front ;
		int max_size ;
		int* arr ;

	public :
	Queue(int max_size = 5){
		this -> front = -1 ;
		this -> rear =  -1 ;
		this -> max_size = max_size ;
		this -> arr = new int(max_size) ;
	}
		
	bool push(int x){
		
		// check if q is empty
		if(this->front == -1){
			this->front = 0 ;
			this -> rear = 0 ;
			arr[this -> rear] = x ;
			return true;
		}
		
		//check for over flow 
		if(this -> rear + 1 == this -> max_size){
			cout << "Queue overflow condition " ;
			return false ;
		}
		this -> rear = this -> rear + 1 ;
		arr[this -> rear] = x ;
		
		return true ;
		
	}
	
	int pop(){
		// check under flow 
		if(this -> front == -1){
			cout << "Under flow" << endl ;
			return -1 ;
		}
		
		int frontData = this -> arr[this -> front] ;
		this -> front = this -> front + 1 ;
		if( (this -> front) > (this -> rear)){
			this -> front = -1 ;
			this -> rear = -1 ;
		}
		return frontData ;
		
	}
	
	int size(){
		
		if(front == -1){
			return 0 ;
		}
		
		int length = (this -> rear) - (this -> front) + 1 ;
		return length ;
		
	}
	
	
};

int main(){
	
//	Queue * q = new Queue(3) ;
//	cout << " 1. " << q -> push(1) << endl ;
//	cout << " 2. " << q -> push(2) << endl ;
//	cout << " 3. " << q -> push(3) << endl ;
//	cout << " 4. " << q -> push(4) << endl ;
//	
//	cout << "==========================================" << endl ;
//	
//	Queue * q2 = new Queue(2) ;
//	cout << " 1. " << q2 -> push(1) << endl ;
//	cout << " 2. " << q2 -> push(2) << endl ;
//	cout << " 3. " << q2 -> push(3) << endl ;
//	
	Queue * q3 = new Queue(2) ;
	
	q3 -> push(10) ;
	q3 -> push(20) ;
	cout << "The length --> " << q3->size() ;
	cout << q3 -> pop() << endl ;
	cout << q3 -> pop() << endl ;
	
	
	q3 -> push(30) ;
	
//	cout << q3 -> pop() << endl ;
//	cout << q3 -> pop() << endl ;
 	 
	
	
	return 0 ;
}
