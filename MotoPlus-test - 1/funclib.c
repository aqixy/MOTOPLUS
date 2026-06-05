/**** funclib.c ****/
/* Copyright 2009 YASKAWA ELECTRIC All Rights reserved. */
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif
#include "motoPlus.h"
#include "math.h"

// for API INTERFACE

// for API & FUNCTIONS

extern long mpPutVarData(MP_VAR_DATA *, long);
extern long mpPutPosVarData(MP_POSVAR_DATA *, long);

extern long mpGetVarData(MP_VAR_INFO *sData, LONG* rData, LONG num);
extern long mpReadIO(MP_IO_INFO *sData, USHORT* rData, LONG num);
extern long mpWriteIO(MP_IO_DATA *sData, LONG num);
//extern long mpGetCartPos(MP_CARTPOS_EX_SEND_DATA *sData,MP_CART_POS_RSP_DATA_EX *rData);
//extern long mpGetAlarmStatus(MP_ALARM_STATUS_RSP_DATA* rData);

// for LOCAL DEFINITIONS

/**************************************
**	useful function for application ***
***************************************/

//读取一个B变量
STATUS GetBVar(UINT16 index, long *value)
{
  MP_VAR_INFO info;

  info.usType = MP_RESTYPE_VAR_B;
  info.usIndex = index;

  return mpGetVarData(&info, value, 1);
}


//赋值一个B变量
STATUS SetBVar(UINT16 index, long value)
{
  MP_VAR_DATA info;

  info.usType = MP_RESTYPE_VAR_B;
  info.usIndex = index;
  info.ulValue = value;

  return mpPutVarData(&info, 1);
}


//赋值多个B变量
STATUS SetMultiBVar(UINT16 startIdx, long *values, long nbr)
{
  int i;
  MP_VAR_DATA info[64];

  nbr = (nbr > 64) ? 64 : nbr;

  for(i=0; i<nbr; i++) 
  {
    info[i].usType = MP_RESTYPE_VAR_B;
    info[i].usIndex = startIdx + i;
    info[i].ulValue = values[i];
  }

  return mpPutVarData(info, nbr);
}


//读取多个B变量
STATUS GetMultiBVar(UINT16 startIdx, long *value, long nbr)
{
  int i;
  MP_VAR_INFO info[20];

  for(i=0; i<nbr; i++)
  {
    info[i].usType = MP_RESTYPE_VAR_B;
    info[i].usIndex = startIdx + i;
  }

  return mpGetVarData(info, value, nbr);
}


//读取一个I变量
STATUS GetIVar(UINT16 index, long *value)
{
  MP_VAR_INFO info;

  info.usType = MP_RESTYPE_VAR_I;
  info.usIndex = index;

  return mpGetVarData(&info, value, 1);
}


//赋值一个I变量
STATUS SetIVar(UINT16 index, long value)
{
  MP_VAR_DATA info;

  info.usType = MP_RESTYPE_VAR_I;
  info.usIndex = index;
  info.ulValue = value;

  return mpPutVarData(&info, 1);
}


//赋值多个I变量
STATUS SetMultiIVar(UINT16 startIdx, long *values, long nbr)
{
  int i;
  MP_VAR_DATA info[64];

  nbr = (nbr > 64) ? 64 : nbr;

  for(i=0; i<nbr; i++) 
  {
    info[i].usType = MP_RESTYPE_VAR_I;
    info[i].usIndex = startIdx + i;
    info[i].ulValue = values[i];
  }

  return mpPutVarData(info, nbr);
}


//读取多个I变量
STATUS GetMultiIVar(UINT16 startIdx, long *value, long nbr)
{
  int i;
  MP_VAR_INFO info[20];

  for(i=0; i<nbr; i++)
  {
    info[i].usType = MP_RESTYPE_VAR_I;
    info[i].usIndex = startIdx + i;
  }

  return mpGetVarData(info, value, nbr);
}


//读取一个D变量
STATUS GetDVar(UINT16 index, long *value)
{
  MP_VAR_INFO info;

  info.usType = MP_RESTYPE_VAR_D;
  info.usIndex = index;

  return mpGetVarData(&info, value, 1);
}


