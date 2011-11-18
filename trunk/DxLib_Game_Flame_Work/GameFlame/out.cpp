#include "GV.h"
#include <math.h>

typedef struct{
	double x,y;
}Vector2_t;

//円同士の当たり判定 ...Check OK
int HitCheck(double ax,double ay,double ar,double bx,double by,double br){
	double x=bx-ax;
	double y=by-ay;
	double r=ar+br;
	if(x*x+y*y<r*r)//当たり判定内なら
		return 1;//当たり
	else//そうでないなら
		return 0;//はずれ
}
//矩形同士の当たり判定
int HitCheck(int x1,int y1,unsigned int h1,unsigned int w1,int x2,int y2,unsigned int h2,unsigned int w2){
	int X0 =x1		,	Y0	=y1,
		X1 =x1+w1	,	Y1	=y1+h1,
		X2 =x2		,	Y2	=y2,
		X3 =x2+w2	,	Y3	=y2+h2;
	

	if(DEVELOP){
		DrawBox(X0,Y0,X1,Y1,GetColor(255,255,  0),FALSE);//PLAYER
		DrawBox(X2,Y2,X3,Y3,GetColor(255,  0,255),FALSE);//OBJECT
	}
	//X0 < X3、X2 < X1、Y2 < Y1、Y0 < Y3 
	//if(X0 < X3 && X2 < X1 && Y0 < Y3 && Y2 < Y1)

	//	X0 < X3	,  X2 < X1 ,  Y0 < Y.  , Y2 < Y1
	if( X0 < X3 && X2 < X1 && Y0 < Y3 && Y2 < Y1 )
		return 1;
	else
		return 0;
}


int HitCheck_P2R(double px,double py,double rx,double ry,double rrange){
	return HitCheck(px,py,0.0,rx,ry,rrange);
}
//点と点との距離を返す
double get_pt_and_pt(Vector2_t p1, Vector2_t p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}


//ベクトル作る
/*
void makeVector(double ax,double bx,double *px,double ay,double by,double *py){
	*px=ax-bx;
	*py=ay-by;
}
*/
void makeVector_t(Vector2_t *diff,const Vector2_t *p,const Vector2_t *q){
	diff->x = p->x - q->x;
	diff->y = p->y - q->y;
}
//内積
double VectorInnerProduct(double ax,double ay,double bx,double by){
	return ax*bx+ay+by;
}
//外積
double VectorOuterProduct(double ax,double ay,double bx,double by){
	return ax*by-bx*ay;
}
/* ベクトル p と q の内積 */
double Vector2InnerProduct(const Vector2_t *p, const Vector2_t *q){
	return p->x * q->x + p->y * q->y;
}

/* ベクトル p と q の外積 */
double Vector2OuterProduct(const Vector2_t *p, const Vector2_t *q){
	return p->x * q->y - p->y * q->x;
}

//点と線分との距離を求める
double get_distance(double x, double y, double x1, double y1, 
					double x2, double y2){
	double dx,dy,a,b,t,tx,ty;
	double distance;
	dx = (x2 - x1); dy = (y2 - y1);
	a = dx*dx + dy*dy;
	b = dx * (x1 - x) + dy * (y1 - y);
	t = -b / a;
	if (t < 0) t = 0;
	if (t > 1) t = 1;
	tx = x1 + dx * t;
	ty = y1 + dy * t;
	distance = sqrt((x - tx)*(x - tx) + (y - ty)*(y - ty));
	return distance;
}


//三点からの角度
double InsideTheShell(double ax,double ay,double bx,double by,double rx, double ry){
	
	Vector2_t c={ax,ay},p={bx,by},q={rx,ry};
	Vector2_t cp,cq;
	double theta,theta2; //Rad
	double ret;

//	makeVector(p.x,c.x,&cp.x,p.y,c.y,&cp.y);
//	makeVector(q.x,c.x,&cq.x,q.y,c.y,&cq.y);
	makeVector_t(&cp, &p, &c);
	makeVector_t(&cq, &q, &c);
	theta	=	VectorInnerProduct(cp.x,cp.y,cq.x,cq.y);
	theta2	=	VectorOuterProduct(cp.x,cp.y,cq.x,cq.y);
	ret = atan2(theta2,theta);
	return ret;
}
void lazer_calc(Vector2_t start,double width,double height,Vector2_t disp[4],Vector2_t outpt[4],double angle,double HF){
//	display
	disp[0].x=start.x+cos(angle+PI/2)*width;
	disp[0].y=start.y+cos(angle+PI/2)*width;
	disp[1].x=start.x+cos(angle-PI/2)*width;
	disp[1].y=start.y+cos(angle-PI/2)*width;
	disp[2].x=start.x+cos(angle-PI/2)*width+cos(angle)*height;
	disp[2].y=start.y+cos(angle-PI/2)*width+sin(angle)*height;
	disp[3].x=start.x+cos(angle+PI/2)*width+cos(angle)*height;
	disp[3].y=start.y+cos(angle+PI/2)*width+sin(angle)*height;
//////////////////////////////////////////////////////////////////
	outpt[0].x=start.x+cos(angle+PI/2)*(width*HF)+cos(angle)*height*((1-HF)/2);
	outpt[0].y=start.y+sin(angle+PI/2)*(width*HF)+sin(angle)*height*((1-HF)/2);
	outpt[1].x=start.x+cos(angle-PI/2)*(width*HF)+cos(angle)*height*((1-HF)/2);
	outpt[1].y=start.y+sin(angle-PI/2)*(width*HF)+sin(angle)*height*((1-HF)/2);
	outpt[2].x=start.x+cos(angle-PI/2)*(width*HF)+cos(angle)*height*(HF+cos(angle)*((1-HF)/2));
	outpt[2].y=start.y+sin(angle-PI/2)*(width*HF)+sin(angle)*height*(HF+sin(angle)*((1-HF)/2));
	outpt[3].x=start.x+cos(angle+PI/2)*(width*HF)+cos(angle)*height*(HF+cos(angle)*((1-HF)/2));
	outpt[3].y=start.y+sin(angle+PI/2)*(width*HF)+sin(angle)*height*(HF+sin(angle)*((1-HF)/2));
	if(DEVELOP){
		for(int i=0;i<4;i++)
			DrawCircle(disp[i].x,disp[i].y,3,GetColor(255,120,  0));
		for(int i=0;i<4;i++)
			DrawCircle(outpt[i].x,outpt[i].y,3,GetColor(  0,120,255));
	}

}

