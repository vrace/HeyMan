#include "InitGdiplus.h"

InitGdiplus::InitGdiplus()
	: token_()
	, input_()
{
	input_.GdiplusVersion = 1;
	Gdiplus::GdiplusStartup(&token_, &input_, nullptr);
}

InitGdiplus::~InitGdiplus()
{
	Gdiplus::GdiplusShutdown(token_);
}
