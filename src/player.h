/*
 * player.h: declare player object, method
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
#ifndef KAGA
#define KAGA
#include <stdlib.h>

typedef struct
{
    char sel[4]; //UNICODE with \0
    char shw[4]; //UNICODE with \0
    char nme[4]; //ASCII   with \0
} Player;

Player* plloc();
Player* plcre(char* sel, char* shw, char* nme);
#endif