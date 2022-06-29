module;

#include <windows.h>

#include <CommCtrl.h>
#include <Uxtheme.h>

export module Nil.WinDef;

export
{

using NLHACCEL       = HACCEL;
using NLHBITMAP      = HBITMAP;
using NLHBRUSH       = HBRUSH;
using NLHCURSOR      = HCURSOR;
using NLHANDLE       = void*;
using NLHDC          = HDC;
using NLHENHMETAFILE = HENHMETAFILE;
using NLHFONT        = HFONT;
using NLHGLRC        = HGLRC;
using NLHICON        = HICON;
using NLHINSTANCE    = HINSTANCE;
using NLHMENU        = HMENU;
using NLHMODULE      = NLHINSTANCE;
using NLHPALETTE     = HPALETTE;
using NLHPEN         = HPEN;
using NLHRGN         = HRGN;
using NLHWND         = HWND;
using NLHTHEME       = HTHEME;

using NLHIMAGELIST   = HIMAGELIST;
using NLHGLOBAL      = HGLOBAL;

using NLDPI_AWARENESS_CONTEXT = DPI_AWARENESS_CONTEXT;

using NLWidget    = NLHWND;

using NLLPARAM    = LPARAM;
using NLWPARAM    = WPARAM;
using NLLRESULT   = LRESULT;
using NLHRESULT   = HRESULT;

using NLBOOL      = BOOL;
using NLUINT      = UINT;
using NLWORD      = WORD;
using NLDWORD     = DWORD;

using NLDWORD_PTR = DWORD_PTR;
using NLPWSTR     = PWSTR;

using NLDRAWITEMSTRUCT    = void*;
using NLMEASUREITEMSTRUCT = void*;
using NLLPCREATESTRUCT    = void*;

using NLTASKDIALOG_BUTTON = TASKDIALOG_BUTTON;
using NLTASKDIALOGCONFIG  = TASKDIALOGCONFIG;

inline constexpr auto NLDLGC_WANTARROWS = DLGC_WANTARROWS;
inline constexpr auto NLWM_GETDLGCODE   = WM_GETDLGCODE;

using NLMSG = MSG;

typedef NLLRESULT (_stdcall *NLWNDPROC)(NLHWND, NLUINT, NLWPARAM, NLLPARAM);

} // export