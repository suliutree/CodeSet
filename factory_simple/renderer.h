// Martin Reddy

#ifndef RENDERER_H
#define RENDERER_H

#include <string>

///
/// An abstract interface for a 3D renderer.
///
class IRenderer
{
public:
	virtual ~IRenderer() {}
	virtual bool LoadScene(const std::string &filename) = 0;
	virtual void SetViewportSize(int w, int h) = 0;
	virtual void SetCameraPos(double x, double y, double z) = 0;
	virtual void SetLookAt(double x, double y, double z) = 0;
	virtual void Render() = 0;
};

#endif
