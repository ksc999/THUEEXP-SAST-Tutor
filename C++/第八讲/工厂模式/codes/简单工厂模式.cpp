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

class EnvaluationFactory
{
public:
	std::shared_ptr<AbstractEmployee> getEmployeeEvaluation(string employeename,string evaluation)
	{
		std::shared_ptr<AbstractEmployee> emp;
		if (employeename == "Teacher") {
			emp = std::shared_ptr<AbstractEmployee>(new Teacher());
		}
		else if (employeename == "Professor") {
			emp = std::shared_ptr<AbstractEmployee>(new Professor());
		}
		if (evaluation == "Good")
			emp->nice_work();
		else if (evaluation == "Bad")
			emp->bad_work();
		return emp;
	}
};

int main()
{
	shared_ptr<EnvaluationFactory> efac = std::make_shared<EnvaluationFactory>();
	shared_ptr<AbstractEmployee> emp = efac->getEmployeeEvaluation("Teacher","Good");
	emp = efac->getEmployeeEvaluation("Professor", "Bad");
}