//赋值一个D变量
STATUS SetDVar(UINT16 index, long value)
{
  MP_VAR_DATA info;

  info.usType = MP_RESTYPE_VAR_D;
  info.usIndex = index;
  info.ulValue = value;

  return mpPutVarData(&info, 1);
}


//赋值多个D变量
STATUS SetMultiDVar(UINT16 startIdx, long *values, long nbr)
{
  int i;
  MP_VAR_DATA info[64];

  nbr = (nbr > 64) ? 64 : nbr;

  for(i=0; i<nbr; i++) 
  {
    info[i].usType = MP_RESTYPE_VAR_D;
    info[i].usIndex = startIdx + i;
    info[i].ulValue = values[i];
  }

  return mpPutVarData(info, nbr);
}


//读取多个D变量
STATUS GetMultiDVar(UINT16 startIdx, long *values, long nbr)
{
  int i;
  MP_VAR_INFO info[64];

  nbr = (nbr > 64) ? 64 : nbr;

  for(i=0; i<nbr; i++) 
  {
    info[i].usType = MP_RESTYPE_VAR_D;
    info[i].usIndex = startIdx + i;
  }

  return mpGetVarData(info, values, nbr);
}


//读取一个任意类型(B,I,D,R)变量
STATUS GetXVar(UINT16 type, UINT16 index, long *value)
{
  MP_VAR_INFO info;

  info.usType = type; //1:B变量 2:I变量 3:D变量 4:R变量
  info.usIndex = index;

  return mpGetVarData(&info, (long *)value, 1);
}


//赋值一个任意类型(B,I,D,R)变量
STATUS SetXVar(UINT16 type, UINT16 index, long value)
{
  MP_VAR_DATA info;

  info.usType = type; //1:B变量 2:I变量 3:D变量 4:R变量
  info.usIndex = index;
  info.ulValue = value;

  return mpPutVarData(&info, 1);
}


//读取一个R变量
STATUS GetRVar(UINT16 index, long *value)
{
  MP_VAR_INFO info;

  info.usType = MP_RESTYPE_VAR_R;
  info.usIndex = index;

  return mpGetVarData(&info, value, 1);
}


//赋值一个R变量
STATUS SetRVar(UINT16 index, long value)
{
  MP_VAR_DATA info;

  info.usType = MP_RESTYPE_VAR_R;
  info.usIndex = index;
  info.ulValue = value;

  return mpPutVarData(&info, 1);
}


//赋值多个R变量
STATUS SetMultiRVar(UINT16 startIdx, long *values, long nbr)
{
  int i;
  MP_VAR_DATA info[64];

  nbr = (nbr > 64) ? 64 : nbr;

  for(i=0; i<nbr; i++) 
  {
    info[i].usType = MP_RESTYPE_VAR_R;
    info[i].usIndex = startIdx + i;
    info[i].ulValue = values[i];
  }

  return mpPutVarData(info, nbr);
}


//读取多个R变量
STATUS GetMultiRVar(UINT16 startIdx, long *values, long nbr)
{
  int i;
  MP_VAR_INFO info[64];

  nbr = (nbr > 64) ? 64 : nbr;

  for(i=0; i<nbr; i++) 
  {
    info[i].usType = MP_RESTYPE_VAR_R;
    info[i].usIndex = startIdx + i;
  }

  return mpGetVarData(info, values, nbr);
}

//赋值单个M寄存器
STATUS WriteReg(UINT32 addr, UINT16 value)
{
  MP_IO_DATA sData;
  sData.ulAddr = 1000000 + addr;
  sData.ulValue = value;

  return mpWriteIO(&sData, 1);
}

//读取单个M寄存器
STATUS ReadReg(UINT32 addr, UINT16* value)
{
  MP_IO_INFO sData;
  sData.ulAddr = 1000000 + addr;

  return mpReadIO (&sData, value, 1);
}

//读取多个M寄存器
STATUS ReadMultiReg(UINT32 addr, UINT16* value, int num)
{
  MP_IO_INFO sData[100];
  int i;
  num = (num > 100) ? 100 : num;
  
  for(i=0;i<num;i++)
  { 
    sData[i].ulAddr = 1000000 + addr + i;
  }

  return mpReadIO (sData, value, num);
}

