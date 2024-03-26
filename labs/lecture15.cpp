#include <iostream>
#include <cstring>
using namespace std;

namespace firstnamespace {
    int a, b, c;
}
namespace secondnamespace {
    double a, b, c;
}
namespace {
    int x, y, z;
}

class Integers {
    private:
        int a;
    public:
        void set_a(int a) 
        {
            this->a = a;
        }
        void print_a() {cout <<"a="<<a<<endl;}
    };

// custom string class implementation (we'll use this to demonstrate function overloading with)
class Strings {
    private:
        char* str;
        int len;

    public:
        //Default constructor
        Strings(): str(nullptr), len(0) {};

        // custom string constructor
        Strings(const char* s) {
            len = strlen(s);
            str = new char[len + 1];
            strcpy(str, s);
        }

        //destructor
        ~Strings() {
            delete[] str;
        }
        //copy constructor
        Strings(const Strings& other) {
            len = other.len;
            str = new char[len + 1];
            strcpy(str, other.str);
        }
        void cat(string a);
        void print_str() const {cout <<str<<endl;}
        Strings operator+(Strings& rhs);

};

Strings Strings::operator+(Strings& rhs) {
    int n;
    char *pTemp;
    n=strlen(rhs);
    if (n == 0) return;
    pTemp = new char[n+1];
    if (pData) strcpy(pTemp, pData);
    strcat(pTemp, a);
    pData = pTemp;
    nLen +=n;
}

int main(){
    Integers obj;
    int a = 10;
    using firstnamespace::c; // when c is referenced, the default is first namespace
    firstnamespace::a = 15.1;
    firstnamespace::b = 16.1;
    firstnamespace::c = 17.1;
    secondnamespace::a = 20.1;
    secondnamespace::b = 21.2;
    secondnamespace::c = 22.3;
    cout <<"first a="<<firstnamespace::a<<endl; //notice the int is rounded down
    cout <<"second a="<<secondnamespace::a<<endl; //notice the double is not rounded down
    cout <<"first b="<<firstnamespace::b<<endl;
    cout <<"second b="<<secondnamespace::b<<endl;
    cout <<"first c="<<c<<endl; // default namespace for c variable used
    cout <<"second c="<<secondnamespace::c<<endl;
    cout <<"default x="<<x<<endl;
    cout <<"default y="<<y<<endl;
    cout <<"default z="<<z<<endl; //these are all from the default namespace
    obj.set_a(a); // no namespace declared so locally scoped variable is used
    obj.print_a();
    obj.set_a(11);
    obj.print_a();
    // cout <<"a in object="<<obj.a<<endl; // this won't compile because obj.a is private

    return 0;
}