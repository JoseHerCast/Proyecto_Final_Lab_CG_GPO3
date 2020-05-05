//Semestre 2017 - 2
//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include <String.h>

#include "cmodel/CModel.h"

//Solo para Visual Studio 2015
#if (_MSC_VER >= 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int velocidad_dia = 1;
bool night=false;
bool lamp = false;
bool door = false;
bool globo = false;
bool nube = false;
bool luna = false;
float Ang_manecilla = 0.0;
float Ang_door = 0.0;
float Ang_globo = 0.0;
float moveNube[3] = {-40.0,0.0,90.0};
float moveLuna[3] = { -200.0,0.0,90.0 };
float rotLuna = 0.0;
char cadena_v [2]= "";
char vel_dia [30]= "";

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

int GLindices[40]={};

GLfloat LightAmbient[] = { 1.0f,1.0f,1.0f, 1.0f }; 			// Ambient Light Values
GLfloat LightPosition[] = { 0.0,0.0,0.0,0.0 };

GLfloat DayLightDiffuse[] = { 0.9f, 0.9f, 0.9f, 1.0f };		// Diffuse Light Values
GLfloat DayLightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };		// Specular Light Values

GLfloat NightLightDiffuse[] = { 0.3f, 0.3f, 0.3f, 1.0f };	// Diffuse Light Values
GLfloat NightLightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };		// Specular Light Values

//Luz de la lampara
GLfloat LampDiffuse[] = { 0.91,1,0.07,1.0};
GLfloat LampPosition[] = {0.0, 0.0, 0.0, 1.0 };
GLfloat LampDirection[] = {0.25,-1.0,0.5};
float LampCutOff = 45.0;
float LampExponent = 5;

//Material del globo terraqueo
GLfloat ArcoDiffuse[] = { 0.85,0.64,0.08, 1.0f };
GLfloat ArcoSpecular[] = { 1.0,1.0,1.0, 1.0 };
GLfloat ArcoShininess[] = { 30.0 };

//Material de la lampara
GLfloat LampDifVer[] = { 0.24,0.74,0.55, 1.0f };//Material color verde
GLfloat LampDifBla[] = { 0.88,0.88,0.88, 1.0f };//Material color blanco
GLfloat LampSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat LampShininess[] = { 30.0 };

GLfloat color_foco1[] = {0.4,0.4,0.4};
GLfloat color_foco2[] = { 0.9,0.9,0.9 };

//Objetos del tipo textura
CTexture t_sky; //Skybox
CTexture t_sky2; //Skybox
CTexture text3;	//Flecha
CTexture t_Street;	//Pavimento
CTexture t_Grass;	//Pasto01
CTexture text6;	//Casa01
CTexture t_Banqueta; //Banqueta
CTexture t_Street2;	//Pavimento
CTexture t_Grass2;	//Pasto01
CTexture t_Banqueta2; //Banqueta
CTexture t_Chair;
CTexture t_Chair2;
CTexture t_Desktop;
CTexture t_Shelf1;
CTexture t_Shelf2;
CTexture t_Cajon;
CTexture t_Cajon2;
CTexture t_Cajon3;
CTexture t_Earth;
CTexture t_Earth2;
CTexture t_Bfront1;
CTexture t_Breverse1;
CTexture t_Bspine1;
CTexture t_Bfront2;
CTexture t_Breverse2;
CTexture t_Bspine2;
CTexture t_Textblock1;
CTexture t_Textblock2;
CTexture t_n_Textblock1;
CTexture t_n_Textblock2;
CTexture t_Table;
CTexture t_Rwood;
CTexture t_Table2;
CTexture t_Rwood2;
CTexture t_Bwall;
CTexture t_Window;
CTexture t_Window2;
CTexture t_Floor;
CTexture t_Roof;
CTexture t_Floor2;
CTexture t_Roof2;
CTexture t_Roofe;
CTexture t_n_Roofe;
CTexture t_Square1;
CTexture t_Square2;
CTexture t_Square3;
CTexture t_Square4;
CTexture t_n_Square;
CTexture t_Books1;
CTexture t_Books2;
CTexture t_Books3;
CTexture t_Books4;
CTexture t_n_Books1;
CTexture t_n_Books2;
CTexture t_n_Books3;
CTexture t_n_Books4;
CTexture t_Wwood;
CTexture t_Draw;
CTexture t_Wwood2;
CTexture t_Draw2;
CTexture t_Night_Wood_Furniture;
CTexture t_n_Cajon;
CTexture t_n_Cajon2;
CTexture t_n_Cajon3;
CTexture t_Bwall2;
CTexture t_n_Window;
CTexture t_n_Window2;
CTexture t_Door;
CTexture t_Door2;
CTexture t_Kintoun;
CTexture t_Kintoun2;
CTexture t_Moon;

//Texturas de la interfaz en pantalla
CTexture clock;
CTexture manecilla;

CFiguras cubo;
CFiguras sky;

//END NEW//////////////////////////////////////////

CFiguras sky_cube;
CFiguras room_cube;
CFiguras Techo;
CFiguras suelo;
CFiguras Chair;
CFiguras Desktop;
CFiguras Librero;
CFiguras Globo;
CFiguras Libro;
CFiguras Mesa;
CFiguras Lampara;
CFiguras Ventana;
CFiguras Cajonera;
CFiguras Puerta;
CFiguras Kintoun;
CFiguras Moon;

//2D GUI
CFiguras Reloj;
CFiguras Manecilla;


CModel Capsule_corp;
CModel Bed;
CModel Car;
CModel F1;
CModel Book;

