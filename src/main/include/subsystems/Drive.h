// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Constants.h"
#include "DemoMode.h"
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/StartEndCommand.h>
#include <frc2/command/RunCommand.h>
#include <frc/motorcontrol/Spark.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DigitalInput.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc/motorcontrol/PWMMotorController.h>
#include <cmath>
#include "units/velocity.h"

class Drive : public frc2::SubsystemBase {
 public:
  Drive();
  ~Drive();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void ArcadeDrive(double fwd, double rot);

  // @brief Will be used as a defualt command that moves the drivetrain
  //void RCDrive(double forwardPW, double turnPW, units::meters_per_second_t leftDriveSpeed, units::meters_per_second_t RightDriveSpeed);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  // private member variables
  frc::Spark m_LeftDriveMotor{DriveConstants::kLeftDriveMotorPort};
  frc::Spark m_RightDriveMotor{DriveConstants::kRightDriveMotorPort};

//   frc::DigitalInput m_LeftDriveEncoder1{DriveConstants::kLeftDrive1EncoderPort};
//   frc::DigitalInput m_LeftDriveEncoder2{DriveConstants::kLeftDrive2EncoderPort};
//   frc::DigitalInput m_RightDriveEncoder1{DriveConstants::kRightDrive1EncoderPort};
//   frc::DigitalInput m_RightDriveEncoder2{DriveConstants::kRightDrive2EncoderPort};

  double m_leftDriveSpeed = 0;
  double m_rightDriveSpeed = 0;

  frc::DifferentialDrive m_drive{[&](double output) { m_LeftDriveMotor.Set(output); },
                               [&](double output) { m_RightDriveMotor.Set(output); }};
};

