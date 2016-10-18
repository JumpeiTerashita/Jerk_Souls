#pragma once

//構造体（ステータス）
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

extern CHARACTER player, zako1, zako2, zako3, zako4, zako5;
extern CHARACTER default, cleared1, cleared2, cleared3, cleared4, cleared5;