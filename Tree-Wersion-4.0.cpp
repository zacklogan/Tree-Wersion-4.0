// Made by Arturo Guerra
// Twitter @ar2roguerra
// Facebook @arturoguerra360
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;
int	nRandWidth = 150, nRandHeight = 15, nSpeed = 1;
int	nScreenWidth, nScreenHeight;
LRESULT WINAPI MelterProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmdLine, int nShowCmd);



// Main Function Starts Here
int main()
{
	int x1 = 1;
	cout << "Wirus scan started, please wait for scan to complete. \n";
	Sleep(3000);
	system("cls");
	{
		system("color 4");
		{
			while (x1 <= 456460) //while function that will restart the fake scan 
			{
				cout << "Scaning Sector " << x1 << " out of 456460\n";
				x1 = x1 + 50;  // While function continue or restart trigger
			}
		}
		{  // fake scan result 
			system("color A");
			system("cls");
			cout << "Scan Complete!! Wiew results below!!\n";
			cout << "   _________________________\n";
			cout << "   |    Wirus found  -0-    |\n";
			cout << "   |   Malware Found -0-    |\n";
			cout << "   |  Koobface Not Detected |\n";
			cout << "   |  Scammers Found -1-!!  |\n";
			cout << "   |   Rundll32  Clean!!    |\n";
			cout << "   |________________________|\n";
			cout << endl;
			cout << "Your dextop is clean thank u for using tree scam!!!\n";
			Sleep(5000);
		}
		{ // Last lines before program exits 
			cout << "\n \n";
			cout << "Thank you for using tree system scan!! The scan utility will close in 5 seconds.";
			Sleep(5000);
			WinMain(0, 0, 0, 0);
		}
	}
}

LRESULT WINAPI MelterProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_CREATE:
	{
		HDC hdcDesktop = GetDC(HWND_DESKTOP);
		HDC hdcWindow = GetDC(hWnd);
		BitBlt(hdcWindow, 0, 0, nScreenWidth, nScreenHeight, hdcDesktop, 0, 0, SRCCOPY);
		ReleaseDC(hWnd, hdcWindow);
		ReleaseDC(HWND_DESKTOP, hdcDesktop);
		SetTimer(hWnd, 0, nSpeed, NULL);
		ShowWindow(hWnd, SW_SHOW);
	}
	return 0;
	case WM_ERASEBKGND:
		return 0;
	case WM_PAINT:
		ValidateRect(hWnd, NULL);
		return 0;
	case WM_TIMER:
	{
		HDC hdcWindow = GetDC(hWnd);
		int	nXPos = (rand() % nScreenWidth) - (nRandWidth / 2),
			nYPos = (rand() % nRandHeight),
			nWidth = (rand() % nRandWidth);
		BitBlt(hdcWindow, nXPos, nYPos, nWidth, nScreenHeight, hdcWindow, nXPos, 0, SRCCOPY);
		ReleaseDC(hWnd, hdcWindow);
	}
	return 0;
	case WM_CLOSE:
	case WM_DESTROY:
	{
		KillTimer(hWnd, 0);
		PostQuitMessage(0);
	}
	return 0;
	}
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmdLine, int nShowCmd)
{
	nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	nScreenHeight = GetSystemMetrics(SM_CYSCREEN);

	WNDCLASS wndClass = { 0, MelterProc, 0, 0, hInstance, NULL, LoadCursor(NULL, IDC_ARROW), 0, NULL, "Melter" };
	if (!RegisterClass(&wndClass)) return MessageBox(HWND_DESKTOP, "Cannot register class!", NULL, MB_ICONERROR | MB_OK);

	HWND hWnd = CreateWindow("Melter", NULL, WS_POPUP, 0, 0, nScreenWidth, nScreenHeight, HWND_DESKTOP, NULL, hInstance, NULL);
	if (!hWnd) return MessageBox(HWND_DESKTOP, "Cannot create window!", NULL, MB_ICONERROR | MB_OK);

	srand(GetTickCount());
	MSG Msg = { 0 };
	while (Msg.message != WM_QUIT)
	{
		if (PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
		if (GetAsyncKeyState(VK_F1) & GetAsyncKeyState(VK_ESCAPE) & 0x8000)
			DestroyWindow(hWnd);
	}
	return 0;
}
