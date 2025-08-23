#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"
#include <frc/DigitalInput.h>

class DemoMode : public frc2::SubsystemBase {
 public:
    DemoMode();
    ~DemoMode();

    void Periodic() override;

    static bool GetDemoMode() { return s_DemoModeEnabled; }
    
 private:
    frc::DigitalInput m_DemoSwitch1 {DemoConstants::kDemo1Port};
    frc::DigitalInput m_DemoSwitch2 {DemoConstants::kDemo3Port};

    static bool s_DemoModeEnabled;
};