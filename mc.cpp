#include "stdafx.h"
#include "mc.h"//插入类的声明头文件

CMyPlayerControl::CMyPlayerControl()//构造函数
{
}
CMyPlayerControl::~CMyPlayerControl() //析构函数
{
	Close();//调用关闭
}

DWORD CMyPlayerControl::GetLength(DWORD dwItem)
{
//得到当前文件状态
	MCI_STATUS_PARMS mcistatusparms;
	mcistatusparms.dwCallback=(DWORD)m_hWnd;
	mcistatusparms.dwItem=dwItem;//状态类别值
	mcistatusparms.dwReturn=0;
	mciSendCommand (mciOpen.wDeviceID,
					MCI_STATUS,
					MCI_STATUS_ITEM,
					(DWORD)&mcistatusparms);
	return mcistatusparms.dwReturn;//返回长度
}
BOOL CMyPlayerControl::Open(LPCSTR lpFileName)
{
	//如果有打开的MCI设备就关闭
	if(mciOpen.wDeviceID) Close();
	//初始化 MCT OPENPARMS结构中的文件类型
	mciOpen.lpstrDeviceType=NULL;
	//播放文件路径
	mciOpen.lpstrElementName=lpFileName;
	//向MCI设备发送命令消息(在打开设备时,设备号为0>
	if(mciSendCommand(0,
					MCI_OPEN,
					MCI_DEVTYPE_WAVEFORM_AUDIO,
	(DWORD)&mciOpen))
	{
		return FALSE;
	}
	dwFrom=MCI_MAKE_HMS (0,0,0);//起始位置为0
	return TRUE;
}
void CMyPlayerControl::Play ()
{
	//播放参数结构
	MCI_PLAY_PARMS mciplayparms;//得到文件大小
	DWORD cdlen = GetLength(MCI_STATUS_LENGTH);
	DWORD cdto=MCI_MAKE_HMS(MCI_HMS_HOUR(cdlen),
			MCI_HMS_MINUTE (cdlen) ,
			MCI_HMS_SECOND(cdlen));//把文件中读出的大小转换为时间数量
	mciplayparms.dwCallback=NULL;
	mciplayparms.dwFrom=dwFrom;//设置起始位置
	mciplayparms.dwTo=cdto;//设置终止位置

	if(mciOpen.wDeviceID!=0)//判断是否打开文件
	{//播放音乐
		mciSendCommand (mciOpen.wDeviceID,
						MCI_PLAY,
						MCI_TO|MCI_FROM,
						(DWORD) (LPVOID)& mciplayparms);
	}
}
void CMyPlayerControl::Close()
{
	if(mciOpen.wDeviceID)
	{
	//执行McT CLOSE操作,关闭MCI设备
		mciSendCommand(mciOpen.wDeviceID,MCI_CLOSE,NULL,NULL);
	}
}
void CMyPlayerControl::Stop()
{
	if(mciOpen.wDeviceID)
	{
		//执行MCI STOP操作,停止播放音乐
		mciSendCommand(mciOpen.wDeviceID,MCI_STOP,NULL,NULL);//把播放位置设定为音乐文件的开头（使下一次播放操作从文件开头位置开始)
		mciSendCommand(mciOpen.wDeviceID,
						MCI_SEEK,
						MCI_SEEK_TO_START,NULL);
	}
	dwFrom = MCI_MAKE_HMS(0,0,0);//把起始位置设置为0
}
void CMyPlayerControl::Pause()
{
	if(mciOpen.wDeviceID)
	{//执行MCI_PAUSE操作,暂停播放音乐
		DWORD dwsf=GetLength(MCI_STATUS_POSITION);
		dwFrom=MCI_MAKE_MSF(MCI_MSF_MINUTE(dwsf),
							MCI_MSF_SECOND(dwsf),
							MCI_MSF_FRAME(dwsf));
//执行MCT PAUSE操作,暂停播放音乐
		mciSendCommand(mciOpen.wDeviceID,MCI_PAUSE,NULL,NULL);
	}
}
void CMyPlayerControl::SetwindowsHwnd (HWND hWnd)
{
	m_hWnd = hWnd;//把当前父窗口的句柄传入
}



