//
//  Resolution.h
//  HSRetina
//
//  Created by callum taylor on 03/08/2015.
//  Copyright (c) 2015 satori. All rights reserved.
//

#ifndef __HSRetina__Resolution__
#define __HSRetina__Resolution__

#include <CoreGraphics/CoreGraphics.h>

typedef struct {
    uint32_t modeNumber;
    uint32_t flags;
    uint32_t width;
    uint32_t height;
    uint32_t depth;
    uint8_t unknown[170];
    uint16_t freq;
    uint8_t more_unknown[16];
    float density;
} CGSDisplayMode;

extern "C" {
    void CGSGetCurrentDisplayMode(CGDirectDisplayID display, int *modeNum);
    void CGSConfigureDisplayMode(CGDisplayConfigRef config, CGDirectDisplayID display, int modeNum);
    void CGSGetNumberOfDisplayModes(CGDirectDisplayID display, int *nModes);
    void CGSGetDisplayModeDescriptionOfLength(CGDirectDisplayID display, int idx, CGSDisplayMode *mode, int length);
}

class Resolution {
public:
    static Resolution *CurrentResolution();
    static Resolution *OriginalResolution();
    
    Resolution(int width, int height);
    
    void Apply();
    void Reset();
private:
    Resolution();
    int _height;
    int _width;
    static Resolution *_originalResolution;
};

#endif /* defined(__HSRetina__Resolution__) */
