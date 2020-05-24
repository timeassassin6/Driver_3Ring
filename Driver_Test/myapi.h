#include "StdAfx.h"

HANDLE WINAPI MyOpenProcess(DWORD dwDesiredAccess,
	BOOL  bInheritHandle,
	DWORD dwProcessId)
{
	struct _CLIENT_ID
	{
		ULONG UniqueProcess = dwProcessId;
		ULONG UniqueThread = NULL;
	}CLIENT_ID;
	struct _OBJECT_ATTRIBUTES
	{
		ULONG Length = 0x18;
		ULONG RootDirectory = NULL;
		ULONG ObjectName = NULL;
		ULONG Attributes = NULL;
		ULONG SecurityDescriptor = NULL;
		ULONG SecurityQualityOfService = NULL;
	}OBJECT_ATTRIBUTES;
	__asm
	{
		
	}
}