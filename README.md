# ComputerGraphics
## Download necessary files
##### Link here: https://github.com/thinhdoanvu/ComputerGraphics/tree/master/Coding/library
## Setup
##### Step 1.
###### Copy:
	6-ConsoleAppGraphics
	ConsoleApp_cpp_graph
###### Paste:
	C:\Program Files\Dev-Cpp\Templates

##### Step 2.
###### Copy:
	graphics
	winbgim
###### Paste:
	C:\Program Files\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include
  
##### Step 3.
###### Copy:
	libbgi.a
###### Paste:
	C:\Program Files\Dev-Cpp\MinGW64\x86_64-w64-mingw32\lib
  
## Coding setup
###### Open DevC - New Project - Console Graphics Application
	C++ File
	Project name: Hello
	Save in some where

###### Tools - Compiler Option:
	 TDM-GCC 4.9.2 32bit Release
   
## Code:
###### Example code:
	#include <graphics.h>
	
	int main()
	{
  		initwindow(800,800);
		setcolor(2);
		setlinestyle(1,0,3);
  		line(100,100,400,400);
  		getch();
	}


## Note
Palette Number  Three Colors
0 LIGHTGREEN LIGHTRED YELLOW
1 LIGHTCYAN LIGHTMAGENTA WHITE
2 GREEN  REDBROWN
3 CYAN MAGENTA LIGHTGRAY

Name   Value
BLACK  0
BLUE   1
GREEN  2
CYAN   3
RED    4
MAGENTA5
BROWN  6
LIGHTGRAY    7
DARKGRAY     8
LIGHTBLUE    9
LIGHTGREEN   10
LIGHTCYAN    11
LIGHTRED     12
LIGHTMAGENTA 13
YELLOW 14
WHITE  15

Line Style
0: SOLID_LINE
1: DOTTED_LINE
2: CENTER_LINE
3: DASHED_LINE
4: USERBIT_LINE

Normal_Width: 1
Thick_Width: 3
