//
//  main.cpp
//  HSRetina
//
//  Created by callum taylor on 03/08/2015.
//  Copyright (c) 2015 satori. All rights reserved.
//

#include "Resolution.h"
int main() {
    Resolution *res = new Resolution(2560, 1600);
    res->Apply();
    sleep(5);
    res->Reset();
    return 0;
}