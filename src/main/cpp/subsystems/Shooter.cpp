// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Shooter.h"

Shooter::Shooter()// Constructor
{
    // Put init stuff here
}

Shooter::~Shooter() {} // Deconstructor

// This method will be called once per scheduler run
void Shooter::Periodic() {
    frc::SmartDashboard::PutNumber("ShooterMotor Power", m_ShooterMotor.Get());

    // frc::SmartDashboard::PutNumber("ShooterMotor1 Encoder", m_ShooterEncoder1.Get());
    // frc::SmartDashboard::PutNumber("ShooterMotor2 Encoder", m_ShooterEncoder2.Get());
}

frc2::CommandPtr Shooter::RunShooter(float speed, float demoSpeed)
{
    return StartEnd
    (
        // execute
        [this, speed, demoSpeed]
        {
            if(DemoMode::GetDemoMode)
            {
                m_ShooterMotor.Set(demoSpeed);
            }
            else
            {
                m_ShooterMotor.Set(speed);
            }
        },
        // end
        [this]
        {
            m_ShooterMotor.Set(0);
        }
    );
}

