// Jogo Asteroids 
// main.cpp
// Prof. Giovani Bernardes Vitor
// ECO034 - 2017



#include <iostream>
#include <thread>

#include "Application.hpp"

Application *ptr_;

void draw() {ptr_->draw();}
void resize(GLsizei w, GLsizei h) {ptr_->resize(w, h);}
void KeyboardHandle(unsigned char key, int x, int y){ptr_->KeyboardHandle(key, x, y);}
void keyUp(unsigned char key, int x, int y){ptr_->keyUp(key, x, y);}
void MouseHandle(int button, int state, int x, int y){ptr_->MouseHandle(button, state, x, y);}
void SpecialKeyHandle(int key, int x, int y){ptr_->SpecialKeyHandle(key, x, y);}
void SpecialKeyUpHandle(int key, int x, int y){ptr_->SpecialKeyUpHandle(key, x, y);}
void update(int value){ptr_->update(value, &update);}

     
// Programa Principal 
int main(int argc, char** argv)
{
     int time=0;

     Application app(argc,argv);
     ptr_ = &app;

     glutDisplayFunc(draw);
     glutReshapeFunc(resize);
     glutKeyboardFunc(KeyboardHandle);
     glutKeyboardUpFunc(keyUp);
     glutMouseFunc(MouseHandle);
     glutSpecialFunc(SpecialKeyHandle); 
     glutSpecialUpFunc(SpecialKeyUpHandle);
     glutTimerFunc(30,update,time);
     glutMainLoop();

     return 0;
}
