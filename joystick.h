#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include <SFML/Window.hpp>

class JoystickData;

class Joystick
{
public:
    bool updateStates();
    void checkForButtons();
    //=================== Variables =============

    QTimer Joy_timer ;
    int pos_x,pos_y,pos_z,pos_r;
    Mode active_mode,previous_mode;

    //=================== Arrays =================

    Mode modes [];
    Button buttons[];

    //=================== Functions ==============

    void UpdateStates ();
    void Move_z (int pos_z);
    void stabilize ();
    void scaling ();

    //============================================
    Joystick();
    Joystick(const Joystick &);
    Joystick &operator=(const Joystick &);
    ~Joystick();


private:
    QSharedDataPointer<JoystickData> data;

};

#endif // JOYSTICK_H
