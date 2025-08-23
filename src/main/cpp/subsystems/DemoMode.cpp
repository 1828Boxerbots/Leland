#include "subsystems/DemoMode.h"

#include <frc/smartdashboard/SmartDashboard.h>

bool DemoMode::s_DemoModeEnabled = true;

DemoMode::DemoMode() // Constructor
{

}
DemoMode::~DemoMode() {} // Deconstructor

void DemoMode::Periodic() {

    s_DemoModeEnabled = (!m_DemoSwitch1.Get() || !m_DemoSwitch2.Get());

    frc::SmartDashboard::PutBoolean("Demo Mode Enabled", s_DemoModeEnabled);
    frc::SmartDashboard::PutBoolean("Demo Switch Pos 1", !m_DemoSwitch1.Get());
    frc::SmartDashboard::PutBoolean("Demo Switch Pos 3", !m_DemoSwitch2.Get());
}