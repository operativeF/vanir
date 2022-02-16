module;

#include <windows.h>

#include <consoleapi.h>
#include <handleapi.h>
#include <WinUser.h>
#include <wingdi.h>
#include <Uxtheme.h>

export module Nil.Win.UniqueHnd;

import Nil.WinDef;

import std.core;

namespace
{

// TODO: Use concepts
// Must satisfy NullablePtr.
// Must satisfy construction from other handle types.
struct WndHandleDeleter
{
    using pointer = NLHANDLE;

    void operator()(NLHANDLE h) noexcept { ::CloseHandle(h); }
};

struct WndWindowDeleter
{
    using pointer = NLHWND;

    void operator()(NLHWND h) noexcept { ::DestroyWindow(h); }
};

template<typename GDIObjT>
struct WndGDIObjDeleter
{
    using pointer = GDIObjT;

    void operator()(GDIObjT h) noexcept { ::DeleteObject(h); }
};

struct WndConsoleDeleter
{
    using pointer = NLHANDLE;
    
    // TODO: Mark variable unused?
    void operator()() noexcept { ::FreeConsole(); }
};

struct WndMenuDeleter
{
    using pointer = NLHMENU;

    void operator()(NLHMENU h) noexcept { ::DestroyMenu(h); }
};

struct WndCursorDeleter
{
    using pointer = NLHCURSOR;

    void operator()(NLHCURSOR h) noexcept { ::DestroyCursor(h); }
};

struct WndDCDeleter
{
    using pointer = NLHDC;

    void operator()(HDC h) noexcept { ::DeleteDC(h); }
};

struct WndGLRCDeleter
{
    using pointer = NLHGLRC;

    void operator()(NLHGLRC h) noexcept { ::wglDeleteContext(h); }
};

struct WndAccelDeleter
{
    using pointer = NLHACCEL;

    void operator()(NLHACCEL h) noexcept { ::DestroyAcceleratorTable(h); }
};

struct WndIconDeleter
{
    using pointer = NLHICON;

    void operator()(NLHICON h) noexcept { ::DestroyIcon(h); }
};

struct WndEnhMetafileDeleter
{
    using pointer = NLHENHMETAFILE;

    void operator()(NLHENHMETAFILE h) noexcept { ::DeleteEnhMetaFile(h); }
};

struct WndHdcWndDeleter
{
    using pointer = NLHDC;

    void operator()(NLHDC hDC) noexcept { ::ReleaseDC(nullptr, hDC); };
};

struct WndHdcPaintDeleter
{
    using pointer = NLHDC;

    void operator()(NLHWND hWnd, const PAINTSTRUCT* lpPaint) noexcept { ::EndPaint(hWnd, lpPaint); };
};

struct WndThemeDeleter
{
    using pointer = NLHTHEME;

    void operator()(NLHTHEME h) noexcept { ::CloseThemeData(h); }
};

} // namespace anonymous

export namespace msw::utils
{

using unique_handle      = std::unique_ptr<NLHANDLE, WndHandleDeleter>;
using unique_wnd         = std::unique_ptr<NLHWND, WndWindowDeleter>;
using unique_console     = std::unique_ptr<NLHANDLE, WndConsoleDeleter>;
using unique_menu        = std::unique_ptr<NLHMENU, WndMenuDeleter>;
using unique_cursor      = std::unique_ptr<NLHCURSOR, WndCursorDeleter>;
using unique_dc          = std::unique_ptr<NLHDC, WndDCDeleter>;
using unique_glrc        = std::unique_ptr<NLHGLRC, WndGLRCDeleter>;
using unique_accel       = std::unique_ptr<NLHACCEL, WndAccelDeleter>;
using unique_icon        = std::unique_ptr<NLHICON, WndIconDeleter>;
using unique_enhmetafile = std::unique_ptr<NLHENHMETAFILE, WndEnhMetafileDeleter>;
using unique_dcwnd       = std::unique_ptr<NLHDC, WndHdcWndDeleter>;
using unique_dcpaint     = std::unique_ptr<NLHDC, WndHdcPaintDeleter>;
using unique_theme       = std::unique_ptr<NLHTHEME, WndThemeDeleter>;

template<typename GDIObjT>
using unique_gdiobj  = std::unique_ptr<GDIObjT, WndGDIObjDeleter<GDIObjT>>;

using unique_palette  = unique_gdiobj<NLHPALETTE>;
using unique_brush    = unique_gdiobj<NLHBRUSH>;
using unique_bitmap   = unique_gdiobj<NLHBITMAP>;
using unique_font     = unique_gdiobj<NLHFONT>;
using unique_pen      = unique_gdiobj<NLHPEN>;
using unique_region   = unique_gdiobj<NLHRGN>;

} // export namespace msw::utils
