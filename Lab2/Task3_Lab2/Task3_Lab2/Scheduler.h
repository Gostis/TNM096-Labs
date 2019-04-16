#include <string>
#include <iostream>

using namespace std;
class Scheduler {
public:
	string schedule[24] = { "MT101", "MT102", "MT103",
		"MT104", "MT105", "MT106",
		"MT107", "MT201", "MT202",
		"MT203", "MT204", "MT205",
		"MT206", "MT301", "MT302",
		"MT303", "MT304", "MT401",
		"MT402", "MT403", "MT501",
		"MT502", "     ", "     " };

	 int numConflicts = 0;

	 int scheduleSize = sizeof(schedule) / sizeof(schedule[0]);

	 Scheduler();

	 Scheduler(string schedule[]);

	 int TotNumConflicts();

	 void Print();

	 void Solver();

	 int findMinConflictsIdx(int idx);

	 void Swap(int p1, int p2);

	 int findConflicts(string compareLec, int idx);

	 bool isConflict(int p1, int p2);
private:
	

	

	
};
