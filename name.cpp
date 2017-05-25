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
name & name::operator = (const name & to_copy)
{
    if(this == &to_copy)
        return *this;
    return *this = to_copy._name;
}
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
bool name::compare(const name & to_comp) const
{
    return !strcmp(_name, to_comp._name);
}
//Step 1: return the value from comparing the passed in data with the object data
bool name::compare(const char * to_comp) const
{
    return !strcmp(_name, to_comp);
}
//Destructor
//Step 1: delete array names object 
//Step 2: set it to NULL
name::~name()
{
    delete [] _name;
    _name = NULL;
}
