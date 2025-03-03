/**
 * Programming Assignment 1
 * Implementing methods within the SpaceRoute class
 * CS210-03
 * March 2, 2025
 * @author Ethan Truong
 */
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T& data;
    Node* next;
    Node* prev;

    Node(T& d) : data(d), next(nullptr), prev(nullptr) {}
    void print() { cout << data << " "; }
};

class CelestialNode {
private:
    string name;
    double distance_from_earth;
    string mission_log;

public:
    CelestialNode(const string& n, double d, const string& log);
    const string& getName() const;
    double getDistance() const;
    const string& getMissionLog() const;
    void print() const { cout << name << " (" << distance_from_earth << " AU) - " << mission_log << endl; }
};

template <typename T>
class SpaceRoute {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

    void addWaypointEmptyRoute(T& data) {
        Node<T>* newNode= new Node<T>(data);
        head = newNode;
        tail = newNode;
        size++;
    }

    void removeWaypointWhenOnlyOne() {
        delete head;
        head=nullptr;
        tail=nullptr;
        size=0;
    }

public:
    SpaceRoute() : head(nullptr), tail(nullptr), size(0) {}  // Constructor

    ~SpaceRoute() { //Destructor
        Node<T>* temp= this->head;
        while (head) {
            head = head->next;
            delete temp;
            temp=head;
        }
    }

    void addWaypointAtBeginning(T& data) {
        if (size==0) {
            addWaypointEmptyRoute(data);
        }
        else {
            Node<T>* newNode = new Node<T>(data);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            size++;
        }
    }

    void addWaypointAtEnd(T& data) {
        if (size==0) {
            addWaypointEmptyRoute(data);
        } else {
            Node<T> *newNode = new Node<T>(data);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            size++;
        }
    }

    void addWaypointAtIndex(int index, T& data) {
        if (index<0 || index>size) {
            cout<< "Index is invalid" <<endl;
        }
        else if (index==0) {
            addWaypointAtBeginning(data);
        }
        else if (index==size) {
            addWaypointAtEnd(data);
        }
        else {
            Node<T>* newNode = new Node<T>(data);
            Node<T>* temp=getWaypoint(index-1);
            newNode->next=temp-> next;
            temp->next->prev=newNode; //setting the node right of newNode's previous node to newNode
            temp->next = newNode;
            newNode->prev=temp;
            size++;
        }
    }

     void removeWaypointAtBeginning() {
        if (size==0) {
            cout << "The SpaceRoute is already empty, so cannot delete " <<endl;
        }
        else if (size==1) {
            removeWaypointWhenOnlyOne();
        }
        else {
            Node<T>* temp = head;
            head= head->next;
            delete temp;
            head->prev=nullptr;
            size--;
        }
    }

     void removeWaypointAtEnd() {
        if (size==0) {
            cout << "The SpaceRoute is already empty, so cannot delete " <<endl;
        }
        else if (size==1) {
            removeWaypointWhenOnlyOne();
        }
        else {
            Node<T>* temp = tail;
            temp->prev->next = nullptr;//setting the next pointer of the node before original tail to nullptr
            tail = temp->prev;
            delete temp;
            size--;
        }
    }

     void removeWaypointAtIndex(int index) {
        if (size==0) {
            cout << "The SpaceRoute is empty, cannot delete anything " <<endl;
        }
        else if (index<0 || index>=size) {
            cout << "The index does not exist" << endl;
        }
        else if (index==0) {
            removeWaypointAtBeginning();
        }
        else if (index==size-1) {
            removeWaypointAtEnd();
        }
        else {
            Node<T>* leftOfTheOneToDelete = getWaypoint(index-1);
            Node<T>* theOneToDelete= leftOfTheOneToDelete->next;
            Node<T>* rightOfTheOneToDelete=theOneToDelete->next;
            leftOfTheOneToDelete->next=theOneToDelete->next;
            rightOfTheOneToDelete->prev=leftOfTheOneToDelete;
            delete theOneToDelete;
            size--;
        }
    }

    void traverseForward() {
        for (int i=0; i<size; i++) {
            cout<<getWaypoint(i)->data<< " ";
        }
    }

    void traverseBackward() {
        for (int i=size-1; i>=0; i--) {
            cout<<getWaypoint(i)->data<< " ";
        }
    }

    Node<T>* getWaypoint(int index) {
        if (size==0) {
            cout << "The SpaceRoute is empty, cannot retrieve anything " <<endl;
            return nullptr;
        }
        else if (index<0 || index>=size) {
            cout << "The index does not exist" << endl;
            return nullptr;
        }
        else if (index==0) {
            return head;
        }
        else if (index==size-1) {
            return tail;
        }
        else {
            Node<T>* temp =head;
            for (int i=0; i<index; i++) {
                temp=temp->next;
            }
            return temp;
        }
    }

    void setWaypoint(int index, T& data) {
        if (size==0) {
            cout << "The SpaceRoute is empty, cannot set any Waypoint to " <<data <<endl;
        }
        else if (index<0 || index>=size) {
            cout << "The index does not exist" << endl;
        }
        else if (index==0) {
            head->data = data;
        }
        else if (index==size-1) {
            tail->data = data;
        }
        else {
            Node<T>* temp =head;
            for (int i=0; i<index; i++) {
                temp=temp->next;
            }
            temp->data = data;
        }
    }

    void print(){
        Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }
};

