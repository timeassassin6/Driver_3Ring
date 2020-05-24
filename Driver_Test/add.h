#include "StdAfx.h"

int add(HANDLE hDevice, int a, int b)
{
	int port[2];
	int buffret;
	ULONG dwWrite;
	port[0] = a;
	port[1] = b;
	
	DeviceIoControl(hDevice, add_code, &port, 8, &buffret, 4, &dwWrite, NULL);
	return buffret;
}