// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/VictorSP.h>
#include "Constants.h"
#include "DemoMode.h"
#include <frc2/command/StartEndCommand.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DigitalInput.h>

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();
  ~Shooter();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  frc2::CommandPtr RunShooter(float speed, float demoSpeed);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  // Private Member Variables
  frc::VictorSP m_ShooterMotor{ShooterConstants::kShooterMotorPort};

  // frc::DigitalInput m_ShooterEncoder1{ShooterConstants::kShooter1EncoderPort};
  // frc::DigitalInput m_ShooterEncoder2{ShooterConstants::kShooter2EncoderPort};
};
