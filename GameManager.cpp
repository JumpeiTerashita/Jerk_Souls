#include "GameManager.h"

//ƒtƒ‰ƒOE•Ï”—Ş‰Šú‰»
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
int GameFlow = PHASE_TITLE;