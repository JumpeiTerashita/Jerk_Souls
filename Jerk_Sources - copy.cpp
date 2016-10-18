﻿#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "MT.h"

typedef struct {
	int hp;
	int maxHp;
	int mp;
	int maxMp;
	char name[16];
	int attack;
	int defence;
	int intelligence;
}CHARACTER;

//実体の宣言
CHARACTER player = {
	30,
	30,
	10,
	10,
	"えにくす",
	4,
	4,
	10
};


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

CHARACTER zako5 = {
	450,
	450,
	50,
	50,
	"ゆうしゃ",
	70,
	30,
	30
};

CHARACTER default = {
	player.hp,
	player.maxHp,
	player.mp,
	player.maxMp,
	"えにくす",
	player.attack,
	player.defence,
	player.intelligence
};

CHARACTER cleared1 = {
	default.hp,
	default.maxHp,
	default.mp,
	default.maxMp,
	"えにくす",
	default.attack,
	default.defence,
	default.intelligence
};

CHARACTER cleared2 = {
	default.hp,
	default.maxHp,
	default.mp,
	default.maxMp,
	"えにくす",
	default.attack,
	default.defence,
	default.intelligence
};

CHARACTER cleared3 = {
	default.hp,
	default.maxHp,
	default.mp,
	default.maxMp,
	"えにくす",
	default.attack,
	default.defence,
	default.intelligence
};

CHARACTER cleared4 = {
	default.hp,
	default.maxHp,
	default.mp,
	default.maxMp,
	"えにくす",
	default.attack,
	default.defence,
	default.intelligence
};

CHARACTER cleared5 = {
	default.hp,
	default.maxHp,
	default.mp,
	default.maxMp,
	"えにくす",
	default.attack,
	default.defence,
	default.intelligence
};

enum {
	Disable,
	Enable
};

enum {
	PHASE_COMMAND,
	PHASE_BATTLE,
	PHASE_MAX
};

enum {
	COMMAND_ATTACK,		//たたかう
	COMMAND_SPELL,		//じゅもん
	COMMAND_CHALLENGE,	//ちょうはつ
	COMMAND_PARRY,		//パリィ
	COMMAND_DEFENCE,	//ぼうぎょ
	COMMAND_ESCAPE,		//にげる
	COMMAND_MAX			//コマンドの数
};



int command = COMMAND_ATTACK;

int phase = PHASE_COMMAND;
int Spell_buffFlag = Disable;
int Spell_dontUse = Disable;
int EnemySpellFlag = Enable;
int TimeStopFlag = Disable;
int turnCount = 0;
int turnCount5 = 0;
int randomNum;
int hpdisp;
int bonus;
int zako1WinFlag = Disable;
int zako2WinFlag = Disable;
int zako3WinFlag = Disable;
int zako4WinFlag = Disable;
int ClearFlag = Disable;




char commandNames[][16] = {
	"たたかう",
	"じゅもん",
	"ちょうはつ",
	"パリィ",
	"ぼうぎょ",
	"にげる"
};

enum {
	Yes,
	No,
	YesNomax
};

enum {
	NEW,
	HELP,
	titlemax
};

enum {
	STATUS_HP,		//たたかう
	STATUS_MP,		//じゅもん
	STATUS_ATTACK,		//にげる
	STATUS_DEFENCE,	//ぼうぎょ
	STATUS_INTELLIGENCE,
	STATUS_MAX			//コマンドの数
};

int cursor = STATUS_HP;

char HS[][16] = {
	"はい",
	"いいえ"
};

char Title[][16] = {
	"New Game",
	"Help"
};

char statusNames[][16] = {
	"たいりょく",
	"まりょく",
	"ちから",
	"みのまもり",
	"かしこさ"
};

int GameTitle() {
	int titleCursor = NEW;
	while (1) {
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t   '||' '||''''|  '||''|.   '||'  |'      .|'''.|   ..|''||   '||'  '|' '||'       .|'''.|  \n");
		printf("\t\t    ||   ||  .     ||   ||   || .'        ||..  '  .|'    ||   ||    |   ||        ||..  '  \n");
		printf("\t\t    ||   ||''|     ||''|'    ||'|.         ''|||.  ||      ||  ||    |   ||         ''|||.  \n");
		printf("\t\t    ||   ||        ||   |.   ||  ||      .     '|| '|.     ||  ||    |   ||       .     '|| \n");
		printf("\t\t|| .|'  .||.....| .||.  '|' .||.  ||.    |'....|'   ''|...|'    '|..'   .||.....| |'....|'  \n");
		printf("\t\t '''  \n");
		printf("\n\n\n\n\n");
		printf("\t\t\t\t　　　ＰＲＥＳＳ　ＡＮＹ　ＫＥＹ　ＴＯ　ＳＴＡＲＴ");
		_getch();
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\n\t\t\t\t*―――――――――――――――――――――――――――――――――*\n");
		printf("\n\n\n\t\t\t\t	最大化表示での　プレイを推奨します\n\t\t\t\t	変更し終わったら　エンターキーを　押してください\n\n");
		printf("\n\n\t\t\t\t*―――――――――――――――――――――――――――――――――*");
		getchar();
		system("cls");
		printf("\n\n\n\t\tあなたは　おおいなるやぼうのために　たたかいの　けいけんを　ほっしています\n");
		printf("\t\t5れんせんをいきのこり　つよく　せいちょうしましょう\n");
		printf("\n\n\t\t＃ せんとうコマンドせつめい ＃\n\n");
		printf("\n\n\t\tたたかう\t:\tあなたの　もっている　つるぎで　てきに　きりかかる\n\t\t\t\t\tダメージルーレットのあたいが　『95』　いじょうのとき だいダメージをあたえる\n\n");
		printf("\n\t\tじゅもん\t:\tこうげき　かいふく　ほじょ　ぶつりわざ　しゅるいは　さまざま\n");
		printf("\t\t\t\t\tつかうには　MP（マジックポイント）が　ひつよう\n\n");
		printf("\n\t\tちょうはつ\t:\tきめぜりふを　はなち　てきの　こころを　ゆさぶる\n");
		printf("\t\t\t\t\tせいこうすれば　あいてを　じゃくたいか　させる\n\n");
		printf("\n\t\tパリィ\t\t:\tせいしんを　しゅうちゅうし　てきの　こうげきを　みきる\n");
		printf("\t\t\t\t\tパリィルーレットのあたいが　『50』　いじょうのとき　せいこう\n");
		printf("\t\t\t\t\tせいこうすれば　あいてに　ふかいきずを　あたえるが\n");
		printf("\t\t\t\t\tしっぱいすれば　じぶんが　ふかいきずを　おう\n\n");
		printf("\n\t\tぼうぎょ\t:\tてきの　こうげきを　ぼうぎょたいせいで　うけとめる\n");
		printf("\t\t\t\t\tあいての　ぶつりこうげきダメージを　けいげんできる\n\n");
		printf("\n\t\tにげる\t\t:\tかなわないと　かんじたら　にげるのも　さくのうち\n");
		printf("\t\t\t\t\tエスケープルーレットのあたいが　『34』　いじょうのとき　せいこう\n\n");
		printf("\n\n\n\t\tエンターキーを　おすと　キャラクタークリエイト画面に　移動します");
		getchar();
		return 0;
	}
}

void PlayerCreate()
{
	enum {
		Disable,
		Enable
	};

	enum {
		Yes,
		No,
		YesNomax
	};

	enum {
		STATUS_HP,		
		STATUS_MP,		
		STATUS_ATTACK,		
		STATUS_DEFENCE,	
		STATUS_INTELLIGENCE,
		STATUS_MAX			
	};

	int cursor = STATUS_HP;

	char YesNo[][16] = {
		"はい",
		"いいえ"
	};

	char statusNames[][16] = {
		"たいりょく",
		"まりょく",
		"ちから",
		"みのまもり",
		"かしこさ"
	};


	player = {
		5,
		5,
		4,
		4,
		"えにくす",
		1,
		1,
		1
	};

	int defaultStatus[] = {
		(player.maxHp / 5),
		(player.maxMp / 4),
		player.attack,
		player.defence,
		player.intelligence
	};
	int newStatus[] = {
		(player.maxHp / 5),
		(player.maxMp / 4),
		player.attack,
		player.defence,
		player.intelligence
	};
	int EnterFlag = Disable;
	bonus = 25;
	int YesNoCursor = 0;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(
		hConsoleOutput, // HANDLE hConsoleOutput
		FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);// WORD wAttributes

	while (EnterFlag == Disable) {
	START:
		system("cls");
		printf("\n *―――――――――――――――――――――――*\n");
		printf("\n　 あなたの　ぶんしんを　さくせいします");
		printf("\n　 ステータスを　わりふってください\n\n");
		printf(" *―――――――――――――――――――――――*");
		printf("\n\n　%s\n", player.name);
		printf("　のこりポイント　%d\n\n\n", bonus);
		for (int i = 0; i < STATUS_MAX; i++) {
			if (i == cursor) {
				printf("　　%s\t< %d >\n\n", statusNames[i], newStatus[i]);
			}
			else {
				printf("　　%s\t  %d\n\n", statusNames[i], newStatus[i]);
			}
		}
		printf("\n\n");
		printf(" zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\n\n\n");
		switch (cursor) {
		case STATUS_HP:
			printf("\tたいりょく\t:\tHPにえいきょうします　　1ポイントにつき　HP 5 じょうしょう\n\t\t\t\tたとえば %d なら さいだいHPは %d", newStatus[0], newStatus[0] * 5);
			break;
		case STATUS_MP:
			printf("\tまりょく\t:\tMPにえいきょうします　　1ポイントにつき　MP 4 じょうしょう\n\t\t\t\tたとえば %d なら さいだいMPは %d", newStatus[1], newStatus[1] * 4);
			break;
		case STATUS_ATTACK:
			printf("\tちから　\t:\tこうげきりょくにえいきょうします\n\t\t\t　　　　ちからこそ　パワー");
			break;
		case STATUS_DEFENCE:
			printf("\tみのまもり\t:\tぼうぎょりょくにえいきょうします\n\t\t\t　　　　こころの　ぼうぎょりょくは　あがりません");
			break;
		case STATUS_INTELLIGENCE:
			printf("\tかしこさ\t:\tまほうのいりょくにえいきょうします\n\t\t\t　　　　かいふくりょうや　まほうたいせいも　じょうしょうします");
			break;
		}
		printf("\n\n\n");
		printf("\t十字キー上下で　選択　　　十字キー左右で　増減\n");
		printf("\tわりふりおわったら　エンターで　けってい\n\n");
		switch (_getch()) {
		case 0x0d:
			EnterFlag = Enable;
			break;
		case 0xe0:
			switch (_getch()) {
			case 0x48:
				if (cursor != STATUS_HP) cursor--;
				else if (cursor == STATUS_HP) cursor = STATUS_MAX - 1;
				break;
			case 0x50:
				if (cursor != STATUS_MAX) cursor++;
				if (cursor == STATUS_MAX) cursor = STATUS_HP;
				break;
			case 0x4d:
				if (bonus > 0) {
					bonus--;
					newStatus[cursor]++;
				}
				break;
			case 0x4b:
				if (bonus < 25 && (newStatus[cursor] > 1)) {
					bonus++;
					newStatus[cursor]--;
				}
				break;
			}
			break;
		}

	}
	EnterFlag = Disable;
	while (EnterFlag == Disable) {
		system("cls");
		printf("\n *―――――――――――――――――――――――*\n");
		printf("\n　 あなたの　ぶんしんを　さくせいします");
		printf("\n　 ステータスを　わりふってください\n\n");
		printf(" *―――――――――――――――――――――――*");
		printf("\n\n　%s\n", player.name);
		printf("　のこりポイント　%d\n\n\n", bonus);
		for (int i = 0; i < STATUS_MAX; i++) {
			printf("　　%s\t  %d\n\n", statusNames[i], newStatus[i]);
		}
		printf("\n\n");
		printf(" zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\n\n\n");
		printf("\tこれで　よろしいですか？\n");
		printf("\tカーソルを　あわせて　エンターを　おしてください\n\n");
		for (int i = 0; i < YesNomax; i++) {
			if (i == YesNoCursor) {
				printf("　　＞　%s", YesNo[i]);
			}
			else {
				printf("　　　　%s", YesNo[i]);
			}
		}
		switch (_getch()) {
		case 0x0d:
			if (YesNoCursor == Yes) EnterFlag = Enable;
			if (YesNoCursor == No) {
				YesNoCursor = Yes;
				goto START;
			}
			break;
		case 0xe0:
			switch (_getch()) {
			case 0x4b:
				if (YesNoCursor != Yes) YesNoCursor--;
				else YesNoCursor++;
				break;
			case 0x4d:
				if (YesNoCursor == Yes) YesNoCursor++;
				else YesNoCursor--;
				break;
			}
			break;
		}
	}

	player = {
		newStatus[0] * 5,
		newStatus[0] * 5,
		newStatus[1] * 4,
		newStatus[1] * 4,
		"えにくす",
		newStatus[2],
		newStatus[3],
		newStatus[4]
	};

}

//表示関数
void display_zako1()
{
	system("cls");
	if (player.hp <= 0) {
		HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(
			hConsoleOutput, // HANDLE hConsoleOutput
			FOREGROUND_RED | FOREGROUND_INTENSITY);// WORD wAttributes
		printf(" ┌――――┐\n");
		printf(" │%s│\n", player.name);
		printf(" ├――――┤\n");
		if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
		else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
		else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
		else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
		if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
		else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
		else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
		printf(" └――――┘\n");
	}
	else {
		HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(
			hConsoleOutput, // HANDLE hConsoleOutput
			FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);// WORD wAttributes
		printf(" ┌――――┐\n");
		printf(" │%s│\n", player.name);
		printf(" ├――――┤\n");
		if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
		else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
		else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
		else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
		if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
		else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
		else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
		printf(" └――――┘\n");
	}
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(
		hConsoleOutput, // HANDLE hConsoleOutput
		FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("\n	　 ヘ_　 ＿_\n");
	printf("	　( (_|-/ ∞ヽ-、\n");
	printf("	　 Ｖ∥ ＞―＜_ﾉ＼\n");
	printf("	　　 (ﾖﾉﾄﾟ仝ﾟｲヽu_)\n");
	printf("	　　 ん/ ＞-<ヽ〉\n");
	printf("	　　　(ﾆﾉ　 (二)\n");
	printf("\n	　　   %s\n\n HP \n", zako1.name);
	int hpdisp_blank = zako1.maxHp;
	hpdisp = zako1.hp;
	while (hpdisp_blank > 0) {
		printf("□");
		hpdisp_blank -= 6;
	}
	printf("\r");
	while (hpdisp > 0) {
		printf("■");
		hpdisp -= 6;
	}
	printf("\n\n\n");
}

void playerattack_vszako1()
{
	system("cls");
	display_zako1();
	printf("%sの　こうげき！\n", player.name);
	while (_kbhit() != 1) {
		randomNum = 10 + genrand_int32() % 90;
		printf("\r%d", randomNum);
	}
	int attackNum = randomNum;
	getchar();
	getchar();
	int ATTACK_CRITICAL = attackNum;
	int ATTACK_RANDOM = attackNum / 10;
	if (ATTACK_RANDOM >= 0 && ATTACK_RANDOM < 4) ATTACK_RANDOM = 1;
	else if (ATTACK_RANDOM >= 4 && ATTACK_RANDOM < 7) ATTACK_RANDOM = 2;
	else if (ATTACK_RANDOM >= 7 && ATTACK_RANDOM < 10) ATTACK_RANDOM = 3;
	int ATTACK_DAMAGE = player.attack / 2 + ATTACK_RANDOM + 1 - zako1.defence / 4;
	if (ATTACK_DAMAGE <= 0) ATTACK_DAMAGE = 1;
	if (ATTACK_CRITICAL >= 95) {
		ATTACK_DAMAGE = player.attack * 2 + (genrand_int32() % 3);
		printf("SMAAAASH!!");
		getchar();
	}
	zako1.hp -= ATTACK_DAMAGE;
	display_zako1();
	printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako1.name, ATTACK_DAMAGE);
	getchar();
	if (zako1.hp <= 0) {
		system("cls");
		printf(" ┌――――┐\n");
		printf(" │%s│\n", player.name);
		printf(" ├――――┤\n");
		if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
		else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
		else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
		else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
		if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
		else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
		else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
		printf(" └――――┘\n");
		printf("\n\n\n\n");
		printf("%sを　たおした！\n", zako1.name);
		cleared1 = {
			default.hp,
			default.maxHp,
			default.mp,
			default.maxMp,
			"えにくす",
			default.attack,
			default.defence,
			default.intelligence
		};
		zako1WinFlag = Enable;
		getchar();
		return;
	}
}

void zako1attack()
{
	int ATTACK_DAMAGE;
	system("cls");
	display_zako1();
	if (zako1.hp < 13) {
		printf("%sの　すてみのこうげき！\n", zako1.name);
		getchar();
		printf("%sは　頭蓋割りをはなった！\n", zako1.name);
		getchar();
		if (genrand_int32() % 10 == 0) {
			printf("\n%sは　こうげきを　やすやすと　かわした！　%sはダメージをあたえられない！", player.name, zako1.name);
			getchar();
			return;
		}
		ATTACK_DAMAGE = zako1.attack + (genrand_int32() % 5) + 5 - player.defence / 4;
		player.hp -= ATTACK_DAMAGE;
		display_zako1();
		printf("%sに　%dポイントの\nダメージを　あたえた！\n", player.name, ATTACK_DAMAGE);
		getchar();
		if (player.hp <= 0) {
			display_zako1();
			printf("%sは　しんでしまった！\n", player.name);
			getchar();
			printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
			getchar();
			return;
		}
		else {
			return;
		}
	}
	else {
		printf("%sの　こうげき！\n", zako1.name);
		getchar();
		ATTACK_DAMAGE = zako1.attack / 2 + (genrand_int32() % 3) + 1 - player.defence / 4;
		if (genrand_int32() % 16 == 0) {
			printf("\n%sは　こうげきを　かわした！　%sはダメージをあたえられない！", player.name, zako1.name);
			getchar();
			return;
		}
		int ATTACK_CRITICAL = genrand_int32() % 100 + 1;
		if (ATTACK_DAMAGE <= 0) ATTACK_DAMAGE = 1;
		if (ATTACK_CRITICAL >= 98) {
			ATTACK_DAMAGE = zako1.attack + (genrand_int32() % 3) + 1;
			printf("SMAAAASH!!");
			getchar();
		}
		player.hp -= ATTACK_DAMAGE;
		display_zako1();
		printf("%sに　%dポイントの\nダメージを　あたえた！\n", player.name, ATTACK_DAMAGE);
		getchar();
		if (player.hp <= 0) {
			display_zako1();
			printf("%sは　しんでしまった！\n", player.name);
			getchar();
			printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
			getchar();
			return;
		}
		else {
			return;
		}
	}
}

