
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <math.h>

double x=0, y=0, z=0.7, r=100;
void DrawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    char c = getchar();
    if(c=='j') {
        x = x - 0.1;
    }
    else if(c=='l'){
        x = x + 0.1;
    }
    else if(c=='k'){
        y = y - 0.1;
    }
    else if(c=='i'){
        y = y + 0.1;
    }
    else ;
    DrawCircle(x, y, z, r);
    glutSwapBuffers();
}

void reshape(int w, int h){
    glViewport(0,0,w,h);
}

void initOpenGl(){
    glClearColor(0.5, 0.5, 0.5, 1.0);
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
