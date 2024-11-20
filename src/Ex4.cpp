#include <iostream>
#include "Ex.h"

// The Singleton Method Design Pattern ensures a class has only one instance and provides a global access onto it.
// It's iedal for scenarios requiring centralized control, like managing database connections or configuration settings

// Below are principles of the singleton pattern:
// 1. Single Instance: Singleton ensures that only one instance of the class exists throughout the application
// 2. Global Access: Provide a global point of access to that instance
// 3. Lazy or Eager Initialization: Support creating the instance either when needed (lazy) or when the class is loaded (eager)
// 4. Thread Safety: Implement mechanism to prevent multiple thread from creating separate instances simultaneously
// 5. Private Constructor: Restrict direct instanctiation by making the constructor private, forcing the use of the access point

// Use the singleton pattern when:
// Consider using the singleton pattern when you need to ensure that only one instance of a class exists in your application
// Use it when you want to provide a straightforward way for clients to access that instances form a specific location in your code
// If you think you might want to extend the class later. It allows for subclassing, so clients can work with the extended version without changing the original singleton
// This pattern is oftn used in situations like logging, managing connections to hardware or databases, cathch data, or handling thread pools, when having just one instance make sense

class Singleton
{
private:
	static Singleton* instance; // Static pointer to the unique instance
	int data; // A member variable

	// Constructor is private to prevent direct instantiation
	Singleton(): data(0)
	{
		cout << "Singleton instance created!" << endl;
	}

	// Delete copy constructor and assignment operator to prevent copying or assigning
	Singleton(const Singleton&) = delete;
	Singleton& operator= (const Singleton&) = delete;

public:
	// Method to access the unique instance
	static Singleton* getInstance()
	{
		if (instance == nullptr)
		{
			instance = new Singleton();
		}
		return instance;
	}

	// Get and Set data variable
	void setData(int value)
	{
		data = value;
	}

	int getData() const
	{
		return data;
	}

	~Singleton()
	{
		cout << "Singleton instance destroyed" << endl;
	}
};

// Initialize static members
Singleton* Singleton::instance = nullptr;

void Ex_4()
{
	// Get the first instance
	Singleton* s1 = Singleton::getInstance();
	s1->setData(42);
	
	// Get the instance again and check the data
	Singleton* s2 = Singleton::getInstance();
	cout << "Data in singleton: " << s2->getData() << endl;

	// Check if both pointers pont to the same Singleton instance
	if (s1 == s2)
	{
		cout << "Both pointers pont to the same Singleton instance" << endl;
	}

	getchar();
}
