#include <iostream>

/**
 * Up to now, we’ve been doing a type of programming called procedural programming. 
 * In procedural programming, the focus is on creating “procedures” (which in C++ are called functions) 
 * that implement our program logic. We pass data objects to these functions, 
 * those functions perform operations on the data, and then potentially return a 
 * result to be used by the caller.
 */

 /**
  * REMINDER:
  * Because a class is a program-defined data type, it must be defined before it can be used.
  */
struct Date
{
    int year {};
    int month {};
    int day {};

    void print() // defines a member function named print
    {
        std::cout << year << '/' << month << '/' << day << '\n';
    }

    void const_print() const // defines a member function named print
    {
        std::cout << year << '/' << month << '/' << day << '\n';
    }

    void printYear(const Date& date ){
        std::cout << "The year is :" << date.year << '\n';
    }

    void incrementYear(){
        year+=1; 
    }

    // Compilation erro 
    // void const_incremment_Year() const 
    // {
    //     year+=1; 
    // }
};

// Const class objects and const member functions 
/**
 * When a program-defined type is declared as constant
 * you cannot modified either the member attributes nor 
 * the member functions can modifies attributes 
 */
void const_struct_example(){
    Date today { 2020, 10, 14 }; // aggregate initialize our struct

    today.day = 16; // member variables accessed using member selection operator (.)
    today.print();  // member functions also accessed using member selection operator (.)

    today.printYear(today);

    // Compilation error 

    // const Date today { 2020, 10, 15 };
    
    // today.incrementYear();
}

// WARNING: constant objects may not call non-constant member functions 
void not_const_calling_member_functions(){
    const Date today {2020, 10, 15};

    today.const_print();
    // today.print();
}

/**
 * REMINDER:
 * A const member function may not: modify the implicit object, call non-const member functions.
 * 
 * A const member function may: modify objects that aren’t the implicit object, 
 * call const member functions, call non-member functions.
 */

/**
 * REMINDER:
 * We typically make the reference const to allow 
 * the function to accept const lvalue arguments and rvalue arguments
 */

// PUBLIC AND PRIVATE MEMBERS AND ACCES SPECIFIERS 

/**
 * The members of a struct are public by default. Public members can be accessed by 
 * other members of the class type, and by the public.
 * 
 * The term “the public” is used to refer to code that exists outside of the members of a 
 * given class type. This includes non-member functions, as well as the members of other class types.
 */


class DateClass // now a class instead of a struct
{
    // class members are private by default, can only be accessed by other members
    int m_year {};     // private by default
    int m_month {};    // private by default
    int m_day {};      // private by default

    void print() const // private by default
    {
        // private members can be accessed in member functions
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }
};


/**
 * REMINDER:
 * Members of a class are private by default
 * Private members are members of a class type that can only 
 * be accessed by other members of the same class.
 */


// aggregate can have “no private or protected non-static data members.” 

/**
 * Our Date class has private data members (because the members of classes are private by default), 
 * so our Date class does not qualify as an aggregate. Therefore, we can not use aggregate initialization 
 * to initialize it any more.
 */

// Because the memebers of the class are private, we cannot use aggregate initialization 
// So the DateClass today {2020, 10, 14} is not allowed anymore 


/**
 * CONVENTION:
 * is a common convention to name private data members starting with an “m_” prefix.
 * This is the same reason we recommend using “s_” prefixes for local static variables, 
 * and “g_” prefixes for globals.
 */


class DateClassWithAccessSpecifier // now a class instead of a struct
{
public: 
    void print() const // private by default
    {
        // private members can be accessed in member functions
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }
private:
    // class members are private by default, can only be accessed by other members
    int m_year {};     // private by default
    int m_month {};    // private by default
    int m_day {};      // private by default

};


/**
 * We want our structs to be aggregates, and aggregates can only have public members.
 */


// Maybe define class invariants


/**
 * BEST PRACTICE:
 * As a rule of thumb, use a struct when all of the following are true:
 *      You have a simple collection of data that doesn’t benefit from restricting access.
 *      Aggregate initialization is sufficient.
 *      You have no class invariants, setup needs, or cleanup needs.
 */


//Exercise

// a) Write a class named Point3d. The class should contain:

// Three private member variables of type int named m_x, m_y, and m_z;
// A public member function named setValues() that allows you to set values for m_x, m_y, and m_z.
// A public member function named print() that prints the Point in the following format: <m_x, m_y, m_z>

// b) Add a function named isEqual() to your Point3d class. The following code should run correctly:

class Point3d{

public:

    void setValues(int x, int y, int z)
    {
        m_x=x; 
        m_y=y;
        m_z=z;
    }

    void print()
    {
        std::cout<< "<"<<m_x<<", "<<m_y<<", "<<m_z<<">";
    }

    bool isEqual(Point3d other)
    {
        return (m_x==other.m_x && m_y==other.m_y && m_z==other.m_z);
    }

private:

    int m_x; 
    int m_y; 
    int m_z;
};

