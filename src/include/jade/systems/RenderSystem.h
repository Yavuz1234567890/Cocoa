#pragma once

#include "jade/renderer/Shader.h"
#include "jade/renderer/Camera.h"

#include <vector>
#include <entt/entt.h>

typedef unsigned int uint;

class RenderBatch;
class RenderSystem {
public:
    RenderSystem(Camera* camera) 
        : m_Camera(camera) {}

    void AddActor(entt::actor& actor);
    void Render();

    Camera& GetCamera() const { return *m_Camera; }

public:
    static const int MAX_BATCH_SIZE;

private:
    std::vector<RenderBatch*> m_Batches;
    Camera* m_Camera;
};

const int RenderSystem::MAX_BATCH_SIZE = 1000;


struct Vertex {
    union {
        float position[3];
        struct {
            float x;
            float y;
            float z;
        };
    };
    union {
        float color[4];
        struct {
            float r;
            float g;
            float b;
            float a;
        };
    };
};

class RenderBatch {
public:
    RenderBatch(RenderSystem* renderer);

    void Clear();
    void Start();
    void Add(entt::actor& spr);
    void Render();

    bool const HasRoom() {
        return m_NumSprites < RenderSystem::MAX_BATCH_SIZE;
    }
    int const NumSprites() {
        return m_NumSprites;
    }

private:
    void LoadVertexProperties(int index);
    void LoadEmptyVertexProperties(int index);
    
    void LoadElementIndices(int index);
    void GenerateIndices();

private:
    entt::actor* m_Actors[RenderSystem::MAX_BATCH_SIZE];
    Shader* m_Shader;
    RenderSystem* m_Renderer;
    
    float m_Vertices[RenderSystem::MAX_BATCH_SIZE * 4 * (sizeof(Vertex) / sizeof(float))];
    int m_Indices[RenderSystem::MAX_BATCH_SIZE * 6];

    uint m_VAO, m_VBO, m_EBO;
    int m_ZIndex = 0;
    int m_NumSprites = 0;
};