#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <math.h>
#include <stdlib.h>

static float da = 0, db = 0, dc = 0;
static float dx = 0, dy = 0, dz = 0;
static float ex = 0, ey = 0, ez = 30;
static float cx = 0, cy = 0, cz = 0;
static float hx = 0, hy = 1, hz = 0;
static float zx = 1, zy = 1, zz = 1;
static float degreex = 0, degreey = 0, degreez = 0;
static float theta = 0;
static int height = 1080, width = 720;
static int flag = 0, flag1 = 0;
static int slices = 50;
static int stacks = 50;
static int on=0;
static int off=0;
/* GLUT callback Handlers */
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void cube(){
    glBegin(GL_QUADS);
        glVertex3f(-1, -1, 1);
        glVertex3f(1, -1, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(-1, 1, 1);

        glVertex3f(1, 1, 1);
        glVertex3f(1, -1, 1);
        glVertex3f(1, -1, -1);
        glVertex3f(1, 1, -1);

        glVertex3f(-1, 1, -1);
        glVertex3f(-1, -1, -1);
        glVertex3f(-1, -1, 1);
        glVertex3f(-1, 1, 1);

        glVertex3f(-1, 1, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, -1, -1);
        glVertex3f(-1, -1, -1);

        glVertex3f(-1, 1, -1);
        glVertex3f(-1, 1, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(1, 1, -1);

        glVertex3f(-1, -1, 1);
        glVertex3f(-1, -1, -1);
        glVertex3f(1, -1, -1);
        glVertex3f(1, -1, 1);
    glEnd();
}

void lower_stand(){

    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.2);;
    for(double i = 360; i >=0; i--)
    {
        double theta = 2.0f * 3.1416 * i / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);

        glVertex3f(x, y, -.08);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.2);
    for(double i = 0; i <=360; i++)
    {
        double theta = 2 * 3.1416 * i / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);

        glVertex3f(x, y, .08);
    }
    glEnd();

    glBegin(GL_QUAD_STRIP);
    for(double i = 0; i <= 360; i++)
    {
        double theta = 2 * 3.1416 * i / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);

        glVertex3f(x, y, .05);
        glVertex3f(x, y, -.05);
    }
    glEnd();
}

void fan_stand(){

   glBegin(GL_POLYGON);
    glColor3f(.3,.3,.3);
    for(double i = 360; i >=0; i--)
    {
        double theta = 2.0f * 3.1416 * i / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);

        glVertex3f(x, y, -.1);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.3,.3,.3);
    for(double i = 0; i <=360; i++)
    {
        double theta = 2 * 3.1416 * i / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);

        glVertex3f(x, y, .1);
    }
    glEnd();

    glBegin(GL_QUAD_STRIP);
 glColor3f(.3,.3,.3);
    for(double i = 0; i <= 360; i++)
    {
        double theta = 2 * 3.1416 * i / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);

        glVertex3f(x, y, .1);
        glVertex3f(x, y, -.1);

    }
    glEnd();
}

