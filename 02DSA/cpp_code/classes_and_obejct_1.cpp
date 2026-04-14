#include <iostream>
using namespace std;

class Book{
  public:
    int bookId;
    string title;
    string author;
    bool isIssued;
    void input()
    {
      cout<<"Enter your marks: ";
      cin>>marks;
    }
    void display()
    {
      cout<<"Enter your marks: ";
      cin>>marks;
    }
    void issueBook()
    {
      cout<<"Enter your marks: ";
      cin>>marks;
    }
    void returnBook()
    {
      cout<<"Enter your marks: ";
      cin>>marks;
    }
};


int main(){
  Book b1;
  b1.input();
  b1.display();

  return 0;
}