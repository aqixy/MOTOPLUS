#define _CRT_SECURE_NO_WARNINGS  // 禁用不安全函数警告
#include "stdio.h"
//mpMain.c
#include "motoPlus.h"

int  SetApplicationInfo();
void mpTask1();
void mpTask2();

//GLOBAL DATA DEFINITIONS
int nTaskID1;
int nTaskID2;

extern STATUS GetBVar(UINT16 index, long* value); //读取B变量
extern STATUS SetBVar(UINT16 index, long value); //写入B变量


void mpUsrRoot(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10)
{
	int rc;

	//TODO: Add additional intialization routines.

	//Creates and starts a new task in a seperate thread of execution.
	//All arguments will be passed to the new task if the function
	//prototype will accept them.
	nTaskID1 = mpCreateTask(MP_PRI_TIME_NORMAL, MP_STACK_SIZE, (FUNCPTR)mpTask1,
		arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
	nTaskID2 = mpCreateTask(MP_PRI_TIME_NORMAL, MP_STACK_SIZE, (FUNCPTR)mpTask2,
		arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);

	//Set application information.
	rc = SetApplicationInfo();

	//Ends the initialization task.
	mpExitUsrRoot;
}

//Set application information.
int SetApplicationInfo(void)
{
	MP_APPINFO_SEND_DATA    sData;
	MP_STD_RSP_DATA         rData;
	int                     rc;

	memset(&sData, 0x00, sizeof(sData));
	memset(&rData, 0x00, sizeof(rData));

	strncpy(sData.AppName, "Default Application", MP_MAX_APP_NAME);
	strncpy(sData.Version, "0.00", MP_MAX_APP_VERSION);
	strncpy(sData.Comment, "MotoPlus Application", MP_MAX_APP_COMMENT);

	rc = mpApplicationInfoNotify(&sData, &rData);
	return rc;
}

void mpTask1(void)
{
	long b0; //变量声明，声明使用一个long类型的变量，名为b0
	GetBVar(0, &b0);//读取B000，括号中左边的0代表起始位，从0开始读取，&为指针符号，代表将读取的数值赋给b0
	SetBVar(1, b0); //B000=>B001，括号里左侧的1代表储存的地址，b0为储存的对象，将右侧值存到左侧
}

void mpTask2(int arg1, int arg2)
{
	//TODO: Add the code for this task
}