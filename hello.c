#include <stdio.h>
#include <math.h>
#include "common.h"

typedef struct
{
     u32 u32GroupType;
     u16 u16Offset;
     u8 u8FieldIndex;
     u8 u8FieldNum;
} sPSToDCMEntry;

sPSToDCMEntry G_aPSToDCMTable[100] = 
{
	{80000, 0, 1, 1},
	{80000, 1, 2, 1},
	{0, 0, 0, 0},
};

int main(void)
{
	printf("Hello Jimmy!\n");
	thanks_2();
	float value;
	value = sin(3.14 / 2);
	printf("%f\n", value);
	jimmy_debug("jimmy song %f.\n", value);

	int i = 0;
	
	u8 u8MaxLen = 17;

	for(i = 0; i < 16; i++)
	{
		int idx = i + 2;
		G_aPSToDCMTable[idx].u32GroupType = 80001;
		G_aPSToDCMTable[idx].u16Offset = u8MaxLen * i;
		G_aPSToDCMTable[idx].u8FieldIndex = 2;
		G_aPSToDCMTable[idx].u8FieldNum = i + 1;
	}
	
	G_aPSToDCMTable[16 + 2].u32GroupType = 0;
	G_aPSToDCMTable[16 + 2].u16Offset = 0;
	G_aPSToDCMTable[16 + 2].u8FieldIndex = 0;
	G_aPSToDCMTable[16 + 2].u8FieldNum = 0;

	i = 0;
	while(G_aPSToDCMTable[i].u32GroupType != 0)
	{
		jimmy_debug("%d.\n", G_aPSToDCMTable[i].u32GroupType);
		i++;
	}
}
