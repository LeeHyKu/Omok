/*
 * omok.h: declare game object, method, etc..
 * Copyright (C) 2021 Hyun-Ku Lee
 *
 * This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef AKAGI
#define AKAGI
#include <stdio.h>
#include <stdlib.h>

#include "cset.h"
#include "player.h"
#include "panel.h"
#include "vector.h"

typedef struct
{
    int     siz; //panel size
    int     end;
    short** pan;
    Vector* ptr;
    Player* ein;
    Player* zwi;
    int     win; //0: no; 1: yes, ein is win; 2: yes, zwi is win
    int     trn;

} Omok;

typedef enum
{
    UP,
    LE, //LEFT
    DN, //DOWN
    RI, //RIGHT
    SU //SUBMIT
} Action;

Omok* omloc();
Omok* omini(
    Omok* omk, 
    int siz, int end, 
    Player* ein, Player* zwi
);
void  omfre(Omok* omk);

void  omin (Omok* omk, Action act);
void  omout(Omok* omk);

int omckw(Omok* omk);
#endif