#pragma once

#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include "DemoMode.h"
#include <frc2/command/StartEndCommand.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc/smartdashboard/SmartDashboard.h>

class Intake : public frc2::SubsystemBase {
 public:
  Intake();
  ~Intake();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  frc2::CommandPtr RunIntake(float speed, float demoSpeed);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  
  // member variables
  frc::VictorSP m_IntakeMotor{IntakeConstants::kIntakeMotorPort};
  
};