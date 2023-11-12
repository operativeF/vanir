
#include <windows.h>

import boost.ut;

import Nil.WinDef;
import Nil.Win.UniqueHnd;

import std;

#define WWIN_MAIN int wWinMain(NLHINSTANCE hInstance, NLHINSTANCE hPrevInstance, NLPWSTR pCmdLine, int nCmdShow)

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

WWIN_MAIN
{
        // Register the window class.
    const wchar_t CLASS_NAME[]  = L"Sample Window Class";
    
    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
        );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
            msw::utils::unique_dcpaint painter{hwnd};

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(painter.get_dc(), &(painter.get()->rcPaint), (HBRUSH) (COLOR_HOTLIGHT+1));
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
