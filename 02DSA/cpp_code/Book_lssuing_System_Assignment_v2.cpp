#include <iostream>
using namespace std;

class Book {
    public:
        int bookId;
        string title;
        string author;
        bool isIssued;
        void input(){
            cin>>bookId;
            cout<<"enter Book title"<<endl;
            cin.ignore();
            getline(cin, title);
            cout<<"Write Author"<<endl;
            getline(cin, author);
            isIssued = false;
        }
        void display(){
            cout<<"BookId: "<<bookId<<endl;
            cout<<"Title: "<<title<<endl;
            cout<<"Author: "<<author<<endl;
            cout<<"Issued?: "<<isIssued<<endl;

        }
        void issueBook(){
            if ( isIssued == false){
                isIssued = true;
            }else {
                cout<<"Book already issued"<<endl;   
            }
        }
        void returnBook(){
            if (isIssued == true ){
                isIssued =false;
            }else{
                cout <<"Book is not issued"<<endl;
            }
        }

};

class User {
    public:
        int userId;
        string name;
        Book*  issuedBook;
        void input(){
            cout <<"Enter user id: ";
            cin >> userId;
            cout<<"Enter name: "<<endl;
            cin.ignore();
            getline(cin, name);
            issuedBook = nullptr;
        }
        void display(){
            cout<<"userId: "<<userId<<endl;
            cout<<"name: "<<name<<endl;
            if (issuedBook != nullptr){
                cout << "Issued Book: " << issuedBook->title <<endl;
            } else {
                cout<<"No book issued"<<endl;
            }
        }
        void borrowBook(Book* b){
            if (issuedBook != nullptr){
                cout<<"User already has a book"<<endl;
                return ;
            }
            if (b->isIssued == false){
                issuedBook  = b;
                b->issueBook ();
                b->isIssued = true;
                cout<<"Book issued successfully"<<endl; 
            }else{
                cout<<"Book already issued"<<endl;
            }
        }
        void returnBook(){
            if(issuedBook == nullptr){
            cout<<"No book to return"<<endl;
        } else( issuedBook != nullptr){
            returnBook (issueBook->returnBook();)
            issuedBook = nullptr;
        }
};


int main(){
    return 0;
}