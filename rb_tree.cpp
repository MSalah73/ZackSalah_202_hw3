#include "rb_tree.h"

rb_node::rb_node(): left(NULL), right(NULL),parent(NULL), app(NULL), color(red)//read
{
}
rb_node::rb_node(const rb_node & to_copy): left(NULL), right(NULL),parent(NULL), app(NULL), color(red)
{
    games * gptr = NULL;
    website * wptr = NULL;
    social_media * sptr = NULL;
    gptr = dynamic_cast<games*>(to_copy.app);
    wptr = dynamic_cast<website*>(to_copy.app);
    sptr = dynamic_cast<social_media*>(to_copy.app);
    if(gptr)
        app = new games(*gptr);
    else if(wptr)
        app = new website(*wptr);
    else if(sptr)
        app = new social_media(*sptr);
}
rb_node::rb_node(const char * to_copy, const int type): left(NULL), right(NULL),parent(NULL), app(NULL), color(red)
{
    if(type == 1)
        app = new games(to_copy);
    else if(type == 2)
        app = new website(to_copy);
    else if(type == 3)
        app = new social_media(to_copy);
}
rb_node & rb_node::operator = (const rb_node & to_copy)
{
    games * gptr = NULL;
    website * wptr = NULL;
    social_media * sptr = NULL;
    gptr = dynamic_cast<games*>(to_copy.app);
    wptr = dynamic_cast<website*>(to_copy.app);
    sptr = dynamic_cast<social_media*>(to_copy.app);
    if(gptr)
    {
        games * original = dynamic_cast<games*>(app);
        if(original)
            *original = *gptr;
    }
    else if(wptr)
    {
        website * original = dynamic_cast<website*>(app);
        if(original)
            *original = *wptr;
    }
    else if(sptr)
    {
        social_media * original = dynamic_cast<social_media*>(app);
        if(original)
            *original = *sptr;
    }
}
int rb_node::display()
{
    if(!app)
        return 0;
    app->display();
    return 1;
}
int rb_node::to_red()
{
    color = red;
    return 1;
}
int rb_node::to_black()
{
    color = black;
    return 1;
}
bool rb_node::is_black()
{
    return (color == black);
}
bool rb_node::is_red()
{
    return (color == red);
}
int rb_node::input()
{
    if(!app)
        return 0;
    app->input();
    return 1;
}
int rb_node::read(ifstream & load, const int type)//file type 
{
    if(type == 1)
        app = new games;
    else if(type == 2)
        app = new website;
    else if(type == 3)
        app = new social_media;
    else
        return 0;
    return app->read(load);
}
bool rb_node::bigger_than(const int to_comp)
{
    if(!app)
        return false;
    return app->bigger_than(to_comp);;
}
rb_node *& rb_node::go_right()
{
    return right;
}
rb_node *& rb_node::go_left()
{
    return left;
}
rb_node *& rb_node::go_parent()
{
    return parent;
}
rb_node::~rb_node()
{
    delete app;
}
//LLL NODE CLASS
LLL_node::LLL_node(): root(NULL), next(NULL)
{
}
LLL_node::LLL_node(const LLL_node & to_copy): root(NULL), next(NULL)
{
}
LLL_node::LLL_node(const char * to_copy): root(NULL), next(NULL)
{
}
LLL_node & LLL_node::operator = (const LLL_node & to_copy)
{
}
LLL_node & LLL_node::operator = (const char * to_add)
{
}
LLL_node & LLL_node::operator += (const LLL_node & to_copy)
{
}
LLL_node & LLL_node::operator += (const char * to_add)
{
}
LLL_node LLL_node::operator + (const LLL_node & to_copy) const
{
}
LLL_node LLL_node::operator + (const char * to_add) const
{
}
bool LLL_node::operator == (const LLL_node & to_copy) const
{
}
bool LLL_node::operator != (const LLL_node & to_copy) const
{
}
bool LLL_node::operator < (const LLL_node & to_copy) const
{
    return (node_sum < to_copy.node_sum);
}
bool LLL_node::operator > (const LLL_node & to_copy) const
{
    return (node_sum > to_copy.node_sum);
}
bool LLL_node::operator >= (const LLL_node & to_copy) const
{
    return (node_sum >= to_copy.node_sum);
}
bool LLL_node::operator <= (const LLL_node & to_copy) const
{
    return (node_sum <= to_copy.node_sum);
}
ostream & operator << (ostream & out, const LLL_node & to_display)
{
    to_display.display_avg(to_display.root);
}
istream & operator >> (istream & in, LLL_node & to_modify)
{
    char name[100] = {0};
    cout<<"\nPlese enter the name of the app\n";
    in.get(name, 100, '\n');
    in.ignore(100, '\n');
    to_modify.add(to_modify.root, name);
    return in;
}
int LLL_node::read(const int type)
{
}
LLL_node *& LLL_node::go_next()
{
    return next;
}
//RED BLACK TREE INSERT CASES
int LLL_node::insert_case1(rb_node *& added)
{
    if(!added->go_parent())
        added->to_black();
    else
        return insert_case2(added);
    return 1;
}
int LLL_node::insert_case2(rb_node *& added)
{
    if(added->go_parent()->is_black())
        return 1;
    else
        insert_case3(added);
}
int LLL_node::insert_case3(rb_node *& added)
{
    rb_node * uncle = find_uncle(added),
            * grand_parent = find_grand(added); 
    if(uncle && uncle->is_red())
    {
        added->go_parent()->to_black();
        uncle->to_black();
        grand_parent->to_red();
        insert_case1(grand_parent);
    }
    else
        insert_case4(added);
}
int LLL_node::insert_case4(rb_node *& added)
{
    rb_node * grand_parent = find_grand(added),
           * parent = added->go_parent();
    if(added == added->go_parent()->go_right() && added->go_parent() == grand_parent->go_left())
    {
        rotate_left(added);
        return insert_case5(parent);
    }
    else if(added == added->go_parent()->go_left() && added->go_parent() == grand_parent->go_right())
    {
        rotate_left(added);
        return insert_case5(parent);
    }
    return insert_case5(added);
}
int LLL_node::insert_case5(rb_node *& added)
{
    rb_node * grand_parent = find_grand(added);
    added->go_parent()->to_black();
    grand_parent->to_red();
    if(added == added->go_parent()->go_left())
        rotate_right(added->go_parent());
    if(added == added->go_parent()->go_right())
        rotate_left(added->go_parent());
}
//RED BLACK ROTATE LEFT / RIGHT
int LLL_node::rotate_left(rb_node *& to_rotate)
{
    if(!to_rotate || !to_rotate->go_parent()) 
        return 0;
    rb_node * grand_parent = to_rotate->go_parent(),
         * hold_left = to_rotate->go_left(),
         * hold_2nd_grand_parent = grand_parent->go_parent();

    to_rotate->go_parent() = hold_2nd_grand_parent;
    grand_parent->go_parent() = to_rotate;
    to_rotate->go_left() = grand_parent;
    grand_parent->go_right() = hold_left;

    if(hold_left)
        hold_left->go_parent() = grand_parent;
    if(hold_2nd_grand_parent)
    {
        if(grand_parent == hold_2nd_grand_parent->go_left())
            hold_2nd_grand_parent->go_left() = to_rotate;
        else
            hold_2nd_grand_parent->go_right() = to_rotate;
    }
    else
        root = to_rotate;
}
int LLL_node::rotate_right(rb_node *& to_rotate)
{
    if(!to_rotate || !to_rotate->go_parent()) 
        return 0;
    rb_node * grand_parent = to_rotate->go_parent(),
         * hold_right = to_rotate->go_right(),
         * hold_2nd_grand_parent = grand_parent->go_parent();

    to_rotate->go_parent() = hold_2nd_grand_parent;
    grand_parent->go_parent() = to_rotate;
    to_rotate->go_right() = grand_parent;
    grand_parent->go_left() = hold_right;

    if(hold_right)
        hold_right->go_parent() = grand_parent;
    if(hold_2nd_grand_parent)
    {
        if(grand_parent == hold_2nd_grand_parent->go_left())
            hold_2nd_grand_parent->go_left() = to_rotate;
        else
            hold_2nd_grand_parent->go_right() = to_rotate;
    }
    else
        root = to_rotate;

}
//FIND GRANDPERANTS AND UNCLE
rb_node * LLL_node::find_uncle(rb_node *& child)
{
    rb_node * grand_parent = find_grand(child);
    if(!grand_parent)
        return NULL;
    if(child->go_parent() == grand_parent->go_left())
        return grand_parent->go_right();
    else
        return grand_parent->go_left();
}
rb_node * LLL_node::find_grand(rb_node *& child)
{
    if(child && child->go_parent())
        return child->go_parent()->go_parent();
    else
        return NULL;
}
int LLL_node::add(rb_node *& root, const char * name)
{
}
int LLL_node::copy(rb_node * src, rb_node *& dest)
{
}
int LLL_node::display_all(rb_node * root) consT
{
}
int LLL_node::display_avg(const rb_node * root) const
{
}
int LLL_node::destroy(rb_node *& to_delete)
{
    if(!to_delete)
        return 1;
    destroy(to_delete->go_right());
    destroy(to_delete->go_left());
    delete to_delete;
}
bool compare(rb_node * root, rb_node * to_comp) const
{
}
LLL_node::~LLL_node()
{
    destroy(root);
}
