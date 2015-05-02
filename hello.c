#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include "PSToDCM.h"
#include "jimmy_debug.h"

//typedef struct
//{
//    u32 u32GroupType;
//    u32 u16Offset;
//    u8 u8FieldIndex;
//	u8 u8FieldNum;
//	u16 u16EntrySize;
//} sPSToDCMEntry;

sPSToDCMEntry G_aPSToDCMTable[1000] =  {};

//sPSToDCMEntry G_aPSToDCMTemplate[100] = 
//{
//	{DCM_GRP_ID_IPMI_SYSPARAM, 0, 1, 1, 0},
//	{DCM_GRP_ID_IPMI_SYSPARAM, 1, 2, 1, 0},
//	{DCM_GRP_ID_IPMI_USERINFO, 0, 1, 16, USERINFOPS_ENTRY_SIZE},
//	{DCM_GRP_ID_IPMI_USERINFO, 17, 2, 16, USERINFOPS_ENTRY_SIZE},
//	{0, 0, 0, 0, 0},
//};


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
		u16 u16Offset = u16StartOffset + (u16EntrySize * i);
		G_aPSToDCMTable[G_u16TableIdx].u16Offset = u16Offset;//u16StartOffset + (u16EntrySize * i);
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
	jimmy_debug(LOG_DEBUG, "jimmy song %f.\n", value);

	int idx = 0;
	jimmy_debug(LOG_DEBUG, "================= Print Template ===============\n");
	while(G_aPSToDCMTemplate[idx].u32GroupType != 0)
	{
		jimmy_debug(LOG_DEBUG, "*GroupType:%d|u16Offset:%d|FieldIndex:%d|FieldNum:%d|EntrySize:%d.\n", 
					G_aPSToDCMTemplate[idx].u32GroupType,
					G_aPSToDCMTemplate[idx].u16Offset,
					G_aPSToDCMTemplate[idx].u8FieldIndex,
					G_aPSToDCMTemplate[idx].u8FieldNum,
					G_aPSToDCMTemplate[idx].u16EntrySize);
		
		AddDCMEntry(G_aPSToDCMTemplate[idx].u32GroupType, 
					G_aPSToDCMTemplate[idx].u16Offset, 
					G_aPSToDCMTemplate[idx].u8FieldIndex,
					G_aPSToDCMTemplate[idx].u8FieldNum, 
					G_aPSToDCMTemplate[idx].u16EntrySize); 
		idx++;
	}

	G_aPSToDCMTable[G_u16TableIdx].u32GroupType = 0;
	G_aPSToDCMTable[G_u16TableIdx].u16Offset = 0;
	G_aPSToDCMTable[G_u16TableIdx].u8FieldIndex = 0;
	G_aPSToDCMTable[G_u16TableIdx].u8FieldNum = 0;
	G_aPSToDCMTable[G_u16TableIdx].u16EntrySize = 0;

	jimmy_debug(LOG_DEBUG, "G_aPSToDCMTable size; %d|G_u16TableIdx:%d.\n", sizeof(G_aPSToDCMTable), G_u16TableIdx);

	idx = 0;
	jimmy_debug(LOG_DEBUG, "================= Print Mapping Table ===============\n");
	while(G_aPSToDCMTable[idx].u32GroupType != 0)
	{
		jimmy_debug(LOG_DEBUG, "GroupType:%d|u16Offset:%d|FieldIndex:%d|FieldNum:%d|EntrySize:%d.\n", 
					G_aPSToDCMTable[idx].u32GroupType,
					G_aPSToDCMTable[idx].u16Offset,
					G_aPSToDCMTable[idx].u8FieldIndex,
					G_aPSToDCMTable[idx].u8FieldNum,
					G_aPSToDCMTable[idx].u16EntrySize);
		idx++;
	}

	u8 u8ChannelID = 1;
	jimmy_debug(LOG_DEBUG, "%d.\n", u8ChannelID << 2);

	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv, &tz);
	jimmy_debug(LOG_DEBUG, "tv_sec:%d|tv_usec:%d|tz_minuteswest:%d|tz_dsttime:%d.\n",
				tv.tv_sec,
				tv.tv_usec,
				tz.tz_minuteswest,
				tz.tz_dsttime);
	
}

