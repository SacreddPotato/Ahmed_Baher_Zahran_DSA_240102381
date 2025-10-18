#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Staff {
    private:
    string name;
    int published_papers;
    int teaching_hours;
    string rank;

    public:

    Staff(string name, int published_papers, int teaching_hours, string rank) {
        this->name = name;
        this->published_papers = published_papers;
        this->teaching_hours = teaching_hours;
        this->rank = rank;

    }

    string getName() const {
        return name;
    }

    int getPublishedPapers() const {
        return published_papers;
    }

    int getTeachingHours() const {
        return teaching_hours;
    }

    string getRank() const {
        return rank;
    }

    double determine_grant() {
        double grant = 0;
        
        if (this->rank == "professor") {grant += 0.2;} // 20% Extra if they're a professor
        if (this->rank == "associate") {grant += 0.15;} // 15% Extra if they're an associate
        if (this->rank == "lecturer") {grant += 0.1;} // 10% Extra if they're a lecturer
        grant += 0.01 * this->teaching_hours; // 10% For each 10 Hours
        grant += 0.05 * this->published_papers; // 5% for each paper
        
        return grant;
    }
    
   

};

int main() {
    vector<Staff> staffs = {Staff("John", 3, 20, "assistant"),
                            Staff("Bob", 1, 10, "lecturer"),
                            Staff("Alice", 5, 30, "associate"),
                            Staff("David", 0, 40, "professor"),
                            Staff("Emma", 10, 5, "lecturer"),
                            Staff("Frank", 0, 0, "lecturer"),
                            Staff("Grace", 15, 50, "associate")};
    
    for (Staff staff: staffs) {
        cout << staff.getName() << ", Grant: " << staff.determine_grant()*100 << "%\n";
    }



    return 0;
}