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
    vector <Project>needTo[100];
    vector <string>contributorWith[100];
};


void pushSkill(Skill skills[], string name, string skillName, int skillLevel, int *skillsNr){
    for(int i = 0; i < *skillsNr; i++){
        if(skills[i].name == skillName && skills[i].level == skillLevel){
            skills[i].contributorWith->push_back(name);
            return;
        }
    }
    skills[*skillsNr].name = skillName;
    skills[*skillsNr].contributorWith->push_back(name);
}

void pushProject(Skill skills[], string projectName, int days, int score, int roles,
                 int best_before, string skillName, int skillLevel, int *skillsNr){
    Project project;
    project.name = projectName;
    project.nr_of_days = days;
    project.nr_of_roles = roles;
    project.best_before = best_before;
    project.score = score;

    for(int i = 0; i < *skillsNr; i++){
        if(skills[i].name == skillName && skills[i].level == skillLevel){
            skills[i].needTo->push_back(project);
            return;
        }
    }
    skills[*skillsNr].name = skillName;
    skills[*skillsNr].needTo->push_back(project);
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
