
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

void drawText (
    
    const char text [],
    const int size,
    const GLint pos_x = 0,
    const GLint pos_y = 0

) {

    glRasterPos2i ( pos_x, pos_y );

    for ( int index = 0; index < size; index ++ ) {

        glutBitmapCharacter ( GLUT_BITMAP_HELVETICA_18, text[ index ] );

    }

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

    int unit_distance = 0;

    glBegin ( GL_LINES );

        glColor3d ( 1.0, 1.0, 1.0 );

        glVertex2f ( - WIDTH, 0 );
        glVertex2f ( WIDTH, 0 );

    glEnd ();

    while ( unit_distance < WIDTH ) {

        const char * text = std::to_string ( unit_distance ).c_str ();
        const char * text2 = std::to_string ( - unit_distance ).c_str ();

        glColor3d ( 1.0, 1.0, 1.0 );

        glBegin ( GL_LINES );

            glVertex2f ( unit_distance, 16 );
            glVertex2f ( unit_distance, -16 );

        glEnd ();

        drawText ( text, 3, unit_distance - 30, - 70 );

        glBegin ( GL_LINES );

            glVertex2f ( 16, unit_distance );
            glVertex2f ( -16, unit_distance );
        
        glEnd ();

        drawText ( text, 3, 50, unit_distance - 10 );

        glBegin ( GL_LINES );

            glVertex2f ( - unit_distance, 16 );
            glVertex2f ( - unit_distance, -16 );

        glEnd ();

        // drawText ( std::to_string ( - unit_distance ).c_str(), 3, - unit_distance - 30, -50 );

        glBegin ( GL_LINES );

            glVertex2f ( 16, - unit_distance );
            glVertex2f ( -16, - unit_distance );
        
        glEnd ();

        unit_distance += 100;

    }

    glBegin ( GL_LINES );
        
        glColor3d ( 1.0, 1.0, 1.0 );

        glVertex2f ( 0, HEIGHT );
        glVertex2f ( 0, -HEIGHT );

    glEnd ();

}

void drawSineWave (
    
    const double amplitude = 200,
    const double phase = 0,
    const double frequency = 10,
    const double duration_from = -1000,
    const double duration_to = 1000

) {

    const double angular_frequency = 2 * PI * frequency;

    glBegin ( GL_POINTS );

        glColor3d ( 1.0, .0, .0 );
    
        for ( int duration = duration_from; duration < duration_to; duration ++ ) {

            glVertex2f ( duration, amplitude * sin ( ( angular_frequency * duration ) + phase ) );

        }

    glEnd ();

}

void render() {

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    drawGrid ( 680, 680, 10 );

    drawText ( "X", 1, 30, 630 );
    drawText ( "Y", 1, 630, 30 );

    drawSineWave ( 300, 0, 8 );

    glFlush (); // render

}

int main ( int args_length, char ** args_context ) {

    const int WIDTH = 680, HEIGHT = 680, UNIT = 100;

    Display mainDisplay ( args_length, args_context, "Circle GL2", GLUT_SINGLE, WIDTH, HEIGHT, 100, 100 );

    mainDisplay.render ( render );

    mainDisplay.loop ();

    return 0;

}