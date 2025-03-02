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

    voyagerRoute.addWaypointAtEnd(mars);
    voyagerRoute.addWaypointAtEnd(jupiter);
    voyagerRoute.addWaypointAtEnd(saturn);
    voyagerRoute.addWaypointAtBeginning(earth);
    voyagerRoute.addWaypointAtIndex(2, venus);

    cout << "Voyager Route (Forward):\n";
    voyagerRoute.traverseForward();

    cout << "\nVoyager Route (Backward):\n";
    voyagerRoute.traverseBackward();

    cout << "\nPrinting Route: \n";
    voyagerRoute.print();

    voyagerRoute.removeWaypointAtIndex(2);
    cout << "\nAfter Removing Venus: \n";
    voyagerRoute.print();

    cout<< "Removing All: " <<endl;

    voyagerRoute.removeWaypointAtBeginning();
    voyagerRoute.removeWaypointAtBeginning();
    voyagerRoute.removeWaypointAtBeginning();
    voyagerRoute.removeWaypointAtBeginning();

    cout<< "HUH" << endl;
    voyagerRoute.removeWaypointAtBeginning();
    cout<< "HUH" << endl;
    voyagerRoute.removeWaypointAtEnd();
    voyagerRoute.removeWaypointAtIndex(8);
    voyagerRoute.removeWaypointAtIndex(-1);
    voyagerRoute.getWaypoint(0);
    voyagerRoute.getWaypoint(-1);
    voyagerRoute.setWaypoint(0, earth);

    voyagerRoute.addWaypointAtIndex(0, venus);
    voyagerRoute.addWaypointAtIndex(-1, jupiter);
    cout<< "Starting from the top: \n"<<endl;
    voyagerRoute.print();

    cout<<"The get method returns "<<voyagerRoute.getWaypoint(0)->data<< endl;

    voyagerRoute.addWaypointAtBeginning(earth);
    voyagerRoute.addWaypointAtEnd(jupiter);
    voyagerRoute.addWaypointAtIndex(3,mars);
    voyagerRoute.addWaypointAtIndex(1,saturn);
    voyagerRoute.print();
    voyagerRoute.removeWaypointAtIndex(2);
    voyagerRoute.print();


    //voyagerRoute.removeWaypointAtIndex(0);
    //cout<< "Starting from the top: \n"<<endl;
    //voyagerRoute.print();
    //cout << "DONE "<< endl;

    // cout<< "Starting Off, our SpaceRoute contains: " <<endl;
    // voyagerRoute.print();
    // cout<< ". " <<endl;
    //
    // voyagerRoute.addWaypointAtEnd(mars); //GOOD
    // voyagerRoute.print();
    //
    //
    // voyagerRoute.addWaypointAtEnd(jupiter); //GOOD
    // voyagerRoute.print();
    //
    // voyagerRoute.addWaypointAtEnd(saturn); //GOOD
    // voyagerRoute.print();
    //
    // voyagerRoute.addWaypointAtBeginning(earth); //GOOD
    // voyagerRoute.print();
    //
    // voyagerRoute.addWaypointAtIndex(2, venus); //GOOD
    // voyagerRoute.print();
    //
    // cout << " " <<endl;
    // cout << "trying the traversal methods"<< endl;
    // cout << " " <<endl;
    //
    // voyagerRoute.traverseForward();
    //
    // cout << " " <<endl;
    //
    // voyagerRoute.traverseBackward();
    // cout << " " <<endl;
    // cout<< "end of trying the traversal methods"<<endl;
    // cout << " " <<endl;
    //
    // voyagerRoute.removeWaypointAtBeginning(); //GOOD
    // voyagerRoute.print();
    //
    // voyagerRoute.removeWaypointAtEnd(); //GOOD
    // voyagerRoute.print();
    //
    // voyagerRoute.removeWaypointAtIndex(1); //GOOD
    // voyagerRoute.print();
    //
    // voyagerRoute.setWaypoint(1, saturn);
    // voyagerRoute.print();
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