#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Project
{
    string name;
    int nr_of_days, score, nr_of_roles, best_before;
};

struct Skill
{
    string name;
    short level;
    vector <Project>needTo;
    vector <string>contributorWith;
};

void pushSkill(Skill skills[], string name, string skillName, int skillLevel, int *skillsNr){
    for(int i = 0; i < *skillsNr; i++){
        if(skills[i].name == skillName && skills[i].level == skillLevel){
            skills[i].contributorWith.push_back(name);
            return;
        }
    }
    skills[*skillsNr].name = skillName;
    skills[*skillsNr].level = skillLevel;
    skills[*skillsNr].contributorWith.push_back(name);
    (*skillsNr)++;
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
            skills[i].needTo.push_back(project);
            return;
        }
    }
    skills[*skillsNr].name = skillName;
    skills[*skillsNr].level = skillLevel;
    skills[*skillsNr].needTo.push_back(project);
    (*skillsNr)++;
}


int main()
{
    ifstream f("input.txt");
    int nr_of_contributors, nr_of_projects;
    f>>nr_of_contributors>>nr_of_projects;
    cout << nr_of_contributors << " " << nr_of_projects;
    Skill skills[1000];
    int skillsNr = 0;

    //contributors
    for (int i=0; i<nr_of_contributors; i++)
    {
        string name;
        int newSkillsNr;
        string skillName;
        int skillLevel;

        f>>name>>newSkillsNr;

        //cout << "\nContributor " << i << ": " << name << " " << newSkillsNr << "\n";

        for (int j=0; j<newSkillsNr; j++)
        {
            f>>skillName>>skillLevel;
            //cout << "   " << skillName << " " << skillLevel << "\n";
            pushSkill(skills, name, skillName, skillLevel, &skillsNr);
        }
    }

    cout << "\n\n---------------------------------\n\n";

    //projects
    for (int i=0; i<nr_of_projects; i++)
    {
        string projName, skillName;
        int days, score, bbefore, roles, skillLevel;

        f>>projName>>days>>score>>bbefore>>roles;

        //cout << "\nProject " << i << ": " << projName << "\n SkillNr: " << roles << "\n Days: " << days << "\n BBefore: " << bbefore << "\n Score: " << score << "\nSkills: \n";

        for (int j=0; j<roles; j++)
        {
            f>>skillName>>skillLevel;
            //cout << "   " << skillName << " " << skillLevel << "\n";
            pushProject(skills, projName, days, score, roles, bbefore, skillName, skillLevel, &skillsNr);
        }
    }

    cout << "\n--------------------------------\n" << skillsNr;

    for (int ii=0; ii<skillsNr; ii++)
    {
        cout << "\n\n" << skills[ii].name << " " << skills[ii].level << "\n NeedTo: ";
        for (int i=0; i<skills[ii].needTo.size(); i++)
        {
            cout << skills[ii].needTo.at(i).name << " ";
        }
        cout << "\n ContrW: ";
        for (int i=0; i<skills[ii].contributorWith.size(); i++)
        {
            cout << skills[ii].contributorWith.at(i) << " ";
        }

    }

    f.close();
    return 0;
}
