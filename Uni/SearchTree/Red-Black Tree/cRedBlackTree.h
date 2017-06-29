#include "cNode.h"
#include <iostream>
using namespace std;

class cRedBlackTree{
public:
        //이부분의 양식은 반드시 지켜져야한다.
        void test();


    cRedBlackTree();
    ~cRedBlackTree(){};
    void treeInsert(int d);
    void treeDelete(int d);
    void treePrint();
private:
    cNode* root;
    cNode* nil;

    int sw;

        //public에 있는 멤버 함수를 위해 자유롭게 구현한다.
    cNode* treeInsert(cNode* root, int x);
    cNode* checkInsert(cNode* root , int x );

    cNode* treeDelete(cNode* root, cNode* delNode, cNode* parentNode);
    cNode* deleteNode(cNode* delNode);
    cNode* checkDelete(cNode* delNode  , cNode* xNode, cNode* parentNode );

    cNode* treeSearch(cNode* root, int x);
    cNode* treeSearchParent(cNode* root, int x);

    //회전
    cNode* rotateLeft(cNode* centerNode, cNode* parentNode );
    cNode* rotateRight(cNode* centerNode, cNode* parentNode );


    void treePrint(cNode* t, int step);
};

void cRedBlackTree::test()
{/*
    root = new cNode(10);
    root->changeColor( BLACK );
    root->left = new cNode(9);
    root->left->left = nil;
    root->left->right = nil;
    root->right = new cNode(11);
    root->right->left = nil;
    root->right->right = nil;
    //root->right->changeColor( BLACK );
    root->left->left = new cNode(8);
    root->left->left->left = nil;
    root->left->left->right = nil;
    */
    root = treeInsert( root , 10 );
    root = treeInsert( root , 9 );
    root = treeInsert( root , 11 );
    root = treeInsert( root , 8 );

    checkInsert( root , 8 );

    rotateLeft( root , root );


    treePrint( root , 0 );

}

cRedBlackTree::cRedBlackTree()
{
    cNode* nilNode = new cNode(0);
    nilNode->changeColor( BLACK ); //레드에서 블랙으로

    nil = nilNode;
    root = nil;

    cout<<"생성자"<<endl;
    sw = 0;
}


void cRedBlackTree::treeDelete(int x){

   // cout<<"삭제노드찾기"<<endl;
    cNode* delNode = treeSearch(root, x );
    cout<<"삭제할 노드 : " << delNode->key <<endl;
    //cout<<"삭제노드부모찾기"<<endl;
    cNode* parentNode = treeSearchParent(root,x);
    //---------------------------------
    //cout<<"삭제시작"<<endl;
    if( root != nil ) root = treeDelete(root, delNode , parentNode );
    //cout<<"삭제"<<endl;


}

