// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Models.h"
#include "ModelMesh.h"
#include "Lighting.h"
#include "Rendering.h"
#include "ITextureFileLoader.h"
#include "IFileIO.h"
#include "AsyncTexturing.h"
#include "IAsyncTextureObserver.h"

#include <vector>
#include <string>

namespace Eegeo
{
    namespace IO
    {
        namespace POD
        {
            class PODTexture;
            class PODScene;
        }
    }
    
	class Blitter;
	class FrustumRadar;
    class Node;
    class SceneAnimator;

	enum
	{
		kModelLoadFlagNone		= 0x00000000,   
		kModelLoadFlagPreLit	= 0x00000001,
		
		kModelLoadFlagDefault	= kModelLoadFlagNone
	};

	class Model : protected Eegeo::NonCopyable, public Rendering::AsyncTexturing::IAsyncTextureObserver
    {
		std::vector <ModelMesh*> 		m_pMeshList;
		std::vector <Node*> 			m_pNodeList;
        
        typedef std::vector<Eegeo::Rendering::AsyncTexturing::IAsyncTexture*> TTextures;
        TTextures m_textures;
        
        typedef std::vector <ModelMaterial*> TMaterialPtrVec;
        TMaterialPtrVec m_pMaterialList;
		
		Node* 					m_pRootNode;
		SceneAnimator* 			m_pAnimator;
        
        int m_numOfTexturesComplete;
		
		void AssignObjects();
        
        void UpdateMaterialTextures();
        
        static std::string GetTextureName(const IO::POD::PODTexture* podTexture);
        
        static void InitFromPODScene(Model& model, const IO::POD::PODScene& podScene, Eegeo::Rendering::AsyncTexturing::IAsyncTextureRequestor* pTextureRequestor, const std::string& texturePath, u32 modelLoadFlags, HeightCB createHeightData = NULL);

	public:

		Model();
		~Model						();
				
		void 		Update 			(void);
        void        UpdateAnimator  (float dt);
        
		void 		Draw 			(Eegeo::Rendering::GLState& glState, Eegeo::Lighting::GlobalFogging& fogging, Eegeo::FrustumRadar* pFrustum = NULL, const bool drawSolid=true, const bool drawAlpha=true);

		Node*   	GetRootNode 	();
		
		u32  		GetNumNodes		();
		Node*   	GetNode 		(u32 nodeIndex);
		Node*   	FindNode 		(const char* nodeName);
		Node*   	FindNode 		(u32 hash);
		
		ModelMaterial* 	GetMaterial 	(u32 materialIndex);
        bool        TryGetMaterialByName(const std::string& materialName, ModelMaterial*& out_pFoundMaterial) const;
		u32 		GetNumMaterials	();
        u32         GetNumTextures () const;
		
		void 		DrawSkeleton 	(Eegeo::Blitter* pBlitter, u32 colour);
        
        void OnTextureLoadSuccess(const Rendering::AsyncTexturing::IAsyncTexture& loadedTexture);
        void OnTextureLoadFail(const Rendering::AsyncTexturing::IAsyncTexture& loadedTexture);
        
        static Model* CreateFromPODScene(const IO::POD::PODScene& podScene, Eegeo::Rendering::AsyncTexturing::IAsyncTextureRequestor* pTextureRequestor, const std::string& texturePath);

        static Model* CreateFromPODStream(std::istream& stream, size_t size,
                                      Eegeo::Rendering::AsyncTexturing::IAsyncTextureRequestor* pTextureRequestor, const std::string& texturePath);
        
        static Model* CreateFromBuffer(const std::vector<Byte>& buffer,
                                       Eegeo::Rendering::AsyncTexturing::IAsyncTextureRequestor* pTextureRequestor, const std::string& texturePath);
        
        static Model* CreateFromPODFile(const char* filename, Helpers::IFileIO& fileIO, Eegeo::Rendering::AsyncTexturing::IAsyncTextureRequestor* pTextureRequestor, const std::string& texturePath);
	};
}
