
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    //glRotatef(0.1, 0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);   // color (Red, Green, Blue)
        glVertex3f(-0.6, 1.0, 0.0);
        glVertex3f(-0.5, 0.0, 0.0);
        glVertex3f(-1.0, 0.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0,1.0, 0.0);
        glVertex3f(0.1, 0.0, 0.0);
        glVertex3f(1.0, 0.0, 0.0);
        glVertex3f(0.8, 0.8, 0.0);
        glVertex3f(0.1, 0.8, 0.0);

    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h){
    glViewport(0,0,w,h);
}

void initOpenGl(){
    glClearColor(0.4, 0.4, 0.8, 1.0);
}

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("first opengl app");

    initOpenGl();

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
