#include <iostream>
#include <stdlib.h>
#include<math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<cstdlib>
#include<ctime>

#include "imageloader.h"

using namespace std;

float aa=-1.11;
float move_x = -1.219f, move_y=-1.1f;
float move_x2= -1.219f, move_y2=-1.1f;
bool move_right=true;
bool move_right2=true;
int cnt=0;
int cnt2=0;
int v,v2;
//bool isPlayerOneTurn = true;


GLuint _textureIdb,dice1,dice2,dice3,dice4,dice5,dice6,dicetemp;
float _angle = 0;            //The rotation of the box
const float BOX_SIZE =0.5f; //the length of each side of the cube
bool rotatecomplete=false,diceRotate=false;

void drawFront()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

	GLfloat lightColor[] = {0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat lightPos[] = {-2 * BOX_SIZE, BOX_SIZE, 4 * BOX_SIZE, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, dice6);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
    glEnd();
    glutSwapBuffers();
    glutPostRedisplay();
}

void drawScene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

	GLfloat lightColor[] = {0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat lightPos[] = {-2 * BOX_SIZE, BOX_SIZE, 4 * BOX_SIZE, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    //drawing board
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glTranslatef(-0.11, 0, -5.0f);
    glScalef(1.8,2,2);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,_textureIdb);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0, -1.0, 0.0);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0, 1.0, 0.0);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, 0.0);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0,-1.0, 0.0);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    ///drawing dice

    glPushMatrix();

    glTranslatef(7.5f, 5.0f, -20.0f);
	glRotatef(-_angle, 1.0f, 1.0f, 0.0f);
	glScalef(1.2,1.2,1.2);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, dice1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	//Top face----1
	//glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	//glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glEnd();

	//Bottom face---------6
	//glColor3f(1.0f, 0.0f, 1.0f);

    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, dice6);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0, -1.0f, 0.0f);
	//glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);

    glEnd();

    //Left face----5
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, dice5);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(-1.0, 0.0f, 0.0f);
  	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
    glEnd();

     //Front face-----3


         if(v==6)
           dicetemp=dice6;
         else if(v==5)
            dicetemp=dice5;
         else if(v==4)
            dicetemp=dice4;
         else if(v==2)
            dicetemp=dice2;
         else if(v==1)
            dicetemp=dice1;
         else
            dicetemp=dice3;



     glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, dicetemp);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
    glEnd();

    //Right face----2
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, dice2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(1.0, 0.0f, 0.0f);
 	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);

    glEnd();

    //Back face--------4
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, dice4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);

	glEnd();
	glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    ///player1
    glPushMatrix();
	glTranslatef(move_x, move_y, -3);//Rotate about the the vector (1, 2, 3)
	glColor3f(1.0,0.0,0);
 	glutSolidSphere(0.055,40,50);
     glPopMatrix();

     ///player2
    glPushMatrix();
	glTranslatef(move_x2, move_y2, -3);//Rotate about the the vector (1, 2, 3)
	glColor3f(0.89,0.905,0);
 	glutSolidSphere(0.055,40,50);
     glPopMatrix();

	glutSwapBuffers();
}

void lightSetting()
{
    srand(0);
	GLfloat ambientIntensity[4] = {0.6, 0.6, 0.6, 1.0};

	GLfloat position[4] = {0.0, 1.0, 0.0, 0.0};

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);


	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientIntensity);

	glLightfv(GL_LIGHT0, GL_POSITION, position);
}



GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}
//Render the images

void initRendering()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, 1.00, 1.0, 200.0);

    Image* image=loadBMP("C:\\Users\\user\\Desktop\\cg\\project\\S_L\\ss.bmp");
    _textureIdb=loadTexture(image);
    delete image;

    //dice1 loading
	image = loadBMP("C:\\Users\\user\\Desktop\\cg\\project\\S_L\\dice1.bmp");
	dice1 = loadTexture(image);
	delete image;

	//dice2 loading
    image = loadBMP("C:\\Users\\user\\Desktop\\cg\\project\\S_L\\dice2.bmp");
	dice2 = loadTexture(image);
	delete image;

	//dice3 loading
    image = loadBMP("C:\\Users\\user\\Desktop\\cg\\project\\S_L\\dice3.bmp");
	dice3 = loadTexture(image);
	delete image;

    //dice4 loading
    image = loadBMP("C:\\Users\\user\\Desktop\\cg\\project\\S_L\\dice4.bmp");
	dice4 = loadTexture(image);
	delete image;

    //dice5 loading
    image = loadBMP("C:\\Users\\user\\Desktop\\cg\\project\\S_L\\dice5.bmp");
	dice5 = loadTexture(image);
	delete image;

    //dice6 loading
    image = loadBMP("C:\\Users\\user\\Desktop\\cg\\project\\S_L\\dice6.bmp");
	dice6 = loadTexture(image);
	delete image;

     //have to load other things================
}

