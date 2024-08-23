#pragma once

//declared min with flaots
float Min(float a, float b);
float Max(float a, float b);
float FindValue(float Numbers[], size_t Count, float Value, int Start);

//declared Sum with floats
float Sum(float a, float b);
float Sum(float a, float b, float c);
float Clamp(float Lowest, float Highest, float Number);
float Distance(float x1, float y1, float x2, float y2);

void PrintArray(float Numbers[], size_t Count);
void MinArray(float Numbers[], size_t Count);
void MaxArray(float Numbers[], size_t Count);
void PairPrinting(float a, float b);
void ReverseArray(float Numbers[], size_t Count);
