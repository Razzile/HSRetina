//
//  DylibMain.cpp
//  HSRetina
//
//  Created by callum taylor on 04/08/2015.
//  Copyright (c) 2015 satori. All rights reserved.
//

#include "Resolution.h"

Resolution *res = nullptr;

__attribute__((constructor))
void Init() {
    res = new Resolution(2560, 1600);
    res->Apply();
}

__attribute__((destructor))
void Exit() {
    res->Reset();
    delete res;
}