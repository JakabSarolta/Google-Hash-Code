#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Project{
    string name;
    int nr_of_days, score, nr_of_roles, best_before;
};

struct Skill{
    string name;
    short level;
    vector <Project>needTo[1000];
    vector <string>contributorWith[1000];
};


void pushSkill(Skill skills[], string name, string skillName, int skillLevel, int *skillsNr){
    for(int i = 0; i < *skillsNr; i++){
        if(skills[i].name == name && skills[i].level == skillLevel){
            skills[i].contributorWith->push_back(name);
            return;
        }
    }
    skills[*skillsNr].name = skillName;
    skills[*skillsNr].contributorWith->push_back(name);
}


int main()
{
    ifstream f("input.txt");
    int nr_of_contributors, nr_of_projects;
    f>>nr_of_contributors>>nr_of_projects;
    cout << nr_of_contributors << " " << nr_of_projects;
    Skill skills[100];
    int skillsNr = 0;

    //contributors
    for (int i=0; i<nr_of_contributors; i++)
    {
        string name;
        int skillsNr;
        string skillName;
        int skillLevel;

        f>>name>>skillsNr;

        for (int j=0; j<skillsNr; j++)
        {
            f>>skillName>>skillLevel;

            pushSkill(skills, name, skillName, skillLevel, &skillsNr);
        }
    }


    f.close();
    return 0;
}
