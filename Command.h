#pragma once


enum {
	Yes,
	No,
	YesNomax
};

//�X�e�[�^�X
enum {
	STATUS_HP,		//��������
	STATUS_MP,		//�������
	STATUS_ATTACK,		//�ɂ���
	STATUS_DEFENCE,	//�ڂ�����
	STATUS_INTELLIGENCE,
	STATUS_MAX			//�R�}���h�̐�
};

extern char commandNames[][16], YesNo[][16],statusNames[][16];
extern int cursor;