void Texture_Load() {

	t_sky.LoadTGA("Textures/Sky/sky5.tga");
	t_sky.BuildGLTexture();
	t_sky.ReleaseImage();

	t_sky2.LoadTGA("Textures/Sky/sky6.tga");
	t_sky2.BuildGLTexture();
	t_sky2.ReleaseImage();

	t_Chair.LoadTGA("Textures/Objects/t_wood7.tga");
	t_Chair.BuildGLTexture();
	t_Chair.ReleaseImage();
	GLindices[1] = t_Chair.GLindex;

	t_Chair2.LoadTGA("Textures/Objects/t_wood6.tga");
	t_Chair2.BuildGLTexture();
	t_Chair2.ReleaseImage();
	GLindices[2] = t_Chair.GLindex;

	t_Desktop.LoadTGA("Textures/Objects/t_wood9.tga");
	t_Desktop.BuildGLTexture();
	t_Desktop.ReleaseImage();
	GLindices[3] = t_Desktop.GLindex;

	t_Shelf1.LoadTGA("Textures/Objects/t_wood8.tga");
	t_Shelf1.BuildGLTexture();
	t_Shelf1.ReleaseImage();
	GLindices[4] = t_Shelf1.GLindex;

	t_Shelf2.LoadTGA("Textures/Objects/t_wood10.tga");
	t_Shelf2.BuildGLTexture();
	t_Shelf2.ReleaseImage();
	GLindices[5] = t_Shelf2.GLindex;


	t_Cajon.LoadTGA("Textures/Objects/t_cajon.tga");
	t_Cajon.BuildGLTexture();
	t_Cajon.ReleaseImage();
	GLindices[6] = t_Cajon.GLindex;

	t_Cajon2.LoadTGA("Textures/Objects/t_cajon2.tga");
	t_Cajon2.BuildGLTexture();
	t_Cajon2.ReleaseImage();
	GLindices[7] = t_Cajon2.GLindex;


	t_Cajon3.LoadTGA("Textures/Objects/t_cajon3.tga");
	t_Cajon3.BuildGLTexture();
	t_Cajon3.ReleaseImage();
	GLindices[8] = t_Cajon3.GLindex;


	t_Earth.LoadTGA("Textures/Objects/t_earth.tga");
	t_Earth.BuildGLTexture();
	t_Earth.ReleaseImage();
	GLindices[0] = t_Earth.GLindex;

	t_Bfront1.LoadTGA("Textures/Objects/t_bfront1.tga");
	t_Bfront1.BuildGLTexture();
	t_Bfront1.ReleaseImage();
	GLindices[22] = t_Bfront1.GLindex;

	t_Breverse1.LoadTGA("Textures/Objects/t_breverse1.tga");
	t_Breverse1.BuildGLTexture();
	t_Breverse1.ReleaseImage();
	GLindices[23] = t_Breverse1.GLindex;


	t_Bspine1.LoadTGA("Textures/Objects/t_bspine1.tga");
	t_Bspine1.BuildGLTexture();
	t_Bspine1.ReleaseImage();
	GLindices[24] = t_Bspine1.GLindex;

	t_Textblock1.LoadTGA("Textures/Objects/t_textblock1.tga");
	t_Textblock1.BuildGLTexture();
	t_Textblock1.ReleaseImage();
	GLindices[31] = t_Textblock1.GLindex;

	t_Textblock2.LoadTGA("Textures/Objects/t_textblock2.tga");
	t_Textblock2.BuildGLTexture();
	t_Textblock2.ReleaseImage();
	GLindices[32] = t_Textblock2.GLindex;

	t_Table.LoadTGA("Textures/Objects/t_wood5.tga");
	t_Table.BuildGLTexture();
	t_Table.ReleaseImage();
	GLindices[12] = t_Table.GLindex;

	t_Rwood.LoadTGA("Textures/Objects/t_wood4.tga");
	t_Rwood.BuildGLTexture();
	t_Rwood.ReleaseImage();
	GLindices[13] = t_Rwood.GLindex;

	t_Bwall.LoadTGA("Textures/Objects/t_bwall.tga");
	t_Bwall.BuildGLTexture();
	t_Bwall.ReleaseImage();
	GLindices[9] = t_Bwall.GLindex;

	t_Window.LoadTGA("Textures/Objects/t_window.tga");
	t_Window.BuildGLTexture();
	t_Window.ReleaseImage();
	GLindices[10] = t_Window.GLindex;

	t_Window2.LoadTGA("Textures/Objects/t_window2.tga");
	t_Window2.BuildGLTexture();
	t_Window2.ReleaseImage();
	GLindices[11] = t_Window2.GLindex;

	t_Floor.LoadTGA("Textures/Objects/t_floor.tga");
	t_Floor.BuildGLTexture();
	t_Floor.ReleaseImage();
	GLindices[17] = t_Floor.GLindex;

	t_Roof.LoadTGA("Textures/Objects/t_roof.tga");
	t_Roof.BuildGLTexture();
	t_Roof.ReleaseImage();
	GLindices[18] = t_Roof.GLindex;

	t_Roofe.LoadTGA("Textures/Objects/t_roofe.tga");
	t_Roofe.BuildGLTexture();
	t_Roofe.ReleaseImage();
	GLindices[34] = t_Roofe.GLindex;

	t_Square1.LoadTGA("Textures/Objects/t_square1.tga");
	t_Square1.BuildGLTexture();
	t_Square1.ReleaseImage();
	GLindices[19] = t_Square1.GLindex;

	t_Square2.LoadTGA("Textures/Objects/t_square2.tga");
	t_Square2.BuildGLTexture();
	t_Square2.ReleaseImage();
	GLindices[20] = t_Square2.GLindex;

	t_Square3.LoadTGA("Textures/Objects/t_square3.tga");
	t_Square3.BuildGLTexture();
	t_Square3.ReleaseImage();
	GLindices[21] = t_Square3.GLindex;

	t_Square4.LoadTGA("Textures/Objects/t_n_square.tga");
	t_Square4.BuildGLTexture();
	t_Square4.ReleaseImage();

	t_Books1.LoadTGA("Textures/Objects/t_books1.tga");
	t_Books1.BuildGLTexture();
	t_Books1.ReleaseImage();
	GLindices[25] = t_Books1.GLindex;

	t_Books2.LoadTGA("Textures/Objects/t_books2.tga");
	t_Books2.BuildGLTexture();
	t_Books2.ReleaseImage();
	GLindices[26] = t_Books2.GLindex;

	t_Books3.LoadTGA("Textures/Objects/t_books3.tga");
	t_Books3.BuildGLTexture();
	t_Books3.ReleaseImage();
	GLindices[27] = t_Books3.GLindex;
	
	t_Books4.LoadTGA("Textures/Objects/t_books4.tga");
	t_Books4.BuildGLTexture();
	t_Books4.ReleaseImage();
	GLindices[28] = t_Books4.GLindex;

	t_Wwood.LoadTGA("Textures/Objects/t_wwood.tga");
	t_Wwood.BuildGLTexture();
	t_Wwood.ReleaseImage();
	GLindices[29] = t_Wwood.GLindex;

	t_Draw.LoadTGA("Textures/Objects/t_draw.tga");
	t_Draw.BuildGLTexture();
	t_Draw.ReleaseImage();
	GLindices[30] = t_Draw.GLindex;

	t_Door.LoadTGA("Textures/Objects/t_door.tga");
	t_Door.BuildGLTexture();
	t_Door.ReleaseImage();
	GLindices[33] = t_Door.GLindex;

	t_Kintoun.LoadTGA("Textures/Objects/t_kintoun.tga");
	t_Kintoun.BuildGLTexture();
	t_Kintoun.ReleaseImage();

	t_Kintoun2.LoadTGA("Textures/Objects/t_kintoun2.tga");
	t_Kintoun2.BuildGLTexture();
	t_Kintoun2.ReleaseImage();

	text3.LoadTGA("Textures/city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	t_Street.LoadTGA("Textures/city/pavimento.tga");
	t_Street.BuildGLTexture();
	t_Street.ReleaseImage();
	GLindices[14] = t_Street.GLindex;

	t_Grass.LoadTGA("Textures/city/pasto2.tga");
	t_Grass.BuildGLTexture();
	t_Grass.ReleaseImage();
	GLindices[15] = t_Grass.GLindex;

	text6.LoadTGA("Textures/city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();

	t_Banqueta.LoadTGA("Textures/city/pavimento2.tga");
	t_Banqueta.BuildGLTexture();
	t_Banqueta.ReleaseImage();
	GLindices[16] = t_Banqueta.GLindex;

	t_Moon.LoadTGA("Textures/Objects/t_moon.tga");
	t_Moon.BuildGLTexture();
	t_Moon.ReleaseImage();

	//Texturas de noche

	t_Earth2.LoadTGA("Textures/Objects/t_earth2.tga");
	t_Earth2.BuildGLTexture();
	t_Earth2.ReleaseImage();

	t_Night_Wood_Furniture.LoadTGA("Textures/Objects/t_night_wood_furniture.tga");
	t_Night_Wood_Furniture.BuildGLTexture();
	t_Night_Wood_Furniture.ReleaseImage();

	t_n_Cajon.LoadTGA("Textures/Objects/t_n_cajon.tga");
	t_n_Cajon.BuildGLTexture();
	t_n_Cajon.ReleaseImage();

	t_n_Cajon2.LoadTGA("Textures/Objects/t_n_cajon2.tga");
	t_n_Cajon2.BuildGLTexture();
	t_n_Cajon2.ReleaseImage();

	t_n_Cajon3.LoadTGA("Textures/Objects/t_n_cajon3.tga");
	t_n_Cajon3.BuildGLTexture();
	t_n_Cajon3.ReleaseImage();

	t_Bwall2.LoadTGA("Textures/Objects/t_bwall2.tga");
	t_Bwall2.BuildGLTexture();
	t_Bwall2.ReleaseImage();

	t_n_Window.LoadTGA("Textures/Objects/t_n_window.tga");
	t_n_Window.BuildGLTexture();
	t_n_Window.ReleaseImage();

	t_n_Window2.LoadTGA("Textures/Objects/t_n_window2.tga");
	t_n_Window2.BuildGLTexture();
	t_n_Window2.ReleaseImage();

	t_Table2.LoadTGA("Textures/Objects/t_n_wood5.tga");
	t_Table2.BuildGLTexture();
	t_Table2.ReleaseImage();

	t_Rwood2.LoadTGA("Textures/Objects/t_n_Rwood.tga");
	t_Rwood2.BuildGLTexture();
	t_Rwood2.ReleaseImage();

	t_Street2.LoadTGA("Textures/city/n_pavimento.tga");
	t_Street2.BuildGLTexture();
	t_Street2.ReleaseImage();

	t_Grass2.LoadTGA("Textures/city/n_pasto2.tga");
	t_Grass2.BuildGLTexture();
	t_Grass2.ReleaseImage();

	t_Banqueta2.LoadTGA("Textures/city/n_pavimento2.tga");
	t_Banqueta2.BuildGLTexture();
	t_Banqueta2.ReleaseImage();

	t_Floor2.LoadTGA("Textures/Objects/t_n_floor.tga");
	t_Floor2.BuildGLTexture();
	t_Floor2.ReleaseImage();

	t_Roof2.LoadTGA("Textures/Objects/t_n_roof.tga");
	t_Roof2.BuildGLTexture();
	t_Roof2.ReleaseImage();

	t_n_Roofe.LoadTGA("Textures/Objects/t_n_roofe.tga");
	t_n_Roofe.BuildGLTexture();
	t_n_Roofe.ReleaseImage();

	t_n_Square.LoadTGA("Textures/Objects/t_n_square.tga");
	t_n_Square.BuildGLTexture();
	t_n_Square.ReleaseImage();

	t_Bfront2.LoadTGA("Textures/Objects/t_bfront2.tga");
	t_Bfront2.BuildGLTexture();
	t_Bfront2.ReleaseImage();

	t_Breverse2.LoadTGA("Textures/Objects/t_breverse2.tga");
	t_Breverse2.BuildGLTexture();
	t_Breverse2.ReleaseImage();

	t_Bspine2.LoadTGA("Textures/Objects/t_bspine2.tga");
	t_Bspine2.BuildGLTexture();
	t_Bspine2.ReleaseImage();

	t_n_Books1.LoadTGA("Textures/Objects/t_n_books1.tga");
	t_n_Books1.BuildGLTexture();
	t_n_Books1.ReleaseImage();

	t_n_Books2.LoadTGA("Textures/Objects/t_n_books2.tga");
	t_n_Books2.BuildGLTexture();
	t_n_Books2.ReleaseImage();

	t_n_Books3.LoadTGA("Textures/Objects/t_n_books3.tga");
	t_n_Books3.BuildGLTexture();
	t_n_Books3.ReleaseImage();

	t_n_Books4.LoadTGA("Textures/Objects/t_n_books4.tga");
	t_n_Books4.BuildGLTexture();
	t_n_Books4.ReleaseImage();

	t_Wwood2.LoadTGA("Textures/Objects/t_wwood2.tga");
	t_Wwood2.BuildGLTexture();
	t_Wwood2.ReleaseImage();
	
	t_Draw2.LoadTGA("Textures/Objects/t_draw2.tga");
	t_Draw2.BuildGLTexture();
	t_Draw2.ReleaseImage();

	t_n_Textblock1.LoadTGA("Textures/Objects/t_n_textblock1.tga");
	t_n_Textblock1.BuildGLTexture();
	t_n_Textblock1.ReleaseImage();

	t_n_Textblock2.LoadTGA("Textures/Objects/t_n_textblock2.tga");
	t_n_Textblock2.BuildGLTexture();
	t_n_Textblock2.ReleaseImage();

	t_Door2.LoadTGA("Textures/Objects/t_door2.tga");
	t_Door2.BuildGLTexture();
	t_Door2.ReleaseImage();

	//Texturas de la interfaz en pantalla

	clock.LoadTGA("Textures/GUI/day_night_clock.tga");
	clock.BuildGLTexture();
	clock.ReleaseImage();

	manecilla.LoadTGA("Textures/GUI/manecilla.tga");
	manecilla.BuildGLTexture();
	manecilla.ReleaseImage();

}

void Models_Load() {
	//Cargar el modelo

	Capsule_corp._3dsLoad("Models/Capsule_corp/capsule_corp.3ds");
	Capsule_corp.LoadTextureImages();
	Capsule_corp.GLIniTextures();
	Capsule_corp.ReleaseTextureImages();

	Bed._3dsLoad("Models/Bed/Bed.3ds");
	Bed.LoadTextureImages();
	Bed.GLIniTextures();
	Bed.ReleaseTextureImages();

	Car._3dsLoad("Models/Car/Car.3ds");

	F1._3dsLoad("Models/F1/F1.3ds");

	Book._3dsLoad("Models/Libro/Libro.3ds");
}

void Luces() {
	
	//Luz principal del entorno
	//glLightfv(GL_LIGHT0,GL_AMBIENT,LightAmbient);
	//glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

	if (night==true){

		glLightfv(GL_LIGHT0, GL_DIFFUSE, NightLightDiffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, NightLightSpecular);
		
		glLightfv(GL_LIGHT2, GL_DIFFUSE, LampDiffuse);
		glLightfv(GL_LIGHT2, GL_SPECULAR, NightLightSpecular);
		glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, LampDirection);
		glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, LampCutOff);
		glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, LampExponent);

		
		if (lamp==true) {
			glEnable(GL_LIGHT2);
		}
		else {
			glDisable(GL_LIGHT2);
		}

	}
	else {

		glDisable(GL_LIGHT2);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, DayLightDiffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, DayLightSpecular);
	}


}

