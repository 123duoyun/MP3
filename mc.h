#ifndef __MY_PLAYER_CONTROL_H__
#define __MY_PLAYER_CONTROL_H__

#include <mmsystem.h>//插入多媒体头文件
class CMyPlayerControl
{
public:
	CMyPlayerControl();//构造函数

	~CMyPlayerControl();//析构函数

public:
	BOOL Open(LPCSTR lpFileName);//打开文件

	void Play ();//播放

	void Close();//关闭

	void Stop ();//停止

	void Pause();//暂停

	DWORD GetLength (DWORD dwItem);//得到歌曲长度

	void SetwindowsHwnd (HWND hWnd);//设置主窗口句柄

private:
	MCI_OPEN_PARMS mciOpen;//打开设备参数

	HWND m_hWnd;//主窗口句柄

	DWORD dwFrom;//播放起始点
};
#endif

