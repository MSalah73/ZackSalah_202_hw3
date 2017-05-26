///////////////////////////////////////////////////////////////////////////////////////
//Zack Salah
//Application frequancy manager
//Homework # 3
//Programming Systems #202
///////////////////////////////////////////////////////////////////////////////////////
//This file contains the implentaion of the Category, Games, Website, and Social Media 
//classes. It contains every function that the programs would need. The comments in the 
//file will descripe the functionalty step by step to ensure the grader's understanding
//of all the functions.
//
//As I immplented all of the classes, I have returned and added and fixed some
//of the functions in this file. Because most of the function have functions from
//outside of the class. I encourge opening all the files to ensure all of the 
//connections that has been made.
//
//Algorithms
//
//This file contain all the classes nessaray to preform a dynamic binding opration. 
//The abstract base class is contains virtual funtions that help make the dynamic binding 
//possible. Once the user picks the app like Social Media or Website the pointer of the 
//Category will be allocate. This concept makes the program way shorter and efficant. This
//will also makes adding an new type much simpler if we were to add new drived category type.
//
/////////////////////////////////////////////////////////////////////////////////////////
//Hierarchy Connections:
//Category -"Is a"-> Name
//Games -"Is a"-> Category -"Is a"-> Name
//Website -"Is a"-> Category -"Is a"-> Name
//Social Media -"Is a"-> Category -"Is a"-> Name
/////////////////////////////////////////////////////////////////////////////////////////
#include "apps.h"
//Defluat constuctor
category::category(): used(0), date(NULL), len(NULL), info(NULL)
{
}
//Copy constuctor
category::category(const char * to_copy): name(to_copy), used(0), date(NULL), len(NULL), info(NULL)
{
}
//Copy constuctor
//step 1: copy the date members data from the passed in arguments
category::category(const category & to_copy): name(to_copy), used(0), date(NULL), len(NULL), info(NULL)
{
    used = to_copy.used;
    copy(to_copy.date, date);
    copy(to_copy.len, len);
    copy(to_copy.info, info);
}
//Operator =
//Step 1: check if the passed in arguments is the same the current object - retuen this ref
//step 2: copy the date members data from the passed in arguments
//step 3: return this address
category & category::operator = (const category & to_copy)
{
    if(this == &to_copy)
        return *this;
    used = to_copy.used;
    copy(to_copy.date, date);
    copy(to_copy.len, len);
    copy(to_copy.info, info);
    return *this;
}
//step 1: return if the frequancy verable is larger than the passed in object's 
bool category::bigger_than(const int to_comp)
{
    return used >= to_comp;
}
//step 1: check if current data exist - delete 
//step 2: allocate with the new array with size of the passed in array
//step 3: copy from the passed in array to the current array return
int category::copy(const char * to_copy, char *& dest)
{
    if(dest)
        delete [] dest;
    dest = new char[strlen(to_copy) + 1];
    strcpy(dest, to_copy);
    return 1;
}
//step 1: delete all arrays
category::~category()
{
   delete [] date;
   delete [] len;
   delete [] info;
}
//GAMES CLASS
//
//Default constructor
games::games(): completion(0)
{
}
//step 1: call input fucnction to set the data
games::games(const char * to_copy):category(to_copy)
{
    input();
}
//copy constructor
//step 1: call parent copy constctor with the passed in argus
games::games(const games & to_copy):category(to_copy), completion(to_copy.completion)
{
}
//Operator =
//Step 1: check if the passed in arguments is the same the current object - retuen this ref
//step 2: copy the date members data from the passed in arguments
//step 3: return this address
games & games::operator = (const games & to_copy)
{
    if(this == &to_copy)
        return *this;
    used = to_copy.used;
    copy(to_copy.date, date);
    copy(to_copy.len, len);
    copy(to_copy.info, info);
    completion = to_copy.completion;
    return *this;
}
//step 1: load data from the file and set to temp array
//step 2: call the copy function to copy to the current data member
//step 3: return
int games::read(ifstream & load, const char * name)
{
    char temp[10000];

    change_name(name);

    load>>used;
    load.ignore(10000, '|');

    load.get(temp,10000, '|');
    load.ignore(10000, '|');
    copy(temp, date);

    load.get(temp,10000, '|');
    load.ignore(10000, '|');
    copy(temp, len);

    load.get(temp,10000, '|');
    load.ignore(10000, '|');
    copy(temp, info);

    load>>completion;
    load.ignore(10000, '\n');

    return 1;
}
//step 1: check if the current data name is null - return
//step 2: diaplay data members
//step 3: return
int games::display()
{
    if(!_name)
        return 0;

    cout<<"\n----------Games----------\n";
    name::display();
    cout<<"Session length: "<<len
        <<"\nDate: "<<date
        <<"\nTimes lunched: "<<used
        <<"\nCompeltion percentage: %"<<completion
        <<"\nSession info:\n"<<info<<endl;

    return 1;
}
//step 1: check id name is null - return
//step 2: prompt the user and copy the data in the right data memebr
//step 3: add to the frequancy
//step 4: return
int games::input()
{
    char temp[10000] = {0};

    if(!_name)
        return 0;

    cout<<"\nPlease enter the date when the app is used\n";
    cin.get(temp, 10000, '\n');
    cin.ignore(10000, '\n');
    copy(temp, date);

    cout<<"\nPlease enter the length of the session\n";
    cin.get(temp, 10000, '\n');
    cin.ignore(10000, '\n');
    copy(temp, len);

    cout<<"\nPlease enter the user's session activities\n";
    cin.get(temp, 10000, '\n');
    cin.ignore(10000, '\n');
    copy(temp, info);

    do
    {
        cout<<"\nPlease enter the completion precentage - from 0 to 100\n";
        cin>>completion;
        cin.ignore(10000, '\n');
    }while(!(completion > -1 && completion < 101));

    ++used;
    return 1;
}
//step 1: use dynamic cast to find out if the category class is has the memory of this current class - return 
//step 2: copy its conntants and add the frequancy
//step 3: return
int games::update(category & to_update)
{
    games * ptr = dynamic_cast<games*>(&to_update);
    if(!ptr)
        return 0;
    copy(date, ptr->date);
    copy(len, ptr->len);
    copy(info, ptr->info);
    used += ptr->used;
    completion += ptr->completion;
    return 1;
}
//step 1: use dynamic cast to find out if the category class is has the memory of this current class - return false 
//step 2: compare all the data members including the name of the app
//step 3: return true if all data members are the same as the passed in object 
bool games::compare(const category & to_comp) const
{
    const games * ptr = dynamic_cast<const games*>(&to_comp);
    if(!ptr)
        return false;

    bool boolean = false;
    int same = 0;
    if(this == &to_comp)
        return true;
    same = name::compare(to_comp);
    same = strcmp(date, ptr->date);
    same = strcmp(len, ptr->len);
    same = strcmp(info, ptr->info);
    boolean = (ptr->used == used) && (ptr->completion == completion);
    return boolean && !same;
}
//destuctor
games::~games()
{
}
//WEB SURFING CLASS 
//
//Default constructor
website::website(): address(NULL)
{
}
//step 1: call input fucnction to set the data
website::website(const char * to_copy): category(to_copy), address(NULL)
{
    input();
}
//copy constructor
//step 1: call parent copy constctor with the passed in argus
website::website(const website & to_copy): category(to_copy), address(NULL)
{
    copy(to_copy.address, address);
}
//Operator =
//Step 1: check if the passed in arguments is the same the current object - retuen this ref
//step 2: copy the date members data from the passed in arguments
//step 3: return this address
website & website::operator = (const website & to_copy)
{
    if(this == &to_copy)
        return *this;
    used = to_copy.used;
    copy(to_copy.date, date);
    copy(to_copy.len, len);
    copy(to_copy.info, info);
    copy(to_copy.address, address);
    return *this;
}
//step 1: load data from the file and set to temp array
//step 2: call the copy function to copy to the current data member
//step 3: return
int website::read(ifstream & load, const char * name)
{
    char temp[10000];

    change_name(name);

    load>>used;
    load.ignore(10000, '|');

    load.get(temp,10000, '|');
    load.ignore(10000, '|');
    copy(temp, date);

    load.get(temp,10000, '|');
    load.ignore(10000, '|');
    copy(temp, len);

    load.get(temp,10000, '|');
    load.ignore(10000, '|');
    copy(temp, info);

    load.get(temp, 10000, '\n');
    load.ignore(10000, '\n');
    copy(temp, address);
    return 1;
}
//step 1: check if the current data name is null - return
//step 2: diaplay data members
//step 3: return
int website::display()
{
    if(!_name)
        return 0;

    cout<<"\n----------Website----------\n";
    name::display();
    cout<<"Session length: "<<len
        <<"\nDate: "<<date
        <<"\nTimes lunched: "<<used
        <<"\nWebsite address: "<<address
        <<"\nSession info:\n"<<info<<endl;

    return 1;
}
//step 1: check id name is null - return
//step 2: prompt the user and copy the data in the right data memebr
//step 3: add to the frequancy
//step 4: return
int website::input()
{
    char temp[10000] = {0};

    if(!_name)
        return 0;

    cout<<"\nPlease enter the date when the app is used\n";
    cin.get(temp, 10000, '\n');
    cin.ignore(10000, '\n');
    copy(temp, date);

    cout<<"\nPlease enter the length of the session\n";
    cin.get(temp, 10000, '\n');
    cin.ignore(10000, '\n');
    copy(temp, len);

    cout<<"\nPlease enter the user's session activities\n";
    cin.get(temp, 10000, '\n');
    cin.ignore(10000, '\n');
    copy(temp, info);

    cout<<"\nPlease enter address of the website\n";
    cin.get(temp, 10000, '\n');
    cin.ignore(10000, '\n');
    copy(temp, address);

    ++used;
    return 1;
}
//step 1: use dynamic cast to find out if the category class is has the memory of this current class - return 
//step 2: copy its conntants and add the frequancy
//step 3: return
int website::update(category & to_update)
{
    website * ptr = dynamic_cast<website*>(&to_update);
    if(!ptr)
        return 0;
    copy(date, ptr->date);
    copy(len, ptr->len);
    copy(info, ptr->info);
    copy(address, ptr->address);
    used += ptr->used;
    return 1;
}
//step 1: use dynamic cast to find out if the category class is has the memory of this current class - return false 
//step 2: compare all the data members including the name of the app
//step 3: return true if all data members are the same as the passed in object 
bool website::compare(const category & to_comp) const
{
    const website * ptr = dynamic_cast<const website *>(&to_comp);
    if(!ptr)
        return false;

    bool boolean = false;
    int same = 0;
    if(this == &to_comp)
        return true;
    same = name::compare(to_comp);
    same = strcmp(date, ptr->date);
    same = strcmp(len, ptr->len);
    same = strcmp(info, ptr->info);
    same = strcmp(address, ptr->address);
    boolean = (ptr->used == used);
    return boolean && !same;
}
//Destrcutor
//step 1: delete data member
website::~website()
{
    delete [] address;
}
//SOCIAL MEDIA CLASS
//
//Default constructor
social_media::social_media(): notification(0)
{
}
//step 1: call input fucnction to set the data
social_media::social_media(const char * to_copy): category(to_copy)
{
    input();
}
//copy constructor
//step 1: call parent copy constctor with the passed in argus
social_media::social_media(const social_media & to_copy): category(to_copy), notification(to_copy.notification)
{
}
//Operator =
//Step 1: check if the passed in arguments is the same the current object - retuen this ref
//step 2: copy the date members data from the passed in arguments
//step 3: return this address
social_media & social_media::operator = (const social_media & to_copy)
{
    if(this == &to_copy)
        return *this;
    used = to_copy.used;
    copy(to_copy.date, date);
    copy(to_copy.len, len);
    copy(to_copy.info, info);
    notification = to_copy.notification;
    return *this;
}
//step 1: load data from the file and set to temp array
//step 2: call the copy function to copy to the current data member
//step 3: return
int social_media::read(ifstream & load, const char * name)
{
    char temp[10000];
    change_name(name);

    load>>used;
    load.ignore(10000, '|');

    load.get(temp,10000, '|');
    load.ignore(10000, '|');
    copy(temp, date);

    load.get(temp,10000, '|');
    load.ignore(10000, '|');
    copy(temp, len);

    load.get(temp,10000, '|');
    load.ignore(10000, '|');
    copy(temp, info);

    load>>notification;
    load.ignore(10000, '\n');

    return 1;
}
//step 1: check if the current data name is null - return
//step 2: diaplay data members
//step 3: return
int social_media::display()
{
    if(!_name)
        return 0;
    cout<<"\n----------Social Media----------\n";
    name::display();
    cout<<"Session length: "<<len
        <<"\nDate: "<<date
        <<"\nTimes lunched: "<<used
        <<"\nNumber of notification: "<<notification
        <<"\nSession info:\n"<<info<<endl;

    return 1;
}
//step 1: check id name is null - return
//step 2: prompt the user and copy the data in the right data memebr
//step 3: add to the frequancy
//step 4: return
int social_media::input()
{
    char temp[10000] = {0};
    if(!_name)
        return 0;
    cout<<"\nPlease enter the date when the app is used\n";
    cin.get(temp, 10000, '\n');
    cin.ignore(10000, '\n');
    copy(temp, date);

    cout<<"\nPlease enter the length of the session\n";
    cin.get(temp, 10000, '\n');
    cin.ignore(10000, '\n');
    copy(temp, len);

    cout<<"\nPlease enter the user's session activities\n";
    cin.get(temp, 10000, '\n');
    cin.ignore(10000, '\n');
    copy(temp, info);

    cout<<"\nPlease enter the completion precentage\n";
    cin>>notification;
    cin.ignore(10000, '\n');

    ++used;
    return 1;
}
//step 1: use dynamic cast to find out if the category class is has the memory of this current class - return 
//step 2: copy its conntants and add the frequancy
//step 3: return
int social_media::update(category & to_update)
{
    social_media * ptr = dynamic_cast<social_media*>(&to_update);
    if(!ptr)
        return 0;
    copy(date, ptr->date);
    copy(len, ptr->len);
    copy(info, ptr->info);
    notification = ptr->notification;
    used += ptr->used;
    return 1;
}
//step 1: use dynamic cast to find out if the category class is has the memory of this current class - return false 
//step 2: compare all the data members including the name of the app
//step 3: return true if all data members are the same as the passed in object 
bool social_media::compare(const category & to_comp) const
{
    const social_media * ptr = dynamic_cast<const social_media*>(&to_comp);
    if(!ptr)
        return false;

    bool boolean = false;
    int same = 0;
    if(this == &to_comp)
        return true;
    same = name::compare(to_comp);
    same = strcmp(date, ptr->date);
    same = strcmp(len, ptr->len);
    same = strcmp(info, ptr->info);
    boolean = (ptr->used == used) && (ptr->notification == notification);
    return boolean && !same;
}
//destructor
social_media::~social_media()
{
}