void Oscurecer() {
	
	t_Earth.GLindex = t_Earth2.GLindex;
	t_Shelf1.GLindex = t_Shelf2.GLindex = t_Desktop.GLindex = t_Chair2.GLindex = t_Chair.GLindex = t_Night_Wood_Furniture.GLindex;
	t_Cajon.GLindex = t_n_Cajon.GLindex;
	t_Cajon2.GLindex = t_n_Cajon2.GLindex;
	t_Cajon3.GLindex = t_n_Cajon3.GLindex;
	t_Bwall.GLindex = t_Bwall2.GLindex;
	t_Window.GLindex = t_n_Window.GLindex;
	t_Window2.GLindex = t_n_Window2.GLindex;
	t_Table.GLindex = t_Table2.GLindex;
	t_Rwood.GLindex = t_Rwood2.GLindex;
	t_Street.GLindex = t_Street2.GLindex;
	t_Grass.GLindex = t_Grass2.GLindex;
	t_Banqueta.GLindex = t_Banqueta2.GLindex;
	t_Floor.GLindex = t_Floor2.GLindex;
	t_Roof.GLindex = t_Roof2.GLindex;
	t_Roofe.GLindex = t_n_Roofe.GLindex;
	t_Square1.GLindex = t_Square2.GLindex = t_Square3.GLindex = t_n_Square.GLindex;
	t_Bfront1.GLindex = t_Bfront2.GLindex;
	t_Breverse1.GLindex = t_Breverse2.GLindex;
	t_Bspine1.GLindex = t_Bspine2.GLindex;
	t_Books1.GLindex = t_n_Books1.GLindex;
	t_Books2.GLindex = t_n_Books2.GLindex;
	t_Books3.GLindex = t_n_Books3.GLindex;
	t_Books4.GLindex = t_n_Books4.GLindex;
	t_Wwood.GLindex = t_Wwood2.GLindex;
	t_Draw.GLindex = t_Draw2.GLindex;
	t_Textblock1.GLindex = t_n_Textblock1.GLindex;
	t_Textblock2.GLindex = t_n_Textblock2.GLindex;
	t_Door.GLindex = t_Door2.GLindex;

}