//赋值多个M寄存器
STATUS WriteMultiReg(UINT32 addr, UINT16* value, int num)
{
  MP_IO_DATA sData[100];
  int i;
  num = (num > 100) ? 100 : num;
  
  for(i=0;i<num;i++)
  {
    sData[i].ulAddr = 1000000 + addr + i;
    sData[i].ulValue = value[i];
  }

  return mpWriteIO(sData, num);
}


//读取单个IO
STATUS GetIo(UINT32 ioAddr, USHORT *signal)
{
  MP_IO_INFO nfo;

  nfo.ulAddr = ioAddr;
  return mpReadIO(&nfo, signal, 1);
}


//控制单个IO
STATUS SetIo(UINT32 ioAddr, USHORT signal)
{
  MP_IO_DATA dta;
  dta.ulAddr = ioAddr;
  dta.ulValue = signal;
  return mpWriteIO(&dta, 1);
}


//赋值多个IO
STATUS SetMultiIo(UINT32 ioStartAddr, USHORT *signal, long nbr)
{
  MP_IO_DATA dta[800];
  int i,j,mod;
  int io1,io2,io3;

  if( nbr > 800 )
    return ERROR;
    
  io1=ioStartAddr/10;
  io2=ioStartAddr-io1*10;
  io3=io1*10;
  
  if (io2==0)
  {
     for(i=0; i<nbr; i++)  //start bit =0
     {
       j=i/8;
       mod=i-j*8;
       dta[i].ulAddr = ioStartAddr+j*10+mod;
       //dta[i].ulAddr = ioStartAddr+i;
       dta[i].ulValue = signal[i];
      } 
      return mpWriteIO(dta, nbr);
  }
  else if (io2!=0 && (io2+nbr) <=8) //end bit <=7
  {
     for(i=0; i<nbr; i++)
     {       
       dta[i].ulAddr = ioStartAddr+i;
       dta[i].ulValue = signal[i];
      } 
      return mpWriteIO(dta, nbr);
  }
  else
  {
     for(i=0; i<nbr; i++)
     {       
       if (i<8-io2)
          {
            dta[i].ulAddr = ioStartAddr+i;
            dta[i].ulValue = signal[i];
          }
       else
       {
          j=(i-(8-io2))/8;
          mod=(i-(8-io2))-j*8;
          dta[i].ulAddr = io3+(j+1)*10+mod;
          dta[i].ulValue = signal[i];
       }
     }
     return mpWriteIO(dta, nbr);
  }
  //return ERROR;
}



//赋值多个IO
STATUS SetMultiIofrmValue(UINT32 ioStartAddr, ULONG ioValue, long nbr)
{
  //MP_IO_DATA dta[64];
  int i,j,mod,rc;
  int io1,io2,io3;
  ULONG ulAddr,ulValue;

  if( nbr > 64 )
    return ERROR;
    
  io1=ioStartAddr/10;
  io2=ioStartAddr-io1*10;
  io3=io1*10;
  
  if (io2==0)
  {
     for(i=0; i<nbr; i++)  //start bit =0
     {
       j=i/8;
       mod=i-j*8;
       ulAddr = ioStartAddr+j*10+mod;
       ulValue = ioValue%2;
       rc = SetIo(ulAddr,ulValue);
       ioValue /= 2;
       if (rc<0) break;
      } 
      //return mpWriteIO(dta, nbr);
  }
  else if (io2!=0 && (io2+nbr) <=8) //end bit <=7
  {
     for(i=0; i<nbr; i++)
     {       
       ulAddr = ioStartAddr+i;
       ulValue = ioValue%2;
       rc = SetIo(ulAddr,ulValue);
       ioValue /= 2;
       if (rc<0) break;
      } 
      //return mpWriteIO(dta, nbr);
  }
  else
  {
     for(i=0; i<nbr; i++)
     {       
       if (i<8-io2)
          {
            ulAddr = ioStartAddr+i;
            ulValue = ioValue%2;
            rc = SetIo(ulAddr,ulValue);
            ioValue /= 2;
          }
       else
       {
          j=(i-(8-io2))/8;
          mod=(i-(8-io2))-j*8;
          ulAddr = io3+(j+1)*10+mod;
          ulValue = ioValue%2;
          rc = SetIo(ulAddr,ulValue);
          ioValue /= 2;
       }
       if (rc<0) break;
     }
     //return mpWriteIO(dta, nbr);
  }
  return rc;
}

