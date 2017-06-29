#include <iostream>
  
template <typename T>
class cBinarySearchTree;
   
template <typename T>
class cNode{
 
public:
    cNode(){};
    cNode(T t){key = t; left0 = right0 = NULL;}
    cNode<T>* left0;
    cNode<T>* right0;
    T key;
};
