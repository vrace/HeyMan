#include "DummyCamera.h"
#include <iostream>

bool CameraCaptureStart(CameraFeedHandler *cameraFeedHandler)
{
	std::cout << "**** DUMMY CAMERA STARTED ****" << std::endl;
	return true;
}

void CameraCaptureStop(void)
{
	std::cout << "**** DUMMY CAMERA STOPPED ****" << std::endl;
}
