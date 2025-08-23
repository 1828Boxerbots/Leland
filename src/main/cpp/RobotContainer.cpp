// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();

  m_Drive.SetDefaultCommand(frc2::RunCommand( 
  [this] {
    m_Drive.ArcadeDrive(-m_driverController.GetLeftY(), -m_driverController.GetRightX());
  },
  {&m_Drive}));

}

void RobotContainer::ConfigureBindings() 
{
  // Configure your trigger bindings here
  
  // Run Intake
  // In
  (!m_driverController.LeftBumper()
    && m_driverController.B()).WhileTrue(m_Intake.RunIntake(IntakeConstants::kSpeed, DemoConstants::kIntakeSpeed));
  // Out
  (m_driverController.LeftBumper()
    && m_driverController.B()).WhileTrue(m_Intake.RunIntake(-IntakeConstants::kSpeed, -DemoConstants::kIntakeSpeed));
  
  // Run Load
  // In
  (!m_driverController.LeftBumper()
    && m_driverController.X()).WhileTrue(m_Load.RunLoad(-LoadConstants::kSpeed, -DemoConstants::kLoadSpeed));
  // Out
  (m_driverController.LeftBumper()
    && m_driverController.X()).WhileTrue(m_Load.RunLoad(LoadConstants::kSpeed, DemoConstants::kLoadSpeed));

  // Run Intake & Load
  // In
  (!m_driverController.LeftBumper()
    && m_driverController.Y()).WhileTrue(m_Intake.RunIntake(IntakeConstants::kSpeed, DemoConstants::kIntakeSpeed));
  (!m_driverController.LeftBumper()
    && m_driverController.Y()).WhileTrue(m_Load.RunLoad(-LoadConstants::kSpeed, -DemoConstants::kLoadSpeed));
  // Out
  (m_driverController.LeftBumper()
    && m_driverController.B()).WhileTrue(m_Intake.RunIntake(-IntakeConstants::kSpeed, -DemoConstants::kIntakeSpeed));
  (m_driverController.LeftBumper()
    && m_driverController.X()).WhileTrue(m_Load.RunLoad(LoadConstants::kSpeed, DemoConstants::kLoadSpeed));

  // Run Shooter
  // Out
  (!m_driverController.LeftBumper()
    && m_driverController.RightTrigger()).WhileTrue(m_Shooter.RunShooter(
      m_driverController.GetRightTriggerAxis() * ShooterConstants::kSpeed, DemoConstants::kShooterSpeed));
  // In
  (m_driverController.LeftBumper()
    && m_driverController.RightTrigger()).WhileTrue(m_Shooter.RunShooter(
      m_driverController.GetRightTriggerAxis() * -ShooterConstants::kSpeed, -DemoConstants::kShooterSpeed));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
