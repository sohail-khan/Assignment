// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Routes.h"
#include "Types.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                struct Candidate
                {
                public:
                    Candidate()
                    : m_candidateSet(NULL)
                    , m_roadFittingInfo(NULL)
                    , m_cost(0.f)
                    , m_splineParamAtClosestPoint(0.f)
                    , m_directionFromTo(false)
                    {
                        
                    }
                    
                    Candidate(const CandidateSet* candidateSet,
                              const NavGraphRoadFittingInfo* roadFittingInfo,
                              float cost,
                              float splineParamAtClosestPoint,
                              bool directionFromTo)
                    : m_candidateSet(candidateSet)
                    , m_roadFittingInfo(roadFittingInfo)
                    , m_cost(cost)
                    , m_splineParamAtClosestPoint(splineParamAtClosestPoint)
                    , m_directionFromTo(directionFromTo)
                    {
                        
                    }
                    
                    void FixupCandidateSet(const CandidateSet* candidateSet)
                    {
                        Eegeo_ASSERT(m_candidateSet == NULL);
                        m_candidateSet = candidateSet;
                    }
                    
                    const CandidateSet* GetCandidateSet() const { return m_candidateSet; }
                    const NavGraphRoadFittingInfo* GetRoadFittingInfo() const { return m_roadFittingInfo; }
                    float GetCost() const { return m_cost; }
                    float GetSplineParamAtClosestPoint() const { return m_splineParamAtClosestPoint; }
                    bool GetDirectionFromTo() const { return m_directionFromTo; }
                    
                    static inline bool OrderByCostPtr(const Candidate* a, const Candidate* b)
                    {
                        return a->m_cost < b->m_cost;
                    }
                    
                private:
                    const CandidateSet* m_candidateSet;
                    const NavGraphRoadFittingInfo* m_roadFittingInfo;
                    float m_cost;
                    float m_splineParamAtClosestPoint;
                    bool m_directionFromTo;
                };
            }
        }
    }
}
