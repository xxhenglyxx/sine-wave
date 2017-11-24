
#include <iostream>

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <math.h>

#define PI 3.14

#include <display/Display.h>

void drawCircle ( const double radius, const double POSX, const double POSY ) {

    int index = 0;
    
    glBegin ( GL_TRIANGLE_FAN );

        glColor3d ( 1.0, .0, .0 );

        for ( index = 0; index < 360; index++ ) {
        
            glVertex2f( radius * cos ( ( float ) index ) + POSX , radius * sin ( ( float ) index ) + POSY );

        }

    glEnd();

}

void drawPoint ( const float p1, const float p2 ) {

    glBegin ( GL_POINTS );

        glColor3d ( 0, 0, 1.0 );
        glVertex2f ( p1, p2 );
    
    glEnd ();

}

void drawTriangle (

    const double c1x,
    const double c1y,
    const double c2x,
    const double c2y,
    const double c3x,
    const double c3y

) {

    glColor3d ( .0, .0, 1.0 );

    glBegin ( GL_TRIANGLES );

        glVertex2f ( c1x, c1y );
        glVertex2f ( c2x, c2y );
        glVertex2f ( c3x, c3y );

    glEnd ();

}

void drawGrid ( const int WIDTH, const int HEIGHT, const int UNIT ) {

    const int unit_width_apart = ( WIDTH / UNIT ) * 2;
    int index = - unit_width_apart;

    glBegin ( GL_LINES );

        glColor3d ( 1.0, 1.0, 1.0 );

        glVertex2f ( - WIDTH, 0 );
        glVertex2f ( WIDTH, 0 );

    glEnd ();

    glBegin ( GL_LINES );
        
        glColor3d ( 1.0, 1.0, 1.0 );

        glVertex2f ( 0, HEIGHT );
        glVertex2f ( 0, -HEIGHT );

    glEnd ();

}

void drawSineWave (
    
    const double amplitude = 200,
    const double phase = 0,
    const double frequency = 2 * PI * 10,
    const double duration_from = -1000,
    const double duration_to = 1000

) {

    glBegin ( GL_POINTS );

        glColor3d ( 1.0, .0, .0 );
    
        for ( int duration = duration_from; duration < duration_to; duration ++ ) {

            glVertex2f ( duration, amplitude * sin ( ( frequency * duration ) + phase ) );

        }

    glEnd ();

}

void render() {

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    drawGrid ( 680, 680, 10 );

    drawSineWave ();

    // drawCircle ( 30, -20, 20 );

    // drawTriangle ( 100, 50, 50, 100, 100, 100 );

    glFlush (); // render

}

int main ( int argc, char ** argv ) {

    const int WIDTH = 680, HEIGHT = 680, UNIT = 10;

    Display mainDisplay ( argc, argv, "Circle GL2", GLUT_SINGLE, WIDTH, HEIGHT, 100, 100 );

    mainDisplay.render ( render );

    mainDisplay.loop ();

    return 0;

}