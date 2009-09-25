//
//  CalcView.h
//  emu48
//
//  A container for the calc background, lcd, annunciators,
//  and button redrawing operations. This is the calc UI.
//
//  Created by Da Woon Jung on Wed Feb 18 2004.
//  Copyright (c) 2004 dwj. All rights reserved.
//
#import "lcd.h"
#import "MacWinAPIPatch.h"


@interface CalcView : NSView
{
    CalcPoint mainBitmapOrigin;
    CalcImage *mainBitmap;
    NSView<CalcLCD> *lcd;	// may be initialized with different kinds of lcds
    NSTimer *uLcdTimerId;
    NSTimer *bwLcdTimer;
    LARGE_INTEGER    lLcdRef;			// reference time for VBL counter
    CalcRect annunciatorOn[6];
    CalcRect annunciatorOff[6];
    BOOL     annunciatorStates[6];
    BOOL     drawingButtonPressed;
    UINT     drawingButtonType;
    CalcRect drawingButtonRect;
    CalcRect drawingButtonRectPressed;
}
+ (CalcImage *)CreateMainBitmap:(NSString *)filename;
//- (void)setMainBitmapOrigin:(NSPoint)aOrigin;
- (void)setMainBitmap:(CalcImage *)aImage atOrigin:(CalcPoint)aOrigin;
- (CalcImage *)mainBitmap;

- (void)setLCD:(NSView<CalcLCD> *)lcd  atOrigin:(CalcPoint)origin;
- (void)setLcdGrayscaleMode:(BOOL) isGrayscale;
- (void)setAnnunciatorRect:(CalcRect)aRect atIndex:(int)nId isOn:(BOOL)isOn;

// Starts periodic LCD updates
- (void)StartDisplay:(NSNumber *)byInitial;
- (void)StopDisplay;
// Called by the engine, passed on to the lcd
- (void)UpdateDisplayPointers;
- (void)UpdateMainDisplay;
- (void)UpdateMenuDisplay;
- (void)RefreshDisp0;
- (void)WriteToMain:(CalcLCDWriteArgument *)args;
- (void)WriteToMenu:(CalcLCDWriteArgument *)args;
- (void)UpdateAnnunciators;

- (void)buttonDrawing;
@end
