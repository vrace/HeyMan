#ifndef HEYMAN_INIT_GDIPLUS_H
#define HEYMAN_INIT_GDIPLUS_H

#include "Platform.h"

class InitGdiplus
{
public:
	InitGdiplus();
	~InitGdiplus();

private:
	ULONG_PTR token_;
	Gdiplus::GdiplusStartupInput input_;
};

#define INIT_GDI_PLUS() InitGdiplus _init_gdi_plus

#endif