void spell_vszako1()
{
	enum {
		SPELL_ATTACK,
		SPELL_HEAL,
		SPELL_BUFF,
		SPELL_DONT_USE,
		SPELL_MAX			//じゅもんの数
	};
	char spellNames[][16] = {
		"メラ",
		"ホイミ",
		"スカラ",
		"もどる"
	};
	int commandS = SPELL_ATTACK;
	int EnterFlagS = Disable;
	system("cls");
	display_zako1();
	while (EnterFlagS == Disable) {
		system("cls");
		display_zako1();
		printf("じゅもん\n");
		for (int i = 0; i < SPELL_MAX; i++) {
			if (i == commandS) {
				printf("＞%s\n", spellNames[i]);
			}
			else {
				printf("　%s\n", spellNames[i]);
			}
		}
		switch (commandS) {
		case SPELL_ATTACK:
			printf("\nしょうひMP:2\nちいさな　ひのたまを　ぶつける");
			break;
		case SPELL_HEAL:
			printf("\nしょうひMP:2\nじぶんの　HPを　かいふくする");
			break;
		case SPELL_BUFF:
			printf("\nしょうひMP:3\nじぶんの　ぼうぎょりょくを　じょうしょうさせる");
			break;
		case SPELL_DONT_USE:
			printf("\nじゅもんをつかうのをやめる");
			break;
		}
		switch (_getch()) {
		case 0x0d:
			EnterFlagS = Enable;
			break;
		case 0xe0:
			switch (_getch()) {
			case 0x48:
				if (commandS != SPELL_ATTACK) commandS--;
				else if (commandS == SPELL_ATTACK) commandS = SPELL_MAX - 1;
				break;
			case 0x50:
				if (commandS != SPELL_MAX) commandS++;
				if (commandS == SPELL_MAX) commandS = SPELL_ATTACK;
				break;
			}
			break;
		}
	}
	switch (commandS) {
	case SPELL_ATTACK:
		system("cls");
		display_zako1();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[0]);
		getchar();
		if (player.mp < 2) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 2;
			int SPELL_DAMAGE;
			if (player.intelligence < 6) {
				SPELL_DAMAGE = 5 + player.intelligence + genrand_int32() % 3 - zako1.intelligence;
			}
			else
			{
				SPELL_DAMAGE = 5 + player.intelligence + genrand_int32() % (player.intelligence / 2) - zako1.intelligence;
			}
			if (SPELL_DAMAGE < 0) SPELL_DAMAGE = 1;
			zako1.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako1();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako1.name, SPELL_DAMAGE);
			getchar();
			if (zako1.hp <= 0) {
				system("cls");
				printf(" ┌――――┐\n");
				printf(" │%s│\n", player.name);
				printf(" ├――――┤\n");
				if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
				else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
				else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
				else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
				if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
				else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
				else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
				printf(" └――――┘\n");
				printf("\n\n\n\n");
				printf("%sを　たおした！\n", zako1.name);
				cleared1 = {
					default.hp,
					default.maxHp,
					default.mp,
					default.maxMp,
					"えにくす",
					default.attack,
					default.defence,
					default.intelligence
				};
				zako1WinFlag = Enable;
				getchar();
				return;
			}
		}
		break;
	case SPELL_HEAL:
		system("cls");
		display_zako1();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[1]);
		getchar();
		if (player.mp < 2) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 2;
			int SPELL_RECOVER = 7 + player.intelligence + genrand_int32() % player.intelligence;
			if (SPELL_RECOVER + player.hp > player.maxHp) SPELL_RECOVER = player.maxHp - player.hp;
			player.hp += SPELL_RECOVER;
			system("cls");
			display_zako1();
			printf("%sは　%dポイント　かいふくした！\n", player.name, SPELL_RECOVER);
			getchar();
		}
		break;
	case SPELL_BUFF:
		system("cls");
		display_zako1();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[2]);
		getchar();
		if (player.mp < 3) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 3;
			player.defence += (player.defence * 2) / 5;
			system("cls");
			display_zako1();
			printf("%sの　ぼうぎょりょくが　あがった！\n", player.name);
			Spell_buffFlag = Enable;
			getchar();
		}
		break;
	case SPELL_DONT_USE:
		Spell_dontUse = Enable;
		break;
	}
	return;
}

int vszako1() {
	default = {
		player.hp,
		player.maxHp,
		player.mp,
		player.maxMp,
		"えにくす",
		player.attack,
		player.defence,
		player.intelligence
	};
	init_genrand((unsigned)time(NULL));
	zako1.hp = zako1.maxHp;
	enum {
		SPELL_ATTACK,
		SPELL_HEAL,
		SPELL_BUFF,
		SPELL_DONT_USE,
		SPELL_MAX			//じゅもんの数
	};
	command = COMMAND_ATTACK;
	int commandS = SPELL_ATTACK;
	phase = PHASE_COMMAND;
	Spell_buffFlag = Disable;
	EnemySpellFlag = Enable;
	display_zako1();
	printf("%sが　あらわれた！\n", zako1.name);
	getchar();
	while ((player.hp > 0) && (zako1.hp > 0)) {
		int EnterFlag = Disable;
		switch (phase) {
		case PHASE_COMMAND:
			while (EnterFlag == Disable) {
				system("cls");
				display_zako1();
				printf("コマンド？\n");
				for (int i = 0; i < COMMAND_MAX; i++) {
					if (i == command) {
						printf("＞%s\n", commandNames[i]);
					}
					else {
						printf("　%s\n", commandNames[i]);
					}
				}
				//コマンド説明
				switch (command) {
				case COMMAND_ATTACK:
					printf("\nこうげきをする");
					break;
				case COMMAND_SPELL:
					printf("\nMPをしょうひして\nじゅもんをつかう");
					break;
				case COMMAND_CHALLENGE:
					printf("\nあいてを　いあつして\nあいてのじゅもんや　こうげきを　ぼうがいする");
					break;
				case COMMAND_PARRY:
					printf("\nあいてのこうげきを　はじいて\nだいダメージを　ねらう");
					break;
				case COMMAND_ESCAPE:
					printf("\nとうぼうをこころみる");
					break;
				case COMMAND_DEFENCE:
					printf("\nぼうぎょをする");
					break;
				}
				switch (_getch()) {
				case 0x0d:
					EnterFlag = Enable;
					break;
				case 0xe0:
					switch (_getch()) {
					case 0x48:
						if (command != COMMAND_ATTACK) command--;
						else if (command == COMMAND_ATTACK) command = COMMAND_MAX - 1;
						break;
					case 0x50:
						if (command != COMMAND_MAX) command++;
						if (command == COMMAND_MAX) command = COMMAND_ATTACK;
						break;
					}
					break;
				}
			}
			phase = PHASE_BATTLE;
			break;
		case PHASE_BATTLE:
			int CHALLENGE_TYPE = 0;
			int CHALLENGE_SUCCESSLATE = 0;
			int escapeNum = 0;
			system("cls");
			display_zako1();
			switch (command) {
			case COMMAND_ATTACK:
				if (player.hp > 0) playerattack_vszako1();
				if (zako1.hp > 0) zako1attack();
				break;
			case COMMAND_ESCAPE:
				printf("%sは　にげだした！\n", player.name);
				while (_kbhit() != 1) {
					randomNum = 10 + genrand_int32() % 90;
					printf("\r%d", randomNum);
				}
				escapeNum = randomNum;
				getchar();
				if (escapeNum < 34) {
					printf("しかし　まわりこまれた！\n");
					getchar();
					if (zako1.hp > 0) {
						zako1attack();
					}
					break;
				}
				else {
					printf("うまく　にげきれた！\n");
					getchar();
					return 0;
				}
			case COMMAND_CHALLENGE:
				system("cls");
				display_zako1();
				printf("%sは　ちょうはつした！\n", player.name);
				getchar();
				CHALLENGE_TYPE = genrand_int32() % 3 + 1;
				CHALLENGE_SUCCESSLATE = genrand_int32() % 100 + 1;
				if (CHALLENGE_TYPE == 1) {
					printf("%s:俺が殺せると思っているのなら\n　　　　 やってみるがいい…！\n", player.name);
					getchar();
					if (CHALLENGE_SUCCESSLATE >= 30) {
						printf("%sは　おそれ　おののいた！\n", zako1.name);
						EnemySpellFlag = Disable;
					}
					else {
						printf("%sは　まるで　きいていない！\n", zako1.name);
					}
					getchar();
					zako1attack();
				}
				if (CHALLENGE_TYPE == 2) {
					printf("%s:オレは戦うのが好きなんじゃねぇんだ…。\n　　　　 勝つのが好きなんだよォォッ！！\n", player.name);
					getchar();
					if (CHALLENGE_SUCCESSLATE >= 30) {
						printf("%sは　おそれ　おののいた！\n", zako1.name);
						EnemySpellFlag = Disable;
						player.attack += 2;
					}
					else {
						printf("%sは　まるで　きいていない！\n", zako1.name);
					}
					getchar();
					zako1attack();
				}
				if (CHALLENGE_TYPE == 3) {
					printf("%s:言いたいことは…いくつか…あるんだよ…\n　　　　 ま…一言で言うなら\n　　　　 本気にさせたな\n", player.name);
					getchar();
					if (CHALLENGE_SUCCESSLATE >= 30) {
						printf("%sは　おそれ　おののいた！\n", zako1.name);
						EnemySpellFlag = Disable;
						player.attack += 4;
					}
					else {
						printf("%sは　まるで　きいていない！\n", zako1.name);
					}
					getchar();
					zako1attack();
				}
				break;
			case COMMAND_DEFENCE:
				system("cls");
				display_zako1();
				printf("%sは　みをまもっている\n", player.name);
				getchar();
				zako1.attack /= 2;
				zako1attack();
				zako1.attack *= 2;
				break;
			default:
				printf("ERROR!\nみじっそうのコマンド\n");
				break;
			case COMMAND_SPELL:
				spell_vszako1();
				if (zako1.hp > 0 && Spell_dontUse == Disable) zako1attack();
				else if (Spell_dontUse == Enable) Spell_dontUse = Disable; break;
				break;
			case COMMAND_PARRY:
				system("cls");
				display_zako1();
				printf("%sは　パリィを　こころみた！\n", player.name);
				getchar();
				system("cls");
				display_zako1();
				if (zako1.hp < 13) {
					printf("%sの　すてみのこうげき！\n", zako1.name);
					getchar();
					printf("%sは　頭蓋割りをはなった！\n", zako1.name);
					getchar();
					printf("おそろしいはやさで　おののやいばがせまってくる…\n", zako1.name);
				}
				else {
					printf("%sの　こうげき！\n", zako1.name);
					getchar();
					printf("おおきなおのの　やいばがせまってくる…\n", zako1.name);
				}
				int randomNum = 0;
				while (_kbhit() != 1) {
					randomNum = 10 + genrand_int32() % 90;
					printf("\r%d", randomNum);
				}
				getchar();
				if (randomNum >= 50) {
					printf("\nパリィ　せいこう！\n");
					getchar();
					int ATTACK_DAMAGE;
					if (randomNum >= 95) {
						printf("SMAAAASH!!");
						getchar();
						ATTACK_DAMAGE = player.attack * 4 + (genrand_int32() % 3);
						if (zako1.hp < 12) {
							printf("すてみの%sに　きょうれつな　カウンターがさくれつした！\n", zako1.name);
							getchar();
							ATTACK_DAMAGE *= 2;
						}
						zako1.hp -= ATTACK_DAMAGE;
					}
					else {
						ATTACK_DAMAGE = player.attack * 2 + (genrand_int32() % 3);
						if (zako1.hp < 12) {
							printf("すてみの%sに　きょうれつな　カウンターがさくれつした！\n", zako1.name);
							getchar();
							ATTACK_DAMAGE *= 2;
						}
						zako1.hp -= ATTACK_DAMAGE;
					}
					display_zako1();
					printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako1.name, ATTACK_DAMAGE);
					getchar();
					if (zako1.hp <= 0) {
						system("cls");
						printf(" ┌――――┐\n");
						printf(" │%s│\n", player.name);
						printf(" ├――――┤\n");
						if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
						else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
						else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
						else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
						if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
						else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
						else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
						printf(" └――――┘\n");
						printf("\n\n\n\n");
						printf("%sを　たおした！\n", zako1.name);
						zako1WinFlag = Enable;
						cleared1 = {
							default.hp,
							default.maxHp,
							default.mp,
							default.maxMp,
							"えにくす",
							default.attack,
							default.defence,
							default.intelligence
						};
						getchar();
						return 0;
					}
				}
				else {
					printf("\nパリィ　しっぱい！\n");
					getchar();
					int ATTACK_DAMAGE = zako1.attack * 2 + (genrand_int32() % 3);
					if (zako1.hp < 13) {
						printf("%sのすてみのこうげきを　まともに　くらってしまった！\n", zako1.name);
						getchar();
						ATTACK_DAMAGE *= 2;
					}
					player.hp -= ATTACK_DAMAGE;
					display_zako1();
					printf("%sは　%dポイントの\nダメージを　うけた！\n", player.name, ATTACK_DAMAGE);
					getchar();
					if (player.hp <= 0) {
						display_zako1();
						printf("%sは　しんでしまった！\n", player.name);
						getchar();
						printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
						getchar();
						return 0;
					}
				}
				break;
			}
			phase = PHASE_COMMAND;
		}
	}
	cleared1 = {
		default.hp,
		default.maxHp,
		default.mp,
		default.maxMp,
		"えにくす",
		default.attack,
		default.defence,
		default.intelligence
	};
}


void display_zako2()
{
	system("cls");
	if (player.hp <= 0) {
		HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(
			hConsoleOutput, // HANDLE hConsoleOutput
			FOREGROUND_RED | FOREGROUND_INTENSITY);// WORD wAttributes
		printf(" ┌――――┐\n");
		printf(" │%s│\n", player.name);
		printf(" ├――――┤\n");
		if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
		else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
		else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
		else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
		if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
		else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
		else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
		printf(" └――――┘\n");
	}
	else {
		HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(
			hConsoleOutput, // HANDLE hConsoleOutput
			FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);// WORD wAttributes
		printf(" ┌――――┐\n");
		printf(" │%s│\n", player.name);
		printf(" ├――――┤\n");
		if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
		else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
		else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
		else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
		if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
		else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
		else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
		printf(" └――――┘\n");
	}
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(
		hConsoleOutput, // HANDLE hConsoleOutput
		FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);


	printf("\n	　　　／￣￣ヽ\n");
	printf("	　　 /　　 |⌒`\n");
	printf("	　　/ 二二`|\n");
	printf("	 _／／O　O＼＼_\n");
	printf("	　`-<￣Ｖ￣>-´\n");
	printf("	　　[二×二]\n");
	printf("	　　/ _人_ ヽ\n");
	printf("	　 [ﾆ/∥∥`ﾆ]\n");
	printf("	　 (人｣人Lﾉ_)===[II○\n");
	printf("	　(⌒~ || ~⌒)\n");
	printf("	　　￣´｀￣\n");
	printf("	  %s\n\n HP \n", zako2.name);
	int hpdisp_blank = zako2.maxHp;
	hpdisp = zako2.hp;
	while (hpdisp_blank > 0) {
		printf("□");
		hpdisp_blank -= 6;
	}
	printf("\r");
	while (hpdisp > 0) {
		printf("■");
		hpdisp -= 6;
	}
	printf("\n\n\n");
}

void playerattack_vszako2()
{
	system("cls");
	display_zako2();
	printf("%sの　こうげき！\n", player.name);
	while (_kbhit() != 1) {
		randomNum = 10 + genrand_int32() % 90;
		printf("\r%d", randomNum);
	}
	getchar();
	int attackNum = randomNum;
	getchar();
	int ATTACK_CRITICAL = attackNum;
	int ATTACK_RANDOM = attackNum / 10;
	if (ATTACK_RANDOM >= 0 && ATTACK_RANDOM < 4) ATTACK_RANDOM = 1;
	else if (ATTACK_RANDOM >= 4 && ATTACK_RANDOM < 7) ATTACK_RANDOM = 2;
	else if (ATTACK_RANDOM >= 7 && ATTACK_RANDOM < 10) ATTACK_RANDOM = 3;
	int ATTACK_DAMAGE = player.attack / 2 + ATTACK_RANDOM + 4 - zako2.defence / 4;
	if (ATTACK_DAMAGE <= 0) ATTACK_DAMAGE = 1;
	if (ATTACK_CRITICAL >= 95) {
		ATTACK_DAMAGE = player.attack * 2 + (genrand_int32() % 3);
		printf("SMAAAASH!!");
		getchar();
	}
	zako2.hp -= ATTACK_DAMAGE;
	display_zako2();
	printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako2.name, ATTACK_DAMAGE);
	getchar();
	if (zako2.hp <= 0) {
		system("cls");
		printf(" ┌――――┐\n");
		printf(" │%s│\n", player.name);
		printf(" ├――――┤\n");
		if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
		else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
		else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
		else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
		if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
		else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
		else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
		printf(" └――――┘\n");
		printf("\n\n\n\n");
		printf("%sを　たおした！\n", zako2.name);
		zako2WinFlag = Enable;
		getchar();
		cleared2 = {
			default.hp,
			default.maxHp,
			default.mp,
			default.maxMp,
			"えにくす",
			default.attack,
			default.defence,
			default.intelligence
		};
		return;
	}
}

int zako2attack(int EnemySpellFlag)
{
	system("cls");
	display_zako2();
	int ATTACK_PATTERN = genrand_int32() % 99 + 1;
	int ATTACK_DAMAGE;
	if (zako2.hp <= 12) {
		printf("%sの　すてみのこうげき！\n", zako2.name);
		getchar();
		printf("%sの　Wまほう！\n", zako2.name);
		getchar();
		system("cls");
		display_zako2();
		printf("%sは　ファイアを　となえた！\n", zako2.name);
		getchar();
		ATTACK_DAMAGE = 5 + zako2.intelligence + (genrand_int32() % 5) + 1 - player.intelligence / 2;
		player.hp -= ATTACK_DAMAGE;
		display_zako2();
		printf("%sに　%dポイントの\nダメージを　あたえた！\n", player.name, ATTACK_DAMAGE);
		getchar();
		system("cls");
		display_zako2();
		printf("%sは　ブリザドを　となえた！\n", zako2.name);
		ATTACK_DAMAGE = 6 + zako2.intelligence + (genrand_int32() % 2) + 1 - player.intelligence / 2;
		player.hp -= ATTACK_DAMAGE;
		getchar();
		display_zako2();
		printf("%sに　%dポイントの\nダメージを　あたえた！\n", player.name, ATTACK_DAMAGE);
		getchar();
		if (player.hp <= 0) {
			display_zako2();
			printf("%sは　しんでしまった！\n", player.name);
			getchar();
			printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
			getchar();
			return 0;
		}
		return 0;
	}
	else if (ATTACK_PATTERN <= 20) {
		printf("%sの　こうげき！\n", zako2.name);
		getchar();
		if (genrand_int32() % 16 == 0) {
			printf("\n%sは　こうげきを　かわした！　%sはダメージを　あたえられない！", player.name, zako2.name);
			getchar();
			return 0;
		}
		int ATTACK_DAMAGE = zako2.attack / 2 + (genrand_int32() % 3) + 1 - player.defence / 4;
		int ATTACK_CRITICAL = genrand_int32() % 100 + 1;
		if (ATTACK_DAMAGE <= 0) ATTACK_DAMAGE = 1;
		if (ATTACK_CRITICAL >= 98) {
			ATTACK_DAMAGE = zako2.attack + (genrand_int32() % 3) + 1;
			printf("SMAAAASH!!");
			getchar();
		}
		player.hp -= ATTACK_DAMAGE;
		display_zako2();
		printf("%sに　%dポイントの\nダメージを　あたえた！\n", player.name, ATTACK_DAMAGE);
		getchar();
		if (player.hp <= 0) {
			getchar();
			display_zako2();
			printf("%sは　しんでしまった！\n", player.name);
			getchar();
			printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
			getchar();
			return 0;
		}
		else {
			return 0;
		}
	}
	else if (ATTACK_PATTERN > 20) {
		printf("%sの　こうげき！\n", zako2.name);
		getchar();
		printf("%sは　ブリザドを　となえた！\n", zako2.name);
		if (EnemySpellFlag == Disable) {
			getchar();
			printf("%sは　どうようしていて　えいしょうがうまくいかない！\n", zako2.name);
			ATTACK_DAMAGE = (genrand_int32() % 3) + 1 + zako2.intelligence - player.intelligence - 5;
			if (ATTACK_DAMAGE < 0) ATTACK_DAMAGE = 1;
			getchar();
		}
		else {
			getchar();
			ATTACK_DAMAGE = zako2.intelligence + (genrand_int32() % 5) + 1 - player.intelligence / 3;
		}
		player.hp -= ATTACK_DAMAGE;
		display_zako2();
		printf("%sに　%dポイントの\nダメージを　あたえた！\n", player.name, ATTACK_DAMAGE);
		getchar();
		if (player.hp <= 0) {
			display_zako2();
			printf("%sは　しんでしまった！\n", player.name);
			getchar();
			printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
			getchar();
			return 0;
		}
		else {
			return 0;
		}
	}
}

