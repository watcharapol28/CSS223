#include<bits/stdc++.h>
using namespace std;

int MaxScore = 100; //Max score of student

struct student //info of all student
{
    char name[20], surname[20], grade;
    int score;
    bool operator < (const student &b) const
    {
        return score < b.score; // sort data min to max
    }
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
        maxscore = max(maxscore, Student[i].score);
    }
    return maxscore;
}

int Minstudent(int n)//function for find min score of all student
{
    int minscore = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        minscore = min(minscore, Student[i].score);
    }
    return minscore;
}

int AvrScore(int n)//function for find Average score of all student
{
    float Avr;
    for(int i = 0; i < n; i++)
    {
        Avr += Student[i].score;
    }
    Avr /= n;
    return Avr;
}

int ModeScore(int n)//function for find mode score of all student
{
    int check[MaxScore + 1] = {}, nMode = 0, ScoreMode;
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
    return Student[pn].score;
}

int SDScore(int n)//function for find S.D. score of all student
{
    float Avr = AvrScore(n), sum;
    for(int i = 0; i < n; i++)
    {
        sum += pow(Student[i].score - Avr, 2);
    }
    float SD = sqrt(sum / n);
    return SD;
}

void find_grade(int n)
{
    float avr = AvrScore(n), sd = SDScore(n);
    for(int i = 0; i < n; i++)
    {
        if(Student[i].score > avr + 2*sd) Student[i].grade = 'A';
        else if(Student[i].score > avr + sd) Student[i].grade = 'B';
        else if(Student[i].score > avr) Student[i].grade = 'C';
        else if(Student[i].score > avr - sd) Student[i].grade = 'D';
        else Student[i].grade = 'F';
    }
}

int main()
{
    int n;
    cout << "How many your students? : ";
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
    sort(Student, Student + n);
    cout <<"   Data of all students \nMax score of students : "<< Maxstudent(n) << endl;
    cout <<"Min score of students : "<< Minstudent(n) << endl;
    cout <<"Average score of students : "<< AvrScore(n) << endl;
    cout <<"Mode score of students : "<< ModeScore(n) << endl;
    cout <<"Median score of students : "<< MedianScore(n) << endl;
    cout <<"S.D. score of students : "<< SDScore(n) << endl << endl;
    
    find_grade(n);
    sort(Student, Student + n, Sortname);//sort first alphabet in name

    cout << "   all students grade \n";
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
100
Ayaka
Kamisato
82
Ayato
Kamisato
79
Lumeme
Ather
80
Itto
Arataki
53
Raiden
Shogun
69
Kazuha
Kaedehara
64
Sara
Kujou
71
Mona
-
71
Yoimiya
-
68
*/


//Output
/*
   Data of all students
Max score of students : 100
Min score of students : 53
Average score of students : 73
Mode score of students : 71
Median score of students : 79
S.D. score of students : 11

   all students grade
Ayato       Kamisato       grade 'C'  (score 79)
Ayaka       Kamisato       grade 'C'  (score 82)
Itto        Arataki        grade 'F'  (score 53)
Kazuha      Kaedehara      grade 'D'  (score 64)
Kokomi      Sangonomiya    grade 'A'  (score 100)
Lumeme      Ather          grade 'C'  (score 80)
Mona        -              grade 'D'  (score 71)
Raiden      Shogun         grade 'D'  (score 69)
Sara        Kujou          grade 'D'  (score 71)
Yoimiya     -              grade 'D'  (score 68)
*/