// lab over precedence in C
/* 
Operators:
1) ()
2) !, ++, --
3) *, /, %
4) +, -
5) <<, >>
6) <, <=, >, >=
7) ==, !=
8) &&
9) ^
10) ?:
11) =, +=, -=
12) || logical OR
*/
int x = 5;
int y = 6;

// compiler steps:
// check operator
// is variable ready? perform operation
// if not ready, update, then perform operation
int z = (x++ + x + y + ++x + ++y) * x;
// z = 5 + x + ++x
// z = 5 + 6 + ++x
// z = 5 + 6 + 7
// z = 18


// ex: 6

int x = 2, y = 3, z = 4, m = 1;
int n = --y + z / x + ++m;
// order:

int a=4,b=2,c=0;
int d = (a>b||b>c&&a==b);
// order: >, ==, &&, ||

// bitwise shifting
// a>>b = a/2^b
// a<<b = a*2^b

// if conditional logic
/*
Syntax
if(condition){
    statement
}else if(condition){
    statement
}else{
    statement
}
example:
if(1%2 == 0){
    printf("if happens")
}else if(1 == 2){
    printf("else if happens")
}else{
    print("else happens")
}
*/