//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    m_Stream = new TMemoryStream();
}
//---------------------------------------------------------------------------
void TForm1::ScreenCap(int LeftPos, int TopPos, int RightPos, int BottomPos)
{
    int RectWidth,RectHeight;
    HDC SourceDC,DestDC;
    HBITMAP Bhandle;
    Graphics::TBitmap* Bitmap;

    RectWidth = RightPos-LeftPos;
    RectHeight = BottomPos-TopPos;

    SourceDC = CreateDC("DISPLAY","","",NULL);
    DestDC = CreateCompatibleDC(SourceDC);
    Bhandle = CreateCompatibleBitmap(SourceDC,RectWidth,RectHeight);

    SelectObject(DestDC,Bhandle);
    BitBlt(DestDC,0,0,RectWidth,RectHeight,SourceDC,LeftPos,TopPos,SRCCOPY);

    Bitmap = new Graphics::TBitmap();
    Bitmap->Handle = Bhandle;
    Bitmap->SaveToStream(m_Stream);
    m_Stream->Position =0;

    //LeftSize = BmpStream.Size;
    delete Bitmap;

    DeleteDC(DestDC);
    ReleaseDC(Bhandle,SourceDC);
}

void TForm1::Get()
{
    RECT r;
    void*Hnd = GetForegroundWindow();
    if (Hnd == Handle) return;
    GetWindowRect(Hnd,&r);
    if(r.left<0)
        r.left = 0;
    if(r.top<0)
        r.top = 0;
    ScreenCap(r.left,r.top,r.right,r.bottom);
    Image1->Picture->Bitmap->LoadFromStream(m_Stream);
    m_Stream->Clear();
}


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    Timer1->Enabled = false;
    Get();
    Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

