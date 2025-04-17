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
