// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IWorldState.h"

namespace Eegeo
{
    namespace WorldStates
    {
        class BaseState : public IWorldState
        {
        public:
            BaseState(std::string stateName);
            virtual ~BaseState() { }
            
            virtual std::string GetStateName() const;
            
            virtual float GetProgress() const { return m_progress; }
        protected:
            void SetProgress(float progress) { m_progress = progress; }
            
        private:
            std::string m_stateName;
            float m_progress;
        };
    }
}