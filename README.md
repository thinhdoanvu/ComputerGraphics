### 1. GUIDE TO INSTALL Graphics.h on WINDOWS   
#### 1.1. [Download libraries files](https://github.com/thinhdoanvu/ComputerGraphics/tree/master/Coding/library)
#### 1.2. Install and Configurations

Copy:  
```
	6-ConsoleAppGraphics
	ConsoleApp_cpp_graph
```
Paste:  
```
	C:\Program Files\Dev-Cpp\Templates
```
Copy:  
```
	graphics
	winbgim
```
Paste:  
```
	C:\Program Files\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include
```	
Copy:  
```
	libbgi.a
```
Paste:  
```
	C:\Program Files\Dev-Cpp\MinGW64\x86_64-w64-mingw32\lib
```	
Open DevC - New Project - Console Graphics Application   
```
	C++ File
	Project name: Hello
	Save in some where
```
Tools - Compiler Option:   
```
  TDM-GCC 4.9.2 32bit Release
```
Code:
```
#include <graphics.h>

int main()
{
  initwindow(800,800);
  line(100,100,400,400);
  getch();
}
```
<iframe width="560" height="315" src="https://www.youtube.com/embed/noJqI1d_78E?si=x80n2MxiKreGJJtp" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

### 2. GUIDE TO INSTALL Graphics.h on MAC OS
#### 2.1. Make 2 folders: dosbox, tc
```
For example: 
	~/Programs/
  		|-dosbox
   		|-tc
```
#### 2.2. [Download DOSBOX ](https://sourceforge.net/projects/dosbox/files/dosbox/0.74-3/DOSBox-0.74-3-3.dmg/download)

#### 2..3. [Download TurboC](https://photogabble.co.uk/files/tc201.zip)

#### 2.4. Install TurboC on DosBox
Step 1. 
Once you have downloaded turbo C and unpacked the zip archive it came in you will be presented with three directories called Disk 1,2 and 3. For ease of installation you need to copy the files from these three directories into one directory which I shall call TC

Step 2.
Run DOSBox-0.74-3-3.dmg

Step 3. 
Run 2 these command on dosbox:
```
1. mount a: ~/Programs/tc
2. mount c: ~/Programs/dosbox
```
Step 4. Install
```
1. Run this command in order to move to A disk directly: 
	A:
2. Type: install
3. Press Enter to continue
4. Choose Install TurboC on Hardisk Drive
5. Keep defaults
6. Press Start install...
7. Finish
```
Step 5. Move to C folder
```
1. C:
2. cd TC
3. Run TC to OPEN Turbo C
```
Run code example
```
	#include <graphics.h>
	
 	#include <stdlib.h>
	
 	#include <stdio.h>
	
 	#include <conio.h>

	int main()
	{
   		int gd = DETECT, gm;
   		initgraph(&gd, &gm, "C:\\TC\\BGI");
		line(100, 100, 200, 200);
   		getch();
   		closegraph();
   		return 0;
	}
 ```
4. Compile and Run
```
Press F2 to Save CPP file   
Press F9 to compile   
and Ctrl+F9 to run EXE file   

ON MAC Press fn key to OPEN Function Keys
```
-------------------------------------------------------
Palette Number  Three Colors
-------------------------------------------------------
```
0 LIGHTGREEN LIGHTRED YELLOW
1 LIGHTCYAN LIGHTMAGENTA WHITE
2 GREEN  RED BROWN
3 CYAN MAGENTA LIGHTGRAY
```
-------------------------------------------------------
Name   Value
-------------------------------------------------------
```
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
```
-------------------------------------------------------
Line Style
-------------------------------------------------------
```
0: SOLID_LINE
1: DOTTED_LINE
2: CENTER_LINE
3: DASHED_LINE
4: USERBIT_LINE
Normal_Width: 1
Thick_Width: 3
```