void spell_vszako2()
{
	enum {
		SPELL_ATTACK,
		SPELL_HEAL,
		SPELL_BUFF,
		SPELL_SLASH,
		SPELL_DONT_USE,
		SPELL_MAX			//じゅもんの数
	};
	char spellNames[][16] = {
		"メラゾーマ",
		"ホイミ",
		"スカラ",
		"しんくうぎり",
		"もどる"
	};
	int commandS = SPELL_ATTACK;
	int EnterFlagS = Disable;
	system("cls");
	display_zako2();
	while (EnterFlagS == Disable) {
		system("cls");
		display_zako2();
		printf("じゅもん\n");
		for (int i = 0; i < SPELL_MAX; i++) {
			if (i == commandS) {
				printf("＞%s\n", spellNames[i]);
			}
			else {
				printf("　%s\n", spellNames[i]);
			}
		}
		switch (commandS) {
		case SPELL_ATTACK:
			printf("\nしょうひMP:10\nきょだいな　ひのたまを　ぶつける");
			break;
		case SPELL_HEAL:
			printf("\nしょうひMP:2\nじぶんの　HPを　かいふくする");
			break;
		case SPELL_BUFF:
			printf("\nしょうひMP:3\nじぶんの　ぼうぎょりょくを　じょうしょうさせる");
			break;
		case SPELL_SLASH:
			printf("\nしょうひMP:5\nたつまきの　ちからをけんにのせ　きりかかる");
			break;
		case SPELL_DONT_USE:
			printf("\nじゅもんをつかうのをやめる");
			break;
		}
		switch (_getch()) {
		case 0x0d:
			EnterFlagS = Enable;
			break;
		case 0xe0:
			switch (_getch()) {
			case 0x48:
				if (commandS != SPELL_ATTACK) commandS--;
				else if (commandS == SPELL_ATTACK) commandS = SPELL_MAX - 1;
				break;
			case 0x50:
				if (commandS != SPELL_MAX) commandS++;
				if (commandS == SPELL_MAX) commandS = SPELL_ATTACK;
				break;
			}
			break;
		}
	}
	switch (commandS) {
	case SPELL_ATTACK:
		system("cls");
		display_zako2();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[0]);
		getchar();
		if (player.mp < 10) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 10;
			int SPELL_DAMAGE;
			if (player.intelligence < 18) {
				SPELL_DAMAGE = player.intelligence * 2 + genrand_int32() % 6 - zako2.intelligence;
			}
			else
			{
				SPELL_DAMAGE = player.intelligence * 2 + genrand_int32() % (player.intelligence / 3) - zako2.intelligence;
			}
			if (SPELL_DAMAGE <= 0) SPELL_DAMAGE = 1;
			zako2.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako2();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako2.name, SPELL_DAMAGE);
			getchar();
			if (zako2.hp <= 0) {
				system("cls");
				printf(" ┌――――┐\n");
				printf(" │%s│\n", player.name);
				printf(" ├――――┤\n");
				if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
				else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
				else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
				else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
				if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
				else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
				else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
				printf(" └――――┘\n");
				printf("\n\n\n\n");
				printf("%sを　たおした！\n", zako2.name);
				zako2WinFlag = Enable;
				cleared2 = {
					default.hp,
					default.maxHp,
					default.mp,
					default.maxMp,
					"えにくす",
					default.attack,
					default.defence,
					default.intelligence
				};
				getchar();
				return;
			}
		}
		break;
	case SPELL_HEAL:
		system("cls");
		display_zako2();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[1]);
		getchar();
		if (player.mp < 2) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 2;
			int SPELL_RECOVER = player.maxHp / 8 + player.intelligence + genrand_int32() % player.intelligence;
			if (SPELL_RECOVER + player.hp > player.maxHp) SPELL_RECOVER = player.maxHp - player.hp;
			player.hp += SPELL_RECOVER;
			system("cls");
			display_zako2();
			printf("%sは　%dポイント　かいふくした！\n", player.name, SPELL_RECOVER);
			getchar();
		}
		break;
	case SPELL_BUFF:
		system("cls");
		display_zako2();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[2]);
		getchar();
		if (player.mp < 3) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 3;
			player.defence += (player.defence * 2) / 5;
			system("cls");
			display_zako2();
			printf("%sの　ぼうぎょりょくが　あがった！\n", player.name);
			Spell_buffFlag = Enable;
			getchar();
		}
		break;
	case SPELL_SLASH:
		system("cls");
		display_zako2();
		printf("%sは　%sをはなった！\n", player.name, spellNames[3]);
		getchar();
		if (player.mp < 5) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 5;
			int SPELL_DAMAGE;
			SPELL_DAMAGE = 5 + player.attack + player.intelligence + genrand_int32() % 5 - zako2.defence / 8 - zako2.intelligence / 8;
			if (SPELL_DAMAGE <= 0) SPELL_DAMAGE = 1;
			zako2.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako2();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako2.name, SPELL_DAMAGE);
			getchar();
			if (zako2.hp <= 0) {
				system("cls");
				printf(" ┌――――┐\n");
				printf(" │%s│\n", player.name);
				printf(" ├――――┤\n");
				if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
				else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
				else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
				else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
				if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
				else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
				else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
				printf(" └――――┘\n");
				printf("\n\n\n\n");
				printf("%sを　たおした！\n", zako2.name);
				cleared2 = {
					default.hp,
					default.maxHp,
					default.mp,
					default.maxMp,
					"えにくす",
					default.attack,
					default.defence,
					default.intelligence
				};
				getchar();
				zako2WinFlag = Enable;
				return;
			}
		}
		break;
	case SPELL_DONT_USE:
		Spell_dontUse = Enable;
		return;
	}
	return;
}

int vszako2() {
	default = {
		player.hp,
		player.maxHp,
		player.mp,
		player.maxMp,
		"えにくす",
		player.attack,
		player.defence,
		player.intelligence
	};
	zako2.hp = zako2.maxHp;
	command = COMMAND_ATTACK;
	phase = PHASE_COMMAND;
	Spell_buffFlag = Disable;
	EnemySpellFlag = Enable;

	init_genrand((unsigned)time(NULL));
	display_zako2();
	printf("%sが　あらわれた！\n", zako2.name);
	getchar();
	while ((player.hp > 0) && (zako2.hp > 0)) {
		enum {
			SPELL_ATTACK,
			SPELL_HEAL,
			SPELL_BUFF,
			SPELL_SLASH,
			SPELL_DONT_USE,
			SPELL_MAX			//じゅもんの数
		};
		int commandS = SPELL_ATTACK;
		int EnterFlag = Disable;
		switch (phase) {
		case PHASE_COMMAND:
			while (EnterFlag == Disable) {
				system("cls");
				display_zako2();
				printf("コマンド？\n");
				for (int i = 0; i < COMMAND_MAX; i++) {
					if (i == command) {
						printf("＞%s\n", commandNames[i]);
					}
					else {
						printf("　%s\n", commandNames[i]);
					}
				}
				//コマンド説明
				switch (command) {
				case COMMAND_ATTACK:
					printf("\nこうげきをする");
					break;
				case COMMAND_SPELL:
					printf("\nMPをしょうひして\nじゅもんをつかう");
					break;
				case COMMAND_CHALLENGE:
					printf("\nあいてを　いあつして\nあいてのじゅもんや　こうげきを　ぼうがいする");
					break;
				case COMMAND_PARRY:
					printf("\nあいてのこうげきを　はじいて\nだいダメージを　ねらう");
					break;
				case COMMAND_ESCAPE:
					printf("\nとうぼうをこころみる");
					break;
				case COMMAND_DEFENCE:
					printf("\nぼうぎょをする");
					break;
				}
				switch (_getch()) {
				case 0x0d:
					EnterFlag = Enable;
					break;
				case 0xe0:
					switch (_getch()) {
					case 0x48:
						if (command != COMMAND_ATTACK) command--;
						else if (command == COMMAND_ATTACK) command = COMMAND_MAX - 1;
						break;
					case 0x50:
						if (command != COMMAND_MAX) command++;
						if (command == COMMAND_MAX) command = COMMAND_ATTACK;
						break;
					}
					break;
				}
			}
			phase = PHASE_BATTLE;
			break;
		case PHASE_BATTLE:
			int CHALLENGE_TYPE = 0;
			int CHALLENGE_SUCCESSLATE = 0;
			int escapeNum = 0;
			system("cls");
			display_zako2();
			switch (command) {
			case COMMAND_ATTACK:
				if (player.hp > 0) playerattack_vszako2();
				if (zako2.hp > 0) zako2attack(EnemySpellFlag);
				break;
			case COMMAND_ESCAPE:
				printf("%sは　にげだした！\n", player.name);
				while (_kbhit() != 1) {
					randomNum = 10 + genrand_int32() % 90;
					printf("\r%d", randomNum);
				}
				escapeNum = randomNum;
				getchar();
				if (escapeNum < 34) {
					printf("しかし　まわりこまれた！\n");
					getchar();
					if (zako2.hp > 0) {
						zako2attack(EnemySpellFlag);
					}
					break;
				}
				else {
					printf("うまく　にげきれた！\n");
					player.hp = 0;
					getchar();
					return 0;
				}
			case COMMAND_CHALLENGE:
				system("cls");
				display_zako2();
				printf("%sは　ちょうはつした！\n", player.name);
				getchar();
				CHALLENGE_TYPE = genrand_int32() % 3 + 1;
				CHALLENGE_SUCCESSLATE = genrand_int32() % 100 + 1;
				if (CHALLENGE_TYPE == 1) {
					printf("%s:俺が殺せると思っているのなら\n　　　　 やってみるがいい…！\n", player.name);
					getchar();
					if (CHALLENGE_SUCCESSLATE >= 30) {
						printf("%sは　おそれ　おののいた！\n", zako2.name);
						EnemySpellFlag = Disable;
					}
					else {
						printf("%sは　まるで　きいていない！\n", zako2.name);
					}
					getchar();
					zako2attack(EnemySpellFlag);
				}
				if (CHALLENGE_TYPE == 2) {
					printf("%s:オレは戦うのが好きなんじゃねぇんだ…。\n　　　　 勝つのが好きなんだよォォッ！！\n", player.name);
					getchar();
					if (CHALLENGE_SUCCESSLATE >= 30) {
						printf("%sは　おそれ　おののいた！\n", zako2.name);
						EnemySpellFlag = Disable;
						player.attack += 2;
					}
					else {
						printf("%sは　まるで　きいていない！\n", zako2.name);
					}
					getchar();
					zako2attack(EnemySpellFlag);
				}
				if (CHALLENGE_TYPE == 3) {
					printf("%s:言いたいことは…いくつか…あるんだよ…\n　　　　 ま…一言で言うなら\n　　　　 本気にさせたな\n", player.name);
					getchar();
					if (CHALLENGE_SUCCESSLATE >= 30) {
						printf("%sは　おそれ　おののいた！\n", zako2.name);
						EnemySpellFlag = Disable;
						player.attack += 2;
					}
					else {
						printf("%sは　まるで　きいていない！\n", zako2.name);
					}
					getchar();
					zako2attack(EnemySpellFlag);
				}
				break;
			case COMMAND_DEFENCE:
				system("cls");
				display_zako2();
				printf("%sは　みをまもっている\n", player.name);
				getchar();
				zako2.attack /= 2;
				zako2attack(EnemySpellFlag);
				zako2.attack *= 2;
				break;
			default:
				printf("ERROR!\nみじっそうのコマンド\n");
				break;
			case COMMAND_SPELL:
				spell_vszako2();
				if (zako2.hp > 0 && Spell_dontUse == Disable) zako2attack(EnemySpellFlag);
				else if (Spell_dontUse == Enable) Spell_dontUse = Disable;
				break;
			case COMMAND_PARRY:
				system("cls");
				display_zako2();
				printf("%sは　パリィを　こころみた！\n", player.name);
				getchar();
				system("cls");
				display_zako2();
				printf("%sの　こうげき！\n", zako2.name);
				printf("\nふりおろされた　つえのさきがせまってくる…", zako2.name);
				getchar();
				int randomNum = 0;
				while (_kbhit() != 1) {
					randomNum = 10 + genrand_int32() % 90;
					printf("\r%d", randomNum);
				}
				getchar();
				if (randomNum >= 50) {
					printf("\nパリィ　せいこう！\n");
					getchar();
					int ATTACK_DAMAGE;
					if (randomNum >= 95) {
						printf("SMAAAASH!!");
						getchar();
						ATTACK_DAMAGE = player.attack * 4 + (genrand_int32() % 3);
						zako2.hp -= ATTACK_DAMAGE;
					}
					else {
						ATTACK_DAMAGE = player.attack * 2 + (genrand_int32() % 3);
						zako2.hp -= ATTACK_DAMAGE;
					}
					display_zako2();
					printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako2.name, ATTACK_DAMAGE);
					getchar();
					if (zako2.hp <= 0) {
						system("cls");
						printf(" ┌――――┐\n");
						printf(" │%s│\n", player.name);
						printf(" ├――――┤\n");
						if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
						else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
						else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
						else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
						if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
						else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
						else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
						printf(" └――――┘\n");
						printf("\n\n\n\n");
						printf("%sを　たおした！\n", zako2.name);
						cleared2 = {
							default.hp,
							default.maxHp,
							default.mp,
							default.maxMp,
							"えにくす",
							default.attack,
							default.defence,
							default.intelligence
						};
						zako2WinFlag = Enable;
						getchar();
					}
				}
				else {
					printf("\nパリィ　しっぱい！\n");
					getchar();
					int ATTACK_DAMAGE = zako2.attack * 2 + (genrand_int32() % 3);
					player.hp -= ATTACK_DAMAGE;
					display_zako2();
					printf("%sは　%dポイントの\nダメージを　うけた！\n", player.name, ATTACK_DAMAGE);
					getchar();
					if (player.hp <= 0) {
						getchar();
						display_zako2();
						printf("%sは　しんでしまった！\n", player.name);
						getchar();
						printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
						getchar();
						return 0;
					}
				}
				break;
			}
			phase = PHASE_COMMAND;
			break;
		}
	}
	player = {
		default.hp,
		default.maxHp,
		default.mp,
		default.maxMp,
		"えにくす",
		default.attack,
		default.defence,
		default.intelligence
	};
	cleared2 = {
		player.hp,
		player.maxHp,
		player.mp,
		player.maxMp,
		"えにくす",
		player.attack,
		player.defence,
		player.intelligence
	};
}


void display_zako3()
{
	system("cls");
	if (player.hp <= 0) {
		HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(
			hConsoleOutput, // HANDLE hConsoleOutput
			FOREGROUND_RED | FOREGROUND_INTENSITY);// WORD wAttributes
		printf(" ┌――――┐\n");
		printf(" │%s│\n", player.name);
		printf(" ├――――┤\n");
		if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
		else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
		else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
		else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
		if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
		else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
		else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
		printf(" └――――┘\n");
	}
	else {
		HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(
			hConsoleOutput, // HANDLE hConsoleOutput
			FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);// WORD wAttributes
		printf(" ┌――――┐\n");
		printf(" │%s│\n", player.name);
		printf(" ├――――┤\n");
		if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
		else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
		else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
		else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
		if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
		else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
		else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
		printf(" └――――┘\n");
	}
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(
		hConsoleOutput, // HANDLE hConsoleOutput
		FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);


	printf("\n	　　　_”￢干干干＼\n");
	printf("	　　／十十十十十十ﾍ\n");
	printf("	　`/十十十十十十十ﾁ|\n");
	printf("	　├十十十十十十十千|\n");
	printf("	　|-十十十十十十十千|\n");
	printf("	　|-十十-|＼土十土／|\n");
	printf("	　├十十-ヽ ＼干／//\n");
	printf("	　├-ヽ 十干干 >干/\n");
	printf("	　├十 ﾍ十十十十／\n");
	printf("	　|-十十＼十十／\n");
	printf("	　|-十十十+干(＼-＿\n");
	printf("\n	 　　%s\n\n HP \n", zako3.name);
	int hpdisp_blank = zako3.maxHp;
	hpdisp = zako3.hp;
	while (hpdisp_blank > 0) {
		printf("□");
		hpdisp_blank -= 7;
	}
	printf("\r");
	while (hpdisp > 0) {
		printf("■");
		hpdisp -= 7;
	}
	printf("\n\n\n");
}

void playerattack_vszako3()
{
	system("cls");
	display_zako3();
	printf("%sの　こうげき！\n", player.name);
	while (_kbhit() != 1) {
		randomNum = 10 + genrand_int32() % 90;
		printf("\r%d", randomNum);
	}
	getchar();
	int attackNum = randomNum;
	getchar();
	int ATTACK_CRITICAL = attackNum;
	int ATTACK_RANDOM = attackNum / 10;
	if (ATTACK_RANDOM >= 0 && ATTACK_RANDOM < 4) ATTACK_RANDOM = 1;
	else if (ATTACK_RANDOM >= 4 && ATTACK_RANDOM < 7) ATTACK_RANDOM = 2;
	else if (ATTACK_RANDOM >= 7 && ATTACK_RANDOM < 10) ATTACK_RANDOM = 3;
	int ATTACK_DAMAGE = player.attack / 2 + ATTACK_RANDOM + 7 - zako3.defence / 4;
	if (ATTACK_DAMAGE <= 0) ATTACK_DAMAGE = 1;
	if (ATTACK_CRITICAL >= 95) {
		ATTACK_DAMAGE = player.attack * 2 + (genrand_int32() % 3);
		printf("SMAAAASH!!");
		getchar();
	}
	zako3.hp -= ATTACK_DAMAGE;
	display_zako3();
	printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako3.name, ATTACK_DAMAGE);
	getchar();
	if (zako3.hp <= 0) {
		system("cls");
		printf(" ┌――――┐\n");
		printf(" │%s│\n", player.name);
		printf(" ├――――┤\n");
		if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
		else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
		else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
		else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
		if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
		else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
		else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
		printf(" └――――┘\n");
		printf("%sを　たおした！\n", zako3.name);
		zako3WinFlag = Enable;
		cleared3 = {
			default.hp,
			default.maxHp,
			default.mp,
			default.maxMp,
			"えにくす",
			default.attack,
			default.defence,
			default.intelligence
		};
		getchar();
		return;
	}
}

