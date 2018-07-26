// Jogo Asteroids 
// triangle.cpp
// Prof. Giovani Bernardes Vitor
// ECO034 - 2017

#include <stdlib.h>
#include <stdio.h>
#include "Player.hpp"


Player::Player()
{
	theta = 0.0f;
	movement = 10.0;
	x = y = 0;
	tipo = 'p';
	limiteTiro = 0;
	tipoEstrutura = 0;
	life = 4;

	points_base[0] = glm::vec3( -15.0f,   -11.0f , 1.0f);
    points_base[1] = glm::vec3( 15.0f,  -11.0f , 1.0f);
    points_base[2] = glm::vec3( 0.0f,  32.0f -11.0f , 1.0f);      

	points[0] = points_base[0];
	points[1] = points_base[1];
	points[2] = points_base[2];

	hitboxQuad_base[0] = glm::vec3(  5.0f,   -5.0f , 1.0f);
    hitboxQuad_base[1] = glm::vec3(  5.0f,  5.0f , 1.0f);
    hitboxQuad_base[2] = glm::vec3( -5.0f,  5.0f , 1.0f); 
    hitboxQuad_base[3] = glm::vec3( -5.0f,  -5.0f , 1.0f); 
    
	hitboxQuad[0] = hitboxQuad[0];
	hitboxQuad[1] = hitboxQuad[1];
	hitboxQuad[2] = hitboxQuad[2];
	hitboxQuad[3] = hitboxQuad[3];
	

	//std::cout << "inicio: " << glm::to_string(points[0]);
	y = -300;
	transform();

}

//---------------------------------------------------------------------
Player::~Player()
{

}

//---------------------------------------------------------------------
double Player::getSize()
{
	return 7*0.899;
}

//---------------------------------------------------------------------
void Player::move(char way)
{
	if(way == 'u' && y<400){
		y += movement*0.45;
	}
	if(way == 'd' && y>-400) {
		y -= movement*0.45;
	}
	if(way == 'l' && x>-400) {
		x -= movement*0.6;
	}
	if(way == 'r' && x<400) {
		x += movement*0.6;
	}
}

//---------------------------------------------------------------------
void Player::update()
{
	transform();
}

//---------------------------------------------------------------------
bool Player::colision(double x, double y, double size)
{
	return (this->x - x) * (this->x - x) + (this->y - y) * (this->y - y) < (getSize() + size) * (getSize() + size);
}

void Player::printPosic()
{	
	printf("%f %f\n", x, y);
	for (int i = 0; i < 3; ++i)
	{
		printf("%f ", points[i].x);
		printf("%f ", points[i].y);
		printf("%f\n", points[i].z);
	}
		printf("\n");
}

//---------------------------------------------------------------------
double Player::getX()
{
	return x;
}

//---------------------------------------------------------------------
double Player::getY()
{
	return y;
}

//---------------------------------------------------------------------
char Player::getTipo()
{
	return tipo;
}

//---------------------------------------------------------------------
int Player::getLimiteTiro(){

	return limiteTiro;
}
//---------------------------------------------------------------------
int Player::getTipoEstrutura(){
	return 	tipoEstrutura;
}
//---------------------------------------------------------------------
void Player::fire(double x, double y)
{
}

//---------------------------------------------------------------------
void Player::transform(void)
{
    glm::mat3 Model = glm::mat3(1.0);
    Model[2] = glm::vec3(x, y, 1.0);

	for(int i=0; i < 3; i++)
	{
		points[i] = Model * points_base[i];
		hitboxQuad[i] = Model * hitboxQuad_base[i];
	}
	hitboxQuad[3] = Model * hitboxQuad_base[3];
}

//---------------------------------------------------------------------
void Player::draw()
{
	glLineWidth(3.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D); /* enable texture mapping */
    glBindTexture(GL_TEXTURE_2D, 13); /* bind to our texture, has id of 13 */

	//transform();
	//std::cout << "tes: " << glm::to_string(points[0]);

    glBegin(GL_TRIANGLES);  
		glTexCoord2f(0.0f, 0.0f);glVertex2f(points[0].x,points[0].y);
		glTexCoord2f(1.0f, 0.0f);glVertex2f(points[1].x,points[1].y);
		glTexCoord2f(0.5f, 1.0f);glVertex2f(points[2].x,points[2].y);
    glEnd();
	glDisable(GL_TEXTURE_2D);

    

    //Fazendo o quadrado de hitbox no meio da nave
    glLineWidth(5.0f);
    glColor3f(7.0f, 0.0f, 9.0f);
    glBegin(GL_QUADS);  
			glVertex2f(hitboxQuad[0].x,hitboxQuad[0].y);
			glVertex2f(hitboxQuad[1].x,hitboxQuad[1].y);
			glVertex2f(hitboxQuad[2].x,hitboxQuad[2].y);
			glVertex2f(hitboxQuad[3].x,hitboxQuad[3].y);
        glEnd();
    
}
