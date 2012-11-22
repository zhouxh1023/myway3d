#pragma once

#include "MWTerrain.h"
#include "MWTerrainLod.h"

namespace Myway {

class MW_ENTRY TerrainSection : public Mover
{
    DECLARE_ALLOC();

    friend class Terrain;

public:
    TerrainSection(Terrain * pTerrain, int x, int z);
    ~TerrainSection();

    virtual void AddRenderQueue(RenderQueue * rq);

    int GetLevel() const { return mLevel; }
    int GetSectionX() const { return mSectionX; }
    int GetSectionZ() const { return mSectionZ; }
	int GetLayer(int index) const { d_assert (index < Terrain::kMaxBlendLayers); return mLayer[index]; }
	float GetOffX() const { return mOffX; }
	float GetOffZ() const { return mOffZ; }

    void UpdateLod();
    void PreRender();

protected:
    void                    Init();

    void                    CalcuMorphBuffer();
    void                    _CalcuMorphBuffer(int level);
    void                    CalcuErrorMetrics();
    float                   _CalcuErrorMetric(int level);

    void                    CalcuLevelDistance();

protected:
    Terrain *               mTerrain;
    int                     mSectionX;
    int                     mSectionZ;
	float					mOffX, mOffZ;

	int						mLayer[Terrain::kMaxBlendLayers];

    int                     mLevel;
    float                   mErrorMetric[Terrain::kMaxDetailLevel];
    float                   mLevelDistSq[Terrain::kMaxDetailLevel];
    VertexBufferPtr         mMorphBuffer[Terrain::kMaxDetailLevel];
    TerrainLod::_Key        mkKey;
    float                   mMorph;

    RenderDesc              mRender;
};

}