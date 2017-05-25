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
        bool compare(const name & to_comp) const; 
        bool compare(const char * to_comp) const; 

    protected:
        char * _name;
};
#endif
