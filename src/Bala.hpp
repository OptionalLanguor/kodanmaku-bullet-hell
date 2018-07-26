#include "Objects.hpp"

class Bala: public Objects
{
public:	
	Bala(const double posicX, const double posicY, bool donoDaBala, int tipoBala);
	~Bala();

	void draw();
	void update();
	void colision(int x, int y);
	double getX();
	double getY();
	char getTipo();
	int getLimiteTiro();
	double getSize();
	double getDamage();
	int getTipoEstrutura();
	glm::vec3* getPoints(){return points_base;}

private:
	glm::vec3 points_base[4];
	glm::vec3 points[4];

private:
	void transform(void);

/////
 private:
	//std::pair<double, double> center, vert1, vert2, vert3;
	double x, y, movement, theta; //**points;
	bool dono; //true é nave, false é inimigo.
	char tipo;
	int limiteTiro;
	int tipoEstrutura;
	int controle;
	double damage;
};
