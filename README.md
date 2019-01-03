# toggle
C++ toggle class that can switch between functions

This small class is useful for toggling between actions only on the initial button press

```cpp
//example using FRC robotics

#include <XboxController.h>
#include <DoubleSolenoid.h>
#include "toggle.cpp"

//this would be in a class, but this is just an example

void move_arm(bool open) {
	if (open) { actuator.Set(frc::DoubleSolenoid::Value::kForward); }
	else { actuator.Set(frc::DoubleSolenoid::Value::kReverse); }
}

frc::XboxController left_controller { 0 };
frc::DoubleSolenoid actuator { 2, 3 };

toggle2<bool>* arm=new toggle2<bool>(
	move_arm, //run the command
	move_arm,
	std::vector<bool>{true,false} //but invert the params
);
```

After setting up all of the variables, you can call this in a loop using:

```cpp
arm->toggleIf(left_controller.GetAButton())
```