// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include "DemoMode.h"
#include <frc2/command/StartEndCommand.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc/smartdashboard/SmartDashboard.h>

class Load : public frc2::SubsystemBase {
 public:
  Load();
  ~Load();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  frc2::CommandPtr RunLoad(float speed, float demoSpeed);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  
  // member variables
  frc::VictorSP m_LoadMotor{LoadConstants::kLoadMotorPort};
  
};
