#pragma once

// Name: Prof Q
// Dare: 3/12/2023
// Chemistry Element (struct) contains these properties(fields/attributes) 
struct Element
{
	int atomicNumber = 0;
	char name[25] = "unknown";
	char symbol[3] = "  ";
	double atomicMass = 0.0;
	int state = 0;
	int type = 0;
	char discoverer[100] = "unknown";
	int discoveredYear = 0;
};

//lookup arrays
const string states[] = { "unknown", "Solid", "Liquid", "Gas" };
const string types[] = { "unknown", "Actinide", "Alkali Metal", "Alkaline Earth Metal", "Halogen", "Lanthanide", "Metalloid", "Noble Gas", "Reactive Nonmetal", "Post-Transition Metal",  "Transition Metal" };

//precodition  : e (an Element structure)
//postcondition: none
// display an element's fields/attibutes
void displayElement(const Element e)
{
	cout << "\n\tAtomic number   : " << e.atomicNumber;
	cout << "\n\tSymbol          : " << e.symbol;
	cout << "\n\tName            : " << e.name;
	cout << "\n\tType            : " << e.type << " (" << types[e.type] << ")";
	cout << "\n\tAtomic mass     : " << e.atomicMass;
	cout << "\n\tStandard state  : " << e.state << " (" << states[e.state] << ")";
	cout << "\n\tDiscovered by   : " << e.discoverer;
	cout << "\n\tDiscovered year : " << e.discoveredYear << "\n";
}

//precodition  : pointer to an array of Element structure)
//               size (integer of the arrary size)
//postcondition: none
// display all elements from the dynamic array
void displayPeriodicTableElements(const Element* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "\n\tPeriodic Table element[" << i << "]";
		cout << "\n\t" << string(70, char(196));
		displayElement(arr[i]);
	}
}

void updateElement(Element& e)
{
	string symbol = inputString("\n\tEnter a new symbol: ", false);
	for (int i = 0; i < symbol.length(); i++)
		symbol[i] = (i == 0) ? toupper(symbol[i]) : tolower(symbol[i]);

	strcpy_s(e.symbol, sizeof(e.symbol), symbol.c_str());

	string name = inputString("\tEnter a new name: ", false);
	for (int i = 0; i < symbol.length(); i++)
		name[i] = (i == 0) ? toupper(name[i]) : tolower(name[i]);

	strcpy_s(e.name, sizeof(e.name), name.c_str());
	e.state = inputInteger("\tEnter a new state (0-unknown, 1-Solid, 2-Liquid, or 3-Gas): ", 0, 3);
	e.atomicMass = inputDouble("\tEnter a new atomic mass: ", true);
	e.type = inputInteger("\tEnter a new type (0-unknown, 1-Actinide, 2-Alkali Metal, 3-Alkaline Earth Metal,\n\t\t\t  4-Halogen, 5-Lanthanide, 6-Metalloid, 7-Noble Gas,\n\t\t\t  8-Reactive Nonmetal, 9-Post-Transition Metal, or 10-Transition Metal): ", 0, 10);
	strcpy_s(e.discoverer, sizeof(e.discoverer), inputString("\tEnter a new discoverer: ", true).c_str());
	e.discoveredYear = inputInteger("\tEnter a new year discovered: ", true);
}