///////////////////////////////////////////////////////////////////////////////////////
//Zack Salah
//Application frequancy manager
//Homework # 3
//Programming Systems #202
///////////////////////////////////////////////////////////////////////////////////////
//This file manges category, games, website, and social media classes. Each class has
//a purpose and they have their own "Job" in the program. The OOP design sumulates the
//connections from paper to actual program. 
//
//Descriptions:
//
//The Category Class
//This class is the Abstract base class. Its purpose to enable the ability of dynamic binding 
//The class has some pure virtual function which allows us to have a pointer of base class 
//but depeding on the allocated object the right function of type virtual will be called.
//
//Games Class
//Games class contains the same virtual funtions as it base class and some unique date members
//that are unqiue to games class. 
//
//Website Class
//Website class contains the same virtual funtions as it base class and some unique date members
//that are unqiue to website class. 
//
//Social Media Class
//Social media class contains the same virtual funtions as it base class and some unique date members
//that are unqiue to social media class. 
//
/////////////////////////////////////////////////////////////////////////////////////////
//Hierarchy Connections:
//Category -"Is a"-> Name
//Games -"Is a"-> Category -"Is a"-> Name
//Website -"Is a"-> Category -"Is a"-> Name
//Social Media -"Is a"-> Category -"Is a"-> Name
/////////////////////////////////////////////////////////////////////////////////////////


#include "name.h"
using namespace std;
class category: public name
{
    public:
        category();
        category(const category & to_copy);
        category(const char * to_copy);
        category & operator = (const category & to_copy);
        virtual~category();

        virtual int read(ifstream & load, const char * name) = 0;
        virtual int display() = 0;
        virtual int input() = 0;
        virtual bool compare(const category & to_comp) const = 0;
        virtual int update(category & to_comp) = 0;
        bool bigger_than(const int to_comp);

    protected:
        int used;
        char * date;
        char * len;
        char * info;

        int copy(const char * to_copy, char *& dest);
};
class games: public category
{
    public:
        games();
        games(const games & to_copy);
        games(const char * to_copy);
        games & operator = (const games & to_copy);
        ~games();

        int read(ifstream & load, const char * name);
        int display();
        int input();
        int update(category & to_update);
        bool compare(const category & to_comp) const;

    private:
        int completion;
};
class website: public category 
{
    public:
        website();
        website(const website & to_copy);
        website(const char * to_copy);
        website & operator = (const website & to_copy);
        ~website();

        int read(ifstream & load, const char * name);
        int display();
        int input();
        int update(category & to_update);
        bool compare(const category & to_comp) const;
    private:
        char * address;
};
class social_media: public category 
{
    public:
        social_media();
        social_media(const social_media & to_copy);
        social_media(const char * to_copy);
        social_media & operator = (const social_media & to_copy);
        ~social_media();

        int read(ifstream & load, const char * name);
        int display();
        int input();
        int update(category & to_update);
        bool compare(const category & to_comp) const;
    private:
        int notification;
};
