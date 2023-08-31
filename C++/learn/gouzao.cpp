#include<iostream>
using namespace std;

class Line{
    public:
        void setLength(double len);
        double getLength(void);
        Line(double len);//构造函数

    private:
        double length;

};
//成员函数定义，包括构造函数   类的内部直接定义该函数，外部用类名::定义。
Line::Line(double len){
    cout<<"object is being created,length="<<len<<endl;
    
}
void Line::setLength(double len){
    length=len;
}
double Line::getLength(void){
    return length;
}
int main(){
    Line line(10);
    cout<<"first length of line:"<<line.getLength()<<endl;

    line.setLength(6.0);
    cout<<"length of line:"<<line.getLength()<<endl;

    return 0;
}