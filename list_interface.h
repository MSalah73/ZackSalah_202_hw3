///////////////////////////////////////////////////////////////////////////////////////
//Zack Salah
//Application Frequancy Manager
//Homework # 3
//Programming Systems #202
///////////////////////////////////////////////////////////////////////////////////////
//This file only contins the Interface class implemention. Each class has a Porpose and
//they have their own "Job" in the program. The OOP design sumulates the connections 
//from paper to actual program. 
//
//Descriptions:
//
//Interface Class:
//
//Since this is a test program for the actual program. I had to implement a user interface
//to test the program. The class sole purpose is for testing. It has nothing to to with the 
//acual program. The real program would replace this with an api that retireve data from
//each appliation istalled on the user's phone.
//
/////////////////////////////////////////////////////////////////////////////////////////
//Hierarchy Connections:
//Interface -"Has a"-> LLL Node
/////////////////////////////////////////////////////////////////////////////////////////
#include "rb_tree.h"
class interface
{
    public:
        interface();
        interface(const interface & to_copy);
        interface & operator = (const interface & to_copy);
        ~interface();
        void manager();
    private:
        LLL_node * head;

        void add_menu();
        void display_menu();
        int add_LLL(LLL_node *& head, const char * type);
        int add(LLL_node *& head, const char * type);
        int display(LLL_node * head, const char * type);
        int display_all(LLL_node * head);
        int copy(LLL_node * src, LLL_node *& dest);
        void sort(LLL_node *& head);
        int destroy(LLL_node *& head);
};
