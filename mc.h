#ifndef __MY_PLAYER_CONTROL_H__
#define __MY_PLAYER_CONTROL_H__

#include <mmsystem.h>//�����ý��ͷ�ļ�
class CMyPlayerControl
{
public:
	CMyPlayerControl();//���캯��

	~CMyPlayerControl();//��������

public:
	BOOL Open(LPCSTR lpFileName);//���ļ�

	void Play ();//����

	void Close();//�ر�

	void Stop ();//ֹͣ

	void Pause();//��ͣ

	DWORD GetLength (DWORD dwItem);//�õ���������

	void SetwindowsHwnd (HWND hWnd);//���������ھ��

private:
	MCI_OPEN_PARMS mciOpen;//���豸����

	HWND m_hWnd;//�����ھ��

	DWORD dwFrom;//������ʼ��
};
#endif

