#pragma once

#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>

struct Address
{
	std::string street;
	size_t num;
};

struct Contact
{
	std::string name;
	Address address;
	size_t suite;

	void show() const
	{
		std::cout << "Name: " << name << std::endl << "Address: " << address.street << " " << address.num << std::endl << "Suite: " << suite << std::endl << std::endl;
	}
};


class EmployeeFactory
{
public:
	static std::unique_ptr<Contact> NewOfficeEmployee(const std::string& name, size_t suite, const std::string& branch)
	{
		auto it = branches.find(branch);
		if (it == branches.end())
		{
			std::cerr << "Branch \"" << branch << "\" not found!" << std::endl;
			return nullptr;
		}

		const Contact& prototype = it->second;
		auto newEmployee = std::make_unique<Contact>(prototype);
		newEmployee->name = name;
		newEmployee->suite = suite;

		return newEmployee;
	}

private:
	static std::unordered_map<std::string, Contact> branches;
};

inline std::unordered_map<std::string, Contact> EmployeeFactory::branches = {
	{"Main", {"", {"123 Main Street", 10}, 0}},
	{"East", {"", {"456 East Road", 20}, 0}},
	{"West", {"", {"789 West Avenue", 30}, 0}}
};
