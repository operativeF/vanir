
module;

#include <windows.h>

export module Nil.Windows.Styles;

import Utils.Bitfield;

export namespace msw::utils
{

enum class WinStyle
{
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
    Overlapped = WS_OVERLAPPED,
    Popup = WS_POPUP,
    PopupWindow = WS_POPUPWINDOW,
    SizeBox = WS_SIZEBOX,
    SysMenu = WS_SYSMENU,
    TabStop = WS_TABSTOP,
    ThickFrame = WS_THICKFRAME,
    Tiled = WS_TILED,
    TiledWindow = WS_TILEDWINDOW,
    Visible = WS_VISIBLE,
    VScroll = WS_VSCROLL
};

enum class WinStyleEx
{
    AcceptFiles = WS_EX_ACCEPTFILES,
    AppWindow   = WS_EX_APPWINDOW,
    ClientEdge  = WS_EX_CLIENTEDGE,
    Composited  = WS_EX_COMPOSITED,
    ContextHelp = WS_EX_CONTEXTHELP,
    ControlParent = WS_EX_CONTROLPARENT,
    DlgModalFrame = WS_EX_DLGMODALFRAME,
    Layered = WS_EX_LAYERED,
    LayoutRTL = WS_EX_LAYOUTRTL,
    Left = WS_EX_LEFT,
    LeftScrollBar = WS_EX_LEFTSCROLLBAR,
    LTRReading = WS_EX_LTRREADING,
    MDIChild = WS_EX_MDICHILD,
    NoActivate = WS_EX_NOACTIVATE,
    NoInheritLayout = WS_EX_NOINHERITLAYOUT,
    NoParentNotify = WS_EX_NOPARENTNOTIFY,
    NoRedirectionBitmap = WS_EX_NOREDIRECTIONBITMAP,
    OverlappedWindow = WS_EX_OVERLAPPEDWINDOW,
    PaletteWindow = WS_EX_PALETTEWINDOW,
    Right = WS_EX_RIGHT,
    RightScrollbar = WS_EX_RIGHTSCROLLBAR,
    RTLReading = WS_EX_RTLREADING,
    StaticEdge = WS_EX_STATICEDGE,
    ToolWindow = WS_EX_TOOLWINDOW,
    TopMost = WS_EX_TOPMOST,
    Transparent = WS_EX_TRANSPARENT,
    WindowEdge = WS_EX_WINDOWEDGE
};



}; // namespace msw::utils