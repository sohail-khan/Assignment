// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AppInterface.h"

namespace Eegeo
{
    class EegeoWorld;
    
    class IAppOnMap
    {
        EegeoWorld* m_pWorld;
    public:
        virtual ~IAppOnMap(){}
        
        EegeoWorld& World () const { return *m_pWorld; }
        void Start (EegeoWorld* pWorld) { m_pWorld = pWorld; OnStart(); };
        
        virtual void OnStart () = 0;
        
        virtual void Update 					(float dt)=0;
        virtual void Draw 						(float dt)=0;
    };
}
