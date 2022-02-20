#include <iostream>
#include "bridge_pattern.h"

int main()
{
	Place *place;
    Job *job;
    
	//在高炉前启动指导炉前工工作的程序
	place = new gaolu();
	job = new luqian();
	place->setup(job);
    place->begin();

	//改变，在平炉前启动指导吊车工工作的程序
    delete place;
	delete job;
    place = new pinglu();
	job = new diaoche();
	place->setup(job);
    place->begin();

	delete place;
	delete job;
	return 0;
}
