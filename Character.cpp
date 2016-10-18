#include "Character.h"

//実体の宣言（えにくす）
CHARACTER player = {
	30,
	30,
	10,
	10,
	"ゆうしゃ",
	4,
	4,
	10
};

//実体の宣言（ごろつき）
CHARACTER zako1 = {
	40,
	40,
	0,
	0,
	"ごろつき",
	4,
	2,
	1
};

//実体の宣言（くろまどうし）
CHARACTER zako2 = {
	70,
	70,
	50,
	50,
	"くろまどうし",
	2,
	6,
	12
};

//実体の宣言（くもおとこ）
CHARACTER zako3 = {
	150,
	150,
	50,
	50,
	"くもおとこ",
	35,
	2,
	40
};

//実体の宣言（きゅうけつき）
CHARACTER zako4 = {
	270,
	270,
	50,
	50,
	"きゅうけつき",
	50,
	10,
	8
};

//実体の宣言（ゆうしゃ）
CHARACTER zako5 = {
	500,
	500,
	50,
	50,
	"ロト",
	70,
	30,
	30
};


//ステータス一時保存用
CHARACTER default = {
	player.hp,
	player.maxHp,
	player.mp,
	player.maxMp,
	"ゆうしゃ",
	player.attack,
	player.defence,
	player.intelligence
};

CHARACTER cleared1 = {
	default.hp,
	default.maxHp,
	default.mp,
	default.maxMp,
	"ゆうしゃ",
	default.attack,
	default.defence,
	default.intelligence
};

CHARACTER cleared2 = {
	default.hp,
	default.maxHp,
	default.mp,
	default.maxMp,
	"ゆうしゃ",
	default.attack,
	default.defence,
	default.intelligence
};

CHARACTER cleared3 = {
	default.hp,
	default.maxHp,
	default.mp,
	default.maxMp,
	"ゆうしゃ",
	default.attack,
	default.defence,
	default.intelligence
};

CHARACTER cleared4 = {
	default.hp,
	default.maxHp,
	default.mp,
	default.maxMp,
	"ゆうしゃ",
	default.attack,
	default.defence,
	default.intelligence
};

CHARACTER cleared5 = {
	default.hp,
	default.maxHp,
	default.mp,
	default.maxMp,
	"ゆうしゃ",
	default.attack,
	default.defence,
	default.intelligence
};