cNode* cRedBlackTree::treeDelete(cNode* root, cNode* delNode, cNode* parentNode)
{
    cNode* xNode;
    sw = 0;
    int ws = 0;

    //삭제 노드가 레드면 그냥 삭제
    //삭제 노드가 블랙이고 유일한 자식이 레드이면 자식을 블랙으로 변경
    if( delNode->color == BLACK )
    {
        cout<<"삭제노드 : 블랙"<<endl;

        if( delNode->left == nil && delNode->right != nil )
        {
            if( delNode->right->color == RED )
            {
                delNode->right->changeColor(BLACK);
                cout<<"삭제노드 블랙 : 자식 노드 레드"<<endl;
                sw = 1;
                ws = 1;
            }
        }
        else if( delNode->left != nil && delNode->right == nil )
        {
            if( delNode->left->color == RED )
            {
                delNode->left->changeColor(BLACK);
                cout<<"삭제노드 블랙 : 자식 노드 레드"<<endl;
                sw = 1;
                ws = 1;
            }

        }
    }

    //cNode* parentNode = treeSearchParent( root , delNode->key );

     //삭제노드가 루트일때
    if( delNode == root )
    {
        root = deleteNode(root);
        xNode = root;
    }
    else
    {   //삭제할 노드가 부모의 왼쪽
        if( delNode == parentNode->left )
        {
            parentNode->left = deleteNode(delNode);
            xNode = parentNode->left;
        }

        else
        {
            parentNode->right = deleteNode(delNode);
            xNode = parentNode->right;
        }
    }

    cout<<"삭제 완료 "<<endl;
    if( delNode->color == RED ) return root;
    if( xNode != root && xNode->color == BLACK && ws == 0 ) sw = 0;

    //--------삭제후 처리

    if( sw != 1 ) root = checkDelete( delNode, xNode , parentNode );


    return root;
}
cNode* cRedBlackTree::checkDelete(cNode* delNode  , cNode* xNode , cNode* parentNode )
{
    cout<< " 색처리 시작" <<endl;

    if( delNode->color == BLACK && xNode->color == BLACK )
    {
        cout<<"삭제 노드 블랙 : 그 자식노드 블랙"<<endl;


        //cNode* parentNode = treeSearchParent( root , xNode->key );
        cNode* sNode;

        //p가 레드
        if( parentNode->color == RED )
        {
            cout<<"부모가 레드"<<endl;
            //내가 왼쪽노드일때
            if( parentNode->left == xNode )
            {
                sNode = parentNode->right;


                //case1-1 <블랙,블랙>
                if( sNode->left->color == BLACK && sNode->right->color == BLACK )
                {
                    cout<<"case1-1 <블랙,블랙>"<<endl;
                    sNode->changeColor( RED );
                    parentNode->changeColor( BLACK );
                } //case1-2 <*,레드>
                else if(  sNode->right->color == RED )
                {
                    cout<<"case1-2 <*,레드> "<<endl;
                    cNode* grandParentNode =  treeSearchParent( root , parentNode->key );

                    root = rotateLeft( parentNode , grandParentNode );

                    sNode->changeColor( parentNode->color );
                    parentNode->changeColor( BLACK );

                    sNode->right->changeColor( BLACK );
                } //case1-3<레드,블랙>
                else if( sNode->left->color == RED && sNode->right->color == BLACK )
                {
                    cout<<"case1-3<레드,블랙> "<<endl;
                    sNode->left->changeColor( BLACK );
                    sNode->changeColor( RED );

                    root = rotateRight( sNode , parentNode );

                    root = checkDelete( delNode , xNode , parentNode );
                }
            }
            //오른쪽 노드일때
            else
            {
                 sNode = parentNode->left;


                //case1-1 <블랙,블랙>
                if( sNode->right->color == BLACK && sNode->left->color == BLACK )
                {
                    cout<<"//case1-1 <블랙,블랙>"<<endl;
                    sNode->changeColor( RED );
                    parentNode->changeColor( BLACK );
                } //case1-2 <*,레드>
                else if(  sNode->left->color == RED )
                {
                    cout<<"//case1-2 <*,레드>  "<<endl;
                    cNode* grandParentNode =  treeSearchParent( root , parentNode->key );

                    root = rotateRight( parentNode , grandParentNode );

                    sNode->changeColor( parentNode->color );
                    parentNode->changeColor( BLACK );

                    sNode->left->changeColor( BLACK );
                } //case1-3<레드,블랙>
                else if( sNode->right->color == RED && sNode->left->color == BLACK )
                {
                    cout<<"//case1-3<레드,블랙> "<<endl;
                    sNode->right->changeColor( BLACK );
                    sNode->changeColor( RED );

                    root = rotateLeft( sNode , parentNode );

                    root = checkDelete( delNode , xNode , parentNode );
                }
            }
        }
        else //p가 블랙
        {
            cout<<"부모가 블랙"<<endl;
            //내가 왼쪽노드일때
            if( parentNode->left == xNode )
            {

                sNode = parentNode->right;

                //case2-1 <블랙,블랙,블랙>
                if( sNode->color == BLACK && sNode->left->color == BLACK && sNode->right->color == BLACK )
                {
                    cout<<"case2-1 <블랙,블랙,블랙>"<<endl;
                    sNode->changeColor( RED );

                    root = checkDelete( delNode , parentNode , parentNode );
                }//case2-2 <블랙,*,레드 >
                else if( sNode->color == BLACK && sNode->right->color == RED )
                {
                    cout<<"case2-2 <블랙,*,레드 >"<<endl;
                    cNode* grandParentNode =  treeSearchParent( root , parentNode->key );

                    root = rotateLeft( parentNode , grandParentNode );

                    sNode->changeColor( parentNode->color );
                    parentNode->changeColor( BLACK );

                    sNode->right->changeColor( BLACK );
                } //case2-3 <블랙,레드,블랙>
                else if( sNode->color == BLACK && sNode->left->color == RED && sNode->right->color ==BLACK )
                {
                    cout<<"case2-3 <블랙,레드,블랙> "<<endl;
                    sNode->left->changeColor( BLACK );
                    sNode->changeColor( RED );

                    root = rotateRight( sNode , parentNode );

                    root = checkDelete( delNode , xNode , parentNode);
                } //case2-4 <레드,블랙,블랙>
                else if( sNode->color == RED && sNode->left->color == BLACK && sNode->right->color ==BLACK )
                {
                    cout<<"case2-4 <레드,블랙,블랙> "<<endl;
                    cNode* grandParentNode =  treeSearchParent( root , parentNode->key );

                    root = rotateLeft( parentNode , grandParentNode );

                    root = checkDelete( delNode  , xNode , parentNode );
                }
            }
            else //내가 오른쪽 노드일때
            {
                sNode = parentNode->left;

                //case2-1 <블랙,블랙,블랙>
                if( sNode->color == BLACK && sNode->right->color == BLACK && sNode->left->color == BLACK )
                {
                    cout<<"//case2-1 <블랙,블랙,블랙>"<<endl;
                    sNode->changeColor( RED );

                    root = checkDelete( delNode , parentNode , parentNode);
                }//case2-2 <블랙,*,레드 >
                else if( sNode->color == BLACK && sNode->left->color == RED )
                {
                    cout<<"//case2-2 <블랙,*,레드 > "<<endl;
                    cNode* grandParentNode =  treeSearchParent( root , parentNode->key );

                    root = rotateRight( parentNode , grandParentNode );

                    sNode->changeColor( parentNode->color );
                    parentNode->changeColor( BLACK );

                    sNode->left->changeColor( BLACK );
                } //case2-3 <블랙,레드,블랙>
                else if( sNode->color == BLACK && sNode->right->color == RED && sNode->left->color ==BLACK )
                {
                    cout<<"//case2-3 <블랙,레드,블랙> "<<endl;
                    sNode->right->changeColor( BLACK );
                    sNode->changeColor( RED );

                    root = rotateLeft( sNode , parentNode );

                    root = checkDelete( delNode , xNode , parentNode );
                } //case2-4 <레드,블랙,블랙>
                else if( sNode->color == RED && sNode->right->color == BLACK && sNode->left->color ==BLACK )
                {
                    cout<<"//case2-4 <레드,블랙,블랙> "<<endl;
                    cNode* grandParentNode =  treeSearchParent( root , parentNode->key );

                    root = rotateRight( parentNode , grandParentNode );

                    root = checkDelete( delNode  , xNode , parentNode );
                }
            }
        }

    }

    return root;
}


