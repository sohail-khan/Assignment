// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Rendering.h"
#include "Space.h"
#include "VectorMathDecl.h"
#include "EcefTangentBasis.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            namespace SceneModelTransformHelpers
            {
                /*! \brief Position and Orient a SceneModel on the Earth surface
                 *  \param inout_sceneModel The scene model to position
                 *  \param originPoint The lateral and vertical position of the model, as a WGS84 decimal degrees LatLongAltitude
                 *  \param absoluteHeadingDegrees The orientation of the model, as a bearing angle in degrees, clockwise from North
                 *  \return EcefTangentBasis representing the position of the model
                 */
                Space::EcefTangentBasis PositionOnEarthSurface(SceneModel& inout_sceneModel, const Space::LatLongAltitude& originPoint, float absoluteHeadingDegrees);
                
                /*! \brief Position and Orient a SceneModel on the Earth surface
                 *  \param inout_sceneModel The scene model to position
                 *  \param originEcef The lateral and vertical position as an ECEF position
                 *  \param absoluteHeadingDegrees The orientation of the model, as a bearing angle in degrees, clockwise from North
                 *  \return EcefTangentBasis representing the position of the model
                 */
                Space::EcefTangentBasis PositionOnEarthSurface(SceneModel& inout_sceneModel, const Eegeo::dv3& originEcef, float absoluteHeadingDegrees);
                
                /*! \brief Position and Orient a SceneModel on the Earth surface
                 *  \param inout_sceneModel The scene model to position
                 *  \param originPoint The lateral and vertical position of the model, as a WGS84 decimal degrees LatLongAltitude
                 *  \param absoluteHeadingDegrees The orientation of the model, as a bearing angle in degrees, clockwise from North
                 *  \param modelTransform The existing transform of the model
                 *  \return EcefTangentBasis representing the position of the model
                 */
                Space::EcefTangentBasis PositionOnEarthSurface(SceneModel& inout_sceneModel, const Space::LatLongAltitude& originPoint, float absoluteHeadingDegrees, const Eegeo::m44& modelTransform);
                
                /*! \brief Position and Orient a SceneModel on the Earth surface
                 *  \param inout_sceneModel The scene model to position
                 *  \param originEcef The lateral and vertical position as an ECEF position
                 *  \param absoluteHeadingDegrees The orientation of the model, as a bearing angle in degrees, clockwise from North
                 *  \param modelTransform The existing transform of the model
                 *  \return EcefTangentBasis representing the position of the model
                 */
                Space::EcefTangentBasis PositionOnEarthSurface(SceneModel& inout_sceneModel, const Eegeo::dv3& originEcef, float absoluteHeadingDegrees, const Eegeo::m44& modelTransform);
            }
        }
    }
}