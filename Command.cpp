#include "Command.h"

//コマンドの名前
char commandNames[][16] = {
	"たたかう",
	"じゅもん",
	"ちょうはつ",
	"パリィ",
	"ぼうぎょ",
	"にげる"
};

//はい・いいえ
char YesNo[][16] = {
	"はい",
	"いいえ"
};

int cursor = STATUS_HP;

//ステータス名前
char statusNames[][16] = {
	"たいりょく",
	"まりょく",
	"ちから",
	"みのまもり",
	"かしこさ"
};

