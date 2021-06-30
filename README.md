# wordSearch
Traverses any given 2D file of text and finds all words of length 6 or longer that appear vertically, horizontally, or diagonally and outputs the given word and the locations of its first and last letters.

The attached file 'words.txt' is a dictionary containing every single documented English word and the file 'puzzle.txt' contains a randomized 2D assortment of 62,500 characters. The program uses the fstream library to intake these files, putting the dictionary into an unordered set to maximize efficiency and the puzzle into a 2D array to maximize accessibility. The 2D array is looped through and crossreferenced with the dictionary to find and output all words and where within the puzzle they reside.
