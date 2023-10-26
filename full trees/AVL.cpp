#include <iostream>
using namespace std;

struct Node{
    int data;
    int height;
    Node *lchild;
    Node *rchild;
}*root = NULL;

int NodeHeight(Node *p){
    int hl,hr;
    // if(p && p->lchild){
    //     hl = p->lchild->height;
    // }else{
    //     hl = 0;
    // }
    // if(p && p->rchild){
    //     hr = p->rchild->height;
    // }else{
    //     hr =  0;
    // }

    hl = p && p->lchild ? p->lchild->height:0;
    hr = p && p->rchild ? p->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}

int BalanceFactor(Node *p){
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;

    return hl-hr;
}

Node *LLRotation(Node *p){
    Node *pl =  p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;
    
    return pl;

}
Node *LRRotation(Node *p){
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

        if(root==p){
            root = plr;
        }
         
    return plr;
}
Node *RRRotation(Node *p){

    Node *pl = p->rchild;
    Node *pll = pl->lchild;

    pl->lchild = p;
    p->rchild = pll; 

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root==p)
        root = pl;
    return pl;
}

Node *RLRotation(Node *p){
    Node *pl = p->rchild;
    Node *pll = pl->lchild;

    pl->lchild = pll->rchild;
    p->rchild = pll->lchild;

    pll->lchild = p;
    pll->rchild = pl;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    pll->height = NodeHeight(pll);

    if(root==p)
        root = pll;

    return pll;
}


Node *Rinsert(Node *p,int key){
    Node *t=NULL;

    if(p==NULL){
        t = new Node();
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data){
        p ->lchild = Rinsert(p->lchild,key);

    }else if(key > p->data){
        p->rchild = Rinsert(p->rchild,key);
    }else{
        return p;
    }

    p->height = NodeHeight(p);

    int balance = BalanceFactor(p);

    if(balance == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if(balance ==2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if(balance == -2 && BalanceFactor(p->rchild) == -1){
        return RRRotation(p);
    }else if(balance==-2 && BalanceFactor(p->rchild)==1){
        return RLRotation(p);
    }


    return p;
}

void *preOrder(Node *root ){
    if(root!=NULL){
        cout << root->data << " ";
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
    return 0;
}
int main(){
    root = Rinsert(root,30);
    Rinsert(root,50);
    Rinsert(root,40);
    preOrder(root);
    return 0;

}