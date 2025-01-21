#ifndef PATIENT_CONTROLLER_H
#define PATIENT_CONTROLLER_H

#include "ui_common.h"

class PatientController {
private:
    UICommon uiCommon;

public:
    void Create();
    void Edit();
    void Display();
};

#endif