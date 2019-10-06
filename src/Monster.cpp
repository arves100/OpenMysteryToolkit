/*+===================================================================
	File:		Monster.cpp

	Summary:	A generic monster, which could be rather a computer or the player.

	This file is part of OpenMysteryToolkit. Copyright © 2019 Arves100.
	For more information, visit: https://www.github.com/arves100/OpenMysteryToolkit
===================================================================+*/

#include "StdAfx.h"
#include "Monster.h"

CMonster::CMonster() : m_strName(""), m_vSize(0, 0)
{
}

void CMonster::LoadSprite(ncine::SceneNode* cSceneNode, const char* szName, unsigned int unWidth, unsigned int unHeight)
{
	// Create the texture and the animation
	m_qpTexture = nctl::makeUnique<ncine::Texture>((ncine::IFile::dataPath() + "test/monsters/" + szName + "/sprites.png").data());
	m_qpSprite = nctl::makeUnique<ncine::AnimatedSprite>(cSceneNode, m_qpTexture.get());

	m_strName = szName;
	m_vSize = ncine::Vector2<int>(unWidth, unHeight);

	/*
		Since we have access to ncine::AnimatedSprite data, we now have to append all the dummy animations that the Monster could use,
		which will allow us to "add" (replate the dummy animation with the real one) any animation we want.

		I would have prefered a map but in this case, only the Vector is used.
	*/
	m_qpSprite->clearAnimations();

	nctl::Array<nctl::UniquePtr<ncine::RectAnimation>>& vAnimations = m_qpSprite->animations();
	vAnimations.setSize(static_cast<unsigned int>(AnimationLayers::TotalAnimations));

	assert(m_qpSprite->numAnimations() == static_cast<unsigned int>(AnimationLayers::TotalAnimations));
}

void CMonster::AddAnimation(AnimationLayers eLayer, float fSpeed, int nAnimationFrames, int nImageOffsetX, int nImageOffsetY)
{
	if (eLayer == AnimationLayers::TotalAnimations || nAnimationFrames < 1)
		return;

	ncine::RectAnimation::LoopMode eLoopMode = ncine::RectAnimation::LoopMode::DISABLED;

	if (eLayer >= AnimationLayers::Idle_Down && eLayer <= AnimationLayers::Idle_DownRight)
		eLoopMode = ncine::RectAnimation::LoopMode::ENABLED;

	// nCine fastest speed range is 0.0f, not 1.0f as the user should pass in configuration files.
	nctl::UniquePtr<ncine::RectAnimation> qpAnimation = nctl::makeUnique<ncine::RectAnimation> (1.0f / fSpeed, eLoopMode, ncine::RectAnimation::RewindMode::FROM_START);
	
	for (int nCurrentAnimation = 0; nCurrentAnimation < nAnimationFrames; nCurrentAnimation++)
		qpAnimation->addRect((nCurrentAnimation * m_vSize.x) + nImageOffsetX, nImageOffsetY, m_vSize.x, m_vSize.y);

	// master branch of nCine does not support this yet.
	m_qpSprite->animations().insertAt(static_cast<unsigned int>(eLayer), nctl::move(qpAnimation));
}

void CMonster::ChangeAnimation(AnimationLayers eAnimation)
{
	m_qpSprite->setAnimationIndex(static_cast<unsigned int>(eAnimation));
	m_qpSprite->setFrame(0);
	m_qpSprite->setPaused(false);
}

void CMonster::Move(Directions eDir)
{
	// NOTE: This should be coordinated with the main game logic

	if (eDir == Directions::Down)
	{
		// Change the animation
		ChangeAnimation(AnimationLayers::Move_Down);
		m_qpSprite->move(0, -1);
	}
	else if (eDir == Directions::Up)
	{
		m_qpSprite->move(0, 1);
	}
	else if (eDir == Directions::Left)
	{
		m_qpSprite->move(-1, 0);
	}
	else if (eDir == Directions::Right)
	{
		m_qpSprite->move(1, 0);
	}
}

void CMonster::Update()
{

}
