// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Models.h"
#include "PODNode.h"
#include "BoundingBox.h"
#include "VectorMath.h"
#include "Rendering.h"
#include "Lighting.h"

#include <vector>

#define NODE_NAME_MAXSIZE     (100)

namespace Eegeo
{
	class FrustumRadar;

	class Node
	{
    private:
        
        IO::POD::PODNode m_podNode;
		char            		m_szName [NODE_NAME_MAXSIZE];
		u32						m_nameHash;
		
		Node*           		m_pParentNode;
		s32           			m_parentNodeID;
	   
		std::vector <Node*> 	m_pChildNodes;
		
		std::vector <Node*>*	m_pNodeList;
		
		ModelMaterial*       		m_pMaterial;
		s32           			m_materialID;
		
		ModelMesh*         		m_pMesh;
		s32	           			m_meshID;
		
		Eegeo::m44        		m_localMatrix;
		Eegeo::m44        		m_worldMatrix;
		
		Eegeo::m44        		m_invPoseMatrix;
		
		Eegeo::BoundingBox    	m_box;
		Eegeo::v3         		m_worldMin;
		Eegeo::v3         		m_worldMax;
		Eegeo::BoundingBox    	m_boxSubtree;
		
		Eegeo::v3         		m_centre;
		Eegeo::v3         		m_centreSubtree;
		float           		m_radius;
		float           		m_radiusSubtree;

		bool            		m_visible;
		bool            		m_dirty;
		bool            		m_dirtyBB;
	 
		void 		SetSkinMatrices		();
        
        void CalculateShereSuperset(Eegeo::v3& centre,
                                    float& radius,
                                    const Eegeo::v3& centre0,
                                    float radius0,
                                    const Eegeo::v3& centre1,
                                    float radius1);
        
        void InitFromPODNode(const IO::POD::PODNode* podNode);
        
	public:
		
		Node();
		~Node();
        
        static Node* CreateFromPODNode(const IO::POD::PODNode* podNode);
        
		//void        ParseFile 			(std::fstream& stream, u32 fileOffset, u32 fileSize);
		void        AssignObjects 		(std::vector<Node*> &nodeList, std::vector<ModelMesh*> &meshList, std::vector<ModelMaterial*> &materialList);
								   
		void        Update 				();
		void        UpdateRecursive 	(bool dirtyParent = false);

		void        UpdateBB 			(bool dirtyBB);
		void        UpdateSphere 		();
		void        UpdateBBRecursive 	(bool dirtyParent = false);
		void		UpdateSphereRecursive(bool dirtyParent = false);
		
		void        Draw 				(Eegeo::Rendering::GLState& glState, Eegeo::Lighting::GlobalFogging& fogging, Eegeo::FrustumRadar* pFrustum = NULL, const bool drawSolid=true, const bool drawAlpha=true);
		void        DrawSphere 			(Eegeo::Rendering::GLState& glState, Eegeo::Lighting::GlobalFogging& fogging, Eegeo::FrustumRadar* pFrustum = NULL, const bool drawSolid=true, const bool drawAlpha=true);
		
		void        DrawRecursive 		(Eegeo::Rendering::GLState& glState, const Eegeo::Lighting::GlobalFogging& fogging, Eegeo::FrustumRadar* pFrustum, const bool drawSolid=true, const bool drawAlpha=true);
		void        DrawSphereRecursive	(Eegeo::Rendering::GLState& glState, Eegeo::Lighting::GlobalFogging& fogging, Eegeo::FrustumRadar* pFrustum, const bool drawSolid=true, const bool drawAlpha=true);
		
		void        AddChild 			(Node* pChildNode);

		void        SetParentNode 		(Node* pParentNode);
		Node*       GetParentNode 		();
		
		u32			GetNumChildNodes	()				{ return static_cast<u32>(m_pChildNodes.size()); }
		Node*		GetChildNode		( u32 index )	{ return m_pChildNodes[index]; }
        
		const Eegeo::IO::POD::PODNode& GetPodNode() { return m_podNode; }
        
		void        SetMaterial 		(ModelMaterial* pMaterial);
		ModelMaterial*   GetMaterial 		();
		
		void        SetMesh 			(ModelMesh* pMesh);
		ModelMesh*  GetMesh 			();
		
		const Eegeo::m44& GetLocalMatrix 		();
		void        	SetLocalMatrix 		(const Eegeo::m44& localMatrix);
		
		const Eegeo::m44& GetInvPoseMatrix 	() { return m_invPoseMatrix; }
		void        	SetInvPoseMatrix 	(const Eegeo::m44& invPoseMatrix) { m_invPoseMatrix = invPoseMatrix; }
		
		const Eegeo::m44& GetWorldMatrix 		();
		
		char*       GetName 			();
		u32			GetNameHash			()	{ return m_nameHash; }
		
		bool        IsVisible 			();
		void        SetVisible 			(bool boOnOff);
	
		void        GetCentre			(Eegeo::v3& centre) const { centre = m_centre; }
		float       GetRadius			() const { return m_radius; }

		void GetMinExtent (Eegeo::v3& extent) const { extent = m_worldMin; }
		void GetMaxExtent (Eegeo::v3& extent) const { extent = m_worldMax; }
		void GetExtents	(Eegeo::v3& min, Eegeo::v3& max) const { GetMinExtent(min); GetMaxExtent(max); }

		void        GetCentreSubtree	(Eegeo::v3& centre) const { centre = m_centreSubtree; }
		float       GetRadiusSubtree	() const { return m_radiusSubtree; }
		
		static u32  TestSphere 			(Eegeo::FrustumRadar* pFrustum, const Eegeo::v3& centre, float radius);

	};
}
