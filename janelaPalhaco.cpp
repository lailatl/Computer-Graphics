#ifdef __APPLE__ // MacOS
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else // Windows e Linux
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <cstdlib>

#include "circulo.h"
#define ESC 27

//Variaveis Globais usadas para definicao de cores
float R,G,B;


// Declaracoes antecipadas (forward) de funcoes para as funcoes callback do OpenGL
void init(void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void keyboard_special(int key, int x, int y);
void display(void);

/*
 * Funcao principal
 */
int main(int argc, char** argv){
    glutInit(&argc, argv); // Passagens de parametros C para o glut
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // Selecao do Modo do Display e do Sistema de cor utilizado
    glutInitWindowSize (512, 512);  // Tamanho da janela do OpenGL
    glutInitWindowPosition (100, 100); //Posicao inicial da janela do OpenGL
    glutCreateWindow ("Computacao Grafica: Palhaco/OpenGL"); // Da nome para uma janela OpenGL
    init(); // Chama a funcao init();
    glutReshapeFunc(reshape); //funcao callback para redesenhar a tela
    glutDisplayFunc(display); //funcao callback de desenho
    glutKeyboardFunc(keyboard); //funcao callback do teclado
    glutSpecialFunc(keyboard_special);	//funcao callback do teclado especial
    glutMainLoop(); // executa o loop do OpenGL
    return EXIT_SUCCESS; // retorna 0 para o tipo inteiro da funcao main()
}
/*	
 * Funcao que inicializa as cores
 */	
void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0); //Limpa a tela com a cor branca;
    R = 0.0;
    G = 0.0;
    B = 0.0;
}

/*	
 * Funcao que inicializa a janela
 */
void reshape(int w, int h)
{
	// Reinicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    // Definindo o Viewport para o tamanho da janela
	glViewport(0, 0, w, h);
	
	// Definindo a projecao para que o seu centro permaneca no centro da tela
	glOrtho (-(w/2), (w/2),-(h/2),(h/2), -1 ,1); // Quantidade de pixels variavel e de acordo com o tamanho da janela
	
	glMatrixMode(GL_MODELVIEW);
}

// Funcao que controla as teclas comuns do teclado

void keyboard(unsigned char key, int x, int y){
    switch (key) { // key - variavel que possui valor ASCII da tecla precionada
        case ESC: exit(EXIT_SUCCESS); break; //encerra o programa com sucesso
    }
}

// Funcao que controla as teclas especiais

void keyboard_special(int key, int x, int y){
    switch(key){
      case GLUT_KEY_F1: R=0.0; G=0.0; B=1.0; break; // F1: muda a cor para azul
      case GLUT_KEY_F2: R=0.0; G=1.0; B=0.0; break; // F2: muda a cor para verde
      case GLUT_KEY_F3: R=1.0; G=0.0; B=0.0; break; // F3: muda a cor para vermelho
      default: break;
    }
    glutPostRedisplay();
}
/*
 *  Funcao usada para desenhar as formas na janela
 */
