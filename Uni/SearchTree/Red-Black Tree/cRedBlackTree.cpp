#include "cRedBlackTree.h"
#include <iostream>
using namespace std;
 
int main(){
    
    char cmd;
    int n, x;
    cRedBlackTree rbt;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>cmd>>x;
        switch(cmd){
        case 'I':
            rbt.treeInsert(x);
            break;
        case 'D':
            rbt.treeDelete(x);
            break;  
        }
    }
    /*
    
    cRedBlackTree rbt;
    
    rbt.test();
    */

    
    rbt.treePrint();
   
   system("pause"); 
    return 0;
}
