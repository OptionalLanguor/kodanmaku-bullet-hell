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
#include "tga.hpp"
#include <sstream>

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
	void keyUp(unsigned char key, int x, int y);
	void keyOperations (void);
	void MouseHandle(int button, int state, int x, int y);
	void SpecialKeyHandle(int key, int x, int y);
	void SpecialKeyUpHandle(int key, int x, int y);
	void update(int value, void (*func_ptr)(int));
	void pewPew(double x, double y, bool donoDaBala, int tipoBala);
	void printOnScreen(double x, double y, float r, float g, float b, void* font, string str);

private:

	int time;
	Player* player;
	int inimigoMorto;

	GLfloat xf;
	GLfloat yf;
	GLfloat win;
	GLint view_w;
	GLint view_h;
	bool* keyStates;
	bool aKeyPressed[4]; // 0 is up, 1 is down, 2 is left and 3 is right
	long long int score;
	bool isRunning;

	vector<Bala*> playerShells_;
	vector<Inimigo*> enemies_;
	vector<Bala*> enemiesShells_;

	list<Objects*> list_;

private:
	void Inicializa (void);
	bool insert_object(void);
	
};

