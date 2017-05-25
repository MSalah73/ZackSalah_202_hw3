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

        virtual int read(ifstream & load) = 0;
        virtual int display() = 0;
        virtual int input() = 0;
        virtual bool compare(const category & to_comp) const = 0;
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

        int read(ifstream & load);
        int display();
        int input();
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

        int read(ifstream & load);
        int display();
        int input();
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

        int read(ifstream & load);
        int display();
        int input();
        bool compare(const category & to_comp) const;
    private:
        int notification;
};