void Restaurar_Indice() {
	
	t_Earth.GLindex = GLindices[0];
	t_Chair.GLindex = GLindices[1];
	t_Chair2.GLindex = GLindices[2];
	t_Desktop.GLindex = GLindices[3];
	t_Shelf1.GLindex = GLindices[4];
	t_Shelf2.GLindex = GLindices[5];
	t_Cajon.GLindex = GLindices[6];
	t_Cajon2.GLindex = GLindices[7];
	t_Cajon3.GLindex = GLindices[8];
	t_Bwall.GLindex = GLindices[9];
	t_Window.GLindex = GLindices[10];
	t_Window2.GLindex = GLindices[11];
	t_Table.GLindex = GLindices[12];
	t_Rwood.GLindex = GLindices[13];
	t_Street.GLindex = GLindices[14];
	t_Grass.GLindex = GLindices[15];
	t_Banqueta.GLindex = GLindices[16];
	t_Floor.GLindex = GLindices[17];
	t_Roof.GLindex = GLindices[18];
	t_Square1.GLindex = GLindices[19];
	t_Square2.GLindex = GLindices[20];
	t_Square3.GLindex = GLindices[21];
	t_Bfront1.GLindex = GLindices[22];
	t_Breverse1.GLindex = GLindices[23];
	t_Bspine1.GLindex = GLindices[24];
	t_Books1.GLindex = GLindices[25];
	t_Books2.GLindex = GLindices[26];
	t_Books3.GLindex = GLindices[27];
	t_Books4.GLindex = GLindices[28];
	t_Wwood.GLindex = GLindices[29];
	t_Draw.GLindex = GLindices[30];
	t_Textblock1.GLindex = GLindices[31];
	t_Textblock2.GLindex = GLindices[32];
	t_Door.GLindex = GLindices[33];
	t_Roofe.GLindex = GLindices[34];


}

void Dibuja_suelo ()
{

		glPushMatrix(); //suelo1
			glTranslatef(23.5,0.0,0.0);
			glScalef(40,0.1,7);
			glDisable(GL_LIGHTING);
			suelo.prisma2(t_Street.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //suelo2
			glTranslatef(-23.5,0.0,0.0);
			glScalef(40,0.1,7);
			glDisable(GL_LIGHTING);
			suelo.prisma2(t_Street.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,-49);
			glScalef(87,0.1,87);
			glDisable(GL_LIGHTING);
			suelo.prisma2(t_Grass.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,49);
			glScalef(87,0.1,87);
			glDisable(GL_LIGHTING);
			suelo.prisma2(t_Grass.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Banqueta
			glTranslatef(0.0, 0.0, -4.5);
			glScalef(87, 0.1, 2);
			glDisable(GL_LIGHTING);
			suelo.prisma_r_u(t_Banqueta.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Banqueta
			glTranslatef(0.0, 0.0,4.5);
			glScalef(87, 0.1, 2);
			glDisable(GL_LIGHTING);
			suelo.prisma_r_u(t_Banqueta.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();
}

void Dibuja_Silla() {

	glTranslatef(0.0, 0.0, -15.0);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glRotatef(180, 0.0f, 0.0f, 1.0f);
		glPushMatrix();
			glColor3f(1.0, 1.0, 1.0);
			//Asiento de la silla
			glPushMatrix();
				glRotatef(90, 0.0f, 0.0f, 1.0f);
				glScalef(10.6, 10.6, 1.0);
				Chair.prisma2(t_Chair2.GLindex, t_Chair2.GLindex);
			glPopMatrix();
			//Patas de la silla (Soporte)
			glPushMatrix();
				glTranslatef(0.0, 0.0, -4.66);
				glRotatef(90, 0.0f, 1.0f, 0.0f);
				glScalef(1.0, 1.0, 8.6);
				glPushMatrix();
					glTranslatef(0.0, 4.8, 0.0);
					Chair.prisma2(t_Chair.GLindex, t_Chair.GLindex);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(0.0, -4.8, 0.0);
					Chair.prisma2(t_Chair.GLindex, t_Chair.GLindex);
				glPopMatrix();
			glPopMatrix();
			//Patas de la silla
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 1.0, 6.66);
				glTranslatef(0.0, 0.0, -0.575);
				glPushMatrix();
					glTranslatef(-4.8, -4.8, 0.0);
					Chair.prisma2(t_Chair.GLindex, t_Chair.GLindex);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-4.8, 4.8, 0.0);
					Chair.prisma2(t_Chair.GLindex, t_Chair.GLindex);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(4.8, -4.8, 0.0);
					Chair.prisma2(t_Chair.GLindex, t_Chair.GLindex);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(4.8, 4.8, 0.0);
					Chair.prisma2(t_Chair.GLindex, t_Chair.GLindex);
				glPopMatrix();
			glPopMatrix();
			//Respaldo
			glPushMatrix();
				glTranslatef(0.0, 4.8, 3.83);
				glPushMatrix();
					glTranslatef(4.8, 0.0, 0.0);
					glScalef(1.0, 1.0, 6.66);
					Chair.prisma2(t_Chair.GLindex, t_Chair.GLindex);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-4.8, 0.0, 0.0);
					glScalef(1.0, 1.0, 6.66);
					Chair.prisma2(t_Chair.GLindex, t_Chair.GLindex);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(0.0, -1.0, 2.83);
					glScalef(10.6, 1.0, 3.33);
					glRotatef(90, 0.0, 1.0, 0.0);
					Chair.prisma2(t_Chair2.GLindex, t_Chair2.GLindex);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
}

void Dibuja_Escritorio() {
	glPushMatrix();
		//glScalef(10.0,10.0,10.0);
		glPushMatrix();
			glPushMatrix();
				glTranslatef(0.3, 0.1, 0.0);
				glScalef(0.015, 0.02, 0.02);
				glEnable(GL_LIGHTING);
				Book.GLrender(NULL, _SHADED, 1.0);
				glDisable(GL_LIGHTING);
		glPopMatrix();
			glScalef(1.59, 0.15, 3.18);
			Desktop.prisma2(t_Desktop.GLindex, t_Desktop.GLindex);
		glPopMatrix();
		//Patas
		glPushMatrix();
			glTranslatef(0.72, -0.935, 1.515);
			glScalef(0.15, 1.72, 0.15);
			glRotatef(90, 1.0, 0.0, 0.0);
			glPushMatrix();//
				glTranslatef(-4.8, 0.0, 0.0);
				glScalef(10.6, 1.0, 1.0);
				Desktop.prisma2(t_Desktop.GLindex, t_Desktop.GLindex);
			glPopMatrix();
			glPushMatrix();//
				glTranslatef(0.0, -20.2, 0.0);
				Desktop.prisma2(t_Desktop.GLindex, t_Desktop.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-9.6, -20.2, 0.0);
				Desktop.prisma2(t_Desktop.GLindex, t_Desktop.GLindex);
			glPopMatrix();
			glPushMatrix();//Cajones
				glTranslatef(-4.8, -3.0, 0.0);
				glPushMatrix();
					glTranslatef(0.0, 0.0, 0.25);
					glScalef(10.6, 5.0, 0.5);
					Desktop.prisma2(t_Desktop.GLindex, t_Cajon2.GLindex);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(0.0, 0.0, -0.125);
					glScalef(10.6, 5.0, 0.25);
					Desktop.prisma2(t_Desktop.GLindex, t_Cajon.GLindex);
					glTranslatef(0.0, 0.0, -1);
					Desktop.prisma2(t_Desktop.GLindex, t_Cajon.GLindex);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-2.65, -14.2, -0.96);
					glScalef(5.3, 5.0, 0.25);
					Desktop.prisma2(t_Desktop.GLindex, t_Cajon3.GLindex);
					glTranslatef(0.0, 0.0, -1);
					Desktop.prisma2(t_Desktop.GLindex, t_Cajon3.GLindex);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
		//Librero
		glPushMatrix();
			glTranslatef(-0.4, 1.375, 1.515);
			glRotatef(90, 1.0, 0.0, 0.0);
			glScalef(0.8, 0.15, 2.6);
			glPushMatrix();
				Desktop.prisma2(t_Desktop.GLindex, t_Desktop.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0, -20.2, 0.0);
				Desktop.prisma2(t_Desktop.GLindex, t_Desktop.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-0.4, 1.44, 0.0);
			glPushMatrix();
				glTranslatef(0.3, 0.6, 0.0);
				glRotatef(90, 0.0, 0.0, 1.0);
				glScalef(1.0, 0.1, 2.9);
				glRotatef(90, 0.0, 1.0, 0.0);
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
				Desktop.plano(t_Books4.GLindex);
				glEnable(GL_ALPHA_TEST);
			glPopMatrix();
			glScalef(0.8, 0.15, 2.88);
			Desktop.prisma2(t_Desktop.GLindex, t_Desktop.GLindex);
			glTranslatef(0.0, 7.0, 0.0);
			Desktop.prisma2(t_Desktop.GLindex, t_Desktop.GLindex);
		glPopMatrix();
	glPopMatrix();
}