//update function , Called every 25 milliseconds
void update(int value) {
	_angle += 3.0f;
	if (_angle > 360) {
		_angle -= 360;
	}

	glutPostRedisplay();
	if(diceRotate)
    {
      glutTimerFunc(25, update, 0);

    }
	//glutTimerFunc(25, update, 0);
}

void update_a(int value_x, int value_y){
    glutPostRedisplay();
    glPushMatrix();
    glTranslatef(value_x, value_y, -3);
    glColor3f(1.0,0.0,0);
    glutSolidSphere(0.055,40,50);
    glPopMatrix();

    glutSwapBuffers();
}
void update_b(int value_x, int value_y){
    glutPostRedisplay();
    glPushMatrix();
    glTranslatef(value_x, value_y, -3);
    glColor3f(1.0,0.0,0);
    glutSolidSphere(0.055,40,50);
    glPopMatrix();

    glutSwapBuffers();
}

void handleKeypress(unsigned char key, int x, int y)
{
//find key codes: https://www.cambiaresearch.com/articles/15/javascript-char-codes-key-codes
   switch (key)
   {
      case 27:     // ESC key
         exit(0);
         break;
      case 81: //Q
       // Pause/resume (Toggle state)

       if (!diceRotate) //start rotate
        {
         diceRotate=true;
         glutTimerFunc(.5,update, 0) ;
         drawFront();
        }
        else //stop rotating
        {
            diceRotate=false;
           _angle=0;
           v=rand() % 6 + 1;
           cout<<v;

           //MOVE

           for(int i=1;i<=v;i++)
          {
            if(move_right)
            {

                if(cnt<10)
                {
                    move_x+=0.215f;
                    update_a(move_x, move_y);
                    cnt++;
                }
                else{
                    move_x+=0.215f;
                    update_a(move_x, move_y);
                    move_right=false;
                    move_x-=0.215f;
                    move_y+=0.24f;
                    cnt=1;
                }
            }

            else
            {
                if(cnt<10)
                {
                    move_x-=0.215f;
                    update_a(move_x, move_y);
                    cnt++;
                }
                else
                {
                    move_x-=0.215f;
                    update_a(move_x, move_y);
                    move_x+=0.215f;
                    move_right=true;
                    move_y+=0.24f;
                    cnt=1;
                }
            }
        }

    }
    break;

      case 80:  //P
        // Pause/resume (Toggle state)

       if (!diceRotate) //start rotate
        {
         diceRotate=true;
         glutTimerFunc(.5,update, 0) ;
         drawFront();
        }
        else //stop rotating
        {
            diceRotate=false;
           _angle=0;
           v=rand() % 6 + 1;
           cout<<v2;

           //MOVE

           for(int i=1;i<=v;i++)
          {
            if(move_right2)
            {

                if(cnt2<10)
                {
                    move_x2+=0.215f;
                    update_b(move_x2, move_y2);
                    cnt2++;
                }
                else{
                    move_x2+=0.215f;
                    update_b(move_x2, move_y2);
                    move_right2=false;
                    move_x2-=0.215f;
                    move_y2+=0.24f;
                    cnt2=1;
                }
            }

            else
            {
                if(cnt2<10)
                {
                    move_x2-=0.215f;
                    update_b(move_x2, move_y2);
                    cnt2++;
                }
                else
                {
                    move_x2-=0.215f;
                    update_b(move_x2, move_y2);
                    move_x2+=0.215f;
                    move_right2=true;
                    move_y2+=0.24f;
                    cnt2=1;
                }
            }
        }

    }
    break;

}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1120,700);
	glutInitWindowPosition(150,0);
	glutCreateWindow("Snake and Ladder");
	lightSetting();
	initRendering();
	glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
   	glutMainLoop();
	return 0;
}









