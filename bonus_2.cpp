#include<bits/stdc++.h>
using namespace std;

int MaxScore = 100; //Max score of student

struct student //info of all student
{
    char name[20], surname[20], grade;
    int score;
    //bool operator < (const student &b) const
    //{
    //    return score < b.score; // sort data min to max
    //}
}Student[10];//have 10 students

bool Sortname (const student &a, const student &b)
{
        return a.name[0] < b.name[0]; // sort name
}

int Maxstudent(int n) //function for find max score of all student
{
    int maxscore = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        //maxscore = max(maxscore, Student[i].score);
        maxscore = (maxscore < Student[i].score)?Student[i].score: maxscore;
    }
    return maxscore;
}

int Minstudent(int n)//function for find min score of all student
{
    int minscore = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        //minscore = min(minscore, Student[i].score);
        minscore = (minscore > Student[i].score)?Student[i].score: minscore;
    }
    return minscore;
}

float AvrScore(int n)//function for find Average score of all student
{
    float Avr = 0;
    for(int i = 0; i < n; i++)
    {
        Avr += Student[i].score;
    }
    Avr /= n;
    return Avr;
}

int ModeScore(int n)//function for find mode score of all student
{
    int check[101] = {}, nMode = 0, ScoreMode;
    for(int i = 0; i < n; i++)
    {
        check[Student[i].score]++;
        if(check[Student[i].score] > nMode)
        {
            nMode = check[Student[i].score];
            ScoreMode = Student[i].score;
        }
    }
    return ScoreMode;
}

int MedianScore(int n)//function for find median score of all student
{
    int pn = (n + 1) / 2 + 1;
    if(n % 2 == 0)
        return Student[pn].score;
    else
        return (Student[pn].score + Student[pn - 1].score) / 2;
}

float SDScore(int n)//function for find S.D. score of all student
{
    float Avr = AvrScore(n), sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += pow(Student[i].score - Avr, 2);
    }
    float SD = sqrt(sum / (n - 1));
    return SD;
}

void find_grade(int n)
{
    float avr = AvrScore(n), sd = SDScore(n);
    for(int i = 0; i < n; i++)
    {
        //cout<< Student[i].score<< " "<<avr<<" "<<sd<<endl;
        if(Student[i].score > avr + 2*sd) Student[i].grade = 'A';
        else if(Student[i].score > avr + sd) Student[i].grade = 'B';
        else if(Student[i].score > avr) Student[i].grade = 'C';
        else if(Student[i].score > avr - sd) Student[i].grade = 'D';
        else Student[i].grade = 'F';
    }
}

int main()
{
    cout << fixed << setprecision(2); // set float showed 2 decimal points
    int n;
    cout << "How many students? : ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << endl << "Enter Name :";
        cin >> Student[i].name;
        cout << "Enter Surname :";
        cin >> Student[i].surname;
        cout << "Enter Score :";
        cin >> Student[i].score;
        cout << endl;
    }
    //sort(Student, Student + n);

    for(int i = 0; i < n; i++) //sort
    {
        int score_swap = INT_MAX, point_swap;
        char name_swap[20], surname_swap[20];
        for(int j = i; j < n; j++)//find min
        {
            if(score_swap > Student[j].score)
            {
                score_swap = Student[j].score; 
                point_swap = j;
            }
        }
        //sort find min of value and search the rest
        strcpy(name_swap, Student[i].name); strcpy(surname_swap, Student[i].surname);
        strcpy(Student[i].name, Student[point_swap].name); strcpy(Student[i].surname, Student[point_swap].surname);
        strcpy(Student[point_swap].name, name_swap); strcpy(Student[point_swap].surname, surname_swap);
        Student[point_swap].score = Student[i].score; Student[i].score = score_swap;
    }

    cout <<"   Data of all students \nMax score of students : "<< Maxstudent(n) << endl;
    cout <<"Min score of students : "<< Minstudent(n) << endl;
    cout <<"Average score of students : "<< AvrScore(n) << endl;
    cout <<"Mode score of students : "<< ModeScore(n) << endl;
    cout <<"Median score of students : "<< MedianScore(n) << endl;
    cout <<"S.D. score of students : "<< SDScore(n) << endl << endl;
    
    find_grade(n);
    sort(Student, Student + n, Sortname);//sort first alphabet in name

    cout << "   All students grade \n";
    for(int i = 0; i < n; i++)
    {
        printf("%-12s%-14s grade \'%c\'  (score %d)\n", Student[i].name, Student[i].surname, Student[i].grade, Student[i].score);
        //cout << Student[i].name << "\t" << Student[i].surname << "\tgrade \"" << Student[i].grade << "\"  (score " << Student[i].score << ")"<< endl;
    }
    cout << endl;
}

//Input
/*
10
Kokomi
Sangonomiya
89
Ayaka
Kamisato
80
Ayato
Kamisato
76
Lumeme
Ather
76
Itto
Arataki
70
Raiden
Shogun
75
Kazuha
Kaedehara
73
Sara
Kujou
76
Mona
-
84
Yoimiya
-
74
*/


//Output
/*
   Data of all students
Max score of students : 89
Min score of students : 70
Average score of students : 77.30
Mode score of students : 76
Median score of students : 76
S.D. score of students : 5.60

   All students grade
Ayato       Kamisato       grade 'D'  (score 76)
Ayaka       Kamisato       grade 'C'  (score 80)
Itto        Arataki        grade 'F'  (score 70)
Kazuha      Kaedehara      grade 'D'  (score 73)
Kokomi      Sangonomiya    grade 'A'  (score 89)
Lumeme      Ather          grade 'D'  (score 76)
Mona        -              grade 'B'  (score 84)
Raiden      Shogun         grade 'D'  (score 75)
Sara        Kujou          grade 'D'  (score 76)
Yoimiya     -              grade 'D'  (score 74)
*/