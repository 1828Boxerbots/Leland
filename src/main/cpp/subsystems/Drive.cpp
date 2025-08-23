// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drive.h"

Drive::Drive() // Constructor
{
    // Put all of the initialization things here

    // Inverting the selected motors
    m_LeftDriveMotor.SetInverted(false);
    m_RightDriveMotor.SetInverted(true);

}
Drive::~Drive() {} // Deconstructor

// This method will be called once per scheduler run
void Drive::Periodic() {
  frc::SmartDashboard::PutNumber("LeftDriveMotor Power", m_LeftDriveMotor.Get());
  frc::SmartDashboard::PutNumber("RightDriveMotor Power", m_RightDriveMotor.Get());
}

void Drive::ArcadeDrive(double fwd, double rot) {
  if(DemoMode::GetDemoMode())
  {
    m_drive.ArcadeDrive((fwd * DemoConstants::kDriveSpeed), (rot * DemoConstants::kDriveSpeed));
  }
  else
  {
    m_drive.ArcadeDrive(fwd, rot);
  }
}
/*
  if(DemoMode::GetDemoMode)
  {

  }
  else
  {

  }
*/