void Dibuja_Librero() {
	glPushMatrix();
		//Soporte fondo
		glPushMatrix();
			glRotatef(90, 0.0, 0.0, 1.0);
			glScalef(5.8, 0.15, 3.7);
			Librero.prisma2(t_Desktop.GLindex, t_Desktop.GLindex);
		glPopMatrix();
		//Verticales
		glPushMatrix();//Lateral derecho
			glTranslatef(0.475, 0.0, -1.775);
			glRotatef(90, 0.0, 1.0, 0.0);
			glRotatef(90, 0.0, 0.0, 1.0);
			glScalef(5.8, 0.15, 0.8);
			Librero.prisma2(t_Desktop.GLindex, t_Desktop.GLindex);
		glPopMatrix();
		glPushMatrix();//Lateral izquierdo
			glTranslatef(0.475, 0.0, 1.775);
			glRotatef(90, 0.0, 1.0, 0.0);
			glRotatef(90, 0.0, 0.0, 1.0);
			glScalef(5.8, 0.15, 0.8);
			Librero.prisma2(t_Desktop.GLindex, t_Desktop.GLindex);
		glPopMatrix();
		glPushMatrix();//Division de repisas
			glTranslatef(0.475, 0.1125, 0.8125);
			glRotatef(90, 0.0, 1.0, 0.0);
			glRotatef(90, 0.0, 0.0, 1.0);
			glScalef(5.275, 0.15, 0.8);
			Librero.prisma2(t_Desktop.GLindex, t_Desktop.GLindex);
		glPopMatrix();
		//Repisas largas horizontales
		glPushMatrix();
			glTranslatef(0.475, -2.825, 0.0);
			glScalef(0.8, 0.15, 3.4);
			Librero.prisma3(t_Shelf2.GLindex, t_Shelf1.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.475, -2.6, 0.0);
			glPushMatrix();
				glTranslatef(0.3, 0.6, -0.5);
				glRotatef(90, 0.0, 0.0, 1.0);
				glScalef(1.0, 0.1, 2.3);
				glRotatef(90, 0.0, 1.0, 0.0);
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
				Librero.plano(t_Books1.GLindex);
				glEnable(GL_ALPHA_TEST);
			glPopMatrix();
			glScalef(0.8, 0.15, 3.4);
			Librero.prisma3(t_Shelf2.GLindex, t_Shelf1.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.475, 2.825, 0.0);
			glScalef(0.8, 0.15, 3.4);
			Librero.prisma3(t_Shelf2.GLindex, t_Shelf1.GLindex);
		glPopMatrix();
		//Repisas medianas horizontales
		glPushMatrix();
			glTranslatef(0.4, 0.0, -0.5);
			glPushMatrix();
				glTranslatef(0.3, 0.5, 0.0);
				glRotatef(90, 0.0, 0.0, 1.0);
				glScalef(0.8, 0.1, 2.3);
				glRotatef(90, 0.0, 1.0, 0.0);
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
				Librero.plano(t_Books2.GLindex);
				glDisable(GL_ALPHA_TEST);
			glPopMatrix();
			glScalef(0.875, 0.15, 2.475);
			Librero.prisma3(t_Shelf2.GLindex, t_Shelf1.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.4, -1.45, -0.5);
			glScalef(0.875, 0.15, 2.475);
			Librero.prisma3(t_Shelf2.GLindex, t_Shelf1.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.4, 1.45, -0.5);
			glPushMatrix();
			glTranslatef(0.3, 0.5, 0.0);
			glRotatef(90, 0.0, 0.0, 1.0);
			glScalef(0.8, 0.1, 2.3);
			glRotatef(90, 0.0, 1.0, 0.0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			Librero.plano(t_Books3.GLindex);
			glDisable(GL_ALPHA_TEST);
			glPopMatrix();
			glScalef(0.875, 0.15, 2.475);
			Librero.prisma3(t_Shelf2.GLindex, t_Shelf1.GLindex);
		glPopMatrix();
		//Repisas peque�as horizontales
		glPushMatrix();
			glTranslatef(0.4, 0.0, 1.3125);
			glPushMatrix();
				glTranslatef(0.1, 0.07, 0.0);
				glScalef(1.0,1.5,1.5);
				glScalef(0.1,0.1,0.1);
				glEnable(GL_LIGHTING);
				F1.GLrender(NULL,_SHADED,1.0);
				glDisable(GL_LIGHTING);
			glPopMatrix();
			glScalef(0.875, 0.15, 0.85);
			Librero.prisma3(t_Shelf2.GLindex, t_Shelf1.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.4, 1.055, 1.3125);
			glScalef(0.875, 0.15, 0.85);
			Librero.prisma3(t_Shelf2.GLindex, t_Shelf1.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.4, 2.11, 1.3125);
			glScalef(0.875, 0.15, 0.85);
			Librero.prisma3(t_Shelf2.GLindex, t_Shelf1.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.4, -1.055, 1.3125);
			glScalef(0.875, 0.15, 0.85);
			Librero.prisma3(t_Shelf2.GLindex, t_Shelf1.GLindex);
		glPopMatrix();
	glPopMatrix();
}

void Dibuja_Globo() {
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ArcoDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ArcoSpecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, ArcoShininess);
	glPushMatrix();
		glTranslatef(0.0, 2.5, 0.0);
		glPushMatrix();//Eje,globo y arco
			glRotatef(20, 1.0, 0.0, 0.0);
			glPushMatrix();
				glRotatef(90, 0.0, 0.0, 1.0);
				glTranslatef(0.0,0.0,0.1);				
				Globo.arco(1.2, 1.0, 20, 20);
				glPushMatrix();
					glTranslatef(1.1,0.0,-0.075);
					glScalef(0.3,0.15,0.15);
					Globo.prisma2(NULL,NULL);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-1.1, 0.0, -0.075);
					glScalef(0.3, 0.15, 0.15);
					Globo.prisma2(NULL, NULL);
				glPopMatrix();
			glPopMatrix();
			glPushMatrix();
				glRotatef(Ang_globo,0.0,1.0,0.0);
				glRotatef(90,0.0,1.0,0.0);
				glDisable(GL_LIGHTING);
				Globo.esfera(1, 20, 20, t_Earth.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Base
			glTranslatef(0.0,-1.4,0.0);
			Globo.cilindro(0.06,0.2,30,NULL);
			glPushMatrix();
				glScalef(1.0,0.1,1.0);
				Globo.esfera(0.6,20,3,NULL);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

void Dibuja_Libro(CTexture front, CTexture reverse, CTexture spine) {
	glPushMatrix();
		glScalef(0.75,1.0,0.4);
		Libro.prisma2(t_Textblock1.GLindex, t_Textblock2.GLindex);
		glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0,0.0,0.25);
		glScalef(0.9, 1.1, 0.1);
		Libro.prisma2(front.GLindex,front.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-0.4, 0.0, 0.0);
		glScalef(0.1, 1.1, 0.4);
		glRotatef(90,1.0,0.0,0.0);
		glRotatef(180,0.0,1.0,0.0);
		Libro.prisma2(front.GLindex, spine.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0, 0.0, -0.25);
		glScalef(0.9, 1.1, 0.1);
		glRotatef(90,0.0,1.0,0.0);
		Libro.prisma2(front.GLindex, reverse.GLindex);
	glPopMatrix();


}

