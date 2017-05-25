#include "apps.h"
category::category(): used(0), date(NULL), len(NULL), info(NULL)
{
}
category::category(const char * to_copy): name(to_copy), used(1), date(NULL), len(NULL), info(NULL)
{
}
category::category(const category & to_copy): name(to_copy), used(0), date(NULL), len(NULL), info(NULL)
{
    used = to_copy.used;
    copy(to_copy.date, date);
    copy(to_copy.len, len);
    copy(to_copy.info, info);
}
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
bool category::bigger_than(const int to_comp)
{
    return used > to_comp;
}
int category::copy(const char * to_copy, char *& dest)
{
    if(dest)
        delete [] dest;
    dest = new char[strlen(to_copy) + 1];
    strcpy(dest, to_copy);
    return 1;
}
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
games::games(const char * to_copy):category(to_copy)
{
}
games::games(const games & to_copy):category(to_copy), completion(to_copy.completion)
{
}
games & games::operator = (const games & to_copy)
{
    if(this == &to_copy)
        return *this;
    completion = to_copy.completion;
    return *this;
}
int games::read(ifstream & load)
{
    char temp[10000];

    load.get(temp,10000, '|');
    load.ignore(10000, '|');
    change_name(temp);

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

    cout<<"\nPlease enter the completion precentage\n";
    cin>>completion;
    cin.ignore(10000, '\n');

    ++used;
    return 1;
}
bool games::compare(const category & to_comp) const
{
    const games * ptr = dynamic_cast<const games*>(&to_comp);
    if(!ptr)
        return false;

    bool boolean = false;
    int same = 0;
    if(this == &to_comp)
        return true;
    boolean = name::compare(to_comp);
    same = strcmp(date, ptr->date);
    same = strcmp(date, ptr->len);
    same = strcmp(date, ptr->info);
    

}
games::~games()
{
}
//WEB SURFING CLASS 
//
//Default constructor
website::website(): address(NULL)
{
}
website::website(const char * to_copy): category(to_copy), address(NULL)
{
}
website::website(const website & to_copy): category(to_copy), address(NULL)
{
    copy(to_copy.address, address);
}
website & website::operator = (const website & to_copy)
{
    if(this == &to_copy)
        return *this;
    copy(to_copy.address, address);
    return *this;
}
int website::read(ifstream & load)
{
    char temp[10000];

    load.get(temp,10000, '|');
    load.ignore(10000, '|');
    change_name(temp);

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
    ++used;
    return 1;
}
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
bool website::compare(const category & to_comp) const
{
}
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
social_media::social_media(const char * to_copy): category(to_copy)
{
}
social_media::social_media(const social_media & to_copy): category(to_copy), notification(to_copy.notification)
{
}
social_media & social_media::operator = (const social_media & to_copy)
{
    if(this == &to_copy)
        return *this;
    notification = to_copy.notification;
    return *this;
}
int social_media::read(ifstream & load)
{
    char temp[10000];
    load.get(temp,10000, '|');
    load.ignore(10000, '|');
    change_name(temp);

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
bool social_media::compare(const category & to_comp) const
{
}
social_media::~social_media()
{
}
