//
//  rawlcd.h
//  emu48
//
//  Image-based CalcLCD implementation that draws
//  to a raw internal image rep
//
//  Created by Da Woon Jung on Thu Feb 26 2004.
//  Copyright (c) 2004 dwj. All rights reserved.
//

#import "lcd.h"
#import "MacTypePatch.h"


@interface CalcRawLCD : NSView <CalcLCD>
{
    NSImage *img;
    float    lcdScale;
    DWORD    LcdPattern[16];
    DWORD    KmlColors[64];
    RGBQUAD  LcdColors[8];
    LPBYTE   lcd;
    LPBYTE   graylcd;
    BYTE     Buf[36];
    BOOL     grayscale;
    DWORD    graymask;
}
- (BOOL)isOpaque;
// CalcLCD methods
- (id)initWithScale:(unsigned)aScale colors:(NSDictionary *)aColors;
- (void)UpdateContrast:(unsigned char)byContrast;
- (void)SetGrayscaleMode:(BOOL)bMode;

- (void)UpdateMain;
- (void)UpdateMenu;
- (void)RefreshDisp0;
- (void)WriteToMain:(CalcLCDWriteArgument *)args;
- (void)WriteToMenu:(CalcLCDWriteArgument *)args;
@end
