#ifndef OMT_MONSTER_H
#define OMT_MONSTER_H

enum class AnimationLayer
{
	IDLE = 0,
};

enum class Directions
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT,
	UP_LEFT,
	UP_RIGHT,
	DOWN_LEFT,
	DOWN_RIGHT,
};

class CMonster
{
public:
	CMonster();

	void LoadSprite(ncine::SceneNode* scene, const char* name, unsigned int width, unsigned int height);
	void Update();
	
	void AddAnimation(AnimationLayer layer, float speed, size_t length, int offsetX, int offsetY);

	void Move(Directions dir);

	nctl::String GetName() { return m_szName; };

protected:
	nctl::UniquePtr<ncine::AnimatedSprite> m_lpSprite;
	nctl::UniquePtr<ncine::Texture> m_lpTexture;
	nctl::String m_szName;
	ncine::Vector2<int> m_v2Size;

};

#endif
