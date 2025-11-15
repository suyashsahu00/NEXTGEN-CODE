#include<iostream>
using namespace std ;

class Node{
	public :
		int data ;
		Node * left ;
		Node * right ;
	
	Node(int data){
		this -> data = data ;
		this -> left = NULL ;
		this -> right = NULL ;
	}
	
	Node * buildTree(){
		int data = -1 ;
		cin >> data ;
		
		if(data == -1){
			//You don't want to go ahead ;
			cout << "Returning with NULL value" << endl ;
			return NULL ;
		}
		// creating root of the subtree
		Node * root = new Node(data) ;
		// build Left 
				cout << "Going Left" << endl ;
		root -> left = buildTree() ;
		// build Right 
				cout << "Going right" << endl ; 
		root -> right = buildTree() ;
		
		//finally returning the root 
		return root ;
		
	}
	
	    void traversalInorder(Node * root ){
        
        if(root == NULL){
            return ;
        }
        // left 
        traversalInorder(root -> left ) ;
        
        // process 
        cout << root -> data << " " ;
        // right 
        traversalInorder( root -> right  ) ;
        
    }
	
};


int main(){
	
	Node * root = new Node(10) ;
	root = root -> buildTree() ;
	root->traversalInorder(root) ;
	
	
	return 0 ;
}
