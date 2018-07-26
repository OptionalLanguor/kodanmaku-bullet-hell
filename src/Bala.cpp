// Jogo Asteroids 
// triangle.cpp
// Prof. Giovani Bernardes Vitor
// ECO034 - 2017

#include <stdlib.h>
#include <stdio.h>
#include "Bala.hpp"


Bala::Bala(const double posicX, const double posicY, const bool donoDaBala, const int tipoBala)
{
	dono = donoDaBala;
	tipo = 'b';
	limiteTiro = 0;

	theta = 0.0f;
	if(donoDaBala)	//Quer dizer se o dono e o player
	{
		movement = 35.0;
		damage = 100;
	}
	else
		movement = 5.0;

	tipoEstrutura = tipoBala;
	x = posicX;
	y = posicY;

	controle = 1;
	
	points_base[0] = glm::vec3( 3.0f,   -3.0f , 1.0f);
    points_base[1] = glm::vec3( 3.0f,  3.0f , 1.0f);
    points_base[2] = glm::vec3( -3.0f,  3.0f , 1.0f);      
	points_base[3] = glm::vec3( -3.0f,  -3.0f , 1.0f); 

	points[0] = points_base[0];
	points[1] = points_base[1];
	points[2] = points_base[2];
	points[3] = points_base[3];

	transform();
	//std::cout << "inicio: " << glm::to_string(points[0]);
}
//---------------------------------------------------------------------
Bala::~Bala()
{

}

//---------------------------------------------------------------------
double Bala::getDamage()
{
	return damage;
}

//---------------------------------------------------------------------
double Bala::getSize()
{
	return 4;
}

//---------------------------------------------------------------------
void Bala::update()
{
	if(tipoEstrutura == 0){
		if(dono == true)
			y+=movement;
		else
			y-=movement;
	}
	else if(tipoEstrutura == 1){
		y-=movement*1.5;
		x-=movement;	
	}
	else if(tipoEstrutura == 2){
		y-=movement*1.5;
		x+=movement;	
	}
	else if(tipoEstrutura == 3){
		
		y-=movement;

	}
	else if(tipoEstrutura == 4){
		y+=movement;
		x-=movement;	
	}
	else if(tipoEstrutura == 5){
		y+=movement;
		x+=movement;	
	}
	else if(tipoEstrutura == 6){
		y-=movement;
		x+=movement;	
	}
	else if(tipoEstrutura == 7){
		y-=movement;
		x-=movement;	
	}	
	else if(tipoEstrutura == 8){
		y+=movement;
	}
	else if(tipoEstrutura == 9){
		x-=movement;	
	}
	else if(tipoEstrutura == 10){
		x+=movement;	
	}
	transform();
}

//---------------------------------------------------------------------
void Bala::colision(int x, int y)
{


}

//---------------------------------------------------------------------
double Bala::getX()
{
	return x;
}

//---------------------------------------------------------------------
double Bala::getY()
{
	return y;
}
//---------------------------------------------------------------------
char Bala::getTipo()
{
	return tipo;
}
//---------------------------------------------------------------------
int Bala::getLimiteTiro(){

	return limiteTiro;
}
//---------------------------------------------------------------------
int Bala::getTipoEstrutura(){
	return tipoEstrutura;
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
	if(dono)
		glColor3f(0.0f, 1.0f, 1.0f);
	else
		glColor3f(1.0f, 1.0f, 0.0f);

	//transform();
	//std::cout << "tes: " << glm::to_string(points[0]);
        glBegin(GL_QUADS);  
			glVertex2f(points[0].x,points[0].y);
			glVertex2f(points[1].x,points[1].y);
			glVertex2f(points[2].x,points[2].y);
			glVertex2f(points[3].x,points[3].y);
        glEnd();


}
