// Jogo Asteroids 
// Objects.hpp
// Prof. Giovani Bernardes Vitor
// ECO034 - 2017


#ifndef __OBJECTS_HPP__
#define __OBJECTS_HPP__

#include <iostream>
#include <GL/glut.h>

//#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>



/////////////////////////////////////////////////////////////
class Objects
{
public:	
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual double getX() = 0;
	virtual double getY() = 0;
	virtual char getTipo() = 0;
	virtual int getLimiteTiro() = 0;
	virtual double getSize() = 0 ;
	virtual int getTipoEstrutura() = 0;
};


#endif
