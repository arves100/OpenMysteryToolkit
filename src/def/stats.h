/*
* @file: def/stats.h
* @author: Arves100
* @date: 10/15/2022
* @url https://www.scaminc.org/schifezze/pue
*/
#pragma once

#include <cstdint>
#include <ncine/IFile.h>

/*!
* Information of the statistics of an entity
*/
struct Stats
{
    int64_t hp;
    int64_t mp;
    uint16_t melee_atk;
    uint16_t melee_def;
    uint16_t magic_atk;
    uint16_t magic_def;
    uint8_t speed;

    Stats& operator =(const Stats& rhs) noexcept
    {
        if (this == &rhs)
            return *this;

        hp = rhs.hp;
        mp = rhs.mp;
        melee_atk = rhs.melee_atk;
        melee_def = rhs.melee_def;
        magic_atk = rhs.magic_atk;
        magic_def = rhs.magic_def;
        speed = rhs.speed;

        return *this;
    }

    Stats& operator +(const Stats& rhs)
    {
        if (this == &rhs)
            return *this;

        hp += rhs.hp;
        mp += rhs.mp;

        uint32_t tmp = melee_atk + rhs.melee_atk;
        if (tmp > UINT16_MAX)
            melee_atk = UINT16_MAX;
        else
            melee_atk = uint16_t(tmp);

        tmp = magic_def + rhs.magic_def;
        if (tmp > UINT16_MAX)
            magic_def = UINT16_MAX;
        else
            melee_def = uint16_t(tmp);

        tmp = magic_atk + rhs.magic_atk;
        if (tmp > UINT16_MAX)
            magic_atk = UINT16_MAX;
        else
            magic_atk = uint16_t(tmp);

        tmp = magic_def + rhs.magic_def;
        if (tmp > UINT16_MAX)
            magic_def = UINT16_MAX;
        else
            magic_def = uint16_t(tmp);

        tmp = speed + rhs.speed;
        if (tmp > UINT8_MAX)
            speed = UINT8_MAX;
        else
            speed += uint8_t(tmp);

        return *this;
    }

    Stats& operator -(const Stats& rhs)
    {
        if (this == &rhs)
            return *this;

        hp -= rhs.hp;
        mp -= rhs.mp;

        int32_t tmp = melee_atk - rhs.melee_atk;
        if (tmp <= 0)
            melee_atk = 0;
        else
            melee_atk = uint16_t(tmp);

        tmp = melee_def - rhs.melee_def;
        if (tmp <= 0)
            melee_def = 0;
        else
            melee_def = uint16_t(tmp);

        tmp = magic_atk - rhs.magic_atk;
        if (tmp <= 0)
            magic_atk = 0;
        else
            magic_atk = uint16_t(tmp);

        tmp = magic_def - rhs.magic_def;
        if (tmp <= 0)
            magic_def = 0;
        else
            magic_def = uint16_t(tmp);

        tmp = speed - rhs.speed;
        if (tmp <= 0)
            speed = 0;
        else
            speed = uint8_t(tmp);

        return *this;
    }
};
