///////////////////////////////////////////////////////////////////////////////////////
//Zack Salah
//Application frequancy manager
//Homework # 3
//Programming Systems #202
///////////////////////////////////////////////////////////////////////////////////////
//This file contains the implentaion of the Red Black Node and Linked List Node classes.
//It contains every function that the programs would need. The comments in the file will
//descripe the functionalty step by step to ensure the grader's understanding of all the
//functions.
//
//As I immplented all of the classes, I have returned and added and fixed some
//of the functions in this file. Because most of the function have functions from
//outside of the class. I encourge opening all the files to ensure all of the 
//connections that has been made.
//
//Algorithms
//
//This file contain the core of the programs. This file orginaze the applications stored
//each Linked list. The Red Black with orginize it self as the a node enters the tree this 
//will give Big O of (log n) in inserting and display an incridiabliy fast algorithm.The Linked
//List will help determine the type name to minimize the use of dynamic cast.
//
/////////////////////////////////////////////////////////////////////////////////////////
//Hierarchy Connections:
//Red Black Node -"Has a"-> Category  
//Red Black Node -"Has a"-> Red Black Node 
//Linked List Node -"Is a"-> Name
//Linked List Node -"Has a"-> Red Black Node
//Linked List Node -"Has a"-> Linked List Node
/////////////////////////////////////////////////////////////////////////////////////////

