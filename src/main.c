/*
 * main.c: core; get player name, run game
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
#include <stdio.h>

#include "cset.h"
#include "player.h"
#include "omok.h"

int main(void)
{
    char einc[4],
         zwic[4];
    printf("input p1 name: ");
    scanf("%3s", &einc);
    fflush(stdin);
    printf("input p2 name: ");
    scanf("%3s", &zwic);
    fflush(stdin);
    Player  *ein = plcre(EINSEL, EINSHW, einc),
            *zwi = plcre(ZWISEL, ZWISHW, zwic);
    Omok    *omk = omini(
        omloc(), 
        19, 5, 
        ein, zwi
    );
    while(!omk->win)
    {
        omout(omk);
        fflush(stdin);
        switch(getch())
        {
            case 'w':
                omin(omk, UP);
                break;
            case 's':
                omin(omk, DN);
                break;
            case 'a':
                omin(omk, LE);
                break;
            case 'd':
                omin(omk, RI);
                break;
            case 0x20:
                omin(omk, SU);
                break;
            case 0xE0:
                switch(getch())
                {
                    case 0x48:
                        omin(omk, UP);
                        break;
                    case 0x50:
                        omin(omk, DN);
                        break;
                    case 0x4B:
                        omin(omk, LE);
                        break;
                    case 0x4D:
                        omin(omk, RI);
                        break;
                }
                break;
        }
    }
    omout(omk);
    omfre(omk);
    return 0;
}