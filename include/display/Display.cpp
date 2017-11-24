
#include "Display.h"

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include <string>
#include <iostream>

Display::Display (

    int argc,
    char ** argv,
    const char * title,
    const unsigned int display_mode,
    const int WIDTH, const int HEIGHT,
    const int POSX, const int POSY

) {

    this -> WIDTH = WIDTH;
    this -> HEIGHT = HEIGHT;
    this -> POSX = POSX;
    this -> POSY = POSY;

    glutInit ( &argc, argv );

    glutInitDisplayMode ( display_mode ? display_mode : this -> display_mode );

    glutInitWindowSize ( this -> WIDTH, this -> HEIGHT );

    glutInitWindowPosition ( this -> POSX, this -> POSY );

    glutCreateWindow ( title ? title : "Baby GL" );

    this -> init ();

}

Display::~Display () {

    std::cout << "Destructing..." << std::endl;

}

void Display::init () {

    glClearColor( .0f, .0f, .0f, .5f );

    this -> setProjView ( - this -> WIDTH, this -> WIDTH, - this -> HEIGHT, this -> HEIGHT );

}

void Display::loop () {

    glutMainLoop ();

}

void Display::render ( void ( * callback ) ( void ) ) {

    glutDisplayFunc ( callback );

}

void Display::setProjView (

    const float left,
    const float right,
    const float top,
    const float bottom

) {

    glMatrixMode ( GL_PROJECTION );
    glLoadIdentity ();
    gluOrtho2D ( left, right, top, bottom );

}