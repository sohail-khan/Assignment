// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Streaming.h"
#include "IResourceStream.h"

namespace Eegeo
{
    namespace Streaming
    {
        class LoggingResourceStream : public IResourceStream
        {
        private:
            int totalRequests;
            int totalFailedRequests;
            int totalSuccessRequests;
            int totalRawResourceBytesSuccessRequests;
            
            int totalSuccessRequestFromWeb;
            int totalSuccessRequestFromCache;
            int totalRawResourceBytesSuccessRequestsFromWeb;
            int totalRawResourceBytesSuccessRequestsFromCache;
            int totalSuccessPreDecompressWebBytesRead;
            
            float totalFailRequestFromWebTimeMilliseconds;
            float totalSuccessRequestFromWebTimeMilliseconds;
            float totalSuccessRequestFromCacheTimeMilliseconds;
            
        public:
            LoggingResourceStream();
        
            int TotalNumRequests() const;
            int TotalFailedRequests() const;
            int TotalSuccessRequests() const;
            int TotalSuccessRequestsFromWeb() const;
            int TotalSuccessRequestsFromCache() const;
            int TotalBytesSuccessRequests() const;
            int TotalBytesSuccessRequestsFromWeb() const;
            int TotalBytesSuccessRequestsFromCache() const;
            int TotalSuccessPreDecompressWebBytesRead() const;
            
            int AvgBytesPerSuccessRequests() const;
            
            float AvgTimeSuccessCacheLoadMs() const;
            float AvgTimeSuccessWebLoadMs() const;
            float AvgTimeFailWebLoadMs() const;
            
            void ResetCounters();
            
            void LogFailedRequest(const MortonKey& key, float totalTimeTakenMilliseconds);
            
            void LogSuccessfulRequest(const MortonKey& key,
                                      size_t rawResourceSize,
                                      bool loadedFromCache,
                                      float totalTimeTakenMilliseconds,
                                      size_t preDecompressBytesRead);
        };
    }
}
