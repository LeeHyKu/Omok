/*
 * panel.c: method for create or remove panel
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
#include "panel.h"

short** pacre(int siz)
{
    short** erg = (short**)malloc(sizeof(short*) * siz);
    for(int i = 0; i < siz; i++)
    {
        erg[i] = (short*)malloc(sizeof(short) * siz);
        for(int j = 0; j < siz; j++)
            erg[i][j] = 0;
    }
    return erg;
}

void pafre(short*** pan, int siz)
{
    for(int i = 0; i < siz; i++)
        free((*pan)[i]);
    free(*pan);
}