/*
//读取多个IO
STATUS GetMultiIo(UINT32 ioStartAddr, USHORT *signal, long nbr)
{
  MP_IO_INFO dta[800];
  int i,j,mod;
  int io1,io2,io3;

  if( nbr > 800 )
    return ERROR;
    
  io1=ioStartAddr/10;
  io2=ioStartAddr-io1*10; 
  io3=io1*10;

  if (io2==0) //start bit =0
  {
     for(i=0; i<nbr; i++)
     {
       j=i/8;
       mod=i-j*8;
       dta[i].ulAddr = ioStartAddr+j*10+mod;
       //dta[i].ulAddr = ioStartAddr+i;
     }
     return mpReadIO(&dta, signal, nbr);
  }
  else if (io2!=0 && (io2+nbr) <=8) //end bit <=7
  {
     for(i=0; i<nbr; i++)
     {
       dta[i].ulAddr = ioStartAddr+i;
     }
     return mpReadIO(&dta, signal, nbr);
  }
  else
  {
     for(i=0; i<nbr; i++)
     {       
       if (i<8-io2)
            dta[i].ulAddr = ioStartAddr+i;
       else
       {
          j=(i-(8-io2))/8;
          mod=(i-(8-io2))-j*8;
          dta[i].ulAddr = io3+(j+1)*10+mod;
       }
     }
     return mpReadIO(&dta, signal, nbr);
  }
     //return ERROR;
}
*/

//读取多个IO
LONG GetMultiIo(UINT32 ioStartAddr, USHORT *signal, long nbr)
{
  MP_IO_INFO dta[800];
  int i,j,k,mod,rc;
  int io1,io2,io3;
  LONG Value = 0;

  if( nbr > 800 )
    return ERROR;
    
  io1=ioStartAddr/10;
  io2=ioStartAddr-io1*10; 
  io3=io1*10;

  if (io2==0) //start bit =0
  {
     for(i=0; i<nbr; i++)
     {
       j=i/8;
       mod=i-j*8;
       dta[i].ulAddr = ioStartAddr+j*10+mod;
       //dta[i].ulAddr = ioStartAddr+i;
     }
     rc= mpReadIO(&dta, signal, nbr);
  }
  else if (io2!=0 && (io2+nbr) <=8) //end bit <=7
  {
     for(i=0; i<nbr; i++)
     {
       dta[i].ulAddr = ioStartAddr+i;
     }
     rc=  mpReadIO(&dta, signal, nbr);
  }
  else
  {
     for(i=0; i<nbr; i++)
     {       
       if (i<8-io2)
            dta[i].ulAddr = ioStartAddr+i;
       else
       {
          j=(i-(8-io2))/8;
          mod=(i-(8-io2))-j*8;
          dta[i].ulAddr = io3+(j+1)*10+mod;
       }
     }
     rc= mpReadIO(&dta, signal, nbr);
  }

  if (nbr<32) //返回值为io组成的整数LONG
  {
     for(k=0;k<nbr;k++)
     {
       Value = Value + (signal[k] * pow(2,k));
     }
     return (Value-4);
  }
  else return -1; //返回值超出LONG范围
}



//设置一个S变量
STATUS SetSVar(UINT16 index, char str[STR_VAR_SIZE+1])
{
	MP_SVAR_SEND_INFO svInf;
	LONG rc;

	svInf.usType = MP_RESTYPE_VAR_S;
	svInf.usIndex = index;
	strncpy((char *)svInf.ucValue,str,STR_VAR_SIZE);
	svInf.ucValue[STR_VAR_SIZE] = '\0';

	rc = mpPutSVarInfo(&svInf,1);
	if (rc < 0)
	{
		printf("%d = mpPutSVarInfo()",rc);
	}
	return rc;
}


