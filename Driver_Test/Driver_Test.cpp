// Driver_Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "StdAfx.h"

int main()
{
    //加载驱动
    BOOL bRet = LoadDriver(DRIVER_NAME, DRIVER_PATH);
    if (!bRet)
    {
        printf("LoadNTDriver error\n");
        getchar();
        return 0;
    }
    //加载成功

    printf("press any key to create device!\n");
    getchar();

    //测试驱动功能开始
    //打开设备，获取设备句柄
    HANDLE hDevice = CreateFile(
        "\\\\.\\Myddk_LinkName",
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    if (hDevice == INVALID_HANDLE_VALUE)
    {
        printf("获取设备句柄失败,error code %d\n", GetLastError());
        getchar();
        return -1;
    }
    int a = 1;
    int b = 2;
    int c = add(hDevice, a, b);
    printf("%d+%d=%d\n", a, b, c);
    getchar();
    //测试驱动功能结束
    //卸载驱动
    bRet = UnloadDriver(DRIVER_NAME);
    if (!bRet)
    {
        printf("UnloadNTDriver error\n");
        getchar();
        return 0;
    }
    else
        printf("Driver Unload Done.");
    return 0;
}

