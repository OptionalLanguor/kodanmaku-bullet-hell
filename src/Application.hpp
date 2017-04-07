// Jogo Asteroids 
// application.hpp
// Prof. Giovani Bernardes Vitor
// ECO034 - 2017

#include <iostream>
#include <vector>
#include <list>

#include <GL/glut.h>


#include "Objects.hpp"
#include "Player.hpp"
#include "Bala.hpp"
#include "Inimigo.hpp"

using namespace std;

/////////////////////////////////////////////////////////////
class Application
{
public:
	Application(int argc, char** argv);
	~Application(void);

	void draw();
	void resize(GLsizei w, GLsizei h);
	void KeyboardHandle(unsigned char key, int x, int y);
	void MouseHandle(int button, int state, int x, int y);
	void SpecialKeyHandle(int key, int x, int y);
	void update(int value, void (*func_ptr)(int));

private:

	int time;
	

	GLfloat xf;
	GLfloat yf;
	GLfloat win;
	GLint view_w;
	GLint view_h;

	list<Objects*> list_;

private:
	void Inicializa (void);
	bool insert_object(void);
	
};

