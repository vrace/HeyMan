#include "Platform.h"

#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>

#include <memory>

#include "../../Application.h"
#include "OpenGLGraphics.h"
#include "InitGdiplus.h"

static const TCHAR APPLICATION_NAME[] = TEXT("HeyMan");

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwnd;
	WNDCLASS wndclass;
	MSG msg;

	INIT_GDI_PLUS();

	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = APPLICATION_NAME;
	wndclass.lpszMenuName = NULL;
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

	RegisterClass(&wndclass);

	hwnd = CreateWindow(
		APPLICATION_NAME, APPLICATION_NAME, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, SW_NORMAL);
	UpdateWindow(hwnd);

	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	HDC hdc = GetDC(hwnd);
	RECT rc;
	GetClientRect(hwnd, &rc);
	OpenGLGraphics::InitGraphics(hdc, rc);

	theApp = std::make_unique<Application>();
	theApp->Init();
	theApp->SetScreenSize(rc.right - rc.left, rc.bottom - rc.top);

	LARGE_INTEGER freq;
	LARGE_INTEGER counter;

	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&counter);

	for (;;)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				break;
			}
		}
		else
		{
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);

			float delta = (float)((double)(current.QuadPart - counter.QuadPart) / (double)freq.QuadPart);
			counter = current;

			theApp->Update(delta);

			theGraphics->Clear();
			theApp->Render();
			theGraphics->Commit();

			SwapBuffers(hdc);
		}
	}

	ReleaseDC(hwnd, hdc);
	OpenGLGraphics::DestroyGraphics();
	theApp->Destroy();

	return 0;
}

LRESULT WINAPI WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	RECT rc;

	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_SIZE:
		GetClientRect(hwnd, &rc);
		OpenGLGraphics::ResizeViewport(rc);
		if (theApp)
			theApp->SetScreenSize(rc.right - rc.left, rc.bottom - rc.top);
		return 0;

	default:
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
