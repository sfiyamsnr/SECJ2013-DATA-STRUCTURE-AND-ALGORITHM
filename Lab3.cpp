// Lab 3 - SECJ2013 - 24251 (Lab3.cpp)
// Group Members:
// 1. ???
// 2. ???

#include <iostream>
#include <string>

using namespace std;

// Class section
class Node {
  public:
    int data;
    Node *next, *prev;

    Node(int n) {
        data = n;
        next = NULL;
        prev = NULL;
    }
};

// List class (linked list)
class List {
    private:
       Node *head;
       Node *last;

    public:
        List() { head = NULL; last = NULL; }

        ~List() {
            Node *n = head;

            while (n != NULL) {
                Node *temp = n;
                n = n->next;
                delete(temp);
            }
        }

        bool isEmpty() {  return head == NULL; }

        // please complete the insertNode function
        void insertNode(int val) {
            Node *newNode = new Node(val);
            
        }

        int findNode(int n) {
           Node *currNode = head;
           int post = 1;
           while (currNode != NULL) {
               if (n == currNode->data) return post;
               currNode = currNode->next;
               post++;
           }

           return 0;
        }

        // please complete the deleteNode function
        int deleteNode(int n) {
            
            return 0;
        }

        void displayList() {
            Node *n = head;
            cout << "displayList:\n";
            
            while (n != NULL) {
                cout << n->data << " ";
                n = n->next;
            }
            
            cout << "\n";
        }
        
        void displayListReverse() {
            Node *n = last;
            cout << "displayListReverse:\n";
            
            while (n != NULL) {
                cout << n->data << " ";
                n = n->prev;
            }
            
            cout << "\n";
        }
};


// Main function section
int main() {
   List linkedList;

   // do not change this insert values sequence
   linkedList.insertNode(0);
   linkedList.insertNode(9);
   linkedList.insertNode(1);
   linkedList.insertNode(6);
   linkedList.insertNode(5);

   linkedList.displayList();
   linkedList.displayListReverse();
   
   linkedList.deleteNode(5);
   linkedList.displayList();
   linkedList.displayListReverse();
   
   linkedList.deleteNode(0);
   linkedList.displayList();
   linkedList.displayListReverse();
   
   linkedList.deleteNode(9);
   linkedList.displayList();
   linkedList.displayListReverse();
   
   return 0;
}
