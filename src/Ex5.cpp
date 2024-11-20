#include <iostream>
#include <string>
#include "Ex.h"

// The Factory Method Design Pattern is a creational design pattern that provides an interface for creating objects in a superclass, allowing subclasses to alter the type of objects that will be created.
// This pattern is particularly useful when the exact types of objects to be created may vary or need to be determined at runtime, enabling flexibility and extensibility in object creation.

// Below is when to use factory method design pattern:
// 1. If your object creation process is complex or varies under different conditions, using a factory method can make your client code simpler and promote reusability.
// 2. The Factory Method Pattern allows you to create objects through an interface or abstract class, hiding the details of concrete implementations. This reduces dependencies and makes it easier to modify or expand the system without affecting existing code.
// 3. Lazy or Eager Initialization: Support creating the instance either when needed (lazy) or when the class is loaded (eager)
// 4. Factories can also encapsulate configuration logic, allowing clients to customize the object creation process by providing parameters or options to the factory method.

// Use the singleton pattern when:
// Consider using the singleton pattern when you need to ensure that only one instance of a class exists in your application
// Use it when you want to provide a straightforward way for clients to access that instances form a specific location in your code
// If you think you might want to extend the class later. It allows for subclassing, so clients can work with the extended version without changing the original singleton
// This pattern is oftn used in situations like logging, managing connections to hardware or databases, cathch data, or handling thread pools, when having just one instance make sense

// Abstract base class for all cars
class Car {
public:
	virtual void drive() = 0;  // Pure virtual function to drive the car
	virtual ~Car() {}           // Virtual destructor for proper cleanup
};

// Concrete class for Sedan car
class SedanCar : public Car {
public:
	void drive() override {
		std::cout << "Driving a Sedan car!" << std::endl;
	}
};

// Concrete class for SUV car
class SUVCar : public Car {
public:
	void drive() override {
		std::cout << "Driving an SUV car!" << std::endl;
	}
};

// Factory class to produce cars
class CarFactory {
public:
	// Static method to create cars based on the input type
	static Car* createCar(const std::string& carType) {
		if (carType == "Sedan") {
			return new SedanCar();
		}
		else if (carType == "SUV") {
			return new SUVCar();
		}
		else {
			std::cout << "Unknown car type!" << std::endl;
			return nullptr;
		}
	}
};

void Ex_5()
{
	// Use the factory to create different types of cars
	Car* myCar1 = CarFactory::createCar("Sedan");
	if (myCar1) {
		myCar1->drive();
	}

	Car* myCar2 = CarFactory::createCar("SUV");
	if (myCar2) {
		myCar2->drive();
	}

	// Clean up
	delete myCar1;
	delete myCar2;
	
	getchar();
}