#include "rb_tree.h"
//Constructor 
rb_node::rb_node(): left(NULL), right(NULL),parent(NULL), app(NULL), color(red)
{
}
//Copy constructor
//step 1: use dynamic cast on each type
//step 2: check if one the pointers is not null
//step 3: allocate to new type of that is not null with the copy constructors
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
//step 1: check if the passed in number is equal to one of the values
//step 2: allocate to the type and pass in the name with construtor with char arguments
rb_node::rb_node(const char * to_copy, const int type): left(NULL), right(NULL),parent(NULL), app(NULL), color(red)
{
    if(type == 1)
        app = new games(to_copy);
    else if(type == 2)
        app = new website(to_copy);
    else if(type == 3)
        app = new social_media(to_copy);
}
//Operator =
//Step 1: check if current object is the same as the passed in arrgument
//step 2: use dynamic cast on each type
//step 3: check if one the pointers is not null
//step 4: repeat 2 and 3 with current app
//step 5: use the assigment oprators of category drived classes
rb_node & rb_node::operator = (const rb_node & to_copy)
{
    if(this == &to_copy)
        return *this;
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
    return *this;
}
//step 1: check if app is null - return
//step 2; display app contants and return 
int rb_node::display()
{
    if(!app)
        return 0;
    app->display();
    return 1;
}
//step 1: set color to red and return 
int rb_node::to_red()
{
    color = red;
    return 1;
}
//step 1: set color to black and return 
int rb_node::to_black()
{
    color = black;
    return 1;
}
//step 1: compare if the current color is black and return 
bool rb_node::is_black()
{
    return (color == black);
}
//step 1: compare if the current color is red and return 
bool rb_node::is_red()
{
    return (color == red);
}
//step 1: check if app null - return
//step 2: call input function for the user to enter data
int rb_node::input()
{
    if(!app)
        return 0;
    app->input();
    return 1;
}
//step 1: 
int rb_node::read(ifstream & load, const char * name, const int type)//file type 
{
    if(type == 1)
        app = new games;
    else if(type == 2)
        app = new website;
    else if(type == 3)
        app = new social_media;
    else
        return 0;
    return app->read(load, name);
}
bool rb_node::compare(const rb_node & to_comp) const
{
    games * gptr = NULL;
    website * wptr = NULL;
    social_media * sptr = NULL;
    gptr = dynamic_cast<games*>(app);
    wptr = dynamic_cast<website*>(app);
    sptr = dynamic_cast<social_media*>(app);
    if(gptr)
        return gptr->compare(*to_comp.app);
    else if(wptr)
        return wptr->compare(*to_comp.app);
    else if(sptr)
        return sptr->compare(*to_comp.app);
    return false;
}
bool rb_node::compare(const char * to_comp) const
{
    return !app->name::compare(to_comp);
}
bool rb_node::bigger_than(const int to_comp)
{
    if(!app)
        return false;
    return app->bigger_than(to_comp);;
}
int rb_node::update(rb_node & to_update)
{
    games * gptr = NULL;
    website * wptr = NULL;
    social_media * sptr = NULL;
    gptr = dynamic_cast<games*>(app);
    wptr = dynamic_cast<website*>(app);
    sptr = dynamic_cast<social_media*>(app);
    if(gptr)
        return gptr->update(*to_update.app);
    else if(wptr)
        return wptr->update(*to_update.app);
    else if(sptr)
        return sptr->update(*to_update.app);
    return 0;
}
int rb_node::comp_names(const rb_node & to_comp)
{
    return app->name::compare(*to_comp.app); 
}
int rb_node::comp_names(const char * to_comp)
{
    return app->name::compare(to_comp); 
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
LLL_node::LLL_node(): root(NULL), next(NULL), freq_sum(0), node_sum(0)
{
}
LLL_node::LLL_node(const char * to_add): name(to_add), root(NULL), next(NULL), freq_sum(0), node_sum(0)
{
}
LLL_node::LLL_node(const LLL_node & to_copy): name(to_copy), root(NULL), next(NULL),freq_sum(0), node_sum(0)
{
    copy(to_copy.root, root);
}
//Operator =
//Step 1: check if current name is has data - delete if so
//step 2: allocate current name with the passed args size
//step 3: copy from the passed in arugment to the current name
//step 4: return this address

LLL_node & LLL_node::operator = (const LLL_node & to_copy)
{
    if(this == &to_copy)
        return *this;
    if(root)
    {
        destroy(root);
        root = NULL;
    }
    copy(to_copy.root, root);
    return *this;
}
//Operator +=
//step 1: add the contant from the passed in tree to the current tree
//step 2: return this ref
LLL_node & LLL_node::operator += (const LLL_node & to_copy)
{
    add_toTree_src(to_copy.root);
    return *this;
}
//step 1: make a temp object and copy the contant of current object 
//step 2: add the contant from the passed in tree to the temp tree
//step 3: add the freqancy from passed in object to the temp frequcy number
//step 4: return temp 
LLL_node LLL_node::operator + (const LLL_node & to_copy) const
{
    LLL_node temp(*this);
    temp.add_toTree_src(to_copy.root);
    temp.freq_sum += to_copy.freq_sum;
    return temp;
}
//step 1: call compare current tree with passed in tree and return
bool LLL_node::operator == (const LLL_node & to_copy) const
{
    return compare(this->root, to_copy.root);
}
//step 1: call compare current tree with passed in tree and return
bool LLL_node::operator != (const LLL_node & to_copy) const
{
    return !compare(this->root, to_copy.root);
}
//step 1: compare the frequancy from current tree to the passed in tree and return 
bool LLL_node::operator < (const LLL_node & to_copy) const
{
    return (freq_sum < to_copy.freq_sum);
}
//step 1: compare the frequancy from current tree to the passed in tree and return 
bool LLL_node::operator > (const LLL_node & to_copy) const
{
    return (freq_sum > to_copy.freq_sum);
}
//step 1: compare the frequancy from current tree to the passed in tree and return  
bool LLL_node::operator >= (const LLL_node & to_copy) const
{
    return (freq_sum >= to_copy.freq_sum);
}
//step 1: compare the frequancy from current tree to the passed in tree and return 
bool LLL_node::operator <= (const LLL_node & to_copy) const
{
    return (freq_sum <= to_copy.freq_sum);
}
//step 1: call display of the passed in object
//step 2: return ostream object 
ostream & operator << (ostream & out, const LLL_node & to_display)
{
    to_display.display_avg(to_display.root);
    return out;
}
//step 1: ask the user to enter a name of the application
//step 2: added to the tree
//step 3: return istream object 
istream & operator >> (istream & in, LLL_node & to_modify)
{
    char name[100] = {0};
    cout<<"\nPlese enter the name of the app\n";
    in.get(name, 100, '\n');
    in.ignore(100, '\n');
    to_modify.add(to_modify.root, name);
    return in;
}
//step 1: assign the type number to a local verable
//step 2: if type - make a ifstream object and open a file depending on the type number
//step 3: load the frequacy and the node numbers
//step 4: load the name and add it to the tree with load object passed in to load the other data memers --check apps.cpp
//step 5: close file and return 
int LLL_node::read()
{
    int _type = type();
    if(_type)
    {
        ifstream load;
        if(_type == 1)
            load.open("games.txt");
        else if(_type == 2)
            load.open("websites.txt");
        else if(_type == 3)
            load.open("social_media.txt");
        if(load)
        {
            char temp[100];
            load>>freq_sum;
            load.ignore(100, '|');
            load>>node_sum;
            load.ignore(100, '\n');
            while(!load.eof())
            {
                load.get(temp, 100, '|');
                load.ignore(100, '|');
                if(temp[0])
                    add_file(root, load, temp);
            }
        }
        load.clear();
        load.close();
        return 1;
    }
    return 0;
}
//return the next pointer 
LLL_node *& LLL_node::go_next()
{
    return next;
}
//RED BLACK TREE INSERT CASES
//
//step 1: check if parent is not null - turn color to black
//step 2: else call case 2
int LLL_node::insert_case1(rb_node *& added)
{
    if(!added->go_parent())
        added->to_black();
    else
        return insert_case2(added);
    return 1;
}
//step 1: check if parent is black - return
//step 2: call case 3
int LLL_node::insert_case2(rb_node *& added)
{
    if(added->go_parent()->is_black())
        return 1;
    else
        return insert_case3(added);
}
//step 1: make a local uncle and grand parent node with find functions
//step 2: check if uncle exixt and its red 
//step 2a: change current and uncle node to black and grand parent to red
//step 2b: call case 1 on grand parent
//step 3: call case 4
int LLL_node::insert_case3(rb_node *& added)
{
    rb_node * uncle = find_uncle(added),
            * grand_parent = find_grand(added); 
    if(uncle && uncle->is_red())
    {
        added->go_parent()->to_black();
        uncle->to_black();
        grand_parent->to_red();
        return insert_case1(grand_parent);
    }
    else
        return insert_case4(added);
}

//step 1: make a local grand parent parent node with find functions
//step 2: check if current node is equal to parent's right child and if current parrent is grand parent's left child
//step 2a: call roate on current and call inser case 5 on parents 
//step 3: check if current node is equal to parent's left child and if current parrent is grand parent's right child
//step 3a: call roate on current and call inser case 5 on parents 
//step 4: call case five on current
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
//step 1: make a local grand parent with find function
//step 2: turn current parents to black
//step 3: turn grand parents to red 
//step 4: if current is equal to crrent's parent's left child
//step 4a: call rotate right with curents parent 
//step 5: if current is equal to crrent's parent's right child
//step 5a: call rotate left with curents parent 
int LLL_node::insert_case5(rb_node *& added)
{
    rb_node * grand_parent = find_grand(added);
    added->go_parent()->to_black();
    grand_parent->to_red();
    if(added == added->go_parent()->go_left())
        return rotate_right(added->go_parent());
    if(added == added->go_parent()->go_right())
        return rotate_left(added->go_parent());
    return 0;
}
//RED BLACK ROTATE LEFT / RIGHT
//
//step 1: check if current or current' parents is null
//step 2: make a local grand parent with find function
//step 3: and some local hold current's left child and current's grand parents
//step 4: Rotaing by assigning pointers
//step 4a: check if some are are not null to assign to other pointer
//setp 4b: if null root equal to rotate
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
    return 1;
}
//step 1: check if current or current' parents is null
//step 2: make a local grand parent with find function
//step 3: and some local hold current's right child and current's grand parents
//step 4: Rotaing by assigning pointers
//step 4a: check if some are are not null to assign to other pointer
//setp 4b: if null root equal to rotate
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
    return 1;
}
//FIND GRANDPERANTS AND UNCLE
//
//Step 1: assign a pointer to the grand_parent with find grand function
//step 2: check if grand parent is null - return 
//step 3: check if child's parent is the same as grand parant's left child 
//step 3a: return grand parent right child
//step 4: return grand parent left child 
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
//step 1: check if child and child's paprent is not null
//step 1a: return child parent's parant 
//step 2: return NULL
rb_node * LLL_node::find_grand(rb_node *& child)
{
    if(child && child->go_parent())
        return child->go_parent()->go_parent();
    else
        return NULL;
}
//step 1: check if root is null
//step 1a: add one to frequancy and nodes sums 
//step 1b: allcolate root with the named passed in 
//step 1c: call orgnize tree case one
//step 2: check if the root name is the same as passed in name
//step 2a: add one to frequnacy and call input
//step 3: if root name is less than that passed in go left otherwise go right 
int LLL_node::add(rb_node *& root, const char * name)
{
    if(!root)
    {
        ++freq_sum;
        ++node_sum;
        root = new rb_node(name,type());
        insert_case1(root);
        return 1;
    }
    if(root->compare(name))
    {
        ++freq_sum;
        root->input();
        return 1;
    }
    if(root->comp_names(name) < 0)
        return add(root->go_left(), name);
    return add(root->go_right(), name);
}
//step 1: check if root is null
//step 1a: allocate root and call read from file with ifstream passed in
//step 1b: call organize tree case one
//step 2: if root not null - check if root is the same as the name
//step 2a: call read with from file with ifstream passed in
//step 3: if root name is less than that passed in go left otherwise go right 
int LLL_node::add_file(rb_node *& root, ifstream & load, const char * name)
{
    if(!root)
    {
        root = new rb_node();
        root->read(load, name, type());
        insert_case1(root);
        return 1;
    }
    if(root->compare(name))
    {
        root->read(load, name, type());
        return 1;
    }
    if(root->comp_names(name) < 0)
        return add_file(root->go_left(), load, name);
    return add_file(root->go_right(), load, name);
}
//step 1: check if the current object name is simmilar with the if statments
//step 2: return the number associated with the type
int LLL_node::type()
{
    if(!name::compare("Games"))
        return 1;
    else if(!name::compare("Website"))
        return 2;
    else if(!name::compare("Social Media"))
        return 3;
    return 0;
}
//step 1: check if source is null - return 
//step 2: alloacte dest and call copy constructor with source 
//step 3: call it self with right and left
int LLL_node::copy(rb_node * src, rb_node *& dest)
{
    if(!src)
        return 0;
    dest = new rb_node(*src);
    return copy(src->go_left(), dest->go_left()) + copy(src->go_right(), dest->go_right());
}
//step 1: check if source is null - return 
//step 2: call add to tree with source
//step 3: call it self with right and left
int LLL_node::add_toTree_src(rb_node *src)
{
    if(!src)
        return 0;
    add_toTree(src, root);
    return add_toTree_src(src->go_left()) + add_toTree_src(src->go_right());
}
//step 1: check if dest is null
//step 1a: add the sum of nodes
//step 1b: allocate current root with paased in source to call the copy constructor and return 
//step 2: check is the dest applicate name is the same as source name
//step 2a: update current root with source
//step 3: compare names and if the return value is smaller than 0  go left otherwise go right
int LLL_node::add_toTree(rb_node * src, rb_node *& dest)
{
    if(!dest)
    {
        ++node_sum;
        dest = new rb_node(*src);
        return 1;
    }
    if(dest->compare(*src))
    {
        dest->update(*src);
        return 1;
    }
    if(dest->comp_names(*src) < 0)
        return add_toTree(src,dest->go_left());
    else
        return add_toTree(src,dest->go_right());
}
//step 1: check if root is null - return
//step 2: call it self with left
//step 3: display data
//step 4: call it self with right and return 
int LLL_node::display_all(rb_node * root) const
{
    if(!root)
        return 0;
    display_all(root->go_left());
    root->display();
    display_all(root->go_right());
    return 1;
}
//step 1: check if root is null - return
//step 2: call it self with left
//step 3: check the current root is larger frequancy wise than the avrage data - display data
//step 4: call it self with right and return 
int LLL_node::display_avg(rb_node * root) const
{
    if(!root)
        return 0;
    display_avg(root->go_left());
    if(root->bigger_than(freq_sum / node_sum))
        root->display();
    display_avg(root->go_right());
    return 1;
}
//step 1: check if root is null - return
//step 2: call it self with right and left
//step 3: delete root and return
int LLL_node::destroy(rb_node *& to_delete)
{
    if(!to_delete)
        return 1;
    destroy(to_delete->go_right());
    destroy(to_delete->go_left());
    delete to_delete;
    return 1;
}
//step 1: check if root is null - return 
//step 2: call it self with right and left
//step 3: call root compare on the passed arguments and return
bool LLL_node::compare(rb_node * root, rb_node * to_comp) const
{
    if(!root)
        return 0;
    return compare(root->go_right(), to_comp->go_right()) + compare(root->go_left(), to_comp->go_left()) + root->compare(*to_comp);
}
//destructor
//step 1: call destory on the root 
LLL_node::~LLL_node()
{
    destroy(root);
}