void Dibuja_Mesa() {
	glPushMatrix();
		Mesa.cilindro(0.1, 0.8, 30, t_Rwood.GLindex);
		glPushMatrix();
			glTranslatef(0.0,0.8,0.0);
			Mesa.cilindro(1,0.1,30,t_Rwood.GLindex);
			glPushMatrix();
				glTranslatef(0.0,0.1,0.0);
				glScalef(1.0,0.1,1.0);
				glScalef(1.0, 0.1, 1.0);
				glRotatef(90, 0.0, 0.0, 1.0);
				glRotatef(90,1.0,0.0,0.0);
				Mesa.esfera(1,30,30,t_Table.GLindex);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0, -0.1, 0.0);
			Mesa.cilindro(0.6, 0.1, 30, t_Rwood.GLindex);
			glPushMatrix();
				glTranslatef(0.0, 0.1, 0.0);
				glScalef(1.0, 0.1, 1.0);
				glScalef(1.0, 0.1, 1.0);
				Mesa.esfera(0.6, 30, 30, t_Rwood.GLindex);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

void Dibuja_Lampara() {
	
	glPushMatrix();

		glPushMatrix();//Brazo
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, LampDifVer);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, LampSpecular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, LampShininess);
			glTranslatef(0.0, 0.51, -0.57);
			glRotatef(60,1.0,0.0,0.0);
			glRotatef(90, 0.0, 0.0, 1.0);
			glScalef(1.0,1.0,1.4);
			Lampara.medio_arco(1.1, 1.05, 40, 20);
		glPopMatrix();

		glPushMatrix();
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, LampDifBla);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, LampSpecular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, LampShininess);
			glTranslatef(0.0, 0.0, 0.625);
			glScalef(1.0, 4.0, 1.0);
			Lampara.torus(0.05, 0.02, 20, 7);
		glPopMatrix();

		glPushMatrix();//Base
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, LampDifVer);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, LampSpecular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, LampShininess);
			glTranslatef(0.0, -0.075, 0.5);
			glScalef(1.0, 0.1, 1.0);
			Lampara.esfera(0.4, 20, 3, NULL);
		glPopMatrix();

		glPushMatrix();//Lampara
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, LampDifVer);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, LampSpecular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, LampShininess);
			glTranslatef(0.0,0.985,0.14);
			glRotatef(45,1.0,0.0,0.0);
			glScalef(1.2,1.0,1.2);
			Lampara.cup(0.2,20,20,NULL);
			glPushMatrix();
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, LampDifBla);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, LampSpecular);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, LampShininess);
				glTranslatef(0.0,0.2,0.0);
				glScalef(0.5,0.5,0.5);
				Lampara.torus(0.1,0.2,40,8);
			glPopMatrix();
			glPushMatrix();
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, LampDifVer);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, LampSpecular);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, LampShininess);
				glTranslatef(0.0,0.215,0.0);
				glScalef(0.6,0.4,0.6);
				Lampara.cup(0.1, 20, 20, NULL);
			glPopMatrix();
			glPushMatrix();
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, LampDifBla);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, LampSpecular);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, LampShininess);
				glTranslatef(0.0,0.1,0.0);
				glDisable(GL_LIGHTING);
				glEnable(GL_COLOR_MATERIAL);
				Lampara.esfera(0.1, 20, 20, NULL);
				glDisable(GL_COLOR_MATERIAL);
				glLightfv(GL_LIGHT2, GL_POSITION, LampPosition);
				glEnable(GL_LIGHTING);
			glPopMatrix();
		glPopMatrix();

	glPopMatrix();
}

