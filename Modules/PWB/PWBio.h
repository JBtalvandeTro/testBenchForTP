/*!
 * \file     PWBio.h
 * \brief    declares the functions of the PWBio sub-module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef PWB_PWBIO_H_
#define PWB_PWBIO_H_

/* ---- Includes ---- */
#include "TYPedef.h"

/* ---- Defines ---- */
typedef enum {
    SwitchCdeS1 = 1,
    SwitchCdeS2,
    SwitchCdeS3
}PWB_CdeSwitchIdE;

typedef enum {
    AuxS2 = 1,
    AuxS3
}PWB_AuxSwitchIdE;

typedef struct
{
    boolean SwitchReadCmdResult;
} PWBio_CmdsResultsStr;

/* ---- Global variables ---- */
#ifndef PWBio_SUBMODULE
extern PWBio_CmdsResultsStr PWBio_cmdResults;
extern boolean PWBio_LowerDutyCycleS2;
extern boolean PWBio_LowerDutyCycleS3;
#else
PWBio_CmdsResultsStr PWBio_cmdResults;
boolean PWBio_LowerDutyCycleS2;
boolean PWBio_LowerDutyCycleS3;
#endif

/* ---- Global functions ---- */
void PWBio_Init(void);

void PWBio_SetCdeSwitch(PWB_CdeSwitchIdE switchId);
void PWBio_UnsetCdeSwitch(PWB_CdeSwitchIdE switchId);
boolean PWBio_ReadAuxSwitch(PWB_AuxSwitchIdE auxId);
void PWBio_RunTests(void);

void PWBio_Deinit(void);


#endif /* PWB_PWBIO_H_ */