void display(void){
	//Limpa o Buffer de Cores e reinicia a matriz
    glClear(GL_COLOR_BUFFER_BIT); 
	glLoadIdentity();

    // Transformacoes usadas no triangulo com vertice esquerdo na origem dos eixos cartesianos
    glColor3f(R, G, B);
//	glScalef(0.5, 0.5, 0);
//	glTranslatef(200,200, 0);
//	glRotatef(180, 0, 0, 1);

// tronco
	glPushMatrix();
 		glColor3f(0, 0, 1);
		glBegin(GL_QUADS);
			glVertex2f(50, 50);
			glVertex2f(-50, 50);
			glVertex2f(-50,-50);
			glVertex2f(50, -50);
		glEnd();	
    glPopMatrix();

// braco direito   
	glPushMatrix();
	glColor3f(1, 0, 0);
		glRotatef(10, 0, 0, 1);
		glTranslatef(111, 20, 0);
    	glBegin(GL_QUADS);
    		glVertex2f(50, 20);
    		glVertex2f(-50, 20);
    		glVertex2f(-50, -20);
    		glVertex2f(50, -20);
        glEnd();
    glPopMatrix();
    
// perna direita  
    glPushMatrix();
	glColor3f(1, 0, 0);
		glRotatef(-70, 0, 0, 1);
		glTranslatef(115, 5, 0);
    	glBegin(GL_QUADS);
    		glVertex2f(50, 25);
    		glVertex2f(-50, 25);
    		glVertex2f(-50, -25);
    		glVertex2f(50, -25);
        glEnd();
    glPopMatrix();

// braco esquerdo	
	glPushMatrix();
		glColor3f(1, 0, 0);
		glRotatef(-10, 0, 0, 1);
		glTranslatef(-111, 20, 0);
    	glBegin(GL_QUADS);
    		glVertex2f(50, 20);
    		glVertex2f(-50, 20);
    		glVertex2f(-50, -20);
    		glVertex2f(50, -20);
        glEnd();
	glPopMatrix();
	
// perna esquerda
    glPushMatrix();
		glColor3f(1, 0, 0);
			glRotatef(250, 0, 0, 1);
			glTranslatef(115, -5, 0);
	    	glBegin(GL_QUADS);
	    		glVertex2f(50, 25);
	    		glVertex2f(-50, 25);
	    		glVertex2f(-50, -25);
	    		glVertex2f(50, -25);
	        glEnd();
   glPopMatrix();

// mao direita
	    glPushMatrix();
		glColor3f(1, 1, 0);
			glTranslatef(170, 50 , 0);
	 	    glRotatef(100, 0, 0, 1);
	    	glBegin(GL_QUADS);
	    		glVertex2f(22.5, 10);
	    		glVertex2f(-22.5, 10);
	    		glVertex2f(-22.5, -10);
	    		glVertex2f(22.5, -10);
	        glEnd();
   glPopMatrix();   

// mao esquerda
	    glPushMatrix();
		glColor3f(1, 1, 0);
			glTranslatef(-170, 50 , 0);
	 	    glRotatef(-100, 0, 0, 1);
	    	glBegin(GL_QUADS);
	    		glVertex2f(22.5, 10);
	    		glVertex2f(-22.5, 10);
	    		glVertex2f(-22.5, -10);
	    		glVertex2f(22.5, -10);
	        glEnd();
   glPopMatrix();   
   
   
// pe direito
	    glPushMatrix();
		glColor3f(1, 1, 0);
			glTranslatef(85, -165 , 0);
	 	    glRotatef(20, 0, 0, 1);
	    	glBegin(GL_QUADS);
	    		glVertex2f(35, 15);
	    		glVertex2f(-35, 15);
	    		glVertex2f(-35, -15);
	    		glVertex2f(35, -15);
	        glEnd();
   glPopMatrix();   

// pe esquerdo
	    glPushMatrix();
		glColor3f(1, 1, 0);
			glTranslatef(-85, -165 , 0);
	 	    glRotatef(160, 0, 0, 1);
	    	glBegin(GL_QUADS);
	    		glVertex2f(35, 15);
	    		glVertex2f(-35, 15);
	    		glVertex2f(-35, -15);
	    		glVertex2f(35, -15);
	        glEnd();
   glPopMatrix(); 

// detalhes do tronco
	glPushMatrix();
	glColor3f(0, 1, 0);
		   desenhaCirculo(10,30,true);
		   glTranslatef(0, 25, 0);
		   desenhaCirculo(10,30,true);
		   glTranslatef(0, -50, 0);
		   desenhaCirculo(10,30,true);	
	glPopMatrix();  

// cabeca
	glPushMatrix();
	glColor3f(1, 1, 0);
		glTranslatef(0, 98, 0);
		desenhaCirculo(45,30, true);
		glColor3f(1, 0, 0);
		desenhaCirculo(10, 30, true);
		glColor3f(0, 0, 0);
		glTranslatef(17, 15, 0);
		desenhaCirculo(7, 30, true);
		glTranslatef(-34, 0, 0);
		desenhaCirculo(7, 30, true);
		// boca
    glColor3f(1, 1, 1);
		glTranslatef(-10, -35, 0);
		desenhaCirculo(5, 30, true);
		glTranslatef(12.5, -7.5, 0);
		desenhaCirculo(5, 30, true);
		glTranslatef(14, -3, 0);
		desenhaCirculo(5, 30, true);
		glTranslatef(15, 3, 0);
		desenhaCirculo(5, 30, true);
		glTranslatef(12.5, 9, 0);
		desenhaCirculo(5, 30, true);
		glColor3f(0, 0, 1);
		glTranslatef(-27, 63, 0);
		glBegin(GL_TRIANGLES);
			glVertex2f(0, 50);
			glVertex2f(50, 0);
			glVertex2f(-50, 0);
			glEnd();
        glColor3f(1, 0, 1);
        glTranslatef(0, 55, 0);
        desenhaCirculo(10, 30, true);
	glPopMatrix();   
	 
// Balao
	glPushMatrix();
		glColor3f(0.75, 0.5, 1);
		glTranslated(20, 0, 0);
		glBegin(GL_LINE_STRIP);
			glVertex2f(150, 50);
			glVertex2f(170, 100);
			glVertex2f(180, 150);
         glEnd();
         glTranslatef(180, 180, 0);
        desenhaCirculo(40, 30, true);
     glPopMatrix();
	


    glFlush(); // manda o OpenGl renderizar as primitivas

}

