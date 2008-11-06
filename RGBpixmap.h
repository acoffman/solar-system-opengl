#ifndef _RGBPIXMAP
	#define _RGBPIXMAP
#if defined(_WIN32)
#include <glut.h>
#else
#include <GLUT/glut.h>
#endif
#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

//@@@@@@@@@@@@@@@@@@ IntPoint class @@@@@@@@@@@@@@@@
class IntPoint
{ 
	// for 2D points with integer coordinates
public:
	int x,y;
	void set(int dx, int dy){x = dx; y = dy;}
	void set(IntPoint& p){ x = p.x; y = p.y;} 
	IntPoint(int xx, int yy){x = xx; y = yy;}
	IntPoint(){ x = y = 0;}
};

//@@@@@@@@@@@@@@@@@@ Point2 class @@@@@@@@@@@@@@@@
class Point2
{
	// for 2D points with real coordinates
public: 
	float x,y;
	void set(float dx, float dy){x = dx; y = dy;}
	void set(Point2& p){ x = p.x; y = p.y;} 
	Point2(float xx, float yy){x = xx; y = yy;}
	Point2(){x = y = 0;}
};

//<<<<<<<<<<<<<<<<<<<<<< PolyLine >>>>>>>>>>>>>>>>>>>>>>>>>
class PolyLine
{
	// a polyline is a num plus an array of points
public:
	int num;
	Point2 pt[80]; //may need larger arrays in some circumstances
	PolyLine(){num = 0;}
};

// @@@@@@@@@@@@@@@@@@@@@@@@ IntRect class @@@@@@@@@@@@@@@@@@@@
class IntRect
{
	// a rectangle with integer border values
public: 
  int left, top, right, bott;
  IntRect(){left = top = right = bott = 0;}
  IntRect(int l, int t, int r, int b)
  {left = l; top = t; right = r; bott = b;}
  void set(int l, int t, int r, int b)
  {left = l; top = t; right = r; bott = b;}
  void set(IntRect& r)
  {left = r.left; top = r.top; right = r.right; bott = r.bott;}
};


// RGBpixmap.h: a class to support working with RGB pixmaps.


typedef unsigned char uchar;

class mRGB
{
	// the name RGB is already used by Windows
public: uchar r,g,b,a;
		mRGB(){r = g = b = 0; a = 255;}
		mRGB(mRGB& p){r = p.r; g = p.g; b = p.b; a = p.a;}
		mRGB(uchar rr, uchar gg, uchar bb){r = rr; g = gg; b = bb; 
											if ( (r==255) && (g==255) && (b==255)) a = 0; else a = 255;}
		mRGB(uchar rr, uchar gg, uchar bb, uchar aa){r = rr; g = gg; b = bb; a = aa;}
		void set(uchar rr, uchar gg, uchar bb){r = rr; g = gg; b = bb; 
											if ( (r==255) && (g==255) && (b==255)) a = 0; else a = 255;}
		void set(uchar rr, uchar gg, uchar bb, uchar aa){r = rr; g = gg; b = bb; a = aa;}
};

//$$$$$$$$$$$$$$$$$ RGBPixmap class $$$$$$$$$$$$$$$
class RGBpixmap
{
private: 
	mRGB* pixel; // array of pixels

public:
	int nRows, nCols; // dimensions of the pixmap
	RGBpixmap() {nRows = nCols = 0; pixel = 0;}
	RGBpixmap(int rows, int cols) //constructor
	{
		nRows = rows;
		nCols = cols;
		pixel = new mRGB[rows*cols]; 
	}

	int readBMPFile(string fname, bool hasAlpha); // read BMP file into this pixmap
	void setTexture(GLuint textureName);

	void freeIt() // give back memory for this pixmap
	{
		delete []pixel; nRows = nCols = 0;
	}

	//<<<<<<<<<<<<<<<<<< copy >>>>>>>>>>>>>>>>>>>
	void copy(IntPoint from, IntPoint to, int x, int y, int width, int height)
	{
		// copy a region of the display back onto the display
		if(nRows == 0 || nCols == 0) return;
		glCopyPixels(x, y, width, height,GL_COLOR);
	}

	//<<<<<<<<<<<<<<<<<<< draw >>>>>>>>>>>>>>>>>
	void draw()
	{ 
		// draw this pixmap at current raster position
		if(nRows == 0 || nCols == 0) return;

		//tell OpenGL: don’t align pixels to 4 byte boundaries in memory
		glPixelStorei(GL_UNPACK_ALIGNMENT,1);
		glDrawPixels(nCols, nRows,GL_RGBA, GL_UNSIGNED_BYTE,pixel);
	}

	//<<<<<<<<<<<<<<<<< read >>>>>>>>>>>>>>>>
	int read(int x, int y, int wid, int ht)
	{ 
		// read a rectangle of pixels into this pixmap
		nRows = ht;
		nCols = wid;
		pixel = new mRGB[nRows *nCols];
		if(!pixel) return -1;

		//tell OpenGL: don’t align pixels to 4 byte boundaries in memory
		glPixelStorei(GL_PACK_ALIGNMENT,1);
		glReadPixels(x, y, nCols, nRows, GL_RGBA,GL_UNSIGNED_BYTE,pixel);
		return 0;
	}

	//<<<<<<<<<<<<<<<<< read from IntRect >>>>>>>>>>>>>>>>
	int read(IntRect r)
	{
		// read a rectangle of pixels into this pixmap
		nRows = r.top - r.bott;
		nCols = r.right - r.left;
		pixel = new mRGB[nRows *nCols]; 
		if(!pixel) return -1;

		//tell OpenGL: don’t align pixels to 4 byte boundaries in memory
		glPixelStorei(GL_PACK_ALIGNMENT,1);
		glReadPixels(r.left,r.bott, nCols, nRows, GL_RGBA, GL_UNSIGNED_BYTE, pixel);
		return 0;
	}

	//<<<<<<<<<<<<<< setPixel >>>>>>>>>>>>>
	void setPixel(int x, int y, mRGB color)
	{
		if(x>=0 && x <nCols && y >=0 && y < nRows)
			pixel[nCols * y + x] = color;
	}

	//<<<<<<<<<<<<<<<< getPixel >>>>>>>>>>>
	mRGB getPixel(int x, int y)
	{ 		
		mRGB bad(255,255,255);
		assert(x >= 0 && x < nCols);
		assert(y >= 0 && y < nRows);
		return pixel[nCols * y + x];
	}
}; //end of class RGBpixmap
#endif



