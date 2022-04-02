#include "stdafx.h"
#include "mc.h"//�����������ͷ�ļ�

CMyPlayerControl::CMyPlayerControl()//���캯��
{
}
CMyPlayerControl::~CMyPlayerControl() //��������
{
	Close();//���ùر�
}

DWORD CMyPlayerControl::GetLength(DWORD dwItem)
{
//�õ���ǰ�ļ�״̬
	MCI_STATUS_PARMS mcistatusparms;
	mcistatusparms.dwCallback=(DWORD)m_hWnd;
	mcistatusparms.dwItem=dwItem;//״̬���ֵ
	mcistatusparms.dwReturn=0;
	mciSendCommand (mciOpen.wDeviceID,
					MCI_STATUS,
					MCI_STATUS_ITEM,
					(DWORD)&mcistatusparms);
	return mcistatusparms.dwReturn;//���س���
}
BOOL CMyPlayerControl::Open(LPCSTR lpFileName)
{
	//����д򿪵�MCI�豸�͹ر�
	if(mciOpen.wDeviceID) Close();
	//��ʼ�� MCT OPENPARMS�ṹ�е��ļ�����
	mciOpen.lpstrDeviceType=NULL;
	//�����ļ�·��
	mciOpen.lpstrElementName=lpFileName;
	//��MCI�豸����������Ϣ(�ڴ��豸ʱ,�豸��Ϊ0>
	if(mciSendCommand(0,
					MCI_OPEN,
					MCI_DEVTYPE_WAVEFORM_AUDIO,
	(DWORD)&mciOpen))
	{
		return FALSE;
	}
	dwFrom=MCI_MAKE_HMS (0,0,0);//��ʼλ��Ϊ0
	return TRUE;
}
void CMyPlayerControl::Play ()
{
	//���Ų����ṹ
	MCI_PLAY_PARMS mciplayparms;//�õ��ļ���С
	DWORD cdlen = GetLength(MCI_STATUS_LENGTH);
	DWORD cdto=MCI_MAKE_HMS(MCI_HMS_HOUR(cdlen),
			MCI_HMS_MINUTE (cdlen) ,
			MCI_HMS_SECOND(cdlen));//���ļ��ж����Ĵ�Сת��Ϊʱ������
	mciplayparms.dwCallback=NULL;
	mciplayparms.dwFrom=dwFrom;//������ʼλ��
	mciplayparms.dwTo=cdto;//������ֹλ��

	if(mciOpen.wDeviceID!=0)//�ж��Ƿ���ļ�
	{//��������
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
	//ִ��McT CLOSE����,�ر�MCI�豸
		mciSendCommand(mciOpen.wDeviceID,MCI_CLOSE,NULL,NULL);
	}
}
void CMyPlayerControl::Stop()
{
	if(mciOpen.wDeviceID)
	{
		//ִ��MCI STOP����,ֹͣ��������
		mciSendCommand(mciOpen.wDeviceID,MCI_STOP,NULL,NULL);//�Ѳ���λ���趨Ϊ�����ļ��Ŀ�ͷ��ʹ��һ�β��Ų������ļ���ͷλ�ÿ�ʼ)
		mciSendCommand(mciOpen.wDeviceID,
						MCI_SEEK,
						MCI_SEEK_TO_START,NULL);
	}
	dwFrom = MCI_MAKE_HMS(0,0,0);//����ʼλ������Ϊ0
}
void CMyPlayerControl::Pause()
{
	if(mciOpen.wDeviceID)
	{//ִ��MCI_PAUSE����,��ͣ��������
		DWORD dwsf=GetLength(MCI_STATUS_POSITION);
		dwFrom=MCI_MAKE_MSF(MCI_MSF_MINUTE(dwsf),
							MCI_MSF_SECOND(dwsf),
							MCI_MSF_FRAME(dwsf));
//ִ��MCT PAUSE����,��ͣ��������
		mciSendCommand(mciOpen.wDeviceID,MCI_PAUSE,NULL,NULL);
	}
}
void CMyPlayerControl::SetwindowsHwnd (HWND hWnd)
{
	m_hWnd = hWnd;//�ѵ�ǰ�����ڵľ������
}



