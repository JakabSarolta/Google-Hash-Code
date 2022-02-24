#include <iostream>

using namespace std;

struct Project{
    char name[20];
    int nr_of_days, score, nr_of_roles, best_before;
};

struct Skill{
    char name[20];
    short level;
    Project needTo[1000];
    string contributorWith[1000];
};


int main()
{
    cout << "Hey";
    return 0;
}
