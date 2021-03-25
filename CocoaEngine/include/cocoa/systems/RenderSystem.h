#pragma once
#include "externalLibs.h"
#include "cocoa/core/Core.h"

#include "cocoa/renderer/Shader.h"
#include "cocoa/components/SpriteRenderer.h"
#include "cocoa/components/FontRenderer.h"
#include "cocoa/components/Transform.h"
#include "cocoa/renderer/RenderBatch.h"
#include "cocoa/util/Settings.h"
#include "cocoa/renderer/Framebuffer.h"
#include "cocoa/scenes/SceneData.h"

namespace Cocoa
{
	namespace RenderSystem
	{
		COCOA void Init();
		COCOA void Destroy();

		COCOA void AddEntity(const TransformData& transform, const FontRenderer& fontRenderer);
		COCOA void AddEntity(const TransformData& transform, const SpriteRenderer& spr);
		COCOA void Render(const SceneData& scene);

		COCOA void Serialize(json& j, Entity entity, const SpriteRenderer& spriteRenderer);
		COCOA void DeserializeSpriteRenderer(json& json, Entity entity);
		COCOA void Serialize(json& j, Entity entity, const FontRenderer& fontRenderer);
		COCOA void DeserializeFontRenderer(json& json, Entity entity);
	};
}