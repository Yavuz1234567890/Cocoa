#include "scenes/Scene.h"

namespace Jade {
    void Scene::AddSystem(System* system) { 
        m_Systems[m_SystemCount++] = system;
    }
    
    void Scene::SetActiveEntity(entt::entity entity) { 
        m_ActiveEntity = entity; 
    }

    const glm::vec2& Scene::GetGameviewPos() const { 
        return m_ImGuiLayer.GetGameviewPos(); 
    }

    const glm::vec2& Scene::GetGameviewSize() const { 
        return m_ImGuiLayer.GetGameviewSize(); 
    }

    entt::registry& Scene::GetRegistry() { 
        return m_Registry; 
    }

    Camera* Scene::GetCamera() const { 
        return m_Camera;
    }

    entt::entity Scene::GetActiveEntity() const { 
        return m_ActiveEntity; 
    }
}