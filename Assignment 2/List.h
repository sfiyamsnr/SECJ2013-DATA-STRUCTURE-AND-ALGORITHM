#include <iostream>
#include <string>

using namespace std;

// List class definition
class List {
    private:
        Student *head, *last;
        
    public:
        List() { 
            cout << "Create list...\n";
            head = NULL; last = NULL;
        }
        
        void insertNode(Student *newStud) {
          cout << "Insert " << newStud->getName() << "\n";
          if(!head||newStud->getName()<head->getName()){
            newStud->setNext(head);
            head=newStud;
          }
          else{
            Student *stud=head;
            while(stud->getNext()&&stud->getNext()->getName()<newStud->getName()){
                stud=stud->getNext();
            }
            newStud->setNext(stud->getNext());
            stud->setNext(newStud);
          }
          if(!newStud->getNext()){
            last-newStud;
          }
        }
        
        Student *findNode(string name) {
            Student *stud=head;
            while(stud){
                if(stud->getName()==name){
                    return stud;
                }
                stud=stud->getNext();
            }
            return NULL;
        }
        
        void deleteNode(string name) {
            Student *stud=head, *prev = NULL;
            while (stud&&stud->getName()!=name){
                prev = stud;
                stud = stud->getNext();
            }
            if(!stud){
                cout<<"Can't found student with name"<<name<<"\n";
                return;
            }

            if(!prev){
                head=stud->getNext();
            }else{
                prev->setNext(stud->getNext());
            }

            if(!stud->getNext()){
                last = prev;
            }

            delete stud;
        }
        
        void displayList() {
          Student *stud = head;
          
          while (stud != NULL) {
            stud->printResult();
            stud = stud->getNext();
        }
        }
        
        Student *getHead() { return head; }
        Student *getLast() { return last; }
        
        ~List() {
          Student *stud = head;
          cout << "Destroy list...\n";
          while (stud != NULL) {
            Student *prevStud = stud;
            stud = stud->getNext();
            cout<<"Destroy student object - "<<prevStud->getName()<<"\n";
      }
    }
};