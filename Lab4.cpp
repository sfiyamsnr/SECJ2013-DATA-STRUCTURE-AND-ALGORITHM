// Lab 4 - SECJ2013 - 24251 (Lab4.cpp)
// Group Members:
// 1. Dayang Farah Farzana binti Abang Idham (A23CS0071)
// 2. Farra Nurzahin binti Zaharil Anuar (A23CS0079)
// 3. Safiya Nursyahadah binti Masnoor (A23CS0176)

#include <iostream>
#include <string>

using namespace std;

const int size = 5;

// Node class to implement circular linked-list type queue
class Node {
    private:
        char item;
        Node *next;

    public:
        Node(char c) { 
            item = c; 
            next = NULL;
        }

        void setNext(Node *n) { next = n; }
        Node *getNext() { return next; }
        char getItem() { return item; }

        ~Node() { cout << "Delete node-item " << item << "\n"; }
};

// Queue class header (array)
class Queue {
private:
    Node* front;
    Node* rear;

public:
    void createQueue();
    void destroyQueue();
    void enQueue(char);
    char deQueue();
    bool isEmpty();
    char getFront();
    char getRear();
};

// Queue class implementation (array)
void Queue::createQueue() {
    front = NULL;
    rear = NULL;
}

void Queue::destroyQueue(){
    while (!isEmpty()){
        deQueue();
    }
}

void Queue::enQueue(char c) {
    cout << "Try to enqueue item " << c << " into the queue\n";
    Node* newNode = new Node(c);
    
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
        newNode->setNext(newNode);
    } else {
        newNode->setNext(front);
        rear->setNext(newNode);
        rear=newNode;
    }
}

char Queue::deQueue() {
    if (!isEmpty()) {
        Node* temp = front;
        char c = temp->getItem();
        
        if(front==rear){
            front =NULL;
            rear=NULL;
        }
        else{
            front=front->getNext();
            rear->setNext(front);
        }

        // rightward drifting
        delete temp;
        return c;
    } else {
        cout << "Can't dequeue item, queue is empty!\n";
        return ' ';
    }
}

bool Queue::isEmpty() {
    return front == NULL;
}

char Queue::getFront() {
    if (!isEmpty()) {
        return front->getItem();
    } else {
        cout << "Can't get front item, queue is empty!\n";
        return ' ';
    }
}

char Queue::getRear() {
    if (!isEmpty()) {
        return rear->getItem();
    } else {
        cout << "Can't get rear item, queue is empty!\n";
        return ' ';
    }
}

// Main function section
int main() {
    Queue myQueue;

    myQueue.createQueue();

    myQueue.enQueue('A');
    myQueue.enQueue('B');
    myQueue.enQueue('C');
    myQueue.enQueue('D');
    myQueue.enQueue('E');
    myQueue.enQueue('F');
    myQueue.enQueue('G');

    cout << "\n";
    cout << "Front item: " << myQueue.getFront() << "\n";
    cout << "Rear item: " << myQueue.getRear() << "\n";
    
    cout << "\n";
    while (!myQueue.isEmpty()) {
        char delItem = myQueue.deQueue();
        cout <<  "dequeue item " << delItem << " from the queue\n";
    }

    myQueue.deQueue();

    cout << "\n";
    myQueue.enQueue('F');
    myQueue.enQueue('G');

    cout << "\n";
    cout << "Front item: " << myQueue.getFront() << "\n";
    cout << "Rear item: " << myQueue.getRear() << "\n";

    cout << "\n";
    while (!myQueue.isEmpty()) {
        char delItem = myQueue.deQueue();
        cout <<  "dequeue item " << delItem << " from the queue\n";
    }

    myQueue.deQueue();

    myQueue.destroyQueue();
    system("pause");

    return 0;
}