//读取一个S变量
STATUS GetSVar(UINT16 index, char str[STR_VAR_SIZE+1])
{
	MP_VAR_INFO sData;
	MP_SVAR_RECV_INFO svInf;
	LONG rc;

	sData.usType = MP_RESTYPE_VAR_S;
	sData.usIndex = index;
	svInf.ucValue[0] = '\0';
	rc = mpGetSVarInfo(&sData,&svInf,1);
	if (rc==0)
	{
		strncpy(str,(char*)svInf.ucValue,STR_VAR_SIZE+1);
		rc = strlen(str);
	}
	else
	{
		printf("%d = mpGetSVarInfo()",rc);
	}
	return rc;
}


//获取报警信息
STATUS GetAlarm(short *status, USHORT *AlmCount, USHORT AlmNo[MAX_ALARM_COUNT], USHORT SubCode[MAX_ALARM_COUNT])
{
   MP_ALARM_STATUS_RSP_DATA Sta;
   MP_ALARM_CODE_RSP_DATA Code;
   int rc1, rc2, i;
   
   rc1 = mpGetAlarmStatus(&Sta);
      
   if (rc1>=0)  //获取报警状态
   {
      status[0]=Sta.sIsAlarm;
      
      if (status[0] == 0) //无报警
      {
         AlmCount[0] = 0;
         for (i=0; i<MAX_ALARM_COUNT; i++)
            {
               AlmNo[i] = 0; //报警代码 
               SubCode[i] = 0; //报警子代码
            }
         return 0;
      }
       
      else //有报警
      {
         rc2 = mpGetAlarmCode(&Code);
            
         if (rc2>=0)  //获取报警信息
         {
            AlmCount[0] = Code.usAlarmNum; //报警个数（最多4个）
            
            if (AlmCount[0]>0)
            {
               for (i=0; i<AlmCount[0]; i++)
               {
                  AlmNo[i] = Code.AlarmData.usAlarmNo[i]; //报警编号 
                  SubCode[i] = Code.AlarmData.usAlarmData[i]; //报警数据
               }
             }
            return 0;
          }
          else return ERROR; //无法获取报警信息
        }
     } 
   else return ERROR; //无法获取报警状态
}


//获取当前位置
STATUS GetPos(SHORT RobotNo, SHORT Frame, SHORT ToolNo, LONG Pos[MAX_CART_AXES_EX])
{
   MP_CARTPOS_EX_SEND_DATA sData;
   MP_CART_POS_RSP_DATA_EX rData;
   int i, rc;
   sData.sRobotNo = RobotNo;
   sData.sFrame = Frame;
   sData.sToolNo = ToolNo;
   rc = mpGetCartPosEx(&sData, &rData);
   if (rc>=0)
   {
      for (i=0; i<MAX_CART_AXES_EX; i++)
      {
         Pos[i] = rData.lPos[i];
      }
   }
   return rc;
}


//获取目标速度和反馈速度
STATUS GetSpeed(CTRLG_T Group, LONG svSpeed[MAX_PULSE_AXES], LONG fbSpeed[MAX_PULSE_AXES])
{
   int rc1, rc2, i;
   MP_CTRL_GRP_SEND_DATA SVsData;
   MP_SERVO_SPEED_RSP_DATA SVrData;
   MP_CTRL_GRP_SEND_DATA FBsData;
   MP_FB_SPEED_RSP_DATA FBrData;
   SVsData.sCtrlGrp = Group; //0-7:R1-R8; 8-15:B1-B8; 16-39:S1-S24
   FBsData.sCtrlGrp = Group; //0-7:R1-R8; 8-15:B1-B8; 16-39:S1-S24
   rc1 = mpGetServoSpeed(&SVsData, &SVrData);
   rc2 = mpGetFBSpeed(&FBsData, &FBrData);
   
   if (rc1>=0 && rc2>=0)   
   {
      for (i=0; i<MAX_PULSE_AXES; i++)
      {
         svSpeed[i] = SVrData.lSpeed[i];
         fbSpeed[i] = FBrData.lSpeed[i];
      }
      return 0;
   }
   else   return ERROR;
}


