#include <iostreaam>
using namespace std;

class Book{
    public:
        string title;
};

int main(){
    Book b;
    b.title = "C++ Notes";
    Book *p;
    p = &b;
    cout<<b.title;
    cout<< p->title;
    return 0;
}