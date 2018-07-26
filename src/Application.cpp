// Jogo Asteroids 
// application.cpp
// Prof. Giovani Bernardes Vitor
// ECO034 - 2017

#include <cstdlib>
#include <cstdio>
#include "Application.hpp"


///////////////////////////////////////////////////////////////////////
// Application Class
Application::Application(int argc, char** argv)
{
	//int n = 3;
	//cout << " TABULEIRO " << n << "x" << n << endl; 
    inimigoMorto = 0;
	glutInit(&argc,argv);

     	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     	glutInitWindowSize(720,720);
   	glutInitWindowPosition(10,10);
   	glutCreateWindow("ASTEROIDS GAME");
    Inicializa();
}

//---------------------------------------------------------------------
Application::~Application()
{
}
//---------------------------------------------------------------------
void Application::Inicializa (void)
{   
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    insert_object();

    xf=50.0f;
    yf=50.0f;
    win=400.0f;

    if (!loadTGA("texture4.tga", 10))
        printf("texture.tga not found!\n");
    if (!loadTGA("texture3.tga", 11))
        printf("texture.tga not found!\n");
    if (!loadTGA("texture2.tga", 12))
        printf("texture.tga not found!\n");
    if (!loadTGA("texture.tga", 13))
        printf("texture.tga not found!\n");
}


//---------------------------------------------------------------------
//void Application::DisplayFunc()
//{
//	glutDisplayFunc(Application::Desenha);
//}
//---------------------------------------------------------------------

void Application::draw()
{   
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
                   
    glClear(GL_COLOR_BUFFER_BIT);

    player -> draw();
    for(vector<Bala*>::const_iterator it = playerShells_.begin(); it != playerShells_.end( ) ;  ++it)
        (*it)->draw();
    for(vector<Inimigo*>::const_iterator it = enemies_.begin(); it != enemies_.end( ) ;  ++it)
        (*it)->draw();
    for(vector<Bala*>::const_iterator it = enemiesShells_.begin(); it != enemiesShells_.end( ) ;  ++it)
        (*it)->draw();

    //printOnScreen(-win+10, -win+50, 1.0f, 1.0f, 1.0f, 
    //    GLUT_BITMAP_9_BY_15, "Life");

    stringstream ss;
    ss << score;
    printOnScreen(-win+10, -win+25, 1.0f, 1.0f, 1.0f, 
        GLUT_BITMAP_9_BY_15, "Score");
    printOnScreen(-win+100, -win+25, 1.0f, 1.0f, 1.0f, 
        GLUT_BITMAP_9_BY_15, ss.str());


    if(!isRunning)
        printOnScreen(-50, 20, 1.0f, 0.0f, 0.0f, 
        GLUT_BITMAP_9_BY_15, "GAME OVER");
    
    glFlush();
}

//---------------------------------------------------------------------
void Application::resize(GLsizei w, GLsizei h)
{ 
    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);
    view_w = w;
    view_h = h;                   

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-win, win, -win, win);
}
//---------------------------------------------------------------------
/*
    Some GLUT fonts:
        GLUT_BITMAP_8_BY_13
        GLUT_BITMAP_9_BY_15
        GLUT_BITMAP_TIMES_ROMAN_10
        GLUT_BITMAP_TIMES_ROMAN_24
        GLUT_BITMAP_HELVETICA_10
        GLUT_BITMAP_HELVETICA_12
        GLUT_BITMAP_HELVETICA_18
*/
void Application::printOnScreen(double x, double y, float r, float g, float b, void* font, string str)
{
    glColor3f( r, g, b );
    glRasterPos2f(x, y);
    int len, i;
    len = str.size();
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(font, str[i]);
    }
}

//---------------------------------------------------------------------
void Application::keyOperations (void) {  
    if(aKeyPressed[0] == true)
    {
        player -> move('u');   
    }
    if(aKeyPressed[1] == true)
    {
        player -> move('d');  
    }
    if(aKeyPressed[2] == true)
    {
        player -> move('l');   
    }
    if(aKeyPressed[3] == true)
    {
        player -> move('r');   
    }
    if(keyStates['z'] || keyStates['Z'])
    {
        pewPew(player -> getX(), player -> getY(), true, 0);
    }
    if(keyStates['p'] || keyStates['p'])
    {
        //player -> printPosic();
    }
    if(keyStates['p'] || keyStates['p'])
    {
        enemies_.push_back(new Inimigo(0, 0, 0));
        //player -> printPosic();
    }
    
}  

//---------------------------------------------------------------------
void Application::keyUp (unsigned char key, int x, int y) {  
    keyStates[key] = false; // Set the state of the current key to not pressed  
} 

//---------------------------------------------------------------------
void Application::KeyboardHandle(unsigned char key, int x, int y)
{
    keyStates[key] = true;
}
        
//---------------------------------------------------------------------
void Application::MouseHandle(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
         if (state == GLUT_DOWN) {
                  // Troca o tamanho do retângulo, que vai do centro da 
                  // janela até a posição onde o usuário clicou com o mouse
                  //xf = ( (2 * win * x) / view_w) - win;
                  //yf = ( ( (2 * win) * (y-view_h) ) / -view_h) - win;
         }
    //glutPostRedisplay();
}

//---------------------------------------------------------------------
void Application::SpecialKeyHandle(int key, int x, int y)
{
	//(*(list_.begin())) -> movementCheck(key);
    if(key == GLUT_KEY_UP){
        aKeyPressed[0] = true;
    }
    if(key == GLUT_KEY_DOWN) {
        aKeyPressed[1] = true;
    }
    if(key == GLUT_KEY_LEFT) {
        aKeyPressed[2] = true;
    }
    if(key == GLUT_KEY_RIGHT) {
        aKeyPressed[3] = true;
    }
}