int zako3attack(int EnemySpellFlag)
{
	system("cls");
	display_zako3();
	int ATTACK_PATTERN = genrand_int32() % 99 + 1;
	if (zako3.hp <= 12) {
		printf("%sの　すてみのこうげき！\n", zako3.name);
		getchar();
		printf("%s: Ultimate... Web! Throw!\n", zako3.name);
		getchar();
		system("cls");
		display_zako3();
		printf("%sの　いとが　%sの　みうごきをふうじる！\n", zako3.name, player.name);
		getchar();
		printf("\n%sは　そのまま　%sを　じめんに　たたきつけた！\n", zako3.name, player.name);
		getchar();
		int ATTACK_DAMAGE = zako3.attack + (genrand_int32() % 10) + 1 - player.defence / 2;
		player.hp -= ATTACK_DAMAGE;
		display_zako3();
		printf("%sに　%dポイントの\nダメージを　あたえた！\n", player.name, ATTACK_DAMAGE);
		getchar();
		printf("\n%s: DOES WHAT A SPIDER CAN!!\n", zako3.name);
		getchar();
		if (player.hp <= 0) {
			display_zako3();
			printf("%sは　しんでしまった！\n", player.name);
			getchar();
			printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
			getchar();
			return 0;
		}
		return 0;
	}
	else if (ATTACK_PATTERN <= 50) {
		printf("%sの　こうげき！\n", zako3.name);
		getchar();
		if (genrand_int32() % 16 == 0) {
			printf("\n%sは　こうげきを　かわした！　%sはダメージを　あたえられない！", player.name, zako3.name);
			getchar();
			return 0;
		}
		int ATTACK_DAMAGE = zako3.attack / 2 + (genrand_int32() % 3) + 1 - player.defence / 4;
		int ATTACK_CRITICAL = genrand_int32() % 100 + 1;
		if (ATTACK_DAMAGE <= 0) ATTACK_DAMAGE = 1;
		if (ATTACK_CRITICAL >= 98) {
			ATTACK_DAMAGE = zako3.attack + (genrand_int32() % 3) + 1;
			printf("SMAAAASH!!");
			getchar();
		}
		player.hp -= ATTACK_DAMAGE;
		display_zako3();
		printf("%sに　%dポイントの\nダメージを　あたえた！\n", player.name, ATTACK_DAMAGE);
		getchar();
		if (player.hp <= 0) {
			display_zako3();
			printf("%sは　しんでしまった！\n", player.name);
			getchar();
			printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
			getchar();
			return 0;
		}
		else {
			return 0;
		}
	}
	else if (ATTACK_PATTERN > 50) {
		printf("%sは　ちょうはつをした！\n\n", zako3.name);
		getchar();
		if (ATTACK_PATTERN < 70) {
			printf("%s: Next time maybe you should cast a spell that'll make you not suck.\n", zako3.name);
			printf("　　　　　  - そのダサいルックスをもう少しマシにする呪文ってないのかい？ -\n");
			getchar();
			player.intelligence -= player.intelligence / 5;
			printf("%sは　こころに　ふかいきずを　おった！\n", player.name);
			getchar();
		}
		else if (ATTACK_PATTERN > 70 && ATTACK_PATTERN < 90) {
			printf("%s:　 Sorry lil' guy. Beating you up is like stepping on a kitten.\n　　　　　　　- ゴメンよ。君を倒すのって子猫ちゃんを踏むみたいな罪悪感があるんだ。-\n", zako3.name);
			getchar();
			player.intelligence -= player.intelligence / 10;
			printf("%sは　こころに　きずを　おった！\n", player.name);
			getchar();
		}
		else {
			printf("%s: Just a little needs up... I wouldn't pick up\n　　　　　  the Daily Bugles tomorrow if I were you.\n", zako3.name);
			printf("　　　　　  - えーと、警告ってほどの話ではないけどさ。-\n　　　　　  - 明日のデイリー・ビューグル紙は買わない方いいと思うな。 -\n");
			getchar();
			printf("%sは　ひにくのいみを　りかいしていない！\n%sのちょうはつは　きかなかった！", player.name, zako3.name);
			getchar();
		}
		return 0;
	}
}

void spell_vszako3()
{
	int EnterFlagS = Disable;
	system("cls");
	display_zako3();
	enum {
		SPELL_ATTACK,
		SPELL_ATTACK2,
		SPELL_HYPERATTACK,
		SPELL_HEAL,
		SPELL_BUFF,
		SPELL_SLASH,
		SPELL_DONT_USE,
		SPELL_MAX			//じゅもんの数
	};
	char spellNames[][16] = {
		"メラゾーマ",
		"マヒャド",
		"メドローア",
		"ホイミ",
		"スカラ",
		"しんくうぎり",
		"もどる"
	};
	int commandS = SPELL_ATTACK;
	while (EnterFlagS == Disable) {
		system("cls");
		display_zako3();
		printf("じゅもん\n");
		for (int i = 0; i < SPELL_MAX; i++) {
			if (i == commandS) {
				printf("＞%s\n", spellNames[i]);
			}
			else {
				printf("　%s\n", spellNames[i]);
			}
		}
		switch (commandS) {
		case SPELL_ATTACK:
			printf("\nしょうひMP:10\nきょだいな　ひのたまを　ぶつける");
			break;
		case SPELL_ATTACK2:
			printf("\nしょうひMP:12\nこおりの　あらしによって　てきを　いてつかせる");
			break;
		case SPELL_HEAL:
			printf("\nしょうひMP:2\nじぶんの　HPを　かいふくする");
			break;
		case SPELL_BUFF:
			printf("\nしょうひMP:3\nじぶんの　ぼうぎょりょくを　じょうしょうさせる");
			break;
		case SPELL_SLASH:
			printf("\nしょうひMP:5\nたつまきの　ちからをけんにのせ　きりかかる");
			break;
		case SPELL_HYPERATTACK:
			printf("\nしょうひMP:50\nほのおと　こおりの　ちからをスパークさせ\nふれたものを　しょうめつさせる　ひかりのやをうちだす");
			break;
		case SPELL_DONT_USE:
			printf("\nじゅもんをつかうのをやめる");
			break;
		}
		switch (_getch()) {
		case 0x0d:
			EnterFlagS = Enable;
			break;
		case 0xe0:
			switch (_getch()) {
			case 0x48:
				if (commandS != SPELL_ATTACK) commandS--;
				else if (commandS == SPELL_ATTACK) commandS = SPELL_MAX - 1;
				break;
			case 0x50:
				if (commandS != SPELL_MAX) commandS++;
				if (commandS == SPELL_MAX) commandS = SPELL_ATTACK;
				break;
			}
			break;
		}
	}
	switch (commandS) {
	case SPELL_ATTACK:
		system("cls");
		display_zako3();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[0]);
		getchar();
		if (player.mp < 10) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 10;
			int SPELL_DAMAGE;
			if (player.intelligence < 18) {
				SPELL_DAMAGE = player.intelligence * 2 + genrand_int32() % 6 - zako3.intelligence;
			}
			else
			{
				SPELL_DAMAGE = player.intelligence * 2 + genrand_int32() % (player.intelligence / 3) - zako3.intelligence;
			}
			if (SPELL_DAMAGE <= 0) SPELL_DAMAGE = 1;
			zako3.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako3();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako3.name, SPELL_DAMAGE);
			getchar();
			if (zako3.hp <= 0) {
				system("cls");
				printf(" ┌――――┐\n");
				printf(" │%s│\n", player.name);
				printf(" ├――――┤\n");
				if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
				else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
				else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
				else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
				if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
				else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
				else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
				printf(" └――――┘\n");
				printf("\n\n\n\n");
				printf("%sを　たおした！\n", zako3.name);
				zako3WinFlag = Enable;
				cleared3 = {
					default.hp,
					default.maxHp,
					default.mp,
					default.maxMp,
					"えにくす",
					default.attack,
					default.defence,
					default.intelligence
				};
				getchar();
				return;
			}
		}
		break;
	case SPELL_ATTACK2:
		system("cls");
		display_zako3();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[1]);
		getchar();
		if (player.mp < 12) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 12;
			int SPELL_DAMAGE;
			SPELL_DAMAGE = 10 + player.intelligence + genrand_int32() % 10 - zako3.intelligence;
			if (SPELL_DAMAGE <= 0) SPELL_DAMAGE = 1;
			zako3.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako3();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako3.name, SPELL_DAMAGE);
			getchar();
			if (zako3.hp > 0 && (genrand_int32() % 2) == 0) {
				printf("%sの　からだのいちぶを　こおらせた！\n", zako3.name);
				zako3.attack -= zako3.attack / 10;
				getchar();
			}
			if (zako3.hp <= 0) {
				system("cls");
				printf(" ┌――――┐\n");
				printf(" │%s│\n", player.name);
				printf(" ├――――┤\n");
				if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
				else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
				else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
				else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
				if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
				else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
				else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
				printf(" └――――┘\n");
				printf("\n\n\n\n");
				printf("%sを　たおした！\n", zako3.name);
				zako3WinFlag = Enable;
				cleared3 = {
					default.hp,
					default.maxHp,
					default.mp,
					default.maxMp,
					"えにくす",
					default.attack,
					default.defence,
					default.intelligence
				};
				getchar();
				return;
			}
		}
		break;
	case SPELL_HEAL:
		system("cls");
		display_zako3();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[3]);
		getchar();
		if (player.mp < 2) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 2;
			int SPELL_RECOVER = player.maxHp / 8 + player.intelligence + genrand_int32() % player.intelligence;
			if (SPELL_RECOVER + player.hp > player.maxHp) SPELL_RECOVER = player.maxHp - player.hp;
			player.hp += SPELL_RECOVER;
			system("cls");
			display_zako3();
			printf("%sは　%dポイント　かいふくした！\n", player.name, SPELL_RECOVER);
			getchar();
		}
		break;
	case SPELL_BUFF:
		system("cls");
		display_zako3();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[4]);
		getchar();
		if (player.mp < 3) {
			printf("しかし　MPがたりない！\n");
			getchar();
			break;
		}
		else {
			player.mp -= 3;
			player.defence += (player.defence * 2) / 5;
			system("cls");
			display_zako3();
			printf("%sの　ぼうぎょりょくが　あがった！\n", player.name);
			Spell_buffFlag = Enable;
			getchar();
		}
		break;
	case SPELL_SLASH:
		system("cls");
		display_zako3();
		printf("%sは　%sをはなった！\n", player.name, spellNames[5]);
		getchar();
		if (player.mp < 5) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 5;
			int SPELL_DAMAGE;
			SPELL_DAMAGE = 5 + player.attack + player.intelligence + genrand_int32() % 5 - zako3.defence / 8 - zako3.intelligence / 8;
			if (SPELL_DAMAGE <= 0) SPELL_DAMAGE = 1;
			zako3.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako3();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako3.name, SPELL_DAMAGE);
			getchar();
			if (zako3.hp <= 0) {
				system("cls");
				printf(" ┌――――┐\n");
				printf(" │%s│\n", player.name);
				printf(" ├――――┤\n");
				if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
				else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
				else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
				else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
				if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
				else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
				else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
				printf(" └――――┘\n");
				printf("\n\n\n\n");
				printf("%sを　たおした！\n", zako3.name);
				cleared3 = {
					default.hp,
					default.maxHp,
					default.mp,
					default.maxMp,
					"えにくす",
					default.attack,
					default.defence,
					default.intelligence
				};
				zako3WinFlag = Enable;
				getchar();
				return;
			}
		}
		break;
	case SPELL_HYPERATTACK:
		system("cls");
		display_zako3();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[2]);
		getchar();
		if (player.mp < 50) {
			printf("しかし　MPがたりない！\n");
			getchar();
			break;
		}
		else {
			printf("\nメラゾーマと　マヒャドがまじりあい\n%sとなる！\n", spellNames[2]);
			getchar();
			player.mp -= 50;
			int SPELL_DAMAGE;
			SPELL_DAMAGE = zako3.hp / 2 + genrand_int32() % 5;
			if (SPELL_DAMAGE <= 0) SPELL_DAMAGE = 1;
			zako3.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako3();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako3.name, SPELL_DAMAGE);
			getchar();
			if (zako3.hp <= 0) {
				system("cls");
				printf(" ┌――――┐\n");
				printf(" │%s│\n", player.name);
				printf(" ├――――┤\n");
				if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
				else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
				else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
				else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
				if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
				else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
				else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
				printf(" └――――┘\n");
				printf("\n\n\n\n");
				printf("%sを　たおした！\n", zako3.name);
				zako3WinFlag = Enable;
				cleared3 = {
					default.hp,
					default.maxHp,
					default.mp,
					default.maxMp,
					"えにくす",
					default.attack,
					default.defence,
					default.intelligence
				};
				getchar();
				return;
			}
		}
		break;
	case SPELL_DONT_USE:
		Spell_dontUse = Enable;
		return;
	}
	return;
}

int vszako3() {
	default = {
		player.hp,
		player.maxHp,
		player.mp,
		player.maxMp,
		"えにくす",
		player.attack,
		player.defence,
		player.intelligence
	};
	init_genrand((unsigned)time(NULL));
	zako3.hp = zako3.maxHp;
	zako3.attack = 35;
	display_zako3();
	command = COMMAND_ATTACK;
	phase = PHASE_COMMAND;
	Spell_buffFlag = Disable;
	EnemySpellFlag = Enable;
	enum {
		SPELL_ATTACK,
		SPELL_HEAL,
		SPELL_BUFF,
		SPELL_SLASH,
		SPELL_DONT_USE,
		SPELL_MAX			//じゅもんの数
	};
	int commandS = SPELL_ATTACK;
	printf("%sが　あらわれた！\n", zako3.name);
	getchar();
	printf("\n%s: 地獄からの使者、蜘蛛男！\n", zako3.name);
	command = COMMAND_ATTACK;
	commandS = SPELL_ATTACK;
	phase = PHASE_COMMAND;
	Spell_buffFlag = Disable;
	EnemySpellFlag = Disable;
	getchar();
	while ((player.hp > 0) && (zako3.hp > 0)) {
		int EnterFlag = Disable;
		switch (phase) {
		case PHASE_COMMAND:
			while (EnterFlag == Disable) {
				system("cls");
				display_zako3();
				printf("コマンド？\n");
				for (int i = 0; i < COMMAND_MAX; i++) {
					if (i == command) {
						printf("＞%s\n", commandNames[i]);
					}
					else {
						printf("　%s\n", commandNames[i]);
					}
				}
				//コマンド説明
				switch (command) {
				case COMMAND_ATTACK:
					printf("\nこうげきをする");
					break;
				case COMMAND_SPELL:
					printf("\nMPをしょうひして\nじゅもんをつかう");
					break;
				case COMMAND_CHALLENGE:
					printf("\nあいてを　いあつして\nあいてのじゅもんや　こうげきを　ぼうがいする");
					break;
				case COMMAND_PARRY:
					printf("\nあいてのこうげきを　はじいて\nだいダメージを　ねらう");
					break;
				case COMMAND_ESCAPE:
					printf("\nとうぼうをこころみる");
					break;
				case COMMAND_DEFENCE:
					printf("\nぼうぎょをする");
					break;
				}
				switch (_getch()) {
				case 0x0d:
					EnterFlag = Enable;
					break;
				case 0xe0:
					switch (_getch()) {
					case 0x48:
						if (command != COMMAND_ATTACK) command--;
						else if (command == COMMAND_ATTACK) command = COMMAND_MAX - 1;
						break;
					case 0x50:
						if (command != COMMAND_MAX) command++;
						if (command == COMMAND_MAX) command = COMMAND_ATTACK;
						break;
					}
					break;
				}
			}
			phase = PHASE_BATTLE;
			break;
		case PHASE_BATTLE:
			int CHALLENGE_TYPE = 0;
			int CHALLENGE_SUCCESSLATE = 0;
			int escapeNum = 0;
			system("cls");
			display_zako3();
			switch (command) {
			case COMMAND_ATTACK:
				if (player.hp > 0) playerattack_vszako3();
				if (zako3.hp > 0) zako3attack(EnemySpellFlag);
				break;
			case COMMAND_ESCAPE:
				printf("%sは　にげだした！\n", player.name);
				while (_kbhit() != 1) {
					randomNum = 10 + genrand_int32() % 90;
					printf("\r%d", randomNum);
				}
				getchar();
				escapeNum = randomNum;
				getchar();
				if (escapeNum < 34) {
					printf("しかし　まわりこまれた！\n");
					getchar();
					if (zako3.hp > 0) {
						zako3attack(EnemySpellFlag);
					}
					break;
				}
				else {
					printf("うまく　にげきれた！\n");
					player = {
						default.hp,
						default.maxHp,
						default.mp,
						default.maxMp,
						"えにくす",
						default.attack,
						default.defence,
						default.intelligence
					};
					getchar();
					return 0;
				}
			case COMMAND_CHALLENGE:
				system("cls");
				display_zako3();
				printf("%sは　ちょうはつした！\n", player.name);
				getchar();
				CHALLENGE_TYPE = genrand_int32() % 3 + 1;
				CHALLENGE_SUCCESSLATE = genrand_int32() % 100 + 1;
				if (CHALLENGE_TYPE == 1) {
					printf("%s:俺が殺せると思っているのなら\n　　　　 やってみるがいい…！\n", player.name);
					getchar();
					printf("%s:　 Great power comes great beat down!\n　　　　　 - 大いなる力には……大いなる戦いが伴うのさ！-\n", zako3.name);
					printf("\n%sは　まるで　きいていない！\n", zako3.name);
					getchar();
					zako3attack(EnemySpellFlag);
				}
				if (CHALLENGE_TYPE == 2) {
					printf("%s:オレは戦うのが好きなんじゃねぇんだ…。\n　　　　 勝つのが好きなんだよォォッ！！\n", player.name);
					getchar();
					printf("%s:　 Sorry lil' guy. Beating you up is like　stepping on a kitten.\n　　　　　  - ゴメンよ。君を倒すのって子猫ちゃんを踏むみたいな罪悪感があるんだ。-\n", zako3.name);
					printf("\n%sは　まるで　きいていない！\n", zako3.name);
					getchar();
					zako3attack(EnemySpellFlag);
				}
				if (CHALLENGE_TYPE == 3) {
					printf("%s:言いたいことは…いくつか…あるんだよ…\n　　　　 ま…一言で言うなら\n　　　　 本気にさせたな\n", player.name);
					getchar();
					printf("%s:　 You've got a black belt in stupid if you think you can beat me.\n　　　　　 - 僕を倒すことできるって…バカ何段？-\n", zako3.name);
					printf("\n%sは　まるで　きいていない！\n", zako3.name);
					getchar();
					zako3attack(EnemySpellFlag);
				}
				break;
			case COMMAND_DEFENCE:
				system("cls");
				display_zako3();
				printf("%sは　みをまもっている\n", player.name);
				getchar();
				zako3.attack /= 2;
				zako3attack(EnemySpellFlag);
				zako3.attack *= 2;
				break;
			default:
				printf("ERROR!\nみじっそうのコマンド\n");
				break;
			case COMMAND_SPELL:
				spell_vszako3();
				if (zako3.hp > 0 && Spell_dontUse == Disable) zako3attack(EnemySpellFlag);
				else if (Spell_dontUse == Enable) Spell_dontUse = Disable;
				break;
			case COMMAND_PARRY:
				system("cls");
				display_zako3();
				printf("%sは　パリィを　こころみた！\n", player.name);
				getchar();
				system("cls");
				display_zako3();
				printf("%sの　こうげき！\n", zako3.name);
				printf("\n%sの　こぶしが\nうなりをあげて　せまってくる…", zako3.name);
				getchar();
				int randomNum = 0;
				while (_kbhit() != 1) {
					randomNum = 10 + genrand_int32() % 90;
					printf("\r%d", randomNum);
				}
				getchar();
				if (randomNum >= 50) {
					printf("\nパリィ　せいこう！\n");
					getchar();
					int ATTACK_DAMAGE;
					if (randomNum >= 95) {
						printf("SMAAAASH!!");
						getchar();
						ATTACK_DAMAGE = player.attack * 4 + (genrand_int32() % 3);
						zako3.hp -= ATTACK_DAMAGE;
					}
					else {
						ATTACK_DAMAGE = player.attack * 2 + (genrand_int32() % 3);
						zako3.hp -= ATTACK_DAMAGE;
					}
					display_zako3();
					printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako3.name, ATTACK_DAMAGE);
					getchar();
					if (zako3.hp <= 0) {
						system("cls");
						printf(" ┌――――┐\n");
						printf(" │%s│\n", player.name);
						printf(" ├――――┤\n");
						if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
						else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
						else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
						else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
						if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
						else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
						else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
						printf(" └――――┘\n");
						printf("\n\n\n\n");
						printf("%sを　たおした！\n", zako3.name);
						getchar();
						zako3WinFlag = Enable;
						player = {
							default.hp,
							default.maxHp,
							default.mp,
							default.maxMp,
							"えにくす",
							default.attack,
							default.defence,
							default.intelligence
						};

						cleared3 = {
							player.hp,
							player.maxHp,
							player.mp,
							player.maxMp,
							"えにくす",
							player.attack,
							player.defence,
							player.intelligence
						};
						return 0;
					}
				}
				else {
					printf("\nパリィ　しっぱい！\n");
					getchar();
					int ATTACK_DAMAGE = zako3.attack + (genrand_int32() % 3);
					player.hp -= ATTACK_DAMAGE;
					display_zako3();
					printf("%sは　%dポイントの\nダメージを　うけた！\n", player.name, ATTACK_DAMAGE);
					getchar();
					if (player.hp <= 0) {
						getchar();
						display_zako3();
						printf("%sは　しんでしまった！\n", player.name);
						getchar();
						printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
						getchar();
						return 0;
					}
				}
				break;
			}
			phase = PHASE_COMMAND;
			break;
		}
	}
	player = {
		default.hp,
		default.maxHp,
		default.mp,
		default.maxMp,
		"えにくす",
		default.attack,
		default.defence,
		default.intelligence
	};
	cleared3 = {
		player.hp,
		player.maxHp,
		player.mp,
		player.maxMp,
		"えにくす",
		player.attack,
		player.defence,
		player.intelligence
	};
	return 0;
}

