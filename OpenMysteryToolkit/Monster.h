#ifndef OMT_MONSTER_H
#define OMT_MONSTER_H

enum class AnimationLayer
{
	IDLE_UP = 0,
	IDLE_DOWN,
	IDLE_LEFT,
	IDLE_RIGHT,

	IDLE_UP_LEFT,
	IDLE_UP_RIGHT,
	IDLE_DOWN_LEFT,
	IDLE_DOWN_RIGHT,

	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,

	MOVE_UP_LEFT,
	MOVE_UP_RIGHT,
	MOVE_DOWN_LEFT,
	MOVE_DOWN_RIGHT,
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

	void SetPosition(float x, float y) { m_lpSprite->setPosition(x, y); }

	void Move(Directions dir);

	nctl::String GetName() { return m_szName; };

protected:
	nctl::UniquePtr<ncine::AnimatedSprite> m_lpSprite;
	nctl::UniquePtr<ncine::Texture> m_lpTexture;
	nctl::String m_szName;
	ncine::Vector2<int> m_v2Size;
	
	std::map<AnimationLayer, ncine::RectAnimation> m_mAnimations;

private:
	void Build();
	bool m_bIsBuilt;
};

#endif
