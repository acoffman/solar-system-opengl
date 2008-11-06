/////////////////////////////////////////////////////////
// SolarSystemGlobals.h - Global Constant Definitions //
/////////////////////////////////////////////////////////

#ifndef SOLAR_SYSTEM_GLOBALS_H 

/********************/
/* Global Constants */
/********************/

const GLfloat PI = 3.1415926535;
const GLfloat TO_RADIANS = PI/180.0;

// Window Position/Resizing Constants
const GLint INIT_WINDOW_POSITION[2] = { 150, 150 };
const GLfloat ASPECT_RATIO = 1.5;

// Lighting Constants
const GLfloat LIGHT_0_POSITION[]    = { 1.0, 0.0, 0.0, 0.0};
const GLfloat LIGHT_1_POSITION[]    = { -1.0, 0.0, 0.0, 0.0};
const GLfloat LIGHT_2_POSITION[]    = { 0.0, 0.0, 1.0, 0.0};
const GLfloat LIGHT_3_POSITION[]    = { 0.0, 0.0, -1.0, 0.0};
const GLfloat LIGHT_AMBIENT[]       = { 0.8, 0.8, 0.8, 1.0};
const GLfloat LIGHT_DIFFUSE[]       = { 0.9, 0.9, 0.9, 1.0};
const GLfloat LIGHT_SPECULAR[]      = { 1.0, 1.0, 1.0, 1.0};
const GLfloat LIGHT_MODEL_AMBIENT[] = { 0.2, 0.2, 0.2, 1.0};

// Earth and Moon Constants
const char EARTH_BMP_FILENAME[] = "Bitmaps/earthmap.bmp";
const char MOON_BMP_FILENAME[]  = "Bitmaps/moonmap.bmp";
const GLfloat EARTH_RADIUS      = 0.18;
const GLfloat MOON_RADIUS       = 0.04;
const GLfloat MOON_ORBIT_RADIUS = 0.50;
const GLfloat EARTH_ROTATION    = 1.00;
const GLfloat LUNAR_CYCLE       = 30.0;

// Viewer Positioning Constants
const GLfloat MAXIMUM_VIEWER_DISTANCE    = 20;
const GLfloat MINIMUM_VIEWER_DISTANCE    = 2;
const GLfloat INITIAL_VIEWER_DISTANCE    = 10;
const GLfloat VIEWER_DISTANCE_INCREMENT  = 0.1;
const GLfloat INITIAL_VIEWER_AZIMUTH     = 0.0;
const GLfloat INITIAL_VIEWER_ZENITH      = PI / 2.0;
const GLfloat VIEWER_ANGLE_INCREMENT     = PI / 60.0;
const GLfloat LOOK_AT_POSITION[] = { 0.0, 0.0, 0.0 };

//Additional Planets Constants for bitmap files
const char MERCURY_BMP_FILENAME[] =	"Bitmaps/mercurymap.bmp";
const char VENUS_BMP_FILENAME[] = 	"Bitmaps/venusmap.bmp";
const char MARS_BMP_FILENAME[] = 		"Bitmaps/marsmap.bmp";
const char JUPITER_BMP_FILENAME[] = "Bitmaps/jupitermap.bmp";
const char SATURN_BMP_FILENAME[] = 	"Bitmaps/saturnmap.bmp";
const char URANUS_BMP_FILENAME[] = 	"Bitmaps/uranusmap.bmp";
const char NEPTUNE_BMP_FILENAME[] = "Bitmaps/neptunemap.bmp";
const char PLUTO_BMP_FILENAME[] = 	"Bitmaps/plutomap.bmp";
const char RING_BMP_FILENAME[] = 		"Bitmaps/saturnringmap.bmp";
const char SUN_BMP_FILENAME[] = 		"Bitmaps/sunmap.bmp";

//Additional Planets Constants for Planet Radiuses
const GLfloat MERCURY_RADIUS =	0.1;
const GLfloat VENUS_RADIUS =		0.18;
const GLfloat MARS_RADIUS = 		0.3;
const GLfloat JUPITER_RADIUS = 	0.6;
const GLfloat SATURN_RADIUS = 	0.5;
const GLfloat URANUS_RADIUS = 	0.3;
const GLfloat NEPTUNE_RADIUS = 	0.3;
const GLfloat PLUTO_RADIUS = 		0.05;
const GLfloat SUN_RADIUS = 			1.0;

//Additional Planets Constants for Orbit Radius
const GLfloat MERCURY_ORBIT_RADIUS = 1.5;
const GLfloat VENUS_ORBIT_RADIUS =	 2.0;
const GLfloat MARS_ORBIT_RADIUS = 	 3.5;
const GLfloat JUPITER_ORBIT_RADIUS = 5.0;
const GLfloat SATURN_ORBIT_RADIUS =  7.0;
const GLfloat URANUS_ORBIT_RADIUS =	 8.5;
const GLfloat NEPTUNE_ORBIT_RADIUS = 9.0;
const GLfloat PLUTO_ORBIT_RADIUS = 	 10.0;
const GLfloat EARTH_ORBIT_RADIUS = 	 3.0;

//Additional Planets Constants for Orbit Duration
const GLfloat MERCURY_ORBIT_DUR = 88;
const GLfloat VENUS_ORBIT_DUR=	 	225;
const GLfloat EARTH_ORBIT_DUR=		365;
const GLfloat MARS_ORBIT_DUR= 	 	686;
const GLfloat JUPITER_ORBIT_DUR=  4333;
const GLfloat SATURN_ORBIT_DUR=   10759;
const GLfloat URANUS_ORBIT_DUR=	  30685;
const GLfloat NEPTUNE_ORBIT_DUR=  60190;
const GLfloat PLUTO_ORBIT_DUR= 	  90800;

//Additional Planets Constants for Rotation Duration
const GLfloat MERCURY_ROTATION_DUR = 59;
const GLfloat VENUS_ROTATION_DUR=	 	 -243;
const GLfloat MARS_ROTATION_DUR= 	 	 1;
const GLfloat JUPITER_ROTATION_DUR=  0.4;
const GLfloat SATURN_ROTATION_DUR=   0.4;
const GLfloat URANUS_ROTATION_DUR=	 -0.7;
const GLfloat NEPTUNE_ROTATION_DUR=  0.7;
const GLfloat PLUTO_ROTATION_DUR= 	 -6;

//Additional Planets Constants for Inclination
const GLfloat MERCURY_INCLINATION = 7;
const GLfloat VENUS_INCLINATION   = 3;
const GLfloat MARS_INCLINATION    = 2;
const GLfloat JUPITER_INCLINATION = 1;
const GLfloat SATURN_INCLINATION  = 2;
const GLfloat URANUS_INCLINATION  = 1;
const GLfloat NEPTUNE_INCLINATION = 2;
const GLfloat PLUTO_INCLINATION   = 1;
const GLfloat EARTH_INCLINATION   = 7;

//Particle System Constants
const char PARTICLE_BMP_FILENAME[] = "Bitmaps/Particle.bmp";


#define SOLAR_SYSTEM_H
#endif