void display_zako4()
{
	system("cls");
	if (TimeStopFlag == Enable) {
		HANDLE TimeStop = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(
			TimeStop, // HANDLE hConsoleOutput
			BACKGROUND_INTENSITY);
		printf(" ┌――――┐\n");
		printf(" │%s│\n", player.name);
		printf(" ├――――┤\n");
		if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
		else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
		else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
		else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
		if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
		else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
		else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
		printf(" └――――┘\n");
	}
	else {
		if (player.hp <= 0) {
			HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(
				hConsoleOutput, // HANDLE hConsoleOutput
				FOREGROUND_RED | FOREGROUND_INTENSITY);// WORD wAttributes
			printf(" ┌――――┐\n");
			printf(" │%s│\n", player.name);
			printf(" ├――――┤\n");
			if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
			else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
			else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
			else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
			if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
			else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
			else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
			printf(" └――――┘\n");
		}
		else {
			HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(
				hConsoleOutput, // HANDLE hConsoleOutput
				FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);// WORD wAttributes
			printf(" ┌――――┐\n");
			printf(" │%s│\n", player.name);
			printf(" ├――――┤\n");
			if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
			else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
			else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
			else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
			if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
			else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
			else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
			printf(" └――――┘\n");
		}
		printf("\x1b[49m");
		HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(
			hConsoleOutput, // HANDLE hConsoleOutput
			FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	if (zako4.hp > 180) {
		printf("\n");
		printf("	　 ,ノ ﾘL／〃Lｰ~ｰ~　ム\n");
		printf("	　ﾉ　　゛゛ｰ<　゛―￣二\n");
		printf("	<゛ｰ　゛_ｰ~　　゛゛　゛\n");
		printf("	　ゝｰ'　~　,⌒　　ゝ―\n");
		printf("	(〃 　､､､ﾉﾉ|ﾄ ヾ゛゛\n");
		printf("	')　〃ミｨｲｨ彡\"ﾕ | ~＼〃~ｰ_\n");
		printf("	(　\"<べ､ | ;;　 \"ｳ)　~ｰヾ\n");
		printf("	､ゞノ⌒ﾍﾞ￣　 ､ ＼,　\n");
		printf("	'((､　　L∠ _ノ　/\n");
		printf("	　'ｰ~　　　'ヾ＿/､\n");
		printf("	　　　　　 　　< ﾉ\n");
		printf("	　　　　　 ,ｰ'~,,\n");
		printf("	　　　　／　　,★\n");
		printf("	　　　 /　゛　　\"\n");
		printf("	　　　｜　　\"\n");
	}
	else {
		printf("\n");
		printf("	   　 ／/ _-~７／/／| ﾊ\n");
		printf("	  　 { {／ﾊ　y'　ﾚ /ﾚ' |\n");
		printf("	   ／/ \"ﾍ゛ﾊ／ / ハ　゛ / / \n");
		printf("	　(\"<ヾ ﾊ゛{ ゛ }　ﾊ　｜７\n");
		printf("	　<ﾊ ヾﾍﾍヾヾヽノ }ﾍ\" ７\n");
		printf("	　ﾉ_,ハ"")ﾉノ⌒-~'彡'ヽﾍ\n");
		printf("	（( ~ }ﾐ }} ﾐノヾ　r-､彡\n");
		printf("	　ﾘ 　ﾍﾄ､ﾍし_ｨﾁス　 G∥=\n");
		printf("	   　　ﾍﾐTﾘヾ￣ ﾐ　､nｿミ\n");
		printf("	　      Y/\"　　 ﾐ !じﾐヾ\n");
		printf("	　 　 _=ヾｰｨ　　　ﾉ　 ﾉ;\n");
		printf("	　　r~ヾ }ｰ=ｰ'　／ﾐ -;;;\n");
		printf("	　｛ ミ　ﾍ＿＿∠＿-;;;／\n");
		printf("	　　ﾍ　ﾐ／;;;;ヾ;;;_~;;;\n");
		printf("	　　 ヾ/;;;;;;;;ｰ~;;;;;;\n");
	}
	printf("\n	 　　　%s\n\n HP \n", zako4.name);
	int hpdisp_blank = zako4.maxHp;
	hpdisp = zako4.hp;
	while (hpdisp_blank > 0) {
		printf("□");
		hpdisp_blank -= 8;
	}
	printf("\r");
	while (hpdisp > 0) {
		printf("■");
		hpdisp -= 8;
	}
	printf("\n\n");
}

void playerattack_vszako4()
{
	system("cls");
	display_zako4();
	printf("%sの　こうげき！\n", player.name);
	while (_kbhit() != 1) {
		randomNum = 10 + genrand_int32() % 90;
		printf("\r%d", randomNum);
	}
	getchar();
	int attackNum = randomNum;
	getchar();
	int ATTACK_CRITICAL = attackNum;
	int ATTACK_RANDOM = attackNum / 10;
	if (ATTACK_RANDOM >= 0 && ATTACK_RANDOM < 4) ATTACK_RANDOM = 1;
	else if (ATTACK_RANDOM >= 4 && ATTACK_RANDOM < 7) ATTACK_RANDOM = 2;
	else if (ATTACK_RANDOM >= 7 && ATTACK_RANDOM < 10) ATTACK_RANDOM = 3;
	int ATTACK_DAMAGE = player.attack / 2 + ATTACK_RANDOM + 11 - zako4.defence / 4;
	if (ATTACK_DAMAGE <= 0) ATTACK_DAMAGE = 1;
	if (ATTACK_CRITICAL >= 95) {
		ATTACK_DAMAGE = player.attack * 2 + 11 + (genrand_int32() % 3);
		printf("SMAAAASH!!");
		getchar();
	}
	zako4.hp -= ATTACK_DAMAGE;
	display_zako4();
	printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako4.name, ATTACK_DAMAGE);
	getchar();
	if (zako4.hp <= 0) {
		system("cls");
		printf(" ┌――――┐\n");
		printf(" │%s│\n", player.name);
		printf(" ├――――┤\n");
		if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
		else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
		else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
		else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
		if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
		else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
		else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
		printf(" └――――┘\n");
		printf("\n\n\n\n");
		printf("%sを　たおした！\n", zako4.name);
		zako4WinFlag = Enable;
		getchar();
		return;
	}
}

int zako4attack(int EnemySpellFlag)
{

	system("cls");
	display_zako4();
	int ATTACK_PATTERN = genrand_int32() % 99 + 1;
	turnCount++;
	if (turnCount % 3 == 1) {
		printf("%sの　こうげき！\n", zako4.name);
		getchar();
		printf("%s: 『世界』ッ！　時よ止まれ！\n", zako4.name);
		getchar();

		HANDLE TimeStop = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(
			TimeStop, // HANDLE hConsoleOutput
			BACKGROUND_INTENSITY);// WORD wAttributes
		TimeStopFlag = Enable;
		system("cls");
		display_zako4();
		printf("とまった　ときのなかで　うごけるのは　%sだけだ！\n", zako4.name);
		getchar();
		int ATTACK_DAMAGE;
		if (zako4.hp < 18) {
			printf("%s:　ロードローラーだッ！\n", zako4.name);
			getchar();
			printf("%sは　%sを　ロードローラーで　つぶし　ラッシュをあびせた！\n", zako4.name, player.name);
			getchar();
			display_zako4();
			printf("%s:　無駄無駄無駄無駄無駄無駄無駄無駄無駄無駄無駄無駄ァーーーーーーッ\n", zako4.name);
			getchar();
			display_zako4();
			printf("%s:　そして　時は　動き出す…\n", zako4.name, player.name);
			getchar();
			ATTACK_DAMAGE = zako4.attack * 2 + (genrand_int32() % 10) + 1 - player.defence / 8;
			player.hp -= ATTACK_DAMAGE;
		}
		else {
			printf("%sは　%sに　こぶしで　ラッシュをあびせた！\n", zako4.name, player.name);
			getchar();
			display_zako4();
			printf("%s:そして　時は　動き出す…\n", zako4.name, player.name);
			getchar();
			ATTACK_DAMAGE = zako4.attack + (genrand_int32() % 10) + 1 - player.defence / 8;
			player.hp -= ATTACK_DAMAGE;
		}
		TimeStopFlag = Disable;
		printf("\x1b[49m");
		display_zako4();
		printf("%sに　%dポイントの\nダメージを　あたえた！\n", player.name, ATTACK_DAMAGE);
		getchar();
		if (player.hp <= 0) {
			display_zako4();
			printf("%sは　しんでしまった！\n", player.name);
			getchar();
			printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
			getchar();
			return 0;
		}
		return 0;
	}
	else {
		printf("%sの　こうげき！\n", zako4.name);
		getchar();
		if (genrand_int32() % 16 == 0) {
			printf("\n%sは　こうげきを　かわした！　%sはダメージを　あたえられない！", player.name, zako4.name);
			getchar();
			return 0;
		}
		if (ATTACK_PATTERN > 15) {
			int ATTACK_DAMAGE = zako4.attack / 2 + (genrand_int32() % 3) + 1 - player.defence / 4;
			int ATTACK_CRITICAL = genrand_int32() % 100 + 1;
			if (ATTACK_DAMAGE <= 0) ATTACK_DAMAGE = 1;
			if (ATTACK_CRITICAL >= 98) {
				ATTACK_DAMAGE = zako4.attack + (genrand_int32() % 3) + 1;
				printf("SMAAAASH!!");
				getchar();
			}
			player.hp -= ATTACK_DAMAGE;
			display_zako4();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", player.name, ATTACK_DAMAGE);
			getchar();
			if (player.hp <= 0) {
				display_zako4();
				printf("%sは　しんでしまった！\n", player.name);
				getchar();
				printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
				getchar();
				return 0;
			}
			else {
				return 0;
			}
		}
		if (ATTACK_PATTERN <= 15) {
			display_zako4();
			printf("%s:　ＷＲＹＹＹＹＹＹＹＹＹＹ！\n", zako4.name);
			getchar();
			printf("%sは　%sから　ちを　すいとった！\n", zako4.name, player.name);
			getchar();
			int ATTACK_DAMAGE = zako4.attack / 2 + (genrand_int32() % 5) + 1 - player.defence / 4;
			int ATTACK_CRITICAL = genrand_int32() % 100 + 1;
			if (ATTACK_DAMAGE <= 0) ATTACK_DAMAGE = 1;
			if (ATTACK_CRITICAL >= 98) {
				ATTACK_DAMAGE = zako4.attack + (genrand_int32() % 3) + 1;
				printf("SMAAAASH!!");
				getchar();
			}
			player.hp -= ATTACK_DAMAGE;
			zako4.hp += ATTACK_DAMAGE / 4;
			display_zako4();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", player.name, ATTACK_DAMAGE);
			getchar();
			if (player.hp <= 0) {
				display_zako4();
				printf("%sは　しんでしまった！\n", player.name);
				getchar();
				printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
				getchar();
				return 0;
			}
			else {
				return 0;
			}
		}
		return 0;
	}
}

void spell_vszako4()
{
	int EnterFlagS = Disable;
	system("cls");
	display_zako4();
	enum {
		SPELL_ATTACK,
		SPELL_ATTACK2,
		SPELL_HYPERATTACK,
		SPELL_HEAL,
		SPELL_BUFF,
		SPELL_SLASH,
		SPELL_DONT_USE,
		SPELL_MAX			//じゅもんの数
	};
	char spellNames[][16] = {
		"メラゾーマ",
		"マヒャド",
		"メドローア",
		"ベホイミ",
		"スカラ",
		"しんくうぎり",
		"もどる"
	};
	int commandS = SPELL_ATTACK;
	while (EnterFlagS == Disable) {
		system("cls");
		display_zako4();
		printf("じゅもん\n");
		for (int i = 0; i < SPELL_MAX; i++) {
			if (i == commandS) {
				printf("＞%s\n", spellNames[i]);
			}
			else {
				printf("　%s\n", spellNames[i]);
			}
		}
		switch (commandS) {
		case SPELL_ATTACK:
			printf("\nしょうひMP:10\nきょだいな　ひのたまを　ぶつける");
			break;
		case SPELL_ATTACK2:
			printf("\nしょうひMP:12\nこおりの　あらしによって　てきを　いてつかせる");
			break;
		case SPELL_HEAL:
			printf("\nしょうひMP:8\nじぶんの　HPを　おおきくかいふくする");
			break;
		case SPELL_BUFF:
			printf("\nしょうひMP:3\nじぶんの　ぼうぎょりょくを　じょうしょうさせる");
			break;
		case SPELL_SLASH:
			printf("\nしょうひMP:5\nたつまきの　ちからをけんにのせ　きりかかる");
			break;
		case SPELL_HYPERATTACK:
			printf("\nしょうひMP:50\nほのおと　こおりの　ちからをスパークさせ\nふれたものを　しょうめつさせる　ひかりのやをうちだす");
			break;
		case SPELL_DONT_USE:
			printf("\nじゅもんをつかうのをやめる");
			break;
		}
		switch (_getch()) {
		case 0x0d:
			EnterFlagS = Enable;
			break;
		case 0xe0:
			switch (_getch()) {
			case 0x48:
				if (commandS != SPELL_ATTACK) commandS--;
				else if (commandS == SPELL_ATTACK) commandS = SPELL_MAX - 1;
				break;
			case 0x50:
				if (commandS != SPELL_MAX) commandS++;
				if (commandS == SPELL_MAX) commandS = SPELL_ATTACK;
				break;
			}
			break;
		}
	}
	switch (commandS) {
	case SPELL_ATTACK:
		system("cls");
		display_zako4();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[0]);
		getchar();
		if (player.mp < 10) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 10;
			int SPELL_DAMAGE;
			if (player.intelligence < 18) {
				SPELL_DAMAGE = player.intelligence * 3 + genrand_int32() % 6 - zako4.intelligence;
			}
			else
			{
				SPELL_DAMAGE = player.intelligence * 3 + genrand_int32() % (player.intelligence / 3) - zako4.intelligence;
			}
			if (SPELL_DAMAGE <= 0) SPELL_DAMAGE = 1;
			zako4.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako4();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako4.name, SPELL_DAMAGE);
			getchar();
			if (zako4.hp <= 0) {
				system("cls");
				printf(" ┌――――┐\n");
				printf(" │%s│\n", player.name);
				printf(" ├――――┤\n");
				if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
				else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
				else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
				else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
				if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
				else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
				else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
				printf(" └――――┘\n");
				printf("\n\n\n\n");
				printf("%sを　たおした！\n", zako4.name);
				zako4WinFlag = Enable;
				getchar();
				return;
			}
		}
		break;
	case SPELL_ATTACK2:
		system("cls");
		display_zako4();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[1]);
		getchar();
		if (player.mp < 12) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 12;
			int SPELL_DAMAGE;
			SPELL_DAMAGE = 10 + player.intelligence * 2 + genrand_int32() % 10 - zako4.intelligence;
			if (SPELL_DAMAGE <= 0) SPELL_DAMAGE = 1;
			zako4.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako4();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako4.name, SPELL_DAMAGE);
			getchar();
			if (zako4.hp > 0 && (genrand_int32() % 2) == 0) {
				printf("%sの　からだのいちぶを　こおらせた！\n", zako4.name);
				zako4.attack -= zako4.attack / 10;
				getchar();
			}
			if (zako4.hp <= 0) {
				system("cls");
				printf(" ┌――――┐\n");
				printf(" │%s│\n", player.name);
				printf(" ├――――┤\n");
				if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
				else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
				else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
				else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
				if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
				else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
				else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
				printf(" └――――┘\n");
				printf("\n\n\n\n");
				printf("%sを　たおした！\n", zako4.name);
				zako4WinFlag = Enable;
				getchar();
				return;
			}
		}
		break;
	case SPELL_HEAL:
		system("cls");
		display_zako4();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[3]);
		getchar();
		if (player.mp < 8) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 8;
			int SPELL_RECOVER = 10 + player.maxHp / 3 + player.intelligence + genrand_int32() % 10;
			if (SPELL_RECOVER + player.hp > player.maxHp) SPELL_RECOVER = player.maxHp - player.hp;
			player.hp += SPELL_RECOVER;
			system("cls");
			display_zako4();
			printf("%sは　%dポイント　かいふくした！\n", player.name, SPELL_RECOVER);
			getchar();
		}
		break;
	case SPELL_BUFF:
		system("cls");
		display_zako4();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[4]);
		getchar();
		if (player.mp < 3) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 3;
			player.defence += (player.defence * 2) / 5;
			system("cls");
			display_zako4();
			printf("%sの　ぼうぎょりょくが　あがった！\n", player.name);
			Spell_buffFlag = Enable;
			getchar();
		}
		break;
	case SPELL_SLASH:
		system("cls");
		display_zako4();
		printf("%sは　%sをはなった！\n", player.name, spellNames[5]);
		getchar();
		if (player.mp < 5) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 5;
			int SPELL_DAMAGE;
			SPELL_DAMAGE = 5 + player.attack + player.intelligence + genrand_int32() % 5 - zako4.defence / 8 - zako4.intelligence / 8;
			if (SPELL_DAMAGE <= 0) SPELL_DAMAGE = 1;
			zako4.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako4();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako4.name, SPELL_DAMAGE);
			getchar();
			if (zako4.hp <= 0) {
				system("cls");
				printf(" ┌――――┐\n");
				printf(" │%s│\n", player.name);
				printf(" ├――――┤\n");
				if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
				else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
				else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
				else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
				if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
				else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
				else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
				printf(" └――――┘\n");
				printf("\n\n\n\n");
				printf("%sを　たおした！\n", zako4.name);
				zako4WinFlag = Enable;
				return;
			}
		}
		break;
	case SPELL_HYPERATTACK:
		system("cls");
		display_zako4();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[2]);
		getchar();
		if (player.mp < 50) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			printf("\nメラゾーマと　マヒャドがまじりあい\n%sとなる！\n", spellNames[2]);
			getchar();
			player.mp -= 50;
			int SPELL_DAMAGE;
			SPELL_DAMAGE = zako4.hp / 2 + genrand_int32() % 5;
			if (SPELL_DAMAGE <= 0) SPELL_DAMAGE = 1;
			zako4.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako4();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako4.name, SPELL_DAMAGE);
			getchar();
			if (zako4.hp <= 0) {
				system("cls");
				printf(" ┌――――┐\n");
				printf(" │%s│\n", player.name);
				printf(" ├――――┤\n");
				if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
				else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
				else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
				else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
				if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
				else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
				else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
				printf(" └――――┘\n");
				printf("\n\n\n\n");
				printf("%sを　たおした！\n", zako4.name);
				zako4WinFlag = Enable;
				return;
			}
		}
		break;
	case SPELL_DONT_USE:
		Spell_dontUse = Enable;
		return;
	}
	return;
}

