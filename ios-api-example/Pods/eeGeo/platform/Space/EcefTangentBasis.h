// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Space.h"
#include "Streaming.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Space
    {
        /*!
         * \brief Defines an orthogonal coordindate basis in ECEF space
         *
         *  EcefTangentBasis defines an orthogonal coordinate basis located
         *  at a point in ECEF (Earth-centred, Earth-fixed) space.
         *  The "up" direction is constrained to be perpendicular to the (earth-) sphere's
         *  surface - so are radial from the sphere centre. 
         *  The "right" and "forward" directions lie on a plane that is tangential
         *  to the earth-sphere surface.
         */
        class EcefTangentBasis
        {
        public:
            EcefTangentBasis();
            
            //! Construct from point and heading (forward) direction
            /*! \param pointEcef the origin of the coordinate basis, in ECEF coordinates
             *  \param heading direction. This is projected onto the sphere-tangent plane passing through
             *  pointEcef, to become the Forward direction
             */
            EcefTangentBasis(const dv3& pointEcef, const v3& heading);
            
            const dv3& GetPointEcef() const { return m_pointEcef; }
            const v3& GetRight() const { return m_basisRight; }
            const v3& GetUp() const { return m_basisUp; }
            const v3& GetForward() const { return m_basisForward; }

            //! Set from point and heading (forward) direction
            /*! \param pointEcef the origin of the coordinate basis, in ECEF coordinates
             *  \param heading direction. This is projected onto the sphere-tangent plane passing through
             *  pointEcef, to become the Forward direction
             */
            void Set(const dv3& pointEcef, const v3& heading);
            
            void SetPoint(const dv3& pointEcef)
            {
                Set(pointEcef, m_basisForward);
            }
            
            void SetHeading(const v3& heading)
            {
                Set(m_pointEcef, heading);
            }

            //! Returns the right, up, forward basis vectors of the basis as a 3x3 matrix.
            /* ! \param out. An output matrix to store the result
             */
            void GetBasisOrientationAsMatrix(m33& out) const;
            
            m44 GetEcefToTangentTransform() const;
            
            m44 GetTangentToEcefTransform() const;

            //! Creates an ecef tangent basis for a morton key.
            /*! \param key. The morton key for which the ecef tangent basis is to be constructed
             */
            static EcefTangentBasis CreateFromMortonKey(const Eegeo::Streaming::MortonKey& key);

        private:
            EcefTangentBasis(dv3 point, v3 right, v3 up, v3 forward);

            dv3 m_pointEcef;
            v3 m_basisRight;
            v3 m_basisUp;
            v3 m_basisForward;
        };
    }
}