cNode* cRedBlackTree::deleteNode(cNode* delNode)
{
    //리프노드일때
    if( delNode->left ==  nil && delNode->right == nil) return nil;
    //자식이 한개일때( 오른쪽 자식 )
    else if( delNode->left == nil && delNode->right != nil ) return delNode->right;
    //자식이 한개일때( 왼쪽 자식 )
    else if( delNode->left != nil && delNode->right == nil ) return delNode->left;
    //자식이 두개일때
    else
    {
        sw = 1;
        cNode* sNode = delNode->right;
        cNode* parent;
        //오른쪽 서브트리 중에 제일 왼쪽
        while( sNode->left != nil )
        {
            parent = sNode;
            sNode = sNode->left;
        }

        delNode->key = sNode->key;
        //sNode 노드의 자식을 붙인다.
        //근데 오른쪽 서브트리 중 왼쪽 찾으랬더니 바로 옆일때
        if( sNode == delNode->right )
            delNode->right = sNode->right;
        //그외 일반적인 상황
        else
            parent->left = sNode->right;

        return delNode;
    }
}

void cRedBlackTree::treeInsert(int x)
{
    root = treeInsert( root , x ); //이진트리 삽입

    //루트노드이면 그대로 종료
    if( root->left == nil && root->right == nil )
    {
        cout<<"루트노드임"<<endl;
        root->changeColor( BLACK );
        return;
    }

    root = checkInsert( root , x );
}

