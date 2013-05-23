object Form1: TForm1
  Left = 413
  Top = 179
  AutoScroll = False
  Caption = 'ForegroundWindow'
  ClientHeight = 441
  ClientWidth = 363
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 22
    Width = 325
    Height = 106
    AutoSize = True
    Stretch = True
  end
  object Timer1: TTimer
    Interval = 50
    OnTimer = Timer1Timer
    Left = 332
    Top = 111
  end
end
