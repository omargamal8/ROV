#include "myjoysticklibrary.h"
#include "SFML/Window.hpp"
#include "map"
int joystick_no, button_no;
vector <bool> buttonstate (button_no);

MyJoystickLibrary::MyJoystickLibrary(){
int joystick_no=joystick_no;
button_no=12;
for(int i =0;i<button_no;i++){
buttonstate[i]=false;
}
}
MyJoystickLibrary::MyJoystickLibrary(int no){
int joystick_no=no;
}

void update(){
sf::Joystick::update();
}

int MyJoystickLibrary::Get_x(){

   return sf::Joystick::getAxisPosition(joystick_no,sf::Joystick::X);
}

int MyJoystickLibrary::Get_y(){

   return sf::Joystick::getAxisPosition(joystick_no,sf::Joystick::Y);
}

int MyJoystickLibrary::Get_z(){

   return sf::Joystick::getAxisPosition(joystick_no,sf::Joystick::Z);
}

int MyJoystickLibrary::Get_r(){

   return sf::Joystick::getAxisPosition(joystick_no,sf::Joystick::R);
}

int MyJoystickLibrary::Get_povx(){

   return sf::Joystick::getAxisPosition(joystick_no,sf::Joystick::PovX);
}
int MyJoystickLibrary::Get_povy(){

   return sf::Joystick::getAxisPosition(joystick_no,sf::Joystick::PovY);
}

bool isButtonPressed(int i){
if(sf::Joystick::isButtonPressed(joystick_no,i))
{
    buttonstate[i]=true;
    return true;
}
    buttonstate[i]=false;
    return false;
}

bool isButtonReleased(int i){
if(sf::Joystick::isButtonPressed(joystick_no,i))
{
    return false;
}
else{
        if(buttonstate[i]==true){
            buttonstate[i]=false;
            return true;
        }
    }
return false;
}
