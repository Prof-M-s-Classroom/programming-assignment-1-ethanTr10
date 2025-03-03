[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)
(Easier to read when looking pressing code button on GitHub)

Helper Methods:
void addWaypointEmptyRoute(T& data); O(1)
    Explanation: One input parameter for data type address and no return. Creates a Node pointer called newNode, sets 
        the head and tail to newNode, and increment size by one.
    Big O: This function is O(1) because it makes use of 4 constant time operations to create the first Waypoint in a 
        SpaceRoute.

void removeWaypointWhenOnlyOne(); O(1)
    Explanation: No input parameter, no return. Simply deletes the head to delete the one Waypoint, sets both head and 
        tail to nullptr, and resets size to be 0 again.
    Big O: This is O(1) because there are only four constant time operations. No need to traverse through a SpaceRoute 
        when deleting the one Waypoint node.


Public Methods:

Constructor:
SpaceRoute(): O(1)
    Explanation: Sets the head and tail pointers to nullptr and sets size to 0.
    Big O: There are just three constant time operations when creating a SpaceRoute, so it would be O(1).

Destructor:
~SpaceRoute() : O(n)
    Explanation: A node pointer called temp is first assigned to the head of the SpaceRoute. The while loop iterates 
        through the SpaceRoute from head to tail deleting each Waypoint node.
    Big O: Since the while loop iterates through the entire SpaceRoute from head to tail, that means the function is 
        dependent on the size of the SpaceRoute and making it O(n).


void addWaypointAtBeginning(T& data); O(1)
    Explanation: If the SpaceRoute is empty, call the helper method addWaypointEmptyRoute(). Otherwise, a newNode gets 
        created, the next pointer is assigned to the original head, the original head's previous pointer is assigned to newNode, the head then becomes newNode, and size increments by one. The method takes in an address of a data type and does not return anything.  
    Big O: This is O(1) because all the actions in the method are constant time operations and do not rely on a certain
        amount of n elements. 

void addWaypointAtEnd(T& data); O(1)
    Explanation : If the SpaceRoute is empty, then addWaypointEmptyRoute() is called, otherwise a newNode is created,
        the orignal tail's next pointer points to newNode, newNode's previous pointer points to original tail, then the tail is assigned to newNode, and size increments by one. The method takes in an address of a data type and does not return anything.  
    Big O: This is O(1) because all the operations are constant and do not rely on any n amount of nodes.

void addWaypointAtIndex(int index, T& data); O(n) 
    Explanation: First checks for invalid indices, calls helper addWaypointAtBeginning() if SpaceRoute is empty, calls 
        helper addWaypointAtEnd() if adding at the end, or executes the else section. The else section creates a newNode,
        uses getWaypoint() to find Waypoint node one index before the insertion point, adjust the next and previous 
        pointers, and increment size by one. The method takes in the index of where to add a new Waypoint node and the
        address of data type for the data value of the node with nothing returned.  
    Big O: This is O(n) because the getWaypoint() is used and may need to traverse all the way to the second to last 
        node of the SpaceRoute. All the other operations are constant, so it is O(n).

void removeWaypointAtBeginning(); O(1)
    Explanation: No input parameter and no return. First checks if SpaceRoute is already empty, calls helper method 
        removeWaypointWhenOnlyOne() when there is only one Waypoint in the SpaceRoute, or executes else section to 
        delete beginning Waypoint. The else section creates a node pointer to keep track of original head, adjusts head 
        pointer to the new head, deletes the original head, sets the new head's previous pointer to be null, and 
        decrements size by one.
    Big 0: O(1) because all the operations are constant time and does not need to traverse through the SpaceRoute.

void removeWaypointAtEnd(); O(1) 
    Explanation: No input parameter and no return. First checks if the SpaceRoute is empty, calls 
        removeWaypointWhenOnlyOne() if SpaceRoute only has one Waypoint, or executes the else section to delete last 
        Waypoint. The else section creates a Node pointer called temp that is assigned to tail, sets the next pointer of
        the node before original tail to nullptr, sets the tail to be the node before original tail, delete temp which 
        is the original tail, and decrement size by one.
    Big 0: This is O(1) because all the statements are constant time operations and function never needs to traverse 
        through the length of SpaceRoute.

void removeWaypointAtIndex(int index); O(n)
    Explanation: Has an input parameter for the index to remove Waypoint at that index but does not return anything.
        Checks if SpaceRoute is already empty, if there are invalid indices, if the index is 0 which would call 
        removeWaypointAtBeginning(), if index is the last node which would call removeWaypointAtEnd(), or execute the
        else section. In the else section, Node pointer leftOfTheOneToDelete points to the node one index before the one
        to be deleted, theOneToDelete points to the node to be deleted, rightOfTheOneToDelete points to the node right 
        of the one to be deleted, leftOfTheOneToDelete's next and rightOfTheOneToDelete's previous pointers get adjusted, 
        theOneToDelete gets deleted, and size is decremented. 
    Big O: This is O(n) because getWaypoint() may be called to access the third to last node in the worse case scenario. 
        Since all the other operations are otherwise constant and getWaypoint() is dependent on the size of the 
        SpaceRoute, big O is O(n).

void traverseForward(); O(n)
    Explanation: Starts from the beginning and goes to the last node, printing the data each time. No input parameter
        and no return.
    Big O: Since there is a for loop that is dependent on the size of the SpaceRoute and increments by one each 
        iteration, this is O(n).

void traverseBackward(); O(n)
    Explanation: Starts from the end and goes to the first node, printing the data each time. No input parameter and 
        no return.
    Big O: Since there is a for loop that is dependent on the size of the SpaceRoute and decrements by one each iteration,
        this is O(n).

Node<T>* getWaypoint(int index); O(n)
    Explanation: Returns a node pointer and takes in an int index parameter. Checks if SpaceRoute is empty and invalid
        indices, if index is 0 then retuns head, if index is the last return tail, or go to else section. The else
        section will create a node pointer called temp which will be returned after a for loop runs to traverse until 
        reaching the Waypoint at specified index.
    Big O: All the if and else-if statements are constant time operations. However, the else section uses a for loop 
        that may have traverse until the second to last node, making this function dependent on the size of SpaceRoute 
        and O(n).

void setWaypoint(int index, T& data); O(n)
    Explanation: Input parameters of index to modify and there is a data type address parameter used to modify the 
        node's data. Checks for invalid indices and if SpaceRoute is already empty, if index is 0 then the head node is
        set to new data, if index is the last one then the tail is set to new data, or the else section occurs. The else 
        section creates a new node pointer named temp which iterates from head until the node at the index of study is 
        found and then the new data is set.
    Big O: All the if and else-if statements are constant operations, but in the worst case the for loop traverses to the 
        second to last node which makes the function dependent on the size of SpaceRoute so O(n).

void print(); O(n)
    Explanation: No input parameters and no returns. Uses a while loop that iterates through from front to tail of 
        SpaceRoute and calling the Node's print method for each node  
    Big O : Traverses from the first to last node and prints the content, making run time dependent on size of 
        SpaceRoute so O(n).
