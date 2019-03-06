How to use graph in Linux - Using SDL

1. First add the Universe repository (since some required packages are not available in main repository):

	sudo add-apt-repository universe
	sudo apt-get update

'universe' distribution component is already enabled for all sources. So, this step can be skip

2. Second install build-essential and some additional packages:
	From Ubuntu 18.04 guile-2.0 works and libesd0-dev is deprecated. For this you need to add repositories of xenial in sources.list.

	sudo nano /etc/apt/sources.list

	Add these lines: 
		deb http://us.archive.ubuntu.com/ubuntu/ xenial main universe
		deb-src http://us.archive.ubuntu.com/ubuntu/ xenial main universe

	Run sudo apt-get update. 
	Then install packages using:
		sudo apt-get install libsdl-image1.2 libsdl-image1.2-dev guile-2.0 \
guile-2.0-dev libsdl1.2debian libart-2.0-dev libaudiofile-dev \
libesd0-dev libdirectfb-dev libdirectfb-extra libfreetype6-dev \
libxext-dev x11proto-xext-dev libfreetype6 libaa1 libaa1-dev \
libslang2-dev libasound2 libasound2-dev

3. Download libgraph-1.0.2.tar.gz
	wget http://download.savannah.gnu.org/releases/libgraph/libgraph-1.0.2.tar.gz


4. Now extract the downloaded libgraph-1.0.2.tar.gz file.
	tar -zxvf libgraph-1.0.2.tar.gz
	cd libgraph-1.0.2

5. cd libgraph-1.0.2

	./configure
	make

5.1. *****Errors:
	compilation terminated.
	Makefile:460: recipe for target 'guile-libgraph.lo' failed
	make[2]: *** [guile-libgraph.lo] Error 1
	make[2]: Leaving directory '/home/thinhdv/SDL/libgraph-1.0.2'
	Makefile:552: recipe for target 'all-recursive' failed
	make[1]: *** [all-recursive] Error 1
	make[1]: Leaving directory '/home/thinhdv/SDL/libgraph-1.0.2'
	Makefile:268: recipe for target 'all' failed
	make: *** [all] Error 2

5.2. *****Repairs:
	The new libguile source is installed in /usr/include/guile/2.0/ so just doing 
 	make again....

5.3. *****Continue:
	sudo make install
	sudo cp /usr/local/lib/libgraph.* /usr/lib

6. Now you can use #include<graphics.h> on Ubuntu and the following line in your program:
	int gd=DETECT,gm; 
	initgraph(&gd,&gm,NULL);

	Here is a sample program using graphics.h:

	/*  demo.c */
	#include <graphics.h>

	int main()
	{
	   int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50;
	   initgraph(&gd,&gm,NULL);
	   
	   //Code here....
           rectangle(left, top, right, bottom);
	   circle(x, y, radius);
	   bar(left + 300, top, right + 300, bottom);
	   line(left - 10, top + 150, left + 410, top + 150);
	   ellipse(x, y + 200, 0, 360, 100, 50);
	   outtextxy(left + 100, top + 325, "C Graphics Program");

	   delay(5000);
	   closegraph();
	   return 0;
	}

7. compile it use: 
	gcc demo.c -o demo -lgraph

8. run type:
	./demo



