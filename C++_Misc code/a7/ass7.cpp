/** CS 3710 - Vocational
  * Assignment 7
  * Ryan Martin
  * 201039054
  * rtm773
  */
  
// number 1
Line 3:

 error: ‘cout’ was not declared in this scope
     cout<<"\nEnter 3 scores: ";
     ^
q1.cpp:14:5: error: ‘cin’ was not declared in this scope
     cin>> score_1 >> score_2 >> score_3;
     ^
q1.cpp:16:40: error: ‘endl’ was not declared in this scope
     cout<< "\nTheir sum is " << sum << endl;

Line 5: 

q1.cpp: In function ‘int main()’:
q1.cpp:13:5: error: ‘cout’ was not declared in this scope
     cout<<"\nEnter 3 scores: ";
     ^
q1.cpp:13:5: note: suggested alternative:
In file included from q1.cpp:3:0:
/usr/include/c++/4.8/iostream:61:18: note:   ‘std::cout’
   extern ostream cout;  /// Linked to standard output
                  ^
q1.cpp:14:5: error: ‘cin’ was not declared in this scope
     cin>> score_1 >> score_2 >> score_3;
     ^
q1.cpp:14:5: note: suggested alternative:
In file included from q1.cpp:3:0:
/usr/include/c++/4.8/iostream:60:18: note:   ‘std::cin’
   extern istream cin;  /// Linked to standard input
                  ^
q1.cpp:16:40: error: ‘endl’ was not declared in this scope
     cout<< "\nTheir sum is " << sum << endl;
                                        ^
q1.cpp:16:40: note: suggested alternative:
In file included from /usr/include/c++/4.8/iostream:39:0,
                 from q1.cpp:3:
/usr/include/c++/4.8/ostream:564:5: note:   ‘std::endl’
     endl(basic_ostream<_CharT, _Traits>& __os)
     
Line 7:

q1.cpp: In function ‘int main()’:
q1.cpp:17:48: error: ‘average’ was not declared in this scope
     cout<< "\nTheir average is " << average(sum) << endl;

Line 10:

q1.cpp:11:5: error: expected unqualified-id before ‘{’ token
     {int score_1, score_2, score_3, sum;
     ^
Line 11:

q1.cpp:13:5: error: expected initializer before ‘cout’
     cout<<"\nEnter 3 scores: ";
     ^
q1.cpp:14:5: error: ‘cin’ does not name a type
     cin>> score_1 >> score_2 >> score_3;
     ^
q1.cpp:15:5: error: ‘sum’ does not name a type
     sum = add3(score_1, score_2, score_3);
     ^
q1.cpp:16:5: error: ‘cout’ does not name a type
     cout<< "\nTheir sum is " << sum << endl;
     ^
q1.cpp:17:5: error: ‘cout’ does not name a type
     cout<< "\nTheir average is " << average(sum) << endl;
     ^
q1.cpp:18:5: error: ‘sum’ does not name a type
     sum = add3(1.5 * score_1, score_2, score_3);
     ^
q1.cpp:19:5: error: ‘cout’ does not name a type
     cout<< "\nThe weighted sum is " << sum << "." <<endl;
     ^
q1.cpp:20:5: error: ‘cout’ does not name a type
     cout<< "\nTheir weighted average is " << average(sum) << "." <<endl;
     ^
q1.cpp:21:5: error: expected unqualified-id before ‘return’
     return(0);
     ^
q1.cpp:22:1: error: expected declaration before ‘}’ token
 }
 ^
 
Line 22: 

q1.cpp: In function ‘int main()’:
q1.cpp:25:5: error: a function-definition is not allowed here before ‘{’ token
     {return (a+b+c);}
     ^
q1.cpp:28:4: error: a function-definition is not allowed here before ‘{’ token
    {return (s/3.0);}
    ^
q1.cpp:28:20: error: expected ‘}’ at end of input
    {return (s/3.0);}
                    ^
Line 24:

q1.cpp:25:5: error: expected unqualified-id before ‘{’ token
     {return (a+b+c);}
     ^
Line 25:

q1.cpp:27:1: error: expected initializer before ‘double’
 double average(int s)
 ^

Line 27: 

q1.cpp:28:4: error: expected unqualified-id before ‘{’ token
    {return (s/3.0);}
    ^
Line 28:

q1.cpp:27:21: error: expected initializer at end of input
 double average(int s)
                     ^
// number 2
int main() {
*pi = i + c;  // illegal. trying to add memory location and character
*pc = s + 10;  // illegal. adding char and integer
pc = s + 2;  // illegal. adding again char and int
pv = pi;  // void. cannot get set to another object
pv = s + 5;  // adding char and int. illegal
pv = --s;  // legal. decrementing pv
pc = pv;  // set char to int. illegal
*pc = *pv;  // legal
*pc = (char) *pv;  // legal 
}

// number 3
#include<iostream>
#include<string>
#include<list>  // for the list
using namespace std;

class Person {
    int studentID, salary, hours, payrate;
    string department, university, researcharea, thesistopic, tara, employer;
    public:
        void set_values(int,int,int,int, string,string,string,string,string,string);
};
void Person::set_values(int id, int money, int hrs, int pay, string dept, string uni, 
                        string research, string thesis, string ta, string empl) {
    studentID = id;
    salary = money;
    hours = hrs;
    payrate = pay;
    department = dept;
    university = uni;
    researcharea = research;
    thesistopic = thesis;
    tara = ta;
    employer = empl;
}

int main() {
    list<Person> people;  // list of Person objects
    for(int i = 0; i < 15; i++) {
        int id;
        cout<<"enter stu id\n"
        cin<<id;
        Person person;
        person.set_value(id);
        people.push_back(person);  // add person object to list
        // we could expand now and do other operations with the list of Person
        // objects such as printing, sorting, modifying, etc.
}
