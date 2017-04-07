// Jogo Asteroids 
// triangle.cpp
// Prof. Giovani Bernardes Vitor
// ECO034 - 2017

#include <stdlib.h>
#include <stdio.h>
#include "Bala.hpp"


Bala::Bala() //Funciona sem "Player::"??
{
	//center = std::make_pair(0.0, 0.0);
	//vert1 = std::make_pair(-2.0, -1.0);
	//vert2 = std::make_pair(0.0, 2.0);
	//vert3 = std::make_pair(2.0, -1.0);
	theta = 0.0f;
	movement = 5.0;

	/*
	points = new double*[3];
	for(int i=0; i<3; i++)
		points[i] = new double[3];
	
	//-2.0, -1.0
	points[0][0] = -2;
	points[1][0] = -1;
	points[2][0] = 1;
	//0.0, 2.0
	points[0][1] = 0;
	points[1][1] = 2;
	points[2][1] = 1;
	//2.0, -1.0
	points[0][2] = 2;
	points[1][2] = -1;
	points[2][2] = 1;

	 Matriz gerada:
	    -2, 0,  2
	    -1, 2, -1
	     1, 1,  1  */

	points_base[0] = glm::vec3( -25.0f,   25.0f , 1.0f);
        points_base[1] = glm::vec3( -15.0f,  25.0f , 1.0f);
        points_base[2] = glm::vec3( -15.0f,  15.0f , 1.0f) ;      
	points_base[3] = glm::vec3( -25.0f,  15.0f , 1.0f) ; 

	points[0] = points_base[0];
	points[1] = points_base[1];
	points[2] = points_base[2];
	points_base[3] = points_base[3] ; 

//	std::cout << "inicio: " << glm::to_string(points[0]);
	//points = *point_;

}
//---------------------------------------------------------------------
Bala::~Bala()
{

}

//---------------------------------------------------------------------
void Bala::update(int key)
{

}

//---------------------------------------------------------------------
void Bala::colision(int x, int y)
{


}

//---------------------------------------------------------------------
void Bala::transform(void)
{

	//glm::vec4 Position = glm::vec4(glm::vec3(0.0), 1.0);
        glm::mat3 Model = glm::mat3(1.0);
        Model[2] = glm::vec3(x, y, 1.0);
	

	//std::cout << "tes: " << glm::to_string(Model[0]) << std::endl;
	//std::cout << "tes: " << glm::to_string(Model[1])<< std::endl;
	//std::cout << "tes: " << glm::to_string(Model[2])<< "\n" << std::endl;
	
        //glm::vec4 Transformed = Model * Position;


	for(int i=0; i < 4; i++)
	{
		points[i] = Model * points_base[i];
	}
}



//---------------------------------------------------------------------
void Bala::draw()
{
	glLineWidth(3.0f);
	glColor3f(1.0f, 0.0f, 0.0f);

	//transform();
	//std::cout << "tes: " << glm::to_string(points[0]);
        glBegin(GL_SQUAD);  
			glVertex2f(points[0].x,points[0].y);
			glVertex2f(points[1].x,points[1].y);
			glVertex2f(points[2].x,points[2].y);
			glVertex2f(points[3].x,points[3].y);
        glEnd();


}
