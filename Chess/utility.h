#pragma once
#include<Windows.h>
#include<iostream>
using namespace std;
void getRowColbyLeftClick(int& rpos, int& cpos);
void gotoRowCol(int rpos, int cpos);
void SetClr(int clr);
void drawBox(int r, int c, int boxDim);
void eraseBox(int r, int c, int boxDim, int clr);