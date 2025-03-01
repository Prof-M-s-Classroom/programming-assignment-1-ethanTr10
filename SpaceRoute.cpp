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

    void addWaypointAtBeginning(T& data) { //waypoint is a node good i think
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

    void addWaypointAtEnd(T& data) { //good
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
            Node<T>* temp=get(index-1);
            newNode->next=temp-> next;
            temp->next->prev=newNode; //setting the node right of newNode's previous node to newNode
            temp->next = newNode;
            newNode->prev=temp;
            size++;
        }
    }

     void removeWaypointAtBeginning() {
        if (head == nullptr && tail == nullptr) {
            cout << "The SpaceRoute is already empty " <<endl;
        }
        Node<T>* temp = head;
        head= head->next;
        delete temp;
        size--;
    }
     void removeWaypointAtEnd() {
        Node<T>* temp = head;
        while(temp->next->next != nullptr) {
            temp=temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        size--;
    }

    // void removeWaypointAtIndex(int index);
    // void traverseForward();
    // void traverseBackward();
     Node<T>* getWaypoint(int index) {

    }
    // void setWaypoint(int index, T& data);
    void print(){

            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }

};

