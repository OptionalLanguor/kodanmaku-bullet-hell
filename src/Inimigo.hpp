#include "Objects.hpp"

class Inimigo: public Objects
{
public:	
	Inimigo(const double posicX, const double posicY, const int tipoInimigo);
	~Inimigo();

	void draw();
	void update();
	double getX();
	double getY();
	char getTipo();
	int getLimiteTiro();
	double getSize();
	bool isKill(double damage);
	bool colision(double x, double y, double size);
	int getTipoEstrutura();

private:
	glm::vec3 points_base[4];
	glm::vec3 points[4];

private:
	void transform(void);

/////
 private:
	double x, y, movement, theta; //**points;
	char tipo; //i inimigo, b bala;
	int limiteTiro;
	char tipoEstrutura;
	double life;
	int controle;
};
