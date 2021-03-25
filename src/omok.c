/*
 * omok.c: manage game
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
#include "omok.h"

void chloc(char** ca, char* st, int siz);

Omok* omloc()
{
    return (Omok*)malloc(sizeof(Omok));
}

Omok* omini(
    Omok* omk,
    int siz, int end,
    Player* ein, Player* zwi
)
{
    omk->siz = siz;
    omk->end = end;
    omk->pan = pacre(siz);
    omk->ptr = vecre(0, 0);
    omk->ein = ein;
    omk->zwi = zwi;
    omk->win = 0;
    omk->trn = 0;
    return omk;
}

void omfre(Omok* omk)
{
    pafre(&omk->pan, omk->siz);
    free(omk->ptr);
    free(omk->ein);
    free(omk->zwi);
    free(omk);
}

void omin(Omok* omk, Action act)
{
    switch(act)
    {
        case UP:
            if(omk->ptr->y > 0)
                omk->ptr->y--;
            break;
        case LE:
            if(omk->ptr->x > 0)
                omk->ptr->x--;
            break;
        case DN:
            if(omk->ptr->y < omk->siz - 1)
                omk->ptr->y++;
            break;
        case RI:
            if(omk->ptr->x < omk->siz - 1)
                omk->ptr->x++;
            break;
        case SU:
        {
            Vector *ptr = omk->ptr;
            if(!omk->pan[ptr->y][ptr->x])
            {
                omk->pan[ptr->y][ptr->x] = omnow(omk) + 1;
                if(omckw(omk)) omk->win = omnow(omk) + 1;
                else omk->trn++;
            }
        }
            break;
    }
}

void omout(Omok* omk)
{
    if(omk->win)
    {
        printf("%s win!", omk->win-1 ? omk->zwi->nme : omk->ein->nme);
    }
    else
    {
        printf("\033[H\033[J");
        int s = omk->siz;
        char*** o = (char***)malloc(sizeof(char **) * s);
        for (int i = 0; i < s; i++)
        {
            char** out = (char**)malloc(sizeof(char *) * s);
            for (int j = 0; j < s; j++)
            {
                out[j] = (char*)malloc(sizeof(char) * 5);
                int t = omk->pan[i][j];
                switch (t)
                {
                    case 0:
                        chloc(
                            &out[j],
                            (i == 0) ?
                            (j == 0) ? TL :
                            (j == (s - 1)) ? TR : TC :
                            (i == (s - 1)) ?
                            (j == 0) ? DL :
                            (j == (s - 1)) ? DR : DC :
                            (j == 0) ? CL :
                            (j == (s - 1)) ? CR : CC,
                            4
                        );
                        strcat(out[j], " ");
                        break;
                    case 1:
                        chloc(&out[j], omk->ein->shw, 4);
                        break;
                    case 2:
                        chloc(&out[j], omk->zwi->shw, 4);
                        break;
                }
            }
            o[i] = out;
        }
        Vector* ve = omk->ptr;
        chloc(
            &o[ve->y][ve->x],
            omnow(omk) ? omk->zwi->sel : omk->ein->sel,
            4
        );
        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j < s; j++)
                printf(o[i][j]);
            printf("\n");
        }
    }
}

int omnow(Omok* omk)
{
    return omk->trn % 2;
}

int omckw(Omok* omk)
{
    int a = omnow(omk) + 1;
    int e = omk->end;
    int s = omk->siz;
    for(int i = 0; i < omk->siz; i++)
    {
        for(int j = 0; j < omk->siz; j++)
        {
            if(omk->pan[i][j] != a) continue;
            int l = 1, d = 1, dl = 1;
            for(int k = 1; k < e; k++)
            {
                if(j + k >= s || omk->pan[i][j + k] != a) l = 0;
                if(i + k >= s || omk->pan[i + k][j] != a) d = 0;
                if(j + k >= s || i + k >= s || omk->pan[i + k][j + k] != a) dl = 0;
            }
            if(l || d || dl) return 1;
        }
    }
    return 0;
}

//UTIL
void chloc(char** ca, char* st, int siz)
{
    for (int i = 0; i < siz; i++)
        (*ca)[i] = st[i];
}