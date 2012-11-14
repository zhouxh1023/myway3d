#pragma once

#include "xObj.h"
#include "xApp.h"

namespace xInfi {

    class xMesh : public xObj
    {
        DECLARE_PROPERTY(xObj);

    public:
        char Name[128];
		char MeshFile[128];
		Vec3 Position;
		Vec3 Orientation;
		Vec3 Scale;

    public:
        xMesh(const char * name);
        virtual ~xMesh();

        virtual bool SetPosition(float x, float y, float z);
        virtual bool SetOrientation(float x, float y, float z);
        virtual bool SetScale(float x, float y, float z);
		virtual Aabb GetBound();

        virtual const char * GetName() { return Name; }
        virtual const char * GetTypeName() { return "Mesh"; }

        virtual bool OnPropertyChanged(const Property * p);

    protected:
        void _setName(const TString128 & name);
        void _setMeshFile(const TString128 & meshFile);
        void _setPosition(const Vec3 & position);
        void _setOrientation(const Vec3 & ort);
        void _setScale(const Vec3 & scale);

    protected:
        SceneNode * mNode;
        Entity * mEntity;
    };

    class xMeshFactory : public xObjFactory
    {
    public:
        xMeshFactory() {};
        virtual ~xMeshFactory() {};

        virtual xMesh * Create(const char * name) { return new xMesh(name); }
		virtual const char * GetGroupName() { return "Entity"; }
		virtual const char * GetTypeName() { return "Mesh"; }
    };

    class xMeshFactoryListener : public EventListener
    {
    public:
        xMeshFactoryListener()
        {
            xApp::OnInit += this;
        }

        virtual ~xMeshFactoryListener()
        {
            xApp::OnInit -= this;
        }

        virtual void OnCall(Event * sender, void * data)
        {
            if (sender == &xApp::OnInit)
            {
                xObjManager::Instance()->AddFactory(new xMeshFactory());
            }
        }

    };
}