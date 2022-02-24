#include <iostream>

using namespace std;

struct Skill{
    char name[20];
    short level;
};

struct Contributor{
    char name[20];
    Skill skills[1000];
};

struct Project{
    char name[20];
    int nr_of_days, score, nr_of_roles, best_before;
    Skill skills[1000];
};

int main()
{
    cout << "Hey";
    return 0;
}
