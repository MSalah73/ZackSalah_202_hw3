//include rb_tree
#include "apps.h"

class LLL_node: public name
{
    public:
        LLL_node();
        LLL_node(const LLL_node & to_copy);
        LLL_node & operator = (const LLL_node & to_copy);
        ~LLL_node();

        void read();
        LLL_node *& go_next();
        void connect_next(LLL_node * to_connect);
    protected:
        void add_app();
        //tree root

}
