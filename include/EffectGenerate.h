//=================================================================================================
//
// EffectGenerate ヘッダファイル
//
//=================================================================================================
#pragma once

//-------------------------------------------------------------------------------------------------
// ヘッダファイルのインクルード
//-------------------------------------------------------------------------------------------------
//#include "Game.h"
#include "Define.h"
//#include "DxDefine.h"
//#include "../Const.h"

//-------------------------------------------------------------------------------------------------
// 宣言
//-------------------------------------------------------------------------------------------------
namespace GAME
{

	class EffectGenerate
	{
		//--------------------------------------------------
		UINT	m_id { 0 };		//エフェクト生成のID

		//--------------------------------------------------
		UINT	m_index { 0 };		//指定Efインデックス
		VEC2	m_pos { 0, 0 };		//生成位置
		float	m_z { 0 };			//z位置
		bool	m_gnrt { F };		//生成
		bool	m_loop { F };		//繰返
		bool	m_sync { F };		//同期

		float	m_rotate { 0 };		//回転[rad]
		VEC2	m_rotate_center { 0, 0 };	//回転中心(x,y)

	public:
		EffectGenerate ();
		EffectGenerate ( const EffectGenerate& rhs );		//コピー可能
		~EffectGenerate ();

		void SetID ( UINT i ) { m_id = i; }
		UINT GetID () const { return m_id; }

		void SetIndex ( UINT i ) { m_index = i; }
		UINT GetIndex () const { return m_index; }

		void SetPos ( VEC2 v ) { m_pos = v; }
		VEC2 GetPos () const { return m_pos; }

		void SetZ ( float f ) { m_z = f; }
		float GetZ () const { return m_z; }

		void SetGnrt ( bool b ) { m_gnrt = b; }
		bool GetGnrt () const { return m_gnrt; }

		void SetLoop ( bool b ) { m_loop = b; }
		bool GetLoop () const { return m_loop; }

		void SetSync ( bool b ) { m_sync = b; }
		bool GetSync () const { return m_sync; }

		void SetRotate ( float rad ) { m_rotate = rad; }
		float GetRotate () const { return m_rotate; }

		void SetRotateCenter ( VEC2 v ) { m_rotate_center = v; }
		VEC2 GetRotateCenter () const { return m_rotate_center; }
	};
	

	using P_EfGnrt = std::shared_ptr < EffectGenerate >;
	using VP_EfGnrt = std::vector < P_EfGnrt >;
	using PVP_EfGnrt = std::shared_ptr < VP_EfGnrt >;


}	//namespace GAME