void Application::SpecialKeyUpHandle(int key, int x, int y)
{
    //(*(list_.begin())) -> movementCheck(key);
    if(key == GLUT_KEY_UP){
        aKeyPressed[0] = false;
    }
    if(key == GLUT_KEY_DOWN) {
        aKeyPressed[1] = false;
    }
    if(key == GLUT_KEY_LEFT) {
        aKeyPressed[2] = false;
    }
    if(key == GLUT_KEY_RIGHT) {
        aKeyPressed[3] = false;
    }
}

//---------------------------------------------------------------------
void Application::update(int value, void (*func_ptr)(int))
{
    if(!isRunning)
        return;
    keyOperations();

    player -> update();
    for(vector<Bala*>::const_iterator it = playerShells_.begin(); it != playerShells_.end( ) ;  ++it)
    {
        (*it)->update();
    }
    for(vector<Inimigo*>::const_iterator it = enemies_.begin(); it != enemies_.end( ) ;  ++it)
    {
        if(((*it)->getTipo() == 'i') && ((*it)->getLimiteTiro() == 1)){
            pewPew((*(it)) -> getX(), (*(it)) -> getY(), false, ((*it)->getTipoEstrutura()));
            int tamanhoNave = 20;

            if(((*(it))->getTipoEstrutura() == 3)){
                pewPew((*(it)) -> getX()-tamanhoNave, (*(it)) -> getY()+tamanhoNave, false, 4);
                pewPew((*(it)) -> getX()+tamanhoNave, (*(it)) -> getY()+tamanhoNave, false, 5);
                pewPew((*(it)) -> getX()+tamanhoNave, (*(it)) -> getY()-tamanhoNave, false, 6);
                pewPew((*(it)) -> getX()-tamanhoNave, (*(it)) -> getY()-tamanhoNave, false, 7);
                pewPew((*(it)) -> getX(), (*(it)) -> getY()+tamanhoNave, false, 8);
            }
        }

        (*it)->update();
    }
    for(vector<Bala*>::const_iterator it = enemiesShells_.begin(); it != enemiesShells_.end( ) ;  ++it)
    {
        (*it)->update();
    }

    //Colisao com algoritmo trivial O(n^2)
    bool enemyDeleteFlag = false;
    for(vector<Inimigo*>::iterator it = enemies_.begin(); it != enemies_.end( ) ; )
    {
        for(vector<Bala*>::iterator it2 = playerShells_.begin(); it2 != playerShells_.end( ) ;)
        {
            if((*it)->colision((*it2)->getX(), (*it2)->getY(), (*it2)->getSize()) )
            {
                if((*it)->isKill((*it2) -> getDamage()))
                    enemyDeleteFlag = true;
                it2 = playerShells_.erase(it2);
            }
            else
                ++it2;
        }
        if(enemyDeleteFlag)
        {
            score += 5;
            inimigoMorto++;
            it = enemies_.erase(it);
            enemyDeleteFlag = false;

        }
        else
            it++;
    }

    for(int k = 0; k<inimigoMorto; k++ )
    {
        enemies_.push_back(new Inimigo(0,0,rand()%4));
        enemies_.push_back(new Inimigo(0,0,rand()%4));
        enemies_.push_back(new Inimigo(0,0,rand()%4));
    }
    inimigoMorto = 0;
    
    for(vector<Bala*>::iterator it2 = enemiesShells_.begin(); it2 != enemiesShells_.end( ) ; it2++)
    {
        if(player->colision((*it2)->getX(), (*it2)->getY(), (*it2)->getSize()) )
        {
            isRunning = false;
        }
    }


    ///////////------------------------------------------------------------------------------------------
    //Algoritmo que deleta as balas que saem da tela
    for(vector<Bala*>::iterator it = playerShells_.begin(); it != playerShells_.end( ) ;)
    {
        if((*it)-> getX() > win + 50 || (*it)-> getX() < -win - 50 || (*it)-> getY() > win + 50 || (*it)-> getY() < -win - 50)
            it = playerShells_.erase(it);
        else
            it++;
    }

    for(vector<Bala*>::iterator it = enemiesShells_.begin(); it != enemiesShells_.end( ) ;)
    {
        if((*it)-> getX() > win + 50 || (*it)-> getX() < -win - 50 || (*it)-> getY() > win + 50 || (*it)-> getY() < -win - 50)
            it = enemiesShells_.erase(it);
        else
            it++;
    }

	glutPostRedisplay();
	glutTimerFunc(30,func_ptr,time);

}

//---------------------------------------------------------------------
void Application::pewPew(double x, double y, bool donoDaBala, int tipoBala) //Tiro do player
{
    if(donoDaBala)
        playerShells_.push_back(new Bala(x, y+7, donoDaBala, tipoBala));
    else
        enemiesShells_.push_back(new Bala(x, y-5, donoDaBala, tipoBala));    
}

//---------------------------------------------------------------------
bool Application::insert_object(void)
{
    isRunning = true;
    score = 0;

    keyStates = new bool [256];
    for(int i = 0; i<256; i++)
        keyStates[i] = false;

    aKeyPressed[0] = false;
    aKeyPressed[1] = false;
    aKeyPressed[2] = false;
    aKeyPressed[3] = false;

    player = new Player();

    enemies_.push_back(new Inimigo(0,0,3));
    enemies_.push_back(new Inimigo(0,0,0));
    enemies_.push_back(new Inimigo(0,0,1));

	return true;
}