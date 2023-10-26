#include <iostream>
#include <algorithm>
using namespace std;
/// @brief Making a such type of node so that we can work with it even in the queue and in  the tree.......


class Node{
    private:
        /// @brief this portion is for the queue
        Node *address;//address of the particular tree node will store here
        Node *nextNode;//This pointer is for the connection of nodes in the queue
        /// @brief this portion is for the tree
        int height;
        int data;
        Node *Left;//left pointer for the left child
        Node *Right;//right pointer for the right child
    public:
        ////These are the function for the  queue 
        void setAddress(Node *p){
            address = p;
        }
        void setHeight(int height){
            this->height = height;
        }
        int getHeight(){
            return height;
        }
        Node *getAddress(){
            return address;
        }
        void setNext(Node *p){
            nextNode = p;
        }
        Node *getNext(){
            return nextNode;
        }
        //These functions are for  making the tree
        void setdata(int data){
            this->data = data;
        }
        int getdata(){
            return data;
        }
        void setLeft(Node *p){
            Left = p;
        }
        void setRight(Node *p){
            Right = p;
        }
        Node *getLeft(){
            return Left;
        }
        Node *getRight(){
            return Right;
        }
};

Node *root;

class Queue{
    private:
        int size;
        Node*front;
        Node*rear;
    public:
        Queue(){
            size = 0;
            front = NULL;
            rear = NULL;
        }
        void enqueue(Node *obj){
            Node*newNode = new Node();
            newNode->setAddress(obj);
            if(isEmpty()){
                newNode->setNext(NULL);
                rear = newNode;
                front = rear;
            }else{
                rear->setNext(newNode);
                newNode->setNext(NULL);
                rear = newNode;
            }

        }
        void dequeue(){
            Node* temp;
            temp = front;
            if(isEmpty()){
                cout << "Queue is already empty"<<endl;
            }else{
                front = front->getNext();
                delete temp;
            }
        }
        Node *frontNode(){
            return front->getAddress();
        }
        int isEmpty(){
            return front==NULL;
        }
};

class Tree{
    private:
        Node *current;
        Queue q;
        int size;
    public:
        Tree(){
            root = current = NULL;
            size = 0;
            
        }
        //Adding data after filtering (means checking number if it is smaller or greater)
        void add(int data){
            Node *newNode = new Node();
            newNode->setdata(data);
            newNode->setHeight(1);
            if(current == NULL){

                newNode->setLeft(NULL);
                newNode->setRight(NULL);
                current = newNode;
                root = current;

            }else{

                while(current){

                    if(newNode->getdata() < current->getdata()){
                        if(current->getLeft() == NULL){
                            current->setLeft(newNode);
                            break;
                        }else{

                            current = current->getLeft();
                        }
                    }else if(newNode->getdata() > current->getdata()){
                        if(current->getRight() == NULL){
                            current->setRight(newNode);
                            break;
                        }else{
                            current = current->getRight();

                        }

                    }else{
                        cout << "Dublicate =" <<newNode->getdata()<<endl;
                        delete newNode;
                        break;
                    }
                }

                current = root;
            }
        }
        //Function to find the height of the tree
        Node *BTHeight(Node * root){
            int leftHeight =0;
            int rightHeight =0;

            if(root == NULL){
                return 0;
            }else{
                BTHeight(root->getLeft());
                leftHeight = root->getHeight();
                BTHeight(root->getRight());
                rightHeight = root->getHeight();
            }
            int ht = max(leftHeight,rightHeight);
            root->setHeight(ht+1);
            cout <<"Height ="<< root->getHeight();
            return root;

        }

        //Function for the preOrder traversel....
        void preOrder(Node *pointer){

            cout << pointer->getdata() << " ";
            if(pointer->getLeft() != NULL){
                preOrder(pointer->getLeft());
            }
            if(pointer->getRight() != NULL){
                preOrder(pointer->getRight());
            }
        }