//获取转矩
STATUS GetTorque(CTRLG_T Group, LONG TrqPcnt[MAX_PULSE_AXES], LONG TrqNm[MAX_PULSE_AXES])
{
   int rc1, rc2, i;
   MP_CTRL_GRP_SEND_DATA sPcnt;
   MP_TORQUE_RSP_DATA rPcnt;
   MP_CTRL_GRP_SEND_DATA sNm;
   MP_TORQUE_EX_RSP_DATA rNm;
   sPcnt.sCtrlGrp = Group;
   sNm.sCtrlGrp = Group;
   rc1 = mpGetTorque(&sPcnt, &rPcnt);
   rc2 = mpGetTorqueEx(&sNm, &rNm);
   
   if (rc1>=0 && rc2>=0)   
   {
      for (i=0; i<MAX_PULSE_AXES; i++)
      {
         TrqPcnt[i] = rPcnt.lTorquePcnt[i];
         TrqNm[i] = rNm.lTorqueNm[i];
      }
      return 0;
   }
   else   return ERROR;
}


//获取经过时间
void GetElapsedTime(SHORT TimeType, LONG *ElapsedTime)
{
   //int rc;
   MP_SYS_TIME_SEND_DATA sData;
   MP_SYS_TIME_RSP_DATA rData;
   sData.sTimeType = TimeType; //0: Control power time; 1:Servo power time; 2:Playback time; 3:Moving time; 4:Operating time
   mpGetSysTimes(&sData,&rData);
   ElapsedTime[0] = rData.lElapsedTime;
   //return rc;
}


//获取工具信息
STATUS GetToolData(SHORT ToolNo, LONG Coord[6], LONG GCenter[3], LONG *Weight, LONG Inertia[3])
{
   int rc;
   SHORT sToolNo;
   MP_TOOL_RSP_DATA rData;
   sToolNo = ToolNo;
   rc = mpGetToolData(sToolNo, &rData);
   if (rc>=0)
   {
      Coord[0] = rData.x;
      Coord[1] = rData.y;
      Coord[2] = rData.z;
      Coord[3] = rData.rx;
      Coord[4] = rData.ry;
      Coord[5] = rData.rz;
      
      GCenter[0] = rData.xg;
      GCenter[1] = rData.yg;
      GCenter[2] = rData.zg;
      
      Weight[0] = rData.w;
      
      Inertia[0] = rData.ix;
      Inertia[1] = rData.iy;
      Inertia[2] = rData.iz;
   }
  return rc; 
}


//获取工具号
STATUS GetToolNo(ULONG RobotNo, SHORT *ToolNo)
{
   int rc;
   ULONG sRobotNo;
   MP_GET_TOOL_NO_RSP_DATA rData;
   sRobotNo = RobotNo;
   rc = mpGetToolNo(sRobotNo,&rData);
   if (rc>=0)  ToolNo[0] = rData.sToolNo;   
   return rc;
}


//获取模式
STATUS GetMode(SHORT *Mode)
{
   int rc;
   MP_MODE_RSP_DATA rData;
   rc = mpGetMode(&rData);
   if (rc>=0)
   {
      if (rData.sMode==1)  Mode[0] = 1; //TEACH
      else if (rData.sMode==2 && rData.sRemote==0)  Mode[0] = 2; //PLAY
      else if (rData.sMode==2 && rData.sRemote==1)  Mode[0] = 3; //REMOTE
      else return ERROR;
   }
   return rc;
}


//控制伺服
STATUS SetServoPower(SHORT Power)
{
   int rc;
   MP_SERVO_POWER_SEND_DATA sData;
   MP_STD_RSP_DATA rData;
   sData.sServoPower = Power; //1:ON; 0:OFF
   rc = mpSetServoPower(&sData,&rData);
   return rc;
}


//暂停
STATUS HOLD(SHORT Hold)
{
   int rc;
   MP_HOLD_SEND_DATA sData;
   MP_STD_RSP_DATA rData;
   sData.sHold = Hold; //1:ON; 0:OFF
   rc = mpHold(&sData,&rData);
   return rc;
}


