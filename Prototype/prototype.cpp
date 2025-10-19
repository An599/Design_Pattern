#include "prototypeF.hpp"

int main()
{
	auto john = EmployeeFactory::NewOfficeEmployee("John Doe", 101, "Main");
	auto jane = EmployeeFactory::NewOfficeEmployee("Jane Smith", 202, "East");
	auto mike = EmployeeFactory::NewOfficeEmployee("Mike Brown", 303, "West");

	if (john) john->show();
	if (jane) jane->show();
	if (mike) mike->show();

	auto ghost = EmployeeFactory::NewOfficeEmployee("Ghost", 404, "North");

	return 0;
}
