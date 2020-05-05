//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;

	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Func�on creacion esfera
	void cilindro(float radio, float altura, int resolucion, GLuint text);	//Func�on creacion cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Func�on creacion cono
	void cubemap(GLuint text, GLuint text2, GLuint text3, GLuint text4);
	void prisma (float altura, float largo, float profundidad, GLuint text);//Func�on creacion prisma
	void prisma2(GLuint text, GLuint text2);
	void prisma_r_u(GLuint text, GLuint text2);
	void prisma_l_o(GLuint text, GLuint text2);
	void prisma3(GLuint text, GLuint text2);
	void plano(GLuint text);
	void skybox(float altura, float largo, float profundidad, GLuint text);
	void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);
	void arco(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);
	void medio_arco(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);
	void cup(GLfloat radio, int meridianos, int paralelos, GLuint text);
	void texturaGUI(GLuint text);

};
