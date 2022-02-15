//方块形状类
class Shape
{
public:
	Shape();
	~Shape();
 
	virtual void setShape();
private:
};
 
//"一"形
class Shape1 : public  Shape
{
public:
	Shape1();
	~Shape1();
 
	virtual void setShape();
private:
};
 
//"十"形
class Shape2 : public  Shape
{
public:
	Shape2();
	~Shape2();
 
	virtual void setShape();
private:
};
 
//"L"形
class Shape3 : public  Shape
{
public:
	Shape3();
	~Shape3();
 
	virtual void setShape();
private:
};
 
//"其他"形
class Shape4: public  Shape
{
public:
	Shape4();
	~Shape4();
 
	virtual void setShape();
private:
};
 
//方块位置类
class Place
{
public:
	Place();
	~Place();
 
	void setPlace();		
private:
};
 
//游戏界面类
class GameUI
{
public:
	GameUI();
	~GameUI();
 
	void showViewCcon();		//游戏方块显示
private:
	Shape *mShape;				//形状
	Place *mPlace;				//位置
	int mStartButton;			//开始按钮
	int mEndButton;				//结束按钮
};