double InsideTheShell_t(Vector2_t pt0,Vector2_t pt1,Vector2_t rpt){
	/* ベクトル C→P と C→Q のなす角θおよび回転方向を求める．*/
	Vector2_t c, p, q; /* 入力データ */
	Vector2_t cp;	  /* ベクトル C→P */
	Vector2_t cq;	  /* ベクトル C→Q */
	double s;		  /* 外積：(C→P) × (C→Q) */
	double t;		  /* 内積：(C→P) ・ (C→Q) */
	double theta;	  /* θ (ラジアン) */

	/* c，p，q を所望の値に設定する．*/
	c.x = pt0.x;	c.y = pt0.y;
	p.x = pt1.x;	p.y = pt1.y;
	q.x = rpt.x;	q.y = rpt.y;
	
	/* 回転方向および角度θを計算する．*/
	makeVector_t(&cp, &p, &c);		  /* cp ← p - c   */
	makeVector_t(&cq, &q, &c);		  /* cq ← q - c   */
	s = Vector2OuterProduct(&cp, &cq); /* s ← cp × cq */
	t = Vector2InnerProduct(&cp, &cq); /* t ← cp ・ cq */
	theta = atan2(s, t);
	return theta;
	
}

int HitCheck(double x,double y,double width,double height,double angle,double rx,double ry,double Range,double HF=1.0){
	double theta ,theta2;
	Vector2_t startp,rpt={rx,ry};
	Vector2_t disppt[4],outpt[4];
	startp.x=x;
	startp.y=y;
	lazer_calc(startp,width,height,disppt,outpt,angle,HF);
//	theta  =  InsideTheShell(outpt[0].x,outpt[0].y,outpt[1].x,outpt[1].y,rx,ry);
//	theta2 =  InsideTheShell(outpt[2].x,outpt[2].y,outpt[3].x,outpt[3].y,rx,ry);
	theta  =  InsideTheShell_t(outpt[0],outpt[1],rpt);
	theta2 =  InsideTheShell_t(outpt[2],outpt[3],rpt);
	if(DEVELOP){
		clsDx();
		/////////////////////////////////////////////////////////
		printfDx("Ch.X = %f\tCh.Y = %f\t\ttheta = %f theta2 = %f\n\n\n",rx,ry);
		printfDx("A.X = %f\tA.Y = %f\n",disppt[0].x,disppt[0].y);
		printfDx("B.X = %f\tB.Y = %f\n",disppt[1].x,disppt[1].y);
		printfDx("C.X = %f\tC.Y = %f\n",disppt[2].x,disppt[2].y);
		printfDx("D.X = %f\tD.Y = %f\n",disppt[3].x,disppt[3].y);
		/////////////////////////////////////////////////////////
		DrawLine(outpt[0].x,outpt[0].y,outpt[1].x,outpt[1].y,GetColor(255,  0,  0));
		DrawLine(outpt[1].x,outpt[1].y,outpt[2].x,outpt[2].y,GetColor(  0,255,  0));
		DrawLine(outpt[2].x,outpt[2].y,outpt[3].x,outpt[3].y,GetColor(  0,  0,255));
		DrawLine(outpt[3].x,outpt[3].y,outpt[0].x,outpt[0].y,GetColor(255,  0,255));
		DrawLine(outpt[0].x,outpt[0].y,rx,ry,GetColor(128,  0,  0));
		DrawLine(outpt[2].x,outpt[2].y,rx,ry,GetColor(  0,128,128));

	}
	

	for(int i=0;i<4;i++){
		if(HitCheck_P2R(outpt[i].x,outpt[i].y,rx,ry,Range)>0)//円の半径に四つ角のドットが入っている
			return 1;
	}

	if(0<=theta && theta<=PI/2 && 0<=theta2 && theta2<=PI/2)
		return 1;
	/*線分と点との距離を求める*/
	for(int i=0;i<4;i++){
		if(get_distance(rpt.x,rpt.y,outpt[i].x,outpt[i].y,outpt[(i+1)%4].x,outpt[(i+1)%4].y)<Range)
			return 1;
	}


	return 0;
}

