///////////////////////////////////////////////////////////////////////////////////////
//Zack Salah
//Application Frequnacy Manger
//Homework # 3
//Programming Systems #202
///////////////////////////////////////////////////////////////////////////////////////
//This file contains the implentaion of the name only. It contains every function.
//The comments in the file will descripe the functionalty step by step to ensure the 
//grader's understanding of all the functions.
//
//As I immplented all of the classes, I have returned and added and fixed some
//of the functions in this file. Becouse most of the function have functions from
//outside of the class. I encourge opening all the files to ensure all of the 
//connections that has been made.
//
//Algorithms
//
//As the drived class from the abstract base class is initailized, drived's initializetion
//list will invoke the name constuctor. This is also true in clase when creating a LLL_node
//as each type is a name. The name will help knowing what type from appliaction with the 
//intensive usage of run time type identification. It also helps when adding the same named
//application, so we can update the data from the previous one.
/////////////////////////////////////////////////////////////////////////////////////////
//Hierarchy Connections:
//Name is the super base class
/////////////////////////////////////////////////////////////////////////////////////////

#include "name.h"
using namespace std;
//NAME CLASS
//Default constructor
name::name(): _name(NULL)
{
}
//Copy constuctor
//Step 1: Call name's change name function
//and pass the const char as an arguments.
name::name(const char * to_add): _name(NULL)
{
    change_name(to_add);
}
//Copy constuctor
//Step 1: Call name's set name function
//and pass the const object of name as an arguments.
name::name(const name & to_copy): _name(NULL)
{
    set_name(to_copy);
}
//Operator =
//Step 1: check if the passed in class is the same as the the current class
//step 1a: return this address if true
//step 2: call the assigment Operator with char and return 
name & name::operator = (const name & to_copy)
{
    if(this == &to_copy)
        return *this;
    return *this = to_copy._name;
}
//Operator =
//Step 1: check if current name is has data - delete if so
//step 2: allocate current name with the passed args size
//step 3: copy from the passed in arugment to the current name
//step 4: return this address
name & name::operator = (const char * to_copy)
{
    if(_name)
        delete [] _name;
    _name = new char[strlen(to_copy) + 1];
    strcpy(_name,to_copy);
    return *this;
    
}
//This fuction will change the name of current object' name 
//to the passed in char.
//Step 1: check if the passed in value is NULL
//Step 2: check if name data memeer has data in it
//Step 2a: if so, delete the name data
//Step 3: set current object's name to the size of passed in name
//Step 4:copy the the data from passed in name to the current object's name
void name::change_name(const char * to_change)
{
    if(!to_change)
        return;
    if(_name)
        delete [] _name;
    _name = new char[strlen(to_change)+1];
    strcpy(_name, to_change);
}
//Step 1: display's current object' name
void name::display() const
{
    cout<<"Name: "<<_name<<endl;
}
//Step 1: check if the passed in object of name's name data member is not NULL
//step 2: if not NULL than call change name function
void name::set_name(const name & to_set)
{
    if(to_set._name)
        change_name(to_set._name);
}
//Step 1: return the value from comparing the passed in data with the object data
int name::compare(const name & to_comp) const
{
    return strcmp(_name, to_comp._name);
}
//Step 1: return the value from comparing the passed in data with the object data
int name::compare(const char * to_comp) const
{
    return strcmp(_name, to_comp);
}
//Destructor
//Step 1: delete array names object 
//Step 2: set it to NULL
name::~name()
{
    delete [] _name;
    _name = NULL;
}
