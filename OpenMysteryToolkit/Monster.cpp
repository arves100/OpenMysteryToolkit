#include "StdAfx.h"
#include "Monster.h"

CMonster::CMonster()
{
	m_bIsBuilt = false;

	ncine::RectAnimation defaultAnimation = ncine::RectAnimation(0.0f, ncine::RectAnimation::LoopMode::DISABLED, ncine::RectAnimation::RewindMode::FROM_START);
	defaultAnimation.addRect(0, 0, 0, 0);

	for (int i = 0; i < (int)AnimationLayer::MOVE_UP_RIGHT; i++)
	{
		m_mAnimations.insert_or_assign((AnimationLayer)i, defaultAnimation);
	}
}

void CMonster::LoadSprite(ncine::SceneNode* scene, const char* name, unsigned int width, unsigned int height)
{
	m_lpTexture = nctl::makeUnique<ncine::Texture>((ncine::IFile::dataPath() + "test/monsters/" + name + "/sprites.png").data());
	m_lpSprite = nctl::makeUnique<ncine::AnimatedSprite>(scene, m_lpTexture.get());

	m_szName = name;
	m_v2Size = ncine::Vector2<int>(width, height);
}

void CMonster::AddAnimation(AnimationLayer layer, float speed, size_t length, int offsetX, int offsetY)
{
	// We need to use ncine::Array in order to have full control of our animations

	ncine::RectAnimation::LoopMode loopMode = ncine::RectAnimation::LoopMode::DISABLED;

	if (layer == AnimationLayer::IDLE_UP || layer == AnimationLayer::IDLE_DOWN || layer == AnimationLayer::IDLE_LEFT || layer == AnimationLayer::IDLE_RIGHT)
		loopMode = ncine::RectAnimation::LoopMode::ENABLED;

	ncine::RectAnimation animation(1.0f / speed, loopMode, ncine::RectAnimation::RewindMode::FROM_START);
	
	for (size_t i = 0; i < length; i++)
		animation.addRect((i * m_v2Size.x) + offsetX, offsetY, m_v2Size.x, m_v2Size.y);

	m_mAnimations.insert_or_assign(layer, animation);

	m_bIsBuilt = false;
}

void CMonster::Build()
{
	m_lpSprite->clearAnimations();

	for (int i = 0; i < (int)AnimationLayer::MOVE_UP_RIGHT; i++)
	{
		m_lpSprite->addAnimation(nctl::makeUnique<ncine::RectAnimation>(m_mAnimations.at((AnimationLayer)i)));
	}

	m_lpSprite->setAnimation((int)AnimationLayer::IDLE_DOWN); // Default animation
	m_lpSprite->setFrame(0);
	m_lpSprite->setPaused(false);

	m_bIsBuilt = true;
}

void CMonster::Move(Directions dir)
{
	// NOTE: This should be coordinated with the main game logic

	if (dir == Directions::DOWN)
	{
		m_lpSprite->setPaused(true);
		m_lpSprite->setAnimation((int)AnimationLayer::MOVE_DOWN);
		m_lpSprite->setFrame(0);
		m_lpSprite->setPaused(false);
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

void CMonster::Update()
{
	if (!m_bIsBuilt)
		Build();
}