int vszako4() {
	default = {
		player.hp,
		player.maxHp,
		player.mp,
		player.maxMp,
		"えにくす",
		player.attack,
		player.defence,
		player.intelligence
	};
	init_genrand((unsigned)time(NULL));
	zako4 = {
		270,
		270,
		50,
		50,
		"きゅうけつき",
		50,
		20,
		8
	};
	display_zako4();
	command = COMMAND_ATTACK;
	phase = PHASE_COMMAND;
	Spell_buffFlag = Disable;
	EnemySpellFlag = Enable;
	enum {
		SPELL_ATTACK,
		SPELL_HEAL,
		SPELL_BUFF,
		SPELL_SLASH,
		SPELL_DONT_USE,
		SPELL_MAX			//じゅもんの数
	};
	int commandS = SPELL_ATTACK;
	printf("%sが　あらわれた！\n", zako4.name);
	getchar();
	printf("\n%s: 君は…　普通の人間にはない　特別な能力を持っているそうだね？", zako4.name);
	getchar();
	printf("　　　　　　  ひとつ…　それを私に見せてくれるとうれしいのだが\n");
	command = COMMAND_ATTACK;
	commandS = SPELL_ATTACK;
	phase = PHASE_COMMAND;
	Spell_buffFlag = Disable;
	EnemySpellFlag = Disable;
	getchar();
	while ((player.hp > 0) && (zako4.hp > 0)) {
		int EnterFlag = Disable;
		switch (phase) {
		case PHASE_COMMAND:
			while (EnterFlag == Disable) {
				system("cls");
				display_zako4();
				printf("コマンド？\n");
				for (int i = 0; i < COMMAND_MAX; i++) {
					if (i == command) {
						printf("＞%s\n", commandNames[i]);
					}
					else {
						printf("　%s\n", commandNames[i]);
					}
				}
				//コマンド説明
				switch (command) {
				case COMMAND_ATTACK:
					printf("\nこうげきをする");
					break;
				case COMMAND_SPELL:
					printf("\nMPをしょうひして\nじゅもんをつかう");
					break;
				case COMMAND_CHALLENGE:
					printf("\nあいてを　いあつして\nあいてのじゅもんや　こうげきを　ぼうがいする");
					break;
				case COMMAND_PARRY:
					printf("\nあいてのこうげきを　はじいて\nだいダメージを　ねらう");
					break;
				case COMMAND_ESCAPE:
					printf("\nとうぼうをこころみる");
					break;
				case COMMAND_DEFENCE:
					printf("\nぼうぎょをする");
					break;
				}
				switch (_getch()) {
				case 0x0d:
					EnterFlag = Enable;
					break;
				case 0xe0:
					switch (_getch()) {
					case 0x48:
						if (command != COMMAND_ATTACK) command--;
						else if (command == COMMAND_ATTACK) command = COMMAND_MAX - 1;
						break;
					case 0x50:
						if (command != COMMAND_MAX) command++;
						if (command == COMMAND_MAX) command = COMMAND_ATTACK;
						break;
					}
					break;
				}
			}
			phase = PHASE_BATTLE;
			break;
		case PHASE_BATTLE:
			int CHALLENGE_TYPE = 0;
			int CHALLENGE_SUCCESSLATE = 0;
			int escapeNum = 0;
			system("cls");
			display_zako4();
			switch (command) {
			case COMMAND_ATTACK:
				if (player.hp > 0) playerattack_vszako4();
				if (zako4.hp > 0) zako4attack(EnemySpellFlag);
				break;
			case COMMAND_ESCAPE:
				printf("%sは　にげだした！\n", player.name);
				while (_kbhit() != 1) {
					randomNum = 10 + genrand_int32() % 90;
					printf("\r%d", randomNum);
				}
				getchar();
				escapeNum = randomNum;
				getchar();
				if (escapeNum < 34) {
					printf("しかし　まわりこまれた！\n");
					getchar();
					if (zako4.hp > 0) {
						zako4attack(EnemySpellFlag);
					}
					break;
				}
				else {
					printf("うまく　にげきれた！\n");
					getchar();
					player = {
						default.hp,
						default.maxHp,
						default.mp,
						default.maxMp,
						"えにくす",
						default.attack,
						default.defence,
						default.intelligence
					};
					return 0;
				}
			case COMMAND_CHALLENGE:
				system("cls");
				display_zako4();
				printf("%sは　ちょうはつした！\n", player.name);
				getchar();
				CHALLENGE_TYPE = genrand_int32() % 3 + 1;
				CHALLENGE_SUCCESSLATE = genrand_int32() % 100 + 1;
				if (CHALLENGE_TYPE == 1) {
					printf("　　%s:　俺が殺せると思っているのなら\n\t　　　 やってみるがいい…！\n", player.name);
					getchar();
					printf("%s:\tフン　くだらん挑発にのってやって…もうちょっとだけためしてやるか…\n", zako4.name);
					printf("\n%sは　てかげん　しはじめた！\n", zako4.name);
					zako4.attack -= zako4.attack / 5;
					turnCount = 1;
					getchar();
					zako4attack(EnemySpellFlag);
				}
				if (CHALLENGE_TYPE == 2) {
					printf("　　%s:　オレは戦うのが好きなんじゃねぇんだ…。\n　　　　　　 　勝つのが好きなんだよォォッ！！\n", player.name);
					getchar();
					printf("%s:\tよかろう…やってみろ……　このDIOに対してッ！\n", zako4.name);
					printf("\nおたがいの　こうげきが　とおりやすくなった！\n", zako4.name);
					player.attack += player.attack * 2 / 5;
					zako4.attack += zako4.attack / 5;
					turnCount = 1;
					getchar();
					zako4attack(EnemySpellFlag);
				}
				if (CHALLENGE_TYPE == 3) {
					printf("　　%s:　 言いたいことは…いくつか…あるんだよ…\n\t\tま…一言で言うなら\n\t\t本気にさせたな\n", player.name);
					getchar();
					printf("%s:\tマヌケが…知るがいい…『世界』の真の能力は…\n\t\tまさに！ 『世界を支配する』能力だということを！\n", zako4.name);
					printf("\nああ！　%sを　いきおいづかせてしまった！\n", zako4.name);
					getchar();
					turnCount = 0;
					zako4attack(EnemySpellFlag);
				}
				break;
			case COMMAND_DEFENCE:
				system("cls");
				display_zako4();
				printf("%sは　みをまもっている\n", player.name);
				getchar();
				zako4.attack /= 2;
				zako4attack(EnemySpellFlag);
				zako4.attack *= 2;
				break;
			default:
				printf("ERROR!\nみじっそうのコマンド\n");
				break;
			case COMMAND_SPELL:
				spell_vszako4();
				if (zako4.hp > 0 && Spell_dontUse == Disable) zako4attack(EnemySpellFlag);
				else if (Spell_dontUse == Enable) Spell_dontUse = Disable;
				break;
			case COMMAND_PARRY:
				system("cls");
				display_zako4();
				printf("%sは　パリィを　こころみた！\n", player.name);
				getchar();
				turnCount++;
				system("cls");
				display_zako4();
				printf("%sの　こうげき！\n", zako4.name);
				getchar();
				if (turnCount % 3 == 1) {
					printf("%s: 『世界』ッ！　時よ止まれ！\n", zako4.name);
					getchar();

					HANDLE TimeStop = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(
						TimeStop, // HANDLE hConsoleOutput
						BACKGROUND_INTENSITY);// WORD wAttributes
					TimeStopFlag = Enable;
					system("cls");
					display_zako4();
					printf("とまった　ときのなかで　うごけるのは　%sだけだ！\n", zako4.name);
					getchar();
					printf("パリィ　しっぱい！\n");
					int ATTACK_DAMAGE;
					if (zako4.hp < 18) {
						printf("%s:　ロードローラーだッ！\n", zako4.name);
						getchar();
						printf("%sは　%sを　ロードローラーで　つぶし　ラッシュをあびせた！\n", zako4.name, player.name);
						getchar();
						display_zako4();
						printf("%s:　無駄無駄無駄無駄無駄無駄無駄無駄無駄無駄無駄無駄ァーーーーーーッ\n", zako4.name);
						getchar();
						display_zako4();
						printf("%s:　そして　時は　動き出す…\n", zako4.name, player.name);
						getchar();
						ATTACK_DAMAGE = zako4.attack * 2 + (genrand_int32() % 10) + 1 - player.defence / 8;
						player.hp -= ATTACK_DAMAGE;
					}
					else {
						printf("%sは　%sに　こぶしで　ラッシュをあびせた！\n", zako4.name, player.name);
						getchar();
						display_zako4();
						printf("%s:そして　時は　動き出す…\n", zako4.name, player.name);
						getchar();
						ATTACK_DAMAGE = zako4.attack + (genrand_int32() % 10) + 1 - player.defence / 8;
						player.hp -= ATTACK_DAMAGE;
					}
					TimeStopFlag = Disable;
					printf("\x1b[49m");
					display_zako4();
					printf("%sに　%dポイントの\nダメージを　あたえた！\n", player.name, ATTACK_DAMAGE);
					getchar();
					if (player.hp <= 0) {
						display_zako4();
						printf("%sは　しんでしまった！\n", player.name);
						getchar();
						printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
						getchar();
						return 0;
					}
					break;
				}
				else {
					printf("\n%sのこぶしが\nうなりをあげて　せまってくる…", zako4.name);
					int randomNum = 0;
					while (_kbhit() != 1) {
						randomNum = 10 + genrand_int32() % 90;
						printf("\r%d", randomNum);
					}
					getchar();
					if (randomNum >= 50) {
						printf("\nパリィ　せいこう！\n");
						getchar();
						int ATTACK_DAMAGE;
						if (randomNum >= 95) {
							printf("SMAAAASH!!");
							getchar();
							ATTACK_DAMAGE = player.attack * 4 + (genrand_int32() % 3);
							zako4.hp -= ATTACK_DAMAGE;
						}
						else {
							ATTACK_DAMAGE = player.attack * 2 + (genrand_int32() % 3);
							zako4.hp -= ATTACK_DAMAGE;
						}
						display_zako4();
						printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako4.name, ATTACK_DAMAGE);
						getchar();
						if (zako4.hp <= 0) {
							system("cls");
							printf(" ┌――――┐\n");
							printf(" │%s│\n", player.name);
							printf(" ├――――┤\n");
							if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
							else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
							else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
							else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
							if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
							else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
							else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
							printf(" └――――┘\n");
							printf("\n\n\n\n");
							printf("%sを　たおした！\n", zako4.name);
							zako4WinFlag = Enable;
							getchar();
							return 0;
						}
					}
					else {
						printf("\nパリィ　しっぱい！\n");
						getchar();
						int ATTACK_DAMAGE = zako4.attack + (genrand_int32() % 3);
						player.hp -= ATTACK_DAMAGE;
						display_zako4();
						printf("%sは　%dポイントの\nダメージを　うけた！\n", player.name, ATTACK_DAMAGE);
						getchar();
						if (player.hp <= 0) {
							display_zako4();
							printf("%sは　しんでしまった！\n", player.name);
							getchar();
							printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
							getchar();
							return 0;
						}
					}
					break;
				}
			}
			phase = PHASE_COMMAND;
			break;
		}
	}
	player = {
		default.hp,
		default.maxHp,
		default.mp,
		default.maxMp,
		"えにくす",
		default.attack,
		default.defence,
		default.intelligence
	};

	cleared4 = {
		player.hp,
		player.maxHp,
		player.mp,
		player.maxMp,
		"えにくす",
		player.attack,
		player.defence,
		player.intelligence
	};
}

void display_zako5()
{
	system("cls");
	if (TimeStopFlag == Enable) {
		HANDLE TimeStop = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(
			TimeStop, // HANDLE hConsoleOutput
			BACKGROUND_INTENSITY);
		printf(" ┌――――┐\n");
		printf(" │%s│\n", player.name);
		printf(" ├――――┤\n");
		if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
		else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
		else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
		else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
		if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
		else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
		else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
		printf(" └――――┘\n");
	}
	else {
		if (player.hp <= 0) {
			HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(
				hConsoleOutput, // HANDLE hConsoleOutput
				FOREGROUND_RED | FOREGROUND_INTENSITY);// WORD wAttributes
			printf(" ┌――――┐\n");
			printf(" │%s│\n", player.name);
			printf(" ├――――┤\n");
			if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
			else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
			else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
			else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
			if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
			else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
			else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
			printf(" └――――┘\n");
		}
		else {
			HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(
				hConsoleOutput, // HANDLE hConsoleOutput
				FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);// WORD wAttributes
			printf(" ┌――――┐\n");
			printf(" │%s│\n", player.name);
			printf(" ├――――┤\n");
			if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
			else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
			else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
			else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
			if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
			else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
			else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
			printf(" └――――┘\n");
		}
		printf("\x1b[49m");
		HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(
			hConsoleOutput, // HANDLE hConsoleOutput
			FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}

	printf("\n");
	printf("	　　　　γ⌒ヾ､\n");
	printf("	　　＿_/⌒ヽヾ_ヾ_\n");
	printf("	　／::/:::: /:::::ヽ\n");
	printf("	／:::(::::_/::::::::\n");
	printf("	二7二7二7二7二7二7／\n");
	printf("	二7二7二7二7二7二(\n");
	printf("	/ﾞ<ﾆ＼/〃／二二>∥ヽ\n");
	printf("	レ|ﾍ_0レ' ﾍ＿0/ ∥::\n");
	printf("	`_|~ く~　 ~~~　/:::\n");
	printf("	∥ ､　-━　∥￣´::/\n");
	printf("	∥　＼ ~　 ∥＿＿_//\n");
	printf("	`￣￣ |━-´`￣￣|~\n");
	printf("	　　〔二二二二二二〕\n");
	printf("	　 ／)::::::::::／ﾞﾒ\n");
	printf("	／ ∠_／):::::／ﾞ／,\n");

	printf("\n\n\n %s\n\n HP \n", zako5.name);
	int hpdisp_blank = zako5.maxHp;
	hpdisp = zako5.hp;
	while (hpdisp_blank > 0) {
		printf("□");
		hpdisp_blank -= 8;
	}
	printf("\r");
	while (hpdisp > 0) {
		printf("■");
		hpdisp -= 8;
	}
	printf("\n\n");
}

void playerattack_vszako5()
{
	system("cls");
	display_zako5();
	printf("%sの　こうげき！\n", player.name);
	while (_kbhit() != 1) {
		randomNum = 10 + genrand_int32() % 90;
		printf("\r%d", randomNum);
	}
	getchar();
	int attackNum = randomNum;
	getchar();
	int ATTACK_CRITICAL = attackNum;
	int ATTACK_RANDOM = attackNum / 10;
	if (ATTACK_RANDOM >= 0 && ATTACK_RANDOM < 4) ATTACK_RANDOM = 1;
	else if (ATTACK_RANDOM >= 4 && ATTACK_RANDOM < 7) ATTACK_RANDOM = 2;
	else if (ATTACK_RANDOM >= 7 && ATTACK_RANDOM < 10) ATTACK_RANDOM = 3;
	int ATTACK_DAMAGE = player.attack / 2 + ATTACK_RANDOM + 13 - zako5.defence / 4;
	if (ATTACK_DAMAGE <= 0) ATTACK_DAMAGE = 1;
	if (ATTACK_CRITICAL >= 95) {
		ATTACK_DAMAGE = player.attack * 2 + 13 + (genrand_int32() % 3);
		printf("SMAAAASH!!");
		getchar();
	}
	zako5.hp -= ATTACK_DAMAGE;
	display_zako5();
	printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako5.name, ATTACK_DAMAGE);
	getchar();
	if (zako5.hp <= 0) {
		system("cls");
		printf(" ┌――――┐\n");
		printf(" │%s│\n", player.name);
		printf(" ├――――┤\n");
		if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
		else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
		else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
		else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
		if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
		else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
		else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
		printf(" └――――┘\n");
		printf("\n\n\n\n");
		printf("%sを　たおした！\n", zako5.name);
		ClearFlag = Enable;
		getchar();
		return;
	}
}

int zako5attack(int EnemySpellFlag)
{
	int ATTACK_PATTERN = genrand_int32() % 99 + 1;
	int ATTACK_DAMAGE;
	system("cls");
	display_zako5();
	if (zako5.hp < 20) {
		printf("%sの　すてみのこうげき！\n", zako5.name);
		getchar();
		printf("%sは　ギガブレイクをはなった！\n", zako5.name);
		getchar();
		if (genrand_int32() % 16 == 0) {
			printf("\n%sは　こうげきを　かわした！　%sはダメージを　あたえられない！", player.name, zako5.name);
			getchar();
			return 0;
		}
		ATTACK_DAMAGE = zako5.attack * 3 + genrand_int32() % 10 - player.defence;
		player.hp -= ATTACK_DAMAGE;
		display_zako5();
		printf("%sに　%dポイントの\nダメージを　あたえた！\n", player.name, ATTACK_DAMAGE);
		getchar();
		if (player.hp <= 0) {
			display_zako5();
			printf("%sは　しんでしまった！\n", player.name);
			getchar();
			printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
			getchar();
		}
		return 0;
	}
	else if (zako5.hp < 150 && genrand_int32() % 100 < 10) {
		printf("%sは　ベホイミを　となえた！\n", zako5.name);
		getchar();
		int ENEMY_RECOVER = 80 + genrand_int32() % 10;
		zako5.hp += ENEMY_RECOVER;
		display_zako5();
		printf("%sは　%dポイント　かいふくした！\n", zako5.name, ENEMY_RECOVER);
		getchar();
		return 0;
	}
	else {
		printf("%sの　こうげき！\n", zako5.name);
		getchar();
		if (ATTACK_PATTERN < 34) {
			printf("%sは　ギガデインをとなえた！\n", zako5.name);
			getchar();
			int SPELL_DAMAGE;
			SPELL_DAMAGE = zako5.intelligence * 3 + genrand_int32() % 10 - player.intelligence;
			if (SPELL_DAMAGE <= 0) SPELL_DAMAGE = 1;
			player.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako5();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", player.name, SPELL_DAMAGE);
			getchar();
			if (player.hp <= 0) {
				display_zako5();
				printf("%sは　しんでしまった！\n", player.name);
				getchar();
				printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
				getchar();
			}
			return 0;
		}
		else if (ATTACK_PATTERN < 45) {
			printf("%sは　まじんぎりをはなった！\n", zako5.name);
			getchar();
			if (genrand_int32() % 8 > 2) {
				system("cls");
				display_zako5();
				printf("ミス！　%sに　ダメージを　あたえられない！\n", player.name);
				getchar();
				return 0;
			}
			else {
				if (genrand_int32() % 16 == 0) {
					printf("\n%sは　こうげきを　かわした！　%sはダメージを　あたえられない！", player.name, zako5.name);
					getchar();
					return 0;
				}
				int SPELL_DAMAGE;
				SPELL_DAMAGE = 5 + zako5.attack * 2 + genrand_int32() % 10;
				player.hp -= SPELL_DAMAGE;
				system("cls");
				display_zako5();
				printf("%sに　%dポイントの\nダメージを　あたえた！\n", player.name, SPELL_DAMAGE);
				getchar();
				if (player.hp <= 0) {
					display_zako5();
					printf("%sは　しんでしまった！\n", player.name);
					getchar();
					printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
					getchar();
				}
				return 0;
			}
		}
		else {
			ATTACK_DAMAGE = zako5.attack / 2 + (genrand_int32() % 3) + 1 - player.defence / 4;
			int ATTACK_CRITICAL = genrand_int32() % 100 + 1;
			if (ATTACK_DAMAGE <= 0) ATTACK_DAMAGE = 1;
			if (ATTACK_CRITICAL >= 98) {
				ATTACK_DAMAGE = zako5.attack + (genrand_int32() % 3) + 1;
				printf("SMAAAASH!!");
				getchar();
			}
			player.hp -= ATTACK_DAMAGE;
			display_zako5();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", player.name, ATTACK_DAMAGE);
			getchar();
			if (player.hp <= 0) {
				display_zako5();
				printf("%sは　しんでしまった！\n", player.name);
				getchar();
				printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
				getchar();
				return 0;
			}
			else {
				return 0;
			}
		}
	}
}

