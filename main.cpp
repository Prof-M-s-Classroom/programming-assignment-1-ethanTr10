#include <iostream>
#include <string>
#include "SpaceRoute.cpp"

using namespace std;

int main() {
    string mars = "Mars";
    string jupiter = "Jupiter";
    string saturn = "Saturn";
    string earth = "Earth";
    string venus = "Venus";

    SpaceRoute<string> voyagerRoute;

    cout<< "Starting Off, our SpaceRoute contains: " <<endl;
    voyagerRoute.print();
    cout<< ". " <<endl;


    voyagerRoute.addWaypointAtEnd(mars); //GOOD
    voyagerRoute.print();


    voyagerRoute.addWaypointAtEnd(jupiter); //GOOD
    voyagerRoute.print();

    voyagerRoute.addWaypointAtEnd(saturn); //GOOD
    voyagerRoute.print();

    voyagerRoute.addWaypointAtBeginning(earth); //GOOD
    voyagerRoute.print();

    voyagerRoute.addWaypointAtIndex(2, venus); //GOOD
    voyagerRoute.print();

    cout << " " <<endl;
    cout << "trying the traversal methods"<< endl;
    cout << " " <<endl;

    voyagerRoute.traverseForward();

    cout << " " <<endl;

    voyagerRoute.traverseBackward();
    cout << " " <<endl;
    cout<< "end of trying the traversal methods"<<endl;
    cout << " " <<endl;

    voyagerRoute.removeWaypointAtBeginning(); //GOOD
    voyagerRoute.print();

    voyagerRoute.removeWaypointAtEnd(); //GOOD
    voyagerRoute.print();

    voyagerRoute.removeWaypointAtIndex(1); //GOOD
    voyagerRoute.print();

    voyagerRoute.setWaypoint(1, saturn);
    voyagerRoute.print();
    //
    // cout << "Voyager Route (Forward):\n";
    // voyagerRoute.traverseForward();
    //
    // cout << "\nVoyager Route (Backward):\n";
    // voyagerRoute.traverseBackward();
    //
    // cout << "\nPrinting Route: \n";
    // voyagerRoute.print();
    //
    // voyagerRoute.removeWaypointAtIndex(2);
    // cout << "\nAfter Removing Venus: \n";
    //voyagerRoute.print();

    return 0;
}