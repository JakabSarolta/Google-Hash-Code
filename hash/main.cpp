#include <iostream>
#include <fstream>

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
    ifstream f("input.txt");
    int nr_of_contributors, nr_of_projects;
    f>>nr_of_contributors>>nr_of_projects;
    cout << nr_of_contributors << " " << nr_of_projects;

    for (int i=0; i<nr_of_contributors; i++)
    {

    }


    f.close();
    return 0;
}
