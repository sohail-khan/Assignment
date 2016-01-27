// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#ifndef __ExampleApp__RouteDrawingExample__
#define __ExampleApp__RouteDrawingExample__

#include <vector>
#include "GlobeCameraExampleBase.h"
#include "RouteService.h"
#include "Route.h"
#include "EegeoWorld.h"
#include "IdentityRouteThicknessPolicy.h"

namespace Examples
{
class RouteDrawingExample : public GlobeCameraExampleBase
{
private:
	Eegeo::Routes::RouteService& m_routeService;
	Eegeo::EegeoWorld& m_world;

	bool m_createdRoutes;
	std::vector<Eegeo::Routes::Route*> m_routes;
	Eegeo::Routes::Style::Thickness::IdentityRouteThicknessPolicy m_routeThicknessPolicy;
    

public:
	RouteDrawingExample(Eegeo::Routes::RouteService& routeService,
	                    Eegeo::EegeoWorld& eegeoWorld,
	                    Eegeo::Camera::GlobeCamera::GlobeCameraController* pCameraController,
                        Eegeo::Camera::GlobeCamera::GlobeCameraTouchController& cameraTouchController);

	static std::string GetName()
	{
		return "RouteDrawingExample";
	}
	std::string Name() const
	{
		return GetName();
	}

	void Start() {}
	void Update(float dt);
	void Draw() {}
	void Suspend();
    
    
};
}



#endif /* defined(__ExampleApp__RouteDrawingExample__) */
