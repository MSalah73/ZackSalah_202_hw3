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
        int compare( rb_node & to_comp) const;
        int input();
        int read(ifstream & load, const int type);
        bool bigger_than(const int to_comp);

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
        LLL_node(const char * to_copy);
        ~LLL_node();

        LLL_node & operator = (const LLL_node & to_copy);
        LLL_node & operator = (const char * to_add);
        LLL_node & operator += (const LLL_node & to_copy);
        LLL_node & operator += (const char * to_add);
        LLL_node operator + (const LLL_node & to_copy) const;
        LLL_node operator + (const char * to_add) const;

        bool operator == (const LLL_node & to_copy) const; 
        bool operator != (const LLL_node & to_copy) const; 
        bool operator < (const LLL_node & to_copy) const; 
        bool operator > (const LLL_node & to_copy) const; 
        bool operator >= (const LLL_node & to_copy) const; 
        bool operator <= (const LLL_node & to_copy) const; 
        friend ostream & operator << (ostream & out, const LLL_node & to_display);
        friend istream & operator >> (istream & in, LLL_node & to_modify);


        int read(const int type);
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
        int copy(rb_node * src, rb_node *& dest);
        int display_all(rb_node * root) const;
        int display_avg(const rb_node * root) const;
        int destroy(rb_node *& to_delete);
        bool compare(rb_node * root, rb_node * to_comp) const;
};
