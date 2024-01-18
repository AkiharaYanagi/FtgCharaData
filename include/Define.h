//=================================================================================================
//
// �f�t�@�C���w�b�_
//�@		GameLib�p���ʒ�`
//
//=================================================================================================
#pragma once

//-------------------------------------------------------------------------------------------------
//	�C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------
#include <WinSock2.h>	//<windows.h>�����O�ɐ錾����
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")
#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <memory>


//=============================================
//
//@info	using namespace std; ���~�߁A	std::�錾��t����
//	�ǂ����Ă��t����Ƃ��� �w�b�_.h �ł͂Ȃ� �\�[�X.cpp�ɕt����
//
//=============================================

//using namespace std;


//-------------------------------------------------------------------------------------------------
//	��`
//-------------------------------------------------------------------------------------------------
namespace GAME
{
	//-------------------------------------------------------------------------------------------------
	// unsigned int
	//-------------------------------------------------------------------------------------------------
	using UINT = unsigned __int32;
	using UINT64 = unsigned __int64;

	typedef struct USIZE
	{
	public:
		USIZE () { w = 0; h = 0; }
		USIZE ( UINT w0, UINT h0 ) { w = w0; h = h0; }
		UINT w;
		UINT h;
	} USIZE;

	using V_UINT = std::vector < UINT >;

	//-------------------------------------------------------------------------------------------------
	// TCAHR�Ή�
	//-------------------------------------------------------------------------------------------------
	using tstring =			std::basic_string< TCHAR >;
	using tistream =		std::basic_istream< TCHAR >;
	using tostream =		std::basic_ostream< TCHAR >;
	using tfstream =		std::basic_fstream< TCHAR >;
	using tifstream =		std::basic_ifstream< TCHAR >;
	using tofstream =		std::basic_ofstream< TCHAR >;
	using tistringstream =	std::basic_istringstream< TCHAR >;
	using tostringstream =	std::basic_ostringstream< TCHAR >;

	using V_STR = std::vector < tstring >;
	using P_STR = std::shared_ptr < tstring >;
	using VP_STR = std::vector < P_STR >;
	using PVP_STR = std::shared_ptr < tstring >;


	typedef tostringstream TOSS;
	typedef std::shared_ptr < TOSS > P_TOSS;


	using UP_CTSTR = std::unique_ptr < TCHAR >;
	using UP_TSTR = std::unique_ptr < TCHAR[] >;	//�z��Ƃ��� < TCHAR[] > �Ő錾����


	//-------------------------------------------------------------------------------------------------
	// TRUE, FALSE
	//-------------------------------------------------------------------------------------------------
	constexpr bool T = true;
	constexpr bool F = false;

	//-------------------------------------------------------------------------------------------------
	//	�����ɂ����ϐ�����A�ϐ��������������񃊃e�����Ƃ��ĕԂ�((#)�������񉻉��Z�q)
	//-------------------------------------------------------------------------------------------------
	#define	STR(var) #var


}	//namespace GAME