void checking_A(){
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';
}

void checking_B(){
    Point3d point1{};
	point1.setValues(1, 2, 3);

	Point3d point2{};
	point2.setValues(1, 2, 3);

	std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

	Point3d point3{};
	point3.setValues(3, 4, 5);

	std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";
}

/**
 * ACCESS FUNCTION: 
 * 
 * An access function is a trivial public member function whose job is to retrieve or 
 * change the value of a private member variable.
 * 
 * Getters (also sometimes called accessors) are public member functions 
 * that return the value of a private member variable
 * 
 * Setters (also sometimes called mutators) are public member functions 
 * that set the value of a private member variable
 */

// Returning data members 
// Consider the class 

class Employee
{
	std::string m_name{};
    std::string m_information {};
    int m_age {};

public:
	void setName(std::string_view name) { m_name = name; }
    void setAge(int age){m_age=age;}
    void fillInformation(){
        m_information += "Name: "+ m_name + " Age: " + std::to_string(m_age) + '\n' ;
    }
	const std::string& getName() const { return m_name; } //  getter returns by const reference
    
    const std::string& getInformation() const {return m_information;} 

};


/**
 * It is okay to return a (const) lvalue reference to a data member. 
 * The implicit object (containing the data member) still exists in 
 * the scope of the caller after the function returns, so any returned references will be valid.
 */

/**
 * WARNING:
 * An rvalue object is destroyed at the end of the full expression in which it is created. 
 * Any references to members of the rvalue object are left dangling at that point.
 * 
 * A reference to a member of an rvalue object can only be safely used within the full 
 * expression where the rvalue object is created.
 */

// In order to explore the Warning consider : 

// createEmployee() returns an Employee by value (which means the returned value is an rvalue)
Employee createEmployee(std::string_view name)
{
	Employee e;
	e.setName(name);
	return e;
}

void cases_for_data_members_for_rvalue(){
    // Case 1: okay: use returned reference to member of rvalue class object in same expression
	std::cout << createEmployee("Frank").getName() << '\n';

    // Case 2: bad: save returned reference to member of rvalue class object for use later
	const std::string& ref { createEmployee("Garbo").getName() }; // reference becomes dangling when return value of createEmployee() is destroyed
	std::cout << ref << '\n'; // undefined behavior

    // Case 3: okay: copy referenced value to local variable for use later
	std::string val { createEmployee("Hans").getName() }; // makes copy of referenced member
	std::cout << val << '\n'; // okay: val is independent of referenced member
}

/**
 * In this example we are cheking whats is the result of using the operator "=" on class instances
 * 
 * Whats happening:
 * 
 * El operador = por defecto copia cada miembro por valor, llamando al operator= de cada miembro.
 * Para tipos básicos: copia directa de bits.
 * Para tipos clase (como std::string): copia profunda del contenido 
 * (cada objeto tiene su propio almacenamiento interno).
 */

void getter_by_const_reference(){
    Employee joe{};
	joe.setName("Joe");
    joe.setAge(30);
    joe.fillInformation();
    // std::cout << joe.cloneEmployee().getName() << '\n';
    // std::cout << "joe object address: " << &joe << "\n";
    
    Employee juan {};
    juan.setName("Juan");
    juan.setAge(50);
    juan.fillInformation();
    // std::cout << "juan object address: " << &juan << "\n";
    
    std::cout << joe.getInformation();
    std::cout << juan.getInformation();

    joe = juan;
    std::cout << "Asignation" << '\n';

    // std::cout << "joe object address: " << &joe << "\n";
    // std::cout << "juan object address: " << &juan << "\n";

    std::cout << joe.getInformation();
    std::cout << juan.getInformation();
}

// A good example about the Warning >> 
// EXAMPLE START
class Employees
{
private:
	std::string m_name{};

public:
	void setName(std::string_view name) { m_name = name; }
    // Note that in getName the parameter is being passed by value not by reference
    // So even the returning data is a string reference, the parameter troll will be a copy 
    // So it will be a rvalue that will only last in this scope 
    const std::string& getName(Employees troll) const { return troll.m_name; } //  getter returns by const reference

    // If we would pass a Employees reference instead a value, the problem would be solve 
    // const std::string& getName(Employees troll) const { return troll.m_name; }
};

void example_of_dangling_reference(){
    Employees joe{}; // joe exists until end of function
	joe.setName("Joe");
    Employees mama{};
    mama.setName("Mama");
    // So in the getName(mama) we are getting the reference to a string from a rvalue 
    const std::string& joeName {joe.getName(mama)};

    // And there is nothing stored in the joeName 
	std::cout << joeName << '\n'; // returns joe.m_name by reference
}

// EXAMPLE END

int main()
{
 
    // DateClassWithAccessSpecifier date_not_initialized {};
    // date_not_initialized.print();
    
    // checking_A();

    // checking_B();

    // getter_by_const_reference();

    cases_for_data_members_for_rvalue();

    // example_of_dangling_reference();


    return 0;
}

