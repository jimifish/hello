#include <stdio.h>
#include <math.h>
#include "common.h"

typedef struct
{
    u32 u32GroupType;
    u32 u32Offset;
    u8 u8FieldIndex;
	u8 u8FieldNum;
	u16 u16EntrySize;
} sPSToDCMEntry;

sPSToDCMEntry G_aPSToDCMTable[1000] =  {};

sPSToDCMEntry G_aPSToDCMTemplate[100] = 
{
	{80000, 0, 1, 1, 0},
	{80000, 1, 2, 1, 0},
	{80001, 0, 1, 16, 64},
	{80001, 17, 2, 16, 64},
	{0, 0, 0, 0, 0},
};


u16 G_u16TableIdx = 0;

void AddDCMEntry(
					UINT32 u32GroupType,
					UINT16 u16StartOffset,
					UINT8 u8FieldIndex,
					UINT16 u16Num,
					u16 u16EntrySize
				)
{
	u16 i = 0;

	for(i = 0; i < u16Num; i++)
	{
		G_aPSToDCMTable[G_u16TableIdx].u32GroupType = u32GroupType;
		u32 u32Offset = u16StartOffset + (u16EntrySize * i);
		G_aPSToDCMTable[G_u16TableIdx].u32Offset = u32Offset;//u16StartOffset + (u16EntrySize * i);
		G_aPSToDCMTable[G_u16TableIdx].u8FieldIndex = u8FieldIndex;
		G_aPSToDCMTable[G_u16TableIdx].u8FieldNum = i + 1;
		G_aPSToDCMTable[G_u16TableIdx].u16EntrySize = u16EntrySize;
		G_u16TableIdx++;
	}
}

int main(void)
{
	printf("Hello Jimmy!\n");
	thanks_2();
	float value;
	value = sin(3.14 / 2);
	printf("%f\n", value);
	jimmy_debug("jimmy song %f.\n", value);

	int i = 0;
	while(G_aPSToDCMTemplate[i].u32GroupType != 0)
	{
		jimmy_debug("GroupType:%d|u16Offset:%d|FieldIndex:%d|FieldNum:%d|EntrySize:%d.\n", 
					G_aPSToDCMTemplate[i].u32GroupType,
					G_aPSToDCMTemplate[i].u32Offset,
					G_aPSToDCMTemplate[i].u8FieldIndex,
					G_aPSToDCMTemplate[i].u8FieldNum,
					G_aPSToDCMTemplate[i].u16EntrySize);
		
		AddDCMEntry(G_aPSToDCMTemplate[i].u32GroupType, 
					G_aPSToDCMTemplate[i].u32Offset, 
					G_aPSToDCMTemplate[i].u8FieldIndex,
					G_aPSToDCMTemplate[i].u8FieldNum, 
					G_aPSToDCMTemplate[i].u16EntrySize); 
		i++;
	}

	G_aPSToDCMTable[G_u16TableIdx].u32GroupType = 0;
	G_aPSToDCMTable[G_u16TableIdx].u32Offset = 0;
	G_aPSToDCMTable[G_u16TableIdx].u8FieldIndex = 0;
	G_aPSToDCMTable[G_u16TableIdx].u8FieldNum = 0;
	G_aPSToDCMTable[G_u16TableIdx].u16EntrySize = 0;

	i = 0;
	while(G_aPSToDCMTable[i].u32GroupType != 0)
	{
		jimmy_debug("GroupType:%d|u16Offset:%d|FieldIndex:%d|FieldNum:%d|EntrySize:%d.\n", 
					G_aPSToDCMTable[i].u32GroupType,
					G_aPSToDCMTable[i].u32Offset,
					G_aPSToDCMTable[i].u8FieldIndex,
					G_aPSToDCMTable[i].u8FieldNum,
					G_aPSToDCMTable[i].u16EntrySize);
		i++;
	}
}

