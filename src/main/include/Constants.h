// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "units/velocity.h"

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace OperatorConstants {

inline constexpr int kDriverControllerPort = 0;

}  // namespace OperatorConstants

namespace DriveConstants
{
    // Ports
    inline constexpr int kLeftDriveMotorPort = 1;
    inline constexpr int kRightDriveMotorPort = 0;

    // Math
    inline constexpr int kDriveMotorRPM = 5310;
    inline constexpr float kDriveMotorGearRatio = 12.75;
    inline constexpr float kDtiveWheelDiameterMeter = 0.1524;
    inline constexpr units::meters_per_second_t kMaxDriveMPS = 3.323_mps;
    inline constexpr double kMaxDriveMPSDouble = 3.323;
}

namespace IntakeConstants
{
    // Ports
    inline constexpr int kIntakeMotorPort = 3;

    // Other Konstants
    inline constexpr float kSpeed = 0.9;
}

namespace LoadConstants
{
    // Ports
    inline constexpr int kLoadMotorPort = 4; 

    // Other konstants
    inline constexpr float kSpeed = 0.6;
}

namespace ShooterConstants
{
    // Posts
    inline constexpr int kShooterMotorPort = 6;


    // Other konstants
    inline constexpr float kSpeed = 0.9;
}

namespace DemoConstants
{
    //Switch Ports
    inline constexpr int kDemo1Port = 8;
    inline constexpr int kDemo3Port = 7;

    // Du Speeds
    inline constexpr float kDriveSpeed = 0.75;
    inline constexpr float kIntakeSpeed = 0.7;
    inline constexpr float kLoadSpeed = 0.3;
    inline constexpr float kShooterSpeed = 0.3;
}
