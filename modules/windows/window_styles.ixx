
module;

#include <windows.h>

export module Nil.Windows.Styles;

import std.core;
import Utils.Bitfield;
import Utils.BitManip;

export namespace msw::utils
{

namespace nu = nil::utils;

enum class WinStyle
{
    Overlapped   = nu::ValToBitPos(WS_OVERLAPPED), // Default, 0
    Tiled        = nu::ValToBitPos(WS_TILED),      // Default, 0
    // Values 1 - 15 are invalid.
    _init_offset = 16,
    MaximizeBox  = nu::ValToBitPos(WS_MAXIMIZEBOX),
    Group        = nu::ValToBitPos(WS_GROUP),
    SizeBox      = nu::ValToBitPos(WS_SIZEBOX),
    ThickFrame   = nu::ValToBitPos(WS_THICKFRAME), // same as SizeBox
    SysMenu      = nu::ValToBitPos(WS_SYSMENU),
    TabStop      = nu::ValToBitPos(WS_TABSTOP), // same as MaximizeBox
    HScroll      = nu::ValToBitPos(WS_HSCROLL),
    VScroll      = nu::ValToBitPos(WS_VSCROLL), // clashes with WS_EX_NOREDIRECTIONBITMAP
    DlgFrame     = nu::ValToBitPos(WS_DLGFRAME),
    Border       = nu::ValToBitPos(WS_BORDER),
    Maximize     = nu::ValToBitPos(WS_MAXIMIZE),
    ClipChildren = nu::ValToBitPos(WS_CLIPCHILDREN),
    ClipSiblings = nu::ValToBitPos(WS_CLIPSIBLINGS),
    Disabled     = nu::ValToBitPos(WS_DISABLED),
    Visible      = nu::ValToBitPos(WS_VISIBLE),
    Iconic       = nu::ValToBitPos(WS_ICONIC),
    Minimize     = nu::ValToBitPos(WS_MINIMIZE), // same as Iconic
    Child        = nu::ValToBitPos(WS_CHILD),
    ChildWindow  = nu::ValToBitPos(WS_CHILDWINDOW), // same as WS_CHILD
    Popup        = nu::ValToBitPos(WS_POPUP),
    _max_size,
    INVALID_MASK = nu::InvBitmaskRange(0, _init_offset)
    // PopupWindow = WS_POPUPWINDOW, combination
    // TiledWindow = WS_TILEDWINDOW, combination
};

enum class WinStyleEx
{
    Left                = nu::ValToBitPos(WS_EX_LEFT), // Default, 0
    LTRReading          = nu::ValToBitPos(WS_EX_LTRREADING), // Default, 0
    RightScrollbar      = nu::ValToBitPos(WS_EX_RIGHTSCROLLBAR), // Default, 0
    DlgModalFrame       = nu::ValToBitPos(WS_EX_DLGMODALFRAME),
    INVALID_2,
    NoParentNotify      = nu::ValToBitPos(WS_EX_NOPARENTNOTIFY),
    TopMost             = nu::ValToBitPos(WS_EX_TOPMOST),
    AcceptFiles         = nu::ValToBitPos(WS_EX_ACCEPTFILES),
    Transparent         = nu::ValToBitPos(WS_EX_TRANSPARENT),
    MDIChild            = nu::ValToBitPos(WS_EX_MDICHILD),
    ToolWindow          = nu::ValToBitPos(WS_EX_TOOLWINDOW),
    WindowEdge          = nu::ValToBitPos(WS_EX_WINDOWEDGE),
    ClientEdge          = nu::ValToBitPos(WS_EX_CLIENTEDGE),
    ContextHelp         = nu::ValToBitPos(WS_EX_CONTEXTHELP),
    INVALID_12,
    Right               = nu::ValToBitPos(WS_EX_RIGHT),
    RTLReading          = nu::ValToBitPos(WS_EX_RTLREADING),
    LeftScrollBar       = nu::ValToBitPos(WS_EX_LEFTSCROLLBAR),
    INVALID_16,
    ControlParent       = nu::ValToBitPos(WS_EX_CONTROLPARENT),
    StaticEdge          = nu::ValToBitPos(WS_EX_STATICEDGE),
    AppWindow           = nu::ValToBitPos(WS_EX_APPWINDOW),
    Layered             = nu::ValToBitPos(WS_EX_LAYERED),
    NoInheritLayout     = nu::ValToBitPos(WS_EX_NOINHERITLAYOUT),
    NoRedirectionBitmap = nu::ValToBitPos(WS_EX_NOREDIRECTIONBITMAP),
    LayoutRTL           = nu::ValToBitPos(WS_EX_LAYOUTRTL),
    INVALID_24,
    INVALID_25,
    Composited          = nu::ValToBitPos(WS_EX_COMPOSITED),
    INVALID_27,
    NoActivate          = nu::ValToBitPos(WS_EX_NOACTIVATE),
    _max_size,
    INVALID_MASK = nu::InvBitmaskValue(INVALID_2,  INVALID_12, INVALID_16,
                                       INVALID_24, INVALID_25, INVALID_27)
    // OverlappedWindow = WS_EX_OVERLAPPEDWINDOW,
    // PaletteWindow = WS_EX_PALETTEWINDOW,
};

}; // namespace msw::utils