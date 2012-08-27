#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include <cstdlib> 
#include <iostream>

using namespace ci;
using namespace ci::app;
using namespace std;

class CatPictureApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

  private:
	float color1;
	float color2;
	float color3;
	int iteration;
};

void CatPictureApp::setup()
{
	color1 = 1.0;
	color2 = 1.0;
	color3 = 1.0;
	iteration = 0;
};

void CatPictureApp::mouseDown( MouseEvent event )
{
};

void CatPictureApp::update()
{
	if(color1 != 0.0){
	color1 = color1 - 0.015;
	};

	//if(color1 < 0.0){
	//	color1 = 1.0;
	//};

	if(color1 < 0.0 && color2 != 0.0){
	color2 = color2 - 0.015;
	};

	if(color1 < 0.0 && color2 < 0.0 && color3 != 0.0){
	color3 = color3 - 0.015;
	};
	
	if(color1 < 0.0 && color2 < 0.0 && color3 < 0.0){
	color1 = 1.0;
	color2 = 1.0;
	color3 = 1.0;
	iteration = rand() % 6;
	/*iteration = iteration + 1;
	if(iteration == 6){
		iteration = 0;
	};*/
	};

};

void CatPictureApp::draw()
{
	// clear out the window with black
	if(iteration == 0){
	gl::clear( Color( color1, color2, color3 ) ); 
	};

	if(iteration == 3){
	gl::clear( Color( color1, color3, color2 ) ); 
	};

	if(iteration == 1){
	gl::clear( Color( color2, color1, color3 ) ); 
	};

	if(iteration == 4){
	gl::clear( Color( color3, color1, color2 ) ); 
	};

	if(iteration == 2){
	gl::clear( Color( color2, color3, color1 ) ); 
	};

	if(iteration == 5){
	gl::clear( Color( color3, color2, color1 ) ); 
	};
};

CINDER_APP_BASIC( CatPictureApp, RendererGl )
