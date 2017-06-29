#include <iostream>

const int RED = 0;
const int BLACK = 1;

class cRedBlackTree;

class cNode{
//friend class cRedBlackTree;
public:
    cNode();
    cNode(int t){key = t; left = right = NULL; color = RED;}

    void changeColor( int _color );
//private:
    cNode* left;
    cNode* right;
    int key;
    int color;
};

void cNode::changeColor( int _color )
{
    /*
    if( color == RED ) color == BLACK;
    else color == RED;*/

    color = _color;
}
