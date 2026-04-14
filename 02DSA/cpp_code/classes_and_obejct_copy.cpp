#include <iostream>
using namespace std;

class Student{
  public:
    int marks;
    void getMarks()
    {
      cout<<"Enter your marks: ";
      cin>>marks;
    }
    void displayMarks(){
      cout<<"Your marks is: "<<marks<<endl;
    }
};


int main(){
  Student s1;
  Student s2;
  s1.getMarks();
  s1.displayMarks();
  return 0;
}