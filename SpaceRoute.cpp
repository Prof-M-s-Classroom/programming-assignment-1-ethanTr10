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

public:
    SpaceRoute() : head(nullptr), tail(nullptr), size(0) {}  // Constructor
    //~SpaceRoute(); // Destructor

    void addWaypointEmptyRoute(T& data) { //good drawing
        Node<T>* newNode= new Node<T>(data);
        head = newNode;
        tail = newNode;
        size++;
    }

    Node<T>* get(int index) {
        if (index<0 || index>=size) {
            return nullptr;
        }
        Node<T>* temp =head;
        for (int i=0; i<index; i++) {
            temp=temp->next;
        }
        return temp;
    }

    void addWaypointAtBeginning(T& data) { //waypoint is a node good in drawing
        if (head == nullptr && tail == nullptr) {
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

    void addWaypointAtEnd(T& data) { //good in drawing
        if (head == nullptr && tail == nullptr) { //if the SpaceRoute is empty
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
            return;
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

    void removeWaypointWhenOnlyOne() {
        delete head;
        head=nullptr;
        tail=nullptr;
        size--;
    }

     void removeWaypointAtBeginning() { //good in drawing
        if (head == nullptr && tail == nullptr) {
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
     void removeWaypointAtEnd() { //good in drawing
        if (head == nullptr && tail == nullptr) {
            cout << "The SpaceRoute is already empty, so cannot delete " <<endl;
        }
        else if (size==1) {
            removeWaypointWhenOnlyOne();
        }
        else {
            Node<T>* temp = head;
            while(temp->next->next != nullptr) {
                temp=temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
            tail=temp;
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
            Node<T>* temp = getWaypoint(index-1);
            Node<T>* theOneToDelete= temp->next;
            Node<T>* theOneNextToOneToDelete=theOneToDelete->next;
            temp->next=theOneToDelete->next;
            theOneNextToOneToDelete->prev=temp;
            delete theOneToDelete;
            size--;
        }
    }
    void traverseForward() { //GOOD
        for (int i=0; i<size; i++) {
            cout<<getWaypoint(i)->data<< " ";
        }
    }
    void traverseBackward() { //GOOD
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
            cout << "The SpaceRoute is empty, cannot set any Waypoint" <<endl;
        }

        else if (index<0 || index>=size) {
            cout << "The index does not exist" << endl;
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

