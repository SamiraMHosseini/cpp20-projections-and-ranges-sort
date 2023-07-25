#include <iostream>
#include <algorithm>

// Person struct to hold data for each person.
struct Person
{
    std::string name;
    std::size_t age;
    std::size_t ID;

    // Constructor
    Person(std::string_view name_, std::size_t age_, std::size_t ID_) :
        name(name_), age(age_), ID(ID_)
    {
    }

    // Operator overload for less than, used for default sorting by age.
    bool operator< (const Person& rhs) const
    {
        return this->age < rhs.age;
    }

    // Getter for age
    std::size_t getAge() const
    {
        return this->age;
    }

    // Getter for name
    std::string getName() const
    {
        return this->name;
    }

    // Getter for ID
    std::size_t getID() const
    {
        return this->ID;
    }
};

// Custom comparison function for sorting by ID
struct Comp
{
    bool operator()(const Person& lhs, const Person& rhs)
    {
        return lhs.getID() < rhs.getID();
    }
};

int main()
{
    std::vector<Person> people{ {"Samira",19,1}, {"Mona",49,7}, {"Aida",55,3}, {"Pashmak",1,12} };

    // Sorting using operator < overload (by age)
    std::cout << "-------------SORTED BY age---------------------------\n";
    std::sort(people.begin(), people.end());
    for (const auto& person : people)
    {
        std::cout << person.getName() << " : " << person.getAge() << " : " << person.getID() << '\n';
    }

    // Sorting using custom comparison function (by ID)
    std::cout << "--------------SORTED BY ID--------------------------\n";
    std::ranges::sort(people, Comp());
    for (const auto& person : people)
    {
        std::cout << person.getName() << " : " << person.getAge() << " : " << person.getID() << '\n';
    }

    // Sorting using lambda function (by name)
    std::cout << "----------------SORTED BY name------------------------\n";
    std::ranges::sort(people, [](const Person& lhs, const Person& rhs)->bool { return lhs.getName() < rhs.getName(); });
    for (const auto& person : people)
    {
        std::cout << person.getName() << " : " << person.getAge() << " : " << person.getID() << '\n';
    }

    // Sorting using C++20 projection (by age)
    std::cout << "----------------SORTED BY age using projection------------------------\n";
    std::ranges::sort(people, {}, &Person::getAge);
    for (const auto& person : people)
    {
        std::cout << person.getName() << " : " << person.getAge() << " : " << person.getID() << '\n';
    }
}
