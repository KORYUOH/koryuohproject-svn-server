//�p�b�h�Ɋւ���\����
typedef struct{
	int key[PAD_MAX];
	int trigger[PAD_MAX];
	int toggle[PAD_MAX];
}pad_t;
#ifdef CPAD_STG
//�R���t�B�O�Ɋւ���\����
typedef struct{
	int left,up,right,down,shot,bom,slow,start,change;
}configpad_t;
#else
#ifdef CPAD_ACT
//�R���t�B�O�Ɋւ���\����
typedef struct{
	int left,up,right,down,a,b,start,select;
}configpad_t;
}
#else
#ifdef CPAD_ARROW
//�R���t�B�O�Ɋւ���\����
typedef struct{
	int left,up,right,down;
}configpad_t;
#else
#ifdef CPAD_PS2
//�R���t�B�O�Ɋւ���\����
typedef struct{
	int left,up,right,down,cross,cercle,triangle,square,start,select,r1,r2.l1,l2;
}configpad_t;
#else
#ifdef CPAD_DS
//�R���t�B�O�Ɋւ���\����
typedef struct{
	int left,up,right,down,a,b,x,y,l,r,start,select;
}configpad_t;
#else
#ifdef CPAD_SIMPLE
//�R���t�B�O�Ɋւ���\����
typedef struct{
	int left,up,right,down,ok,no;
}configpad_t;
#endif	//CPAD_SIMPLE
#endif	//CPAD_DS
#endif	//CPAD_PS2
#endif	//CPAD_ARROW
#endif	//CPAD_ACT
#endif	//CPAD_STG
