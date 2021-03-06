#pragma once
#include "SubSystem.h"
#include "Cameras.h"
#include "ThrustersSubSystem.h"
#include "MetalChecker.h"

class OutputSubSystem :public SubSystem
{
public:
	OutputSubSystem()
	{
		int i = 0;
#ifdef MANIPULATOR_ENABLE
		devices[i++] = new ROVBuilderManipulator();
#endif
#ifdef THRUSTERSSUBSYSTEM_ENABLE
		devices[i++] = new ThrustersSubSystem();
#endif
#ifdef ROTARYCAMERA_ENABLE
		devices[i++] = new Cameras();
#endif
#ifdef METALCHECKER_ENABLE
		devices[i++] = new MetalChecker();
#endif

	}
	void apply(RovData& rov_data);
	Output* devices[SIZE_OUTPUT_DEVICES];
};