//获取单个P变量
STATUS GetPosVar(USHORT Type, USHORT Index, LONG *VarType, LONG *Posture, LONG *ToolNo, LONG *UFno, LONG Coord[8])
{
   int rc, i;
   MP_VAR_INFO sData[1];
   LONG rData[10],temp;
   
   sData[0].usType = Type; //5:机器人 6:基座 7:工装轴
   sData[0].usIndex = Index;
   rc = mpGetPosVarData(&sData,&rData,1);
   if (rc>=0)
   {
      VarType[0] = rData[0] & 0x0000003F;            
      Posture[0] = (rData[0] & 0x00003F00) >>8;      
      ToolNo[0] =  (rData[0] & 0x003F0000) >>16;      
      UFno[0] = (rData[0] & 0x0FC00000) >>22;
      for (i=0; i<8; i++)
      {
         Coord[i] = rData[i+2];
      }
   }
   return rc;
}


//设置单个P变量
STATUS PutPosVar(USHORT Type, USHORT Index, LONG VarType, LONG Posture, LONG ToolNo, LONG UFno, LONG Coord[8])
{
   int i, rc;
   MP_POSVAR_DATA sData[1];
   LONG vartype, posture, toolno, ufno;
   sData[0].usType = Type; //5:机器人 6:基座 7:工装轴
   sData[0].usIndex = Index;
   
   vartype = VarType & 0x0000003F;
   posture = (Posture <<8) & 0x00003F00;
   toolno = (ToolNo <<16) & 0x003F0000;
   ufno = (UFno <<22) & 0x0FC00000;
   sData[0].ulValue[0] = vartype | posture | toolno | ufno;   
   sData[0].ulValue[1] = 0;
   
   for (i=0; i<8; i++)
   {
     sData[0].ulValue[i+2] = Coord[i];
   }
   
   rc = mpPutPosVarData(sData, 1);
   return rc;
}


//获取多个P变量
STATUS GetMultiPosVar(USHORT Type[100], USHORT Index, LONG num, LONG VarType[100], LONG Posture[100], LONG ToolNo[100], LONG UFno[100], LONG Coord[800])
{
   int rc, i, j, k=0;
   MP_VAR_INFO sData[100];
   LONG rData[1000];
   
   for (j=0; j<num; j++)
   {
      sData[j].usType = Type[j]; //5:机器人 6:基座 7:工装轴
      sData[j].usIndex = Index + j;
   }
   rc = mpGetPosVarData(&sData,&rData,num);
   if (rc>=0)
   {
      for (j=0; j<num; j++)
      {
         VarType[j] = rData[0+j*10] & 0x0000003F;            
         Posture[j] = (rData[0+j*10] & 0x00003F00) >>8;      
         ToolNo[j] =  (rData[0+j*10] & 0x003F0000) >>16;      
         UFno[j] = (rData[0+j*10] & 0x0FC00000) >>22;
         for (i=0; i<8; i++)
         {
            //Coord[i+j*10-k*2] = rData[i+2+j*10];
            Coord[i+j*8] = rData[i+2+j*10];
         }
         //k++;
      }
   }
   return rc;
}


//设置多个P变量
STATUS PutMultiPosVar(USHORT Type[100], USHORT Index, LONG num, LONG VarType[100], LONG Posture[100], LONG ToolNo[100], LONG UFno[100], LONG Coord[800])
{
   int i, j, rc;
   MP_POSVAR_DATA sData[100];
   LONG vartype[100], posture[100], toolno[100], ufno[100];
   
   for (j=0; j<num; j++)
   {
     sData[j].usType = Type[j]; //5:机器人 6:基座 7:工装轴
     sData[j].usIndex = Index + j;
   
     vartype[j] = VarType[j] & 0x0000003F;
     posture[j] = (Posture[j] <<8) & 0x00003F00;
     toolno[j] = (ToolNo[j] <<16) & 0x003F0000;
     ufno[j] = (UFno[j] <<22) & 0x0FC00000;
     sData[j].ulValue[0] = vartype[j] | posture[j] | toolno[j] | ufno[j];   
     sData[j].ulValue[1] = 0;
   
     for (i=0; i<8; i++)
     {
       sData[j].ulValue[i+2] = Coord[i+j*8];
     }
   }
   rc = mpPutPosVarData(sData, num);
   return rc;
}