void spell_vszako5()
{
	int EnterFlagS = Disable;
	system("cls");
	display_zako5();
	enum {
		SPELL_ATTACK,
		SPELL_ATTACK2,
		SPELL_HYPERATTACK,
		SPELL_HEAL,
		SPELL_BUFF,
		SPELL_SLASH,
		SPELL_BREATHE,
		SPELL_DONT_USE,
		SPELL_MAX			//じゅもんの数
	};
	char spellNames[][16] = {
		"メラゾーマ",
		"マヒャド",
		"メドローア",
		"ベホイミ",
		"スカラ",
		"ギガスラッシュ",
		"こごえるふぶき",
		"もどる"
	};
	int commandS = SPELL_ATTACK;
	while (EnterFlagS == Disable) {
		system("cls");
		display_zako5();
		printf("じゅもん\n");
		for (int i = 0; i < SPELL_MAX; i++) {
			if (i == commandS) {
				printf("＞%s\n", spellNames[i]);
			}
			else {
				printf("　%s\n", spellNames[i]);
			}
		}
		switch (commandS) {
		case SPELL_ATTACK:
			printf("\nしょうひMP:10\nきょだいな　ひのたまを　ぶつける");
			break;
		case SPELL_ATTACK2:
			printf("\nしょうひMP:12\nこおりの　あらしによって　てきを　いてつかせる");
			break;
		case SPELL_HEAL:
			printf("\nしょうひMP:8\nじぶんの　HPを　おおきくかいふくする");
			break;
		case SPELL_BUFF:
			printf("\nしょうひMP:3\nじぶんの　ぼうぎょりょくを　じょうしょうさせる");
			break;
		case SPELL_SLASH:
			printf("\nしょうひMP:20\nすべてをこえる　きゅうきょくの　ひっさつけん");
			break;
		case SPELL_BREATHE:
			printf("\nしょうひMP:8\nきゅうきょく　とうけつ　おうぎ");
			break;
		case SPELL_HYPERATTACK:
			printf("\nしょうひMP:50\nほのおと　こおりの　ちからをスパークさせ\nふれたものを　しょうめつさせる　ひかりのやをうちだす");
			break;
		case SPELL_DONT_USE:
			printf("\nじゅもんをつかうのをやめる");
			break;
		}
		switch (_getch()) {
		case 0x0d:
			EnterFlagS = Enable;
			break;
		case 0xe0:
			switch (_getch()) {
			case 0x48:
				if (commandS != SPELL_ATTACK) commandS--;
				else if (commandS == SPELL_ATTACK) commandS = SPELL_MAX - 1;
				break;
			case 0x50:
				if (commandS != SPELL_MAX) commandS++;
				if (commandS == SPELL_MAX) commandS = SPELL_ATTACK;
				break;
			}
			break;
		}
	}
	switch (commandS) {
	case SPELL_ATTACK:
		system("cls");
		display_zako5();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[0]);
		getchar();
		if (player.mp < 10) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 10;
			int SPELL_DAMAGE;
			if (player.intelligence < 18) {
				SPELL_DAMAGE = player.intelligence * 3 + genrand_int32() % 6 - zako5.intelligence;
			}
			else
			{
				SPELL_DAMAGE = player.intelligence * 3 + genrand_int32() % (player.intelligence / 3) - zako5.intelligence;
			}
			if (SPELL_DAMAGE <= 0) SPELL_DAMAGE = 1;
			zako5.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako5();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako5.name, SPELL_DAMAGE);
			getchar();
			if (zako5.hp <= 0) {
				system("cls");
				printf(" ┌――――┐\n");
				printf(" │%s│\n", player.name);
				printf(" ├――――┤\n");
				if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
				else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
				else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
				else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
				if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
				else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
				else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
				printf(" └――――┘\n");
				printf("\n\n\n\n");
				printf("%sを　たおした！\n", zako5.name);
				getchar();
				ClearFlag = Enable;
				return;
			}
		}
		break;
	case SPELL_ATTACK2:
		system("cls");
		display_zako5();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[1]);
		getchar();
		if (player.mp < 12) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 12;
			int SPELL_DAMAGE;
			SPELL_DAMAGE = 10 + player.intelligence * 2 + genrand_int32() % 10 - zako5.intelligence;
			if (SPELL_DAMAGE <= 0) SPELL_DAMAGE = 1;
			zako5.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako5();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako5.name, SPELL_DAMAGE);
			getchar();
			if (zako5.hp > 0 && (genrand_int32() % 2) == 0) {
				printf("%sの　からだのいちぶを　こおらせた！\n", zako5.name);
				zako5.attack -= zako5.attack / 5;
				getchar();
			}
			if (zako5.hp <= 0) {
				system("cls");
				printf(" ┌――――┐\n");
				printf(" │%s│\n", player.name);
				printf(" ├――――┤\n");
				if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
				else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
				else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
				else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
				if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
				else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
				else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
				printf(" └――――┘\n");
				printf("\n\n\n\n");
				printf("%sを　たおした！\n", zako5.name);
				ClearFlag = Enable;
				getchar();
				return;
			}
		}
		break;
	case SPELL_HEAL:
		system("cls");
		display_zako5();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[3]);
		getchar();
		if (player.mp < 8) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 8;
			int SPELL_RECOVER = 10 + player.maxHp / 3 + player.intelligence + genrand_int32() % 10;
			if (SPELL_RECOVER + player.hp > player.maxHp) SPELL_RECOVER = player.maxHp - player.hp;
			player.hp += SPELL_RECOVER;
			system("cls");
			display_zako5();
			printf("%sは　%dポイント　かいふくした！\n", player.name, SPELL_RECOVER);
			getchar();
		}
		break;
	case SPELL_BUFF:
		system("cls");
		display_zako5();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[4]);
		getchar();
		if (player.mp < 3) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 3;
			player.defence += (player.defence * 2) / 5;
			system("cls");
			display_zako5();
			printf("%sの　ぼうぎょりょくが　あがった！\n", player.name);
			Spell_buffFlag = Enable;
			getchar();
		}
		break;
	case SPELL_SLASH:
		system("cls");
		display_zako5();
		printf("%sは　%sをはなった！\n", player.name, spellNames[5]);
		getchar();
		if (player.mp < 20) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 20;
			int SPELL_DAMAGE;
			SPELL_DAMAGE = player.attack * 2 + player.intelligence + genrand_int32() % 5 - zako5.defence / 8 - zako5.intelligence / 8;
			if (SPELL_DAMAGE <= 0) SPELL_DAMAGE = 1;
			zako5.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako5();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako5.name, SPELL_DAMAGE);
			getchar();
			if (zako5.hp <= 0) {
				system("cls");
				printf(" ┌――――┐\n");
				printf(" │%s│\n", player.name);
				printf(" ├――――┤\n");
				if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
				else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
				else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
				else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
				if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
				else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
				else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
				printf(" └――――┘\n");
				printf("\n\n\n\n");
				printf("%sを　たおした！\n", zako5.name);
				getchar();
				ClearFlag = Enable;
				return;
			}
		}
		break;
	case SPELL_BREATHE:
		system("cls");
		display_zako5();
		printf("%sは　こごえる　ふぶきを　はいた！\n", player.name, spellNames[1]);
		getchar();
		if (player.mp < 8) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			player.mp -= 8;
			int SPELL_DAMAGE;
			SPELL_DAMAGE = player.intelligence * 2 + genrand_int32() % 10 - zako5.intelligence;
			if (SPELL_DAMAGE <= 0) SPELL_DAMAGE = 1;
			zako5.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako5();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako5.name, SPELL_DAMAGE);
			getchar();
			if (zako5.hp > 0 && (genrand_int32() % 2) == 0) {
				printf("%sの　からだのいちぶを　こおらせた！\n", zako5.name);
				zako5.attack -= zako5.attack / 5;
				getchar();
			}
			if (zako5.hp <= 0) {
				system("cls");
				printf(" ┌――――┐\n");
				printf(" │%s│\n", player.name);
				printf(" ├――――┤\n");
				if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
				else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
				else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
				else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
				if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
				else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
				else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
				printf(" └――――┘\n");
				printf("\n\n\n\n");
				printf("%sを　たおした！\n", zako5.name);
				getchar();
				ClearFlag = Enable;
				return;
			}
		}
		break;
	case SPELL_HYPERATTACK:
		system("cls");
		display_zako5();
		printf("%sは　%sをとなえた！\n", player.name, spellNames[2]);
		getchar();
		if (player.mp < 50) {
			printf("しかし　MPがたりない！\n");
			getchar();
		}
		else {
			printf("\nメラゾーマと　マヒャドがまじりあい\n%sとなる！\n", spellNames[2]);
			getchar();
			player.mp -= 50;
			int SPELL_DAMAGE;
			SPELL_DAMAGE = zako5.hp / 2 + genrand_int32() % 5;
			if (SPELL_DAMAGE <= 0) SPELL_DAMAGE = 1;
			zako5.hp -= SPELL_DAMAGE;
			system("cls");
			display_zako5();
			printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako5.name, SPELL_DAMAGE);
			getchar();
			if (zako5.hp <= 0) {
				system("cls");
				printf(" ┌――――┐\n");
				printf(" │%s│\n", player.name);
				printf(" ├――――┤\n");
				if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
				else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
				else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
				else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
				if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
				else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
				else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
				printf(" └――――┘\n");
				printf("\n\n\n\n");
				printf("%sを　たおした！\n", zako5.name);
				getchar();
				ClearFlag = Enable;
				return;
			}
		}
		break;
	case SPELL_DONT_USE:
		Spell_dontUse = Enable;
		return;
	}
	return;
}

int vszako5() {
	default = {
		player.hp,
		player.maxHp,
		player.mp,
		player.maxMp,
		"えにくす",
		player.attack,
		player.defence,
		player.intelligence
	};
	init_genrand((unsigned)time(NULL));
	zako5 = {
		450,
		450,
		50,
		50,
		"ゆうしゃ",
		70,
		30,
		30
	};
	display_zako5();
	command = COMMAND_ATTACK;
	phase = PHASE_COMMAND;
	Spell_buffFlag = Disable;
	EnemySpellFlag = Enable;
	enum {
		SPELL_ATTACK,
		SPELL_HEAL,
		SPELL_BUFF,
		SPELL_SLASH,
		SPELL_DONT_USE,
		SPELL_MAX			//じゅもんの数
	};
	int commandS = SPELL_ATTACK;
	turnCount5 = 0;
	printf("%sが　あらわれた！\n", zako5.name);
	getchar();
	printf("\n%s: %sよ！　なにゆえ もがき いきるのか？\n", player.name, zako5.name);
	getchar();
	printf("　　　　  ほろびこそ わが よろこび。しにゆくものこそ うつくしい。\n");
	getchar();
	printf("　　　　  さあ わが うでのなかで　いきたえるがよい！\n");
	command = COMMAND_ATTACK;
	commandS = SPELL_ATTACK;
	phase = PHASE_COMMAND;
	Spell_buffFlag = Disable;
	EnemySpellFlag = Disable;
	getchar();
	while ((player.hp > 0) && (zako5.hp > 0)) {
		int EnterFlag = Disable;
		switch (phase) {
		case PHASE_COMMAND:
			while (EnterFlag == Disable) {
				system("cls");
				display_zako5();
				printf("コマンド？\n");
				for (int i = 0; i < COMMAND_MAX; i++) {
					if (i == command) {
						printf("＞%s\n", commandNames[i]);
					}
					else {
						printf("　%s\n", commandNames[i]);
					}
				}
				//コマンド説明
				switch (command) {
				case COMMAND_ATTACK:
					printf("\nこうげきをする");
					break;
				case COMMAND_SPELL:
					printf("\nMPをしょうひして\nじゅもんをつかう");
					break;
				case COMMAND_CHALLENGE:
					printf("\nあいてを　いあつして\nあいてのじゅもんや　こうげきを　ぼうがいする");
					break;
				case COMMAND_PARRY:
					printf("\nあいてのこうげきを　はじいて\nだいダメージを　ねらう");
					break;
				case COMMAND_ESCAPE:
					printf("\nとうぼうをこころみる");
					break;
				case COMMAND_DEFENCE:
					printf("\nぼうぎょをする");
					break;
				}
				switch (_getch()) {
				case 0x0d:
					EnterFlag = Enable;
					break;
				case 0xe0:
					switch (_getch()) {
					case 0x48:
						if (command != COMMAND_ATTACK) command--;
						else if (command == COMMAND_ATTACK) command = COMMAND_MAX - 1;
						break;
					case 0x50:
						if (command != COMMAND_MAX) command++;
						if (command == COMMAND_MAX) command = COMMAND_ATTACK;
						break;
					}
					break;
				}
			}
			phase = PHASE_BATTLE;
			break;
		case PHASE_BATTLE:
			int CHALLENGE_TYPE = 0;
			int CHALLENGE_SUCCESSLATE = 0;
			int escapeNum = 0;
			system("cls");
			display_zako5();
			switch (command) {
			case COMMAND_ATTACK:
				if (player.hp > 0) playerattack_vszako5();
				if (zako5.hp > 0) zako5attack(EnemySpellFlag);
				break;
			case COMMAND_ESCAPE:
				printf("%sは　にげだした！\n", player.name);
				while (_kbhit() != 1) {
					randomNum = 10 + genrand_int32() % 90;
					printf("\r%d", randomNum);
				}
				getchar();
				escapeNum = randomNum;
				getchar();
				if (escapeNum < 34) {
					printf("しかし　まわりこまれた！\n");
					getchar();
					if (zako5.hp > 0) {
						zako5attack(EnemySpellFlag);
					}
					break;
				}
				else {
					printf("うまく　にげきれた！\n");
					getchar();
					player = {
						default.hp,
						default.maxHp,
						default.mp,
						default.maxMp,
						"えにくす",
						default.attack,
						default.defence,
						default.intelligence
					};
					return 0;
				}
			case COMMAND_CHALLENGE:
				system("cls");
				display_zako5();
				printf("%sは　ちょうはつした！\n", player.name);
				getchar();
				CHALLENGE_TYPE = genrand_int32() % 3 + 1;
				CHALLENGE_SUCCESSLATE = genrand_int32() % 100 + 1;
				if (CHALLENGE_TYPE == 1) {
					printf("%s:知らなかったのか…？　大魔王からは逃げられない…！！！\n", player.name);
					getchar();
					printf("\n%sは　おそれ　おののいた！\n", zako5.name);
					zako5.attack -= zako5.attack / 10;
					player.attack += player.attack / 5;
					getchar();
					zako5attack(EnemySpellFlag);
				}
				if (CHALLENGE_TYPE == 2) {
					printf("%s:天よ叫べ！　地よ唸れ！\n", player.name);
					getchar();
					printf("　　　　 いまここに……魔の時代来たり！\n");
					getchar();
					printf("\n%sは　おそれ　おののいた！\n", zako5.name);
					zako5.attack -= zako5.attack / 10;
					player.intelligence += player.intelligence / 5;
					getchar();
					zako5attack(EnemySpellFlag);
				}
				if (CHALLENGE_TYPE == 3) {
					printf("%s:己の強さに酔う…！　どんな美酒を飲んでも味わえない極上の気分だぞ………\n", player.name);
					getchar();
					printf("\n%sは　おそれ　おののいた！\n", zako5.name);
					zako5.attack -= zako5.attack / 10;
					player.defence += player.defence / 5;
					getchar();
					zako5attack(EnemySpellFlag);
				}
				break;
			case COMMAND_DEFENCE:
				system("cls");
				display_zako5();
				printf("%sは　みをまもっている\n", player.name);
				getchar();
				zako5.attack /= 2;
				zako5attack(EnemySpellFlag);
				zako5.attack *= 2;
				break;
			default:
				printf("ERROR!\nみじっそうのコマンド\n");
				break;
			case COMMAND_SPELL:
				spell_vszako5();
				if (zako5.hp > 0 && Spell_dontUse == Disable) zako5attack(EnemySpellFlag);
				else if (Spell_dontUse == Enable) Spell_dontUse = Disable;
				break;
			case COMMAND_PARRY:
				system("cls");
				display_zako5();
				printf("%sは　パリィを　こころみた！\n", player.name);
				getchar();
				system("cls");
				display_zako5();
				printf("%sの　こうげき！\n", zako5.name);
				printf("\n%sの　けんさきが　せまってくる…", zako5.name);
				getchar();
				int randomNum = 0;
				while (_kbhit() != 1) {
					randomNum = 10 + genrand_int32() % 90;
					printf("\r%d", randomNum);
				}
				getchar();
				if (randomNum > 50) {
					printf("\nパリィ　せいこう！\n");
					getchar();
					int ATTACK_DAMAGE;
					if (randomNum >= 95) {
						printf("SMAAAASH!!");
						getchar();
						ATTACK_DAMAGE = player.attack * 4 + (genrand_int32() % 3);
						zako5.hp -= ATTACK_DAMAGE;
					}
					else {
						ATTACK_DAMAGE = player.attack * 2 + (genrand_int32() % 3);
						zako5.hp -= ATTACK_DAMAGE;
					}
					display_zako5();
					printf("%sに　%dポイントの\nダメージを　あたえた！\n", zako5.name, ATTACK_DAMAGE);
					getchar();
					if (zako5.hp <= 0) {
						system("cls");
						printf(" ┌――――┐\n");
						printf(" │%s│\n", player.name);
						printf(" ├――――┤\n");
						if (player.hp <= 0) printf(" │HP    0 │\n", player.hp);
						else if (player.hp < 10) printf(" │HP    %d │\n", player.hp);
						else if (player.hp < 100) printf(" │HP   %d │\n", player.hp);
						else if (player.hp < 1000) printf(" │HP  %d │\n", player.hp);
						if (player.mp < 10) printf(" │MP    %d │\n", player.mp);
						else if (player.mp < 100) printf(" │MP   %d │\n", player.mp);
						else if (player.mp < 1000) printf(" │MP  %d │\n", player.mp);
						printf(" └――――┘\n");
						printf("\n\n\n\n");
						printf("%sを　たおした！\n", zako5.name);
						ClearFlag = Enable;
						getchar();
						return 0;
					}
				}
				else {
					printf("\nパリィ　しっぱい！\n");
					getchar();
					int ATTACK_DAMAGE = zako5.attack + (genrand_int32() % 3);
					player.hp -= ATTACK_DAMAGE;
					display_zako5();
					printf("%sは　%dポイントの\nダメージを　うけた！\n", player.name, ATTACK_DAMAGE);
					getchar();
					if (player.hp <= 0) {
						display_zako5();
						printf("%sは　しんでしまった！\n", player.name);
						getchar();
						printf("おお　%s！しんでしまうとは　なにごとだ！\n", player.name);
						getchar();
					}
				}
				break;
			}
			phase = PHASE_COMMAND;
			break;
		}
	}
	player = {
		default.hp,
		default.maxHp,
		default.mp,
		default.maxMp,
		"えにくす",
		default.attack,
		default.defence,
		default.intelligence
	};

	cleared5 = {
		player.hp,
		player.maxHp,
		player.mp,
		player.maxMp,
		"えにくす",
		player.attack,
		player.defence,
		player.intelligence
	};
}



