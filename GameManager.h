#pragma once

//�Q�[���t���[
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

//�t���O�Ǘ��p
enum {
	Disable,
	Enable
};

//�t�F�[�Y��
enum {
	PHASE_COMMAND,
	PHASE_BATTLE,
	PHASE_MAX
};

//�R�}���h��
enum {
	COMMAND_ATTACK,		//��������
	COMMAND_SPELL,		//�������
	COMMAND_CHALLENGE,	//���傤�͂�
	COMMAND_PARRY,		//�p���B
	COMMAND_DEFENCE,	//�ڂ�����
	COMMAND_ESCAPE,		//�ɂ���
	COMMAND_MAX			//�R�}���h�̐�
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
