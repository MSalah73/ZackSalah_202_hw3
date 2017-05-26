////////////////////////////////////////////////////////////////////////////////////////
//Zack Salah
//Application Frequnacy Manger
//Homework # 3
//Programming Systems #202
///////////////////////////////////////////////////////////////////////////////////////
//This file contains the implentaion of the interface class. It contains every function.
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
//The interface class has two purposes. First,  is for the user to test for bugs and test
//how the overall program work and how effiecent is it. Second, which will be kept in the
//final product, is the type of application allocation in the list, and most importantly
//the sort function. The sort function will sort the linear linked list after each entry.
//the sorting algorithms uses the power of operator overloading to check each nodes overall
//frequancy and depending on that the linked list will be sorted.
//
/////////////////////////////////////////////////////////////////////////////////////////
//Hierarchy Connections:
//Interface -"Has a"-> LLL Node
/////////////////////////////////////////////////////////////////////////////////////////


#include "list_interface.h"
//Default constuctor
//step 1: create the link list with the type of applications
interface::interface(): head(NULL)
{
    add_LLL(head, "Games");
    add_LLL(head, "Website");
    add_LLL(head, "Social Media");
}
//copy constructor
//step 1: call copy nodes functiom with the passed in argusment
interface::interface(const interface & to_copy): head(NULL)
{
    copy(to_copy.head, head);
}
//Operator =
//Step 1: check if passes in object is the same as the this pointer - retur this ref
//step 2: check if head - call destroy
//step 3: copy from the passed in arugment
//step 4: return this address
interface & interface::operator = (const interface & to_copy)
{
    if(this == &to_copy)
        return *this;
    if(head)
        destroy(head);
    copy(to_copy.head, head);
    return *this;
}
//Step 1: prompt the user to pick a choice when from the displayed menu
//step 2: call a function or quit depeding on the choice
void interface::manager()
{
    cout<<"\nWelcome to appliaction frequency manager demo alpha v1.0.\n"; 
    cout<<"The apllication is intended to be used by getting the data from the phone."
        <<"However, this is a user version to test.\n"; 
    int choice = 0;
    do
    {
        cout<<"\nWhat would you like to do?\n"
            <<"Please pick a number associated with one of options below\n"
            <<"1 - Add an application\n"
            <<"2 - Display all most frequent\n"
            <<"3 - Display most frequent from one category\n"
            <<"4 - Quit\n"
            <<"Choice: #";
        cin>>choice;
        cin.ignore(100, '\n');
        if(choice == 1)
            add_menu();
        else if(choice == 2)
            display_all(head);
        else if(choice == 3)
            display_menu();
        else if(choice == 4);
        else 
            cerr<<"\nInvalid choice!!!";
    }while(choice != 4);

}
//Step 1: prompt the user to pick a choice when from the displayed menu
//step 2: call a function to add or go back to the main menu depeding on the choice
void interface::add_menu()
{
    int choice = 0;
    do
    {
        cout<<"\nWhat category would you like to add to?\n"
            <<"Please pick a number associated with one of options below\n"
            <<"1 - Games\n"
            <<"2 - Website\n"
            <<"3 - Social Media\n"
            <<"4 - Previous menu\n"
            <<"Choice: #";
        cin>>choice;
        cin.ignore(100, '\n');
        if(choice == 1)
            add(head, "Games");
        else if(choice == 2)
            add(head, "Website");
        else if(choice == 3)
            add(head, "Social Media");
        else if(choice == 4);
        else 
            cerr<<"\nInvalid choice!!!";
        sort(head);
    }while(choice != 4);

}
//Step 1: prompt the user to pick a choice when from the displayed menu
//step 2: call a function to display or go back to main menu depeding on the choice
void interface::display_menu()
{
    int choice = 0;
    do
    {
        cout<<"\nWhat category would you like to display its most frequent apps?\n"
            <<"Please pick a number associated with one of options below\n"
            <<"1 - Games\n"
            <<"2 - Website\n"
            <<"3 - Social Media\n"
            <<"4 - Previous menu\n"
            <<"Choice: #";
        cin>>choice;
        cin.ignore(100, '\n');
        if(choice == 1)
            display(head, "Games");
        else if(choice == 2)
            display(head, "Website");
        else if(choice == 3)
            display(head, "Social Media");
        else if(choice == 4);
        else 
            cerr<<"\nInvalid choice!!!";
    }while(choice != 4);
}
//step 1: check if head is null - return
//step 2: check is head->next exist - switch nodes loactions and return 
//step 3: call it self recusivliy
void interface::sort(LLL_node *& head)
{
    if(!head)
        return;
    if(head->go_next())
    {
        if(*head < *head->go_next())
        {
            LLL_node * hold = head;
            head = head->go_next();
            hold->go_next() = head->go_next();
            head->go_next() = hold;
        }
    }
    sort(head->go_next());
}

//step 1: check if head is null - return 
//step 2: create new node with the type and connect its next with to head and up date head to temp
//step 3: call it self recusivily with the next pointer
int interface::add_LLL(LLL_node *& head, const char * type)
{
    if(!head)
    {
        LLL_node * temp = new LLL_node(type);
        temp->read();
        temp->go_next() = head;
        head = temp;
        return 1;
    }
    return add_LLL(head->go_next(), type);
}

//step 1: check if head is null - return 
//step 2: check if head category name is the same as name type passed in 
//step 2a: call the implemented version of cin opeartor on head and return
//step 3: call it self recusivily with the next pointer
int interface::add(LLL_node *& head, const char * type)
{
    if(!head)
        return 0;
    if(!head->name::compare(type))
    {
        cin>>*head;
        return 1;
    }
    return add(head->go_next(), type);
}
//step 1: check if head is null - return 
//step 2: check if head category name is the same as name type passed in 
//step 2a: call the implemented version of cout opeartor on head and return
//step 3: call it self recusivily with the next pointer
int interface::display(LLL_node * head, const char * type)
{
    if(!head)
        return 0;
    if(!head->name::compare(type))
    {
        cout<<*head;
        return 1;
    }
    return display(head->go_next(), type);
}
//step 1: check if head is null - return 
//step 2: call the implemented version of cout opeartor on head
//step 3: call it self recusivily with the next pointer 
int interface::display_all(LLL_node * head)
{
    if(!head)
        return 0;
    cout<<*head;
    return display_all(head->go_next());
}
//step 1: check if source is null - return 
//step 2: allocate dest and call the copy constrctor with source
//step 3: call it self recursivily with the next poniter 
int interface::copy(LLL_node * src, LLL_node *& dest)
{
    if(!src)
        return 1;
    dest = new LLL_node(*src);
    return copy(src->go_next(), dest->go_next());
}
//step 1: check if head i null - return 
//step 2: call it self recursivliy with the next pointer
//step 3: delete head and return 
int interface::destroy(LLL_node *& head)
{
    if(!head)
        return 1;
    destroy(head->go_next());
    delete head;
    return 1;
}
//Destructor
//step 1: call destory
interface::~interface()
{
    destroy(head);
}