void light_cover(){

    glBegin(GL_POLYGON);
    glColor3f(0,1,0);;
    for(double i = 360; i >=0; i--)
    {
        double theta = 2.0f * 3.1416 * i / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);

        glVertex3f(x, y, -.08);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    for(double i = 0; i <=360; i++)
    {
        double theta = 2 * 3.1416 * i / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);

        glVertex3f(x, y, .08);
    }
    glEnd();

}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glTranslated(dx,dy,dz);

    glRotated(da,1,0,0);
    glRotated(db,0,1,0);
    glRotated(dc,0,0,1);

    glScaled(zx,zy,zz);

    glPushMatrix(); //monitor
        glColor3d(1,1,1);
        glScaled(0.9,0.5,0.04);
        cube();
    glPopMatrix();

    glPushMatrix(); //monitor back cover
        glColor3d(.2,.2,.2);
        glTranslatef(0,0,-0.05);
        glScaled(0.9,0.5,0.01);
        cube();
    glPopMatrix();

    glPushMatrix(); //monitor upper border
        glColor3d(.2,.2,.2);
        glTranslatef(0,0.55,0);
        glScaled(0.9,0.05,0.04);
        cube();
    glPopMatrix();

    glPushMatrix(); //monitor lower border
        glColor3d(.2,.2,.2);
        glTranslatef(0,-0.55,0);
        glScaled(0.9,0.05,0.04);
        cube();
    glPopMatrix();

    glPushMatrix(); //monitor left border
        glColor3d(.2,.2,.2);
        glRotated(90,0,0,1);
        glTranslatef(0,-0.95,0);
        glScaled(0.6,0.05,0.04);
        cube();
    glPopMatrix();

    glPushMatrix(); //monitor right border
        glColor3d(.2,.2,.2);
        glRotated(90,0,0,1);
        glTranslatef(0,0.95,0);
        glScaled(0.6,0.05,0.04);
        cube();
    glPopMatrix();

    glPushMatrix(); //monitor stand
        glColor3d(.2,.3,.1);
        glTranslatef(0,-0.65,0);
        glScaled(0.1,0.05,0.1);
        cube();
    glPopMatrix();

    glPushMatrix(); //monitor lower stand
        glRotated(90,1,0,0);
        glTranslatef(0,0,0.7);
        glScaled(0.1,0.1,0.1);
        lower_stand();
    glPopMatrix();

    glPushMatrix(); //monitor table
        glColor3d(.3,.3,.3);
        glTranslatef(-0.5,-0.75,0);
        glScaled(2,0.05,1);
        cube();
    glPopMatrix();

    glPushMatrix(); //monitor table left side
        glColor3d(.2,.2,.2);
        glTranslatef(-1.5,-1.80,0);
        glScaled(1,1,1);
        cube();
    glPopMatrix();

    glPushMatrix(); //monitor table right side front leg
        glColor3d(.2,.2,.2);
        glTranslatef(1.20,-1.80,0.7);
        glScaled(0.1,1,0.1);
        cube();
    glPopMatrix();

    glPushMatrix(); //monitor table right side back leg
        glColor3d(.2,.2,.2);
        glTranslatef(1.20,-1.80,-0.7);
        glScaled(0.1,1,0.1);
        cube();
    glPopMatrix();

    glPushMatrix(); //lamp stand
        glRotated(180,1,0,0);
        glTranslatef(-2.25,0.5,0);
        glScaled(0.08,0.5,0.04);
        cube();
    glPopMatrix();

    glPushMatrix(); //lamp middle design
        glColor3d(1,1,1);
        glRotated(180,1,0,0);
        glTranslatef(-2.25,0.35,0);
        glScaled(0.02,0.25,0.06);
        cube();
    glPopMatrix();

    glPushMatrix(); //lamp joint
        glColor3d(.2,.2,.2);
        glTranslatef(-2.25,0.10,0);
        glRotated(180,1,0,0);
        glutSolidTorus(0.05,0.05,slices,stacks);
    glPopMatrix();

    glPushMatrix(); //lamp joint design front
        glColor3d(1,1,1);
        glTranslatef(-2.25,0.10,0.06);
        glRotated(180,1,0,0);
        glutSolidTorus(0.02,0.02,slices,stacks);
    glPopMatrix();

    glPushMatrix(); //lamp joint design back
        glColor3d(1,1,1);
        glTranslatef(-2.25,0.10,-0.06);
        glRotated(180,1,0,0);
        glutSolidTorus(0.02,0.02,slices,stacks);
    glPopMatrix();

    glPushMatrix(); //lamp upper stand
        glColor3d(.2,.2,.2);
        glTranslatef(-1.8,0.48,0);
        glRotated(-50,0,0,1);
        glScaled(0.08,0.5,0.04);
        cube();
    glPopMatrix();

    glPushMatrix(); //lamp upper middle design
        glColor3d(1,1,1);
        glTranslatef(-1.8,0.48,0);
        glRotated(-50,0,0,1);
        glScaled(0.02,0.25,0.06);
        cube();
    glPopMatrix();
  glPushMatrix();// lamp cover
     glColor3d(.3,.3,.3);
       glTranslatef(-1.4,0.4,0);
      glScaled(.38,.38,.38);
        glRotated(-90,1,0,0);
        glutSolidCone(1,1,50,50);
    glPopMatrix();
     glPushMatrix();//light
     glColor3d(on,off,0);
           glTranslatef(-1.4,0.4,0);
      glScaled(.1,.1,.1);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

glPushMatrix(); // fan base
       glTranslated(3,-2.8,-2.1);
        glRotated(90,1,0,0);
        glScaled(.4,.4,1);
       fan_stand();
    glPopMatrix();

glPushMatrix(); // fan rod
       glTranslated(3,-1,-2.1);
      glScaled(.1,18,.1);
        glRotated(90,1,0,0);
       fan_stand();
    glPopMatrix();
glPushMatrix(); // fan motor
     glTranslated(3,1.1,-2);
      glScaled(.2,.2,6);
   //  glRotated(90,1,0,0);
 fan_stand();
    glPopMatrix();

glPushMatrix(); // fan motor rod
glColor3d(0,0,0);
    glTranslated(3,1.1,-1.3);
        glScaled(.1,.1,.2);
        cube();
    glPopMatrix();
    glPushMatrix();//fan 1
      glColor3d(.2,.2,.2);
    glTranslated(3,1.1,-1);
     glRotated(-a*4,0,0,1);
        glScaled(.8,.1,.1);
        cube();
    glPopMatrix();

    glPushMatrix();    //fan 2
      glColor3d(.2,.2,.2);
     glTranslated(3,1.1,-1);
      glRotated(-a*4,0,0,1);
        glScaled(.1,.8,.1);
        cube();
    glPopMatrix();

 glPushMatrix();// Fan Net
  glColor3d(.3,.3,.3);
           glTranslated(3,1.1,-.6);
        glScaled(1,1,1);
        glutWireSphere(1,8,8);
    glPopMatrix();


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
    gluLookAt(ex,ey,ez,cx,cy,cz,hx,hy,hz);

    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            zx +=.05;
            zy +=.05;
            zz +=.05;
            break;

        case '-':
            zx -=.05;
            zy -=.05;
            zz -=.05;
            break;

        case 'a':
            da +=5;
            break;

        case 'b':
            db +=5;
            break;

        case 'c':
            dc +=5;
            break;

        case 'd':
            da -=5;
            break;

        case 'e':
            db -=5;
            break;

        case 'f':
            dc -=5;
            break;

        case 'x':
            dx +=.5;
            dy = 0;
            dz = 0;
            break;

        case 'y':
        	dx = 0;
            dy +=.5;
            dz = 0;
            break;

        case 'z':
        	dx = 0;
        	dy = 0;
            dz +=.5;
            break;

        case 'i':
            dx -=.5;
            dy = 0;
            dz = 0;
            break;

        case 'j':
        	dx = 0;
            dy -=.5;
            dz = 0;
            break;
            case '1':
        	on=1;
        	off=1;
            break;
 case '0':
        	on=0;
        	off=0;
            break;
        case 'k':
        	dx = 0;
        	dy = 0;
            dz -=.5;
            break;

    }
    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

/* Program entry point */
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1080,720);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Computer Desk");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glutMainLoop();

    return EXIT_SUCCESS;
}
