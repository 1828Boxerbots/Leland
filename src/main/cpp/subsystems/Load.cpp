// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Load.h"

Load::Load() //Constructor
{
    //Put init stuff her
}

Load::~Load() {} //Deconstructor

// This method will be called once per scheduler run
void Load::Periodic() {
    frc::SmartDashboard::PutNumber("Load Motor Power", m_LoadMotor.Get());
}

// frc2::CommandPtr Load::RunAllLoad(float speed, float demoSpeed)
// {
//     return StartEnd
//     (
//         // execute
//         [this, speed, demoSpeed]
//         {
//             if(DemoMode::GetDemoMode)
//             {
//                 m_FrontLoadMotor.Set(demoSpeed);
//                 m_MidLoadMotor.Set(-demoSpeed);
//             }
//             else
//             {
//                 m_FrontLoadMotor.Set(speed);
//                 m_MidLoadMotor.Set(-speed);
//             }
//         },
//         // end
//         [this]
//         {
//             m_FrontLoadMotor.Set(0);
//             m_MidLoadMotor.Set(0);
//         }
//     );
// }

frc2::CommandPtr Load::RunLoad(float speed, float demoSpeed)
{
    return StartEnd
    (
        // execute
        [this, speed, demoSpeed]
        {
            if(DemoMode::GetDemoMode)
            {
                m_LoadMotor.Set(demoSpeed);
            }
            else
            {
                m_LoadMotor.Set(speed);
            }
        },
        // end
        [this]
        {
            m_LoadMotor.Set(0);
        }
    );
}
