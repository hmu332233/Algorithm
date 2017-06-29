#include "cNode.h"
#include <iostream>
using namespace std;
   
template <typename T>
class cBinarySearchTree{
 
public:
    cBinarySearchTree(){root = NULL; };
    ~cBinarySearchTree(){};
    void treeInsert(T x);
    void treeDelete(T x);
    void treePrint();
private:
    cNode<T>* treeInsert(cNode<T>* root, T x);
    cNode<T>* treeDelete(cNode<T>* root, cNode<T>* delNode, cNode<T>* parentNode);  
    cNode<T>* deleteNode(cNode<T>* delNode);
    void treePrint(cNode<T>* t, int step);
    cNode<T>* root;
      
    cNode<T>* treeSearch(cNode<T>* root, T x);
    cNode<T>* treeSearchParent(cNode<T>* root, T x);
};
  
  
template <typename T>
void cBinarySearchTree<T>::treeInsert(T x){
//  cout<<"삽입시작"<<endl; 
    root = treeInsert(root, x);
   // cout<<"완료"<<endl; 
}
  
template <typename T>
void cBinarySearchTree<T>::treeDelete(T x){
  
   // cout<<"삭제노드찾기"<<endl;
    cNode<T>* delNode = treeSearch(root, x );
    //cout<<"삭제노드부모찾기"<<endl;
    cNode<T>* parentNode = treeSearchParent(root,x);
    //cout<<"삭제시작"<<endl;
    if( root != NULL ) root = treeDelete(root, delNode , parentNode );
    //cout<<"삭제"<<endl; 
}
  
template <typename T>
cNode<T>* cBinarySearchTree<T>::treeDelete(cNode<T>* root, cNode<T>* delNode, cNode<T>* parentNode) 
{
    //삭제노드가 루트일때 
    if( delNode == root ) root = deleteNode(root);
    else
    {   //삭제할 노드가 부모의 왼쪽 
        if( delNode == parentNode->left0 ) 
            parentNode->left0 = deleteNode(delNode); 
        else
            parentNode->right0 = deleteNode(delNode);    
    }
      
    return root;
}
template <typename T>
cNode<T>* cBinarySearchTree<T>::deleteNode(cNode<T>* delNode)
{
    //리프노드일때 
    if( delNode->left0 ==  NULL && delNode->right0 == NULL) return NULL; 
    //자식이 한개일때( 오른쪽 자식 )
    else if( delNode->left0 == NULL && delNode->right0 != NULL ) return delNode->right0;
    //자식이 한개일때( 왼쪽 자식 )
    else if( delNode->left0 != NULL && delNode->right0 == NULL ) return delNode->left0;
    //자식이 두개일때
    else
    {
        cNode<T>* sNode = delNode->right0;
        cNode<T>* parent;
        //오른쪽 서브트리 중에 제일 왼쪽
        while( sNode->left0 != NULL )
        {
            parent = sNode;
            sNode = sNode->left0;
        } 
          
        delNode->key = sNode->key;
        //sNode 노드의 자식을 붙인다.
        //근데 오른쪽 서브트리 중 왼쪽 찾으랬더니 바로 옆일때 
        if( sNode == delNode->right0 )
            delNode->right0 = sNode->right0;
        //그외 일반적인 상황 
        else
            parent->left0 = sNode->right0;
              
        return delNode;
    } 
      
  
}
  
template <typename T>
cNode<T>* cBinarySearchTree<T>::treeInsert(cNode<T>* root, T x)
{
      
  
    if( root == NULL )
    {
        cNode<T>* newNode = new cNode<T>(x);
   
        return newNode;
    }
    else
    {
        //왼쪽 
        if( x < (root->key) )
        {
            root->left0 = treeInsert( root->left0 ,x );
            return root;
        }
        else
        {
            root->right0 = treeInsert( root->right0 ,x );
            return root;
        }
    }  
}
  
template <typename T>
cNode<T>* cBinarySearchTree<T>::treeSearch(cNode<T>* root, T x)
{
    if( root == NULL || root->key == x) return root;
    else
    {
        if( x < root->key ) return treeSearch(root->left0,x);
        else return treeSearch(root->right0,x);  
    }   
}
  
template <typename T>
cNode<T>* cBinarySearchTree<T>::treeSearchParent(cNode<T>* root, T x)
{
      
     if( root->key == x ) return root;
       
      if( root->left0 != NULL )
      {
          if( root->left0->key == x ) return root;
      }
        
      if( root->right0 != NULL )
      {
          if( root->right0->key == x ) return root;    
      }
        
   
        
      if( x < root->key ) return treeSearchParent(root->left0,x);
      else return treeSearchParent(root->right0,x);  
        
}
  
  
template <typename T>
void cBinarySearchTree<T>::treePrint()
{
    int step = 0;
    treePrint(root,step);
}
  
template <typename T>
void cBinarySearchTree<T>::treePrint(cNode<T>* t, int step)
{
    if( t == NULL)
    {
        step--;
        return;
    }
      
    for(int i = 0 ; i < step ; i++ ) cout <<"    ";
      
      
    cout<< t->key<<endl; 
      
    treePrint(t->left0,++step);
    step--;
    treePrint(t->right0,++step);
    step--;
}
