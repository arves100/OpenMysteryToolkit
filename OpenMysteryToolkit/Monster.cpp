#include "StdAfx.h"
#include "Monster.h"

CMonster::CMonster()
{

}

void CMonster::LoadSprite(ncine::SceneNode* scene, const char* name, unsigned int width, unsigned int height)
{
	m_lpTexture = nctl::makeUnique<ncine::Texture>((ncine::IFile::dataPath() + "test/monsters/" + name + "/sprites.png").data());
	m_lpSprite = nctl::makeUnique<ncine::AnimatedSprite>(scene, m_lpTexture.get());

	m_szName = name;
	m_v2Size = ncine::Vector2<int>(width, height);
}

void CMonster::AddIdleAnimation(float speed, size_t length)
{
	nctl::UniquePtr<ncine::RectAnimation> animation = nctl::makeUnique<ncine::RectAnimation>(speed, ncine::RectAnimation::LoopMode::ENABLED, ncine::RectAnimation::RewindMode::FROM_START);
	
	for (size_t i = 0; i < length; i++)
		animation->addRect(i * m_v2Size.x, 0, m_v2Size.x, m_v2Size.y);

	m_lpSprite->addAnimation(nctl::move(animation));
	m_lpSprite->setAnimation((int)AnimationLayer::IDLE);
	m_lpSprite->setFrame(0);
}

	/*nctl::UniquePtr<ncine::RectAnimation> animation = nctl::makeUnique<ncine::RectAnimation>(0.2f, ncine::RectAnimation::LoopMode::ENABLED, ncine::RectAnimation::RewindMode::FROM_START);

	animation->addRect(0, 0, width, height);
	animation->addRect(20, 0, 20, 20);

	m_lpSprite->addAnimation(nctl::move(animation));
	m_lpSprite->setAnimation((int)AnimationLayer::IDLE);
	m_lpSprite->setFrame(0);
	m_lpSprite->setPaused(true);*/

void CMonster::Update()
{
	m_lpSprite->setPaused(false);
}
