#ifndef OMT_MONSTER_H
#define OMT_MONSTER_H

enum class AnimationLayer
{
	IDLE = 0,
};

class CMonster
{
public:
	CMonster();

	void LoadSprite(ncine::SceneNode* scene, const char* name, unsigned int width, unsigned int height);
	void Update();
	void AddIdleAnimation(float speed, size_t length);
	
	void Move(float x, float y) { m_lpSprite->move(x, y); }
	void Move(ncine::Vector2f vec) { m_lpSprite->move(vec); }

	nctl::String GetName() { return m_szName; };
	ncine::Vector2<int> GetSize() { return m_v2Size; };

protected:
	nctl::UniquePtr<ncine::AnimatedSprite> m_lpSprite;
	nctl::UniquePtr<ncine::Texture> m_lpTexture;
	nctl::String m_szName;
	ncine::Vector2<int> m_v2Size;

};

#endif
