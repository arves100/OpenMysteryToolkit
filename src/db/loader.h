/*
 * @file: db/loader.h
 * @author: Arves100
 * @date: 10/16/2022
 * @url https://www.scaminc.org/schifezze/pue
 */
#pragma once

#include <def/stats.h>
#include <def/deftable.h>
#include <python/link.h>

#include <ncine/IFile.h>

class Loader
{
  public:
	Loader(ncine::IFile &file)
	    : file_(file) {}

	template <typename T>
	bool Load(T& elem)
	{
		return Load(&elem, sizeof(T));
	}

	bool Load(void* data, unsigned long sz)
	{
		return file_.read(data, sz) == sz;
	}

	bool Load(TableHeader& header, uint32_t magic)
	{
		if (!Load(header.magic))
			return false;

		if (magic != header.magic)
			return false;

		return Load(header.size);
	}

	bool Load(PythonLink& lnk)
	{
		bool hasLink;
		if (!Load(hasLink))
			return false;

		if (!hasLink)
			return true;

		nctl::String mod;
		if (!Load(mod))
			return false;

		nctl::String def;
		if (!Load(def))
			return false;

		return lnk.Link(mod, def);
	}

	bool Load(nctl::String &sz)
	{
		unsigned int size;
		if (!Load(size))
			return false;

		nctl::String str(size);
		if (!Load(str.data(), size))
			return false;

		sz = str;
		return true;
	}

	bool Load(Stats& elem)
	{
		if (!Load(elem.hp))
			return false;

		if (!Load(elem.mp))
			return false;

		if (!Load(elem.melee_atk))
			return false;

		if (!Load(elem.melee_def))
			return false;

		if (!Load(elem.magic_atk))
			return false;

		if (!Load(elem.magic_def))
			return false;

		return Load(elem.speed);
	}

  protected:
	ncine::IFile &file_;
};
