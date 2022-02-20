#ifndef __BRIDGE_PATTERN_H__
#define __BRIDGE_PATTERN_H__
#include <iostream>
#include <string.h>
#include <mutex>
using namespace std;

// 实现类接口:工种
class Job
{
public:
	Job() {}
	virtual ~Job() {}
	virtual void begin() = 0;
private:
};

// 具体实现类:炉前工
class luqian :public Job
{
public:
	luqian() {}
	void begin() {
		cout << "luqian begin" << endl;
	}
};

// 具体实现类:吊车工
class diaoche :public Job
{
public:
	diaoche() {}
	void begin() {
		cout<<"diaoche begin"<<endl;
	}
};

// 具体实现类:备料工
class beiliao :public Job
{
public:
	beiliao() {}
	void begin() {
		cout << "beiliao begin" << endl;
	}
};

//抽象类：场景
class Place
{
public:
	Place() {}
	virtual ~Place() {}
	virtual void setup(Job* job) = 0;
	virtual void begin() = 0;
private:
	Job* job;
};

// 扩充抽象类：高炉
class gaolu :public Place
{
public:
	gaolu() {}
	void setup(Job* ijob) {
		this->job = ijob;
	}
	void begin() {
		this->job->begin();
	}
private:
	Job* job;
};

// 扩充抽象类：平炉
class pinglu :public Place
{
public:
	pinglu() {}
	void setup(Job* ijob) {
		this->job = ijob;
	}
	void begin() {
		this->job->begin();
	}
private:
	Job* job;
};

// 扩充抽象类：转炉
class zhuanlu :public Place
{
public:
	zhuanlu() {}
	void setup(Job* ijob) {
		this->job = ijob;
	}
	void begin() {
		this->job->begin();
	}
private:
	Job* job;
};


#endif //__BRIDGE_PATTERN_H__