///////////////////////////////////////////////////////////////////////////////////////
//Zack Salah
//Application Frequancy Manager
//Homework # 3
//Programming Systems #202
///////////////////////////////////////////////////////////////////////////////////////
//This file only contins the name class implemtaion. The class contains the most 
//important functionlity that the program need. Each fuction has a discription of how its
//implemented.
//
//Descriptions:
//
//Name Class:
//The name class is the core of main hub base class of the program. It 
//manages the name of applications and name of type of applictions. The class can be 
//considered as the main core of the program as it is the base class for mainly
//every class.
/////////////////////////////////////////////////////////////////////////////////////////
//Hierarchy Connections:
//Name is super base class
/////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#ifndef NAME_H
#define NAME_H
class name
{
    public:
        name();
        name(const char * to_add);
        name(const name & to_copy);
        name & operator = (const name & to_copy);
        name & operator = (const char * to_copy);
        ~name();

        void display() const;
        void change_name(const char * to_change);
        void set_name(const name & to_set);
        int compare(const name & to_comp) const; 
        int compare(const char * to_comp) const; 

    protected:
        char * _name;
};
#endif
