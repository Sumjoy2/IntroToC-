#pragma once

int* ZeroArray(size_t OutSize);
char* CharSearch(const char TheCharacter, char * CharacterArray, bool CaseSensitive = false);
void NumberLover();

// Returns a pointer to a dynamic integer array that is a copy of the provided array
//  - origArray refers to the array to be copied
//  - size refers to the size of the original array to copy
int* DuplicateArray(int* origArray, size_t size);
void IntSubArrCopy(int* InArray, int StartLocal, int EndLocal, int* OutArray = {});