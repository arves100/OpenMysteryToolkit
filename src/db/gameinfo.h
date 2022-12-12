/*
* @file: db/gameinfo.h
* @author: Arves100
* @date: 10/14/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <nctl/String.h>

class GameInfo final
{
public:
	explicit GameInfo();

	bool Load(nctl::String path);

	const nctl::String& GetGameName() const { return m_szGameName; }
	const nctl::String &GetAuthor() const { return m_szAuthor; }
	const nctl::String &GetVersion() const { return m_szAuthor; }
	const nctl::String &GetURL() const { return m_szURL; }
	const nctl::String &GetEntryPoint() const { return m_szEntryPoint; }
	const nctl::String &GetIcon() const { return m_szIcon; }
	bool IsOnlineEnabled() const { return m_bOnline; }
	bool IsNetPlayEnabled() const { return m_bNetPlay; }
	bool IsLocalPlayEnabled() const { return m_bLocalPlay; }

protected:
  nctl::String m_szGameName;
  nctl::String m_szAuthor;
  nctl::String m_szVersion;
  nctl::String m_szURL;
  nctl::String m_szEntryPoint;
  nctl::String m_szIcon;
  bool m_bOnline;
  bool m_bLocalPlay;
  bool m_bNetPlay;
};
