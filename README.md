# Fillit_42school
The project assembles a given Tetriminos set altogether in the smallest possible square.

# Usage
There are two folders: srcs with all the c-files needed for the project and includes with the header file.

So, your steps:
1) Clone the repository

	git clone https://github.com/VladlenaSkubi-du/Fillit_42school.git [folder's name you want] 

2) Get into it and compile the project:

	cd [folder's name you want]
	make

3) Test with the test files from the folder (you can also create your ouw test files):

	./fillit 

**NOTE:** The program works only with one testing file

Go and try. Good luck!

# The function returns
The program displays the smallest assembled square on the standard output. To identify each Tetrimino in the square solution, there is a capital letter assigned to each Tetrimino, starting with ’A’ and increasing for each new Tetrimino. 
The file with Tetriminos should contain between 1 and 26 Tetriminos. The description of a Tetriminos must respect the following rules :
	-Precisely 4 lines of 4 characters, each followed by a new line (well... a 4x4 square)
	-A Tetrimino is a classic piece of Tetris composed of 4 blocks
	-Each character must be either a block character(’#’ ) or an empty character (’.’)
	-Each block of a Tetrimino must touch at least one other block on any of his 4 sides (up, down, left and right)

# Grade
# 125/100
