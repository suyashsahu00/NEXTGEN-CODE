#include <iostream>
using namespace std;

class Employee{

    int salary=10000; //declared private here
    public:
        string name;
        string post;
};

int main(){
    Employee e1;
    cout<<"Enter your name: ";
    cin>>e1.name;
    cout<<"Your name is: "<<e1.name<<endl;
    cout<<"Enter your post: ";
    cin>>e1.post;
    cout<<"Your post is: "<<e1.post;
    // cout<<e1.salary;//'int Employee::salary' is private within this context
    return 0;
}