cNode* cRedBlackTree::checkInsert(cNode* root , int x )
{
    cout<<"삽입체크"<<endl;
    //부모노드 찾기 p
    cNode* parentNode = treeSearchParent( root, x );
    cout<<"부모 : " <<  parentNode->key<<endl;
    //본인 찾기 x
    cNode* xNode = treeSearch( root , x ) ;
    cout<<"본인 : " <<  xNode->key<<endl;

    if( parentNode->color == RED )
    {
        cout<<"p 가 레드 " <<endl;
        //p2
        cNode* grandParentNode = treeSearchParent( root , parentNode->key );

        if( grandParentNode->left == parentNode ) //왼쪽
        {

            cNode* sNode = grandParentNode->right;

            if( sNode->color == RED ) //s가 레드
            {
                cout<<"case 1 : s가 레드"<<endl;

                sNode->changeColor( BLACK );
                parentNode->changeColor( BLACK );
                grandParentNode->changeColor( RED );

                cout<<"s p p2 색 반전"<<endl;


                if( grandParentNode == root )
                {
                    grandParentNode->changeColor( BLACK );
                    return root;
                }

                cNode* greatGrandParentNode = treeSearchParent( root , grandParentNode->key );

                if( greatGrandParentNode->color == RED )
                {
                    cout<<"p2 기준으로 재호출"<<endl;
                    root = checkInsert( root , grandParentNode->key );
                }

            }
            else //s가 블랙
            {
                cout<<"case 2 : s가 블랙"<<endl;

                //x가 p의 오른쪽 자식
                if( xNode == parentNode->right )
                {
                    cout<<"case 2-1: x가 p의 오른쪽 자식"<<endl;
                    rotateLeft( parentNode , grandParentNode);


                    swap( parentNode , xNode );
                }

                cout<<"case 2-2: x가 p의 왼쪽 자식"<<endl;

                cNode* greatGrandParentNode = treeSearchParent( root , grandParentNode->key );

                parentNode->changeColor( BLACK );
                grandParentNode->changeColor( RED );

                root = rotateRight( grandParentNode , greatGrandParentNode );

            }
        }
        else //오른쪽
        {
            cNode* sNode = grandParentNode->left;

            if( sNode->color == RED ) //s가 레드
            {
                cout<<"case 1 : s가 레드"<<endl;

                sNode->changeColor( BLACK );
                parentNode->changeColor( BLACK );
                grandParentNode->changeColor( RED );

                cout<<"s p p2 색 반전"<<endl;


                if( grandParentNode == root )
                {
                    cout<<"루트노드는 블랙으로"<<endl;
                    grandParentNode->changeColor( BLACK );

                    return root;
                }
                 cNode* greatGrandParentNode = treeSearchParent( root , grandParentNode->key );

                if( greatGrandParentNode->color == RED )
                {
                    cout<<"p2 기준으로 재호출"<<endl;
                    root = checkInsert( root , grandParentNode->key );
                }
            }
            else //s가 블랙
            {
                cout<<"2case 2 : s가 블랙"<<endl;

                //x가 p의 오른쪽 자식 1
                if( xNode == parentNode->left )
                {
                    cout<<"2case 2-1: x가 p의 왼쪽 자식"<<endl;
                    rotateRight( parentNode , grandParentNode);


                    swap( parentNode , xNode );
                }

                cout<<"2case 2-2: x가 p의 오른쪽 자식"<<endl;

                cNode* greatGrandParentNode = treeSearchParent( root , grandParentNode->key );

                parentNode->changeColor( BLACK );
                grandParentNode->changeColor( RED );

                root = rotateLeft( grandParentNode , greatGrandParentNode );

            }
        }

    }

    return root;
}



cNode* cRedBlackTree::treeInsert(cNode* root, int x)
{
    if( root == nil )
    {
        cNode* newNode = new cNode(x);
        newNode->left = nil;
        newNode->right = nil;

        return newNode;
    }
    else
    {
        if( x < (root->key) )
        {
            root->left = treeInsert( root->left ,x );
            return root;
        }
        else
        {
            root->right = treeInsert( root->right ,x );
            return root;
        }
    }
}

cNode* cRedBlackTree::treeSearch(cNode* root, int x)
{
    if( root == nil || root->key == x) return root;
    else
    {
        if( x < root->key ) return treeSearch(root->left,x);
        else return treeSearch(root->right,x);
    }
}

cNode* cRedBlackTree::treeSearchParent(cNode* root, int x)
{

     if( root->key == x ) return root;

      if( root->left != nil )
      {
          if( root->left->key == x ) return root;
      }

      if( root->right != nil )
      {
          if( root->right->key == x ) return root;
      }



      if( x < root->key ) return treeSearchParent(root->left,x);
      else return treeSearchParent(root->right,x);
}


cNode* cRedBlackTree::rotateLeft(cNode* centerNode, cNode* parentNode )
{
    cNode* rightNode = centerNode->right;

    centerNode->right = rightNode->left;
    rightNode->left = centerNode;

    if( root == centerNode )
    {
        root = rightNode;
    }
    else
    {
        if( parentNode->left == centerNode ) parentNode->left = rightNode;
        else parentNode->right = rightNode;
    }

    return root;

}

cNode* cRedBlackTree::rotateRight(cNode* centerNode, cNode* parentNode )
{

    cNode* leftNode = centerNode->left;

    centerNode->left = leftNode->right;
    leftNode->right = centerNode;

    if( root == centerNode )
    {
        root = leftNode;
        cout<<"기준점이 루트노드"<<endl;
    }
    else
    {
        if( parentNode->left == centerNode ) parentNode->left = leftNode;
        else parentNode->right = leftNode;
    }

    return root;
}

void cRedBlackTree::treePrint()
{
    int step = 0;
    treePrint(root,step);
}


void cRedBlackTree::treePrint(cNode* t, int step)
{

    if( t == nil )
    {
        step--;
        return;
    }


    for(int i = 0 ; i < step ; i++ ) cout <<"    ";


    cout<< t->key << " : " << t->color <<endl;

    treePrint( t->left ,++step);
    step--;
    treePrint(t->right,++step);
    step--;
}