void OnScreen_GUI() {

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(-1.0,1.0,-1.0,1.0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glLoadIdentity();

			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			glPushMatrix();
				glTranslatef(0.8, 0.8, 0.0);
				glPushMatrix();
					glTranslatef(0.0,0.0,-0.1);
					glScalef(0.25,0.25,1.0);
					Reloj.texturaGUI(clock.GLindex);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(0.0,0.0,0.1);
					glRotatef(Ang_manecilla, 0.0, 0.0, 1.0);
					glScalef(0.15, 0.15, 1.0);
					Manecilla.texturaGUI(manecilla.GLindex);
				glPopMatrix();
			glPopMatrix();
			glDisable(GL_ALPHA_TEST);

			glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	glEnable(GL_BLEND);
	
	
	Texture_Load();
	

	Models_Load();
	//END NEW//////////////////////////////

	objCamera.Position_Camera(8,2.5f,3, 8,2.5f,0, 0, 1, 0);

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	//Llamar a crear luces

	Luces();

	if (night == true) {
		Oscurecer();
	}
	else {
		Restaurar_Indice();
	}
		
	glPushMatrix();

		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
		glPushMatrix();		
			
			glPushMatrix(); //Se pinta el cielo
				glDisable(GL_LIGHTING);
				if (night == true) {
					sky_cube.skybox(10000.0, 5000.0, 5000.0, t_sky2.GLindex);
				}
				else {
					sky_cube.skybox(10000.0, 5000.0, 5000.0, t_sky.GLindex);
				}
				
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Cuarto
			glTranslatef(0.0,0.01,-11.0);
			glScalef(0.5,0.5,0.5);
				glPushMatrix();
					//Cubo exterior
					glPushMatrix();
						glDisable(GL_LIGHTING);
						glEnable(GL_ALPHA_TEST);
						glAlphaFunc(GL_GREATER,0.1);
						glTranslatef(0.0,5.1,0.0);
						glPushMatrix();//Techo
							glTranslatef(0.1,0.4,0.0);
							glPushMatrix();//Techo lado derecho
								glTranslatef(5.0,8.8,0.0);
								glRotatef(45,0.0,0.0,1.0);
								glScalef(0.5,15.0,23.0);
								glRotatef(-90,1.0,0.0,0.0);
								Techo.prisma_l_o(t_Roofe.GLindex, t_Roofe.GLindex);
							glPopMatrix();
							glPushMatrix();//Techo lado izquierdo
								glTranslatef(-5.25, 8.8, 0.0);
								glRotatef(-45, 0.0, 0.0, 1.0);
								glScalef(0.5, 14.0, 23.0);
								glRotatef(-90, 1.0, 0.0, 0.0);
								Techo.prisma_l_o(t_Roofe.GLindex, t_Roofe.GLindex);
							glPopMatrix();
							glPushMatrix();
								glEnable(GL_COLOR_MATERIAL);
								if (night==false) {
									glColor3f(0.68,0.68,0.68);
								}
								else {
									glColor3f(0.4, 0.4, 0.4);
								}
								glPushMatrix();
									glTranslatef(-0.2,4.6,11.0);
									glScalef(10.5,9.0,0.1);
									glRotatef(30,0.0,1.0,0.0);
									Techo.cono(1.0, 1.0, 3, NULL);
								glPopMatrix();
								glPushMatrix();
									glTranslatef(-0.2, 4.6, -11.0);
									glScalef(10.5, 9.0, 0.1);
									glRotatef(30, 0.0, 1.0, 0.0);
									Techo.cono(1.0, 1.0, 3, NULL);
								glPopMatrix();
								glDisable(GL_COLOR_MATERIAL);
							glPopMatrix();
						glPopMatrix();
						glScalef(18.0,10.0,22.0);
						glRotatef(90, 0.0, 0.0, 1.0);
						room_cube.cubemap(t_Bwall.GLindex,t_Window.GLindex,t_Floor.GLindex,t_Roof.GLindex);
						glDisable(GL_ALPHA_TEST);
						glEnable(GL_LIGHTING);
					glPopMatrix();
					//Pared con marco de madera
					glPushMatrix();
						glTranslatef(3.0,0.0,0.0);
						glPushMatrix();
							glTranslatef(5.5,5.1,0.0);
							glPushMatrix();//Dibuja puerta
								glTranslatef(0.0,0.0,5.47);
								glRotatef(Ang_door, 0.0, 1.0, 0.0);
								glTranslatef(0.0,-0.55,2.65);
								glScalef(1.0, 8.9, 5.7);
								glRotatef(-90,1.0,0.0,0.0);
								glDisable(GL_LIGHTING);
								glEnable(GL_ALPHA_TEST);
								glAlphaFunc(GL_GREATER, 0.7);//Transparencia parcial
								glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
								Puerta.prisma_l_o(t_Chair.GLindex, t_Door.GLindex);
								glDisable(GL_ALPHA_TEST);
								glEnable(GL_LIGHTING);
							glPopMatrix();
							glScalef(0.95,9.95,21.9);
							glRotatef(-90,1.0,0.0,0.0);
							glDisable(GL_LIGHTING);
							glEnable(GL_ALPHA_TEST);
							glAlphaFunc(GL_GREATER, 0.2);
							Ventana.prisma_l_o(t_Bwall.GLindex, t_Window2.GLindex);
							glDisable(GL_ALPHA_TEST);
							glEnable(GL_LIGHTING);
						glPopMatrix();
						//Marco de madera
						glPushMatrix();
							glTranslatef(4.8,0.0,0.0);
							glScalef(0.95,5.9,0.05);
							glRotatef(90, 0.0, 1.0, 0.0);
							glPushMatrix();
								glTranslatef(136,1.0,0.75);
								glDisable(GL_LIGHTING);
								Ventana.prisma_l_o(t_Square1.GLindex,t_Square1.GLindex);
								glEnable(GL_LIGHTING);
							glPopMatrix();
							glPushMatrix();
								glTranslatef(-8.0, 1.0, 0.75);
								glDisable(GL_LIGHTING);
								Ventana.prisma_l_o(t_Square2.GLindex, t_Square2.GLindex);
								glEnable(GL_LIGHTING);
							glPopMatrix();
						glPopMatrix();

						glPushMatrix();
							glTranslatef(4.8, 0.0, 0.0);
							glScalef(0.95, 0.05, 7.2);
							glRotatef(90,1.0,0.0,0.0);
							glRotatef(90, 0.0, 1.0, 0.0);
							glPushMatrix();
								glTranslatef(59, -0.445, 0.74);
								glDisable(GL_LIGHTING);
								Ventana.prisma_l_o(t_Square3.GLindex, t_Square3.GLindex);
								glEnable(GL_LIGHTING);
							glPopMatrix();
							glPushMatrix();
								glTranslatef(177, -0.445, 0.74);
								glDisable(GL_LIGHTING);
								Ventana.prisma_l_o(t_Square4.GLindex, t_Square4.GLindex);
								glEnable(GL_LIGHTING);
							glPopMatrix();
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();

				glPushMatrix();//Se pinta la silla
					glTranslatef(5.5, 1.725, -5.3);
					glScalef(1.75,2.25,1.75);
					glScalef(0.1, 0.1, 0.1);
					glDisable(GL_LIGHTING);
					Dibuja_Silla();
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();//Se pinta el escritorio
					glTranslatef(5.0, 2.675, -9.2);
					glRotatef(-90,0.0,1.0,0.0);
					glScalef(2.0,1.4,1.5);
					glDisable(GL_LIGHTING);
					Dibuja_Escritorio();
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();//Se pinta el librero
					glTranslatef(-1.1, 4.75, -10.6);
					glRotatef(-90, 0.0, 1.0, 0.0);
					glScalef(2.0, 1.6, 1.6);
					glDisable(GL_LIGHTING);
					Dibuja_Librero();
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();//Se pinta el globo terraqueo
					glTranslatef(-1.2, 1.8, -9.5);
					glScalef(0.7,0.7,0.7);
					glRotatef(-90,0.0,1.0,0.0);
					Dibuja_Globo();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.0,0.0,-1.0);
					glPushMatrix();//Se pinta mesa
						glTranslatef(-1.0, 0.3, -2.0);
						glScalef(1.5,2.0,1.5);
						glDisable(GL_LIGHTING);
						Dibuja_Mesa();
						glEnable(GL_LIGHTING);
					glPopMatrix();
					glPushMatrix();//Se pinta libro
						glTranslatef(-1.5, 2.225, -2.0);
						glRotatef(-20, 0.0, 1.0, 0.0);
						glRotatef(90,1.0,0.0,0.0);
						glScalef(1.0,1.0,0.4);
						glDisable(GL_LIGHTING);
						Dibuja_Libro(t_Bfront1, t_Breverse1, t_Bspine1);
						glEnable(GL_LIGHTING);
					glPopMatrix();

					glPushMatrix();//Se carga modelo del carro
						glTranslatef(-0.3, 2.19, -1.8);
						glRotatef(170, 0.0, 1.0, 0.0);
						glScalef(0.02, 0.02, 0.02);
						Car.GLrender(NULL, _SHADED, 1.0);
					glPopMatrix();
				glPopMatrix();

				glPushMatrix();//Se pinta lampara
				if (lamp==true) {
					glColor3fv(color_foco2);
				}
				else {
					glColor3fv(color_foco1);
				}
					glTranslatef(4.25, 2.9, -9.0);
					glScalef(1.5,1.25,1.5);
					glRotatef(-110,0.0,1.0,0.0);
					Dibuja_Lampara();
				glPopMatrix();

				glPushMatrix();//Se pinta cajonera
					glTranslatef(-7.5,2.1,-4.0);
					glScalef(2.5,4.0,5.0);
					glRotatef(-90,1.0,0.0,0.0);
					glRotatef(90,0.0,0.0,1.0);
					glDisable(GL_LIGHTING);
					Cajonera.prisma3(t_Wwood.GLindex,t_Draw.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();//Se carga modelo de la cama
					glDisable(GL_LIGHTING);
					glTranslatef(-5.5,1.6,7.5);
					glScalef(0.4, 0.5,0.4);
					Bed.GLrender(NULL,_SHADED,1.0);
					glEnable(GL_LIGHTING);
				glPopMatrix();

			glPopMatrix();

			glPushMatrix();//Se dibuja_suelo
				glDisable(GL_LIGHTING);
				Dibuja_suelo();
				glEnable(GL_LIGHTING);
			glPopMatrix();
			
			glPushMatrix(); 
				glScalef(7,0.1,7);
				glDisable(GL_LIGHTING);
				suelo.prisma2(t_Street.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();
		
			glPushMatrix();//Se carga modelo capsule corp
				glDisable(GL_LIGHTING);
				glTranslatef(0.0,8.0,42);
				glRotatef(-90, 0.0, 1.0, 0.0);
				glScalef(2.0,2.0,2.0);
					Capsule_corp.GLrender(NULL,_SHADED,1.0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			if (night==false) {
				glPushMatrix();
					glTranslatef(moveNube[0],moveNube[1],moveNube[2]);
					glRotatef(90,0.0,1.0,0.0);
					glScalef(4.0, 2.0, 1.0);
					glDisable(GL_LIGHTING);
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
					Kintoun.esfera(1.0, 10, 10, t_Kintoun.GLindex);
					glPushMatrix();
						glTranslatef(-1.4,0.0,0.0);
						glScalef(1.0,0.7,0.2);
						glRotatef(-90, 1.0, 0.0, 0.0);
						glRotatef(90,0.0,0.0,1.0);
						Kintoun.prisma_l_o(NULL,t_Kintoun2.GLindex);
					glPopMatrix();
					glDisable(GL_ALPHA_TEST);
					glEnable(GL_LIGHTING);
				glPopMatrix();
			}
			else {
				glPushMatrix();
					glTranslatef(moveLuna[0], moveLuna[1], moveLuna[2]);
					glRotatef(rotLuna, 0.0, 1.0, 0.0);
					glRotatef(90, 0.0, 1.0, 0.0);
					glScalef(10.0, 10.0, 10.0);
					glDisable(GL_LIGHTING);
					Moon.esfera(1.0, 15, 15, t_Moon.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();
			}

		glPopMatrix(); 

	glPopMatrix();


	//Aqui se dibuja la GUI en 2D

	OnScreen_GUI();

	//Se pinta el texto con la velocidad del dia
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(0.97, 0.53, 0.09);
	_itoa((velocidad_dia), cadena_v, 10);
	strcpy(vel_dia, "Velocidad del dia X ");
	strcat(vel_dia, cadena_v);
	pintaTexto(-14, 12.0, -14.0, (void*)font, vel_dia);
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void animacion()
{
	//Animación del reloj de dia/noche
	if (Ang_manecilla > -360) {
		Ang_manecilla -= 0.1*velocidad_dia;
		if (Ang_manecilla > -180) {
			night = false;
		}
		else {
			night = true;
		}
	}
	else {
		Ang_manecilla = 0.0;
	}

	//Animación puerta

	if (door == true) {
		if (Ang_door < 90) {
			Ang_door += 2.0;
		}
		else {
			Ang_door += 0.0;
		}
	}
	else {
		if (Ang_door > 0) {
			Ang_door -= 2.0;
		}
		else {
			Ang_door -= 0.0;
		}
	}

	//Animación globo terraqueo

	if (globo==true) {
		if (Ang_globo < 360) {
			Ang_globo += 4.0;
		}
		else {
			Ang_globo = 0.0;
			globo = false;
		}
	}
	else{
		Ang_globo += 0.0;
	}

	//Animación nube voladora.

	if (night==false) {//La nube voladora solo aparece durante el día
		nube = true;
		if (nube == true) {
			moveNube[2] -= 0.1*velocidad_dia;
			moveNube[1] =50+4*sin(moveNube[2]);
		}
	}
	else {
		nube = false;
		moveNube[2] = 90.0;
	}

	//Animación Luna

	if (night==true) {//La nube voladora solo aparece durante el día
		luna = true;
		if (luna == true) {
			moveLuna[2] -= 0.1 * velocidad_dia;
			rotLuna += 0.1;
			moveLuna[1] = 200-pow(moveLuna[2],2)/300;//Trayectoria parabólica
		}
	}
	else {
		luna = false;
		moveLuna[2] = 90.0;
		if (rotLuna > 360) {
			rotLuna = 0.0;
		}
	}

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 20000.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
				objCamera.Move_Camera(CAMERASPEED + 0.2);
				printf("\nCoordenadas de cámara: %f,%f", objCamera.mPos.x, objCamera.mPos.z);

			break;

		case 's':
		case 'S':
				objCamera.Move_Camera(-(CAMERASPEED + 0.2));
				printf("\nCoordenadas de cámara: %f,%f", objCamera.mPos.x, objCamera.mPos.z);

			break;

		case 'a':
		case 'A':
				objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
				printf("\nCoordenadas de cámara: %f,%f", objCamera.mPos.x, objCamera.mPos.z);

			break;

		case 'd':
		case 'D':
				objCamera.Strafe_Camera(CAMERASPEED + 0.4);
				printf("\nCoordenadas de cámara: %f,%f", objCamera.mPos.x, objCamera.mPos.z);
			break;

		case '+':
			if (velocidad_dia > 10) {
				velocidad_dia += 0;
			}
			else {
				velocidad_dia += 1;
			}
			break;

		case '-':
			if (velocidad_dia < 2) {
				velocidad_dia -= 0;
			}
			else {
				velocidad_dia -= 1;
			}
			break;

		case 'l':
		case 'L':
			//Este condicional nos limita el espacio de coordenadas en el cual se puede desatar una acción
			//En este caso el encender/apagar la luz de la lampara de escritorio
			if (objCamera.mPos.x > 1 && objCamera.mPos.x < 4 && objCamera.mPos.z < -12 && objCamera.mPos.z > -15) {
				lamp ^= true;
			}
			break;

		case 'o':
		case 'O':
			//Este condicional nos limita el espacio de coordenadas en el cual se puede desatar una acción
			//En este caso el abrir/cerrar la puerta.
			if (objCamera.mPos.x > 0 && objCamera.mPos.x < 8 && objCamera.mPos.z < -5 && objCamera.mPos.z > -8) {
				door ^= true;
			}
			break;
		case 'r':
		case 'R':
			//Este condicional nos limita el espacio de coordenadas en el cual se puede desatar una acción
			//En este caso el rotar el globo
			if (objCamera.mPos.x > -1 && objCamera.mPos.x < 1 && objCamera.mPos.z < -12 && objCamera.mPos.z > -15) {
				globo ^= true;
			}
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (800, 800);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Final"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );

  glutMainLoop        ( );          // 

  return 0;
}