void PlayerUpgrowth()
{
	int defaultStatus[5] = {
		(player.maxHp / 5),
		(player.maxMp / 4),
		player.attack,
		player.defence,
		player.intelligence
	};
	int newStatus[5] = {
		(player.maxHp / 5),
		(player.maxMp / 4),
		player.attack,
		player.defence,
		player.intelligence
	};
	int EnterFlag = Disable;
	int YesNoCursor = 0;
	int bonusDefault = bonus;
	while (EnterFlag == Disable) {
	START:
		system("cls");
		printf("\n *―――――――――――――――――――――――*\n");
		printf("\n　 たたかいを　へて　せいちょうしました");
		printf("\n　 ボーナスポイントを　わりふってください\n\n");
		printf(" *―――――――――――――――――――――――*");
		printf("\n\n　%s\n", player.name);
		printf("　のこりポイント　%d　　　\tげんざいの　ステータス\n\n\n", bonus);
		for (int i = 0; i < STATUS_MAX; i++) {
			if (i == cursor) {
				printf("　　%s\t< %d >\t\t%d (%+d)\n\n", statusNames[i], newStatus[i], defaultStatus[i], newStatus[i] - defaultStatus[i]);
			}
			else {
				printf("　　%s\t  %d\t\t%d (%+d)\n\n", statusNames[i], newStatus[i], defaultStatus[i], newStatus[i] - defaultStatus[i]);
			}
		}
		printf(" zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\n\n\n");
		switch (cursor) {
		case STATUS_HP:
			printf("\tたいりょく\t:\tHPにえいきょうします　　1ポイントにつき　HP 5 じょうしょう\n\t\t\t\tたとえば %d なら さいだいHPは %d", newStatus[0], newStatus[0] * 5);
			break;
		case STATUS_MP:
			printf("\tまりょく\t:\tMPにえいきょうします　　1ポイントにつき　MP 4 じょうしょう\n\t\t\t\tたとえば %d なら さいだいMPは %d", newStatus[1], newStatus[1] * 4);
			break;
		case STATUS_ATTACK:
			printf("\tちから　\t:\tこうげきりょくにえいきょうします\n\t\t\t　　　　ちからこそ　パワー");
			break;
		case STATUS_DEFENCE:
			printf("\tみのまもり\t:\tぼうぎょりょくにえいきょうします\n\t\t\t　　　　こころの　ぼうぎょりょくは　あがりません");
			break;
		case STATUS_INTELLIGENCE:
			printf("\tかしこさ\t:\tまほうのいりょくにえいきょうします\n\t\t\t　　　　かいふくりょうや　まほうたいせいも　じょうしょうします");
			break;
		}
		printf("\n\n\n");
		printf("\t十字キー上下で　選択　　　十字キー左右で　増減\n");
		printf("\tわりふりおわったら　エンターで　けってい\n\n");
		switch (_getch()) {
		case 0x0d:
			EnterFlag = Enable;
			break;
		case 0xe0:
			switch (_getch()) {
			case 0x48:
				if (cursor != STATUS_HP) cursor--;
				else if (cursor == STATUS_HP) cursor = STATUS_MAX - 1;
				break;
			case 0x50:
				if (cursor != STATUS_MAX) cursor++;
				if (cursor == STATUS_MAX) cursor = STATUS_HP;
				break;
			case 0x4d:
				if (bonus > 0) {
					bonus--;
					newStatus[cursor]++;
				}
				break;
			case 0x4b:
				if (bonus < bonusDefault && (newStatus[cursor] > 1) && (defaultStatus[cursor] < newStatus[cursor])) {
					bonus++;
					newStatus[cursor]--;
				}
				break;
			}
			break;
		}
	}
	EnterFlag = Disable;
	while (EnterFlag == Disable) {
		system("cls");
		printf("\n *―――――――――――――――――――――――*\n");
		printf("\n　 たたかいを　へて　せいちょうしました");
		printf("\n　 ボーナスポイントを　わりふってください\n\n");
		printf(" *―――――――――――――――――――――――*");
		printf("\n\n　%s\n", player.name);
		printf("　のこりポイント　%d\n\n\n", bonus);
		for (int i = 0; i < STATUS_MAX; i++) {
			printf("　　%s\t  %d\n\n", statusNames[i], newStatus[i]);
		}
		printf("\n\nこれで　よろしいですか？\n");
		for (int i = 0; i < YesNomax; i++) {
			if (i == YesNoCursor) {
				printf("　＞　%s", HS[i]);
			}
			else {
				printf("　　　%s", HS[i]);
			}
		}
		switch (_getch()) {
		case 0x0d:
			if (YesNoCursor == Yes) EnterFlag = Enable;
			if (YesNoCursor == No) goto START;
			break;
		case 0xe0:
			switch (_getch()) {
			case 0x4b:
				if (YesNoCursor != Yes) YesNoCursor--;
				else YesNoCursor++;
				break;
			case 0x4d:
				if (YesNoCursor == Yes) YesNoCursor++;
				else YesNoCursor--;
				break;
			}
			break;
		}
	}

	player = {
		newStatus[0] * 5,
		newStatus[0] * 5,
		newStatus[1] * 4,
		newStatus[1] * 4,
		"えにくす",
		newStatus[2],
		newStatus[3],
		newStatus[4]
	};

}


int Continue() {
	int EnterFlag = Disable;
	int YesNoCursor = Yes;
	while (1) {
		system("cls");
		printf("\n\n\n\n\t  .,-:::::/   :::.     .        :  .,::::::     ...    :::      .::..,:::::: :::::::..   \n");
		printf("\t,;;-'````'    ;;`;;    ;;,.    ;;; ;;;;''''  .;;;;;;;. ';;,   ,;;;' ;;;;'''' ;;;;``;;;;  \n");
		printf("\t[[[   [[[[[[/,[[ '[[,  [[[[, ,[[[[, [[cccc  ,[[     \\[[,\\[[  .[[/    [[cccc   [[[,/[[['  \n");
		printf("\t\"$$c.    \"$$c$$$cc$$$c $$$$$$$$\"$$$ $$\"\"\"\"  $$$,     $$$ Y$c.$$\"     $$\"\"\"\"   $$$$$$c    \n");
		printf("\t `Y8bo,,,o88o888   888,888 Y88\" 888o888oo,__\"888,_ _,88P  Y88P       888oo,__ 888b \"88bo, \n");
		printf("\t   `'YMUP\"YMMYMM   \"\"` MMM  M'  \"MMM\"\"\"\"YUMMM \"YMMMMMP\"    MP        \"\"\"\"YUMMMMMMM   \"W\" \n");
		printf("\n\n\n\n\tコンティニューしますか？\n");
		printf("\tカーソルを　あわせて　エンターを　おしてください\n\n");
		for (int i = 0; i < YesNomax; i++) {
			if (i == YesNoCursor) {
				printf("　＞　%s", HS[i]);
			}
			else {
				printf("　　　%s", HS[i]);
			}
		}
		if (zako1WinFlag == Disable) printf("\n\n\n\n # TIPS #\n\n\tのこりHPが　すくなくなると　てきは　すてみでこうげきしてくるぞ\n\tじゅもんで　やきつくせ！");
		else if (zako2WinFlag == Disable) printf("\n\n\n\n # TIPS #\n\n\tまほうつかいは　ちょうはつされると　ペースがみだされる\n\tちょうはつで　おそれ　おののかせろ！");
		else if (zako3WinFlag == Disable) printf("\n\n\n\n # TIPS #\n\n\t『しんくうぎり』は　まほうたいせいの　たかいてきにも　ゆうこうだ\n\tこころにきずをおいすぎると　じゅもんが　じゃくたいかしてしまう\n\tたんきけっせんを　こころがけろ！");
		else if (zako4WinFlag == Disable) printf("\n\n\n\n # TIPS #\n\n\tときをとめる　タイミングをはかって　てきかくに『ぼうぎょ』しろ！\n\tやりすごしたら　『じゅもん』だ！");
		else if (ClearFlag == Disable) printf("\n\n\n\n # TIPS #\n\n\tさいごの　たたかいだ！\n\tきようびんぼうな　ステータスでは　かてないぞ！");
		switch (_getch()) {
		case 0x0d:
			if (YesNoCursor == Yes) {
				printf("\n\nステータス振り分け画面まで戻ります…\n");
				getchar();
				return Yes;
			}
			if (YesNoCursor == No) return No;
			break;
		case 0xe0:
			switch (_getch()) {
			case 0x4b:
				if (YesNoCursor != Yes) YesNoCursor--;
				else YesNoCursor++;
				system("cls");
				break;
			case 0x4d:
				if (YesNoCursor == Yes) YesNoCursor++;
				else YesNoCursor--;
				system("cls");
				break;
			}
			break;
		}
	}
}

int Gameover() {
	system("cls");
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(
		hConsoleOutput, // HANDLE hConsoleOutput
		FOREGROUND_RED | FOREGROUND_INTENSITY);// WORD wAttributes
	printf("\n\n\n\n\t  .,-:::::/   :::.     .        :  .,::::::     ...    :::      .::..,:::::: :::::::..   \n");
	printf("\t,;;-'````'    ;;`;;    ;;,.    ;;; ;;;;''''  .;;;;;;;. ';;,   ,;;;' ;;;;'''' ;;;;``;;;;  \n");
	printf("\t[[[   [[[[[[/,[[ '[[,  [[[[, ,[[[[, [[cccc  ,[[     \\[[,\\[[  .[[/    [[cccc   [[[,/[[['  \n");
	printf("\t\"$$c.    \"$$c$$$cc$$$c $$$$$$$$\"$$$ $$\"\"\"\"  $$$,     $$$ Y$c.$$\"     $$\"\"\"\"   $$$$$$c    \n");
	printf("\t `Y8bo,,,o88o888   888,888 Y88\" 888o888oo,__\"888,_ _,88P  Y88P       888oo,__ 888b \"88bo, \n");
	printf("\t   `'YMUP\"YMMYMM   \"\"` MMM  M'  \"MMM\"\"\"\"YUMMM \"YMMMMMP\"    MP        \"\"\"\"YUMMMMMMM   \"W\" \n");

	HANDLE hConsoleOutputW = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(
		hConsoleOutputW, // HANDLE hConsoleOutput
		FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// WORD wAttributes
	printf("\n\n\n\t\t　そのご　%sの　すがたを　みたものは　だれも　いない…\n", player.name);
	printf("\n\n\n\t\t\tエンターキーを　おすと　タイトルに　もどります");
	getchar();
	zako1WinFlag = Disable;
	zako2WinFlag = Disable;
	zako3WinFlag = Disable;
	zako4WinFlag = Disable;
	ClearFlag = Disable;
	return 0;
}

int main() {
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(
		hConsoleOutput, // HANDLE hConsoleOutput
		FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);// WORD wAttributes
	HANDLE Windowsize = GetStdHandle(STD_OUTPUT_HANDLE);	// DWORD nStdHandle
	COORD dwSize = { 180, 60 };
	SetConsoleScreenBufferSize(
		Windowsize, // HANDLE hConsoleOutput
		dwSize);        // COORD dwSize
	SMALL_RECT consoleWindow = { 0, 0, 160, 40 };
	SetConsoleWindowInfo(
		Windowsize, // HANDLE hConsoleOutput
		TRUE,           // BOOL bAbsolute
		&consoleWindow);// CONST SMALL_RECT *lpConsoleWindow
CLEARED:
	GameTitle();
ZAKO1:
	PlayerCreate();
	vszako1();
	if (zako1WinFlag == Enable) {
		player = {
			default.hp,
			default.maxHp,
			default.mp,
			default.maxMp,
			"えにくす",
			default.attack,
			default.defence,
			default.intelligence
		};
	ZAKO2:
		bonus = 10;
		PlayerUpgrowth();
		printf("\n\n\n%sは　%sとのたたかいの　けいけんから\n『しんくうぎり』をあみだした！\n", player.name, zako1.name);
		getchar();
		printf("%sの『メラ』は　『メラゾーマ』にしんかした！", player.name);
		getchar();
		vszako2();
	}
	else {
		int ContinueTF = Continue();
		if (ContinueTF == Yes) goto ZAKO1;
		else if (ContinueTF == No) {
			Gameover();
			goto CLEARED;
		}
	}
	if (zako2WinFlag == Enable) {
		player = {
			default.hp,
			default.maxHp,
			default.mp,
			default.maxMp,
			"えにくす",
			default.attack,
			default.defence,
			default.intelligence
		};
		cleared2 = {
			default.hp,
			default.maxHp,
			default.mp,
			default.maxMp,
			"えにくす",
			default.attack,
			default.defence,
			default.intelligence
		};
	ZAKO3:
		bonus = 20;
		PlayerUpgrowth();
		printf("\n\n\n%sは　%sとのたたかいの　けいけんから\n『マヒャド』をあみだした！\n", player.name, zako2.name);
		getchar();
		printf("『メラゾーマ』と『マヒャド』から　『メドローア』を　あみだした！\n");
		getchar();
		vszako3();
	}
	else {
		int ContinueTF = Continue();
		if (ContinueTF == Yes) {
			player = {
				cleared1.hp,
				cleared1.maxHp,
				cleared1.mp,
				cleared1.maxMp,
				"えにくす",
				cleared1.attack,
				cleared1.defence,
				cleared1.intelligence
			};
			goto ZAKO2;
		}
		else if (ContinueTF == No) {
			Gameover();
			goto CLEARED;
		}
	}
	if (zako3WinFlag == Enable) {
		player = {
			default.hp,
			default.maxHp,
			default.mp,
			default.maxMp,
			"えにくす",
			default.attack,
			default.defence,
			default.intelligence
		};
		cleared3 = {
			default.hp,
			default.maxHp,
			default.mp,
			default.maxMp,
			"えにくす",
			default.attack,
			default.defence,
			default.intelligence
		};
	ZAKO4:
		bonus = 30;
		PlayerUpgrowth();
		printf("\n\n\n%sは　%sとのたたかいの　けいけんから\n『ホイミ』が　『ベホイミ』にしんかした！\n", player.name, zako3.name);
		getchar();
		vszako4();
	}
	else {
		int ContinueTF = Continue();
		if (ContinueTF == Yes) {
			player = {
				cleared2.hp,
				cleared2.maxHp,
				cleared2.mp,
				cleared2.maxMp,
				"えにくす",
				cleared2.attack,
				cleared2.defence,
				cleared2.intelligence
			};
			goto ZAKO3;
		}
		else if (ContinueTF == No) {
			Gameover();
			goto CLEARED;
		}
	}
	if (zako4WinFlag == Enable) {
		player = {
			default.hp,
			default.maxHp,
			default.mp,
			default.maxMp,
			"えにくす",
			default.attack,
			default.defence,
			default.intelligence
		};
		cleared4 = {
			default.hp,
			default.maxHp,
			default.mp,
			default.maxMp,
			"えにくす",
			default.attack,
			default.defence,
			default.intelligence
		};
	ZAKO5:
		bonus = 55;
		PlayerUpgrowth();
		printf("\n\n\n%sは　%sとのたたかいの　けいけんから\n『こごえるふぶき』をあみだした！\n", player.name, zako4.name);
		getchar();
		printf("『しんくうぎり』が　『ギガスラッシュ』に　しんかした！\n");
		getchar();
		vszako5();
	}
	else {
		int ContinueTF = Continue();
		if (ContinueTF == Yes) {
			player = {
				cleared3.hp,
				cleared3.maxHp,
				cleared3.mp,
				cleared3.maxMp,
				"えにくす",
				cleared3.attack,
				cleared3.defence,
				cleared3.intelligence
			};
			goto ZAKO4;
		}
		else if (ContinueTF == No) {
			Gameover();
			goto CLEARED;
		}
	}
	if (ClearFlag == Enable) {
		system("cls");
		HANDLE GAMECLEAR = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(
			GAMECLEAR, // HANDLE hConsoleOutput
			FOREGROUND_RED | FOREGROUND_GREEN);// WORD wAttributes

		printf("\n\n\n\t\to     o o .oPYo. .oPYo. o .oPYo. o    o        .oo .oPYo. .oPYo. .oPYo. o     o  .oPYo. o     o .oPYo.  o    o .oPYo. ooo.   \n");
		printf("\t\t8b   d8 8 8      8      8 8    8 8b   8       .P 8 8    8 8    8 8    8 8b   d8  8    8 8     8 8       8    8 8.     8  `8. \n");
		printf("\t\t8`b d'8 8 `Yooo. `Yooo. 8 8    8 8`b  8      .P  8 8      8      8    8 8`b d'8 o8YooP' 8     8 `Yooo. o8oooo8 `boo   8   `8 \n");
		printf("\t\t8 `o' 8 8     `8     `8 8 8    8 8 `b 8     oPooo8 8      8      8    8 8 `o' 8  8      8     8     `8  8    8 .P     8    8 \n");
		printf("\t\t8     8 8      8      8 8 8    8 8  `b8    .P    8 8    8 8    8 8    8 8     8  8      8     8      8  8    8 8      8   .P \n");
		printf("\t\t8     8 8 `YooP' `YooP' 8 `YooP' 8   `8   .P     8 `YooP' `YooP' `YooP' 8     8  8      8oooo 8 `YooP'  8    8 `YooP' 8ooo'  \n");
		printf("\t\t..::::....:.....::.....:..:.....:..:::..::..:::::..:.....::.....::.....:..::::..:..:::::........:.....::..:::..:.....:.....::\n");
		printf("\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf("\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		HANDLE NORMAL = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(
			NORMAL, // HANDLE hConsoleOutput
			FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);// WORD wAttributes
		printf("\n\t\t%sは　じんるいのきぼうである %s を　たおした！\n", player.name, zako5.name);
		getchar();
		printf("\n\t\tせかいは　やみに　おおわれ　このよは　『じゃあくな　ソウル』に　しはいされた！\n");
		getchar();
		printf("\n\t\tせかいに　へいわは　おとずれない！\n");
		getchar();
		printf("\n\n\n\t\tエンターキーを　おすと　タイトルに　もどります…\n");
		getchar();
		zako1WinFlag = Disable;
		zako2WinFlag = Disable;
		zako3WinFlag = Disable;
		zako4WinFlag = Disable;
		ClearFlag = Disable;
		goto CLEARED;
	}
	else {
		int ContinueTF = Continue();
		if (ContinueTF == Yes) {
			player = {
				cleared4.hp,
				cleared4.maxHp,
				cleared4.mp,
				cleared4.maxMp,
				"えにくす",
				cleared4.attack,
				cleared4.defence,
				cleared4.intelligence
			};
			goto ZAKO5;
		}
		else if (ContinueTF == No) {
			Gameover();
			goto CLEARED;
		}
	}
	return 0;
}