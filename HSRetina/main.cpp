//
//  main.cpp
//  HSRetina
//
//  Created by callum taylor on 03/08/2015.
//  Copyright (c) 2015 satori. All rights reserved.
//

#include "Resolution.h"

void Close();

Resolution *res = nullptr;
int main() {
    atexit(Close);
    res = new Resolution(2560, 1600);
    res->Apply();
    char c;
    c = getchar();
    return 0;
}


void Close() {
    res->Reset();
    delete res;
}