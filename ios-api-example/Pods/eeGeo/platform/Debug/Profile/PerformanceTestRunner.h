// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "VectorMath.h"
#include "CatmullRomSpline.h"
#include "ICallback.h"
#include "Types.h"
#include "DebugDecl.h"
#include "CallbackCollection.h"
#include "CameraSplinePlaybackController.h"
#include "IDebugStats.h"
#include <vector>
#include <map>
#include <string>
#include <utility>

namespace Eegeo
{
    namespace Debug
    {
        namespace Profile
        {
            namespace PerformanceTestState
            {
                enum Values
                {
                    Started,
                    Ended
                };
            }

            struct SplineData
            {
                std::vector<Eegeo::dv3> cameraPositionsEcef;
                std::vector<Eegeo::dv3> targetPositionsEcef;
                Geometry::TimeParameterizationMethod::Values interpolationMethod;
                float playbackSpeed;

                void AddPoint(const Eegeo::dv3& cameraPositionEcef, const Eegeo::dv3& targetPositionEcef)
                {
                    cameraPositionsEcef.push_back(cameraPositionEcef);
                    targetPositionsEcef.push_back(targetPositionEcef);
                }
            };

            struct PerformanceTestReport
            {
                std::string ToString() const;

                float AverageFramesPerSecond;
                float MaxFrameTimeMS;
                size_t MemoryUsedBytes;

                typedef std::pair<std::string, StreamStat> TNamedStreamStat;

                std::vector<TNamedStreamStat > StreamNameToStatPairs;
            };

            class PerformanceTestRunner
            {
                struct TestState
                {
                    TestState();
                    void Stop();
                    void Start(const std::string& splineName, const int loopCount);
                    void SingleSplineCompleted();
                    bool IsTestCompleted() const;

                    bool IsActive() const { return m_isActive; }
                    const std::string& SplineName() const { return m_splineName; }

                private:
                    bool m_isActive;
                    int m_splineRunsCompleted;
                    std::string m_splineName;
                    int m_loopCount;
                };

            public:
                typedef std::map<std::string, SplineData> TNameSplineData;

                PerformanceTestRunner(
                        SplinePlayback::DebugCameraSplinePlaybackService& splinePlaybackService,
                        Debug::IDebugStats& debugStats);
                ~PerformanceTestRunner();

                bool IsTestInProgress() const { return m_state.IsActive(); }
                void RegisterCameraSpline(const std::string& name, const SplineData& data);

                void RegisterPerformanceTestCompletedCallback(Helpers::ICallback1<const PerformanceTestReport&>& callback);
                void UnregisterPerformanceTestCompletedCallback(Helpers::ICallback1<const PerformanceTestReport&>& callback);

                void RegisterPerformanceTestStateChangedCallback(Helpers::ICallback1<const PerformanceTestState::Values&>& callback);
                void UnregisterPerformanceTestStateChangedCallback(Helpers::ICallback1<const PerformanceTestState::Values&>& callback);

                bool TryBeginSplineCameraPathPerformanceTest(const std::string& splineName, const int loopCount);

            private:
                void HandlePlaybackStateChanged(const Camera::SplinePlayback::SplinePlaybackState& state);

                std::map<std::string, SplineData> m_nameToSplineData;
                SplinePlayback::DebugCameraSplinePlaybackService& m_debugSplinePlaybackService;
                Helpers::TCallback1<PerformanceTestRunner, const Camera::SplinePlayback::SplinePlaybackState&> m_splinePlaybackStateChangedCallback;
                Helpers::CallbackCollection1<const PerformanceTestState::Values&> m_performanceTestStatedChangedCallbacks;
                Helpers::CallbackCollection1<const PerformanceTestReport&> m_performanceTestCompletedCallbacks;
                Debug::IDebugStats& m_debugStats;

                TestState m_state;
            };
        }
    }
}


