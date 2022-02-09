
module;

#include <windows.h>

export module Nil.Windows.Styles;

import Utils.Bitfield;

export namespace msw::utils
{

enum class WinStyle
{
    Overlapped = WS_OVERLAPPED, // 0
    Tiled = WS_TILED, // 0
    Border  = WS_BORDER,
    Caption = WS_CAPTION,
    Child   = WS_CHILD,
    ChildWindow = WS_CHILDWINDOW,
    ClipChildren = WS_CLIPCHILDREN,
    ClipSiblings = WS_CLIPSIBLINGS,
    Disabled = WS_DISABLED,
    DlgFrame = WS_DLGFRAME,
    Group = WS_GROUP,
    HScroll = WS_HSCROLL,
    Iconic = WS_ICONIC,
    Maximize = WS_MAXIMIZE,
    MaximizeBox = WS_MAXIMIZEBOX,
    Minimize = WS_MINIMIZE,
    Popup = WS_POPUP,
    // PopupWindow = WS_POPUPWINDOW,
    SizeBox = WS_SIZEBOX,
    SysMenu = WS_SYSMENU,
    TabStop = WS_TABSTOP,
    ThickFrame = WS_THICKFRAME,
    // TiledWindow = WS_TILEDWINDOW,
    Visible = WS_VISIBLE,
    VScroll = WS_VSCROLL // clashes with WS_EX_NOREDIRECTIONBITMAP
};

enum class WinStyleEx
{
    Left, // Default value
    LTRReading = Left, // Default value
    RightScrollbar = LTRReading, // Default value

    DlgModalFrame, // = WS_EX_DLGMODALFRAME
    INVALID_2,
    NoParentNotify = WS_EX_NOPARENTNOTIFY, // 4
    TopMost = WS_EX_TOPMOST, // 8
    AcceptFiles = WS_EX_ACCEPTFILES, // 16
    Transparent = WS_EX_TRANSPARENT, // 32
    MDIChild = WS_EX_MDICHILD, // 64
    ToolWindow = WS_EX_TOOLWINDOW, // 128
    WindowEdge = WS_EX_WINDOWEDGE, // 256
    ClientEdge  = WS_EX_CLIENTEDGE, // 512
    ContextHelp = WS_EX_CONTEXTHELP, // 1024
    // INVALID_2048,
    Right = WS_EX_RIGHT, // 4096
    RTLReading = WS_EX_RTLREADING, // 8192
    LeftScrollBar = WS_EX_LEFTSCROLLBAR, // 16384
    // INVALID_32768,
    ControlParent = WS_EX_CONTROLPARENT, // 65536
    StaticEdge = WS_EX_STATICEDGE, // 131072
    AppWindow   = WS_EX_APPWINDOW, // 262144
    Layered = WS_EX_LAYERED, // 524288
    NoInheritLayout = WS_EX_NOINHERITLAYOUT, // 1048576
    NoRedirectionBitmap = WS_EX_NOREDIRECTIONBITMAP, // 2097152
    LayoutRTL = WS_EX_LAYOUTRTL, // 4194304
    // INVALID_8388608,
    // INVALID_16777216,
    Composited  = WS_EX_COMPOSITED, // 33554432
    // INVALID_67108864,
    NoActivate = WS_EX_NOACTIVATE // 134217728
    // OverlappedWindow = WS_EX_OVERLAPPEDWINDOW,
    // PaletteWindow = WS_EX_PALETTEWINDOW,
};



}; // namespace msw::utils