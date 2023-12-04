#include "PickupTruck.h"


int main()
{
	Vehicle vehicle("OpelAstra", 200);
	Car opelAstra("Opel Astra", 250, 5);
	opelAstra.addPassenger("Ivan");
	opelAstra.addPassenger("Pesho");
	std::cout << opelAstra.getModel() << ", max Range: " << opelAstra.getMaxRange() << "\n";
	opelAstra.removePassenger("Ivan");

	Truck man("MAN", 500, 250, 100);
	man.load(50);
	man.unload(149);
	std::cout << man.getModel() << ", max Range: " << man.getMaxRange() << "\n";
	
	PickupTruck pikap("Bruh", 1000, 3, 600, 200);
	char* task = new char[strlen("Go to Pesho's!") + 1];
	strcpy(task, "Go to Pesho's!");

	pikap.addPassenger("Ivan");
	pikap.addPassenger("Pesho");
	pikap.addPassenger("Joro");
	pikap.removePassenger("Joro");
	pikap.setSchedule(task);
	std::cout << "Pikap next Task : " << pikap.getNextTask() << "\n";
	std::cout << "Pikap Max Range : " << pikap.getMaxRange() << "\n";
	

	return 0;
}