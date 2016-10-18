#pragma once


enum {
	Yes,
	No,
	YesNomax
};

//ステータス
enum {
	STATUS_HP,		//たたかう
	STATUS_MP,		//じゅもん
	STATUS_ATTACK,		//にげる
	STATUS_DEFENCE,	//ぼうぎょ
	STATUS_INTELLIGENCE,
	STATUS_MAX			//コマンドの数
};

extern char commandNames[][16], YesNo[][16],statusNames[][16];
extern int cursor;
