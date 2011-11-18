//パッドに関する構造体
typedef struct{
	int key[PAD_MAX];
	int trigger[PAD_MAX];
	int toggle[PAD_MAX];
}pad_t;
#ifdef CPAD_STG
//コンフィグに関する構造体
typedef struct{
	int left,up,right,down,shot,bom,slow,start,change;
}configpad_t;
#else
#ifdef CPAD_ACT
//コンフィグに関する構造体
typedef struct{
	int left,up,right,down,a,b,start,select;
}configpad_t;
}
#else
#ifdef CPAD_ARROW
//コンフィグに関する構造体
typedef struct{
	int left,up,right,down;
}configpad_t;
#else
#ifdef CPAD_PS2
//コンフィグに関する構造体
typedef struct{
	int left,up,right,down,cross,cercle,triangle,square,start,select,r1,r2.l1,l2;
}configpad_t;
#else
#ifdef CPAD_DS
//コンフィグに関する構造体
typedef struct{
	int left,up,right,down,a,b,x,y,l,r,start,select;
}configpad_t;
#else
#ifdef CPAD_SIMPLE
//コンフィグに関する構造体
typedef struct{
	int left,up,right,down,ok,no;
}configpad_t;
#endif	//CPAD_SIMPLE
#endif	//CPAD_DS
#endif	//CPAD_PS2
#endif	//CPAD_ARROW
#endif	//CPAD_ACT
#endif	//CPAD_STG
