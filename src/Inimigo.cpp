// Jogo Asteroids 
// triangle.cpp
// Prof. Giovani Bernardes Vitor
// ECO034 - 2017

#include <stdlib.h>
#include <stdio.h>
#include "Inimigo.hpp"


Inimigo::Inimigo(const double posicX, const double posicY, const int tipoInimigo1 = 0)
{
	theta = 0.0f;
	movement = 5.0;
	x = posicX;
	y = posicY;
	tipo = 'i';
	life = 1000;
	controle = 1;

	tipoEstrutura = tipoInimigo1;

	if(tipoEstrutura < 3)
		limiteTiro = 0;
	else
		limiteTiro = 2;

	points_base[0] = glm::vec3( 20.0f,   -20.0f , 1.0f);
    points_base[1] = glm::vec3( 20.0f,  20.0f , 1.0f);
    points_base[2] = glm::vec3( -20.0f,  20.0f , 1.0f);      
	points_base[3] = glm::vec3( -20.0f,  -20.0f , 1.0f); 

	points[0] = points_base[0];
	points[1] = points_base[1];
	points[2] = points_base[2];
	points[3] = points_base[3]; 


	//if(tipoInimigo == 0){

		y = 300;
		x = -500;
	//}

	transform();

//	std::cout << "inicio: " << glm::to_string(points[0]);
	//points = *point_;

}
//---------------------------------------------------------------------
Inimigo::~Inimigo()
{

}

double Inimigo::getSize()
{
	return 12;
}

//---------------------------------------------------------------------
void Inimigo::update()
{
	bool condicao = false;

	if(tipoEstrutura == 0){ //Elipse Lenta
		limiteTiro++;
		if(limiteTiro>10)
			limiteTiro = 0;

		theta += 0.02;
		x += sin(theta)*10;
		y += cos(theta)*0.5;

	}
 	else if(tipoEstrutura == 1){  //diagonal diagonal
		limiteTiro++;
		if(limiteTiro>20)
			limiteTiro = 0;

		theta += 0.02;
		x += sin(theta)*10;
		y += cos(theta)*0.5;
 	}
 	else if(tipoEstrutura == 2) //diagonal diagonal
 	{
	 		if(x <= -500)
	 			controle = 1;
	 			//x+=10;
	 		else if( x  >= 500)
	 			controle = -1;
	 			//x-=10;
	 		//else{
	 		x += 10*controle;
 			if(limiteTiro >= 10)
 				limiteTiro=0;
 			limiteTiro++;

 	}else if(tipoEstrutura == 3)//central explosivo
 	{
	 		if(x <= -500)
	 			controle = 1;
	 			//x+=10;
	 		else if( x  >= 500)
	 			controle = -1;
	 			//x-=10;
	 		//else{
	 		x += 10*controle;
 			if(limiteTiro >= 10)
 				limiteTiro=0;
 			limiteTiro++;
 		
	 		//}	
 	}


///TIPO 1 - ELIPSE RAPIDA
/*
	theta += 0.05;
	x += (cos(theta)*25);
	y += (sin(theta)*0.5);


*/
///TIPO 2 - ELIPSE LENTA

	transform();
}

//---------------------------------------------------------------------
bool Inimigo::colision(double x, double y, double size)
{
	return (this->x - x) * (this->x - x) + (this->y - y) * (this->y - y) < (getSize() + size) * (getSize() + size);
}

bool Inimigo::isKill(double damage)
{
	life = life - damage;
	if(life <= 0)
		return true;
	return false;
}

//---------------------------------------------------------------------
double Inimigo::getX()
{
	return x;
}

//---------------------------------------------------------------------
double Inimigo::getY()
{
	return y;
}
//---------------------------------------------------------------------
char Inimigo::getTipo()
{
	return tipo;
}

//---------------------------------------------------------------------
int Inimigo::getLimiteTiro(){

	return limiteTiro;
}
//---------------------------------------------------------------------
int Inimigo::getTipoEstrutura(){
	return tipoEstrutura;
}
//---------------------------------------------------------------------
void Inimigo::transform(void)
{

	//glm::vec4 Position = glm::vec4(glm::vec3(0.0), 1.0);
    glm::mat3 Model = glm::mat3(1.0);
    Model[2] = glm::vec3(x, y, 1.0);
	
	
    if(tipoEstrutura >= 3){
	    theta += ((15*3.14)/180);
    	Model[0] = glm::vec3(cos(theta), sin(theta), 0.0);
    	Model[1] = glm::vec3(-sin(theta), cos(theta), 0.0);
    	//x *= theta;
    	//y *= theta;
    }
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
void Inimigo::draw()
{
	glLineWidth(3.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D); /* enable texture mapping */
    if(tipoEstrutura == 0)
	    glBindTexture(GL_TEXTURE_2D, 12); /* bind to our texture, has id of 13 */
    else if(tipoEstrutura < 2)
    	glBindTexture(GL_TEXTURE_2D, 11);
    else
    	glBindTexture(GL_TEXTURE_2D, 10);

	//transform();
	//std::cout << "tes: " << glm::to_string(points[0]);
    glBegin(GL_QUADS);  
		glTexCoord2f(1.0f, 1.0f);glVertex2f(points[0].x,points[0].y);
		glTexCoord2f(1.0f, 0.0f);glVertex2f(points[1].x,points[1].y);
		glTexCoord2f(0.0f, 0.0f);glVertex2f(points[2].x,points[2].y);
		glTexCoord2f(0.0f, 1.0f);glVertex2f(points[3].x,points[3].y);
    glEnd();

	glDisable(GL_TEXTURE_2D);

}
