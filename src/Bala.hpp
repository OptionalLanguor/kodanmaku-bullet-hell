#include "Objects.hpp"

class Bala public Objects
{
public:	
	Bala();
	~Bala();

	void draw();
	void update(int key);
	void colision(int x, int y);

private:
	glm::vec3 points_base[4];
	glm::vec3 points[4];

private:
	void transform(void);

/////
 private:
	//std::pair<double, double> center, vert1, vert2, vert3;
	double x, y, movement, theta; //**points;

};
