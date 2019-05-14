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
  		line(100,100,400,400);
  		getch();
	}

 
