/*#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 1. Drawing character 'A' using primitives (lines)
    glColor3f(0.0, 1.0, 0.0);
    glLineWidth(4.0);

    glBegin(GL_LINES);
        glVertex2f(-0.5f, -0.5f); // left leg
        glVertex2f( 0.0f,  0.5f);

        glVertex2f( 0.0f,  0.5f); // right leg
        glVertex2f( 0.5f, -0.5f);

        glVertex2f(-0.25f, 0.0f); // cross bar
        glVertex2f( 0.25f, 0.0f);
    glEnd();

    // 2. Drawing character 'A' using bitmap font
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2f(-0.1f, -0.8f); // position in window
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1); // orthographic 2D view
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Task 1: Display Character A");
    glutInitWindowSize(500, 500);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
*/
#include <GL/glut.h>
#include <ctype.h>

char currentChar = 'A';

void drawPrimitiveChar(char c) {
    glLineWidth(4.0);
    glBegin(GL_LINES);

    switch (toupper(c)) {
        case 'A':
            glVertex2f(-0.5f, -0.5f); glVertex2f(0.0f, 0.5f);
            glVertex2f(0.0f, 0.5f); glVertex2f(0.5f, -0.5f);
            glVertex2f(-0.25f, 0.0f); glVertex2f(0.25f, 0.0f);
            break;

        case 'Z':
            glVertex2f(-0.5f, 0.5f); glVertex2f(0.5f, 0.5f);
            glVertex2f(0.5f, 0.5f); glVertex2f(-0.5f, -0.5f);
            glVertex2f(-0.5f, -0.5f); glVertex2f(0.5f, -0.5f);
            break;

        case '3':
            glVertex2f(-0.2f, 0.5f); glVertex2f(0.2f, 0.5f);
            glVertex2f(0.2f, 0.5f); glVertex2f(0.2f, 0.0f);
            glVertex2f(0.2f, 0.0f); glVertex2f(-0.2f, 0.0f);
            glVertex2f(0.2f, 0.0f); glVertex2f(0.2f, -0.5f);
            glVertex2f(0.2f, -0.5f); glVertex2f(-0.2f, -0.5f);
            break;

        case '&':
            glVertex2f(0.0f, 0.5f); glVertex2f(-0.3f, 0.3f);
            glVertex2f(-0.3f, 0.3f); glVertex2f(-0.1f, 0.1f);
            glVertex2f(-0.1f, 0.1f); glVertex2f(-0.3f, -0.2f);
            glVertex2f(-0.3f, -0.2f); glVertex2f(0.2f, -0.3f);
            glVertex2f(0.2f, -0.3f); glVertex2f(0.0f, 0.0f);
            break;

        default:
            // Draw nothing for unsupported characters
            break;
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 1. Draw character manually with lines
    glColor3f(0.0, 1.0, 0.0);
    drawPrimitiveChar(currentChar);

    // 2. Draw character using bitmap
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2f(-0.05f, -0.8f);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, currentChar);

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if (isalnum(key) || key == '&' || key == '*') {
        currentChar = key;
        glutPostRedisplay();
    }
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Task 1: Draw Characters - A, Z, 3, &");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}
