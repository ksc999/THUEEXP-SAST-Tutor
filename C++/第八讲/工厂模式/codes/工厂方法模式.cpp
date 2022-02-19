#include<iostream>
using namespace std;

class AbstractEmployee
{
public:
	AbstractEmployee() {

	}
	virtual ~AbstractEmployee() {};
	virtual void nice_work() = 0;
	virtual void bad_work() = 0;
};

class Teacher :public AbstractEmployee
{
public:
	Teacher() {

	}
	~Teacher() {};
	void nice_work()
	{
		cout << "The teacher works well." << endl;
	}
	void bad_work()
	{
		cout << "The teacher works badly." << endl;
	}
};

class Professor :public AbstractEmployee
{
public:
	Professor() {

	}
	~Professor() {};
	void nice_work()
	{
		cout << "The professor works well." << endl;
	}
	void bad_work()
	{
		cout << "The professor works badly." << endl;
	}
};

class AbstractFactory
{
public:
	virtual shared_ptr<AbstractEmployee> getEmployeeEvaluation(string evaluation) = 0;
	virtual ~AbstractFactory() {}
};

class TeacherEnvaluationFactory: public AbstractFactory
{
public:
	shared_ptr<AbstractEmployee> getEmployeeEvaluation(string evaluation)
	{
		shared_ptr<AbstractEmployee> emp;
		emp = shared_ptr<AbstractEmployee>(new Teacher());
		if (evaluation == "Good")
			emp->nice_work();
		else if (evaluation == "Bad")
			emp->bad_work();
		return emp;
	}
};

class ProfessorEnvaluationFactory : public AbstractFactory
{
public:
	shared_ptr<AbstractEmployee> getEmployeeEvaluation(string evaluation)
	{
		shared_ptr<AbstractEmployee> emp;
		emp = shared_ptr<AbstractEmployee>(new Professor());
		if (evaluation == "Good")
			emp->nice_work();
		else if (evaluation == "Bad")
			emp->bad_work();
		return emp;
	}
};

int main()
{
	shared_ptr<AbstractFactory> efac = make_shared<TeacherEnvaluationFactory>();
	shared_ptr<AbstractEmployee> emp = efac->getEmployeeEvaluation("Good");
	efac = make_shared<ProfessorEnvaluationFactory>();
	emp = efac->getEmployeeEvaluation("Good");
}
