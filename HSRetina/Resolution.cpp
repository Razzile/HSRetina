//
//  Resolution.cpp
//  HSRetina
//
//  Created by callum taylor on 03/08/2015.
//  Copyright (c) 2015 satori. All rights reserved.
//

#include "Resolution.h"

Resolution *Resolution::_originalResolution = nullptr;

Resolution *Resolution::CurrentResolution() {
    int num = 0;
    CGSGetCurrentDisplayMode(CGMainDisplayID(), &num);
    
    CGSDisplayMode mode;
    CGSGetDisplayModeDescriptionOfLength(CGMainDisplayID(), num, &mode, sizeof mode);
    Resolution *res = new Resolution(mode.width, mode.height);
    if (!_originalResolution) _originalResolution = res;
    return res;
}

Resolution *Resolution::OriginalResolution() {
    return _originalResolution;
}

Resolution::Resolution(int width, int height)
: _width(width), _height(height) {
    if (_originalResolution == nullptr) {
        _originalResolution = new Resolution();
        int num = 0;
        CGSGetCurrentDisplayMode(CGMainDisplayID(), &num);
        
        CGSDisplayMode mode;
        CGSGetDisplayModeDescriptionOfLength(CGMainDisplayID(), num, &mode, sizeof mode);
        
        _originalResolution->_width = mode.width;
        _originalResolution->_height = mode.height;
    }
}

Resolution::Resolution() = default;

void Resolution::Apply() {
    CGDirectDisplayID display = CGMainDisplayID();
    CGSDisplayMode mode;
    
    int numberOfDisplayModes;
    int displayMode = 0;
    CGSGetNumberOfDisplayModes(display, &numberOfDisplayModes);
    for (int i = 0; i < numberOfDisplayModes; i++) {
        CGSGetDisplayModeDescriptionOfLength(display, i, &mode, sizeof mode);
        if (mode.width == _width || mode.height == _height) {
            displayMode = i;
            break;
        }
    }
    CGSGetDisplayModeDescriptionOfLength(display, displayMode, &mode, sizeof mode);
    mode.width = _width;
    mode.height = _height;
    CGDisplayConfigRef config;
    CGBeginDisplayConfiguration(&config);
    CGSConfigureDisplayMode(config, display, mode.modeNumber);
    CGCompleteDisplayConfiguration(config, kCGConfigurePermanently);
}

void Resolution::Reset() {
    _originalResolution->Apply();
}
