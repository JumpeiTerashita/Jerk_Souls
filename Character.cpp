#include "Character.h"

//���̂̐錾�i���ɂ����j
CHARACTER player = {
	30,
	30,
	10,
	10,
	"�䂤����",
	4,
	4,
	10
};

//���̂̐錾�i������j
CHARACTER zako1 = {
	40,
	40,
	0,
	0,
	"�����",
	4,
	2,
	1
};

//���̂̐錾�i����܂ǂ����j
CHARACTER zako2 = {
	70,
	70,
	50,
	50,
	"����܂ǂ���",
	2,
	6,
	12
};

//���̂̐錾�i�������Ƃ��j
CHARACTER zako3 = {
	150,
	150,
	50,
	50,
	"�������Ƃ�",
	35,
	2,
	40
};

//���̂̐錾�i���イ�����j
CHARACTER zako4 = {
	270,
	270,
	50,
	50,
	"���イ����",
	50,
	10,
	8
};

//���̂̐錾�i�䂤����j
CHARACTER zako5 = {
	500,
	500,
	50,
	50,
	"���g",
	70,
	30,
	30
};


//�X�e�[�^�X�ꎞ�ۑ��p
CHARACTER default = {
	player.hp,
	player.maxHp,
	player.mp,
	player.maxMp,
	"�䂤����",
	player.attack,
	player.defence,
	player.intelligence
};

CHARACTER cleared1 = {
	default.hp,
	default.maxHp,
	default.mp,
	default.maxMp,
	"�䂤����",
	default.attack,
	default.defence,
	default.intelligence
};

CHARACTER cleared2 = {
	default.hp,
	default.maxHp,
	default.mp,
	default.maxMp,
	"�䂤����",
	default.attack,
	default.defence,
	default.intelligence
};

CHARACTER cleared3 = {
	default.hp,
	default.maxHp,
	default.mp,
	default.maxMp,
	"�䂤����",
	default.attack,
	default.defence,
	default.intelligence
};

CHARACTER cleared4 = {
	default.hp,
	default.maxHp,
	default.mp,
	default.maxMp,
	"�䂤����",
	default.attack,
	default.defence,
	default.intelligence
};

CHARACTER cleared5 = {
	default.hp,
	default.maxHp,
	default.mp,
	default.maxMp,
	"�䂤����",
	default.attack,
	default.defence,
	default.intelligence
};