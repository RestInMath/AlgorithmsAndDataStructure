#include "stdafx.h"
#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List nl;
	nl.push_back(1);
	nl.push_front(5);
	nl.push_back(7);
	nl.insert(6,0);

	nl.print_to_console(); //6517

	List snl;
	snl.push_back(1);
	snl.push_back(7);

	cout << "ARE EQUAL: " << nl.isEqual(&snl) << '\n';

	snl.print_to_console();

	cout << "FIRST INTRANCE:" << nl.find_first_entrance(snl) << '\n';

    return 0;
}