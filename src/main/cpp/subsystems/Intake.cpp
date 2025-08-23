#include "subsystems/Intake.h"

Intake::Intake() //Constructor
{
    //Put init stuff her
}

Intake::~Intake() {} //Deconstructor

// This method will be called once per scheduler run
void Intake::Periodic() {
    frc::SmartDashboard::PutNumber("Intake Motor Power", m_IntakeMotor.Get());
}

frc2::CommandPtr Intake::RunIntake(float speed, float demoSpeed)
{
    return StartEnd
    (
        // execute
        [this, speed, demoSpeed]
        {
            if(DemoMode::GetDemoMode)
            {
                m_IntakeMotor.Set(demoSpeed);
            }
            else
            {
                m_IntakeMotor.Set(speed);
            }
        },
        // end
        [this]
        {
            m_IntakeMotor.Set(0);
        }
    );
}