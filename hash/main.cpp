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

    //contributors
    for (int i=0; i<nr_of_contributors; i++)
    {
        string name;
        int skillsNr;
        string skillName;
        int skillLevel;

        f>>name>>skillsNr;

        cout << "\nContributor " << i << ": " << name << " " << skillsNr << "\n";


        for (int j=0; j<skillsNr; j++)
        {
            f>>skillName>>skillLevel;
            cout << "   " << skillName << " " << skillLevel << "\n";
            //pushSkill(name, skillName, skillLevel);
        }
    }

    cout << "\n\n---------------------------------\n\n";

    //projects
    for (int i=0; i<nr_of_projects; i++)
    {
        string projName, skillName;
        int days, score, bbefore, roles, skillLevel;

        f>>projName>>days>>score>>bbefore>>roles;

        cout << "\nProject " << i << ": " << projName << "\n SkillNr: " << roles << "\n Days: " << days << "\n BBefore: " << bbefore << "\n Score: " << score << "\nSkills: \n";

        for (int j=0; j<roles; j++)
        {
            f>>skillName>>skillLevel;
            cout << "   " << skillName << " " << skillLevel << "\n";
//            pushProject(projName, skillName, skillLevel);
        }
    }


    f.close();
    return 0;
}
