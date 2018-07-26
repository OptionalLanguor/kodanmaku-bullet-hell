// Jogo Asteroids 
// triangle.hpp
// Prof. Giovani Bernardes Vitor
// ECO034 - 2017


#include "Objects.hpp"


/////////////////////////////////////////////////////////////
class Player: public Objects
{
public:	
	Player();
	~Player();

	void draw();
	void update();
	bool colision(double x, double y, double size);
	void fire(double x, double y);
	void move(char way);
	double getX();
	double getY();
	char getTipo();
	int getLimiteTiro();
	double getSize();
	void printPosic();
	int getTipoEstrutura();

private:
	glm::vec3 points_base[3];
	glm::vec3 points[3];
	glm::vec3 hitboxQuad_base[4];
	glm::vec3 hitboxQuad[4];
	
	double x, y, movement, theta; //**points;
	
	char tipo;
	int limiteTiro;
	int tipoEstrutura;
	int life;

	void transform(void);
};


