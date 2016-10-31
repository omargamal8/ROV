#include "joystt.h"
#include "SFML/Window.hpp"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include "myjoysticklibrary.h"
#define rotatingbut 1
#define drivingbut 2
#define manipulationbut 3

class JoysttData : public QSharedData
{
private:
typedef  void (Joystt::*FPTR) (int);

public:

 QVector<FPTR> pointer_to_func;
 //void (Joystt::*fptr) (int) = &Joystt::first;
//pointer_to_func.append(&Joystt::first);
};
Joystt::Joystt() : data(new JoysttData)
{


}

Joystt::Joystt(const Joystt &rhs) : data(rhs.data)
{

}

Joystt &Joystt::operator=(const Joystt &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Joystt::~Joystt()
{


}
bool Joystt::updateStatus(){
 sf::Joystick::update();
  if(sf::Joystick::isConnected(0)){
      return true;
  }

  else{
      return false;
  }
}

 QVector <int> Joystt::checkForButtons(){
     sf::Joystick::update();
    QVector <int> list;
     for(int i=0;i<sf::Joystick::Count;i++){
        if(sf::Joystick::isButtonPressed(0,i)){
            list.append(i);
            qDebug()<<"buttonpressed";


        }
    }
}
mode active_mode,previous_mode;

 void Joystt::UpdateModes(){
     if(active_mode==modes[rotating]&& MyJoystickLibrary::isButtonReleased(rotating)){
         active_mode=previous_mode;
     }
    else
    if(MyJoystickLibrary::isButtonPressed(rotatingbut) && active_mode!= modes[rotatingbut]){
     previous_mode=active_mode;
     active_mode=modes[rotatingbut-1];
    }
    else
    if(MyJoystickLibrary::isButtonPressed(drivingbut)&& active_mode!= modes[drivingbut]){
        previous_mode=active_mode;
        active_mode=modes[drivingbut];
    }
    else
    if(MyJoystickLibrary::isButtonPressed(manipulationbut)&& active_mode!= modes[manipulationbut]){
        previous_mode=active_mode;
        active_mode=modes[manipulationbut];
    }



 }

void Joystt::first(int i ){
qDebug()<<"Dakhal "+ i;

}

void Joystt::second(int i ){
qDebug()<<"Dakhal "+i;

}

