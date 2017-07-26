// Martin Reddy

#include "rendererfactory.h"

int main(int, char **)
{
	// create the factory object
	RendererFactory *f = new RendererFactory;

	// create an OpenGL renderer
	IRenderer *ogl = f->CreateRenderer("opengl");
	ogl->Render();
	delete ogl;

	// create a Mesa software renderer
	IRenderer *mesa = f->CreateRenderer("mesa");
	mesa->Render();
	delete mesa;

	delete f;
	return 0;
}
