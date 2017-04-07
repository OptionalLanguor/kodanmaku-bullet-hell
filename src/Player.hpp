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
	void update(int key);
	void colision(int x, int y);

private:
	glm::vec3 points_base[3];
	glm::vec3 points[3];

private:
	void transform(void);

/////
 private:
	//std::pair<double, double> center, vert1, vert2, vert3;
	double x, y, movement, theta; //**points;

};


