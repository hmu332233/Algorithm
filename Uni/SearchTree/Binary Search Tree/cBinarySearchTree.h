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
//  cout<<"���Խ���"<<endl; 
    root = treeInsert(root, x);
   // cout<<"�Ϸ�"<<endl; 
}
  
template <typename T>
void cBinarySearchTree<T>::treeDelete(T x){
  
   // cout<<"�������ã��"<<endl;
    cNode<T>* delNode = treeSearch(root, x );
    //cout<<"�������θ�ã��"<<endl;
    cNode<T>* parentNode = treeSearchParent(root,x);
    //cout<<"��������"<<endl;
    if( root != NULL ) root = treeDelete(root, delNode , parentNode );
    //cout<<"����"<<endl; 
}
  
template <typename T>
cNode<T>* cBinarySearchTree<T>::treeDelete(cNode<T>* root, cNode<T>* delNode, cNode<T>* parentNode) 
{
    //������尡 ��Ʈ�϶� 
    if( delNode == root ) root = deleteNode(root);
    else
    {   //������ ��尡 �θ��� ���� 
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
    //��������϶� 
    if( delNode->left0 ==  NULL && delNode->right0 == NULL) return NULL; 
    //�ڽ��� �Ѱ��϶�( ������ �ڽ� )
    else if( delNode->left0 == NULL && delNode->right0 != NULL ) return delNode->right0;
    //�ڽ��� �Ѱ��϶�( ���� �ڽ� )
    else if( delNode->left0 != NULL && delNode->right0 == NULL ) return delNode->left0;
    //�ڽ��� �ΰ��϶�
    else
    {
        cNode<T>* sNode = delNode->right0;
        cNode<T>* parent;
        //������ ����Ʈ�� �߿� ���� ����
        while( sNode->left0 != NULL )
        {
            parent = sNode;
            sNode = sNode->left0;
        } 
          
        delNode->key = sNode->key;
        //sNode ����� �ڽ��� ���δ�.
        //�ٵ� ������ ����Ʈ�� �� ���� ã�������� �ٷ� ���϶� 
        if( sNode == delNode->right0 )
            delNode->right0 = sNode->right0;
        //�׿� �Ϲ����� ��Ȳ 
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
        //���� 
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
