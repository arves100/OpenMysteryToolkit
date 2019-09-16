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

	m_lpSprite->setPosition(200.0f, 200.0f);
}

void CMonster::AddAnimation(AnimationLayer layer, float speed, size_t length, int offsetX, int offsetY)
{
	// NOTE!!! Due to nCine not supporting loading multiple animations in one, this code will break if someone calls AddAnimation(1, ...)

	nctl::UniquePtr<ncine::RectAnimation> animation = nctl::makeUnique<ncine::RectAnimation>(1.0f / speed, ncine::RectAnimation::LoopMode::ENABLED, ncine::RectAnimation::RewindMode::FROM_START);
	
	for (size_t i = 0; i < length; i++)
		animation->addRect((i * m_v2Size.x) + offsetX, offsetY, m_v2Size.x, m_v2Size.y);

	m_lpSprite->addAnimation(nctl::move(animation));

	if (layer == AnimationLayer::IDLE)
	{
		m_lpSprite->setAnimation((int)AnimationLayer::IDLE);
		m_lpSprite->setFrame(0);
	}
}

void CMonster::Move(Directions dir)
{
	if (dir == Directions::DOWN)
	{
		m_lpSprite->move(0, -1);
	}
	else if (dir == Directions::UP)
	{
		m_lpSprite->move(0, 1);
	}
	else if (dir == Directions::LEFT)
	{
		m_lpSprite->move(-1, 0);
	}
	else if (dir == Directions::RIGHT)
	{
		m_lpSprite->move(1, 0);
	}
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
