Simulation games remain a popular genre of video games and you have decided to capitalize on their
success by designing SimBacteria. Given an area randomly populated by single cell organisms, players will be able
to watch their cultures thrive (or die) throughout many generations of bacteria. Your program will drive the
simulation and display each generation before recording the last generation into a file.

Pseudocode: Your pseudocode should describe the following items
• Main.cpp
o List functions you plan to create
▪ Determine the parameters
▪ Determine the return type
▪ Detail the step-by-step logic that the function will perform
o Detail the step-by-step logic of the main function

SimBacteria Rules
• Each cell has at most 8 neighbors (cells on the edge of the world will have fewer):

 1   2   3
 4  Cell 5
 6   7   8

• If a cell contains an organism and has fewer than 2 neighbors, the organism dies of loneliness.
o A neighbor is an organism in one of the 8 spots (or fewer if on the edge) around a cell
• If a cell contains an organism and has more than 3 neighbors, it dies from overcrowding.
• If an empty location has exactly three neighbors, an organism is born in that location.
• All births and deaths happen simultaneously.
o No changes should be made to the world until all cells have been tested.

Details
• The world in which the bacteria live will be implemented as a 2 dimensional array.
• The array will be dynamic 
o The size of the array will be determined by the file containing the initial bacteria generation.
o You may create a dynamic multi- or single dimension array
▪ Dynamic multi-dimensional arrays require double pointers (which we will not cover)
▪ This is an option for students with a more advanced skill set.
o Remember that standard multi-dimensional arrays in C++ are stored as single dimension arrays in
memory
▪ This may be easier to work with than the double pointers.

• The initial bacteria generation will be read from a file.
• The use of pointers is required to traverse the array.
• You must use pointer arithmetic to move the pointers.
o Offset notation (-10 points if used) nor bracket notation are allowed for
accessing the array

• The final bacteria generation will be written to a file.
Input: The initial bacteria generation will be read from a file named simbac.txt. Each line in the file will
represent a row in the 2D array. The array you create is to be no bigger than the initial bacteria generation
presented in the file. You will need to determine how many rows and columns are in the file before creating the
array.
Each row will contain two types of characters - asterisks (*) or a space. An asterisk represents an organism and
the space represents an empty cell. Each line of the file will end with a newline character, except the last line.
The last line may or may not have a newline character at the end
Once the file has been read into memory, prompt the user to enter the number of generations to simulate. The
maximum number of generations allowed for simulation is 10. You must validate that the user only enters an
integer from 1 – 10. If the user enters invalid data, display an error message and prompt the user for correct
input.

Output: After the user has entered a valid number, display each generation to the console. The last generation
will be displayed to the console as well as written to the file (simbac.txt). Use an asterisk (*) to indicate an
organism during output.
Hints:
• You should consider a second 2-dimensional array to mark births and deaths
o This allows you to evaluate births and deaths simultaneously by modifying a copy of the world
rather than the original

• There are 3 rows of neighbors for cells. It may be easier to check neighbors by using a pointer for each
row of neighbors
o Remember the border cases have fewer neighbors
