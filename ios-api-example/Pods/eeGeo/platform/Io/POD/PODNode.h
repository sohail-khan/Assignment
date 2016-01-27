// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMathDecl.h"
#include <vector>
#include <string>

namespace Eegeo
{
    namespace IO
    {
        namespace POD
        {
            const int POD_NODE_NUM_OF_POSITION_ELEMENTS = 3;
            const int POD_NODE_NUM_OF_ROTATION_ELEMENTS = 4;
            const int POD_NODE_NUM_OF_SCALE_ELEMENTS = 7;
            const int POD_NODE_NUM_OF_MATRIX_ELEMENTS = 16;
            
            class PODNode
            {
            public:
                PODNode();
                
                void SetMeshId(const s32 meshId);
                void SetName(const std::string &name);
                void SetMaterialId(const s32 materialId);
                void SetParentNodeId(const s32 parentNodeId);
                void SetLocalMatrix(const m44& localMatrix);

                void SetAnimPositions(float* pAnimPositions, u32 numOfPositions);
                void SetAnimPositionIndices(s32* pAnimPositionIndices, u32 numOfIndices);

                void SetAnimRotations(float* pAnimRotations, u32 numOfRotations);
                void SetAnimRotationIndices(s32* pAnimRotationIndices, u32 numOfIndices);
                
                void SetAnimScales(float* pAnimScales, u32 numOfScales);
                void SetAnimScaleIndices(s32* pAnimScaleIndices, u32 numOfIndices);

                void SetAnimMatrices(float* pAnimMatrices, u32 numOfMatrices);
                void SetAnimMatrixIndices(s32* pAnimMatrixIndices, u32 numOfIndices);
                
                s32 GetMaterialId() const;
                s32 GetParentNodeId() const;
                s32 GetMeshId() const;
                std::string GetName() const;
                
                u32 GetNumOfAnimPositions() const;
                u32 GetNumOfAnimPositionFrames() const;
                Eegeo::v3 GetAnimPosition(u32 positionIndex) const;
                u32 GetNumOfAnimPositionIndices() const;
                s32 GetAnimPositionIndex(u32 frameNumber) const;
                Eegeo::v3 GetAnimPositionForFrame(u32 frameNumber) const;

                u32 GetNumOfAnimRotations() const;
                u32 GetNumOfAnimRotationFrames() const;
                Eegeo::Quaternion GetAnimRotation(u32 rotationIndex) const;
                u32 GetNumOfAnimRotationIndices() const;
                s32 GetAnimRotationIndex(u32 frameNumber) const;
                Eegeo::Quaternion GetAnimRotationForFrame(u32 frameNumber) const;

                u32 GetNumOfAnimScales() const;
                u32 GetNumOfAnimScaleFrames() const;
                Eegeo::v3 GetAnimScale(u32 scaleIndex) const;
                Eegeo::v3 GetAnimAxisScale(u32 scaleIndex) const;
                float GetAnimStretchRotation(u32 scaleIndex) const;
                u32 GetNumOfAnimScaleIndices() const;
                s32 GetAnimScaleIndex(u32 frameNumber) const;
                Eegeo::v3 GetAnimScaleForFrame(u32 frameNumber) const;
                Eegeo::v3 GetAnimAxisScaleForFrame(u32 frameNumber) const;
                float GetAnimStretchRotationForFrame(u32 frameNumber) const;
                
                u32 GetNumOfAnimMatrices() const;
                u32 GetNumOfAnimMatrixFrames() const;
                Eegeo::m44 GetAnimMatrix(u32 matrixIndex) const;
                u32 GetNumOfAnimMatrixIndices() const;
                s32 GetAnimMatrixIndex(u32 frameNumber) const;
                Eegeo::m44 GetAnimMatrixForFrame(u32 frameNumber) const;
                
            private:
                
                s32 m_meshId;
                std::string m_name;
                s32 m_materialId;
                s32 m_parentNodeId;
                
                std::vector<float> m_animPositions;
                std::vector<s32> m_animPositionIndices;
                std::vector<float> m_animRotations;
                std::vector<s32> m_animRotationIndices;
                
                std::vector<float> m_animScales;
                std::vector<s32> m_animScaleIndices;
                std::vector<float> m_animMatrices;
                std::vector<s32> m_animMatrixIndices;

                
                u32 GetAnimScaleIndexForFrame(u32 frameNumber) const;
            };
        }
    }
}
