# Pointers and Dynamic Arrays
This dungeon program creates a canvas of a user-defined size using dynamic 2D arrays and displays a draw board on it using a 2D vector. Additionally, it randomly generates the positions of two triggers and two objects, a hero and a creature, on the canvas, ensuring that their positions are unique.

## Function implementation

### Canvas Creation
The program checks if the dimensions provided by the user are valid (i.e., both length and width must be greater than 3).

If the input is invalid, the program displays a warning message and prompts the user to enter valid dimensions.

Once the user enters valid dimensions, the program creates the canvas correctly and proceeds to the next step of the program.

### Use 2D Vector to Build DrawBoard
This program uses a 2D vector to build a draw board to display the canvas and elements. 

Here are the steps taken to achieve this:
1. Allocate and initialize the game board using a 2D dynamic array in the `setupBoard(int rowN, int colN)` function.
2. Setup and implement a drawing board using 2d vector in the `void draw()` function.
    
### Managing Triggers with Pointer Vector
This program utilizes a vector of trigger pointers for managing and manipulating triggers. 

The following steps are taken in the implementation:
1. The vector of trigger pointers is created in order to further manage and manipulate the triggers.
2. The two triggers are initialized and pushed to the container.
3. The triggers are drawn on the draw board using a for loop.
4. The triggers are updated using a while loop.
    
### Random Object Positioning
This program randomly positions the hero, creature, and two triggers within the canvas, ensuring that their positions do not repeat. 