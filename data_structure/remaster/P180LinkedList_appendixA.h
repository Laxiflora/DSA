struct NetStruct{
    friend class Student;
    private:
        int grade;
    public:
        int Net_GetGrade(){return this->grade;}
        NetStruct(){this->grade = 2;}
        NetStruct(int g){this->grade = g;}
};

struct Student{
    private:
        int id;
        char sex;
        NetStruct* gradeing;
    public:
        int GetID(){return id;}
        char GetSex(){return sex;}
        int GetGrade(){return gradeing->Net_GetGrade();}
        Student(){
            id = 10;
            sex='M';
            gradeing = new NetStruct();
            }
        Student(int id,char sex,int grade){
            this->id = id;
            this->sex=sex;
            gradeing = new NetStruct(grade);
            }
        ~Student(){delete gradeing;}
};

ostream& operator<<(ostream& os, Student data){
    cout<<data.GetID()<<endl<<data.GetSex()<<endl<<data.GetGrade()<<endl<<endl;
    return os;
}
