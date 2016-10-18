#pragma once

//ゲームフロー
enum {
	PHASE_TITLE,
	PHASE_CHARACTERCREATE,
	PHASE_VERSUS1,
	PHASE_VERSUS2,
	PHASE_VERSUS3,
	PHASE_VERSUS4,
	PHASE_VERSUS5,
	PHASE_UPGROWTH,
	PHASE_CONTINUE,
	PHASE_GAMEOVER
};

//フラグ管理用
enum {
	Disable,
	Enable
};

//フェーズ列挙
enum {
	PHASE_COMMAND,
	PHASE_BATTLE,
	PHASE_MAX
};

//コマンド列挙
enum {
	COMMAND_ATTACK,		//たたかう
	COMMAND_SPELL,		//じゅもん
	COMMAND_CHALLENGE,	//ちょうはつ
	COMMAND_PARRY,		//パリィ
	COMMAND_DEFENCE,	//ぼうぎょ
	COMMAND_ESCAPE,		//にげる
	COMMAND_MAX			//コマンドの数
};

extern int	
command,
phase,
Spell_buffFlag,
Spell_dontUse,
EnemySpellFlag,
TimeStopFlag,
turnCount,
turnCount5,
randomNum,
hpdisp,
bonus,
zako1WinFlag,
zako2WinFlag,
zako3WinFlag,
zako4WinFlag,
ClearFlag,
GameFlow;
