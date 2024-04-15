#include <iostream>
#include <vector>
using namespace std;


class Cell{
private :
    string value;
    bool occupied = false;
public:
    // Accessors --------------------------------
    string getValue();
    bool isOccupied();
    // Mutators --------------------------------
    void setValue(string);
    void setOccupied(bool);
    // Constructors --------------------------------
    Cell();
};

// Accessors --------------------------------
void Cell::getValue(){
    cout << value;
}

bool Cell::isOccupied(){
    return occupied;
}

// Mutators --------------------------------
void Cell::setValue(string value){
    this->value = value;
}

void Cell::setOccupied(bool occupied){
    this->occupied = occupied;
}

// Constructors --------------------------------
Cell::Cell(){
    this->value = " ";
    this->occupied = false;
}

int main(){
    Cell c1;
    c1.setValue("X");
    c1.setOccupied(true);
    cout << c1.getValue() << endl;
    cout << c1.isOccupied() << endl;
    return 0;
}