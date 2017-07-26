// Martin Reddy

#ifndef RENDERERFACTORY_H
#define RENDERERFACTORY_H

#include "renderer.h"
#include <string>

///
/// A factory object that creates instances of different
/// 3D renderers.
///
class RendererFactory
{
public:
	/// Create a new instance of a named 3D renderer.
	/// type can be one of "opengl", "directx", or "mesa"
	IRenderer *CreateRenderer(const std::string &type);
};

#endif