        //Fumction for the inOrder traversal...
        void inOrder(Node *pointer){

            if(pointer->getLeft() != NULL){
                inOrder(pointer->getLeft());
            }

            cout << pointer->getdata() << " ";

            if(pointer->getRight() != NULL){
                inOrder(pointer->getRight());
            }
        }

        //Function for the postOrder traversal..
        void postOrder(Node *pointer){

            if(pointer->getLeft() != NULL){
                postOrder(pointer->getLeft());
            }
            if(pointer->getRight() != NULL){
                postOrder(pointer->getRight());
            }
            cout << pointer->getdata() << " ";

        }

        //Function for the levelOrder traversal..
        void levelOrder(Node *root){
                q.enqueue(root);
                while(!q.isEmpty()){
                    root = q.frontNode();
                    cout << root->getdata() << " ";
                    q.dequeue();
                    if(root->getLeft()!=NULL){
                        q.enqueue(root->getLeft());
                    }
                    if(root->getRight()!=NULL){
                        q.enqueue(root->getRight());
                    }
                    
                    
                }
        }
        //Function for to searh an element

        bool search(int key){
            current = root;
            int flag = 0;
            while (current != NULL){
                if(current->getdata() == key){
                    flag = 1;
                    break;
                }else if(current->getdata() > key){
                    current = current->getLeft();
                }else if(current->getdata() < key){
                    current = current->getRight();
                }
            }
            if(flag == 1){
                cout << "The number is found"<<endl;
                return true;
            }else{

                cout << "The number is not found"<<endl;
                return false;
            }              
        }

        //Function to find minimum
        Node * findMin(Node *root){
            if(root->getLeft() == NULL){
                return root;
            }
            return findMin(root->getLeft());
        }

        //..Function to delete a node from the tree
        Node * del(Node *root,int key){

            Node * t;
            if(key < root->getdata()){
                t = del(root->getLeft(),key);
                root->setLeft(t);

            }else if(key > root->getdata()){
                t = del(root->getRight(),key);
                root->setRight(t);

            }else if(root->getRight() != NULL && root->getLeft()!=NULL){
                Node *minNode;
                minNode = findMin(root->getRight());
                root->setdata(minNode->getdata());
                t = del(root->getRight(),minNode->getdata());
                root->setRight(t);

            }

            if(root->getdata() == key){

                Node* nodeToDelete = root;
                if(root->getLeft() == NULL){
                    root = root->getRight();
                }else if(root->getRight() == NULL){
                    root = root->getLeft();
                }else{
                    root = NULL;
                }
                delete nodeToDelete;
            }
            return root;
                       
        }

        //Function to display the result..
        void display(){
            cout << "Preorder =";
            preOrder(root);
            cout << endl;
            cout << "inOrder =";            
            inOrder(root);
            cout << endl;
            cout << "postOrder =";
            postOrder(root);
            cout << endl;
            cout << "LevelOrder =";
            levelOrder(root);
            cout << endl;
            cout << endl;
            BTHeight(root);
        }
};


int main(){
    int size;
    int number;
    Tree s1;
    s1.add(30); // root node
    s1.add(20); // right child
    s1.add(10);
    // s1.add(40);
    // s1.add(50);
    // s1.add(9);  // left childe
    // s1.add(9);  // left childe
    
    // cout << "How many numbers do you want to enter =";
    // cin >> size;
    // for(int i=0; i<size; i++){
    //     cout << "Enter the number =";
    //     cin >> number;
    //     s1.add(number);
    // }

    // // cout << "Which number do want to search =";
    // // cin >> number;
    // // s1.search(number);
    // int x=0;
    //     do{
    //         cout << "Do you want to delete the node 1/0 =";
    //         cin >> x;
    //         if(x==1){
    //             cout << "Which number do you want to delete =";
    //             cin >> number;
    //             if(s1.search(number) == true){
    //                 s1.del(root,number);
    //             }
    //             s1.display();
    //         }

    //     }while(x==1);
        s1.display();


    // s1.search(90);
   
}