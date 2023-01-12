#include <iostream>
using namespace std;
/// @brief Making a such type of node so that we can work with it even in the queue and in  the tree.......

class Node{
    private:
        /// @brief this portion is for the queue
        Node *address;//address of the particular tree node will store here
        Node *nextNode;//This pointer is for the connection of nodes in the queue
        /// @brief this portion is for the tree
        int data;
        Node *Left;//left pointer for the left child
        Node *Right;//right pointer for the right child
    public:
        ////These are the function for the  queue 
        void setAddress(Node *p){
            address = p;
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
        Node *root;
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
        }
};


int main(){
    int size;
    int number;
    Tree s1;
    // s1.add(10); // root node
    // s1.add(15); // right child
    // s1.add(15);
    // s1.add(9);  // left childe
    // s1.add(9);  // left childe
    
    cout << "How much number do you want to enter =";
    cin >> size;
    for(int i=0; i<size; i++){
        cout << "Enter the number =";
        cin >> number;
        s1.add(number);
    }
    
    s1.display();
   
}
