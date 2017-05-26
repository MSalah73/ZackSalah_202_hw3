///////////////////////////////////////////////////////////////////////////////////////
//Zack Salah
//Application frequancy manager
//Homework # 3
//Programming Systems #202
///////////////////////////////////////////////////////////////////////////////////////
//This file manges Red Black node and Linked List Node classes. Each class has a 
//purpose and they have their own "Job" in the program. The OOP design sumulates the
//connections from paper to actual program. 
//
//Descriptions:
//
//The Red Black Node
//
//The Red black node class helps store the all the application entered by the program from
//all the applications installed from the phone. This program is a test however, the user
//enter the data and some appliations are from the file stored in current directory. The Red
//black tree help store the in efficenly plus it minimize traveral because of the blanace factor.
//
//Linked List Node
//
//The Linked List class is a name. the name servae as a category name. The list has a red black
//root to store all application that resigns to list category. The List class has the operators
//need to display all the data. or insert data.
/////////////////////////////////////////////////////////////////////////////////////////
//Hierarchy Connections:
//Red Black Node -"Has a"-> Category  
//Red Black Node -"Has a"-> Red Black Node 
//Linked List Node -"Is a"-> Name
//Linked List Node -"Has a"-> Red Black Node
//Linked List Node -"Has a"-> Linked List Node
/////////////////////////////////////////////////////////////////////////////////////////

#include "apps.h"
class rb_node
{
    public:
        rb_node();
        rb_node(const rb_node & to_copy);
        rb_node(const char * to_copy, const int type);
        rb_node & operator = (const rb_node & to_copy);
        ~rb_node();

        int display();
        bool compare(const rb_node & to_comp) const;
        bool compare(const char * to_comp) const;
        int input();
        int update(rb_node & to_update);
        int read(ifstream & load, const char * name, const int type);
        bool bigger_than(const int to_comp);
        int comp_names(const rb_node & to_comp);
        int comp_names(const char * to_comp);

        int to_red();
        int to_black();
        bool is_red();
        bool is_black();

        rb_node *& go_right();
        rb_node *& go_left();
        rb_node *& go_parent();

    private:
        rb_node * left, * right, * parent;
        category * app;
        enum {black, red} color;
};
class LLL_node: public name
{
    public:
        LLL_node();
        LLL_node(const LLL_node & to_copy);
        LLL_node(const char * to_add);
        ~LLL_node();

        LLL_node & operator = (const LLL_node & to_copy);
        LLL_node & operator += (const LLL_node & to_copy);
        LLL_node operator + (const LLL_node & to_copy) const;

        bool operator == (const LLL_node & to_copy) const; 
        bool operator != (const LLL_node & to_copy) const; 
        bool operator < (const LLL_node & to_copy) const; 
        bool operator > (const LLL_node & to_copy) const; 
        bool operator >= (const LLL_node & to_copy) const; 
        bool operator <= (const LLL_node & to_copy) const; 
        friend ostream & operator << (ostream & out, const LLL_node & to_display);
        friend istream & operator >> (istream & in, LLL_node & to_modify);


        int read();
        LLL_node *& go_next();
    private:
        rb_node * root;
        LLL_node * next;
        int freq_sum;
        int node_sum;

        //RED BLACK TREE INSERT CASES
        int insert_case1(rb_node *& added); 
        int insert_case2(rb_node *& added); 
        int insert_case3(rb_node *& added); 
        int insert_case4(rb_node *& added); 
        int insert_case5(rb_node *& added); 

        //RED BLACK ROTATE LEFT / RIGHT
        int rotate_left(rb_node *& to_rotate);
        int rotate_right(rb_node *& to_rotate);

        //FIND GRANDPERANTS AND UNCLE
        rb_node * find_uncle(rb_node *& child);
        rb_node * find_grand(rb_node *& child);

        int add(rb_node *& root, const char * name);
        int add_file(rb_node *& root, ifstream & load, const char * name);
        int type();
        int copy(rb_node * src, rb_node *& dest);
        int add_toTree(rb_node * src, rb_node *& dest);
        int add_toTree_src(rb_node *src);
        int display_all(rb_node * root) const;
        int display_avg(rb_node * root) const;
        int destroy(rb_node *& to_delete);
        bool compare(rb_node * root, rb_node * to_comp) const;
};
