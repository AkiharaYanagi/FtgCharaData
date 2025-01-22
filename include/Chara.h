//=================================================================================================
//
//	Chara ヘッダファイル
//		キャラクタのデータを管理する
//		イメージ、スクリプト、コマンド
//
//=================================================================================================
#pragma once

//-------------------------------------------------------------------------------------------------
// ヘッダファイルのインクルード
//-------------------------------------------------------------------------------------------------
//※ Siv3DもGameLibraryも用いない独立した定義

#include "Chara_Const.h"
#include "Compend.h"
#include "Compend.h"
#include "Route.h"


//-------------------------------------------------------------------------------------------------
// 宣言
//-------------------------------------------------------------------------------------------------
namespace GAME
{
	//==================================================================================
	//	キャラ 実行上データ ver.050
	//	
	//	キャラ	
	//		┣コンペンド：ビヘイビア
	//		┃	┣[]スクリプト
	//		┃
	//		┣コンペンド：ガーニッシュ
	//		┃	┣[]スクリプト
	//		┃
	//		┣[]コマンド
	//		┣[]ブランチ
	//		┣[]ルート
	//
	//==================================================================================


	class Chara
	{
//		Behavior		m_bhvMain;		//メイン スクリプト
//		PVP_TxBs		m_pvpTxMain;	//メインイメージ テクスチャ配列
		PVP_Sqc			m_pvpAction;	//アクション配列

//		Garnish			m_bhvEf;		//EF スクリプト
//		PVP_TxBs		m_pvpTxEf;		//EFイメージ テクスチャ配列
		PVP_Sqc			m_pvpEf;		//エフェクト配列

		VP_Command		m_vpCommand;	//コマンド配列
		VP_Branch		m_vpBranch;		//ブランチ配列
		VP_Route		m_vpRoute;		//ルート配列

	public:
		Chara ();
		Chara ( const Chara & rhs ) = delete;
		~Chara ();

		void Make ();
		void Rele ();
		void Reset ();

		void Clear ();

#if 0

		//-----------------------------------------------------------------
		//メインイメージ テクスチャ配列ポインタ
		PVP_TxBs GetpvpMainTexture () const { return m_pvpTxMain; }

		//メインイメージ テクスチャ配列に追加
		void AddpMainTexture ( P_TxBs pTexture ) { m_pvpTxMain->push_back ( pTexture ); }

		//メインイメージ テクスチャポインタの取得
		P_TxBs GetpMainTexture ( UINT index ) { return m_pvpTxMain->at ( index ); }

#endif // 0

		//-----------------------------------------------------------------
		//アクション配列ポインタを取得
		PVP_Sqc GetpvpAction () { return m_pvpAction; }

		//アクション配列に追加
		void AddpAction ( P_Sqc pAction ) { m_pvpAction->push_back ( pAction ); }

		//アクション配列にまとめて追加
		void AddpAction ( std::unique_ptr < P_Sqc [] > arypAction, rsize_t size );
		void AddpAction ( std::shared_ptr < P_Sqc [] > arypAction, rsize_t size );
		void AddpAction ( const std::vector < P_Sqc > & arypAction, rsize_t size );

		//---------------------------------------------------------------------
		//名前からアクションIDを取得する(無いときは０を返す)
		UINT GetActionID ( tstring name ) const;

		//アクションポインタを取得
		P_Sqc GetpAction ( UINT index ) { return m_pvpAction->at ( index ); }
		P_Sqc GetpAction ( tstring name ) { return GetpAction ( GetActionID ( name ) ); }

		//---------------------------------------------------------------------
		//スクリプトポインタを取得
		P_Script GetpScript ( UINT indexAction, UINT indexScript ) { return m_pvpAction->at ( indexAction )->GetpScript( indexScript ); }

		//次スクリプトが存在するかどうか
		bool IsNextScript ( UINT indexAction, UINT indexScript )
		{
			return m_pvpAction->at ( indexAction )->IsNextScript( indexScript );
		}
#if 0

		//-----------------------------------------------------------------
		//Efイメージ テクスチャ配列ポインタ
		PVP_TxBs GetpvpEfTexture () const { return m_pvpTxEf; }

		//Efイメージ テクスチャ配列に追加
		void AddpEfTexture ( P_TxBs pTexture ) { m_pvpTxEf->push_back ( pTexture ); }

		//Efイメージ テクスチャポインタの取得
		P_TxBs GetpEfTexture ( UINT index ) { return m_pvpTxEf->at ( index ); }
#endif // 0

		//-----------------------------------------------------------------
		//エフェクト配列に追加
		void AddpEffect ( P_Sqc pEffect ) { m_pvpEf->push_back ( pEffect ); }

		//エフェクト配列ポインタを取得
		PVP_Sqc GetpvpEffect () { return m_pvpEf; }

		//エフェクトポインタを取得
		P_Sqc GetpEffect ( UINT index ) { return m_pvpEf->at ( index ); }

		//エフェクト配列にまとめて追加
		void AddpEffect ( std::unique_ptr < P_Sqc [] > arypEffect, rsize_t size );
		void AddpEffect ( const std::vector < P_Sqc > & arypEffect, rsize_t size );

		//---------------------------------------------------------------------
		//コマンド配列に追加
		void AddpCommand ( P_Command pCommand ) { m_vpCommand.push_back ( pCommand ); }
		void AddaCommand ( std::unique_ptr < P_Command [] > aryCmd, UINT size );

		//コマンドを取得
		P_Command GetpCommand ( UINT indexCommand ) const { return m_vpCommand[indexCommand]; }
		const VP_Command & GetvpCommand () const { return m_vpCommand; }


		//ブランチ配列に追加
		void AddpBranch ( P_Branch pBranch ) { m_vpBranch.push_back ( pBranch ); }
		void AddaBranch ( std::unique_ptr < P_Branch [] > aryBrc, UINT size );

		//ブランチを取得
		P_Branch GetpBranch ( UINT indexBranch ) const { return m_vpBranch[indexBranch]; }
		const VP_Branch & GetvpBranch () const { return m_vpBranch; }


		//ルート配列に追加
		void AddpRoute ( P_Route pRoute ) { m_vpRoute.push_back ( pRoute ); }
		void AddaRoute ( std::unique_ptr < P_Route [] > aryRut, UINT size );

		//ルートを取得
		P_Route GetpRoute ( UINT indexRoute ) const { return m_vpRoute[indexRoute]; }
		const VP_Route & GetvpRoute () const { return m_vpRoute; }
	};

	using P_Chara = std::shared_ptr < Chara >;
	using VP_Chara = std::vector < P_Chara >;
	using PVP_Chara = std::shared_ptr < VP_Chara >;


}	//namespace GAME


