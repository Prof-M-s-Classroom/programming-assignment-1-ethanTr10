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


    voyagerRoute.addWaypointAtEnd(mars);
    voyagerRoute.print();


    voyagerRoute.addWaypointAtEnd(jupiter);
    voyagerRoute.print();

    voyagerRoute.addWaypointAtEnd(saturn);
    voyagerRoute.print();

    voyagerRoute.addWaypointAtBeginning(earth);
    voyagerRoute.print();

    voyagerRoute.addWaypointAtIndex(2, venus);
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