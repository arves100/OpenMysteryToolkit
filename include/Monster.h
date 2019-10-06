/*+===================================================================
	File:		Monster.h

	Summary:	A generic monster, which could be rather a computer or the player.

	This file is part of OpenMysteryToolkit. Copyright © 2019 Arves100.
	For more information, visit: https://www.github.com/arves100/OpenMysteryToolkit
===================================================================+*/

#ifndef OMT_MONSTER_H
#define OMT_MONSTER_H

/*E===================================================================
	Enum:			Directions

	Summary:		Directions where the monster could move.
===================================================================E*/
enum class Directions
{
	Up = 0,
	Down,
	Left,
	Right,
	UpLeft,
	UpRight,
	DownLeft,
	DownRight,
};

/*E===================================================================
	Enum:			AnimationLayers

	Summary:		All supported animation layers in each monster.
===================================================================E*/
enum class AnimationLayers
{
	// Idle animations (8 directions)
	Idle_Up,
	Idle_Down,
	Idle_Left,
	Idle_Right,
	Idle_UpLeft,
	Idle_UpRight,
	Idle_DownLeft,
	Idle_DownRight,

	// Movement animations (8 directions)
	Move_Up,
	Move_Down,
	Move_Left,
	Move_Right,
	Move_UpLeft,
	Move_UpRight,
	Move_DownLeft,
	Move_DownRight,

	/* Total of all the animations, this value is used to check if the value of AnimationLayers is valid or not and it must be placed at the end of all animation names.
	Do not pass this value to any Animation function. */
	TotalAnimations,
};


/*C===================================================================
	Class:		CMonster

	Summary:	Rapresentation of a generic monster (which could be either an AI monster or a player, since the base logic is the same).

	Methods:	LoadSprite
					Loads the sprite data (one image containing all animations).
				AddAnimation
					Adds an animation to the animations layer.
				SetPosition
					Sets the position of the sprite.
				Move
					Move the sprite in one direction.
				CMonster
					Constructor.
===================================================================C*/
class CMonster
{
public:
	/*M===================================================================
		Method:		CMonster::CMonster

		Summary:	Default costructor of the class

		Args:		None

		Modifies:	m_strName, m_vSize

		Returns:	None
	===================================================================M*/
	CMonster();

	/*M===================================================================
		Method:		CMonster::LoadSprite

		Summary:	Load one image containing all the image, creates the unique pointer of both the sprite and texture and add the sprite to the current scene node.

		Args:		ncine::SceneNode* cSceneNode
						The scene where the sprite should be added.
					const char* szName
						Name of the sprite.
					unsigned int unWidth
						Width of the sprite texture.
					unsigned int unHeight
						Height of the sprite texture.

		Modifies:	m_qpTexture, m_qpSprite, m_strName, m_vSize

		Returns:	void
	===================================================================M*/
	void LoadSprite(ncine::SceneNode* cSceneNode, const char* szName, unsigned int unWidth, unsigned int unHeight);

	/*M===================================================================
		Method:		CMonster::ChangeAnimation

		Summary:	Load one image containing all the image, creates the unique pointer of both the sprite and texture and add the sprite to the current scene node.

		Args:		AnimationLayers eAnimation
						Changes the current animation to the one specified in this parameter.

		Modifies:	m_qpSprite

		Returns:	void
	===================================================================M*/
	void ChangeAnimation(AnimationLayers eAnimation);

	/*M===================================================================
		Method:		CMonster::Update

		Summary:	Perform an update of the monster logic (for example, automatic movement or attacking)

		Args:		None

		Modifies:	None

		Returns:	void
	===================================================================M*/
	void Update();
	
	/*M===================================================================
		Method:		CMonster::AddAnimation

		Summary:	Adds an animation to the animation layers.

		Args:		AnimationLayers eLayer
						The layer where the animation will be added.
					float fSpeed
						The speed which the animation will run at.
					unsigned int unAnimationFrames
						The number of frames (width x height box in the sprite image) that the animation have.
						Each frame needs to be next to each other (with the same Y position)
					unsigned int unHeight
						Height of the sprite texture

		Modifies:	m_qpSprite

		Returns:	void
	===================================================================M*/
	void AddAnimation(AnimationLayers eLayer, float fSpeed, int nAnimationFrames, int nImageOffsetX, int nImageOffsetY);

	/*M===================================================================
		Method:		CMonster::SetPosition

		Summary:	Sets the position of the monster.

		Args:		float x
						X position
					float y
						Y position

		Modifies:	m_qpSprite

		Returns:	void
	===================================================================M*/
	void SetPosition(float x, float y) { m_qpSprite->setPosition(x, y); }

	/*M===================================================================
		Method:		CMonster::Move

		Summary:	Moves the monster into one block of one direction.

		Args:		Directions eDir
						The direction to move

		Modifies:	m_qpSprite

		Returns:	void
	===================================================================M*/
	void Move(Directions eDir);

	/*M===================================================================
		Method:		CMonster::GetName

		Summary:	Gets the name of the sprite.

		Args:		None

		Modifies:	None

		Returns:	nctl::String
						A null terminated string containing the sprite name.
	===================================================================M*/
	nctl::String GetName() const { return m_strName; };

protected:
	nctl::UniquePtr<ncine::AnimatedSprite> m_qpSprite;
	nctl::UniquePtr<ncine::Texture> m_qpTexture;
	nctl::String m_strName;
	ncine::Vector2<int> m_vSize;
};

#endif // OMT_MONSTER_H
