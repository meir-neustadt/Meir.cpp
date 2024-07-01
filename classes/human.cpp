#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include <chrono>

#define tab " "

class Human {
public:
    enum class Gender { Male, Female, Other, NotShare };

private:
    std::string family;
    std::string name;
    std::tm birthDate;
    Gender gender;
    std::map<std::string, std::string> hobbies;

public:
    Human(const std::string& fam, const std::string& nm, const std::tm& bd, Gender g, const std::map<std::string, std::string>& hbs)
        : family(fam), name(nm), birthDate(bd), gender(g), hobbies(hbs) {}

    ~Human() = default;

    int age() const {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm* now_tm = std::localtime(&now_c);

        int years = now_tm->tm_year + 1900 - birthDate.tm_year;
        if (now_tm->tm_mon < birthDate.tm_mon || 
           (now_tm->tm_mon == birthDate.tm_mon && now_tm->tm_mday < birthDate.tm_mday)) {
            --years;
        }
        return years;
    }

    void printInfo() const {
        std::cout << "Name: " << name << tab << family << std::endl;
        std::cout << "Age: " << age() << std::endl;
        std::cout << "Gender: " << genderToString(gender) << std::endl;
        std::cout << "Hobbies: ";
        for (const auto& hobby : hobbies) {
            std::cout << hobby.first << ": " << hobby.second << ", ";
        }
        std::cout << std::endl;
    }

private:
    static std::string genderToString(Gender g) {
        switch (g) {
            case Gender::Male: return "Male";
            case Gender::Female: return "Female";
            case Gender::Other: return "Other";
            case Gender::NotShare: return "Prefer not to share";
            default: return "Unknown";
        }
    }
};

int main() {
    std::tm birthDate = {};
    birthDate.tm_year = 1990 - 1900; // Years since 1900
    birthDate.tm_mon = 5 - 1;        // Months since January
    birthDate.tm_mday = 15;

    std::map<std::string, std::string> hobbies = {
        {"Reading", "Books"},
        {"Sports", "Football"}
    };

    Human person("Doe", "John", birthDate, Human::Gender::Male, hobbies);
    person.printInfo();

    return 0;
}
