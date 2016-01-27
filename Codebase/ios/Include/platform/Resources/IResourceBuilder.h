// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Streaming.h"
#include "Resources.h"
#include <vector>

namespace Eegeo 
{
    namespace Resources
    {
        typedef std::vector<IBuiltResource*> TBuiltResources;
        
        namespace BuilderTransitionOutput
        {
            enum BuilderTransitionOutputType
            {
                ERROR=0,
                CANCELLED,
                COMPLETE
            };
        }
        
        struct BuilderTransition
        {
            BuilderTransitionOutput::BuilderTransitionOutputType type;
            TBuiltResources output;
            
            static BuilderTransition Success(TBuiltResources output)
            {        
                BuilderTransition result;
                result.output = output;
                result.type = BuilderTransitionOutput::COMPLETE;
                return result;
            }
            
            static BuilderTransition Error()
            {        
                BuilderTransition result;
                result.type = BuilderTransitionOutput::ERROR;
                return result;
            }
            
            static BuilderTransition Cancelled()
            {
                BuilderTransition result;
                result.type = BuilderTransitionOutput::CANCELLED;
                return result;
            }
        };
        
        class IResourceBuilder
        {
        private:
        	long long currentClockStart;
            long long millisBuilding;
            int builds;
            
        public:
            IResourceBuilder()
            {
            	millisBuilding = 0;
            	builds = 0;
            }

            virtual ~IResourceBuilder() { }
            void StartClock();
            void EndClock();
            void ResetCounters();
            int NumBuilds();
            double AvgTimeTakenMs();
            
            virtual bool Flush(const Streaming::MortonKey& key, void* input, TBuiltResources& result)=0;
            virtual void DestroyBuiltResource(const Streaming::MortonKey& key, void* input)=0;
            
            virtual void* BuildResource(const Streaming::MortonKey& key, const Byte* data, size_t length)=0;
            
            virtual bool AcceptsErroredRequests() = 0;
        };
    }
}
